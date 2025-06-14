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
/* Calibration values array. */
uint16 Param_Input_Calibration[4] = {0};
/* Vehicle speed signal status. */
uint8 VehicleSpeed_VehicleState = 253;
/* Wiper stock signal status. */
uint8 WiperStock_VehicleState = 255;
/* Input value array. */
uint32 StatusList_InputValue[5] = {253};
/* Input status array. */
InStat StatusList_InputStatus[5];
/* Processed output values array. */
uint32 StatusList_OutputValue[5] = {253};
/* Processed CAN output values array. */
uint8 StatusList_ComOutValue[5] = {253};
/* Processed raw output values array. */
uint8 StatusList_RawValue[5] = {253};
/* Input coding data. */
uint32 InputCtrl_CodingData[4] = {253};
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
			for(uint8 j = 0; j < 5; j++)
			{
				StatusList_InputValue[j] = 0;
				StatusList_OutputValue[j] = 0;
				StatusList_ComOutValue[j] = 0;
				StatusList_RawValue[j] = 0;
			}
			break;
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
			StatusList_InputValue[4] = 0;
			StatusList_OutputValue[4] = 0;
			StatusList_ComOutValue[4] = 0;
			StatusList_InputStatus[4].DCYStatus = 1;
			StatusList_InputStatus[4].errorStatus = 1;
			break;
		}
		else
		{
			/* Do nothing. */
		}
	}
	StatusList_OutputValue[4] = StatusList_InputValue[4];
	/* Process input status. */
	for(uint8 i = 0; i < 4; i++)
	{
		if(i == 0 || i == 2)
		{
			continue;
		}
		else
		{
			/* Do nothing. */
		}
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
	for(uint8 i = 0; i < 4; i++)
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
	for(uint8 i = 0; i < 4; i++) StatusList_RawValue[i] = (StatusList_InputValue[i] * 255) / 4095;
	/* Update the to-be-sent-on-CAN variables. */

	StatusList_ComOutValue[4] = StatusList_OutputValue[4];

	if(StatusList_OutputValue[0] < 1500)
	{
		StatusList_ComOutValue[0] = 0;
	}
	else if(1500 <= StatusList_OutputValue[0] && StatusList_OutputValue[0] < 4000)
	{
		StatusList_ComOutValue[0] = 1;
	}
	else if(4000 <= StatusList_OutputValue[0])
	{
		StatusList_ComOutValue[0] = 2;
	}
	else
	{
		/* Do nothing. */
	}

	if(StatusList_OutputValue[2] < 1200)
	{
		StatusList_ComOutValue[2] = 0;
	}
	else if(StatusList_OutputValue[2] >= 1200 && StatusList_OutputValue[2] < 2000)
	{
		StatusList_ComOutValue[2] = 1;
	}
	else if(StatusList_OutputValue[2] >= 2000 && StatusList_OutputValue[2] < 4000)
	{
		StatusList_ComOutValue[2] = 2;
	}
	else if(StatusList_OutputValue[2] >= 4000)
	{
		StatusList_ComOutValue[2] = 3;
	}
	else
	{
		/* Do nothing. */
	}

	if(StatusList_OutputValue[1] >= 3000)
	{
		StatusList_ComOutValue[1] = 1;
	}
	else
	{
		StatusList_ComOutValue[1] = 0;
	}

	if(StatusList_OutputValue[3] >= 3000)
	{
		StatusList_ComOutValue[3] = 1;
	}
	else
	{
		StatusList_ComOutValue[3] = 0;
	}

	/* Process error discovered on inputs. */
	for(uint8 i = 0; i < 4; i++)
	{
		/* Store DTCs in case of errors were detected. */
		if((StatusList_InputStatus[i].DCYStatus == 1) && (StatusList_InputStatus[i].errorStatus != 0))
		{
			Dem_SaveDtc(i + 1, 1);
			StatusList_InputStatus[i].DCYStatus = 2;
		}
		else if(StatusList_InputStatus[i].errorStatus == 0) Dem_SaveDtc(i + 1, 0);
		else
		{
			/* Do nothing. */
		}
	}
	/* Invalidate the input if not coded. */
	if(InputCtrl_CodingData[0] == 1) StatusList_ComOutValue[4] = 0;
	else
	{
		/* Do nothing. */
	}
	/* Invalidate the input if not coded. */
	if(InputCtrl_CodingData[1] == 1)
	{
		if(StatusList_OutputValue[4] == 0x03) StatusList_ComOutValue[4] = 0;
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
	if(InputCtrl_CodingData[2] == 1) StatusList_ComOutValue[3] = 0;
	else
	{
		/* Do nothing. */
	}
	/* Invalidate the input if not coded. */
	if(InputCtrl_CodingData[3] == 1) StatusList_ComOutValue[1] = 0;
	else
	{
		/* Do nothing. */
	}
	/* Main counter. */
	InputCtrl_MainCounter++;
}
/* FUNCTIONS END */
/* STOP OF FILE */
