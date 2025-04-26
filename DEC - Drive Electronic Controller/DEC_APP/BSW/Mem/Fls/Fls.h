
#define DFLASH_PAGE_LENGTH          IFXFLASH_DFLASH_PAGE_LENGTH
#define DFLASH_STARTING_ADDRESS     0xAF000000u
#define MEM(address)                *((uint32 *)(address))
#define FLASH_MODULE                0u
#define DFLASH_PAGE_LENGTH          IFXFLASH_DFLASH_PAGE_LENGTH
#define DFLASH_STARTING_ADDRESS     0xAF000000u
#define DFLASH_SECOND_SECTOR_ADDRESS 0xAF020000U

extern void Fls_WriteBlock(uint32 BlockAddress, uint32 *BlockData, uint32 DataLength);
extern void Fls_ReadBlock(uint32 BlockAddress, uint32 *BlockData, uint32 DataLength);
extern void Fls_Erase(void);

