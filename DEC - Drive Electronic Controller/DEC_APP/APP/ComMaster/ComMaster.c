#include "ComMaster.h"
#include "EncCal.h"
#include "Crc.h"
#include "SysMgr.h"
#include "Dem.h"

#define WUP_PDM               &MODULE_P00,0
#define WUP_DMU               &MODULE_P00,1

ComMaster_TransmitType_t ComMaster_TransmitTable[7u] =
{
        /* Vehicle State */
        {
                .transmitMessage =
                {
                        .txMsg =
                        {
                                .bufferNumber = 0u,
                                .messageId = 0x97u,
                                .remoteTransmitRequest = 0u,
                                .messageIdLength = IfxCan_MessageIdLength_standard,
                                .errorStateIndicator = 0u,
                                .dataLengthCode = 8u,
                                .frameMode = IfxCan_FrameMode_standard,
                                .txEventFifoControl = FALSE,
                                .storeInTxFifoQueue = FALSE,
                                .readFromRxFifo0 = FALSE,
                                .readFromRxFifo1 = FALSE
                        },
                        .txData =
                        {
                                0u,//ComMaster_TxSignal_Gear
                                0u,//ComMaster_TxSignal_Ignition
                                0u,//ComMaster_TxSignal_IrSenStat
                                0u,//ComMaster_TxSignal_PowerSteeringAngle
                                0u,//ComMaster_TxSignal_Rpm
                                0u,//ComMaster_TxSignal_Speed
                                0u//ComMaster_TxSignal_VehicleStatus
                        }
                },
                .transmitFlag = 1u,
                .cycleTime = 20u,
        },
        /* Status Body Control */
        {
                .transmitMessage =
                {
                        .txMsg =
                        {
                                .bufferNumber = 1u,
                                .messageId = 0x98u,
                                .remoteTransmitRequest = 0u,
                                .messageIdLength = IfxCan_MessageIdLength_standard,
                                .errorStateIndicator = 0u,
                                .dataLengthCode = 6u,
                                .frameMode = IfxCan_FrameMode_standard,
                                .txEventFifoControl = FALSE,
                                .storeInTxFifoQueue = FALSE,
                                .readFromRxFifo0 = FALSE,
                                .readFromRxFifo1 = FALSE
                        },
                        .txData =
                        {
                                0u,//ComMaster_TxSignal_RecirculationRequest
                                0u,//ComMaster_TxSignal_FogLights
                                0u,//ComMaster_TxSignal_HighBeam
                                0u,//ComMaster_TxSignal_StatusOutTemp
                                0u,//ComMaster_TxSignal_TurnSignals
                                0u//ComMaster_TxSignal_AutoClimateRequest
                        }
                },
                .transmitFlag = 1u,
                .cycleTime = 20u,
        },
        /* Status Body Control 2 */
        {
                .transmitMessage =
                {
                        .txMsg =
                        {
                                .bufferNumber = 2u,
                                .messageId = 0x99u,
                                .remoteTransmitRequest = 0u,
                                .messageIdLength = IfxCan_MessageIdLength_standard,
                                .errorStateIndicator = 0u,
                                .dataLengthCode = 5u,
                                .frameMode = IfxCan_FrameMode_standard,
                                .txEventFifoControl = FALSE,
                                .storeInTxFifoQueue = FALSE,
                                .readFromRxFifo0 = FALSE,
                                .readFromRxFifo1 = FALSE
                        },
                        .txData =
                        {
                                0u,//ComMaster_TxSignal_FanValueRequest
                                0u,//ComMaster_TxSignal_DisplayModeRequest
                                0u,//ComMaster_TxSignal_ClimaTempRequest
                                0u,//ComMaster_TxSignal_RlsRequest
                                0u//ComMaster_TxSignal_WiperStockRequest
                        }
                },
                .transmitFlag = 1u,
                .cycleTime = 20u,
        },
        /* Info Cluster Message */
        {
                .transmitMessage =
                {
                        .txMsg =
                        {
                                .bufferNumber = 3u,
                                .messageId = 0x10Bu,
                                .remoteTransmitRequest = 0u,
                                .messageIdLength = IfxCan_MessageIdLength_standard,
                                .errorStateIndicator = 0u,
                                .dataLengthCode = 5u,
                                .frameMode = IfxCan_FrameMode_standard,
                                .txEventFifoControl = FALSE,
                                .storeInTxFifoQueue = FALSE,
                                .readFromRxFifo0 = FALSE,
                                .readFromRxFifo1 = FALSE
                        },
                        .txData = {0U/*ComMaster_TxSignal_ICM_ID*/}
                },
                .transmitFlag = 1u,
                .cycleTime = 0u,
        },
        /* CommandLoad */
        {
                .transmitMessage =
                {
                        .txMsg =
                        {
                                .bufferNumber = 4u,
                                .messageId = 0x10Eu,
                                .remoteTransmitRequest = 0u,
                                .messageIdLength = IfxCan_MessageIdLength_standard,
                                .errorStateIndicator = 0u,
                                .dataLengthCode = 8u,
                                .frameMode = IfxCan_FrameMode_standard,
                                .txEventFifoControl = FALSE,
                                .storeInTxFifoQueue = FALSE,
                                .readFromRxFifo0 = FALSE,
                                .readFromRxFifo1 = FALSE
                        },
                        .txData =
                        {
                                0U,//ComMaster_TxSignal_CommandLoad1
                                0U,//ComMaster_TxSignal_CommandLoad2
                                0U,//ComMaster_TxSignal_CommandLoad3
                                0U,//ComMaster_TxSignal_CommandLoad4
                                0U,//ComMaster_TxSignal_CommandLoad5
                                0U,//ComMaster_TxSignal_CommandLoad6
                                0U,//ComMaster_TxSignal_CommandLoad7
                                0U//ComMaster_TxSignal_CommandLoad8
                        }
                },
                .transmitFlag = 1u,
                .cycleTime = 200u,
        },
        /* DataRecorder */
        {
                .transmitMessage =
                {
                        .txMsg =
                        {
                                .bufferNumber = 5u,
                                .messageId = 0x10Eu,
                                .remoteTransmitRequest = 0u,
                                .messageIdLength = IfxCan_MessageIdLength_standard,
                                .errorStateIndicator = 0u,
                                .dataLengthCode = 8u,
                                .frameMode = IfxCan_FrameMode_standard,
                                .txEventFifoControl = FALSE,
                                .storeInTxFifoQueue = FALSE,
                                .readFromRxFifo0 = FALSE,
                                .readFromRxFifo1 = FALSE
                        },
                        .txData =
                        {
                                0U,//ComMaster_TxSignal_DcyStatus
                                0U//ComMaster_TxSignal_VBat
                        }
                },
                .transmitFlag = 1u,
                .cycleTime = 200u,
        },
        /* Networkmanagement3 */
        {
                .transmitMessage =
                {
                        .txMsg =
                        {
                                .bufferNumber = 6u,
                                .messageId = 0x510u,
                                .remoteTransmitRequest = 0u,
                                .messageIdLength = IfxCan_MessageIdLength_standard,
                                .errorStateIndicator = 0u,
                                .dataLengthCode = 5u,
                                .frameMode = IfxCan_FrameMode_standard,
                                .txEventFifoControl = FALSE,
                                .storeInTxFifoQueue = FALSE,
                                .readFromRxFifo0 = FALSE,
                                .readFromRxFifo1 = FALSE
                        },
                        .txData =
                        {
                                0U,//ComMaster_TxSignal_NM3
                                0U,//ComMaster_TxSignal_NM3_PN1
                                0U//ComMaster_TxSignal_NM3_PN1
                        }
                },
                .transmitFlag = 1u,
                .cycleTime = 20u,
        }
};
ComMaster_ReceiveType_t ComMaster_ReceiveTable[9u] =
{
        /* Status Drive Control */
        {
                .receiveMessage =
                {
                        .rxMsg =
                        {
                                .bufferNumber = 0u,
                                .messageId = 0x100u,
                                .remoteTransmitRequest = FALSE,
                                .messageIdLength = IfxCan_MessageIdLength_standard,
                                .errorStateIndicator = FALSE,
                                .dataLengthCode = 5u,
                                .frameMode = IfxCan_FrameMode_standard,
                                .txEventFifoControl = FALSE,
                                .storeInTxFifoQueue = FALSE,
                                .readFromRxFifo0 = FALSE,
                                .readFromRxFifo1 = FALSE
                        },
                        .rxData = {0u}
                },
                .receivedValidFlag = 0u
        },
        /* Status Actuator */
        {
                .receiveMessage =
                {
                        .rxMsg =
                        {
                                .bufferNumber = 1u,
                                .messageId = 0x101u,
                                .remoteTransmitRequest = FALSE,
                                .messageIdLength = IfxCan_MessageIdLength_standard,
                                .errorStateIndicator = FALSE,
                                .dataLengthCode = 3u,
                                .frameMode = IfxCan_FrameMode_standard,
                                .txEventFifoControl = FALSE,
                                .storeInTxFifoQueue = FALSE,
                                .readFromRxFifo0 = FALSE,
                                .readFromRxFifo1 = FALSE
                        },
                        .rxData = {0u}
                },
                .receivedValidFlag = 0u
        },
        /* Status Load List */
        {
                .receiveMessage =
                {
                        .rxMsg =
                        {
                                .bufferNumber = 2u,
                                .messageId = 0x103u,
                                .remoteTransmitRequest = FALSE,
                                .messageIdLength = IfxCan_MessageIdLength_standard,
                                .errorStateIndicator = FALSE,
                                .dataLengthCode = 8u,
                                .frameMode = IfxCan_FrameMode_standard,
                                .txEventFifoControl = FALSE,
                                .storeInTxFifoQueue = FALSE,
                                .readFromRxFifo0 = FALSE,
                                .readFromRxFifo1 = FALSE
                        },
                        .rxData = {0u}
                },
                .receivedValidFlag = 0u
        },
        /* Status Power Supply Network */
        {
                .receiveMessage =
                {
                        .rxMsg =
                        {
                                .bufferNumber = 3u,
                                .messageId = 0x104u,
                                .remoteTransmitRequest = FALSE,
                                .messageIdLength = IfxCan_MessageIdLength_standard,
                                .errorStateIndicator = FALSE,
                                .dataLengthCode = 1u,
                                .frameMode = IfxCan_FrameMode_standard,
                                .txEventFifoControl = FALSE,
                                .storeInTxFifoQueue = FALSE,
                                .readFromRxFifo0 = FALSE,
                                .readFromRxFifo1 = FALSE
                        },
                        .rxData = {0u}
                },
                .receivedValidFlag = 0u
        },
        /* Status Voltage Current */
        {
                .receiveMessage =
                {
                        .rxMsg =
                        {
                                .bufferNumber = 4u,
                                .messageId = 0x107u,
                                .remoteTransmitRequest = FALSE,
                                .messageIdLength = IfxCan_MessageIdLength_standard,
                                .errorStateIndicator = FALSE,
                                .dataLengthCode = 3u,
                                .frameMode = IfxCan_FrameMode_standard,
                                .txEventFifoControl = FALSE,
                                .storeInTxFifoQueue = FALSE,
                                .readFromRxFifo0 = FALSE,
                                .readFromRxFifo1 = FALSE
                        },
                        .rxData = {0u}
                },
                .receivedValidFlag = 0u
        },
        /* Light Status */
        {
                .receiveMessage =
                {
                        .rxMsg =
                        {
                                .bufferNumber = 5u,
                                .messageId = 0x108u,
                                .remoteTransmitRequest = FALSE,
                                .messageIdLength = IfxCan_MessageIdLength_standard,
                                .errorStateIndicator = FALSE,
                                .dataLengthCode = 3u,
                                .frameMode = IfxCan_FrameMode_standard,
                                .txEventFifoControl = FALSE,
                                .storeInTxFifoQueue = FALSE,
                                .readFromRxFifo0 = FALSE,
                                .readFromRxFifo1 = FALSE
                        },
                        .rxData = {0u}
                },
                .receivedValidFlag = 0u
        },
        /* ClimateWiperControl */
        {
                .receiveMessage =
                {
                        .rxMsg =
                        {
                                .bufferNumber = 6u,
                                .messageId = 0x10Au,
                                .remoteTransmitRequest = FALSE,
                                .messageIdLength = IfxCan_MessageIdLength_standard,
                                .errorStateIndicator = FALSE,
                                .dataLengthCode = 8u,
                                .frameMode = IfxCan_FrameMode_standard,
                                .txEventFifoControl = FALSE,
                                .storeInTxFifoQueue = FALSE,
                                .readFromRxFifo0 = FALSE,
                                .readFromRxFifo1 = FALSE
                        },
                        .rxData = {0u}
                },
                .receivedValidFlag = 0u
        },
        /* StatusErrorSetting_701 */
        {
                .receiveMessage =
                {
                        .rxMsg =
                        {
                                .bufferNumber = 7u,
                                .messageId = 0x10Cu,
                                .remoteTransmitRequest = FALSE,
                                .messageIdLength = IfxCan_MessageIdLength_standard,
                                .errorStateIndicator = FALSE,
                                .dataLengthCode = 1u,
                                .frameMode = IfxCan_FrameMode_standard,
                                .txEventFifoControl = FALSE,
                                .storeInTxFifoQueue = FALSE,
                                .readFromRxFifo0 = FALSE,
                                .readFromRxFifo1 = FALSE
                        },
                        .rxData = {0u}
                },
                .receivedValidFlag = 0u
        },
        /* StatusErrorSetting_705 */
        {
                .receiveMessage =
                {
                        .rxMsg =
                        {
                                .bufferNumber = 7u,
                                .messageId = 0x10Du,
                                .remoteTransmitRequest = FALSE,
                                .messageIdLength = IfxCan_MessageIdLength_standard,
                                .errorStateIndicator = FALSE,
                                .dataLengthCode = 1u,
                                .frameMode = IfxCan_FrameMode_standard,
                                .txEventFifoControl = FALSE,
                                .storeInTxFifoQueue = FALSE,
                                .readFromRxFifo0 = FALSE,
                                .readFromRxFifo1 = FALSE
                        },
                        .rxData = {0u}
                },
                .receivedValidFlag = 0u
        }
};
uint8 ComMaster_RxSignal_AutoClimate = 255u;
uint8 ComMaster_RxSignal_ClimateTemperature = 255u;
uint8 ComMaster_RxSignal_DisplayMode = 255u;
uint8 ComMaster_RxSignal_Err701_ID = 255u;
uint8 ComMaster_RxSignal_Err705_ID = 255u;
uint8 ComMaster_RxSignal_FanValue = 255u;
uint8 ComMaster_RxSignal_LoadStatus1 = 255u;
uint8 ComMaster_RxSignal_LoadStatus2 = 255u;
uint8 ComMaster_RxSignal_LoadStatus3 = 255u;
uint8 ComMaster_RxSignal_LoadStatus4 = 255u;
uint8 ComMaster_RxSignal_LoadStatus5 = 255u;
uint8 ComMaster_RxSignal_LoadStatus6 = 255u;
uint8 ComMaster_RxSignal_LoadStatus7 = 255u;
uint8 ComMaster_RxSignal_LoadStatus8 = 255u;
uint8 ComMaster_RxSignal_MeasuredVoltageSupply = 255u;
uint8 ComMaster_RxSignal_PSNWarn = 255u;
uint8 ComMaster_RxSignal_Recirculation = 255u;
uint8 ComMaster_RxSignal_RotaryLightSwitch = 255u;
uint8 ComMaster_RxSignal_StatusAcc = 255u;
uint8 ComMaster_RxSignal_StatusBr = 255u;
uint8 ComMaster_RxSignal_StatusIgn = 255u;
uint8 ComMaster_RxSignal_StatusGb = 255u;
uint8 ComMaster_RxSignal_StatusPs = 255u;
uint8 ComMaster_RxSignal_StatusDoorLeft = 255u;
uint8 ComMaster_RxSignal_StatusDoorRight = 255u;
uint8 ComMaster_RxSignal_StatusHighBeam = 255u;
uint8 ComMaster_RxSignal_StatusFogLights = 255u;
uint8 ComMaster_RxSignal_WiperStock = 255u;
uint8 ComMaster_RxSignal_OutsideTemperature = 255u;
uint8 ComMaster_RxSignal_TurnSignals = 255u;
uint8 ComMaster_RxSignal_TotalCurrentConsumption = 255u;
uint8 ComMaster_RxSignal_TotalCurrentConsumption2 = 255u;
uint8 ComMaster_RxSignal_StatusHc05 = 255u;
uint8 ComMaster_TxSignal_AutoClimateRequest = 255u;
uint8 ComMaster_TxSignal_ClimaTempRequest = 255u;
uint8 ComMaster_TxSignal_CommandLoad1 = 255u;
uint8 ComMaster_TxSignal_CommandLoad2 = 255u;
uint8 ComMaster_TxSignal_CommandLoad3 = 255u;
uint8 ComMaster_TxSignal_CommandLoad4 = 255u;
uint8 ComMaster_TxSignal_CommandLoad5 = 255u;
uint8 ComMaster_TxSignal_CommandLoad6 = 255u;
uint8 ComMaster_TxSignal_CommandLoad7 = 255u;
uint8 ComMaster_TxSignal_CommandLoad8 = 255u;
uint8 ComMaster_TxSignal_DcyStatus = 255u;
uint8 ComMaster_TxSignal_DisplayModeRequest = 255u;
uint8 ComMaster_TxSignal_FanValueRequest = 255u;
uint8 ComMaster_TxSignal_FogLights = 255u;
uint8 ComMaster_TxSignal_Gear = 255u;
uint8 ComMaster_TxSignal_HighBeam = 255u;
uint8 ComMaster_TxSignal_ICM_ID = 255u;
uint8 ComMaster_TxSignal_Ignition = 255u;
uint8 ComMaster_TxSignal_IrSenStat = 255u;
uint8 ComMaster_TxSignal_NM3 = 255u;
uint8 ComMaster_TxSignal_NM3_PN1 = 255u;
uint8 ComMaster_TxSignal_NM3_PN2 = 255u;
uint8 ComMaster_TxSignal_StatusOutTemp = 255u;
uint8 ComMaster_TxSignal_PowerSteeringAngle = 255u;
uint8 ComMaster_TxSignal_RecirculationRequest = 255u;
uint8 ComMaster_TxSignal_RlsRequest = 255u;
uint8 ComMaster_TxSignal_Rpm = 255u;
uint8 ComMaster_TxSignal_Speed = 255u;
uint8 ComMaster_TxSignal_TurnSignals = 255u;
uint8 ComMaster_TxSignal_VBat = 255u;
uint8 ComMaster_TxSignal_WiperStockRequest = 255u;
uint8 ComMaster_TxSignal_VehicleStatus = 255u;
uint8 ComMaster_ActivityOnTheBus = 0u;
uint8 ComMaster_SwitchTxOff = 1u;
static uint32 ComMaster_MainCounter = 0u;

