/* START OF FILE */
/* INCLUDE START */
#include "Xcp.h"
#include "can.h"
#include "CanH.h"
/* INCLUDE END */
/* VARIABLES START */
/* Store read address for XCP. */
uint32 Xcp_RequestedAddress = 0;
extern uint8 OS_XCP_CpuLoad;
extern uint8 CanH_XcpTxData[8];
extern uint32 CanH_XcpTxMailbox;
extern CAN_TxHeaderTypeDef CanH_XcpTxHeader;
extern CAN_RxHeaderTypeDef CanH_XcpRxHeader;
extern uint8 Can_isXcpActive;
extern uint8 CanH_XcpArray[8];
/* VARIABLES STOP */
/* FUNCTIONS START */
void Xcp_PositiveAcknowledge(void);
void Xcp_MainFunction(void);
/* FUNCTIONS STOP */
/* FUNCTIONS START */
/* Positive response to XCP request. */
void Xcp_PositiveAcknowledge(void)
{
	CanH_XcpTxHeader.DLC = CanH_XcpRxHeader.DLC;
	CanH_XcpTxHeader.StdId = CanH_XcpRxHeader.StdId + 1;
	CanH_XcpTxData[0] = 0xFF;
	CanH_XcpTxData[1] = 0x00;
	CanH_XcpTxData[2] = CanH_XcpArray[1];
	CanH_XcpTxData[3] = CanH_XcpArray[3];
	CanH_XcpTxData[4] = CanH_XcpArray[4];
	CanH_XcpTxData[5] = CanH_XcpArray[5];
	CanH_XcpTxData[6] = CanH_XcpArray[6];
	HAL_CAN_AddTxMessage(&hcan, &CanH_XcpTxHeader, CanH_XcpTxData, &CanH_XcpTxMailbox);
	CanH_XcpTxMailbox = 0;
	CanH_XcpTxHeader.DLC = 0;
	CanH_XcpTxHeader.ExtId = 0;
	CanH_XcpTxHeader.IDE = 0;
	CanH_XcpTxHeader.RTR = 0;
	CanH_XcpTxHeader.StdId = 0;
	for(uint8 i = 0; i < 8; i++) CanH_XcpTxData[i] = 0;
}
/* Main function. */
void Xcp_MainFunction(void)
{
	/* Main counter. */
	static uint32 Xcp_MainCounter = 0;
	/* Connect command. */
	if(CanH_XcpArray[0] == 0x01)
	{
		Xcp_PositiveAcknowledge();
	}
	else
	{
		/* Do nothing. */
	}
	/* Set MTA command. */
	if(CanH_XcpArray[0] == 0x02)
	{
		/* Positive response. */
		Xcp_PositiveAcknowledge();
		/* Get the address requested to be read. */
		Xcp_RequestedAddress = (CanH_XcpArray[7] << 24) \
				| (CanH_XcpArray[6] << 16) \
				| (CanH_XcpArray[5] << 8) \
				|  CanH_XcpArray[4];
	}
	else
	{
		/* Do nothing. */
	}
	/* Upload requested variable. */
	if(CanH_XcpArray[0] == 0x04)
	{
		/* Process the address. */
		volatile uint32 *ptr = (volatile uint32*)(Xcp_RequestedAddress);
		uint32 value = *ptr;
		/* Respond with the requested value. */
		CanH_XcpArray[3] = (value >> 24) & 0xFF;
		CanH_XcpArray[4] = (value >> 16) & 0xFF;
		CanH_XcpArray[5] = (value >> 8) & 0xFF;
		CanH_XcpArray[6] = value & 0xFF;
		Xcp_PositiveAcknowledge();
	}
	else
	{
		/* Do nothing. */
	}
	/* GET CCP VERSION */
	if(CanH_XcpArray[0] == 0x1B)
	{
		Xcp_PositiveAcknowledge();
	}
	else
	{
		/* Do nothing. */
	}
	/* EXCHANGE_ID */
	if(CanH_XcpArray[0] == 0x17)
	{
		Xcp_PositiveAcknowledge();
	}
	else
	{
		/* Do nothing. */
	}
	/* DISCONNECT */
	if(CanH_XcpArray[0] == 0x07)
	{
		Xcp_PositiveAcknowledge();
		Can_isXcpActive = 0;
	}
	else
	{
		/* Do nothing. */
	}
	/* Reset the buffers */
	CanH_XcpRxHeader.DLC = 0;
	CanH_XcpRxHeader.ExtId = 0;
	CanH_XcpRxHeader.FilterMatchIndex = 0;
	CanH_XcpRxHeader.IDE = 0;
	CanH_XcpRxHeader.RTR = 0;
	CanH_XcpRxHeader.StdId = 0;
	CanH_XcpRxHeader.Timestamp = 0;
	for(uint8 i = 0; i < 8; i++)
	{
		CanH_XcpArray[i] = 0;
	}
	/* Increment the counter. */
	Xcp_MainCounter++;
}
/* FUNCTIONS STOP */
/* STOP OF FILE */
