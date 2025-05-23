#include "Ifx_Types.h"

#define NVM_NO_BLOCKS               5U //+1, first is not used
#define NVM_SIZE_HEADER_BYTES       8U // Data-flash write done in 8 bytes at a time

typedef struct
{
        uint8 blockId;
        uint16 blockSize;
        uint8 padding1;
        uint32 padding2;
}Nvm_Header_t;

typedef struct
{
        uint16 blockSize;
        uint32 blockAddress;
        uint16 padding1;
}Nvm_NvStat_t;

typedef struct
{
        uint32* data;
        uint32 crc;
}Nvm_Block_t;

extern uint32 Nvm_CurrentAddress;
extern uint32 Nvm_SectorSwitchActivated;
extern uint32 Nvm_CurrentSector;
extern Nvm_Header_t Nvm_HeaderArr[NVM_NO_BLOCKS];
extern Nvm_NvStat_t Nvm_NvStatArr[NVM_NO_BLOCKS];
extern Nvm_Block_t Nvm_BlockDataList[NVM_NO_BLOCKS];
extern Nvm_Block_t Nvm_RomDefaults_BlockDataList[NVM_NO_BLOCKS];
extern uint8 Nvm_WriteAllFinished;
extern uint8 Nvm_ReadAllFinished;

extern void Nvm_SectorSwitch(void);
extern void Nvm_WriteBlock(uint16 blockId, uint32 *data);
extern void Nvm_FindCurrentAddress();
extern void Nvm_ReadAll(void);
extern void Nvm_WriteAll(void);
