#include "Dcm.h"
#include "CanH.h"
#include "can.h"
#include "Dem.h"
#include <string.h>

#define DCM_CAN_ID_TX 0x702
#define DCM_CAN_ID_RX 0x703
#define DCM_DATA_SIZE (DEM_NUMBER_OF_DTCS * sizeof(Dem_DTC_t))
#define DCM_MAX_CAN_DATA_LEN 8
typedef struct
{
	uint8 SoftwareVersion;
	uint8 FlashBootLoaderVersion;
}SWV;
/* DIAGNOSTIC SESSION DATA TYPE */
typedef enum
{
	DEFAULT = 0U,
	EXTENDED = 1U,
	PROGRAMMING = 2U,
	CODING = 3U,
	CALIBRATION = 4U,
	HARDRESET = 5U,
	SOFTRESET = 6U,
	JUMPTOAPPL = 7U
}DiagState;
typedef void (*Dcm_FuncPtr)();
SWV Dcm_SWVersion =
{
		0x01, /* SW */
		0x01, /* FBL */
};
__attribute__((section(".ncr"))) DiagState Dcm_DiagnosticSession = 0x00;
__attribute__((section(".ncr"))) uint32 Dcm_AliveCounter = 0x00;
__attribute__((section(".ccmram"))) uint32 Dcm_MainCounter = 0x00;
__attribute__((section(".ccmram"))) CAN_TxHeaderTypeDef Dcm_TxHeader = {0, 0, 0, 0, 0, 0};
__attribute__((section(".ccmram"))) uint8 Dcm_TxData[8] = {0};
__attribute__((section(".ccmram"))) uint32 Dcm_TxMailbox = 0;
extern CAN_HandleTypeDef hcan1;
extern __attribute__((section(".ccmram"))) Dem_DTC_t Dem_DTCArray[DEM_NUMBER_OF_DTCS];
extern __attribute__((section(".ccmram"))) uint8 CanH_DiagArray[8];
extern __attribute__((section(".ccmram"))) uint8 CanH_RequestBusSleep;
extern __attribute__((section(".ccmram"))) uint8 CanH_NoCommCounter;
extern __attribute__((section(".ccmram"))) CanH_ComStat_t CanH_CommunicationState;
extern __attribute__((section(".ccmram"))) uint8 Dem_DTCSettingDeactivated;
extern __attribute__((section(".ccmram"))) uint8 DigitalCluster_IsSelfTestRequested;
extern __attribute__((section(".ccmram"))) uint8 RevCam_RxSig_ReverseCameraRequest;
extern __attribute__((section(".ccmram"))) uint8 DigitalCluster_RxSig_ReverseCameraRequest;
extern __attribute__((section(".ccmram"))) CAN_RxHeaderTypeDef CanH_DiagRxHeader;
extern __attribute__((section(".ccmram"))) uint32 RevCam_DcmiStatus;
extern __attribute__((section(".ccmram"))) uint32 RevCam_I2cStatus;
extern __attribute__((section(".ccmram"))) uint8 RevCam_InitStatus;
extern __attribute__((section(".ccmram"))) uint8 DigitalCluster_FsmcDmaErrorFlag;
extern __attribute__((section(".ccmram"))) uint8 DigitalCluster_LcdInit;
extern __attribute__((section(".ccmram"))) uint8 DigitalCluster_ShutOffDisplayFlag;
extern __attribute__((section(".ccmram"))) uint8 DigitalCluster_ReadDisplaySelfDiagnosticsResult;

