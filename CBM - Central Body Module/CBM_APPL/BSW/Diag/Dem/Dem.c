/* START OF FILE */
/* INCLUDE START */
#include "Dem.h"
#include "CanSpi.h"
/* INCLUDE END */
/* VARIABLES START */
CANSPI_uCAN_MSG Dem_DtcMessage;
uint8 Dem_ControlDtcSettingStatus = 0;
uint32 Dem_DTCStoreArray[DEM_SIZE_OF_DTC_ARRAY];
/* VARIABLES STOP */
/* FUNCTIONS START */
void Dem_SaveDtc(uint8 index, uint8 status);
/* FUNCTIONS STOP */
/* FUNCTIONS START */
void Dem_SaveDtc(uint8 index, uint8 status)
{
	__disable_irq();
	/* Store DTC. */
	if(0 == Dem_ControlDtcSettingStatus)
	{
		if(1 == status)
		{
			if(Dem_DTCStoreArray[(index - 0x01) * 2 + 1] == 1 || Dem_DTCStoreArray[(index - 0x01) * 2 + 1] == 0)
			{
				Dem_DtcMessage.frame.idType = 1;
				Dem_DtcMessage.frame.id = 0x10C;
				Dem_DtcMessage.frame.dlc = 1;
				Dem_DtcMessage.frame.data0 = index;
				CanSpi_Transmit(&Dem_DtcMessage);
				Dem_DTCStoreArray[(index - 0x01) * 2] = index;
				Dem_DTCStoreArray[(index - 0x01) * 2 + 1] = status + 1;
			}
			else
			{
				/* Do nothing. */
			}
		}
		else
		{
			if(Dem_DTCStoreArray[(index - 0x01) * 2 + 1] == 1)
			{
				Dem_DTCStoreArray[(index - 0x01) * 2] = index;
				Dem_DTCStoreArray[(index - 0x01) * 2 + 1] = status + 1;
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
	__enable_irq();
}
/* FUNCTIONS STOP */
/* STOP OF FILE */
