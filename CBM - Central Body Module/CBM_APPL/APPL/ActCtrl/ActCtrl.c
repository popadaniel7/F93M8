/* START OF FILE */
/* INCLUDE START */
#include "ActCtrl.h"
#include "InputCtrl.h"
#include "tim.h"
#include "TimH.h"
#include <stdlib.h>
/* INCLUDE END */
/* VARIABLES START */
/* Variable used as coefficient when changing wiper PWM for slow mode. */
uint8 Param_WindshieldWiperSlow_Calibration = 0;
/* Variable used as coefficient when changing wiper PWM for fast mode. */
uint8 Param_WindshieldWiperFast_Calibration = 0;
uint8 Param_DoorLockPwmIncrement = 0;
/* Variable used as coding option for how long to wash the windshield. */
uint8 WindshieldWashing_CodingData = 0;
uint8 WashingWipingCounter_CodingData = 0;
/* Variable used to determine the time period of wiper interval. */
uint16 WiperDelay_Vector[2][6][1] =
{
		{{1700}, {1200}, {1100}, {1000}, {900}, {700}},
		{{600}, {500}, {400}, {300}, {200}, {100}}
};
/* Variable used for speed intervals based on which the wiper actuate. */
uint8 WiperSpeed_Vector[5] = {5, 15, 30, 40, 50};
/* Variable used to store PWM value of actuators. */
uint8 CmdList_RawValue[ACT_NO] = {0};
/* Variable used to send on CAN the status of actuators. */
uint8 CmdList_ActualValue[ACT_NO] = {0};
/* CAN signals for climate fan control. */
uint8 StatusBodyControl_FanValue = 0;
/* CAN signals for climate fan control. */
uint8 StatusBodyControl_Auto = 0;
/* CAN signals for climate fan control. */
uint8 StatusBodyControl_Recirc = 0;
/* CAN signals for climate fan control. */
uint8 StatusBodyControl_Temperature = 0;
/* CAN signals for climate fan control. */
uint8 StatusBodyControl_OutsideTemp = 0;
/* VARIABLES END*/
/* PROTOTYPE START */
void ActCtrl_ClimaMainFunction(void);
void ActCtrl_MainFunction(void);
/* PROTOTYPE END */
/* FUNCTIONS START */
void ActCtrl_ClimaMainFunction(void)
{
	/* PWM value. */
	static uint8 calculatedPWM = 0;
	/* Auto fan value scaled down. */
	static uint8 autoFanValue = 0;
	/* Coefficient calculation. */
	static uint8 recirculationCalculatedValue = 0;
	/* Coefficient calculation. */
	static uint8 calculatedTemperatureValue = 0;
	/* Manual control. */
	if(0 == StatusBodyControl_Auto) calculatedPWM = 25 * StatusBodyControl_FanValue;
	else
	{
		/* Scale down. */
		autoFanValue = (StatusBodyControl_FanValue / 2) + 1;
		/* Check requested recirculation state to be AUTO. */
		if(2 == StatusBodyControl_Recirc)
		{
			/* Calculate recirculation coefficient that impacts the final PWM value of the climate fan.
			 * This does not have an impact on how should a climate fan in a car behave I would assume.
			 * But for the sake of example and demonstration of functionality, this is present here.
			 * So the fan acts according to the design, in the end! */
			if(1 == StatusList_ComOutValue[GSNS_ARRPOS] && 1 == StatusList_ComOutValue[AQSNS_ARRPOS]) recirculationCalculatedValue = 4;
			else if(1 == StatusList_ComOutValue[GSNS_ARRPOS] || 1 == StatusList_ComOutValue[AQSNS_ARRPOS]) recirculationCalculatedValue = 3;
			else recirculationCalculatedValue = 2;
		}
		else recirculationCalculatedValue = 1;
		/* Calculate the coefficient of the fan speed applied based on the difference of the temperature: requested versus outside. */
		if(0 == StatusBodyControl_OutsideTemp && 0 == StatusBodyControl_Temperature) calculatedTemperatureValue = 1;
		else
		{
			if(abs(StatusBodyControl_OutsideTemp - StatusBodyControl_Temperature) > 16) calculatedTemperatureValue = 16;
			else calculatedTemperatureValue = abs(StatusBodyControl_OutsideTemp - StatusBodyControl_Temperature);
		}
		/* Calculate the PWM value to be applied to the fan. */
		calculatedPWM = 8 * (calculatedTemperatureValue + recirculationCalculatedValue + autoFanValue);
		/* Scale it down. */
		calculatedPWM = (calculatedPWM / 5) * 5;
		/* Fan value requested 0 means no fan. */
		if(0 == StatusBodyControl_FanValue) calculatedPWM = 0;
		else
		{
			/* Do nothing. */
		}
	}
	/* Apply the correct PWM to the MOSFET board that controls the speed of the fan. */
	if(0 != calculatedPWM)
	{
		if(calculatedPWM > htim2.Instance->CCR1) htim2.Instance->CCR1 += 5;
		else if(calculatedPWM < htim2.Instance->CCR1) htim2.Instance->CCR1 -= 5;
		else
		{
			/* Do nothing. */
		}
	}
	else htim2.Instance->CCR1 = 0;
}