void ComMaster_MainFunction(void);
void ComMaster_E2e_UpdateTx(McmcanType *message, uint8 sequenceCounter);
uint8 ComMaster_E2e_CheckRx(McmcanType *message, uint8 sequenceCounter);

void ComMaster_MainFunction(void)
{
    static uint32 timestampIgnition = 0u;
    static uint32 timestampIgnValid = 0u;
    static uint32 timestampSwitchOffNm3s = 0u;
    static uint32 timestampActivityOnTheBus = 0u;
    static uint8 pComMaster_RxSignal_StatusAcc = 0u;
    static uint8 pComMaster_RxSignal_StatusBr = 0u;
    static uint8 pComMaster_RxSignal_StatusIgn = 0u;
    static uint8 pComMaster_RxSignal_StatusGb = 0u;
    static uint8 pComMaster_RxSignal_StatusPs = 0u;

    if(0u == ComMaster_MainCounter)
    {
        IfxPort_setPinMode(WUP_DMU, IfxPort_Mode_outputPushPullGeneral);
        IfxPort_setPinMode(WUP_PDM, IfxPort_Mode_outputPushPullGeneral);
    }
    else
    {
        /* Do nothing. */
    }

    if(CAN_PROCESS_RXTX == Can_State)
    {
        for(uint8 i = 0; i < 9u; i ++)
        {
            if(0u == ComMaster_ReceiveTable[i].receiveMessage.rxMsg.errorStateIndicator)
            {
                switch(ComMaster_ReceiveTable[i].receiveMessage.rxMsg.messageId)
                {
                    case 0x100u:
                        ComMaster_RxSignal_StatusAcc =  (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[0];
                        ComMaster_RxSignal_StatusBr = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[1];
                        ComMaster_RxSignal_StatusGb = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[2];
                        ComMaster_RxSignal_StatusIgn = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[3];
                        ComMaster_RxSignal_StatusPs = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[4];
                        break;
                    case 0x101u:
                        ComMaster_RxSignal_StatusDoorLeft = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[0];
                        ComMaster_RxSignal_StatusDoorRight = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[1];
                        ComMaster_RxSignal_StatusHc05 = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[2];
                        break;
                    case 0x103u:
                        ComMaster_RxSignal_LoadStatus1 = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[0];
                        ComMaster_RxSignal_LoadStatus2 = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[1];
                        ComMaster_RxSignal_LoadStatus3 = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[2];
                        ComMaster_RxSignal_LoadStatus4 = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[3];
                        ComMaster_RxSignal_LoadStatus5 = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[4];
                        ComMaster_RxSignal_LoadStatus6 = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[5];
                        ComMaster_RxSignal_LoadStatus7 = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[6];
                        ComMaster_RxSignal_LoadStatus8 = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[7];
                        break;
                    case 0x104u:
                        ComMaster_RxSignal_PSNWarn = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[0];
                        break;
                    case 0x107u:
                        ComMaster_RxSignal_MeasuredVoltageSupply = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[0];
                        ComMaster_RxSignal_TotalCurrentConsumption2 = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[1];
                        ComMaster_RxSignal_TotalCurrentConsumption2 = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[2];
                        break;
                    case 0x108u:
                        ComMaster_RxSignal_StatusFogLights = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[0];
                        ComMaster_RxSignal_StatusHighBeam = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[1];
                        ComMaster_RxSignal_TurnSignals = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[2];
                        break;
                    case 0x10Au:
                        ComMaster_RxSignal_AutoClimate = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[0];
                        ComMaster_RxSignal_ClimateTemperature = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[1];
                        ComMaster_RxSignal_DisplayMode = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[2];
                        ComMaster_RxSignal_FanValue = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[3];
                        ComMaster_RxSignal_Recirculation = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[4];
                        ComMaster_RxSignal_RotaryLightSwitch = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[5];
                        ComMaster_RxSignal_WiperStock = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[6];
                        ComMaster_RxSignal_OutsideTemperature = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[7];
                        break;
                    case 0x10Cu:
                        ComMaster_RxSignal_Err701_ID = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[0];
                        break;
                    case 0x10Du:
                        ComMaster_RxSignal_Err705_ID = (uint8)ComMaster_ReceiveTable[i].receiveMessage.rxData[0];
                        break;
                    default:
                        ComMaster_ReceiveTable[i].receivedValidFlag = 0xFFU;
                        break;
                }
            }
            else
            {
                ComMaster_ReceiveTable[i].receivedValidFlag = 0xFFU;
            }
        }
    }
    else
    {
        /* Do nothing. */
    }

    if(1u < ComMaster_RxSignal_AutoClimate)
    {
        ComMaster_RxSignal_AutoClimate = 253u; // invalid value
        ComMaster_TxSignal_AutoClimateRequest = 0u; // default value
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_AUTOCLIMATE_INVALID, 1u, 9u);
    }
    else
    {
        ComMaster_TxSignal_AutoClimateRequest = ComMaster_RxSignal_AutoClimate;
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_AUTOCLIMATE_INVALID, 0u, 9u);
    }

    if(16u < ComMaster_RxSignal_ClimateTemperature)
    {
        ComMaster_RxSignal_ClimateTemperature = 253u; // invalid value
        ComMaster_TxSignal_ClimaTempRequest = 6u; // default value
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_CLIMATETEMPERATURE_INVALID, 1u, 10u);
    }
    else
    {
        ComMaster_TxSignal_ClimaTempRequest = ComMaster_RxSignal_ClimateTemperature;
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_CLIMATETEMPERATURE_INVALID, 0u, 10u);
    }

    if(3u < ComMaster_RxSignal_DisplayMode)
    {
        ComMaster_RxSignal_DisplayMode = 253u; // invalid value
        ComMaster_TxSignal_DisplayModeRequest = 0u; // default value
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_DISPLAYMODEREQUEST_INVALID, 1u, 11u);
    }
    else
    {
        ComMaster_TxSignal_DisplayModeRequest = ComMaster_RxSignal_DisplayMode;
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_DISPLAYMODEREQUEST_INVALID, 0u, 11u);
    }

    if(8u < ComMaster_RxSignal_FanValue)
    {
        ComMaster_RxSignal_FanValue = 253u; // invalid value
        ComMaster_TxSignal_FanValueRequest = 0u; // default value
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_FANVALUE_INVALID, 1u, 12u);
    }
    else
    {
        ComMaster_TxSignal_FanValueRequest = ComMaster_RxSignal_FanValue;
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_FANVALUE_INVALID, 0u, 12u);
    }

    if(1u < ComMaster_RxSignal_LoadStatus1)
    {
        ComMaster_RxSignal_LoadStatus1 = 253u; // invalid value
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_LOADSTATUS_INVALID, 1u, 13u);
    }
    else
    {
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_LOADSTATUS_INVALID, 0u, 13u);
    }

    if(1u < ComMaster_RxSignal_LoadStatus2)
    {
        ComMaster_RxSignal_LoadStatus2 = 253u; // invalid value
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_LOADSTATUS_INVALID, 1u, 13u);
    }
    else
    {
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_LOADSTATUS_INVALID, 0u, 13u);
    }

    if(1u < ComMaster_RxSignal_LoadStatus3)
    {
        ComMaster_RxSignal_LoadStatus3 = 253u; // invalid value
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_LOADSTATUS_INVALID, 1u, 13u);
    }
    else
    {
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_LOADSTATUS_INVALID, 0u, 13u);
    }

    if(1u < ComMaster_RxSignal_LoadStatus4)
    {
        ComMaster_RxSignal_LoadStatus4 = 253u; // invalid value
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_LOADSTATUS_INVALID, 1u, 13u);
    }
    else
    {
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_LOADSTATUS_INVALID, 0u, 13u);
    }

    if(1u < ComMaster_RxSignal_LoadStatus5)
    {
        ComMaster_RxSignal_LoadStatus5 = 253u; // invalid value
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_LOADSTATUS_INVALID, 1u, 13u);
    }
    else
    {
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_LOADSTATUS_INVALID, 0u, 13u);
    }

    if(1u < ComMaster_RxSignal_LoadStatus6)
    {
        ComMaster_RxSignal_LoadStatus6 = 253u; // invalid value
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_LOADSTATUS_INVALID, 1u, 13u);
    }
    else
    {
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_LOADSTATUS_INVALID, 0u, 13u);
    }

    if(1u < ComMaster_RxSignal_LoadStatus7)
    {
        ComMaster_RxSignal_LoadStatus7 = 253u; // invalid value
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_LOADSTATUS_INVALID, 1u, 13u);
    }
    else
    {
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_LOADSTATUS_INVALID, 0u, 13u);
    }

    if(1u < ComMaster_RxSignal_LoadStatus8)
    {
        ComMaster_RxSignal_LoadStatus8 = 253u; // invalid value
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_LOADSTATUS_INVALID, 1u, 13u);
    }
    else
    {
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_LOADSTATUS_INVALID, 0u, 13u);
    }

    if(22u > ComMaster_RxSignal_MeasuredVoltageSupply)
    {
        ComMaster_RxSignal_MeasuredVoltageSupply = 253u; // invalid value
        ComMaster_TxSignal_VBat = 253u; // default value
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_MEASUREDVOLTAGESUPPLY_INVALID, 1u, 14u);
    }
    else
    {
        ComMaster_TxSignal_VBat = ComMaster_RxSignal_MeasuredVoltageSupply;
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_MEASUREDVOLTAGESUPPLY_INVALID, 0u, 14u);
    }

    if(4u < ComMaster_RxSignal_PSNWarn)
    {
        ComMaster_RxSignal_PSNWarn = 253u; // invalid value
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_POWERSUPPLYNETWORKWARNING_INVALID, 1u, 15u);
    }
    else
    {
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_POWERSUPPLYNETWORKWARNING_INVALID, 0u, 15u);
    }

    if(3u < ComMaster_RxSignal_Recirculation)
    {
        ComMaster_RxSignal_Recirculation = 253u; // invalid value
        ComMaster_TxSignal_RecirculationRequest = 0u; // default value
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_RECIRCULATION_INVALID, 1u, 16u);
    }
    else
    {
        ComMaster_TxSignal_RecirculationRequest = ComMaster_RxSignal_Recirculation;
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_RECIRCULATION_INVALID, 0u, 16u);
    }

    if(3u < ComMaster_RxSignal_RotaryLightSwitch)
    {
        ComMaster_RxSignal_RotaryLightSwitch = 253u; // invalid value
        ComMaster_TxSignal_RlsRequest = 0u; // default value
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_ROTARYLIGHTSWITCH_INVALID, 1u, 17u);
    }
    else
    {
        ComMaster_TxSignal_RlsRequest = ComMaster_RxSignal_RotaryLightSwitch;
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_ROTARYLIGHTSWITCH_INVALID, 0u, 17u);
    }

    if(100u < ComMaster_RxSignal_StatusAcc)
    {
        ComMaster_RxSignal_StatusAcc = 253u;
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSACCELERATION_INVALID, 1u, 18u);
    }
    else
    {
        if((pComMaster_RxSignal_StatusAcc > ComMaster_RxSignal_StatusAcc) &&
                (ComMaster_RxSignal_StatusAcc != 253u))
        {
            if(50u < pComMaster_RxSignal_StatusAcc - ComMaster_RxSignal_StatusAcc)
            {
                ComMaster_RxSignal_StatusAcc = 253u;
                pComMaster_RxSignal_StatusAcc = 0u;
                Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSACCELERATION_INVALID, 1u, 18u);
            }
            else
            {
                /* Do nothing. */
            }
        }
        else if((pComMaster_RxSignal_StatusAcc < ComMaster_RxSignal_StatusAcc) &&
                (ComMaster_RxSignal_StatusAcc != 253u))
        {
            if(50u < ComMaster_RxSignal_StatusAcc - pComMaster_RxSignal_StatusAcc)
            {
                ComMaster_RxSignal_StatusAcc = 253u;
                pComMaster_RxSignal_StatusAcc = 0u;
                Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSACCELERATION_INVALID, 1u, 18u);
            }
            else
            {
                /* Do nothing. */
            }
        }
        else
        {
            Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSACCELERATION_INVALID, 0u, 18u);
        }

        if((pComMaster_RxSignal_StatusAcc != ComMaster_RxSignal_StatusAcc)  &&
                (ComMaster_RxSignal_StatusAcc != 253u))
        {
            pComMaster_RxSignal_StatusAcc = ComMaster_RxSignal_StatusAcc;
        }
        else
        {
            /* Do nothing. */
        }
    }

    if(100u < ComMaster_RxSignal_StatusBr)
    {
        ComMaster_RxSignal_StatusBr = 253u;
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSBRAKE_INVALID, 1u, 19u);
    }
    else
    {
        if((pComMaster_RxSignal_StatusBr > ComMaster_RxSignal_StatusBr) &&
                (ComMaster_RxSignal_StatusBr != 253u))
        {
            if(50u < pComMaster_RxSignal_StatusBr - ComMaster_RxSignal_StatusBr)
            {
                ComMaster_RxSignal_StatusBr = 253u;
                pComMaster_RxSignal_StatusBr = 0u;
                Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSBRAKE_INVALID, 1u, 19u);
            }
            else
            {
                /* Do nothing. */
            }
        }
        else if((pComMaster_RxSignal_StatusBr < ComMaster_RxSignal_StatusBr) &&
                (ComMaster_RxSignal_StatusBr != 253u))
        {
            if(50u < ComMaster_RxSignal_StatusBr - pComMaster_RxSignal_StatusBr)
            {
                ComMaster_RxSignal_StatusBr = 253u;
                pComMaster_RxSignal_StatusBr = 0u;
                Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSBRAKE_INVALID, 1u, 19u);
            }
            else
            {
                /* Do nothing. */
            }
        }
        else
        {
            Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSBRAKE_INVALID, 0u, 19u);
        }

        if((pComMaster_RxSignal_StatusBr != ComMaster_RxSignal_StatusBr)  &&
                (ComMaster_RxSignal_StatusBr != 253u))
        {
            pComMaster_RxSignal_StatusBr = ComMaster_RxSignal_StatusBr;
        }
        else
        {
            /* Do nothing. */
        }
    }

    if(3u < ComMaster_RxSignal_StatusGb)
    {
        ComMaster_RxSignal_StatusGb = 253u;
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSGEARBOX_INVALID, 1u, 22u);
    }
    else
    {
        if((pComMaster_RxSignal_StatusGb > ComMaster_RxSignal_StatusGb) &&
                (ComMaster_RxSignal_StatusGb != 253u))
        {
            if(3u < pComMaster_RxSignal_StatusGb - ComMaster_RxSignal_StatusGb)
            {
                ComMaster_RxSignal_StatusGb = 253u;
                pComMaster_RxSignal_StatusGb = 0u;
                Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSGEARBOX_INVALID, 1u, 22u);
            }
            else
            {
                /* Do nothing. */
            }
        }
        else if((pComMaster_RxSignal_StatusGb < ComMaster_RxSignal_StatusGb) &&
                (ComMaster_RxSignal_StatusGb != 253u))
        {
            if(3u < ComMaster_RxSignal_StatusBr - pComMaster_RxSignal_StatusGb)
            {
                ComMaster_RxSignal_StatusGb = 253u;
                pComMaster_RxSignal_StatusGb = 0u;
                Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSGEARBOX_INVALID, 1u, 22u);
            }
            else
            {
                /* Do nothing. */
            }
        }
        else
        {
            Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSGEARBOX_INVALID, 0u, 22u);
        }

        if((pComMaster_RxSignal_StatusGb != ComMaster_RxSignal_StatusGb)  &&
                (ComMaster_RxSignal_StatusGb != 253u))
        {
            pComMaster_RxSignal_StatusGb = ComMaster_RxSignal_StatusGb;
        }
        else
        {
            /* Do nothing. */
        }

        if(ComMaster_TxSignal_Ignition != 2u)
        {
            ComMaster_TxSignal_Gear = 0u;
        }
        else
        {
            ComMaster_TxSignal_Gear = ComMaster_RxSignal_StatusGb;
        }
    }

    if(180u < ComMaster_RxSignal_StatusPs)
    {
        ComMaster_RxSignal_StatusPs = 253u;
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSPOWERSTEERING_INVALID, 1u, 20u);
    }
    else
    {
        if((pComMaster_RxSignal_StatusPs > ComMaster_RxSignal_StatusPs) &&
                (ComMaster_RxSignal_StatusPs != 253u))
        {
            if(90u < pComMaster_RxSignal_StatusPs - ComMaster_RxSignal_StatusPs)
            {
                ComMaster_RxSignal_StatusPs = 253u;
                pComMaster_RxSignal_StatusGb = 0u;
                Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSPOWERSTEERING_INVALID, 1u, 20u);
            }
            else
            {
                /* Do nothing. */
            }
        }
        else if((pComMaster_RxSignal_StatusPs < ComMaster_RxSignal_StatusPs) &&
                (ComMaster_RxSignal_StatusPs != 253u))
        {
            if(90u < ComMaster_RxSignal_StatusPs - pComMaster_RxSignal_StatusPs)
            {
                ComMaster_RxSignal_StatusPs = 253u;
                pComMaster_RxSignal_StatusPs = 90u;
                Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSPOWERSTEERING_INVALID, 1u, 20u);
            }
            else
            {
                /* Do nothing. */
            }
        }
        else
        {
            Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSPOWERSTEERING_INVALID, 0u, 20u);
        }

        if((pComMaster_RxSignal_StatusPs != ComMaster_RxSignal_StatusPs)  &&
                (ComMaster_RxSignal_StatusPs != 253u))
        {
            pComMaster_RxSignal_StatusPs = ComMaster_RxSignal_StatusPs;
        }
        else
        {
            /* Do nothing. */
        }

        if(ComMaster_TxSignal_Ignition != 2u)
        {
            ComMaster_RxSignal_StatusPs = 0u;
        }
        else
        {
            ComMaster_TxSignal_Gear = ComMaster_RxSignal_StatusPs;
        }
    }

    if(4u < ComMaster_RxSignal_StatusDoorLeft)
    {
        ComMaster_RxSignal_StatusDoorLeft = 0u;
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSDOORLEFT_INVALID, 1u, 23u);
    }
    else
    {
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSDOORLEFT_INVALID, 0u, 23u);
    }

    if(4u < ComMaster_RxSignal_StatusDoorRight)
    {
        ComMaster_RxSignal_StatusDoorRight = 0u;
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSDOORRIGHT_INVALID, 1u, 24u);
    }
    else
    {
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSDOORRIGHT_INVALID, 0u, 24u);
    }

    if(4u < ComMaster_RxSignal_StatusHc05)
    {
        ComMaster_RxSignal_StatusHc05 = 0u;
    }
    else
    {
        /* Do nothing. */
    }

    if(1u < ComMaster_RxSignal_StatusHighBeam)
    {
        ComMaster_RxSignal_StatusHighBeam = 253u;
        ComMaster_TxSignal_HighBeam = 0u;
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSHIGHBEAM_INVALID, 1u, 25u);
    }
    else
    {
        ComMaster_TxSignal_HighBeam = ComMaster_RxSignal_StatusHighBeam;
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSHIGHBEAM_INVALID, 0u, 25u);
    }

    if(3u < ComMaster_RxSignal_StatusFogLights)
    {
        ComMaster_RxSignal_StatusFogLights = 253u;
        ComMaster_TxSignal_FogLights = 0u;
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSFOGLIGHTS_INVALID, 1u, 26u);
    }
    else
    {
        ComMaster_TxSignal_FogLights = ComMaster_RxSignal_StatusFogLights;
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSFOGLIGHTS_INVALID, 0u, 26u);
    }

    if(4u < ComMaster_RxSignal_WiperStock)
    {
        ComMaster_RxSignal_WiperStock = 253u;
        ComMaster_TxSignal_WiperStockRequest = 0u;
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSWIPERSTOCK_INVALID, 1u, 27u);
    }
    else
    {
        ComMaster_TxSignal_WiperStockRequest = ComMaster_RxSignal_WiperStock;
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSWIPERSTOCK_INVALID, 0u, 27u);
    }

    if(99u < ComMaster_RxSignal_OutsideTemperature)
    {
        ComMaster_RxSignal_OutsideTemperature = 253u;
        ComMaster_TxSignal_StatusOutTemp = 0u;
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSOUTSIDETEMPERATURE_INVALID, 1u, 28u);
    }
    else
    {
        ComMaster_TxSignal_StatusOutTemp = ComMaster_RxSignal_OutsideTemperature;
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSOUTSIDETEMPERATURE_INVALID, 0u, 28u);
    }

    if(3u < ComMaster_RxSignal_TurnSignals)
    {
        ComMaster_RxSignal_TurnSignals = 253u;
        ComMaster_TxSignal_TurnSignals = 0u;
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSTURNSIGNALS_INVALID, 1u, 29u);
    }
    else
    {
        ComMaster_TxSignal_TurnSignals = ComMaster_RxSignal_TurnSignals;
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSTURNSIGNALS_INVALID, 0u, 29u);
    }

    if(2u < ComMaster_RxSignal_StatusIgn)
    {
        ComMaster_RxSignal_StatusIgn = 253u;
        Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSIGNITION_INVALID, 1u, 21u);

        ComMaster_TxSignal_Ignition = 1u;

        if(0u == timestampIgnition)
        {
            timestampIgnition = ComMaster_MainCounter;
        }
        else
        {
            /* Do nothing. */
        }

        if((((EncCal_Coding_ConsumerCutoffTime * 60u * 1000u) / 5u) < (ComMaster_MainCounter - timestampIgnition)) ||
                (((0u == ComMaster_RxSignal_StatusDoorLeft) || (0u == ComMaster_RxSignal_StatusDoorRight)) &&
                        (0u == ComMaster_RxSignal_StatusHc05)))
        {
            ComMaster_TxSignal_Ignition = 0u;
        }
        else
        {
            /* Do nothing. */
        }
    }
    else
    {
        if((pComMaster_RxSignal_StatusIgn > ComMaster_RxSignal_StatusIgn) &&
                (ComMaster_TxSignal_Ignition != 253u))
        {
            if(2u == (pComMaster_RxSignal_StatusIgn - ComMaster_RxSignal_StatusIgn))
            {
                ComMaster_RxSignal_StatusIgn = 253u;
                pComMaster_RxSignal_StatusIgn = 1u;
                ComMaster_TxSignal_Ignition = 1u;
                Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSIGNITION_INVALID, 1u, 21u);
            }
            else
            {
                /* Do nothing. */
            }
        }
        else if((pComMaster_RxSignal_StatusIgn < ComMaster_RxSignal_StatusIgn) &&
                (ComMaster_TxSignal_Ignition != 253u))
        {
            if(2u == (ComMaster_RxSignal_StatusIgn - pComMaster_RxSignal_StatusIgn))
            {
                ComMaster_RxSignal_StatusIgn = 253u;
                pComMaster_RxSignal_StatusIgn = 1u;
                ComMaster_TxSignal_Ignition = 1u;
                Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSIGNITION_INVALID, 1u, 21u);
            }
            else
            {
                /* Do nothing. */
            }
        }
        else
        {
            Dem_SetDtc(COMMASTER_DTC_ID_SIGNAL_STATUSIGNITION_INVALID, 0u, 21u);
        }

        if(pComMaster_RxSignal_StatusIgn != ComMaster_RxSignal_StatusIgn &&
                253u != ComMaster_RxSignal_StatusIgn)
        {
            pComMaster_RxSignal_StatusIgn = ComMaster_RxSignal_StatusIgn;
        }
        else
        {
            /* Do nothing. */
        }

        if((2u == pComMaster_RxSignal_StatusIgn) && (2u > ComMaster_RxSignal_StatusIgn))
        {
            ComMaster_TxSignal_Ignition = 3u;

            if(0u == timestampIgnValid)
            {
                timestampIgnValid = ComMaster_MainCounter;
            }
            else
            {
                /* Do nothing. */
            }
        }
        else
        {
            ComMaster_TxSignal_Ignition = ComMaster_RxSignal_StatusIgn;
        }

        if(3u == ComMaster_TxSignal_Ignition)
        {
            if((((EncCal_Coding_ConsumerCutoffTime * 60u * 1000u) / 5u) < (ComMaster_MainCounter - timestampIgnValid)) ||
                    (((0u == ComMaster_RxSignal_StatusDoorLeft) || (0u == ComMaster_RxSignal_StatusDoorRight)) &&
                            (0u == ComMaster_RxSignal_StatusHc05)))
            {
                ComMaster_TxSignal_Ignition = 0u;
            }
            else
            {
                /* Do nothing. */
            }
        }
        else
        {
            timestampIgnValid = 0u;
        }

        timestampIgnition = 0u;
    }

    switch(ComMaster_TxSignal_Ignition)
    {
        case 3u:
            ComMaster_TxSignal_NM3 = 0x10u;
            ComMaster_TxSignal_NM3_PN1 = 0x11u;
            ComMaster_TxSignal_NM3_PN2 = 0x12u;
            IfxPort_setPinState(WUP_DMU, IfxPort_State_high);
            IfxPort_setPinState(WUP_PDM, IfxPort_State_high);
            timestampSwitchOffNm3s = 0u;
            break;
        case 2u:
            ComMaster_TxSignal_NM3 = 0x10u;
            ComMaster_TxSignal_NM3_PN1 = 0x11u;
            ComMaster_TxSignal_NM3_PN2 = 0x12u;
            IfxPort_setPinState(WUP_DMU, IfxPort_State_high);
            IfxPort_setPinState(WUP_PDM, IfxPort_State_high);
            timestampSwitchOffNm3s = 0u;
            break;
        case 1u:
            ComMaster_TxSignal_NM3 = 0x10u;
            ComMaster_TxSignal_NM3_PN1 = 0x11u;
            ComMaster_TxSignal_NM3_PN2 = 0x12u;
            IfxPort_setPinState(WUP_DMU, IfxPort_State_high);
            IfxPort_setPinState(WUP_PDM, IfxPort_State_high);
            timestampSwitchOffNm3s = 0u;
            break;
        case 0u:
            ComMaster_TxSignal_NM3 = 0x10u;
            ComMaster_TxSignal_NM3_PN1 = 0x11u;
            ComMaster_TxSignal_NM3_PN2 = 0x00u;
            IfxPort_setPinState(WUP_DMU, IfxPort_State_low);

            if((((EncCal_Coding_ConsumerCutoffTime * 60u * 1000u) / 5u) < (ComMaster_MainCounter - timestampIgnValid)) ||
                    (((0u == ComMaster_RxSignal_StatusDoorLeft) || (0u == ComMaster_RxSignal_StatusDoorRight)) &&
                            (0u == ComMaster_RxSignal_StatusHc05)))
            {
                ComMaster_TxSignal_NM3_PN1 = 0x00u;

                if(0u == timestampSwitchOffNm3s)
                {
                    timestampSwitchOffNm3s = ComMaster_MainCounter;
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

            if(2000u < ComMaster_MainCounter - timestampSwitchOffNm3s)
            {
                IfxPort_setPinState(WUP_PDM, IfxPort_State_low);
                ComMaster_TxSignal_NM3 = 0x00u;
            }
            else
            {
                /* Do nothing. */
            }

            break;
        default:
            break;
    }

    ComMaster_TransmitTable[0u].transmitMessage.txData[0] = ComMaster_TxSignal_Gear;
    ComMaster_TransmitTable[0u].transmitMessage.txData[1] = ComMaster_TxSignal_Ignition;
    ComMaster_TransmitTable[0u].transmitMessage.txData[2] = ComMaster_TxSignal_IrSenStat;
    ComMaster_TransmitTable[0u].transmitMessage.txData[3] = ComMaster_TxSignal_PowerSteeringAngle;
    ComMaster_TransmitTable[0u].transmitMessage.txData[4] = ComMaster_TxSignal_Rpm;
    ComMaster_TransmitTable[0u].transmitMessage.txData[5] = ComMaster_TxSignal_Speed;
    ComMaster_TransmitTable[0u].transmitMessage.txData[6] = ComMaster_TxSignal_VehicleStatus;

    ComMaster_TransmitTable[1u].transmitMessage.txData[0] = ComMaster_TxSignal_RecirculationRequest;
    ComMaster_TransmitTable[1u].transmitMessage.txData[1] = ComMaster_TxSignal_FogLights;
    ComMaster_TransmitTable[1u].transmitMessage.txData[2] = ComMaster_TxSignal_HighBeam;
    ComMaster_TransmitTable[1u].transmitMessage.txData[3] = ComMaster_TxSignal_StatusOutTemp;
    ComMaster_TransmitTable[1u].transmitMessage.txData[4] = ComMaster_TxSignal_TurnSignals;
    ComMaster_TransmitTable[1u].transmitMessage.txData[5] = ComMaster_TxSignal_AutoClimateRequest;

    ComMaster_TransmitTable[2u].transmitMessage.txData[0] = ComMaster_TxSignal_FanValueRequest;
    ComMaster_TransmitTable[2u].transmitMessage.txData[1] = ComMaster_TxSignal_DisplayModeRequest;
    ComMaster_TransmitTable[2u].transmitMessage.txData[2] = ComMaster_TxSignal_ClimaTempRequest;
    ComMaster_TransmitTable[2u].transmitMessage.txData[3] = ComMaster_TxSignal_RlsRequest;
    ComMaster_TransmitTable[2u].transmitMessage.txData[4] = ComMaster_TxSignal_WiperStockRequest;

    if(0u != ComMaster_TxSignal_ICM_ID)
    {
        ComMaster_TransmitTable[3u].transmitMessage.txData[0] = ComMaster_TxSignal_ICM_ID;
    }
    else
    {
        /* Do nothing. */
    }

    ComMaster_TransmitTable[4u].transmitMessage.txData[0] = ComMaster_TxSignal_CommandLoad1;
    ComMaster_TransmitTable[4u].transmitMessage.txData[1] = ComMaster_TxSignal_CommandLoad2;
    ComMaster_TransmitTable[4u].transmitMessage.txData[2] = ComMaster_TxSignal_CommandLoad3;
    ComMaster_TransmitTable[4u].transmitMessage.txData[3] = ComMaster_TxSignal_CommandLoad4;
    ComMaster_TransmitTable[4u].transmitMessage.txData[4] = ComMaster_TxSignal_CommandLoad5;
    ComMaster_TransmitTable[4u].transmitMessage.txData[5] = ComMaster_TxSignal_CommandLoad6;
    ComMaster_TransmitTable[4u].transmitMessage.txData[6] = ComMaster_TxSignal_CommandLoad7;
    ComMaster_TransmitTable[4u].transmitMessage.txData[7] = ComMaster_TxSignal_CommandLoad8;

    ComMaster_TransmitTable[5u].transmitMessage.txData[0] = ComMaster_TxSignal_DcyStatus;
    ComMaster_TransmitTable[5u].transmitMessage.txData[1] = ComMaster_TxSignal_VBat;

    ComMaster_TransmitTable[6u].transmitMessage.txData[0] = ComMaster_TxSignal_NM3;
    ComMaster_TransmitTable[6u].transmitMessage.txData[1] = ComMaster_TxSignal_NM3_PN1;
    ComMaster_TransmitTable[6u].transmitMessage.txData[2] = ComMaster_TxSignal_NM3_PN2;

    if((ComMaster_MainCounter) != 0u && (ComMaster_SwitchTxOff == 1u))
    {
        if(ComMaster_MainCounter % ComMaster_TransmitTable[0u].cycleTime == 0u)
        {
            ComMaster_TransmitTable[0u].transmitFlag = 1u;
        }
        else
        {
            /* Do nothing. */
        }

        if(ComMaster_MainCounter % ComMaster_TransmitTable[4u].cycleTime == 0u)
        {
            ComMaster_TransmitTable[4u].transmitFlag = 1u;
        }
        else
        {
            /* Do nothing. */
        }

        if(ComMaster_MainCounter % ComMaster_TransmitTable[6u].cycleTime == 0u)
        {
            ComMaster_TransmitTable[6u].transmitFlag = 1u;
        }
        else
        {
            /* Do nothing. */
        }

        if(0u < ComMaster_TxSignal_Ignition)
        {
            if(ComMaster_MainCounter % ComMaster_TransmitTable[1u].cycleTime == 0u)
            {
                ComMaster_TransmitTable[1u].transmitFlag = 1u;
            }
            else
            {
                /* Do nothing. */
            }

            if(ComMaster_MainCounter % ComMaster_TransmitTable[2u].cycleTime == 0u)
            {
                ComMaster_TransmitTable[2u].transmitFlag = 1u;
            }
            else
            {
                /* Do nothing. */
            }

            if(ComMaster_MainCounter % ComMaster_TransmitTable[3u].cycleTime == 0u)
            {
                ComMaster_TransmitTable[3u].transmitFlag = 1u;
            }
            else
            {
                /* Do nothing. */
            }

            if(ComMaster_MainCounter % ComMaster_TransmitTable[5u].cycleTime == 0u)
            {
                ComMaster_TransmitTable[5u].transmitFlag = 1u;
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

    if(0u == ComMaster_TxSignal_NM3)
    {
        timestampActivityOnTheBus = ComMaster_MainCounter;
        Can_ActivityOnTheBus = 0u;

        if(12000u < (ComMaster_MainCounter - timestampActivityOnTheBus))
        {
            ComMaster_SwitchTxOff = 0u;
            ComMaster_ActivityOnTheBus = 0u;

        }
        else
        {
            /* Do nothing. */
        }
    }
    else
    {
        ComMaster_ActivityOnTheBus = Can_ActivityOnTheBus;
        ComMaster_SwitchTxOff = 1u;
    }

    if(Can_ActivityOnTheBus == 1u)
    {
        ComMaster_TxSignal_NM3 = 0x10u;
        ComMaster_SwitchTxOff = 1u;
        ComMaster_ActivityOnTheBus = Can_ActivityOnTheBus;
    }
    else
    {
        /* Do nothing. */
    }

    SysMgr_NoBusActivity = ComMaster_ActivityOnTheBus;

    ComMaster_MainCounter++;
}

void ComMaster_E2e_UpdateTx(McmcanType *message, uint8 sequenceCounter)
{
    uint8 calculatedCrc = 0u;

    message->txData[0u] = sequenceCounter;
    calculatedCrc = (uint8)Crc_CalculateFCECRC((uint32*) message->txData, 2u, 0u);
    message->txData[1u] = calculatedCrc;
}

uint8 ComMaster_E2e_CheckRx(McmcanType *message, uint8 sequenceCounter)
{
    uint8 receivedCrc = 0u;
    uint8 seqCnt = 0u;
    uint8 calculatedCrc = 0u;
    uint8 retVal = 0u;

    receivedCrc = (uint8)message->rxData[1u];
    seqCnt = (uint8)message->rxData[0u];
    calculatedCrc = (uint8)Crc_CalculateFCECRC((uint32*)message->rxData, 2u, 0u);

    if (receivedCrc == calculatedCrc && seqCnt == sequenceCounter) retVal = 0u;
    else retVal = 1u;

    return retVal;
}
