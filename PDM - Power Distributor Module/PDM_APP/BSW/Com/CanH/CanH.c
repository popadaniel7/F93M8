#include "CanH.h"
#include "can.h"
#include "Dem.h"
#include "Xcp.h"

uint8 CanH_RxSig_Gear = 0;
uint8 CanH_RxSig_Ignition = 0;
uint8 CanH_RxSig_Rpm = 0;
uint8 CanH_RxSig_Speed = 0;
uint32 CanH_MainCounter = 0;
CAN_RxHeaderTypeDef CanH_RxHeader = {0, 0, 0, 0, 0, 0, 0};
uint8 CanH_RxData[8] = {0};
CAN_TxHeaderTypeDef CanH_TxHeader = {0, 0, 0, 0, 0, 0};
uint8 CanH_TxData[8] = {0};
uint32 CanH_TxMailbox = 0;
uint8 CanH_XcpTxData[8] = {0};
uint32 CanH_XcpTxMailbox = 0;
CAN_TxHeaderTypeDef CanH_XcpTxHeader = {0, 0, 0, 0, 0, 0};
uint8 CanH_RequestBusSleep = 0;
uint32 CanH_NoCommCounter = 0;
CanH_ComStat_t CanH_CommunicationState = 0;
uint8 CanH_XcpArray[8] = {0};
uint8 CanH_DiagArray[8] = {0};
CAN_RxHeaderTypeDef CanH_DiagRxHeader = {0, 0, 0, 0, 0, 0, 0};
CAN_RxHeaderTypeDef CanH_XcpRxHeader = {0, 0, 0, 0, 0, 0, 0};
uint8 Can_isXcpActive = 0;
extern CAN_HandleTypeDef hcan;
extern uint8 CanH_TxSig_StatusList1;
extern uint8 CanH_TxSig_StatusList2;
extern uint8 CanH_TxSig_StatusList3;
extern uint8 CanH_TxSig_StatusList4;
extern uint8 CanH_TxSig_StatusList5;
extern uint8 CanH_TxSig_StatusList6;
extern uint8 CanH_TxSig_StatusList7;
extern uint8 CanH_TxSig_StatusList8;
extern uint8 CanH_TxSig_TotalCurrentConsumption;
extern uint8 CanH_TxSig_TotalCurrentConsumption2;
extern uint8 CanH_TxSig_PowerSupplyNetworkWarning;
extern uint8 CanH_TxSig_SupplyVoltage;
extern uint8 CanH_RxSig_CommandList1;
extern uint8 CanH_RxSig_CommandList2;
extern uint8 CanH_RxSig_CommandList3;
extern uint8 CanH_RxSig_CommandList4;
extern uint8 CanH_RxSig_CommandList5;
extern uint8 CanH_RxSig_CommandList6;
extern uint8 CanH_RxSig_CommandList7;
extern uint8 CanH_RxSig_CommandList8;

void CanH_MainFunction(void);
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_RxFifo0MsgFullCallback(CAN_HandleTypeDef *hcan);

