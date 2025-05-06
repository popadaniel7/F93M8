#include <string.h>
#include "Ifx_Types.h"
#include "Fls.h"
#include "IfxFlash.h"
#include "IfxCpu.h"

void Fls_WriteBlock(uint32 BlockAddress, uint32 *BlockData, uint32 DataLength);
void Fls_ReadBlock(uint32 BlockAddress, uint32 *BlockData, uint32 DataLength);
void Fls_Erase(void);

void Fls_ReadBlock(uint32 BlockAddress, uint32 *BlockData, uint32 DataLength)
{
    uint32 numPages = (DataLength + DFLASH_PAGE_LENGTH - 1u) / DFLASH_PAGE_LENGTH;

    for(uint32 page = 0u; page < numPages; page++)
    {
        uint32 pageAddr = BlockAddress + (page * DFLASH_PAGE_LENGTH);
        uint32 dataIndex = page * (DFLASH_PAGE_LENGTH / sizeof(uint32));

        if(dataIndex < DataLength)
        {
            BlockData[dataIndex] = MEM(pageAddr);
        }
        else
        {
            /* Do nothing. */
        }

        if((dataIndex + 1u) < DataLength)
        {
            BlockData[dataIndex + 1u] = MEM(pageAddr + 4u);
        }
        else
        {
            /* Do nothing. */
        }
    }
}

void Fls_WriteBlock(uint32 BlockAddress, uint32 *BlockData, uint32 DataLength)
{
    uint16 endInitSafetyPassword = IfxScuWdt_getSafetyWatchdogPassword();
    uint32 numPages = (DataLength + DFLASH_PAGE_LENGTH - 1u) / DFLASH_PAGE_LENGTH;

    for(uint32 page = 0u; page < numPages; page++)
    {
        uint32 pageAddr = BlockAddress + (page * DFLASH_PAGE_LENGTH); /* Get correct address */

        IfxFlash_enterPageMode(pageAddr);
        IfxFlash_waitUnbusy(FLASH_MODULE, IfxFlash_FlashType_D0);

        uint32 dataIndex = page * (DFLASH_PAGE_LENGTH / sizeof(uint32));
        uint32 data1 = (dataIndex < DataLength) ? BlockData[dataIndex] : 0xFFFFFFFF;
        uint32 data2 = ((dataIndex + 1) < DataLength) ? BlockData[dataIndex + 1u] : 0xFFFFFFFF;

        IfxFlash_loadPage2X32(pageAddr, data1, data2);
        IfxScuWdt_clearSafetyEndinit(endInitSafetyPassword);
        IfxFlash_writePage(pageAddr);
        IfxScuWdt_setSafetyEndinit(endInitSafetyPassword);
        IfxFlash_waitUnbusy(FLASH_MODULE, IfxFlash_FlashType_D0);
    }
}

void Fls_Erase(void)
{
    IfxScuWdt_clearSafetyEndinit(IfxScuWdt_getSafetyWatchdogPassword());
    IfxFlash_eraseMultipleSectors(0xAF000000u, 64u);
    IfxFlash_waitUnbusy(FLASH_MODULE, IfxFlash_FlashType_D0);
    IfxScuWdt_setSafetyEndinit(IfxScuWdt_getSafetyWatchdogPassword());
}
