#include "CanH.h"
#include "can.h"
#include "Dem.h"

__attribute__((section(".ccmram"))) uint32 CanH_MainCounter = 0;
__attribute__((section(".ccmram"))) uint32 CanH_Status = 0;
__attribute__((section(".ccmram"))) uint32 CanH_ErrArr[21] = {0};
__attribute__((section(".ccmram"))) uint32 CanH_RxFifo0MsgPendingCnt = 0;
__attribute__((section(".ccmram"))) uint32 CanH_RxFifo0FullCnt = 0;
__attribute__((section(".ccmram"))) CAN_RxHeaderTypeDef CanH_RxHeader = {0, 0, 0, 0, 0, 0, 0};
__attribute__((section(".ccmram"))) uint8 CanH_RxData[8] = {0};
__attribute__((section(".ccmram"))) CAN_TxHeaderTypeDef CanH_TxHeader = {0, 0, 0, 0, 0, 0};
__attribute__((section(".ccmram"))) uint8 CanH_TxData[8] = {0};
__attribute__((section(".ccmram"))) uint32 CanH_TxMailbox = 0;
__attribute__((section(".ccmram"))) uint8 CanH_RequestBusSleep = 0;
__attribute__((section(".ccmram"))) uint32 CanH_NoCommCounter = 0;
__attribute__((section(".ccmram"))) CanH_ComStat_t CanH_CommunicationState = 0;
__attribute__((section(".ccmram"))) uint8 CanH_RxSig_Networkmanagement3 = 0;
__attribute__((section(".ccmram"))) uint8 CanH_RxSig_Ignition = 0;
__attribute__((section(".ccmram"))) uint8 CanH_RxSig_Speed = 0;
__attribute__((section(".ccmram"))) uint8 CanH_RxSig_Rpm = 0;
__attribute__((section(".ccmram"))) uint8 CanH_RxSig_CurrentConsumption = 0;
__attribute__((section(".ccmram"))) uint8 CanH_RxSig_Gear = 0;
__attribute__((section(".ccmram"))) uint8 CanH_RxSig_TemperatureSensor = 0;
__attribute__((section(".ccmram"))) uint8 CanH_RxSig_DisplayMode = 0;
__attribute__((section(".ccmram"))) uint8 CanH_RxSig_RotaryLightSwitch = 0;
__attribute__((section(".ccmram"))) uint8 CanH_RxSig_TurnSignal = 0;
__attribute__((section(".ccmram"))) uint8 CanH_RxSig_HighBeam = 0;
__attribute__((section(".ccmram"))) uint8 CanH_RxSig_CcmId = 0;
__attribute__((section(".ccmram"))) uint8 CanH_RxSig_IrSensStat = 0;
__attribute__((section(".ccmram"))) uint8 CanH_RxSig_DrivecycleStatus = 0;
__attribute__((section(".ccmram"))) uint8 CanH_RxSig_FogLights = 0;
__attribute__((section(".ccmram"))) uint8 CanH_RxSig_Recirculation = 0;
__attribute__((section(".ccmram"))) uint8 CanH_RxSig_FanValue = 0;
__attribute__((section(".ccmram"))) uint8 CanH_RxSig_ClimaTemp = 0;
__attribute__((section(".ccmram"))) uint8 CanH_RxSig_AutoClimate = 0;
__attribute__((section(".ccmram"))) uint8 CanH_DiagArray[8] = {0};
__attribute__((section(".ccmram"))) CAN_RxHeaderTypeDef CanH_DiagRxHeader = {0, 0, 0, 0, 0, 0, 0};
__attribute__((section(".ccmram"))) uint32 CanH_VehState_MissCnt = 0;
__attribute__((section(".ccmram"))) uint32 CanH_BodyState_MissCnt = 0;
__attribute__((section(".ccmram"))) uint32 CanH_BodyState2_MissCnt = 0;
__attribute__((section(".ccmram"))) uint32 CanH_DataRecorder_MissCnt = 0;
extern __attribute__((section(".ccmram"))) uint8 DigitalCluster_ReadDisplayPowerMode_RegisterValue;
extern __attribute__((section(".ccmram"))) uint8 DigitalCluster_LcdInit;
extern __attribute__((section(".ccmram"))) uint16 DigitalCluster_ReadDisplayStatus_RegisterValue;
extern __attribute__((section(".ccmram"))) uint32 RevCam_DcmiStatus;
extern __attribute__((section(".ccmram"))) uint32 RevCam_I2cStatus;
extern __attribute__((section(".ccmram"))) uint8 RevCam_InitStatus;
extern __attribute__((section(".ccmram"))) uint32 Ain_MeasValues[3];
extern __attribute__((section(".ccmram"))) uint32 DataRecorder_RxSig_VehicleSpeed;
extern __attribute__((section(".ccmram"))) uint8 DataRecorder_RxSig_DriveCycleStatus;
extern __attribute__((section(".ccmram"))) uint8 DataRecorder_RxSig_LVBat;
extern __attribute__((section(".ccmram"))) uint8 DataRecorder_RxSig_CurrentConsumptionInstantLV;
extern __attribute__((section(".ccmram"))) uint8 DataRecorder_RxSig_QC;
extern __attribute__((section(".ccmram"))) uint8 DigitalCluster_RxSig_IgnitionStatus;
extern __attribute__((section(".ccmram"))) uint8 DigitalCluster_RxSig_Gear;
extern __attribute__((section(".ccmram"))) uint8 DigitalCluster_RxSig_HighBeamStatus;
extern __attribute__((section(".ccmram"))) uint8 DigitalCluster_RxSig_VehicleSpeed;
extern __attribute__((section(".ccmram"))) uint8 DigitalCluster_RxSig_MotorRpm;
extern __attribute__((section(".ccmram"))) uint8 DigitalCluster_RxSig_TurnSignals;
extern __attribute__((section(".ccmram"))) uint8 DigitalCluster_RxSig_DisplayMode;
extern __attribute__((section(".ccmram"))) uint8 DigitalCluster_RxSig_CollisionWarning;
extern __attribute__((section(".ccmram"))) uint8 DigitalCluster_RxSig_ReverseCameraRequest;
extern __attribute__((section(".ccmram"))) uint8 DigitalCluster_RxSig_CheckControlMessageId;
extern __attribute__((section(".ccmram"))) uint8 DigitalCluster_RxSig_OutsideTemperature;
extern __attribute__((section(".ccmram"))) uint8 DigitalCluster_RxSig_FogLightFront;
extern __attribute__((section(".ccmram"))) uint8 DigitalCluster_RxSig_FogLightRear;
extern __attribute__((section(".ccmram"))) uint8 DigitalCluster_RxSig_Rls;
extern __attribute__((section(".ccmram"))) uint8 DigitalCluster_RxSig_Recirculation;
extern __attribute__((section(".ccmram"))) uint8 DigitalCluster_RxSig_RequestedTemperature;
extern __attribute__((section(".ccmram"))) uint8 DigitalCluster_RxSig_AutoClimate;
extern __attribute__((section(".ccmram"))) uint8 DigitalCluster_RxSig_FanValue;
extern __attribute__((section(".ccmram"))) float Ain_VrefInt;
extern __attribute__((section(".ccmram"))) float Ain_McuTemp;
extern __attribute__((section(".ccmram"))) float Ain_Vbat;
extern __attribute__((section(".ccmram"))) uint8 EcuM_StopModeActive;
extern CAN_HandleTypeDef hcan1;

