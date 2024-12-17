#include "LoadCtrl.h"
#include "main.h"
#include "Dem.h"
#include <stdlib.h>

float LoadCtrl_VoltValueToActualAmperage = 0; /* Final value of current consumption. */
float LoadCtrl_AdcVoltToActualVolt = 0; /* Final value of voltage level. */
uint16 LoadCtrl_MainCounter = 0;
uint16 LoadCtrl_AnalogVoltValue = 0;
uint16 LoadCtrl_AnalogCurrentValue = 0;
uint16 LoadCtrl_VrefInt = 0;
uint8 LoadCtrl_StatusList[8] = {0};
uint8 DiagLoadCtrl_StatusList[8] = {0};
uint8 CanH_RxSig_CommandList1 = 1;
uint8 CanH_RxSig_CommandList2 = 1;
uint8 CanH_RxSig_CommandList3 = 1;
uint8 CanH_RxSig_CommandList4 = 1;
uint8 CanH_RxSig_CommandList5 = 1;
uint8 CanH_RxSig_CommandList6 = 1;
uint8 CanH_RxSig_CommandList7 = 1;
uint8 CanH_RxSig_CommandList8 = 1;
uint8 CanH_TxSig_StatusList1 = 0;
uint8 CanH_TxSig_StatusList2 = 0;
uint8 CanH_TxSig_StatusList3 = 0;
uint8 CanH_TxSig_StatusList4 = 0;
uint8 CanH_TxSig_StatusList5 = 0;
uint8 CanH_TxSig_StatusList6 = 0;
uint8 CanH_TxSig_StatusList7 = 0;
uint8 CanH_TxSig_StatusList8 = 0;
uint8 CanH_TxSig_SupplyVoltage = 0;
uint8 CanH_TxSig_TotalCurrentConsumption = 0;
uint8 CanH_TxSig_TotalCurrentConsumption2 = 0;
uint8 CanH_TxSig_PowerSupplyNetworkWarning = 0;
uint8 Param_MaxVoltageValue = 0;
uint8 Param_MinVoltageValue = 0;
uint8 Param_NominalCurrentRating = 0;
uint8 Param_MaximumCurrentRating = 0;
uint8 Param_I2tRating = 0;
__attribute__((section(".ncr"))) uint32 LoadCtrl_I2tCounter;
__attribute__((section(".ncr"))) uint8 LoadCtrl_SwitchOffFlag;
__attribute__((section(".ncr"))) uint8 LoadCtrl_PermanentSwitchOff_Rin1;
__attribute__((section(".ncr"))) uint8 LoadCtrl_PermanentSwitchOff_Rin2;
__attribute__((section(".ncr"))) uint8 LoadCtrl_PermanentSwitchOff_Rin3;
__attribute__((section(".ncr"))) uint8 LoadCtrl_PermanentSwitchOff_Rin4;
__attribute__((section(".ncr"))) uint8 LoadCtrl_PermanentSwitchOff_Rin5;
__attribute__((section(".ncr"))) uint8 LoadCtrl_PermanentSwitchOff_Rin6;
__attribute__((section(".ncr"))) uint8 LoadCtrl_PermanentSwitchOff_Rin7;
__attribute__((section(".ncr"))) uint8 LoadCtrl_PermanentSwitchOff_Rin8;
__attribute__((section(".ncr"))) uint8 LoadCtrl_Rin1Counter;
__attribute__((section(".ncr"))) uint8 LoadCtrl_Rin2Counter;
__attribute__((section(".ncr"))) uint8 LoadCtrl_Rin3Counter;
__attribute__((section(".ncr"))) uint8 LoadCtrl_Rin4Counter;
__attribute__((section(".ncr"))) uint8 LoadCtrl_Rin5Counter;
__attribute__((section(".ncr"))) uint8 LoadCtrl_Rin6Counter;
__attribute__((section(".ncr"))) uint8 LoadCtrl_Rin7Counter;
__attribute__((section(".ncr"))) uint8 LoadCtrl_Rin8Counter;
__attribute__((section(".ncr"))) uint8 LoadCtrl_LockRin1;
__attribute__((section(".ncr"))) uint8 LoadCtrl_LockRin2;
__attribute__((section(".ncr"))) uint8 LoadCtrl_LockRin3;
__attribute__((section(".ncr"))) uint8 LoadCtrl_LockRin4;
__attribute__((section(".ncr"))) uint8 LoadCtrl_LockRin5;
__attribute__((section(".ncr"))) uint8 LoadCtrl_LockRin6;
__attribute__((section(".ncr"))) uint8 LoadCtrl_LockRin7;
__attribute__((section(".ncr"))) uint8 LoadCtrl_LockRin8;

