/* START OF FILE */
/* INCLUDE START */
#include "Nvm.h"
#include "Dem.h"
#include "EcuM.h"
#include "Dcm.h"
#include "main.h"
#include <string.h>
#include "string.h"
#include "stdio.h"
#include <stdlib.h>
/* INCLUDE END */
/* DEFINE START */
#define NVM_CALIBRATION_START_ADDRESS 0x0800F800
#define NVM_DTC_START_ADDRESS 0x0800FC00
/* DEFINE STOP */
/* TYPEDEF START */
typedef enum
{
	READALL,
	WRITEALL,
	PENDING,
	READY
}NvMState_t;
/* TYPEDEF END */
/* VARIABLES START */
static uint32 NvM_MainCounter = 0;
static NvMState_t NvMState = READALL;
static uint8 NvM_ReadAll_Flag = 0;
static uint8 NvM_WriteAll_Flag = 0;
uint8 Nvm_WriteAllPending;
uint8 Nvm_ReadAllPending;
uint8 NvM_WriteFlag_Dtc = 0;
uint8 NvM_WriteFlag_Calibration = 0;
uint32 NvM_Block_Calibration[12] = {0};
uint32 NvM_BlockDefault_Calibration[5] =
{
		55, 25, 2, 5, 9
/*
Param_MaxVoltageValue = 55;
Param_MinVoltageValue = 25;
Param_NominalCurrentRating = 2;
Param_MaximumCurrentRating = 5;
Param_I2tRating = 9;
 */
};
Dem_DTC_t NvmBlock_Dem_DTCArray[DEM_NUMBER_OF_DTCS];
extern Dem_DTC_t Dem_DTCArray[DEM_NUMBER_OF_DTCS];
extern uint32 Dcm_DiagnosticCalibrationData[5];
extern uint8 Param_MaxVoltageValue;
extern uint8 Param_MinVoltageValue;
extern uint8 Param_NominalCurrentRating;
extern uint8 Param_MaximumCurrentRating;
extern uint8 Param_I2tRating;
/* VARIABLES END */
/* FUNCTIONS START */
static void NvM_ReadAll(void);
void NvM_WriteAll(void);
void NvM_MainFunction(void);
uint32 Nvm_GetPage(uint32 Address);
extern void Nvm_FlashReadData(uint32 StartPageAddress, uint32 *RxBuf, uint16 numberofwords);
extern uint32 Nvm_FlashWriteData(uint32 StartPageAddress, uint32 *Data, uint16 numberofwords);
/* FUNCTIONS END */
/* FUNCTIONS START */
static void NvM_ReadAll(void)
{
	NvM_ReadAll_Flag = 1;
	Nvm_FlashReadData(NVM_CALIBRATION_START_ADDRESS, NvM_Block_Calibration, 12);
	Nvm_FlashReadData(NVM_DTC_START_ADDRESS, (uint32*)NvmBlock_Dem_DTCArray, (DEM_NUMBER_OF_DTCS * sizeof(Dem_DTC_t)) / 4);
	if(0xffffffff != NvmBlock_Dem_DTCArray[0].counter)
	{
		memcpy(Dem_DTCArray, NvmBlock_Dem_DTCArray, (DEM_NUMBER_OF_DTCS * sizeof(Dem_DTC_t)));
	}
	else
	{
		memset(NvmBlock_Dem_DTCArray, 0, (DEM_NUMBER_OF_DTCS * sizeof(Dem_DTC_t)));
		Nvm_FlashWriteData(NVM_DTC_START_ADDRESS, (uint32*)NvmBlock_Dem_DTCArray, (DEM_NUMBER_OF_DTCS * sizeof(Dem_DTC_t)) / 4);
	}
	if(0xffffffff != NvM_Block_Calibration[0])
	{
		Param_MaxVoltageValue = NvM_Block_Calibration[0];
		Param_MinVoltageValue = NvM_Block_Calibration[1];
		Param_NominalCurrentRating = NvM_Block_Calibration[2];
		Param_MaximumCurrentRating = NvM_Block_Calibration[3];
		Param_I2tRating = NvM_Block_Calibration[4];
		for(uint8 i = 0; i < 5; i++) Dcm_DiagnosticCalibrationData[i] = NvM_Block_Calibration[i];
	}
	else
	{
		for(uint8 i = 0; i < 5; i++)
		{
			NvM_Block_Calibration[i] = NvM_BlockDefault_Calibration[i];
			Dcm_DiagnosticCalibrationData[i] = NvM_BlockDefault_Calibration[i];
		}
		Nvm_FlashWriteData(NVM_CALIBRATION_START_ADDRESS, NvM_Block_Calibration, 5);
		Param_MaxVoltageValue = NvM_Block_Calibration[0];
		Param_MinVoltageValue = NvM_Block_Calibration[1];
		Param_NominalCurrentRating = NvM_Block_Calibration[2];
		Param_MaximumCurrentRating = NvM_Block_Calibration[3];
		Param_I2tRating = NvM_Block_Calibration[4];
	}
}
void NvM_WriteAll(void)
{
	for(uint8 i = 0; i < 5; i++)
	{
		if(Dcm_DiagnosticCalibrationData[i] != NvM_Block_Calibration[i])
		{
			NvM_WriteFlag_Calibration = 1;
			NvM_Block_Calibration[i] = Dcm_DiagnosticCalibrationData[i];
		}
		else
		{
			/* Do nothing. */
		}
	}
	if(NvM_WriteFlag_Calibration == 1)
	{
		NvM_WriteFlag_Calibration = 0;
		Nvm_FlashWriteData(NVM_CALIBRATION_START_ADDRESS, NvM_Block_Calibration, 5);
	}
	else
	{
		/* Do nothing. */
	}
	for(uint8 i = 0; i < 11; i++)
	{
		if(NvmBlock_Dem_DTCArray[i].counter != Dem_DTCArray[i].counter)
		{
			NvM_WriteFlag_Dtc = 1;
			NvmBlock_Dem_DTCArray[i].isActiveNow = 0;
			Dem_DTCArray[i].isActiveNow = 0;
			memcpy(NvmBlock_Dem_DTCArray, Dem_DTCArray, sizeof(Dem_DTCArray));
		}
		else
		{
			/* Do nothing. */
		}
	}
	if(NvM_WriteFlag_Dtc == 1)
	{
		NvM_WriteFlag_Dtc = 0;
		Nvm_FlashWriteData(NVM_DTC_START_ADDRESS, (uint32*)NvmBlock_Dem_DTCArray, (DEM_NUMBER_OF_DTCS * sizeof(Dem_DTC_t)) / 4);
	}
	else
	{
		/* Do nothing. */
	}
	NvM_WriteAll_Flag = 1;
	Nvm_WriteAllPending = 2;
}
void NvM_MainFunction(void)
{
	if(EcuM_State == POSTRUN && NvM_WriteAll_Flag == 0) NvMState = WRITEALL;
	else if(EcuM_State == RUN) NvM_WriteAll_Flag = 0;
	else
	{
		/* Do nothing. */
	}
	switch(NvMState)
	{
	case READALL:
		NvMState = PENDING;
		NvM_ReadAll();
		NvMState = READY;
		break;
	case WRITEALL:
		NvMState = PENDING;
		NvM_WriteAll();
		NvMState = READY;
		break;
	default:
		break;
	}
	NvM_MainCounter++;
}
uint32 Nvm_GetPage(uint32 Address)
{
	for (uint8 indx=0; indx < 128; indx++) if((Address < (0x08000000 + (FLASH_PAGE_SIZE *(indx + 1))) ) && (Address >= (0x08000000 + FLASH_PAGE_SIZE * indx))) return (0x08000000 + FLASH_PAGE_SIZE * indx);
	return 0;
}
uint32 Nvm_FlashWriteData(uint32 StartPageAddress, uint32 *Data, uint16 numberofwords)
{
	static FLASH_EraseInitTypeDef EraseInitStruct;
	uint32 PAGEError;
	uint32 sofar=0;
	uint32 StartPage = Nvm_GetPage(StartPageAddress);
	uint32 EndPageAdress = StartPageAddress + numberofwords * 4;
	uint32 EndPage = Nvm_GetPage(EndPageAdress);
	HAL_FLASH_Unlock();
	EraseInitStruct.TypeErase   = FLASH_TYPEERASE_PAGES;
	EraseInitStruct.PageAddress = StartPage;
	EraseInitStruct.NbPages     = ((EndPage - StartPage)/FLASH_PAGE_SIZE) +1;
	if (HAL_FLASHEx_Erase(&EraseInitStruct, &PAGEError) != HAL_OK) return HAL_FLASH_GetError ();
	while (sofar<numberofwords)
	{
		if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, StartPageAddress, Data[sofar]) == HAL_OK)
		{
			StartPageAddress += 4;
			sofar++;
		}
		else return HAL_FLASH_GetError ();
	}
	HAL_FLASH_Lock();
	return 0;
}

void Nvm_FlashReadData(uint32 StartPageAddress, uint32 *RxBuf, uint16 numberofwords)
{
	for (uint16 i = 0; i < numberofwords; i++) RxBuf[i] = *(__IO volatile uint32 *)(StartPageAddress + (i * 4));
}
/* FUNCTIONS END */
/* STOP OF FILE */
