#include "Nvm.h"
#include "main.h"
#include <string.h>
#include "Dem.h"

__attribute__((section(".ccmram"))) uint32 Nvm_MainCounter = 0;
__attribute__((section(".ccmram"))) uint8 Nvm_WriteAllPending = 0;
__attribute__((section(".ccmram"))) uint8 Nvm_ReadAllPending = 0;
__attribute__((section(".ccmram"))) uint32 Nvm_DataRecorder_CommonBlock[2] = {0};
extern __attribute__((section(".ccmram"))) uint32 DataRecorder_KilometerTotal;
extern __attribute__((section(".ccmram"))) uint32 DataRecorder_KilometerPerDcy;
extern __attribute__((section(".ccmram"))) uint32 Dem_DTCArray[DEM_NUMBER_OF_DTCS];

void Nvm_MainFunction(void);
void Nvm_ReadAll(void);
void Nvm_WriteAll(void);
void NvM_FlashReadData(uint32 StartSectorAddress, uint32 *RxBuf, uint16 numberofwords);
uint32 NvM_FlashWriteData(uint32 StartSectorAddress, uint32 *Data, uint16 numberofwords, uint32 Sector);
void Nvm_ReadAll(void)
{
	NvM_FlashReadData(0x0800C000, (uint32*)Dem_DTCArray, DEM_NUMBER_OF_DTCS);
	if(Dem_DTCArray[0] >= 255) memset(Dem_DTCArray, 0, sizeof(Dem_DTCArray));
	else
	{
		/* Do nothing. */
	}

	NvM_FlashReadData(0x08008000, Nvm_DataRecorder_CommonBlock, 2);
	DataRecorder_KilometerTotal = Nvm_DataRecorder_CommonBlock[0];
	DataRecorder_KilometerPerDcy = Nvm_DataRecorder_CommonBlock[1];

}
void Nvm_WriteAll(void)
{
	Nvm_DataRecorder_CommonBlock[0] = DataRecorder_KilometerTotal;
	Nvm_DataRecorder_CommonBlock[1] = DataRecorder_KilometerPerDcy;
	NvM_FlashWriteData(0x08008000, Nvm_DataRecorder_CommonBlock, 2, 2);
	NvM_FlashWriteData(0x0800C000, (uint32*)Dem_DTCArray, DEM_NUMBER_OF_DTCS, 3);
}
void Nvm_MainFunction(void)
{
	if(1 == Nvm_ReadAllPending)
	{
		Nvm_ReadAll();
		Nvm_ReadAllPending = 2;
	}
	else if(1 == Nvm_WriteAllPending)
	{
		Nvm_WriteAll();
		Nvm_WriteAllPending = 2;
	}
	else
	{
		/* Do nothing. */
	}
	Nvm_MainCounter++;
}
uint32 NvM_FlashWriteData(uint32 StartSectorAddress, uint32 *Data, uint16 numberofwords, uint32 Sector)
{
	static FLASH_EraseInitTypeDef EraseInitStruct;
	uint32 SECTORError;
	uint32 sofar=0;
	uint32 StartSector = Sector;
	uint32 EndSector = Sector;
	HAL_FLASH_Unlock();
	EraseInitStruct.TypeErase     = FLASH_TYPEERASE_SECTORS;
	EraseInitStruct.VoltageRange  = FLASH_VOLTAGE_RANGE_3;
	EraseInitStruct.Sector        = StartSector;
	EraseInitStruct.NbSectors     = (EndSector - StartSector) + 1;
	if(HAL_FLASHEx_Erase(&EraseInitStruct, &SECTORError) != HAL_OK) return HAL_FLASH_GetError ();
	else
	{
		/* Do nothing. */
	}
	while(sofar < numberofwords)
	{
		if(HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, StartSectorAddress, Data[sofar]) == HAL_OK)
		{
			StartSectorAddress += 4;
			sofar++;
		}
		else return HAL_FLASH_GetError ();
	}
	HAL_FLASH_Lock();
	return 0;
}
void NvM_FlashReadData(uint32 StartSectorAddress, uint32 *RxBuf, uint16 numberofwords)
{
	for(uint16 i = 0; i < numberofwords; i++) RxBuf[i] = *(__IO uint32 *)(StartSectorAddress + (i * 4));
}
