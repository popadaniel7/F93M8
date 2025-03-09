/* START OF FILE */
/* INCLUDE START */
#include "InputCtrl.h"
#include "Dem.h"
#include "Ain.h"
#include "UartH.h"
#include "main.h"
#include <stdlib.h>
/* INCLUDE END */
/* VARIABLES START */
/* Under-voltage de-bounce parameterizable variable. */
uint8 Param_UndervoltageThreshold_Calibration = 0;
/* De-bounce time parameterizable variable. */
uint8 Param_ErrorSettingDebouceThreshold_Calibration = 0;
/* Out of bound value parameterizable variable. */
uint16 Param_OutofboundThreshold_Calibration = 0;
/* De-bounce previous state time value parameterizable variable. */
uint16 Param_DebouncePreviouState_Calibration = 0;
/* Calibration values array. */
uint16 Param_Input_Calibration[INPUT_NUMBER] = {0};
/* Lock state signal status. */
uint8 LockState_VehicleState = 0;
/* Vehicle speed signal status. */
uint8 VehicleSpeed_VehicleState = 0;
/* Wiper stock signal status. */
uint8 WiperStock_VehicleState = 0;
/* Input value array. */
uint32 StatusList_InputValue[INPUT_NUMBER] = {0};
/* Input status array. */
InStat StatusList_InputStatus[STATUS_NUMBER] = {0};
/* Processed output values array. */
uint32 StatusList_OutputValue[INPUT_NUMBER] = {0};
/* Processed CAN output values array. */
uint8 StatusList_ComOutValue[INPUT_NUMBER] = {0};
/* Processed raw output values array. */
uint8 StatusList_RawValue[RAW_INPUTS] = {0};
/* Input coding data. */
uint32 InputCtrl_CodingData[INPUT_NUMBER - 2] = {0};
/* VARIABLES STOP */
/* PROTOTYPE START */
void InputCtrl_MainFunction(void);
/* PROTOTYPE END */
/* FUNCTIONS START */
void InputCtrl_MainFunction(void)
{
	/* Main counter. */
	static uint32 InputCtrl_MainCounter = 0;
	/* Invalidate inputs in case of ADC error. */
	for(uint8 i = 0; i < 3; i++)
	{
		if(Adc_Error[i] != 0)
		{
			for(uint8 j = IGN_ARRPOS; j <= STATUS_GSNS_ARRPOS; j++)
			{
				StatusList_InputValue[j] = 0;
				StatusList_OutputValue[j] = 0;
				StatusList_ComOutValue[j] = 0;
				StatusList_RawValue[j] = 0;
			}
		}
		else
		{
			/* Do nothing. */
		}
	}
	/* Invalidate inputs in case of UART error. */
	for(uint8 i = 0; i < 5; i++)
	{
		if(UartH_ErrorArr[i] != 0)
		{
			StatusList_InputValue[HC05_ARRPOS] = 0;
			StatusList_OutputValue[HC05_ARRPOS] = 0;
			StatusList_ComOutValue[HC05_ARRPOS] = 0;
			StatusList_InputStatus[HC05_ARRPOS].DCYStatus = 1;
			StatusList_InputStatus[HC05_ARRPOS].errorStatus = 0xA;
			break;
		}
		else
		{
			/* Do nothing. */
		}
	}
	/* Process input status. */
	for(uint8 i = IGN_ARRPOS; i <= GSNS_ARRPOS; i++)
	{
		/* If this has not been set this drive cycle status. */
		if(StatusList_InputStatus[i].DCYStatus == 0)
		{
			/* Check the value to be under threshold. */
			if(StatusList_InputValue[i] < Param_UndervoltageThreshold_Calibration)
			{
				/* Count the time period while the input retains the same value. */
				StatusList_InputStatus[i].debounceTimer_undervoltage++;
				/* If enough time has elapsed with error. */
				if(StatusList_InputStatus[i].debounceTimer_undervoltage == Param_ErrorSettingDebouceThreshold_Calibration)
				{
					/* Store the error. */
					StatusList_InputStatus[i].debounceTimer_undervoltage = 0;
					StatusList_InputStatus[i].DCYStatus = 1;
					StatusList_InputStatus[i].errorStatus = 1;
				}
				else
				{
					/* Do nothing. */
				}
			}
			else
			{
				/* Do nothing. */
			}
		}
		else
		{
			/* Do nothing. */
		}
	}
	/* Process the output values. */
	for(uint8 i = STATUS_IGN_ARRPOS; i <= STATUS_GSNS_ARRPOS; i++)
	{
		/* In case of error is detected, invalidate the input. */
		if(StatusList_InputStatus[i].errorStatus == 0)
		{
			if(StatusList_InputValue[i] <= Param_Input_Calibration[i]) StatusList_OutputValue[i] = 0;
			else StatusList_OutputValue[i] = StatusList_InputValue[i]; /* If no error have occurred, store the processed value. */
		}
		else StatusList_OutputValue[i] = 0xFF;
	}
	/* Process the raw value to be sent on CAN. */
	for(uint8 i = IGN_ARRPOS; i < RAW_INPUTS; i++) StatusList_RawValue[i] = (StatusList_InputValue[i] * 255) / 4095;
	/* Update the to-be-sent-on-CAN variables. */
	StatusList_ComOutValue[IGN_ARRPOS] = (StatusList_OutputValue[IGN_ARRPOS] * 2) / 4095;
	//StatusList_ComOutValue[ACC_ARRPOS] = (StatusList_OutputValue[ACC_ARRPOS] * 100) / 4095;
	//StatusList_ComOutValue[BR_ARRPOS] = (StatusList_OutputValue[BR_ARRPOS] * 100) / 4095;
	//StatusList_ComOutValue[PS_ARRPOS] = (StatusList_OutputValue[PS_ARRPOS] * 180) / 4095;
	StatusList_ComOutValue[GB_ARRPOS] = (StatusList_OutputValue[GB_ARRPOS] * 2) / 4095;
	StatusList_ComOutValue[HC05_ARRPOS] = StatusList_OutputValue[HC05_ARRPOS];
	/* Process the input values of sensors. */
	for(uint8 i = LSNS_ARRPOS; i <= GSNS_ARRPOS; i++)
	{
		if(StatusList_OutputValue[i] > 3000) StatusList_ComOutValue[i] = 1;
		else StatusList_ComOutValue[i] = 0;
	}
	/* Process error discovered on inputs. */
	for(uint8 i = STATUS_IGN_ARRPOS; i < STATUS_NUMBER; i++)
	{
		/* If input is not coded, do not set a DTC. */
		if(i >= STATUS_LSNS_ARRPOS && i <= STATUS_GSNS_ARRPOS)
		{
			if(InputCtrl_CodingData[i] == 1)
			{
				StatusList_InputStatus[i].DCYStatus = 0;
				StatusList_InputStatus[i].errorStatus = 0;
			}
			else
			{
				/* Do nothing */
			}
		}
		else
		{
			/* Do nothing. */
		}
		/* Store DTCs in case of errors were detected. */
		if((StatusList_InputStatus[i].DCYStatus == 1) && (StatusList_InputStatus[i].errorStatus != 0))
		{
			Dem_SaveDtc(i, StatusList_InputStatus[i].errorStatus);
			StatusList_InputStatus[i].DCYStatus = 2;
		}
		else if(StatusList_InputStatus[i].errorStatus == 0) Dem_SaveDtc(i, StatusList_InputStatus[i].errorStatus);
		else
		{
			/* Do nothing. */
		}
	}
	/* Invalidate the input if not coded. */
	if(InputCtrl_CodingData[0] == 1) StatusList_ComOutValue[HC05_ARRPOS] = 0;
	else
	{
		/* Do nothing. */
	}
	/* Invalidate the input if not coded. */
	if(InputCtrl_CodingData[1] == 1)
	{
		if(StatusList_OutputValue[HC05_ARRPOS] == 0x03) StatusList_ComOutValue[HC05_ARRPOS] = 0;
		else
		{
			/* Do nothing. */
		}
	}
	else
	{
		/* Do nothing. */
	}
	/* Invalidate the input if not coded. */
	if(InputCtrl_CodingData[2] == 1)
	{
		if(StatusList_OutputValue[HC05_ARRPOS] == 0x04) StatusList_ComOutValue[HC05_ARRPOS] = 0;
		else
		{
			/* Do nothing. */
		}
	}
	else
	{
		/* Do nothing. */
	}
	/* Invalidate the input if not coded. */
	if(InputCtrl_CodingData[3] == 1)
	{
		if(StatusList_OutputValue[HC05_ARRPOS] == 0x05) StatusList_ComOutValue[HC05_ARRPOS] = 0;
		else
		{
			/* Do nothing. */
		}
	}
	else
	{
		/* Do nothing. */
	}
	/* Invalidate the input if not coded. */
	if(InputCtrl_CodingData[4] == 1) StatusList_ComOutValue[RSNS_ARRPOS] = 0;
	else
	{
		/* Do nothing. */
	}
	/* Invalidate the input if not coded. */
	if(InputCtrl_CodingData[5] == 1) StatusList_ComOutValue[LSNS_ARRPOS] = 0;
	else
	{
		/* Do nothing. */
	}
	/* Invalidate the input if not coded. */
	if(InputCtrl_CodingData[6] == 1) StatusList_ComOutValue[AQSNS_ARRPOS] = 0;
	else
	{
		/* Do nothing. */
	}
	/* Invalidate the input if not coded. */
	if(InputCtrl_CodingData[7] == 1) StatusList_ComOutValue[GSNS_ARRPOS] = 0;
	else
	{
		/* Do nothing. */
	}
	/* Main counter. */
	InputCtrl_MainCounter++;
}
/* FUNCTIONS END */
/* STOP OF FILE */