void LoadCtrl_MainFunction(void);

void LoadCtrl_MainFunction(void)
{
	static float aux1 = 0;
	static uint16 aux2 = 0;
	static float aux3 = 0;
	aux1 = (1.2 * 4095.0) / LoadCtrl_VrefInt; /* Get the actual VAREF (expectation is to have it < 3.3V, since voltage drops occurs on
	the 5V power supply line due to consumers). */
	LoadCtrl_AdcVoltToActualVolt = ((LoadCtrl_AnalogVoltValue * aux1) / 4095.0) * 5; /* Use the VAREF previously calculated to get the voltage level.
	Note: Supply line monitored is 5V; voltage supply for the voltage sensor and current sensor is 5V; VAREF for both sensors is 5V in this scenario.
	However, they can measure values up to 25V and 5A and since the voltage drops occurs on the power line, they can never output their maximum potential.
	That means we can never exceed 3.3V on the analog inputs.
	And the extra-compensation done here is because of the voltage drop. Calculating the current VAREF allows for proper measurements. */
	aux3 = (LoadCtrl_AnalogCurrentValue * aux1) / 4095.0; /* Convert the output pin of the current sensor to voltage value. */
	LoadCtrl_VoltValueToActualAmperage = (((LoadCtrl_AdcVoltToActualVolt / 5) * 2.5) - aux3) / 0.185; /* Calculate current value.
	We know the voltage drops below 5V, that means the following:
	- The output pin of the current sensor in no-load-or-consumer-state is no longer 2.49 / 2.5 volts, but less; this is compensated by the fact that we accurately measure
	the voltage value of the supply line with the voltage sensor
	- The output pin state of the current sensor during loads connection is going to be less than expected if we had 5V stable supply. Anyway, it is subtracted from a value compensated.
	- 0.185 is in mV, or the sensor sensitivity. */
	for(uint8 i = 0; i < 8; i++)
	{
		if(LoadCtrl_StatusList[0] == 0) aux2++;
		else
		{
			/* Do nothing */
		}
	}
	/* PDM is on the same board as CBM
	 * Normal operation is with no relay activated and no other consumers connected
	 * but the CBM board with HC05 and MCP2515 always supplied
	 * PDM board supplied, with the current and voltage sensor as well as the relay board.
	 * Normal operation current is 0.11 - 0.13 A
	 * QC current (PDM CBM MCUs in STANDBY) is 0.07 A
	 * Relay control pins are set to output HIGH level Pull-up
	 * Triggering a relay adds 130 mA to the measurement, when it should add 0.65 mA.
	 * Assumption is that the relay NOCS cannot be measured due to the hardware setup.
	 * So a correction is required.
	 * Tested with 1.2 A load, 0.3 A load. */
	LoadCtrl_VoltValueToActualAmperage -= 0.13 * aux2;
	/* No fault detected. */
	if(0 == LoadCtrl_SwitchOffFlag)
	{
		if(!DiagLoadCtrl_StatusList[0]) LoadCtrl_StatusList[0] = CanH_RxSig_CommandList1;
		if(!DiagLoadCtrl_StatusList[1]) LoadCtrl_StatusList[1] = CanH_RxSig_CommandList2;
		if(!DiagLoadCtrl_StatusList[2]) LoadCtrl_StatusList[2] = CanH_RxSig_CommandList3;
		if(!DiagLoadCtrl_StatusList[3]) LoadCtrl_StatusList[3] = CanH_RxSig_CommandList4;
		if(!DiagLoadCtrl_StatusList[4]) LoadCtrl_StatusList[4] = CanH_RxSig_CommandList5;
		if(!DiagLoadCtrl_StatusList[5]) LoadCtrl_StatusList[5] = CanH_RxSig_CommandList6;
		if(!DiagLoadCtrl_StatusList[6]) LoadCtrl_StatusList[6] = CanH_RxSig_CommandList7;
		if(!DiagLoadCtrl_StatusList[7]) LoadCtrl_StatusList[7] = CanH_RxSig_CommandList8;
	}
	else
	{
		/* Do nothing. */
	}
	/* 10 milliseconds de-bounce before checks. */
	if(2 <= LoadCtrl_MainCounter)
	{
		/* Send on CAN measured values.*/
		CanH_TxSig_TotalCurrentConsumption = LoadCtrl_VoltValueToActualAmperage;
		CanH_TxSig_TotalCurrentConsumption2 = ((uint8)LoadCtrl_VoltValueToActualAmperage * 100) % 100;
		CanH_TxSig_SupplyVoltage = LoadCtrl_AdcVoltToActualVolt * 10;
		/* If current consumption is below nominal. */
		if(Param_NominalCurrentRating >= LoadCtrl_VoltValueToActualAmperage)
		{
			/* Simulate cable cooling off. */
			if(LoadCtrl_I2tCounter >= Param_NominalCurrentRating * Param_NominalCurrentRating * 5) LoadCtrl_I2tCounter -=  Param_NominalCurrentRating * Param_NominalCurrentRating * 5;
			else
			{
				/* If not in under-voltage. */
				if(Param_MinVoltageValue <= LoadCtrl_AdcVoltToActualVolt)
				{
					/* Set the DTC accordingly. */
					if(1 == LoadCtrl_Rin1Counter && 0 == LoadCtrl_Rin2Counter)
					{
						LoadCtrl_PermanentSwitchOff_Rin1++;
						Dem_SetDtc(0, 1, 1);
					}
					else if(1 == LoadCtrl_Rin2Counter && 0 == LoadCtrl_Rin3Counter)
					{
						LoadCtrl_PermanentSwitchOff_Rin2++;
						Dem_SetDtc(1, 1, 1);
					}
					else if(1 == LoadCtrl_Rin3Counter  && 0 == LoadCtrl_Rin4Counter)
					{
						LoadCtrl_PermanentSwitchOff_Rin3++;
						Dem_SetDtc(2, 1, 1);
					}
					else if(1 == LoadCtrl_Rin4Counter && 0 == LoadCtrl_Rin5Counter)
					{
						LoadCtrl_PermanentSwitchOff_Rin4++;
						Dem_SetDtc(3, 1, 1);
					}
					else if(1 == LoadCtrl_Rin5Counter && 0 == LoadCtrl_Rin6Counter)
					{
						LoadCtrl_PermanentSwitchOff_Rin5++;
						Dem_SetDtc(4, 1, 1);
					}
					else if(1 == LoadCtrl_Rin6Counter && 0 == LoadCtrl_Rin7Counter)
					{
						LoadCtrl_PermanentSwitchOff_Rin6++;
						Dem_SetDtc(5, 1, 1);
					}
					else if(1 == LoadCtrl_Rin7Counter && 0 == LoadCtrl_Rin8Counter)
					{
						LoadCtrl_PermanentSwitchOff_Rin7++;
						Dem_SetDtc(6, 1, 1);
					}
					else if(1 == LoadCtrl_Rin8Counter)
					{
						LoadCtrl_PermanentSwitchOff_Rin8++;
						Dem_SetDtc(7, 1, 1);
					}
					else
					{
						Dem_SetDtc(0, 1, 0);
						Dem_SetDtc(1, 1, 0);
						Dem_SetDtc(2, 1, 0);
						Dem_SetDtc(3, 1, 0);
						Dem_SetDtc(4, 1, 0);
						Dem_SetDtc(5, 1, 0);
						Dem_SetDtc(6, 1, 0);
						Dem_SetDtc(7, 1, 0);
					}
				}
				else
				{
					/* Do nothing. */
				}
				/* Reset variables. */
				CanH_TxSig_PowerSupplyNetworkWarning &= ~(1 << 0);
				LoadCtrl_I2tCounter = 0;
				LoadCtrl_Rin1Counter = 0;
				LoadCtrl_Rin2Counter = 0;
				LoadCtrl_Rin3Counter = 0;
				LoadCtrl_Rin4Counter = 0;
				LoadCtrl_Rin5Counter = 0;
				LoadCtrl_Rin6Counter = 0;
				LoadCtrl_Rin7Counter = 0;
				LoadCtrl_Rin8Counter = 0;
				LoadCtrl_SwitchOffFlag = 0;
			}
		}
		else if(Param_NominalCurrentRating < LoadCtrl_VoltValueToActualAmperage &&
				Param_MaximumCurrentRating >= LoadCtrl_VoltValueToActualAmperage)
		{
			/* Update status on CAN. */
			CanH_TxSig_PowerSupplyNetworkWarning |= (1 << 0);
			/* Accumulate I2T. */
			LoadCtrl_I2tCounter += LoadCtrl_VoltValueToActualAmperage * LoadCtrl_VoltValueToActualAmperage * 5;
			/* Set flag to start switching off loads. */
			if(Param_I2tRating * 1000 <= LoadCtrl_I2tCounter) LoadCtrl_SwitchOffFlag = 1;
		}
		else if(Param_MaximumCurrentRating < LoadCtrl_VoltValueToActualAmperage)
		{
			/* Update status on CAN. */
			CanH_TxSig_PowerSupplyNetworkWarning |= (1 << 0);
			/* Set flag to start switching off loads. */
			LoadCtrl_SwitchOffFlag = 1;
		}
		else
		{
			/* Do nothing. */
		}
		/* If in under-voltage, switch off all the loads except for the first two (CBM and DEC) (<2v5). */
		if(Param_MinVoltageValue > LoadCtrl_AdcVoltToActualVolt)
		{
			CanH_TxSig_PowerSupplyNetworkWarning |= (1 << 1);
			HAL_GPIO_WritePin(RIN3_GPIO_Port, RIN3_Pin, 0);
			HAL_GPIO_WritePin(RIN4_GPIO_Port, RIN4_Pin, 0);
			HAL_GPIO_WritePin(RIN5_GPIO_Port, RIN5_Pin, 0);
			HAL_GPIO_WritePin(RIN6_GPIO_Port, RIN6_Pin, 0);
			HAL_GPIO_WritePin(RIN7_GPIO_Port, RIN7_Pin, 0);
			HAL_GPIO_WritePin(RIN8_GPIO_Port, RIN8_Pin, 0);
			LoadCtrl_SwitchOffFlag = 2;
			for(uint8 i = 2; i < 8; i++) LoadCtrl_StatusList[i] = 0;
			Dem_SetDtc(8, 1, 1);
		}
		else
		{
			CanH_TxSig_PowerSupplyNetworkWarning &= ~(1 << 1);
			Dem_SetDtc(8, 1, 0);
		}
		/* Switch off all the loads (DEC, CBM, DMU) to prevent damage in over-voltage (>5v5). */
		if(Param_MaxVoltageValue < LoadCtrl_AdcVoltToActualVolt)
		{
			CanH_TxSig_PowerSupplyNetworkWarning |= (1 << 2);
			HAL_GPIO_WritePin(RIN1_GPIO_Port, RIN1_Pin, 0);
			HAL_GPIO_WritePin(RIN2_GPIO_Port, RIN2_Pin, 0);
			HAL_GPIO_WritePin(RIN3_GPIO_Port, RIN3_Pin, 0);
			Dem_SetDtc(9, 1, 1);
			LoadCtrl_SwitchOffFlag = 2;
			for(uint8 i = 0; i < 8; i++) LoadCtrl_StatusList[i] = 0;
		}
		else
		{
			Dem_SetDtc(9, 1, 0);
			CanH_TxSig_PowerSupplyNetworkWarning &= ~(1 << 2);
		}
		/* Brute searching the faulty load... */
		if(1 == LoadCtrl_SwitchOffFlag)
		{
			if(1 == LoadCtrl_StatusList[0])
			{
				LoadCtrl_StatusList[0] = 0;
				LoadCtrl_Rin1Counter = 1;
			}
			else if(0 == LoadCtrl_StatusList[0] && 1 == LoadCtrl_StatusList[1])
			{
				LoadCtrl_StatusList[0] = 0;
				LoadCtrl_Rin1Counter = 1;
				LoadCtrl_StatusList[1] = 0;
				LoadCtrl_Rin2Counter = 1;
			}
			else if(0 == LoadCtrl_StatusList[1] && 1 == LoadCtrl_StatusList[2])
			{
				LoadCtrl_StatusList[0] = 0;
				LoadCtrl_Rin1Counter = 1;
				LoadCtrl_StatusList[2] = 0;
				LoadCtrl_Rin3Counter = 1;
				LoadCtrl_StatusList[1] = 0;
				LoadCtrl_Rin2Counter = 1;
			}
			else if(0 == LoadCtrl_StatusList[2] &&
					1 == LoadCtrl_StatusList[3])
			{
				LoadCtrl_StatusList[0] = 0;
				LoadCtrl_Rin1Counter = 1;
				LoadCtrl_StatusList[3] = 0;
				LoadCtrl_Rin4Counter = 1;
				LoadCtrl_StatusList[2] = 0;
				LoadCtrl_Rin3Counter = 1;
				LoadCtrl_StatusList[1] = 0;
				LoadCtrl_Rin2Counter = 1;
			}
			else if(0 == LoadCtrl_StatusList[3] && 1 == LoadCtrl_StatusList[4])
			{
				LoadCtrl_StatusList[0] = 0;
				LoadCtrl_Rin1Counter = 1;
				LoadCtrl_StatusList[4] = 0;
				LoadCtrl_Rin5Counter = 1;
				LoadCtrl_StatusList[3] = 0;
				LoadCtrl_Rin4Counter = 1;
				LoadCtrl_StatusList[2] = 0;
				LoadCtrl_Rin3Counter = 1;
				LoadCtrl_StatusList[1] = 0;
				LoadCtrl_Rin2Counter = 1;
			}
			else if(0 == LoadCtrl_StatusList[4] && 1 == LoadCtrl_StatusList[5])
			{
				LoadCtrl_StatusList[0] = 0;
				LoadCtrl_Rin1Counter = 1;
				LoadCtrl_StatusList[5] = 0;
				LoadCtrl_Rin6Counter = 1;
				LoadCtrl_StatusList[4] = 0;
				LoadCtrl_Rin5Counter = 1;
				LoadCtrl_StatusList[3] = 0;
				LoadCtrl_Rin4Counter = 1;
				LoadCtrl_StatusList[2] = 0;
				LoadCtrl_Rin3Counter = 1;
				LoadCtrl_StatusList[1] = 0;
				LoadCtrl_Rin2Counter = 1;
			}
			else if(0 == LoadCtrl_StatusList[5] && 1 == LoadCtrl_StatusList[6])
			{
				LoadCtrl_StatusList[0] = 0;
				LoadCtrl_Rin1Counter = 1;
				LoadCtrl_StatusList[6] = 0;
				LoadCtrl_Rin7Counter = 1;
				LoadCtrl_StatusList[5] = 0;
				LoadCtrl_Rin6Counter = 1;
				LoadCtrl_StatusList[4] = 0;
				LoadCtrl_Rin5Counter = 1;
				LoadCtrl_StatusList[3] = 0;
				LoadCtrl_Rin4Counter = 1;
				LoadCtrl_StatusList[2] = 0;
				LoadCtrl_Rin3Counter = 1;
				LoadCtrl_StatusList[1] = 0;
				LoadCtrl_Rin2Counter = 1;
			}
			else if(0 == LoadCtrl_StatusList[6] && 1 == LoadCtrl_StatusList[7])
			{
				LoadCtrl_StatusList[0] = 0;
				LoadCtrl_Rin1Counter = 1;
				LoadCtrl_StatusList[7] = 0;
				LoadCtrl_Rin8Counter = 1;
				LoadCtrl_StatusList[6] = 0;
				LoadCtrl_Rin7Counter = 1;
				LoadCtrl_StatusList[5] = 0;
				LoadCtrl_Rin6Counter = 1;
				LoadCtrl_StatusList[4] = 0;
				LoadCtrl_Rin5Counter = 1;
				LoadCtrl_StatusList[3] = 0;
				LoadCtrl_Rin4Counter = 1;
				LoadCtrl_StatusList[2] = 0;
				LoadCtrl_Rin3Counter = 1;
				LoadCtrl_StatusList[1] = 0;
				LoadCtrl_Rin2Counter = 1;
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
		/* Permanent switching off of one faulty load. */
		if(3 == LoadCtrl_PermanentSwitchOff_Rin1)
		{
			LoadCtrl_LockRin1 = 1;
			LoadCtrl_StatusList[0] = LoadCtrl_LockRin1;
			LoadCtrl_PermanentSwitchOff_Rin1 = 0;
			Dem_SetDtc(10, 1, 1);
		}
		else
		{
			Dem_SetDtc(10, 1, 0);
		}
		if(3 == LoadCtrl_PermanentSwitchOff_Rin2)
		{
			LoadCtrl_LockRin2 = 1;
			LoadCtrl_StatusList[1] = LoadCtrl_LockRin2;
			LoadCtrl_PermanentSwitchOff_Rin2 = 0;
			Dem_SetDtc(11, 1, 1);
		}
		else
		{
			Dem_SetDtc(11, 1, 0);
		}
		if(3 == LoadCtrl_PermanentSwitchOff_Rin3)
		{
			LoadCtrl_LockRin3 = 1;
			LoadCtrl_StatusList[2] = LoadCtrl_LockRin3;
			LoadCtrl_PermanentSwitchOff_Rin3 = 0;
			Dem_SetDtc(12, 1, 1);
		}
		else
		{
			Dem_SetDtc(12, 1, 0);
		}
		if(3 == LoadCtrl_PermanentSwitchOff_Rin4)
		{
			LoadCtrl_LockRin4 = 1;
			LoadCtrl_StatusList[3] = LoadCtrl_LockRin4;
			LoadCtrl_PermanentSwitchOff_Rin4 = 0;
			Dem_SetDtc(13, 1, 1);
		}
		else
		{
			Dem_SetDtc(13, 1, 0);
		}
		if(3 == LoadCtrl_PermanentSwitchOff_Rin5)
		{
			LoadCtrl_LockRin5 = 1;
			LoadCtrl_StatusList[4] = LoadCtrl_LockRin5;
			LoadCtrl_PermanentSwitchOff_Rin5 = 0;
			Dem_SetDtc(14, 1, 1);
		}
		else
		{
			Dem_SetDtc(14, 1, 0);
		}
		if(3 == LoadCtrl_PermanentSwitchOff_Rin6)
		{
			LoadCtrl_LockRin6 = 1;
			LoadCtrl_StatusList[5] = LoadCtrl_LockRin6;
			LoadCtrl_PermanentSwitchOff_Rin6 = 0;
			Dem_SetDtc(15, 1, 1);
		}
		else
		{
			Dem_SetDtc(15, 1, 0);
		}
		if(3 == LoadCtrl_PermanentSwitchOff_Rin7)
		{
			LoadCtrl_LockRin7 = 1;
			LoadCtrl_StatusList[6] = LoadCtrl_LockRin7;
			LoadCtrl_PermanentSwitchOff_Rin7 = 0;
			Dem_SetDtc(16, 1, 1);
		}
		else
		{
			Dem_SetDtc(16, 1, 0);
		}
		if(3 == LoadCtrl_PermanentSwitchOff_Rin8)
		{
			LoadCtrl_LockRin8 = 1;
			LoadCtrl_StatusList[7] = LoadCtrl_LockRin8;
			LoadCtrl_PermanentSwitchOff_Rin8 = 0;
			Dem_SetDtc(17, 1, 1);
		}
		else
		{
			Dem_SetDtc(17, 1, 0);
		}
		/* Keep the loads off with this flag. */
		if(0 != LoadCtrl_LockRin1)
		{
			LoadCtrl_StatusList[0] = 0;
		}
		else
		{
			/* Do nothing. */
		}
		if(0 != LoadCtrl_LockRin2)
		{
			LoadCtrl_StatusList[1] = 0;
		}
		else
		{
			/* Do nothing. */
		}
		if(0 != LoadCtrl_LockRin3)
		{
			LoadCtrl_StatusList[2] = 0;
		}
		else
		{
			/* Do nothing. */
		}
		if(0 != LoadCtrl_LockRin4)
		{
			LoadCtrl_StatusList[3] = 0;
		}
		else
		{
			/* Do nothing. */
		}
		if(0 != LoadCtrl_LockRin5)
		{
			LoadCtrl_StatusList[4] = 0;
		}
		else
		{
			/* Do nothing. */
		}
		if(0 != LoadCtrl_LockRin6)
		{
			LoadCtrl_StatusList[5] = 0;
		}
		else
		{
			/* Do nothing. */
		}
		if(0 != LoadCtrl_LockRin7)
		{
			LoadCtrl_StatusList[8] = 0;
		}
		else
		{
			/* Do nothing. */
		}
		if(0 != LoadCtrl_LockRin8)
		{
			LoadCtrl_StatusList[7] = 0;
		}
		else
		{
			/* Do nothing. */
		}
		/* Update status on CAN.*/
		for(uint8 i = 0; i < 8; i++)
		{
			CanH_TxSig_StatusList1 = LoadCtrl_StatusList[0];
			CanH_TxSig_StatusList2 = LoadCtrl_StatusList[1];
			CanH_TxSig_StatusList3 = LoadCtrl_StatusList[2];
			CanH_TxSig_StatusList4 = LoadCtrl_StatusList[3];
			CanH_TxSig_StatusList5 = LoadCtrl_StatusList[4];
			CanH_TxSig_StatusList6 = LoadCtrl_StatusList[5];
			CanH_TxSig_StatusList7 = LoadCtrl_StatusList[6];
			CanH_TxSig_StatusList8 = LoadCtrl_StatusList[7];
		}
		/* Switch the loads according to their state. */
		HAL_GPIO_WritePin(RIN1_GPIO_Port, RIN1_Pin, LoadCtrl_StatusList[0]);
		HAL_GPIO_WritePin(RIN2_GPIO_Port, RIN2_Pin, LoadCtrl_StatusList[1]);
		HAL_GPIO_WritePin(RIN3_GPIO_Port, RIN3_Pin, LoadCtrl_StatusList[2]);
		HAL_GPIO_WritePin(RIN4_GPIO_Port, RIN4_Pin, LoadCtrl_StatusList[3]);
		HAL_GPIO_WritePin(RIN5_GPIO_Port, RIN5_Pin, LoadCtrl_StatusList[4]);
		HAL_GPIO_WritePin(RIN6_GPIO_Port, RIN6_Pin, LoadCtrl_StatusList[5]);
		HAL_GPIO_WritePin(RIN7_GPIO_Port, RIN7_Pin, LoadCtrl_StatusList[6]);
		HAL_GPIO_WritePin(RIN8_GPIO_Port, RIN8_Pin, LoadCtrl_StatusList[7]);
	}
	else
	{
		/* Do nothing. */
	}
	LoadCtrl_MainCounter++;
}
