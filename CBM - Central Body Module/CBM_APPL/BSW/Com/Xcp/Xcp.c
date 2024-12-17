/* START OF FILE */
/* INCLUDE START */
#include "Xcp.h"
#include "CanSpi.h"
/* INCLUDE END */
/* VARIABLES START */
/* Store read address for XCP. */
uint32 Xcp_RequestedAddress = 0;
extern uint8 OS_XCP_CpuLoad;
/* VARIABLES STOP */
/* FUNCTIONS START */
void Xcp_PositiveAcknowledge(void);
void Xcp_MainFunction(void);
/* FUNCTIONS STOP */
/* FUNCTIONS START */
/* Positive response to XCP request. */
void Xcp_PositiveAcknowledge(void)
{
	CanSpi_Xcp_TxBuffer.frame.id = CanSpi_Xcp_RxBuffer.frame.id + 1;;
	CanSpi_Xcp_TxBuffer.frame.idType = CanSpi_Xcp_RxBuffer.frame.idType;
	CanSpi_Xcp_TxBuffer.frame.dlc = CanSpi_Xcp_RxBuffer.frame.dlc;
	CanSpi_Xcp_TxBuffer.frame.data0 = 0xFF;
	CanSpi_Xcp_TxBuffer.frame.data1 = 0x00;
	CanSpi_Xcp_TxBuffer.frame.data2 = CanSpi_Xcp_RxBuffer.frame.data1;
	CanSpi_Transmit(&CanSpi_Xcp_TxBuffer);
	CanSpi_Xcp_TxBuffer.frame.idType = 0;
	CanSpi_Xcp_TxBuffer.frame.id = 0;
	CanSpi_Xcp_TxBuffer.frame.dlc = 0;
	CanSpi_Xcp_TxBuffer.frame.data0 = 0;
	CanSpi_Xcp_TxBuffer.frame.data1 = 0;
	CanSpi_Xcp_TxBuffer.frame.data2 = 0;
	CanSpi_Xcp_TxBuffer.frame.data3 = 0;
	CanSpi_Xcp_TxBuffer.frame.data4 = 0;
	CanSpi_Xcp_TxBuffer.frame.data5 = 0;
	CanSpi_Xcp_TxBuffer.frame.data6 = 0;
	CanSpi_Xcp_TxBuffer.frame.data7 = 0;
}
/* Main function. */
void Xcp_MainFunction(void)
{
	/* Main counter. */
	static uint32 Xcp_MainCounter = 0;
	/* Connect command. */
	if(CanSpi_Xcp_RxBuffer.frame.data0 == 0x01) Xcp_PositiveAcknowledge();
	else
	{
		/* Do nothing. */
	}
	/* Set MTA command. */
	if(CanSpi_Xcp_RxBuffer.frame.data0 == 0x02)
	{
		/* Positive response. */
		Xcp_PositiveAcknowledge();
		/* Get the address requested to be read. */
		Xcp_RequestedAddress = (CanSpi_Xcp_RxBuffer.frame.data7 << 24) \
				| (CanSpi_Xcp_RxBuffer.frame.data6 << 16) \
				| (CanSpi_Xcp_RxBuffer.frame.data5 << 8) \
				| CanSpi_Xcp_RxBuffer.frame.data4;
	}
	else
	{
		/* Do nothing. */
	}
	/* Upload requested variable. */
	if(CanSpi_Xcp_RxBuffer.frame.data0 == 0x04)
	{
		/* Process the address. */
		volatile uint32 *ptr = (volatile uint32*)(Xcp_RequestedAddress);
		uint32 value = *ptr;
		/* Respond with the requested value. */
		CanSpi_Xcp_TxBuffer.frame.data3 = (value >> 24) & 0xFF;
		CanSpi_Xcp_TxBuffer.frame.data4 = (value >> 16) & 0xFF;
		CanSpi_Xcp_TxBuffer.frame.data5 = (value >> 8) & 0xFF;
		CanSpi_Xcp_TxBuffer.frame.data6 = value & 0xFF;
		Xcp_PositiveAcknowledge();
	}
	else
	{
		/* Do nothing. */
	}
	/* GET CCP VERSION */
	if(CanSpi_Xcp_RxBuffer.frame.data0 == 0x1B) Xcp_PositiveAcknowledge();
	else
	{
		/* Do nothing. */
	}
	/* EXCHANGE_ID */
	if(CanSpi_Xcp_RxBuffer.frame.data0 == 0x17) Xcp_PositiveAcknowledge();
	else
	{
		/* Do nothing. */
	}
	/* DISCONNECT */
	if(CanSpi_Xcp_RxBuffer.frame.data0 == 0x07)
	{
		Xcp_PositiveAcknowledge();
		CanSpi_isXcpActive = 0;
	}
	else
	{
		/* Do nothing. */
	}
	/* Reset the buffers */
	CanSpi_Xcp_RxBuffer.frame.idType = 0;
	CanSpi_Xcp_RxBuffer.frame.id = 0;
	CanSpi_Xcp_RxBuffer.frame.dlc = 0;
	CanSpi_Xcp_RxBuffer.frame.data0 = 0;
	CanSpi_Xcp_RxBuffer.frame.data1 = 0;
	CanSpi_Xcp_RxBuffer.frame.data2 = 0;
	CanSpi_Xcp_RxBuffer.frame.data3 = 0;
	CanSpi_Xcp_RxBuffer.frame.data4 = 0;
	CanSpi_Xcp_RxBuffer.frame.data5 = 0;
	CanSpi_Xcp_RxBuffer.frame.data6 = 0;
	CanSpi_Xcp_RxBuffer.frame.data7 = 0;
	/* Increment the counter. */
	Xcp_MainCounter++;
}
/* FUNCTIONS STOP */
/* STOP OF FILE */
