#include "Std_Types.h"

typedef struct
{
	uint32 counter;
	uint8 isActiveNow;
	uint8 VoltageFF[3];
	uint8 SpeedFF[3];
	uint8 RpmFF[3];
	uint8 TimeFF[3];;
	uint8 IgnFF[3];
	uint8 GearFF[3];
	uint32 ReasonFF[3];
}Dem_DTC_t;

#define DEM_NUMBER_OF_DTCS 18

extern void Dem_SetDtc(uint8 IDPrimary, uint32 Reason, uint8 Status);
extern void Dem_MainFunction(void);
