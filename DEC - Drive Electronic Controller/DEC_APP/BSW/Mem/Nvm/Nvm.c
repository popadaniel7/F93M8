#include <Nvm.h>
#include "Crc.h"
#include "string.h"
#include "Fls.h"
#include "EncCal.h"
#include "Dem.h"

extern EncCal_VOData_t EncCal_VODataComplete_Default;

uint32 Nvm_CurrentAddress;
uint32 Nvm_SectorSwitchActivated;
uint32 Nvm_CurrentSector;
Nvm_Header_t Nvm_HeaderArr[NVM_NO_BLOCKS];
Nvm_Header_t Nvm_HeaderArr_Default[NVM_NO_BLOCKS]=
{
        {0u, 0u, 0u, 0u}, // block 0 dummy not used
        {1u, ENCCAL_CALIBRATION_SIZE * 4u, 0u, 0u}, // calibration block
        {2u, ENCCAL_CODING_SIZE, 0u, 0u}, // coding block
        {3u, sizeof(EncCal_VODataComplete), 0u, 0u}, // VO data block
        {4u, DEM_NUMBER_OF_DTCS, 0u, 0u}, // dtc data block
};
Nvm_NvStat_t Nvm_NvStatArr[NVM_NO_BLOCKS];
Nvm_NvStat_t Nvm_NvStatArr_Default[NVM_NO_BLOCKS] =
{
        {0u, 0u, 0u}, // block 0 dummy not used
        {ENCCAL_CALIBRATION_SIZE * 4u, 0u, 0u,}, // calibration block
        {ENCCAL_CODING_SIZE, 0u, 0u}, // coding block
        {sizeof(EncCal_VODataComplete), 0u, 0u}, // VO data block
        {DEM_NUMBER_OF_DTCS, 0u, 0u}, // dtc data block
};
Nvm_Block_t Nvm_BlockDataList[NVM_NO_BLOCKS] =
{
        {NULL_PTR, 0u}, // block 0 dummy not used
        {(uint32*)&EncCal_Calibration_Buffer, 0u},
        {(uint32*)&EncCal_Coding_Buffer, 0u},
        {(uint32*)&EncCal_VODataComplete, 0u},
        {(uint32*)&Dem_DtcArray, 0u},
};
Nvm_Block_t Nvm_RomDefaults_BlockDataList[NVM_NO_BLOCKS] =
{
        {NULL_PTR, 0u}, // block 0 dummy not used
        {(uint32*)&EncCal_Calibration_DefaultBuffer, 0u},
        {(uint32*)&EncCal_Coding_DefaultBuffer, 0u},
        {(uint32*)&EncCal_VODataComplete_Default, 0u},
        {(uint32*)&Dem_DtcArray, 0u},
};
uint8 Nvm_BlockIdListForWriteAll[NVM_NO_BLOCKS] = {0u, 0u, 0u, 0u};//, 1u}
uint8 Nvm_WriteAllFinished;
uint8 Nvm_ReadAllFinished;

void Nvm_SectorSwitch(void);
void Nvm_WriteBlock(uint16 blockId, uint32 *data);
void Nvm_ReadBlock(uint32 blockId, uint32 *data);
void Nvm_FindCurrentAddress();
void Nvm_ReadAll(void);
void Nvm_WriteAll(void);

void Nvm_SectorSwitch(void)
{
    IfxCpu_disableInterrupts();

    uint32 startPattern[2] = {0, 0};

    Fls_Erase(0xAF000000u);
    Fls_Erase(0xAF040000u);
    Nvm_CurrentAddress = 0xAF000000u;
    /* Write sector pattern, assumption is that the data-flash is empty. */
    startPattern[0] = 0xA5A5u;
    startPattern[1] = 0xA5A5u;
    Fls_WriteBlock(Nvm_CurrentAddress, (uint32*)&startPattern, 8u);
    Nvm_CurrentAddress += 8u;

    for(uint8 i = 0u; i < NVM_NO_BLOCKS; i++)
    {
        Nvm_WriteBlock(i, (uint32*)&Nvm_BlockDataList[i].data);
    }

    IfxCpu_enableInterrupts();
}