void CanH_MainFunction(void)
{
	if(1 == Can_isXcpActive) Xcp_MainFunction(); /* XCP functionality... well not XCP, but CCP, because it was easier to use with CAN standard. */
	else
	{
		/* Do nothing. */
	}
	/* Don't attempt to send CAN messages with error. */
	if(0x04 != HAL_CAN_GetError(&hcan))
	{
		/* Pre-conditions for sending messages. CC = Communication control set to no TX by default / hard-coded by DIAG request. */
		if((FULL_COMMUNICATION == CanH_CommunicationState) &&
				(PARTIAL_COMMUNICATION != CanH_CommunicationState) &&
				CC_ACTIVE != CanH_CommunicationState)
		{
			/* StatusLoadList */
			if(0 == CanH_MainCounter % 20)
			{
				CanH_TxData[0] = CanH_TxSig_StatusList1;
				CanH_TxData[1] = CanH_TxSig_StatusList2;
				CanH_TxData[2] = CanH_TxSig_StatusList3;
				CanH_TxData[3] = CanH_TxSig_StatusList4;
				CanH_TxData[4] = CanH_TxSig_StatusList5;
				CanH_TxData[5] = CanH_TxSig_StatusList6;
				CanH_TxData[6] = CanH_TxSig_StatusList7;
				CanH_TxData[7] = CanH_TxSig_StatusList8;
				CanH_TxHeader.DLC = 8;
				CanH_TxHeader.StdId = 0x103;
				HAL_CAN_AddTxMessage(&hcan, &CanH_TxHeader, CanH_TxData, &CanH_TxMailbox);
				for(uint8 i = 0; i < 8; i++) CanH_TxData[i] = 0;
				CanH_TxHeader.DLC = 0;
				CanH_TxHeader.StdId = 0;
			}
			else
			{
				/* Do nothing. */
			}
			/* StatusPowerSupplyNetwork */
			if(0 == CanH_MainCounter % 20)
			{
				CanH_TxData[0] = CanH_TxSig_PowerSupplyNetworkWarning;
				CanH_TxHeader.DLC = 1;
				CanH_TxHeader.StdId = 0x104;
				HAL_CAN_AddTxMessage(&hcan, &CanH_TxHeader, CanH_TxData, &CanH_TxMailbox);
				CanH_TxData[0] = 0;
				CanH_TxHeader.DLC = 0;
				CanH_TxHeader.StdId = 0;
			}
			else
			{
				/* Do nothing */
			}
			/* StatusVoltageCurrent */
			if(0 == CanH_MainCounter % 20)
			{
				CanH_TxData[1] = CanH_TxSig_TotalCurrentConsumption;
				CanH_TxData[2] = CanH_TxSig_TotalCurrentConsumption2;
				CanH_TxData[0] = CanH_TxSig_SupplyVoltage;
				CanH_TxHeader.DLC = 3;
				CanH_TxHeader.StdId = 0x107;
				HAL_CAN_AddTxMessage(&hcan, &CanH_TxHeader, CanH_TxData, &CanH_TxMailbox);
				CanH_TxData[0] = 0;
				CanH_TxData[1] = 0;
				CanH_TxHeader.DLC = 0;
				CanH_TxHeader.StdId = 0;
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
		/* Do nothing. */
	}
	/* Request TRCV off. */
	if(NO_COMMUNICATION == CanH_CommunicationState)
	{
		CanH_RequestBusSleep = 1;
	}
	else
	{
		/* Do nothing.  */
	}
	/* Keep SW in RUN for at least 10 seconds. */
	if(2000 <= CanH_NoCommCounter)
	{
		CanH_CommunicationState = NO_COMMUNICATION;
	}
	else
	{
		/* Do nothing. */
	}
	/* Switch TRCV off. */
	if(1 == CanH_RequestBusSleep)
	{
		if(0 == HAL_CAN_IsSleepActive(&hcan))
		{
			HAL_CAN_RequestSleep(&hcan);
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
	CanH_NoCommCounter++;
	CanH_MainCounter++;
	for(uint8 i = 0; i < 8; i++) CanH_TxData[i] = 0;
}
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
	/* Pending and full callback to prevent messages being lost. */
	HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &CanH_RxHeader, CanH_RxData);
	/* CommandLoad */
	if(0x10e == CanH_RxHeader.StdId)
	{
		CanH_RxSig_CommandList1 = CanH_RxData[0];
		CanH_RxSig_CommandList2 = CanH_RxData[1];
		CanH_RxSig_CommandList3 = CanH_RxData[2];
		CanH_RxSig_CommandList4 = CanH_RxData[3];
		CanH_RxSig_CommandList5 = CanH_RxData[4];
		CanH_RxSig_CommandList6 = CanH_RxData[5];
		CanH_RxSig_CommandList7 = CanH_RxData[6];
		CanH_RxSig_CommandList8 = CanH_RxData[7];
	}
	else
	{
		/* Do nothing. */
	}
	/* NM3 */
	if(0x510 == CanH_RxHeader.StdId &&
			0x10 == CanH_RxData[0])
	{
		if(CanH_CommunicationState != CC_ACTIVE) CanH_CommunicationState = FULL_COMMUNICATION;
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
	/* XCP / CCP */
	if(0x602 == CanH_RxHeader.StdId)
	{
		CanH_XcpRxHeader.StdId = CanH_RxHeader.StdId;
		CanH_XcpRxHeader.DLC = CanH_RxHeader.DLC;
		Can_isXcpActive = 1;
		for(uint8 i = 0; i < 8; i++) CanH_XcpArray[i] = CanH_RxData[i];
	}
	else
	{
		/* Do nothing. */
	}
	/* DIAG */
	if(0x702 == CanH_RxHeader.StdId)
	{
		CanH_DiagRxHeader.StdId = CanH_RxHeader.StdId;
		CanH_DiagRxHeader.DLC = CanH_RxHeader.DLC;
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
}
void HAL_CAN_RxFifo0MsgFullCallback(CAN_HandleTypeDef *hcan)
{
	/* Pending and full callback to prevent messages being lost. */
	HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &CanH_RxHeader, CanH_RxData);
	/* CommandLoad */
	if(0x10e == CanH_RxHeader.StdId)
	{
		CanH_RxSig_CommandList1 = CanH_RxData[0];
		CanH_RxSig_CommandList2 = CanH_RxData[1];
		CanH_RxSig_CommandList3 = CanH_RxData[2];
		CanH_RxSig_CommandList4 = CanH_RxData[3];
		CanH_RxSig_CommandList5 = CanH_RxData[4];
		CanH_RxSig_CommandList6 = CanH_RxData[5];
		CanH_RxSig_CommandList7 = CanH_RxData[6];
		CanH_RxSig_CommandList8 = CanH_RxData[7];
	}
	else
	{
		/* Do nothing. */
	}
	/* NM3 */
	if(0x510 == CanH_RxHeader.StdId &&
			0x10 == CanH_RxData[0])
	{
		if(CanH_CommunicationState != CC_ACTIVE) CanH_CommunicationState = FULL_COMMUNICATION;
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
	/* XCP / CCP */
	if(0x602 == CanH_RxHeader.StdId)
	{
		CanH_XcpRxHeader.StdId = CanH_RxHeader.StdId;
		CanH_XcpRxHeader.DLC = CanH_RxHeader.DLC;
		Can_isXcpActive = 1;
		for(uint8 i = 0; i < 8; i++) CanH_XcpArray[i] = CanH_RxData[i];
	}
	else
	{
		/* Do nothing. */
	}
	/* DIAG */
	if(0x702 == CanH_RxHeader.StdId)
	{
		CanH_DiagRxHeader.StdId = CanH_RxHeader.StdId;
		CanH_DiagRxHeader.DLC = CanH_RxHeader.DLC;
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
}
