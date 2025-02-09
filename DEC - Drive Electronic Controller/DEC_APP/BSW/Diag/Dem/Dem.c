#include "Dem.h"

uint8 Dem_DtcArray[DEM_NUMBER_OF_DTCS];

void Dem_SetDtc(uint32 dtcId, uint8 dtcStatus, uint8 index);
void Dem_Init(void);

void Dem_Init(void)
{
    for(uint8 i = 0; i < DEM_NUMBER_OF_DTCS; i++)
    {
        if(i % 2 == 1)
        {
            Dem_DtcArray[i] = 0u;
        }
        else
        {
            /* Do nothing. */
        }
    }
}

void Dem_SetDtc(uint32 dtcId, uint8 dtcStatus, uint8 index)
{
    if(dtcStatus != 0u)
    {
        Dem_DtcArray[index] = (uint8)dtcId;
        Dem_DtcArray[index + 1] = dtcStatus;
    }
    else
    {
        /* Do nothing. */
    }

    if(Dem_DtcArray[index] != 0u &&
            dtcStatus == 0u)
    {
        Dem_DtcArray[index] = (uint8)dtcId;
        Dem_DtcArray[index + 1] = dtcStatus;
    }
    else
    {
        /* Do nothing. */
    }
}

void Dem_ClearDtc(void)
{
    for(uint8 i = 0; i < DEM_NUMBER_OF_DTCS; i++)
    {
        Dem_DtcArray[i] = 0u;
    }
}