void Dcm_MainFunction(void);
void Dcm_TxIsoTp(uint8 *data, uint16 size);
void DiagRoutine_DSC_DefaultSession(void);
void DiagRoutine_DSC_ExtendedSession(void);
void DiagRoutine_DSC_ProgrammingSession(void);
void DiagRoutine_DSC_CodingSession(void);
void DiagRoutine_ER_HardReset(void);
void DiagRoutine_ER_SoftReset(void);
void DiagRoutine_TP_TesterPresent(void);
void DiagRoutine_CDTCI_ClearDiagnosticInformation(void);
void DiagRoutine_RDTCI_ReadDTCInformationSupportedDtc(void);
void DiagRoutine_RDBI_ReadSWData(void);
void DiagRoutine_RDBI_ReadActiveDiagnosticSession(void);
void DiagRoutine_RDBI_ReadAliveTime(void);
void DiagRoutine_RDBPI_ReadCameraStatus(void);
void DiagRoutine_RDBPI_ReadDisplayStatus(void);
void DiagRoutine_CC_CommunicationControl(void);
void DiagRoutine_CDTCS_ControlDTCSetting(void);
void DiagRoutine_RC_DisplaySelfTest(void);
void DiagRoutine_RC_CameraDisplay(void);
extern void EcuM_PerformReset(uint8 param);
extern void Dem_ClearDtc(void);
extern void Nvm_WriteAll(void);
typedef void (*Dcm_FuncPtr)();
typedef struct
{
	Dcm_FuncPtr FuncPtr;
}Dcm_RDBPI_Table_t;
Dcm_RDBPI_Table_t Dcm_RDBPI_Table[] =
{
		{DiagRoutine_RDBPI_ReadCameraStatus},
		{DiagRoutine_RDBPI_ReadDisplayStatus},
};
void Dcm_MainFunction(void)
{
	Dcm_AliveCounter++;
	if(Dcm_MainCounter == 0) Dcm_DiagnosticSession = DEFAULT;
	else
	{
		/* Do nothing. */
	}
	if(0x3E == CanH_DiagArray[1]) DiagRoutine_TP_TesterPresent();
	else
	{
		/* Do nothing. */
	}
	if(0x28 == CanH_DiagArray[1]) DiagRoutine_CC_CommunicationControl();
	else
	{
		/* Do nothing. */
	}
	if(0x85 == CanH_DiagArray[1]) DiagRoutine_CDTCS_ControlDTCSetting();
	else
	{
		/* Do nothing. */
	}
	if(CanH_DiagArray[1] == 0x10)
	{
		/* DEFAULT */
		if(CanH_DiagArray[2] == 0x01) DiagRoutine_DSC_DefaultSession();
		else
		{
			/* Do nothing. */
		}
		/* EXTENDED */
		if(CanH_DiagArray[2] == 0x03) DiagRoutine_DSC_ExtendedSession();
		else
		{
			/* Do nothing. */
		}
		/* PROGRAMMING */
		if(CanH_DiagArray[2] == 0x02 && Dcm_DiagnosticSession == EXTENDED) DiagRoutine_DSC_ProgrammingSession();
		else
		{
			/* Do nothing. */
		}
	}
	else
	{
		/* Do nothing. */
	}
	if(CanH_DiagArray[3] == 0x86 && CanH_DiagArray[2] == 0xF1 && CanH_DiagArray[1] == 0x22) DiagRoutine_RDBI_ReadActiveDiagnosticSession();
	else
	{
		/* Do nothing. */
	}
	/* Execute hard reset. */
	if(CanH_DiagArray[1] == 0x11 && CanH_DiagArray[2] == 0x01) DiagRoutine_ER_HardReset();
	else
	{
		/* Do nothing. */
	}
	/* Execute soft reset. */
	if(CanH_DiagArray[1] == 0x11 && CanH_DiagArray[2] == 0x03) DiagRoutine_ER_SoftReset();
	else
	{
		/* Do nothing. */
	}
	/* Execute clear DTC. */
	if(CanH_DiagArray[1] == 0x14) DiagRoutine_CDTCI_ClearDiagnosticInformation();
	else
	{
		/* Do nothing. */
	}
	/* Execute read DTC. */
	if(CanH_DiagArray[1] == 0x19) DiagRoutine_RDTCI_ReadDTCInformationSupportedDtc();
	else
	{
		/* Do nothing. */
	}
	/* Extended session routines. */
	if(Dcm_DiagnosticSession == EXTENDED)
	{
		if(CanH_DiagArray[1] == 0x31)
		{
			if(CanH_DiagArray[2] == 0x01)
			{
				if(CanH_DiagArray[3] == 0x3E && CanH_DiagArray[4] == 0x3E) DiagRoutine_RC_DisplaySelfTest();
				else
				{
					/* Do nothing. */
				}
				if(CanH_DiagArray[3] == 0x3F && CanH_DiagArray[4] == 0x3F) DiagRoutine_RC_CameraDisplay();
				else
				{
					/* Do nothing. */
				}
			}
		}
		/* Read data routines. */
		if(CanH_DiagArray[1] == 0x2A)
		{
			if(CanH_DiagArray[2] == 0x04)
			{
				Dcm_RDBPI_Table[CanH_DiagArray[3] - 12].FuncPtr();
			}
			else if(CanH_DiagArray[2] != 0x04)
			{
				Dcm_RDBPI_Table[CanH_DiagArray[3] - 12].FuncPtr();
			}
			else
			{
				/* Do nothing. */
			}
		}
		else
		{
			/* Do nothing. */
		}
		if(CanH_DiagArray[1] == 0x22)
		{
			if(CanH_DiagArray[2] == 0x00)
			{
				if(CanH_DiagArray[3] == 0x05) DiagRoutine_RDBI_ReadAliveTime();
				else
				{
					/* Do nothing. */
				}
			}
			else
			{
				/* Do nothing. */
			}
			if(CanH_DiagArray[2] == 0xF1 && CanH_DiagArray[3] == 0x80) DiagRoutine_RDBI_ReadSWData();
			else
			{
				/* Do nothing. */
			}
		}
		else
		{
			/* Do nothing. */
		}
	}
	else
	{
		/* Do nothing. */
	}
	Dcm_TxHeader.DLC = 0;
	Dcm_TxHeader.ExtId = 0;
	Dcm_TxHeader.IDE = 0;
	Dcm_TxHeader.RTR = 0;
	Dcm_TxHeader.StdId = 0;
	CanH_DiagRxHeader.DLC = 0;
	CanH_DiagRxHeader.ExtId = 0;
	CanH_DiagRxHeader.FilterMatchIndex = 0;
	CanH_DiagRxHeader.IDE = 0;
	CanH_DiagRxHeader.RTR = 0;
	CanH_DiagRxHeader.StdId = 0;
	CanH_DiagRxHeader.Timestamp = 0;
	for(uint8 i = 0; i < 8; i++)
	{
		Dcm_TxData[i] = 0;
		CanH_DiagArray[i] = 0;
	}
	Dcm_MainCounter++;
}
void DiagRoutine_RDBPI_ReadCameraStatus(void)
{
	Dcm_TxHeader.DLC = 8;
	Dcm_TxHeader.StdId = 0x703;
	Dcm_TxData[0] = 7;
	Dcm_TxData[1] = CanH_DiagArray[1] + 0x40;
	Dcm_TxData[2] = CanH_DiagArray[2];
	Dcm_TxData[3] = CanH_DiagArray[3];
	Dcm_TxData[4] = RevCam_DcmiStatus;
	Dcm_TxData[5] = RevCam_I2cStatus;
	Dcm_TxData[6] = RevCam_InitStatus;
	Dcm_TxData[7] = RevCam_RxSig_ReverseCameraRequest;
	HAL_CAN_AddTxMessage(&hcan1, &Dcm_TxHeader, Dcm_TxData, &Dcm_TxMailbox);
}
void DiagRoutine_RDBPI_ReadDisplayStatus(void)
{
	Dcm_TxHeader.DLC = 8;
	Dcm_TxHeader.StdId = 0x703;
	Dcm_TxData[0] = 7;
	Dcm_TxData[1] = CanH_DiagArray[1] + 0x40;
	Dcm_TxData[2] = CanH_DiagArray[2];
	Dcm_TxData[3] = CanH_DiagArray[3];
	Dcm_TxData[4] = DigitalCluster_FsmcDmaErrorFlag;
	Dcm_TxData[5] = DigitalCluster_IsSelfTestRequested;
	Dcm_TxData[6] = DigitalCluster_LcdInit;
	Dcm_TxData[7] = DigitalCluster_ShutOffDisplayFlag;
	HAL_CAN_AddTxMessage(&hcan1, &Dcm_TxHeader, Dcm_TxData, &Dcm_TxMailbox);
}
void DiagRoutine_DSC_DefaultSession(void)
{
	Dcm_TxHeader.DLC = CanH_DiagRxHeader.DLC;
	Dcm_TxHeader.StdId = 0x703;
	Dcm_TxData[0] = CanH_DiagRxHeader.DLC - 1;
	Dcm_TxData[1] = CanH_DiagArray[1] + 0x40;
	Dcm_TxData[2] = CanH_DiagArray[2];
	Dcm_TxData[3] = 0;
	Dcm_TxData[4] = 0;
	Dcm_TxData[5] = 0;
	Dcm_TxData[6] = 0;
	Dcm_TxData[7] = 0;
	Dcm_DiagnosticSession = DEFAULT;
	HAL_CAN_AddTxMessage(&hcan1, &Dcm_TxHeader, Dcm_TxData, &Dcm_TxMailbox);
}
void DiagRoutine_DSC_ExtendedSession(void)
{
	Dcm_TxHeader.DLC = CanH_DiagRxHeader.DLC;
	Dcm_TxHeader.StdId = CanH_DiagRxHeader.StdId + 1;
	Dcm_TxData[0] = CanH_DiagRxHeader.DLC - 1;
	Dcm_TxData[1] = CanH_DiagArray[1] + 0x40;
	Dcm_TxData[2] = CanH_DiagArray[2];
	Dcm_TxData[3] = 0;
	Dcm_TxData[4] = 0;
	Dcm_TxData[5] = 0;
	Dcm_TxData[6] = 0;
	Dcm_TxData[7] = 0;
	Dcm_DiagnosticSession = EXTENDED;
	HAL_CAN_AddTxMessage(&hcan1, &Dcm_TxHeader, Dcm_TxData, &Dcm_TxMailbox);
}
void DiagRoutine_DSC_ProgrammingSession(void)
{
	__disable_irq();
	Dcm_TxHeader.DLC = CanH_DiagRxHeader.DLC;
	Dcm_TxHeader.StdId = CanH_DiagRxHeader.StdId + 1;
	Dcm_TxData[0] = CanH_DiagRxHeader.DLC - 1;
	Dcm_TxData[1] = CanH_DiagArray[1] + 0x40;
	Dcm_TxData[2] = CanH_DiagArray[2];
	Dcm_TxData[3] = 0;
	Dcm_TxData[4] = 0;
	Dcm_TxData[5] = 0;
	Dcm_TxData[6] = 0;
	Dcm_TxData[7] = 0;
	Dcm_DiagnosticSession = PROGRAMMING;
	Nvm_WriteAll();
	__enable_irq();
	HAL_CAN_AddTxMessage(&hcan1, &Dcm_TxHeader, Dcm_TxData, &Dcm_TxMailbox);
	HAL_Delay(1);
	EcuM_PerformReset(0);
}
void DiagRoutine_ER_HardReset(void)
{
	__disable_irq();
	Dcm_TxHeader.DLC = 3;
	Dcm_TxHeader.StdId = 0x703;
	Dcm_TxData[0] = 2;
	Dcm_TxData[1] = 0x51;
	Dcm_TxData[2] = 0x01;
	Dcm_TxData[3] = 0;
	Dcm_TxData[4] = 0;
	Dcm_TxData[5] = 0;
	Dcm_TxData[6] = 0;
	Dcm_TxData[7] = 0;
	Dcm_DiagnosticSession = HARDRESET;
	Nvm_WriteAll();
	__enable_irq();
	HAL_CAN_AddTxMessage(&hcan1, &Dcm_TxHeader, Dcm_TxData, &Dcm_TxMailbox);
	HAL_Delay(1);
	EcuM_PerformReset(0);
}
void DiagRoutine_ER_SoftReset(void)
{
	__disable_irq();
	Dcm_TxHeader.DLC = 3;
	Dcm_TxHeader.StdId = 0x703;
	Dcm_TxData[0] = 2;
	Dcm_TxData[1] = 0x51;
	Dcm_TxData[2] = 3;
	Dcm_TxData[3] = 0;
	Dcm_TxData[4] = 0;
	Dcm_TxData[5] = 0;
	Dcm_TxData[6] = 0;
	Dcm_TxData[7] = 0;
	Dcm_DiagnosticSession = SOFTRESET;
	Nvm_WriteAll();
	__enable_irq();
	HAL_CAN_AddTxMessage(&hcan1, &Dcm_TxHeader, Dcm_TxData, &Dcm_TxMailbox);
	HAL_Delay(1);
	EcuM_PerformReset(0);
}
void DiagRoutine_TP_TesterPresent(void)
{
	Dcm_TxHeader.DLC = CanH_DiagRxHeader.DLC;
	Dcm_TxHeader.StdId = CanH_DiagRxHeader.StdId + 1;
	Dcm_TxData[0] = CanH_DiagRxHeader.DLC - 1;
	Dcm_TxData[1] = CanH_DiagArray[1] + 0x40;
	Dcm_TxData[2] = CanH_DiagArray[2];
	Dcm_TxData[3] = 0;
	Dcm_TxData[4] = 0;
	Dcm_TxData[5] = 0;
	Dcm_TxData[6] = 0;
	Dcm_TxData[7] = 0;
	CanH_RequestBusSleep = 0;
	if(CanH_CommunicationState != CC_ACTIVE) CanH_CommunicationState = FULL_COMMUNICATION;
	else
	{
		/* Do nothing. */
	}
	CanH_NoCommCounter = 0;
	HAL_CAN_AddTxMessage(&hcan1, &Dcm_TxHeader, Dcm_TxData, &Dcm_TxMailbox);
}
void DiagRoutine_CDTCI_ClearDiagnosticInformation(void)
{
	Dcm_TxHeader.DLC = CanH_DiagRxHeader.DLC;
	Dcm_TxHeader.StdId = CanH_DiagRxHeader.StdId + 1;
	Dcm_TxData[0] = CanH_DiagRxHeader.DLC - 1;
	Dcm_TxData[1] = CanH_DiagArray[1] + 0x40;
	Dcm_TxData[2] = 0;
	Dcm_TxData[3] = 0;
	Dcm_TxData[4] = 0;
	Dcm_TxData[5] = 0;
	Dcm_TxData[6] = 0;
	Dcm_TxData[7] = 0;
	Dem_ClearDtc();
	HAL_CAN_AddTxMessage(&hcan1, &Dcm_TxHeader, Dcm_TxData, &Dcm_TxMailbox);
}
void Dcm_TxIsoTp(uint8 *data, uint16 size)
{
	CAN_TxHeaderTypeDef localTxHeader = {0, 0, 0, 0, 0, 0};
	uint32 localTxMailbox = 0;
	uint16 localRemainingData = size;
	uint16 localOffset = 0;
	uint8 localCANData[DCM_MAX_CAN_DATA_LEN];
	uint8 localSeqNum = 1;
	localTxHeader.StdId = DCM_CAN_ID_TX;
	localTxHeader.RTR = CAN_RTR_DATA;
	localTxHeader.IDE = CAN_ID_STD;
	localTxHeader.DLC = DCM_MAX_CAN_DATA_LEN;
	localTxHeader.TransmitGlobalTime = DISABLE;
	if (7 < size)
	{
		localCANData[0] = 0x10 | ((size >> 8) & 0x0F);
		localCANData[1] = (size & 0xFF);
		memcpy(&localCANData[2], &data[0], 6);
		localOffset = 6;
		localRemainingData -= 6;
		HAL_CAN_AddTxMessage(&hcan1, &localTxHeader, localCANData, &localTxMailbox);
	}
	else
	{
		localCANData[0] = size & 0x0F;
		memcpy(&localCANData[1], &data[0], size);
		HAL_CAN_AddTxMessage(&hcan1, &localTxHeader, localCANData, &localTxMailbox);
	}
	while(localRemainingData > 0)
	{
		localCANData[0] = 0x20 | (localSeqNum & 0x0F);
		if (localRemainingData >= 7)
		{
			memcpy(&localCANData[1], &data[localOffset], 7);
			localOffset += 7;
			localRemainingData -= 7;
		}
		else
		{
			memcpy(&localCANData[1], &data[localOffset], localRemainingData);
			localOffset += localRemainingData;
			localRemainingData = 0;
		}
		HAL_CAN_AddTxMessage(&hcan1, &localTxHeader, localCANData, &localTxMailbox);
		HAL_Delay(1);
		localSeqNum++;
	}
}
void DiagRoutine_RDTCI_ReadDTCInformationSupportedDtc(void)
{
	uint8 *data = (uint8*)Dem_DTCArray;
	uint16 total_size = DEM_NUMBER_OF_DTCS;
	Dcm_TxHeader.DLC = 3;
	Dcm_TxHeader.StdId = 0x703;
	Dcm_TxData[0] = 2;
	Dcm_TxData[1] = 0x59;
	Dcm_TxData[2] = 0x0A;
	Dcm_TxData[3] = 0;
	Dcm_TxData[4] = 0;
	Dcm_TxData[5] = 0;
	Dcm_TxData[6] = 0;
	Dcm_TxData[7] = 0;
	HAL_CAN_AddTxMessage(&hcan1, &Dcm_TxHeader, Dcm_TxData, &Dcm_TxMailbox);
	Dcm_TxIsoTp(data, total_size);
}
void DiagRoutine_RDBI_ReadSWData(void)
{
	Dcm_TxHeader.DLC = 6;
	Dcm_TxHeader.StdId = CanH_DiagRxHeader.StdId + 1;
	Dcm_TxData[0] = 5;
	Dcm_TxData[1] = CanH_DiagArray[1] + 0x40;
	Dcm_TxData[2] = CanH_DiagArray[2];
	Dcm_TxData[3] = CanH_DiagArray[3];
	Dcm_TxData[4] = Dcm_SWVersion.FlashBootLoaderVersion;
	Dcm_TxData[5] = Dcm_SWVersion.SoftwareVersion;
	Dcm_TxData[6] = 0;
	Dcm_TxData[7] = 0;
	HAL_CAN_AddTxMessage(&hcan1, &Dcm_TxHeader, Dcm_TxData, &Dcm_TxMailbox);
}
void DiagRoutine_RDBI_ReadActiveDiagnosticSession(void)
{
	Dcm_TxHeader.DLC = CanH_DiagRxHeader.DLC;
	Dcm_TxHeader.StdId = CanH_DiagRxHeader.StdId + 1;
	Dcm_TxData[0] = CanH_DiagRxHeader.DLC - 1;
	Dcm_TxData[1] = CanH_DiagArray[1] + 0x40;
	Dcm_TxData[2] = CanH_DiagArray[2];
	Dcm_TxData[3] = CanH_DiagArray[3];
	Dcm_TxData[4] = CanH_DiagArray[4];
	Dcm_TxData[5] = Dcm_DiagnosticSession;
	Dcm_TxData[6] = 0;
	Dcm_TxData[7] = 0;
	HAL_CAN_AddTxMessage(&hcan1, &Dcm_TxHeader, Dcm_TxData, &Dcm_TxMailbox);
}
void DiagRoutine_RDBI_ReadAliveTime(void)
{
	Dcm_TxHeader.DLC = CanH_DiagRxHeader.DLC;
	Dcm_TxHeader.StdId = CanH_DiagRxHeader.StdId + 1;
	Dcm_TxData[0] = CanH_DiagRxHeader.DLC - 1;
	Dcm_TxData[1] = CanH_DiagArray[1] + 0x40;
	Dcm_TxData[2] = CanH_DiagArray[2];
	Dcm_TxData[3] = CanH_DiagArray[3];
	Dcm_TxData[4] = CanH_DiagArray[4];
	Dcm_TxData[5] = (uint8)(Dcm_AliveCounter * 5 / 60000);
	Dcm_TxData[6] = 0;
	Dcm_TxData[7] = 0;
	HAL_CAN_AddTxMessage(&hcan1, &Dcm_TxHeader, Dcm_TxData, &Dcm_TxMailbox);
}
void DiagRoutine_CC_CommunicationControl(void)
{
	Dcm_TxHeader.DLC = CanH_DiagRxHeader.DLC;
	Dcm_TxHeader.StdId = CanH_DiagRxHeader.StdId + 1;
	Dcm_TxData[0] = 0x02;
	Dcm_TxData[1] = CanH_DiagArray[1] + 0x40;
	Dcm_TxData[2] = CanH_DiagArray[2];
	if(CanH_DiagArray[2] == 0) CanH_CommunicationState = FULL_COMMUNICATION;
	else if(CanH_DiagArray[2] == 1) CanH_CommunicationState = CC_ACTIVE;
	else
	{
		/* Do nothing. */
	}
	HAL_CAN_AddTxMessage(&hcan1, &Dcm_TxHeader, Dcm_TxData, &Dcm_TxMailbox);
}
void DiagRoutine_CDTCS_ControlDTCSetting(void)
{
	Dcm_TxHeader.DLC = CanH_DiagRxHeader.DLC;
	Dcm_TxHeader.StdId = CanH_DiagRxHeader.StdId + 1;
	Dcm_TxData[0] = CanH_DiagArray[0];
	Dcm_TxData[1] = CanH_DiagArray[1] + 0x40;
	Dcm_TxData[2] = CanH_DiagArray[2];
	if(CanH_DiagArray[2] == 1) Dem_DTCSettingDeactivated = 0;
	else if(CanH_DiagArray[2] == 2) Dem_DTCSettingDeactivated = 1;
	else
	{
		/* Do nothing. */
	}
	HAL_CAN_AddTxMessage(&hcan1, &Dcm_TxHeader, Dcm_TxData, &Dcm_TxMailbox);
}
void DiagRoutine_RC_DisplaySelfTest(void)
{
	Dcm_TxHeader.DLC = 5;
	Dcm_TxHeader.StdId = 0x703;
	Dcm_TxData[0] = 4;
	Dcm_TxData[1] = 0x71;
	Dcm_TxData[2] = 0x01;
	Dcm_TxData[3] = 0x3E;
	Dcm_TxData[4] =	0x3E;
	Dcm_TxData[5] = 0;
	Dcm_TxData[6] = 0;
	Dcm_TxData[7] = 0;
	DigitalCluster_IsSelfTestRequested = 1;
	HAL_CAN_AddTxMessage(&hcan1, &Dcm_TxHeader, Dcm_TxData, &Dcm_TxMailbox);
}
void DiagRoutine_RC_CameraDisplay(void)
{
	Dcm_TxHeader.DLC = 5;
	Dcm_TxHeader.StdId = 0x703;
	Dcm_TxData[0] = 4;
	Dcm_TxData[1] = 0x71;
	Dcm_TxData[2] = 0x01;
	Dcm_TxData[3] = 0x3F;
	Dcm_TxData[4] =	0x3F;
	Dcm_TxData[5] = 0;
	Dcm_TxData[6] = 0;
	Dcm_TxData[7] = 0;
	RevCam_RxSig_ReverseCameraRequest = CanH_DiagArray[5];
	DigitalCluster_RxSig_ReverseCameraRequest = CanH_DiagArray[5];
	HAL_CAN_AddTxMessage(&hcan1, &Dcm_TxHeader, Dcm_TxData, &Dcm_TxMailbox);
}
