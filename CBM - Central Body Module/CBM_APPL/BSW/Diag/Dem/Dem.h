/* START OF FILE */
/* INCLUDE START */
#include "Std_Types.h"
/* INCLUDE END */
/* VARIABLES START */
typedef struct
{
	uint32 counter;
	uint32 isActiveNow;
	uint8 VoltageFF[3];
	uint8 SpeedFF[3];
	uint8 RpmFF[3];
	uint8 TimeFF[3];;
	uint8 IgnFF[3];
	uint8 GearFF[3];
}Dem_DTC_t;

extern Dem_DTC_t Dem_DTCStoreArray[13];
/* VARIABLES STOP */
/* FUNCTIONS START */
extern void Dem_SaveDtc(uint8 index, uint8 status);
/* FUNCTIONS STOP */
/* STOP OF FILE */
