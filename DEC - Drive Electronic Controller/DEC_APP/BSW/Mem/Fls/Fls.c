#include <string.h>
#include "Ifx_Types.h"
#include "Fls.h"
#include "IfxFlash.h"
#include "IfxCpu.h"

void Fls_WriteBlock(uint32 BlockAddress, uint32 *BlockData, uint32 DataLength);      /* Function that flashes the Data Flash memory     */
void Fls_ReadBlock(uint32 BlockAddress, uint32 *BlockData, uint32 DataLength);
void Fls_Erase(uint32 sectorAddress);

void Fls_ReadBlock(uint32 BlockAddress, uint32 *BlockData, uint32 DataLength)
{
    uint32 numPages = (DataLength + DFLASH_PAGE_LENGTH - 1u) / DFLASH_PAGE_LENGTH; /* Calculate required pages */
    for (uint32 page = 0u; page < numPages; page++)
    {
        uint32 pageAddr = BlockAddress + (page * DFLASH_PAGE_LENGTH); /* Calculate the address for each page */
        /* Read the data directly from the Data Flash memory */
        uint32 dataIndex = page * (DFLASH_PAGE_LENGTH / sizeof(uint32));

        if (dataIndex < DataLength)
        {
            BlockData[dataIndex] = MEM(pageAddr);
        }
        else
        {
            /* Do nothing. */
        }

        if ((dataIndex + 1u) < DataLength)
        {
            BlockData[dataIndex + 1u] = MEM(pageAddr + 4u);
        }
        else
        {
            /* Do nothing. */
        }
    }
}
/* This function flashes the Data Flash memory.
 * It is not needed to run this function from the PSPR, thus functions from the Program Flash memory can be called
 * inside.
 */
void Fls_WriteBlock(uint32 BlockAddress, uint32 *BlockData, uint32 DataLength)
{
    uint16 endInitSafetyPassword = IfxScuWdt_getSafetyWatchdogPassword();
    /* Calculate the number of pages needed */
    uint32 numPages = (DataLength + DFLASH_PAGE_LENGTH - 1u) / DFLASH_PAGE_LENGTH;
    for (uint32 page = 0u; page < numPages; page++)
    {
        uint32 pageAddr = BlockAddress + (page * DFLASH_PAGE_LENGTH); /* Get correct address */
        /* Enter in page mode */
        IfxFlash_enterPageMode(pageAddr);
        IfxFlash_waitUnbusy(FLASH_MODULE, IfxFlash_FlashType_D0);
        /* Load two words of data at a time */
        uint32 dataIndex = page * (DFLASH_PAGE_LENGTH / sizeof(uint32));
        uint32 data1 = (dataIndex < DataLength) ? BlockData[dataIndex] : 0xFFFFFFFF;
        uint32 data2 = ((dataIndex + 1) < DataLength) ? BlockData[dataIndex + 1u] : 0xFFFFFFFF;
        IfxFlash_loadPage2X32(pageAddr, data1, data2);
        /* Write the loaded page */
        IfxScuWdt_clearSafetyEndinit(endInitSafetyPassword);
        IfxFlash_writePage(pageAddr);
        IfxScuWdt_setSafetyEndinit(endInitSafetyPassword);
        /* Wait until the data is written */
        IfxFlash_waitUnbusy(FLASH_MODULE, IfxFlash_FlashType_D0);
    }
}

void Fls_Erase(uint32 sectorAddress)
{
    uint16 password = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(password);
    IfxFlash_eraseSector(sectorAddress);
    IfxScuWdt_setSafetyEndinit(password);
}
