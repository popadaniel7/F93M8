#include "Dem.h"

uint8 Dem_DtcArray[DEM_NUMBER_OF_DTCS];
uint8 Dem_DtcArray_Default[DEM_NUMBER_OF_DTCS];
uint8 Dem_ControlDtcSetting = 0u;

void Dem_SetDtc(uint32 dtcId, uint8 dtcStatus, uint8 index);
void Dem_PreInit(void);
void Dem_Init(void);

void Dem_PreInit(void)
{
    for(uint8 i = 0u; i < DEM_NUMBER_OF_DTCS; i++)
    {
        Dem_DtcArray_Default[i] = 0x50u;
        Dem_DtcArray[i] = 0x50u;
    }
}

void Dem_Init(void)
{
    for(uint8 i = 0u; i < DEM_NUMBER_OF_DTCS; i++)
    {
        if(0u == i)
        {
            /* Do nothing. */
        }
        else if(1u == i)
        {
            Dem_DtcArray[i] = 0u;
        }
        else if(2u == i)
        {
            /* Do nothing. */
        }
        else
        {
            /* Do nothing. */
        }

        if(i % 2u == 1u && 2u < i)
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
    if(0u == Dem_ControlDtcSetting)
    {
        if(1u == dtcStatus)
        {
            if(1u == Dem_DtcArray[(index) * 2u + 1u] || 0u == Dem_DtcArray[(index) * 2u + 1u])
            {
                Dem_DtcArray[index * 2u] = (uint8)dtcId;
                Dem_DtcArray[index * 2u + 1u] = dtcStatus;
            }
            else
            {
                /* Do nothing. */
            }
        }
        else
        {
            if(1u == Dem_DtcArray[(index) * 2u + 1u])
            {
                Dem_DtcArray[index * 2u] = (uint8)dtcId;
                Dem_DtcArray[index * 2u + 1u] = dtcStatus;
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

void Dem_ClearDtc(void)
{
    for(uint8 i = 0u; i < DEM_NUMBER_OF_DTCS; i++)
    {
        Dem_DtcArray[i] = 0x50u;
    }
}
