#ifndef MCMCAN_H_
#define MCMCAN_H_ 1

#include <stdio.h>
#include <string.h>
#include "Ifx_Types.h"
#include "IfxCan_Can.h"
#include "IfxCpu_Irq.h"
#include "IfxPort.h"
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define MAXIMUM_CAN_DATA_PAYLOAD    8u
#define CAN_NO_RX_MSG               10u
#define CAN_NO_TX_MSG               10u
#define CAN_RX_BUFFER_COUNT         9u
#define ISO_TP_MAX_PAYLOAD          2048u
#define ISO_TP_CAN_DL               8u

typedef struct
{
        uint16 id;
        uint8  dlc;
        uint8  data[ISO_TP_CAN_DL];
} CanMsg;

typedef enum
{
    ISO_TP_TX_IDLE = 0,
    ISO_TP_TX_WAIT_FC,
    ISO_TP_TX_CF
} IsoTpTxState_t;

typedef struct
{
    uint16 txId;
    const uint8 *txData;
    uint16 txDataSize;
    uint16 txDataOffset;
    uint8  txSequenceNumber;
    uint8  blockSize;
    uint8  stMin;
    uint8  blockCounter;
    IsoTpTxState_t state;
} IsoTpTx_t;


typedef enum
{
    CAN_INIT = 0U,
    CAN_INIT_SUCCESFUL = 1U,
    CAN_PROCESS_RXTX = 2U,
    CAN_SLEEP = 3U,
    CAN_FIRST_TRANSMIT = 4U,
    CAN_ERROR = 5U,
    CAN_WAKEUP = 6U
}Can_Status_t;

typedef struct
{
        IfxCan_Can_Config canConfig;
        IfxCan_Can canModule;
        IfxCan_Can_Node canSrcNode;
        IfxCan_Can_Node canDstNode;
        IfxCan_Can_NodeConfig canNodeConfig;
        IfxCan_Filter canFilter;
        IfxCan_Message txMsg;
        IfxCan_Message rxMsg;
        uint8 txData[MAXIMUM_CAN_DATA_PAYLOAD];
        uint8 rxData[MAXIMUM_CAN_DATA_PAYLOAD];
} McmcanType;

typedef struct
{
        IfxCan_Message rxMsg;
        uint8 rxData[MAXIMUM_CAN_DATA_PAYLOAD];
}Can_RxMsg_t;

typedef struct
{
        IfxCan_Message txMsg;
        uint8 txData[MAXIMUM_CAN_DATA_PAYLOAD];
}Can_TxMsg_t;

typedef struct
{
        Can_TxMsg_t transmitMessage;
        uint8 transmitFlag;
        uint8 cycleTime;
        uint8 transmissionRule;
}Can_TransmitType_t;

typedef struct
{
        Can_RxMsg_t receiveMessage;
        uint8 receivedValidFlag;
}Can_ReceiveType_t;

extern Can_TransmitType_t Can_TransmitTable[CAN_NO_TX_MSG];
extern Can_ReceiveType_t Can_ReceiveTable[CAN_NO_RX_MSG];
extern McmcanType g_mcmcan;
extern uint32 Can_Rx_DiagBufCnt;
extern Can_RxMsg_t Can_RxMessageBuffer[50u];
extern Can_RxMsg_t Can_Rx_DiagnosticBuffer[50u];
extern uint32 Can_BufferIndex_ReceivedMessages;
extern uint8 Can_BusOff_Flag;
extern uint8 Can_Alrt_Flag;
extern uint8 Can_Moer_Flag;
extern uint8 Can_Loi_Flag;
extern Can_Status_t Can_State;
extern uint8 Can_ActivityOnTheBus;
extern uint8 Can_DedBuff;

extern void Can_Sleep(void);
extern void Can_ProcessReceivedMessages(void);
extern void Can_TransmitScheduleTable(void);
extern void Can_TransmitAllMessages(void);
extern void Can_TransmitDiagnosis(void);
extern void Can_Init(void);
extern bool Can_Tx(McmcanType message);
extern void Can_Rx(void);
extern void Can_MainFunction(void);
extern bool Can_IsoTp_SendFrame(uint16 canId, const uint8 *data, uint8 size);
extern void Can_IsoTp_MainFunction(void);
extern bool Can_SendFrame(uint16 id, const uint8_t *data, uint8 dlc);
extern bool Can_IsoTpTransmit(uint16 txId, const uint8 *data, uint16 length);
extern void Can_ProcessIsoTpMessage(const CanMsg *msg);
extern void Can_SendFlowControlFrame(void);
extern void Can_IsoTpTx_MainFunction(void);
#endif /* MCMCAN_H_ */