void Nvm_WriteBlock(uint16 blockId, uint32 *data)
{
    IfxCpu_disableInterrupts();

    uint32 address = 0u;
    uint32 crc = 0u;
    uint32 crcPadded[2] = {0u};
    uint16 size = 0u;

    address = Nvm_CurrentAddress;
    size = Nvm_NvStatArr[blockId].blockSize / 4u;
    crc = Crc_Calculate(data, size, 0u);

    if((address + NVM_SIZE_HEADER_BYTES + Nvm_NvStatArr[blockId].blockSize + 8) < 0xAF040000)
    {
        Fls_WriteBlock(address, (uint32*)&Nvm_HeaderArr[blockId], NVM_SIZE_HEADER_BYTES);
        address += NVM_SIZE_HEADER_BYTES;
        Nvm_NvStatArr[blockId].blockAddress = address;
        Fls_WriteBlock(address, data, Nvm_NvStatArr[blockId].blockSize);
        address += Nvm_NvStatArr[blockId].blockSize;
        crcPadded[0] = crc;
        Fls_WriteBlock(address, (uint32*)&crcPadded, 8u);
        address += 8u;
        Nvm_CurrentAddress = address;
    }
    else
    {
        /* Sector switch. */
        __debug();
        Nvm_SectorSwitch();
        Fls_WriteBlock(address, (uint32*)&Nvm_HeaderArr[blockId], NVM_SIZE_HEADER_BYTES);
        address += NVM_SIZE_HEADER_BYTES;
        Fls_WriteBlock(address, data, Nvm_NvStatArr[blockId].blockSize);
        address += Nvm_NvStatArr[blockId].blockSize;
        Fls_WriteBlock(address, &crc, 8u);
        address += 8u;
        Nvm_CurrentAddress = address;
    }

    IfxCpu_enableInterrupts();
}
void Nvm_ReadBlock(uint32 blockId, uint32 *data)
{
    IfxCpu_disableInterrupts();
    data = Nvm_BlockDataList[blockId].data;
    IfxCpu_enableInterrupts();
}

void Nvm_FindCurrentAddress()
{
    IfxCpu_disableInterrupts();

    uint32 localAddress = Nvm_CurrentAddress;
    uint32 startPattern[2] = {0, 0};
    Nvm_Header_t localHeader;
    uint8 localBlockId = 0u;
    uint8 localBlockCounter = 0u;

    if(0u == localAddress)
    {
        localAddress = DFLASH_STARTING_ADDRESS;
        Nvm_CurrentAddress = localAddress;
    }
    else
    {
        /* Do nothing. */
    }

    if(DFLASH_STARTING_ADDRESS == localAddress ||
            DFLASH_SECOND_SECTOR_ADDRESS == localAddress)
    {
        /* Read start pattern of the sector. */
        Fls_ReadBlock(localAddress, (uint32*)&startPattern, 8u);

        if(0xA5A5A5A5U == startPattern[0] && 0xA5A5A5A5U == startPattern[1])
        {
            /* Sector pattern identified, proceed with header identification. */
            localAddress += 8u;

            while(localAddress + 8u < 0xAF040000)
            {
                Fls_ReadBlock(localAddress, (uint32*)&localHeader, NVM_SIZE_HEADER_BYTES);

                localBlockId = localHeader.blockId;

                if(0u != localBlockId
                        && NVM_NO_BLOCKS > localBlockId)
                {
                    if(localHeader.blockId == Nvm_HeaderArr_Default[localBlockId].blockId
                            && localHeader.blockSize == Nvm_HeaderArr_Default[localBlockId].blockSize)
                    {
                        Nvm_HeaderArr[localBlockId].blockId = localHeader.blockId;
                        Nvm_HeaderArr[localBlockId].blockSize = localHeader.blockSize;
                        Nvm_NvStatArr[localBlockId].blockSize = localHeader.blockSize;
                        Nvm_NvStatArr[localBlockId].blockAddress = localAddress + 8u;
                        localAddress += localHeader.blockSize + 8u; // 8u crc size and padding
                        Nvm_CurrentAddress = localAddress;
                        localBlockCounter++;

                        if(NVM_NO_BLOCKS - 1 == localBlockCounter)
                        {
                            break;
                        }
                        else
                        {
                            /* Do nothing. */
                        }
                    }
                    else
                    {
                        Nvm_HeaderArr[localBlockId].blockId = 0xFFu;
                        Nvm_HeaderArr[localBlockId].blockSize = 0xFFu;
                        localAddress += 8u;
                        Nvm_CurrentAddress = localAddress;
                    }
                }
                else
                {
                    localAddress += 8u;
                    Nvm_CurrentAddress = localAddress;
                }
            }
        }
        else if(0u != startPattern[0] && 0u != startPattern[1])
        {
            __debug();
            /* Corrupted pattern, erase the data-flash. */
            Fls_Erase(localAddress);
            /* Write sector pattern, assumption is that the data-flash is empty. */
            startPattern[0] = 0xA5A5u;
            startPattern[1] = 0xA5A5u;
            Fls_WriteBlock(localAddress, (uint32*)&startPattern, 8u);
            localAddress += 8u;
            Nvm_CurrentAddress = localAddress;
        }
        else
        {
            /* Write sector pattern, assumption is that the data-flash is empty. */
            startPattern[0] = 0xA5A5A5A5u;
            startPattern[1] = 0xA5A5A5A5u;
            Fls_WriteBlock(localAddress, (uint32*)&startPattern, 8u);
            localAddress += 8u;
            Nvm_CurrentAddress = localAddress;
        }
    }
    else
    {
        /* Do nothing. */
    }

    IfxCpu_enableInterrupts();
}