void ActCtrl_MainFunction(void)
{
	/* Main counter. */
	static uint32 ActCtrl_MainCounter = 0;
	/* Delta time variable. */
	static uint32 wiperDebounce_timer = 0;
	/* Wiper travel status variable. */
	static uint8 wiperTravel_completed = 0;
	/* Previous Wiper travel status variable. */
	static uint8 previousStatus_wiperTravel_completed = 0;
	/* Store the speed interval we are situated. */
	static uint8 wiperStatus_speedInterval = 0;
	/* Count how many times the wipers have travelled. */
	static uint32 washingCounter = 0;
	/* Wait before setting the wipers to default position. */
	static uint32 washingTimeStamp = 0;
	/* Process climate fan. */
	ActCtrl_ClimaMainFunction();
	/* Process the PWM value based on CAN command. */
	/* Invalidate PWM registers if TIM error is detected. */
	if(Tim_ErrorStatus[0] == 0)
	{
		/* Do nothing. */
	}
	else htim2.Instance->CCR1 = 0;
	/* Invalidate PWM registers if TIM error is detected. */
	if(Tim_ErrorStatus[1] == 0)
	{
		/* If latest command from received via BT is 1. */
		if(StatusList_OutputValue[HC05_ARRPOS] == 1)
		{
			/* Door lock left */
			if(1250 - Param_DoorLockPwmIncrement > htim3.Instance->CCR1) htim3.Instance->CCR1 += Param_DoorLockPwmIncrement;
			else
			{
				/* Do nothing. */
			}
			/* Door lock right */
			if(1250 - Param_DoorLockPwmIncrement > htim3.Instance->CCR2) htim3.Instance->CCR2 += Param_DoorLockPwmIncrement;
			else
			{
				/* Do nothing. */
			}
		}/* Else close the doors. */
		else if(StatusList_OutputValue[HC05_ARRPOS] == 2)
		{
			/* Door lock left */
			if(Param_DoorLockPwmIncrement < htim3.Instance->CCR1) htim3.Instance->CCR1 -= Param_DoorLockPwmIncrement;
			else
			{
				/* Do nothing. */
			}
			/* Door lock right */
			if(Param_DoorLockPwmIncrement < htim3.Instance->CCR2) htim3.Instance->CCR2 -= Param_DoorLockPwmIncrement;
			else
			{
				/* Do nothing. */
			}
		}
		else
		{
			/* Do nothing. */
		}
		/* Process the speed interval. */
		if(VehicleSpeed_VehicleState <= WiperSpeed_Vector[0]) wiperStatus_speedInterval = 1;
		else if(VehicleSpeed_VehicleState > WiperSpeed_Vector[0] && VehicleSpeed_VehicleState <= WiperSpeed_Vector[1]) wiperStatus_speedInterval = 2;
		else if(VehicleSpeed_VehicleState > WiperSpeed_Vector[1] && VehicleSpeed_VehicleState <= WiperSpeed_Vector[2]) wiperStatus_speedInterval = 3;
		else if(VehicleSpeed_VehicleState > WiperSpeed_Vector[2] && VehicleSpeed_VehicleState <= WiperSpeed_Vector[3]) wiperStatus_speedInterval = 4;
		else if(VehicleSpeed_VehicleState > WiperSpeed_Vector[3] && VehicleSpeed_VehicleState <= WiperSpeed_Vector[4]) wiperStatus_speedInterval = 5;
		else if(VehicleSpeed_VehicleState > WiperSpeed_Vector[4]) wiperStatus_speedInterval = 6;
		else
		{
			/* Do nothing. */
		}
		/* If this is the first part of the wiping */
		if(wiperTravel_completed == 1)
		{
			/* Check the speed interval */
			if(wiperStatus_speedInterval < 6)
			{
				/* Update the PWM registers. */
				if(htim3.Instance->CCR3 < (1250 - Param_WindshieldWiperSlow_Calibration) && htim3.Instance->CCR4 < (1250 - Param_WindshieldWiperSlow_Calibration))
				{
					htim3.Instance->CCR3 += Param_WindshieldWiperSlow_Calibration;
					htim3.Instance->CCR4 += Param_WindshieldWiperSlow_Calibration;
				}
				else
				{
					/* Note that the first part of the wiping travel has been finished. */
					if(wiperTravel_completed == 1) wiperTravel_completed = 2;
					else
					{
						/* Do nothing. */
					}
				}
			}/* If the speed interval is the highest. */
			else
			{
				/* Update the PWM registers. */
				if(htim3.Instance->CCR3 < (1250 - Param_WindshieldWiperFast_Calibration) && htim3.Instance->CCR4 < (1250 - Param_WindshieldWiperFast_Calibration))
				{
					htim3.Instance->CCR3 += Param_WindshieldWiperFast_Calibration;
					htim3.Instance->CCR4 += Param_WindshieldWiperFast_Calibration;
				}
				else
				{
					/* Note that the first part of the wiping travel has been finished. */
					if(wiperTravel_completed == 1) wiperTravel_completed = 2;
					else
					{
						/* Do nothing. */
					}
				}
			}
		}/* If this is the second part of the wiping. */
		else if(wiperTravel_completed == 2)
		{
			/* Check the speed interval */
			if(wiperStatus_speedInterval < 6)
			{
				/* Update the PWM registers. */
				if(htim3.Instance->CCR3 > Param_WindshieldWiperSlow_Calibration && htim3.Instance->CCR4 > Param_WindshieldWiperSlow_Calibration)
				{
					htim3.Instance->CCR3 -= Param_WindshieldWiperSlow_Calibration;
					htim3.Instance->CCR4 -= Param_WindshieldWiperSlow_Calibration;
				}
				else
				{
					/* Note that the second part of the wiping travel has been finished. */
					if(wiperTravel_completed == 2)
					{
						wiperTravel_completed = 0;
						htim3.Instance->CCR3 = 0;
						htim3.Instance->CCR4 = 0;
					}
					else
					{
						/* Do nothing. */
					}
				}
			}/* If the speed interval is the highest. */
			else if(wiperStatus_speedInterval == 6)
			{
				/* Update the PWM registers. */
				if(htim3.Instance->CCR3 > Param_WindshieldWiperFast_Calibration && htim3.Instance->CCR4 > Param_WindshieldWiperFast_Calibration)
				{
					htim3.Instance->CCR3 -= Param_WindshieldWiperFast_Calibration;
					htim3.Instance->CCR4 -= Param_WindshieldWiperFast_Calibration;
				}
				else
				{
					/* Note that the second part of the wiping travel has been finished. */
					if(wiperTravel_completed == 2)
					{
						wiperTravel_completed = 0;
						htim3.Instance->CCR3 = 0;
						htim3.Instance->CCR4 = 0;
					}
					else
					{
						/* Do nothing. */
					}
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
		/* If auto mode is selected. */
		if(WiperStock_VehicleState == 1 && StatusList_OutputValue[RSNS_ARRPOS] >= 3000)
		{
			if(wiperTravel_completed == 0) wiperTravel_completed = 1;
			else
			{
				/* Do nothing. */
			}
		}/* Else if the manual mode is selected. */
		else if(WiperStock_VehicleState == 2 || WiperStock_VehicleState == 3)
		{
			/* Check the previous state and re-init the delta time. */
			if(previousStatus_wiperTravel_completed != wiperTravel_completed)
			{
				previousStatus_wiperTravel_completed = wiperTravel_completed;
				wiperDebounce_timer = 0;
			}
			else
			{
				/* Do nothing. */
			}
			/* Take a time stamp. */
			if(wiperDebounce_timer == 0) wiperDebounce_timer = ActCtrl_MainCounter;
			else
			{
				/* Do nothing. */
			}
			/* If the time period has elapsed, start a new wiping process. */
			if(ActCtrl_MainCounter - wiperDebounce_timer >= WiperDelay_Vector[WiperStock_VehicleState - 2][wiperStatus_speedInterval - 1][0]) wiperTravel_completed = 1;
			else
			{
				/* Do nothing. */
			}
		}/* Washing command. */
		else if(WiperStock_VehicleState == 4)
		{
			/* Initialize the time stamp and the washing counter. */
			if(washingTimeStamp == 0)
			{
				washingTimeStamp = ActCtrl_MainCounter;
				washingCounter = WashingWipingCounter_CodingData;
			}
			else
			{
				/* Do nothing. */
			}
		}
		else
		{
			/* Reset the delta time. */
			wiperDebounce_timer = 0;
			/* Reset the previous state. */
			previousStatus_wiperTravel_completed = 0;
		}
		/* Wait before wiping. */
		if(((ActCtrl_MainCounter - washingTimeStamp) < WindshieldWashing_CodingData) &&
				(washingTimeStamp != 0))
		{
			/* Start a new wipe cycle. */
			if(wiperTravel_completed == 0)
			{
				wiperTravel_completed = 1;
				washingCounter--;
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
		/* Start a new wipe cycle. */
		if(wiperTravel_completed == 0 && washingCounter > 0)
		{
			wiperTravel_completed = 1;
			washingCounter--;
		}
		else
		{
			/* Do nothing. */
		}
		/* If enough wiping have been performed, finish the sequence. */
		if(washingCounter == 0) washingTimeStamp = 0;
		else
		{
			/* Do nothing. */
		}
	}
	else
	{
		/* Reset registers and variables if error is detected. */
		htim3.Instance->CCR1 = 0;
		htim3.Instance->CCR2 = 0;
		htim3.Instance->CCR3 = 0;
		htim3.Instance->CCR4 = 0;
		wiperDebounce_timer = 0;
		wiperTravel_completed = 0;
		previousStatus_wiperTravel_completed = 0;
		wiperStatus_speedInterval = 0;
	}
	/* Update the variables that are sent on CAN. */
	CmdList_RawValue[WWR_ARRPOS] = (htim3.Instance->CCR3 * 255) / 1250;
	CmdList_RawValue[WWL_ARRPOS] = (htim3.Instance->CCR4  * 255) / 1250;
	CmdList_RawValue[DLL_ARRPOS] = (htim3.Instance->CCR1  * 255) / 1250;
	CmdList_RawValue[DLR_ARRPOS] = (htim3.Instance->CCR2  * 255) / 1250;
	CmdList_RawValue[CLIMA_ARRPOS] = (htim2.Instance->CCR1 * 255) / 100;
	CmdList_ActualValue[WWR_ARRPOS] = (htim3.Instance->CCR3 * 255) / 1250;
	CmdList_ActualValue[WWL_ARRPOS] = (htim3.Instance->CCR4 * 255) / 1250;
	CmdList_ActualValue[DLL_ARRPOS] = htim3.Instance->CCR1 / 255;
	CmdList_ActualValue[DLR_ARRPOS] = htim3.Instance->CCR2 / 255;
	CmdList_ActualValue[CLIMA_ARRPOS] = htim2.Instance->CCR1;
	/* Increment the main counter. */
	ActCtrl_MainCounter++;
}
/* FUNCTIONS END */
/* STOP OF FILE */