extern void EcuM_PerformReset(uint8 param);

void CanH_MainFunction(void);
void HAL_CAN_ErrorCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan);

void CanH_MainFunction(void)
{
	static uint32 notificationLocal = 0;
	CanH_Status = HAL_CAN_GetState(&hcan1);
	if(0x00 == CanH_MainCounter)
	{
		HAL_CAN_Start(&hcan1);
		notificationLocal = CAN_IT_RX_FIFO0_MSG_PENDING |
				CAN_IT_RX_FIFO1_MSG_PENDING |
				CAN_IT_ERROR_WARNING |
				CAN_IT_ERROR_PASSIVE |
				CAN_IT_BUSOFF |
				CAN_IT_LAST_ERROR_CODE |
				CAN_IT_ERROR;
		HAL_CAN_ActivateNotification(&hcan1, notificationLocal);
		CanH_CommunicationState = PARTIAL_COMMUNICATION;
	}
	else
	{
		/* Do nothing. */
	}
	if((FULL_COMMUNICATION == CanH_CommunicationState || PARTIAL_COMMUNICATION == CanH_CommunicationState) && CC_ACTIVE != CanH_CommunicationState)
	{
		for(uint8 i = 0; i < 21; i++) CanH_ErrArr[i] = 0;
		CanH_BodyState_MissCnt++;
		CanH_VehState_MissCnt++;
		CanH_DataRecorder_MissCnt++;
		CanH_BodyState2_MissCnt++;
		if(200 < CanH_BodyState_MissCnt) Dem_SetDtc(DEM_BODYSTATE_MESSAGEMISSING_ID, 1, 1);
		else Dem_SetDtc(DEM_BODYSTATE_MESSAGEMISSING_ID, 1, 0);
		if(200 < CanH_VehState_MissCnt) Dem_SetDtc(DEM_VEHSTATE_MESSAGEMISSING_ID, 1, 1);
		else Dem_SetDtc(DEM_VEHSTATE_MESSAGEMISSING_ID, 1, 0);
		if(200 < CanH_DataRecorder_MissCnt) Dem_SetDtc(DEM_DATARECORDER_MESSAGEMISSING_ID, 1, 1);
		else Dem_SetDtc(DEM_DATARECORDER_MESSAGEMISSING_ID, 1, 0);
		if(200 < CanH_BodyState2_MissCnt) Dem_SetDtc(DEM_BODYSTATE2_MESSAGEMISSING_ID, 1, 1);
		else Dem_SetDtc(DEM_BODYSTATE2_MESSAGEMISSING_ID, 1, 0);
	}
	else
	{
		/* Do nothing. */
	}
	if(1000 <= CanH_NoCommCounter) CanH_CommunicationState = NO_COMMUNICATION;
	else
	{
		/* Do nothing. */
	}
	if(NO_COMMUNICATION == CanH_CommunicationState) CanH_RequestBusSleep = 1;
	else
	{
		/* Do nothing.  */
	}
	if(1 == CanH_RequestBusSleep && 0 == HAL_CAN_IsSleepActive(&hcan1)) HAL_CAN_RequestSleep(&hcan1);
	else
	{
		/* Do nothing. */
	}
	CanH_NoCommCounter++;
	CanH_MainCounter++;
	for(uint8 i = 0; i < 8; i++) CanH_TxData[i] = 0;
}
void HAL_CAN_ErrorCallback(CAN_HandleTypeDef *hcan)
{
	switch(hcan->ErrorCode)
	{
	case HAL_CAN_ERROR_EWG:
		CanH_ErrArr[0] = 1;
		HAL_CAN_ResetError(hcan);
		break;
	case HAL_CAN_ERROR_EPV:
		CanH_ErrArr[1] = 2;
		HAL_CAN_ResetError(hcan);
		break;
	case HAL_CAN_ERROR_BOF:
		CanH_ErrArr[2] = 3;
		HAL_CAN_ResetError(hcan);
		break;
	case HAL_CAN_ERROR_STF:
		HAL_CAN_ResetError(hcan);
		break;
	case HAL_CAN_ERROR_FOR:
		CanH_ErrArr[4] = 5;
		HAL_CAN_ResetError(hcan);
		break;
	case HAL_CAN_ERROR_ACK:
		CanH_ErrArr[5] = 6;
		HAL_CAN_ResetError(hcan);
		break;
	case HAL_CAN_ERROR_BR:
		CanH_ErrArr[6] = 7;
		HAL_CAN_ResetError(hcan);
		break;
	case HAL_CAN_ERROR_BD:
		CanH_ErrArr[7] = 8;
		HAL_CAN_ResetError(hcan);
		break;
	case HAL_CAN_ERROR_CRC:
		CanH_ErrArr[8] = 9;
		HAL_CAN_ResetError(hcan);
		break;
	case HAL_CAN_ERROR_RX_FOV0:
		CanH_ErrArr[9] = 10;
		HAL_CAN_ResetError(hcan);
		break;
	case HAL_CAN_ERROR_RX_FOV1:
		CanH_ErrArr[10] = 11;
		HAL_CAN_ResetError(hcan);
		break;
	case HAL_CAN_ERROR_TX_ALST0:
		CanH_ErrArr[11] = 12;
		HAL_CAN_ResetError(hcan);
		break;
	case HAL_CAN_ERROR_TX_TERR0:
		CanH_ErrArr[12] = 13;
		HAL_CAN_ResetError(hcan);
		break;
	case HAL_CAN_ERROR_TX_ALST1:
		CanH_ErrArr[13] = 14;
		HAL_CAN_ResetError(hcan);
		break;
	case HAL_CAN_ERROR_TX_TERR1:
		CanH_ErrArr[14] = 15;
		HAL_CAN_ResetError(hcan);
		break;
	case HAL_CAN_ERROR_TX_ALST2:
		CanH_ErrArr[16] = 17;
		break;
	case HAL_CAN_ERROR_TX_TERR2:
		CanH_ErrArr[17] = 18;
		HAL_CAN_ResetError(hcan);
		break;
	case HAL_CAN_ERROR_NOT_INITIALIZED:
		CanH_ErrArr[18] = 19;
		HAL_CAN_ResetError(hcan);
		break;
	case HAL_CAN_ERROR_NOT_READY:
		CanH_ErrArr[19] = 20;
		HAL_CAN_ResetError(hcan);
		break;
	case HAL_CAN_ERROR_NOT_STARTED:
		CanH_ErrArr[20] = 21;
		HAL_CAN_ResetError(hcan);
		break;
	case HAL_CAN_ERROR_PARAM:
		CanH_ErrArr[21] = 22;
		HAL_CAN_ResetError(hcan);
		break;
	default:
		break;
	}
}
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
	if(1u == EcuM_StopModeActive)
	{
		HAL_CAN_GetRxMessage(&hcan1, CAN_RX_FIFO0, &CanH_RxHeader, CanH_RxData);
		/* NM3 */
		if(0x510 == CanH_RxHeader.StdId)
		{
			CanH_RxSig_Networkmanagement3 = CanH_RxData[1];
			if(0x11 == CanH_RxData[1])
			{
				EcuM_PerformReset(0);
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
		HAL_PWR_EnableSleepOnExit();
	}
	else
	{
		CanH_RxFifo0MsgPendingCnt++;
		HAL_CAN_GetRxMessage(&hcan1, CAN_RX_FIFO0, &CanH_RxHeader, CanH_RxData);
		/* NM3 */
		if(0x510 == CanH_RxHeader.StdId)
		{
			CanH_RxSig_Networkmanagement3 = CanH_RxData[1];
			if(0x11 == CanH_RxData[1])
			{
				CanH_RequestBusSleep = 0;
				if(CC_ACTIVE != CanH_CommunicationState) CanH_CommunicationState = FULL_COMMUNICATION;
				else
				{
					/* Do nothing. */
				}
				CanH_NoCommCounter = 0;
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
		/* VehicleState */
		if(0x97 == CanH_RxHeader.StdId)
		{
			CanH_RxSig_Ignition = CanH_RxData[2];
			CanH_RxSig_Speed = CanH_RxData[7];
			CanH_RxSig_Rpm = CanH_RxData[6];
			CanH_RxSig_Gear = CanH_RxData[3];
			CanH_RxSig_IrSensStat = CanH_RxData[5];
			CanH_VehState_MissCnt = 0;
		}
		else
		{
			/* Do nothing. */
		}
		/* StatusBodyControl */
		if(0x98 == CanH_RxHeader.StdId)
		{
			CanH_RxSig_Recirculation = CanH_RxData[0];
			CanH_RxSig_FogLights = CanH_RxData[3];
			CanH_RxSig_HighBeam = CanH_RxData[4];
			CanH_RxSig_TemperatureSensor = CanH_RxData[5];
			CanH_RxSig_TurnSignal = CanH_RxData[6];
			CanH_RxSig_AutoClimate = CanH_RxData[7];
			CanH_BodyState_MissCnt = 0;
		}
		else
		{
			/* Do nothing. */
		}
		/* StatusBodyControl2 */
		if(0x99 == CanH_RxHeader.StdId)
		{
			CanH_RxSig_FanValue = CanH_RxData[0];
			CanH_RxSig_DisplayMode = CanH_RxData[1];
			CanH_RxSig_ClimaTemp = CanH_RxData[2];
			CanH_RxSig_RotaryLightSwitch = CanH_RxData[3];
			CanH_BodyState2_MissCnt = 0;
		}
		else
		{
			/* Do nothing. */
		}
		if(0x10b == CanH_RxHeader.StdId)CanH_RxSig_CcmId = CanH_RxData[0];
		else
		{
			/* Do nothing. */
		}
		/* DataRecorder */
		if(0x10f == CanH_RxHeader.StdId)
		{
			CanH_RxSig_DrivecycleStatus = CanH_RxData[0];
			CanH_DataRecorder_MissCnt = 0;
		}
		else
		{
			/* Do nothing. */
		}
		/* Diagnosis */
		if(0x702 == CanH_RxHeader.StdId)
		{
			CanH_DiagRxHeader.DLC = CanH_RxHeader.DLC;
			CanH_DiagRxHeader.ExtId = CanH_RxHeader.ExtId;
			CanH_DiagRxHeader.FilterMatchIndex = CanH_RxHeader.FilterMatchIndex;
			CanH_DiagRxHeader.IDE = CanH_RxHeader.IDE;
			CanH_DiagRxHeader.RTR = CanH_RxHeader.RTR;
			CanH_DiagRxHeader.StdId = CanH_RxHeader.StdId;
			CanH_DiagRxHeader.Timestamp = CanH_RxHeader.Timestamp;
			for(uint8 i = 0; i < 8; i++) CanH_DiagArray[i] = CanH_RxData[i];
		}
		else
		{
			/* Do nothing. */
		}
		CanH_RxHeader.DLC = 0;
		CanH_RxHeader.ExtId = 0;
		CanH_RxHeader.FilterMatchIndex = 0;
		CanH_RxHeader.IDE = 0;
		CanH_RxHeader.RTR = 0;
		CanH_RxHeader.StdId = 0;
		CanH_RxHeader.Timestamp = 0;
		for(uint8 i = 0; i < 8; i++) CanH_RxData[i] = 0;
		DataRecorder_RxSig_VehicleSpeed = CanH_RxSig_Speed;
		DataRecorder_RxSig_DriveCycleStatus = CanH_RxSig_DrivecycleStatus;
		DigitalCluster_RxSig_IgnitionStatus = CanH_RxSig_Ignition;
		DigitalCluster_RxSig_Gear = CanH_RxSig_Gear;
		DigitalCluster_RxSig_HighBeamStatus = CanH_RxSig_HighBeam;
		DigitalCluster_RxSig_VehicleSpeed = CanH_RxSig_Speed;
		DigitalCluster_RxSig_MotorRpm = CanH_RxSig_Rpm;
		DigitalCluster_RxSig_TurnSignals = CanH_RxSig_TurnSignal;
		DigitalCluster_RxSig_DisplayMode = CanH_RxSig_DisplayMode;
		DigitalCluster_RxSig_CollisionWarning = CanH_RxSig_IrSensStat;
		if(0 != CanH_RxSig_CcmId) DigitalCluster_RxSig_CheckControlMessageId = CanH_RxSig_CcmId;
		else
		{
			/* Do nothing. */
		}
		DigitalCluster_RxSig_OutsideTemperature = CanH_RxSig_TemperatureSensor;
		DigitalCluster_RxSig_FanValue = CanH_RxSig_FanValue;
		DigitalCluster_RxSig_RequestedTemperature = CanH_RxSig_ClimaTemp;
		DigitalCluster_RxSig_Recirculation = CanH_RxSig_Recirculation;
		DigitalCluster_RxSig_AutoClimate = CanH_RxSig_AutoClimate;
		DigitalCluster_RxSig_Rls = CanH_RxSig_RotaryLightSwitch;
		switch(CanH_RxSig_FogLights)
		{
		case 1:
			DigitalCluster_RxSig_FogLightFront = 1;
			DigitalCluster_RxSig_FogLightRear = 0;
			break;
		case 2:
			DigitalCluster_RxSig_FogLightFront = 0;
			DigitalCluster_RxSig_FogLightRear = 1;
			break;
		case 3:
			DigitalCluster_RxSig_FogLightFront = 1;
			DigitalCluster_RxSig_FogLightRear = 1;
			break;
		default:
			DigitalCluster_RxSig_FogLightFront = 0;
			DigitalCluster_RxSig_FogLightRear = 0;
			break;
		}
	}
}
void HAL_CAN_RxFifo0FullCallback(CAN_HandleTypeDef *hcan)
{
	CanH_RxFifo0FullCnt++;
	if(1u == EcuM_StopModeActive)
	{
		HAL_CAN_GetRxMessage(&hcan1, CAN_RX_FIFO0, &CanH_RxHeader, CanH_RxData);
		/* NM3 */
		if(0x510 == CanH_RxHeader.StdId)
		{
			CanH_RxSig_Networkmanagement3 = CanH_RxData[1];
			if(0x11 == CanH_RxData[1])
			{
				EcuM_PerformReset(0);
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
	}
	else
	{
		CanH_RxFifo0MsgPendingCnt++;
		HAL_CAN_GetRxMessage(&hcan1, CAN_RX_FIFO0, &CanH_RxHeader, CanH_RxData);
		/* NM3 */
		if(0x510 == CanH_RxHeader.StdId)
		{
			CanH_RxSig_Networkmanagement3 = CanH_RxData[1];
			if(0x11 == CanH_RxData[1])
			{
				CanH_RequestBusSleep = 0;
				if(CC_ACTIVE != CanH_CommunicationState) CanH_CommunicationState = FULL_COMMUNICATION;
				else
				{
					/* Do nothing. */
				}
				CanH_NoCommCounter = 0;
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
		/* VehicleState */
		if(0x97 == CanH_RxHeader.StdId)
		{
			CanH_RxSig_Ignition = CanH_RxData[2];
			CanH_RxSig_Speed = CanH_RxData[7];
			CanH_RxSig_Rpm = CanH_RxData[6];
			CanH_RxSig_Gear = CanH_RxData[3];
			CanH_RxSig_IrSensStat = CanH_RxData[5];
			CanH_VehState_MissCnt = 0;
		}
		else
		{
			/* Do nothing. */
		}
		/* StatusBodyControl */
		if(0x98 == CanH_RxHeader.StdId)
		{
			CanH_RxSig_Recirculation = CanH_RxData[0];
			CanH_RxSig_FogLights = CanH_RxData[3];
			CanH_RxSig_HighBeam = CanH_RxData[4];
			CanH_RxSig_TemperatureSensor = CanH_RxData[5];
			CanH_RxSig_TurnSignal = CanH_RxData[6];
			CanH_RxSig_AutoClimate = CanH_RxData[7];
			CanH_BodyState_MissCnt = 0;
		}
		else
		{
			/* Do nothing. */
		}
		/* StatusBodyControl2 */
		if(0x99 == CanH_RxHeader.StdId)
		{
			CanH_RxSig_FanValue = CanH_RxData[0];
			CanH_RxSig_DisplayMode = CanH_RxData[1];
			CanH_RxSig_ClimaTemp = CanH_RxData[2];
			CanH_RxSig_RotaryLightSwitch = CanH_RxData[3];
			CanH_BodyState2_MissCnt = 0;
		}
		else
		{
			/* Do nothing. */
		}
		if(0x10b == CanH_RxHeader.StdId)CanH_RxSig_CcmId = CanH_RxData[0];
		else
		{
			/* Do nothing. */
		}
		/* DataRecorder */
		if(0x10f == CanH_RxHeader.StdId)
		{
			CanH_RxSig_DrivecycleStatus = CanH_RxData[0];
			CanH_DataRecorder_MissCnt = 0;
		}
		else
		{
			/* Do nothing. */
		}
		/* Diagnosis */
		if(0x702 == CanH_RxHeader.StdId)
		{
			CanH_DiagRxHeader.DLC = CanH_RxHeader.DLC;
			CanH_DiagRxHeader.ExtId = CanH_RxHeader.ExtId;
			CanH_DiagRxHeader.FilterMatchIndex = CanH_RxHeader.FilterMatchIndex;
			CanH_DiagRxHeader.IDE = CanH_RxHeader.IDE;
			CanH_DiagRxHeader.RTR = CanH_RxHeader.RTR;
			CanH_DiagRxHeader.StdId = CanH_RxHeader.StdId;
			CanH_DiagRxHeader.Timestamp = CanH_RxHeader.Timestamp;
			for(uint8 i = 0; i < 8; i++) CanH_DiagArray[i] = CanH_RxData[i];
		}
		else
		{
			/* Do nothing. */
		}
		CanH_RxHeader.DLC = 0;
		CanH_RxHeader.ExtId = 0;
		CanH_RxHeader.FilterMatchIndex = 0;
		CanH_RxHeader.IDE = 0;
		CanH_RxHeader.RTR = 0;
		CanH_RxHeader.StdId = 0;
		CanH_RxHeader.Timestamp = 0;
		for(uint8 i = 0; i < 8; i++) CanH_RxData[i] = 0;
		DataRecorder_RxSig_VehicleSpeed = CanH_RxSig_Speed;
		DataRecorder_RxSig_DriveCycleStatus = CanH_RxSig_DrivecycleStatus;
		DigitalCluster_RxSig_IgnitionStatus = CanH_RxSig_Ignition;
		DigitalCluster_RxSig_Gear = CanH_RxSig_Gear;
		DigitalCluster_RxSig_HighBeamStatus = CanH_RxSig_HighBeam;
		DigitalCluster_RxSig_VehicleSpeed = CanH_RxSig_Speed;
		DigitalCluster_RxSig_MotorRpm = CanH_RxSig_Rpm;
		DigitalCluster_RxSig_TurnSignals = CanH_RxSig_TurnSignal;
		DigitalCluster_RxSig_DisplayMode = CanH_RxSig_DisplayMode;
		DigitalCluster_RxSig_CollisionWarning = CanH_RxSig_IrSensStat;
		if(0 != CanH_RxSig_CcmId) DigitalCluster_RxSig_CheckControlMessageId = CanH_RxSig_CcmId;
		else
		{
			/* Do nothing. */
		}
		DigitalCluster_RxSig_OutsideTemperature = CanH_RxSig_TemperatureSensor;
		DigitalCluster_RxSig_FanValue = CanH_RxSig_FanValue;
		DigitalCluster_RxSig_RequestedTemperature = CanH_RxSig_ClimaTemp;
		DigitalCluster_RxSig_Recirculation = CanH_RxSig_Recirculation;
		DigitalCluster_RxSig_AutoClimate = CanH_RxSig_AutoClimate;
		DigitalCluster_RxSig_Rls = CanH_RxSig_RotaryLightSwitch;
		switch(CanH_RxSig_FogLights)
		{
		case 1:
			DigitalCluster_RxSig_FogLightFront = 1;
			DigitalCluster_RxSig_FogLightRear = 0;
			break;
		case 2:
			DigitalCluster_RxSig_FogLightFront = 0;
			DigitalCluster_RxSig_FogLightRear = 1;
			break;
		case 3:
			DigitalCluster_RxSig_FogLightFront = 1;
			DigitalCluster_RxSig_FogLightRear = 1;
			break;
		default:
			DigitalCluster_RxSig_FogLightFront = 0;
			DigitalCluster_RxSig_FogLightRear = 0;
			break;
		}
	}
}
