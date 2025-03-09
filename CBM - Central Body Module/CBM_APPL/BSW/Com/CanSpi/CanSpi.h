/* START OF FILE */
/* INCLUDE START */
#include "Std_Types.h"
#include "spi.h"
#include "stdbool.h"
/* INCLUDE END */
/* DEFINE START */
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RESET          	 	0xC0
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_READ           	 	0x03
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_READ_RXB0SIDH  	 	0x90
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_READ_RXB0D0     		0x92
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_READ_RXB1SIDH  	 	0x94
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_READ_RXB1D0     		0x96
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_WRITE           		0x02
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_LOAD_TXB0SIDH   		0x40
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_LOAD_TXB0D0     		0x41
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_LOAD_TXB1SIDH   		0x42
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_LOAD_TXB1D0     		0x43
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_LOAD_TXB2SIDH   		0x44
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_LOAD_TXB2D0     		0x45
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RTS_TX0         		0x81
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RTS_TX1         		0x82
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RTS_TX2         		0x84
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RTS_ALL         		0x87
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_READ_STATUS     		0xA0
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RX_STATUS       		0xB0
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_BIT_MOD         		0x05
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXF0SIDH				0x00
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXF0SIDL				0x01
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXF0EID8				0x02
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXF0EID0				0x03
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXF1SIDH				0x04
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXF1SIDL				0x05
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXF1EID8				0x06
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXF1EID0				0x07
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXF2SIDH				0x08
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXF2SIDL				0x09
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXF2EID8				0x0A
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXF2EID0				0x0B
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_CANSTAT				0x0E
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_CANCTRL				0x0F
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXF3SIDH				0x10
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXF3SIDL				0x11
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXF3EID8				0x12
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXF3EID0				0x13
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXF4SIDH				0x14
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXF4SIDL				0x15
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXF4EID8				0x16
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXF4EID0				0x17
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXF5SIDH				0x18
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXF5SIDL				0x19
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXF5EID8				0x1A
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXF5EID0				0x1B
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_TEC					0x1C
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_REC					0x1D
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXM0SIDH				0x20
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXM0SIDL				0x21
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXM0EID8				0x22
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXM0EID0				0x23
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXM1SIDH				0x24
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXM1SIDL				0x25
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXM1EID8				0x26
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXM1EID0				0x27
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_CNF3					0x28
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_CNF2					0x29
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_CNF1					0x2A
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_CANINTE				0x2B
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_CANINTF				0x2C
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_EFLG					0x2D
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_TXB0CTRL				0x30
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_TXB1CTRL				0x40
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_TXB2CTRL				0x50
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXB0CTRL				0x60
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXB0SIDH				0x61
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXB1CTRL				0x70
/* MCP2515 REGISTER */
#define CANSPI_MCP2515_RXB1SIDH				0x71
/* MCP2515 REGISTER */
#define CANSPI_MSG_IN_RXB0             		0x01
/* MCP2515 REGISTER */
#define CANSPI_MSG_IN_RXB1             		0x02
/* MCP2515 REGISTER */
#define CANSPI_MSG_IN_BOTH_BUFFERS     		0x03
/* MCP2515 REGISTER */
#define CANSPI_dSTANDARD_CAN_MSG_ID_2_0B 	1
/* MCP2515 REGISTER */
#define CANSPI_dEXTENDED_CAN_MSG_ID_2_0B 	2
/* DEFINE STOP */
/* TYPEDEF START */
/* COM STATE ENUM */
typedef enum
{
	NO_COMMUNICATION,
	PARTIAL_COMMUNICATION,
	FULL_COMMUNICATION,
	CC_ACTIVE
}CANSPI_ComState_t;
/* CAN FRAME DATA TYPE */
typedef union
{
	struct
	{
		uint8 idType;
		uint32 id;
		uint8 dlc;
		uint8 data0;
		uint8 data1;
		uint8 data2;
		uint8 data3;
		uint8 data4;
		uint8 data5;
		uint8 data6;
		uint8 data7;
	}frame;
}CANSPI_uCAN_MSG;
/* CTRL STATUS REGISTER DATA TYPE */
typedef union
{
	struct
	{
		unsigned RX0IF      : 1;
		unsigned RX1IF      : 1;
		unsigned TXB0REQ    : 1;
		unsigned TX0IF      : 1;
		unsigned TXB1REQ    : 1;
		unsigned TX1IF      : 1;
		unsigned TXB2REQ    : 1;
		unsigned TX2IF      : 1;
	};
	uint8 CtrlStatus;
}CANSPI_CtrlStatus_t;
/* CTRL RX STATUS REGISTER DATA TYPE */
typedef union
{
	struct
	{
		unsigned filter     : 3;
		unsigned msgType    : 2;
		unsigned unusedBit  : 1;
		unsigned rxBuffer   : 2;
	};
	uint8 CtrlRxStatus;
}CANSPI_CtrlRxStatus_t;
/* CTRL ERROR STATUS REGISTER DATA TYPE */
typedef union
{
	struct
	{
		unsigned EWARN      :1;
		unsigned RXWAR      :1;
		unsigned TXWAR      :1;
		unsigned RXEP       :1;
		unsigned TXEP       :1;
		unsigned TXBO       :1;
		unsigned RX0OVR     :1;
		unsigned RX1OVR     :1;
	};
	uint8 CtrlErrorStatus;
}CANSPI_CtrlErrorStatus_t;
/* RX REGISTER DATA TYPE */
typedef union
{
	struct
	{
		uint8_t RXBnSIDH;
		uint8_t RXBnSIDL;
		uint8_t RXBnEID8;
		uint8_t RXBnEID0;
		uint8_t RXBnDLC;
		uint8_t RXBnD0;
		uint8_t RXBnD1;
		uint8_t RXBnD2;
		uint8_t RXBnD3;
		uint8_t RXBnD4;
		uint8_t RXBnD5;
		uint8_t RXBnD6;
		uint8_t RXBnD7;
	};
	uint8 rx_reg_array[13];
}CANSPI_rx_reg_t;
/* RXF0 REGISTER DATA TYPE */
typedef struct
{
	uint8 RXF0SIDH;
	uint8 RXF0SIDL;
	uint8 RXF0EID8;
	uint8 RXF0EID0;
}CANSPI_RXF0;
/* RXF1 REGISTER DATA TYPE */
typedef struct
{
	uint8 RXF1SIDH;
	uint8 RXF1SIDL;
	uint8 RXF1EID8;
	uint8 RXF1EID0;
}CANSPI_RXF1;
/* RXF2 REGISTER DATA TYPE */
typedef struct
{
	uint8 RXF2SIDH;
	uint8 RXF2SIDL;
	uint8 RXF2EID8;
	uint8 RXF2EID0;
}CANSPI_RXF2;
/* RXF3 REGISTER DATA TYPE */
typedef struct
{
	uint8 RXF3SIDH;
	uint8 RXF3SIDL;
	uint8 RXF3EID8;
	uint8 RXF3EID0;
}CANSPI_RXF3;
/* RXF4 REGISTER DATA TYPE */
typedef struct
{
	uint8 RXF4SIDH;
	uint8 RXF4SIDL;
	uint8 RXF4EID8;
	uint8 RXF4EID0;
}CANSPI_RXF4;
/* RXF5 REGISTER DATA TYPE */
typedef struct
{
	uint8 RXF5SIDH;
	uint8 RXF5SIDL;
	uint8 RXF5EID8;
	uint8 RXF5EID0;
}CANSPI_RXF5;
/* RXM0 REGISTER DATA TYPE */
typedef struct
{
	uint8 RXM0SIDH;
	uint8 RXM0SIDL;
	uint8 RXM0EID8;
	uint8 RXM0EID0;
}CANSPI_RXM0;
/* RXM1 REGISTER DATA TYPE */
typedef struct
{
	uint8 RXM1SIDH;
	uint8 RXM1SIDL;
	uint8 RXM1EID8;
	uint8 RXM1EID0;
}CANSPI_RXM1;
/* ID REGISTER DATA TYPE */
typedef struct
{
	uint8 tempSIDH;
	uint8 tempSIDL;
	uint8 tempEID8;
	uint8 tempEID0;
}CANSPI_id_reg_t;
/* TYPEDEF STOP */
/* VARIABLES START */
/* Error counter for SPI. */
extern uint32 CanSpi_ErrorArr[9];
/* Error counter for CAN bus. */
extern uint32 CanSpi_Bus_ErrorArr[3];
/* Communication status variable. */
extern CANSPI_ComState_t CanSpi_Communication_Status;
/* Communication status timeout variable. */
extern uint16 CanSpi_Communication_StatusTimeout;
/* CAN RX buffer 1. */
extern CANSPI_uCAN_MSG CanSpi_RxFrame_Buffer0;
/* CAN RX buffer 2. */
extern CANSPI_uCAN_MSG CanSpi_RxFrame_Buffer1;
/* DIAG ROUTINE CAN RX buffer. */
extern CANSPI_uCAN_MSG Dcm_DiagServiceResponse_Frame;
/* DIAG ROUTINE CAN TX buffer. */
extern CANSPI_uCAN_MSG Dcm_DiagServiceRequest_Frame;
/* NM3 signal value. */
extern uint8 CanSpi_Networkmanagement3_Signal;
/* VARIABLES STOP */
/* FUNCTIONS START */
/* Main function. */
extern void CanSpi_MainFunction(void);
/* Configure CAN transceiver for sleep. */
extern void CanSpi_Sleep(void);
/* Initialization function. */
extern uint8 CanSpi_Initialize(void);
/* Transmit function. */
extern uint8 CanSpi_Transmit(CANSPI_uCAN_MSG *tempCanMsg);
/* Receive function. */
extern uint8 CanSpi_Receive(CANSPI_uCAN_MSG *tempCanMsg);
/* FUNCTIONS STOP */
/* STOP OF FILE */
