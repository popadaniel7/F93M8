#define DFLASH_PAGE_LENGTH          IFXFLASH_DFLASH_PAGE_LENGTH /* 0x8 = 8 Bytes (smallest unit that can be programmed in the Data Flash memory (DFLASH))    */
#define DATA_FLASH_0                IfxFlash_FlashType_D0       /* Define the Data Flash Bank to be used            */
#define DFLASH_STARTING_ADDRESS     0xAF000000                  /* Address of the DFLASH where the data is written  */
#define DFLASH_NUM_PAGE_TO_FLASH    8                           /* Number of pages to flash in the DFLASH           */
#define MEM(address)                *((uint32 *)(address))      /* Macro to simplify the access to a memory address */
#define FLASH_MODULE                0                           /* Macro to select the flash (PMU) module           */
#define DFLASH_PAGE_LENGTH          IFXFLASH_DFLASH_PAGE_LENGTH /* 8 Bytes */
#define DFLASH_STARTING_ADDRESS     0xAF000000  /* Start Address of Data Flash */
#define DFLASH_SECTOR_SIZE          (128 * 1024) /* 128 KB per sector */
#define DFLASH_NUM_SECTORS          2 /* Number of DFLASH sectors used for EEPROM emulation */
#define BLOCK_HEADER_SIZE           8 /* Block metadata header size (ID + Status) */

/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
extern void Fls_WriteBlock(uint32 BlockAddress, uint32 *BlockData, uint32 DataLength);      /* Function that flashes the Data Flash memory     */
extern void Fls_ReadBlock(uint32 BlockAddress, uint32 *BlockData, uint32 DataLength);
extern void Fls_Erase(uint32 sectorAddress);

