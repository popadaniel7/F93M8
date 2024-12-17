#include "Dem.h"
#include "can.h"
#include <string.h>

Dem_DTC_t Dem_DTCArray[DEM_NUMBER_OF_DTCS];
uint8 Dem_DTCSettingDeactivated = 0;
CAN_TxHeaderTypeDef Dem_TxHeader = {0, 0, 0, 0, 0, 0};
uint8 Dem_TxData[8] = {0};
uint32 Dem_TxMailbox = 0;

extern uint8 CanH_TxSig_SupplyVoltage;
extern uint8 CanH_RxSig_Gear;
extern uint8 CanH_RxSig_Ignition;
extern uint8 CanH_RxSig_Rpm;
extern uint8 CanH_RxSig_Speed;
extern __attribute__((section(".ncr"))) uint32 Dcm_AliveCounter;

void Dem_SetDtc(uint8 IDPrimary, uint32 Reason, uint8 Status);
void Dem_ClearDtc(void);

void Dem_ClearDtc(void)
{
	memset(Dem_DTCArray, 0, sizeof(Dem_DTCArray));
}
void Dem_SetDtc(uint8 IDPrimary, uint32 Reason, uint8 Status)
{
	uint8 i = 0;
	if(0 == Dem_DTCSettingDeactivated)
	{
		if(1 == Status)
		{
			Dem_TxHeader.DLC = 1;
			Dem_TxHeader.StdId = 0x10D;
			Dem_TxData[0] = IDPrimary;

			HAL_CAN_AddTxMessage(&hcan, &Dem_TxHeader, Dem_TxData, &Dem_TxMailbox);

			for(i = 0; i < 3; i++)
			{
				if(0 != Dem_DTCArray[IDPrimary].GearFF[i]) break;
				else
				{
					/* Do nothing. */
				}
			}

			Dem_DTCArray[IDPrimary].counter++;
			Dem_DTCArray[IDPrimary].isActiveNow = 1;
			Dem_DTCArray[IDPrimary].GearFF[i] = CanH_RxSig_Gear;
			Dem_DTCArray[IDPrimary].IgnFF[i] = CanH_RxSig_Ignition;
			Dem_DTCArray[IDPrimary].RpmFF[i] = CanH_RxSig_Rpm;
			Dem_DTCArray[IDPrimary].ReasonFF[i] = Reason;
			Dem_DTCArray[IDPrimary].SpeedFF[i] = CanH_RxSig_Speed;
			Dem_DTCArray[IDPrimary].TimeFF[i] = Dcm_AliveCounter;
			Dem_DTCArray[IDPrimary].VoltageFF[i] = CanH_TxSig_SupplyVoltage;
		}
		else Dem_DTCArray[IDPrimary].isActiveNow = 0;
	}
	else
	{
		/* Do nothing. */
	}
}