void Nvm_ReadAll(void)
{
    IfxCpu_disableInterrupts();

    uint32 localCrc[2] = {0u};
    uint32 compareCrc = 0u;
    uint32 crcAddress = 0u;

    Nvm_FindCurrentAddress();

    for(uint8 i = 1u; i < NVM_NO_BLOCKS; i++)
    {
        if((Nvm_HeaderArr[i].blockId != 0u) && (Nvm_HeaderArr[i].blockId != 0xFF)
                && (Nvm_HeaderArr[i].blockSize != 0u && Nvm_HeaderArr[i].blockSize != 0xFF))
        {
            Fls_ReadBlock(Nvm_NvStatArr[i].blockAddress, Nvm_BlockDataList[i].data, Nvm_NvStatArr[i].blockSize);
            crcAddress = Nvm_NvStatArr[i].blockAddress + Nvm_NvStatArr[i].blockSize;
            Fls_ReadBlock(crcAddress, localCrc, 8u);
            compareCrc = Crc_Calculate(Nvm_BlockDataList[i].data, Nvm_NvStatArr[i].blockSize / 4u, 0u);

            if(compareCrc == localCrc[0])
            {
                /* Do nothing. */
            }
            else
            {
                //__debug();
                //memcpy(&Nvm_BlockDataList[i].data, &Nvm_RomDefaults_BlockDataList[i].data, sizeof(Nvm_RomDefaults_BlockDataList[i].data));
                //Nvm_WriteBlock(i, (uint32*)&Nvm_BlockDataList[i].data);
            }

        }
        else
        {
            memcpy(&Nvm_HeaderArr[i], &Nvm_HeaderArr_Default[i], sizeof(Nvm_HeaderArr[i]));
            memcpy(&Nvm_NvStatArr[i], &Nvm_NvStatArr_Default[i], sizeof(Nvm_NvStatArr[i]));
            Nvm_WriteBlock(i, Nvm_RomDefaults_BlockDataList[i].data);
        }
    }

    Nvm_ReadAllFinished = 2u;

    IfxCpu_enableInterrupts();
}

void Nvm_WriteAll(void)
{
    IfxCpu_disableInterrupts();

    for(uint8 i = 0u; i < NVM_NO_BLOCKS; i++)
    {
        if(1u == Nvm_BlockIdListForWriteAll[i])
        {
            Nvm_WriteBlock(i, (uint32*)&Nvm_BlockDataList[i].data);
        }
        else
        {
            /* Do nothing. */
        }
    }

    Nvm_WriteAllFinished = 2u;

    IfxCpu_enableInterrupts();
}
