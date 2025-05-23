#include <string.h>
#include "Ifx_Types.h"
#include "IfxFlash.h"
#include "IfxCpu.h"
#include "IfxCan_Can.h"
#include "IfxScuRcu.h"
#include "aurix_pin_mappings.h"

#define MAXIMUM_CAN_DATA_PAYLOAD    8u
#define IRQ_CANRX_CHANNEL           4U
#define IRQ_CANTX_CHANNEL           5U
#define SESSIONSTATUS_ADDR          0xb00000dcu
#define RSTCNT_ADDR                 0xb0000108u
#define APPL_START_ADDRESS          0xA0300000
#define PFLASH_PAGE_LENGTH          IFXFLASH_PFLASH_PAGE_LENGTH /* 0x20 = 32 Bytes (smallest unit that can be programmed in the Program Flash memory (PFLASH)) */
#define FLASH_MODULE                0u                           /* Macro to select the flash (PMU) module           */
#define PROGRAM_FLASH_0             IfxFlash_FlashType_P1       /* Define the Program Flash Bank to be used         */
#define PFLASH_NUM_SECTORS          32u                           /* Number of PFLASH sectors to be erased            */
/* Reserved space for erase and program routines in bytes */
#define ERASESECTOR_LEN             (110U)
#define WAITUNBUSY_LEN              (110U)
#define ENTERPAGEMODE_LEN           (110U)
#define LOADPAGE2X32_LEN            (110U)
#define WRITEPAGE_LEN               (110U)
#define ERASEPFLASH_LEN             (0x186U)
#define WRITEPFLASH_LEN             (0x228U)
/* Relocation address for the erase and program routines: Program Scratch-Pad SRAM (PSPR) of CPU0 */
#define RELOCATION_START_ADDR       (0x70100000U)
/* Definition of the addresses where to relocate the erase and program routines, given their reserved space */
#define ERASESECTOR_ADDR            (RELOCATION_START_ADDR)
#define WAITUNBUSY_ADDR             (ERASESECTOR_ADDR + ERASESECTOR_LEN)
#define ENTERPAGEMODE_ADDR          (WAITUNBUSY_ADDR + WAITUNBUSY_LEN)
#define LOAD2X32_ADDR               (ENTERPAGEMODE_ADDR + ENTERPAGEMODE_LEN)
#define WRITEPAGE_ADDR              (LOAD2X32_ADDR + LOADPAGE2X32_LEN)
#define ERASEPFLASH_ADDR            (WRITEPAGE_ADDR + WRITEPAGE_LEN)
#define WRITEPFLASH_ADDR            (ERASEPFLASH_ADDR + ERASEPFLASH_LEN)

typedef enum
{
    DEFAULT = 0U,
    EXTENDED = 1U,
    PROGRAMMING = 2U,
    HARDRESET = 5U,
    SOFTRESET = 6U,
    JUMPTOAPPL = 7U
}FBL_DSC_t;

typedef struct
{
        IfxCan_Can_Config canConfig;                            /* CAN module configuration structure                   */
        IfxCan_Can canModule;                                   /* CAN module handle                                    */
        IfxCan_Can_Node canSrcNode;                             /* CAN source node handle data structure                */
        IfxCan_Can_Node canDstNode;                             /* CAN destination node handle data structure           */
        IfxCan_Can_NodeConfig canNodeConfig;                    /* CAN node configuration structure                     */
        IfxCan_Filter canFilter;                                /* CAN filter configuration structure                   */
        IfxCan_Message txMsg;                                   /* Transmitted CAN message structure                    */
        IfxCan_Message rxMsg;                                   /* Received CAN message structure                       */
        uint8 txData[MAXIMUM_CAN_DATA_PAYLOAD];                 /* Transmitted CAN data array                           */
        uint8 rxData[MAXIMUM_CAN_DATA_PAYLOAD];                 /* Received CAN data array                              */
} McmcanType;

McmcanType g_mcmcan;
long long alive_counter = 0u;
uint32* FBL_DSC_Pointer = (uint32*)(SESSIONSTATUS_ADDR);
uint32* FBL_RSTCNT_Pointer = (uint32*)(RSTCNT_ADDR);
uint32 FBL_ProgrammingData = 0u;
uint32 FBL_ProgrammingIndex = 0u;
uint32 FBL_ProgrammingAddress = 0u;
uint32 ROM_APPL_START_ADDR_storedValue = 0u;
uint32 ROM_APPL_START_ADDR = APPL_START_ADDRESS;
uint32 FBL_DSC_Status = 0u;
uint32 globalData[8u];
uint8 accumulatedDataFlag;
uint8 globalCounter32bytes;
uint8 FBL_RxFrame[8u] = {0u};
uint8 FBL_TxFrame[8u] = {0u};
FBL_DSC_t FBL_DSC_State = JUMPTOAPPL;
volatile uint32 appEntryGlobal;
uint8 FBL_ResetCounter = 0u;

IFX_INTERRUPT(ISR_CanRx, 0u, 1u);
void Can_Init(void);
uint32 Can_Tx(McmcanType message);
void Can_Rx(void);
void FBL_JumpToAppl(void);
void FBL_DiagService_ER_SoftReset(void);
void FBL_DiagService_ER_HardReset(void);
void FBL_DiagService_DSC_Programming(void);
void FBL_DiagService_DSC_RequestDownload(void);
void FBL_DiagService_DSC_TransferData(void);
void FBL_DiagService_DSC_RequestTransferExit(void);
void FBL_DiagService_RAR_MassEraseAPPL(void);
void FBL_DiagService_RDBI_ReadActiveDiagnosticSession(void);
void FBL_CopyFunctionsToPSPR(void);
void erasePFLASH(uint32 sectorAddr);
void writePFLASH(uint32 startingAddr);

typedef struct
{
        void (*eraseSectors)(uint32 sectorAddr, uint32 numSector);
        uint8 (*waitUnbusy)(uint32 flash, IfxFlash_FlashType flashType);
        uint8 (*enterPageMode)(uint32 pageAddr);
        void (*load2X32bits)(uint32 pageAddr, uint32 wordL, uint32 wordU);
        void (*writePage)(uint32 pageAddr);
        void (*eraseFlash)(uint32 sectorAddr);
        void (*writeFlash)(uint32 startingAddr);
} Function;

Function g_commandFromPSPR;

void core0_main(void)
{
    IfxCpu_disableInterrupts();
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
    IfxScuWdt_disableSafetyWatchdog(IfxScuWdt_getSafetyWatchdogPassword());
    gpio_init_pins();
    can0_node0_init_pins();
    Can_Init();

    FBL_ProgrammingAddress = 0u;
    FBL_ProgrammingIndex = 0u;
    FBL_DSC_Pointer = (uint32*)(SESSIONSTATUS_ADDR);
    FBL_DSC_Status = *FBL_DSC_Pointer;
    FBL_RSTCNT_Pointer = (uint32*)(RSTCNT_ADDR);
    FBL_ResetCounter = (uint8)*FBL_RSTCNT_Pointer;

    if(50u == FBL_ResetCounter)
    {
        FBL_DSC_Status = PROGRAMMING;
    }
    else
    {
        /* Do nothing. */
    }

    FBL_CopyFunctionsToPSPR();
    IfxCpu_enableInterrupts();

    if((FBL_DSC_Status == PROGRAMMING) || (FBL_DSC_Status == SOFTRESET) || (FBL_DSC_Status == HARDRESET))
    {
        FBL_DSC_State = FBL_DSC_Status;

        if(FBL_DSC_Status == SOFTRESET)
        {
            FBL_DiagService_ER_SoftReset();
        }
        else if(FBL_DSC_Status == HARDRESET)
        {
            FBL_DiagService_ER_HardReset();
        }
        else
        {
            /* Do nothing. */
        }
    }
    else
    {
        FBL_JumpToAppl();
    }

    while(1){alive_counter++;}
}

void ISR_CanRx(void)
{
    Can_Rx();
}

void Can_Init(void)
{
    IfxScuWdt_clearCpuEndinit(IfxScuWdt_getCpuWatchdogPassword());
    IfxScuWdt_clearSafetyEndinit(IfxScuWdt_getSafetyWatchdogPassword());
    IfxPort_setPinModeOutput(&MODULE_P20, 6, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
    IfxPort_setPinLow(&MODULE_P20, 6);
    IfxCan_Can_initModuleConfig(&g_mcmcan.canConfig, &MODULE_CAN0);
    IfxCan_Can_initModule(&g_mcmcan.canModule, &g_mcmcan.canConfig);
    IfxCan_Can_initNodeConfig(&g_mcmcan.canNodeConfig, &g_mcmcan.canModule);
    IfxScuCcu_setMcanFrequency(40000000.0f);
    g_mcmcan.canNodeConfig.baudRate.baudrate = 500000u;
    g_mcmcan.canNodeConfig.baudRate.prescaler = 3u;
    g_mcmcan.canNodeConfig.baudRate.samplePoint = 8095;
    g_mcmcan.canNodeConfig.baudRate.syncJumpWidth = 0u;
    g_mcmcan.canNodeConfig.baudRate.timeSegment1 = 14u;
    g_mcmcan.canNodeConfig.baudRate.timeSegment2 = 3u;
    g_mcmcan.canNodeConfig.calculateBitTimingValues = FALSE;
    g_mcmcan.canNodeConfig.busLoopbackEnabled = FALSE;
    g_mcmcan.canNodeConfig.txConfig.txMode = IfxCan_TxMode_dedicatedBuffers;
    g_mcmcan.canNodeConfig.txConfig.dedicatedTxBuffersNumber = 1u;
    g_mcmcan.canNodeConfig.txConfig.txBufferDataFieldSize = IfxCan_DataFieldSize_8;
    g_mcmcan.canNodeConfig.frame.mode = IfxCan_FrameMode_standard;
    g_mcmcan.canNodeConfig.frame.type = IfxCan_FrameType_transmitAndReceive;
    g_mcmcan.canNodeConfig.nodeId = IfxCan_NodeId_0;
    g_mcmcan.canNodeConfig.rxConfig.rxMode = IfxCan_RxMode_dedicatedBuffers;
    g_mcmcan.canNodeConfig.rxConfig.rxBufferDataFieldSize = IfxCan_DataFieldSize_8;
    g_mcmcan.canNodeConfig.interruptConfig.messageStoredToDedicatedRxBufferEnabled = TRUE;
    g_mcmcan.canNodeConfig.interruptConfig.reint.priority = 1u;
    g_mcmcan.canNodeConfig.interruptConfig.reint.interruptLine = IfxCan_InterruptLine_0;
    g_mcmcan.canNodeConfig.interruptConfig.reint.typeOfService = IfxSrc_Tos_cpu0;
    g_mcmcan.canNodeConfig.messageRAM.baseAddress = (uint32)(g_mcmcan.canNodeConfig.can);
    g_mcmcan.canNodeConfig.messageRAM.standardFilterListStartAddress = 0x0u;
    g_mcmcan.canNodeConfig.messageRAM.extendedFilterListStartAddress = 0x0u;
    g_mcmcan.canNodeConfig.messageRAM.rxFifo0StartAddress = 0x0u;
    g_mcmcan.canNodeConfig.messageRAM.rxFifo1StartAddress = 0x0u;
    g_mcmcan.canNodeConfig.messageRAM.rxBuffersStartAddress = 0x120;
    g_mcmcan.canNodeConfig.messageRAM.txEventFifoStartAddress = 0x0u;
    g_mcmcan.canNodeConfig.messageRAM.txBuffersStartAddress = 0x520u;
    g_mcmcan.canDstNode.can = &MODULE_CAN0;
    g_mcmcan.canDstNode.frameMode = IfxCan_FrameMode_standard;
    g_mcmcan.canSrcNode.can = &MODULE_CAN0;
    g_mcmcan.canSrcNode.frameMode = IfxCan_FrameMode_standard;
    g_mcmcan.canNodeConfig.filterConfig.messageIdLength = IfxCan_MessageIdLength_standard;
    g_mcmcan.canNodeConfig.filterConfig.standardListSize = 1u;
    g_mcmcan.canNodeConfig.filterConfig.extendedListSize = 0u;
    g_mcmcan.canNodeConfig.filterConfig.standardFilterForNonMatchingFrames = IfxCan_NonMatchingFrame_reject;
    g_mcmcan.canNodeConfig.filterConfig.extendedFilterForNonMatchingFrames = IfxCan_NonMatchingFrame_reject;
    g_mcmcan.canNodeConfig.filterConfig.rejectRemoteFramesWithStandardId = TRUE;
    g_mcmcan.canNodeConfig.filterConfig.rejectRemoteFramesWithExtendedId = TRUE;
    IfxCan_Can_initNode(&g_mcmcan.canDstNode, &g_mcmcan.canNodeConfig);
    g_mcmcan.canFilter.elementConfiguration = IfxCan_FilterElementConfiguration_storeInRxBuffer;
    g_mcmcan.canFilter.number = 0u;
    g_mcmcan.canFilter.id1 = 0x6FEu;
    g_mcmcan.canFilter.rxBufferOffset = IfxCan_RxBufferId_0;
    IfxCan_Can_setStandardFilter(&g_mcmcan.canDstNode, &g_mcmcan.canFilter);
    IfxCan_Node_initRxPin(g_mcmcan.canDstNode.node, &IfxCan_RXD00B_P20_7_IN, IfxPort_Mode_inputPullUp, IfxPort_PadDriver_cmosAutomotiveSpeed1);
    IfxCan_Node_initTxPin(&IfxCan_TXD00_P20_8_OUT, IfxPort_OutputMode_pushPull, IfxPort_PadDriver_cmosAutomotiveSpeed4);
    IfxScuWdt_setCpuEndinit(IfxScuWdt_getCpuWatchdogPassword());
    IfxScuWdt_setSafetyEndinit(IfxScuWdt_getSafetyWatchdogPassword());
}

uint32 Can_Tx(McmcanType message)
{
    return IfxCan_Can_sendMessage(&message.canDstNode, &message.txMsg, (uint32*)message.txData);
}

void Can_Rx(void)
{
    IfxCan_Node_clearInterruptFlag(g_mcmcan.canDstNode.node, IfxCan_Interrupt_messageStoredToDedicatedRxBuffer);

    g_mcmcan.rxMsg.bufferNumber = 0u;

    if(1U == IfxCan_Can_isNewDataReceived(&g_mcmcan.canDstNode, 0u))
    {
        IfxCan_Can_readMessage(&g_mcmcan.canDstNode, &g_mcmcan.rxMsg, (uint32*)&g_mcmcan.rxData[0u]);
    }
    else
    {
        IfxCan_Node_clearRxBufferNewDataFlag(g_mcmcan.canDstNode.node, 0u);
    }

    if(0x6feu == g_mcmcan.rxMsg.messageId)
    {
        for(uint8 i = 0u; i < 8u; i++) FBL_RxFrame[i] = (uint8)g_mcmcan.rxData[i];
        switch(FBL_DSC_State)
        {
            case PROGRAMMING:
                FBL_DiagService_DSC_Programming();
                break;
            case HARDRESET:
                FBL_DiagService_ER_HardReset();
                break;
            case SOFTRESET:
                FBL_DiagService_ER_SoftReset();
                break;
            default:
                if(g_mcmcan.rxData[1u] == 0x10u && g_mcmcan.rxData[2u] == 0x02u)
                {
                    g_mcmcan.txMsg.dataLengthCode = g_mcmcan.rxMsg.dataLengthCode;
                    g_mcmcan.txMsg.messageId = g_mcmcan.rxMsg.messageId + 1u;
                    g_mcmcan.txData[0u] = g_mcmcan.rxData[0u];
                    g_mcmcan.txData[1u] = g_mcmcan.rxData[1u] + 0x40u;
                    g_mcmcan.txData[2u] = g_mcmcan.rxData[2u];
                    FBL_DSC_State = PROGRAMMING;
                    Can_Tx(g_mcmcan);
                    FBL_DiagService_DSC_Programming();
                }
                else
                {
                    /* Do nothing. */
                }
                break;
        }
        for(uint8 i = 0u; i < 8u; i++) FBL_RxFrame[i] = 0u;
        
    }
    else
    {
        /* Do nothing. */
    }

    memset(g_mcmcan.rxData, 0u, sizeof(g_mcmcan.rxData));
    g_mcmcan.rxMsg.messageId = 0u;
}

void FBL_CopyFunctionsToPSPR(void)
{
    memcpy((void *)ERASESECTOR_ADDR, (const void *)IfxFlash_eraseMultipleSectors, ERASESECTOR_LEN);
    g_commandFromPSPR.eraseSectors = (void *)ERASESECTOR_ADDR;
    memcpy((void *)WAITUNBUSY_ADDR, (const void *)IfxFlash_waitUnbusy, WAITUNBUSY_LEN);
    g_commandFromPSPR.waitUnbusy = (void *)WAITUNBUSY_ADDR;
    memcpy((void *)ENTERPAGEMODE_ADDR, (const void *)IfxFlash_enterPageMode, ENTERPAGEMODE_LEN);
    g_commandFromPSPR.enterPageMode = (void *)ENTERPAGEMODE_ADDR;
    memcpy((void *)LOAD2X32_ADDR, (const void *)IfxFlash_loadPage2X32, LOADPAGE2X32_LEN);
    g_commandFromPSPR.load2X32bits = (void *)LOAD2X32_ADDR;
    memcpy((void *)WRITEPAGE_ADDR, (const void *)IfxFlash_writePage, WRITEPAGE_LEN);
    g_commandFromPSPR.writePage = (void *)WRITEPAGE_ADDR;
    memcpy((void *)ERASEPFLASH_ADDR, (const void *)erasePFLASH, ERASEPFLASH_LEN);
    g_commandFromPSPR.eraseFlash = (void *)ERASEPFLASH_ADDR;
    memcpy((void *)WRITEPFLASH_ADDR, (const void *)writePFLASH, WRITEPFLASH_LEN);
    g_commandFromPSPR.writeFlash = (void *)WRITEPFLASH_ADDR;
}

void writePFLASH(uint32 startingAddr)
{
    IfxScuWdt_clearSafetyEndinitInline(IfxScuWdt_getSafetyWatchdogPasswordInline());
    g_commandFromPSPR.enterPageMode(startingAddr);
    IfxFlash_waitUnbusy(FLASH_MODULE, PROGRAM_FLASH_0);
    g_commandFromPSPR.load2X32bits(startingAddr, globalData[0u], globalData[1u]);
    g_commandFromPSPR.load2X32bits(startingAddr, globalData[2u], globalData[3u]);
    g_commandFromPSPR.load2X32bits(startingAddr, globalData[4u], globalData[5u]);
    g_commandFromPSPR.load2X32bits(startingAddr, globalData[6u], globalData[7u]);
    g_commandFromPSPR.writePage(startingAddr);
    IfxFlash_waitUnbusy(FLASH_MODULE, PROGRAM_FLASH_0);
    IfxScuWdt_setSafetyEndinitInline(IfxScuWdt_getSafetyWatchdogPasswordInline());
}

void FBL_DiagService_DSC_TransferData(void)
{
    FBL_ProgrammingData = (FBL_RxFrame[6u] << 24) |
            (FBL_RxFrame[5u] << 16) |
            (FBL_RxFrame[4u] << 8)  |
            FBL_RxFrame[3u];

    globalData[globalCounter32bytes] = FBL_ProgrammingData;
    globalCounter32bytes++;

    if(8u == globalCounter32bytes)
    {
        IfxCpu_disableInterrupts();
        g_commandFromPSPR.writeFlash(FBL_ProgrammingAddress);
        IfxCpu_enableInterrupts();
        globalCounter32bytes = 0u;
    }
    else
    {
        /* Do nothing. */
    }

    if(0u == globalCounter32bytes)
    {
        FBL_ProgrammingAddress += 32u;
        FBL_ProgrammingIndex += 8u;
    }
    else
    {
        /* Do nothing. */
    }

    g_mcmcan.txMsg.dataLengthCode = g_mcmcan.rxMsg.dataLengthCode;
    g_mcmcan.txMsg.messageId = g_mcmcan.rxMsg.messageId + 1u;
    g_mcmcan.txData[0u] = g_mcmcan.rxData[0u];
    g_mcmcan.txData[1u] = g_mcmcan.rxData[1u] + 0x40u;
    g_mcmcan.txData[2u] = g_mcmcan.rxData[2u];
    Can_Tx(g_mcmcan);
    for (uint8 i = 0u; i < 8u; i++) g_mcmcan.txData[i] = 0u;
    g_mcmcan.txMsg.dataLengthCode = 0u;
}

void erasePFLASH(uint32 sectorAddr)
{
    /* Get the current password of the Safety WatchDog module */
    uint16 endInitSafetyPassword = IfxScuWdt_getSafetyWatchdogPasswordInline();
    /* Erase the sector */
    IfxScuWdt_clearSafetyEndinitInline(endInitSafetyPassword);      /* Disable EndInit protection                   */
    g_commandFromPSPR.eraseSectors(sectorAddr, PFLASH_NUM_SECTORS); /* Erase the given sector                       */
    IfxScuWdt_setSafetyEndinitInline(endInitSafetyPassword);        /* Enable EndInit protection                    */
    /* Wait until the sector is erased */
    g_commandFromPSPR.waitUnbusy(FLASH_MODULE, PROGRAM_FLASH_0);
}

void FBL_DiagService_DSC_RequestDownload(void)
{
    g_mcmcan.txMsg.dataLengthCode = g_mcmcan.rxMsg.dataLengthCode;
    g_mcmcan.txMsg.messageId = g_mcmcan.rxMsg.messageId + 1u;
    g_mcmcan.txData[0u] = g_mcmcan.rxData[0u];
    g_mcmcan.txData[1u] = g_mcmcan.rxData[1u] + 0x40u;
    g_mcmcan.txData[2u] = g_mcmcan.rxData[2u];
    Can_Tx(g_mcmcan);
    for(uint8 i = 0u; i < 8u ; i++) g_mcmcan.txData[i] = 0u;
    g_mcmcan.txMsg.dataLengthCode = 0u;
}

void FBL_DiagService_DSC_RequestTransferExit(void)
{
    g_mcmcan.txMsg.dataLengthCode = g_mcmcan.rxMsg.dataLengthCode;
    g_mcmcan.txMsg.messageId = g_mcmcan.rxMsg.messageId + 1u;
    g_mcmcan.txData[0] = g_mcmcan.rxData[0u];
    g_mcmcan.txData[1] = g_mcmcan.rxData[1u] + 0x40u;
    g_mcmcan.txData[2] = g_mcmcan.rxData[2u];
    Can_Tx(g_mcmcan);
    for(uint8 i = 0u; i < 8u ; i++) g_mcmcan.txData[i] = 0u;
    g_mcmcan.txMsg.dataLengthCode = 0u;
}
void FBL_DiagService_RAR_MassEraseAPPL(void)
{
    IfxCpu_disableInterrupts();
    g_mcmcan.txMsg.dataLengthCode = g_mcmcan.rxMsg.dataLengthCode;
    g_mcmcan.txMsg.messageId = g_mcmcan.rxMsg.messageId + 1u;
    g_mcmcan.txData[0u] = g_mcmcan.rxData[0u];
    g_mcmcan.txData[1u] = g_mcmcan.rxData[1u] + 0x40u;
    g_mcmcan.txData[2u] = g_mcmcan.rxData[2u];
    Can_Tx(g_mcmcan);
    g_commandFromPSPR.eraseFlash(APPL_START_ADDRESS);
    for(uint8 i = 0u; i < 8u ; i++) g_mcmcan.txData[i] = 0u;
    g_mcmcan.txMsg.dataLengthCode = 0u;
    IfxCpu_enableInterrupts();
}

void FBL_JumpToAppl(void)
{
    appEntryGlobal = APPL_START_ADDRESS;

    IfxCpu_disableInterrupts();
    __asm("movh.a  a15,#@his(appEntryGlobal)");
    __asm("lea     a15,[a15]@los(appEntryGlobal)");
    __asm("ld.a    a15,[a15]");
    __asm("isync");
    __asm("ji      a15");
}
void FBL_DiagService_ER_SoftReset(void)
{
    IfxCpu_disableInterrupts();
    *FBL_DSC_Pointer = 0u;
    IfxScuRcu_performReset(2u, 0u);
}
void FBL_DiagService_ER_HardReset(void)
{
    IfxCpu_disableInterrupts();
    *FBL_DSC_Pointer = 0u;
    IfxScuRcu_performReset(2u, 0u);
}

void FBL_DiagService_RDBI_ReadActiveDiagnosticSession(void)
{
    g_mcmcan.txMsg.dataLengthCode = g_mcmcan.rxMsg.dataLengthCode;
    g_mcmcan.txMsg.messageId = g_mcmcan.rxMsg.messageId + 1u;
    g_mcmcan.txData[0u] = g_mcmcan.rxData[0u];
    g_mcmcan.txData[1u] = g_mcmcan.rxData[1u] + 0x40u;
    g_mcmcan.txData[2u] = g_mcmcan.rxData[2u];
    g_mcmcan.txData[3u] = g_mcmcan.rxData[3u];
    g_mcmcan.txData[4u] =  FBL_DSC_State;
    Can_Tx(g_mcmcan);
    for(uint8 i = 0u; i < 8u ; i++)
    {
        g_mcmcan.txData[i] = 0u;
    }
    g_mcmcan.txMsg.dataLengthCode = 0u;
}

uint32 debugaddress;

void FBL_DiagService_DSC_Programming(void)
{
    static uint8 counterblock = 0u;

    if(FBL_RxFrame[1u] == 0x22u && FBL_RxFrame[2u] == 0xF1u && FBL_RxFrame[3u] == 0x86u)
    {
        FBL_DiagService_RDBI_ReadActiveDiagnosticSession();
    }
    else
    {
        /* Do nothing. */
    }
    if(FBL_RxFrame[0u] == 0x04u && FBL_RxFrame[1u] == 0x31u && FBL_RxFrame[4u] == 0x00u)
    {
        FBL_DiagService_RAR_MassEraseAPPL();
    }
    else
    {
        /* Do nothing. */
    }

    if(FBL_RxFrame[1u] == 0x34u)
    {
        counterblock++;
        if(3u == counterblock)
        {
            debugaddress = FBL_ProgrammingAddress;
        }
        for(uint8 i = 0u; i < 8u; i++) globalData[i] = 0u;
        globalCounter32bytes = 0;
        FBL_ProgrammingAddress = (0xA0u << 24u)|(FBL_RxFrame[4u] << 16u)|(FBL_RxFrame[5u] << 8u)|(FBL_RxFrame[6u]);
        FBL_DiagService_DSC_RequestDownload();
    }
    else
    {
        /* Do nothing. */
    }

    if(FBL_RxFrame[1u] == 0x36u)
    {
        FBL_DiagService_DSC_TransferData();
    }
    else
    {
        /* Do nothing. */
    }

    if(FBL_RxFrame[1u] == 0x37u && FBL_RxFrame[0u] == 0x01u)
    {
        FBL_DiagService_DSC_RequestTransferExit();
    }
    else
    {
        /* Do nothing. */
    }

    if(FBL_RxFrame[1u] == 0x11u && FBL_RxFrame[2u] == 0x01u)
    {
        g_mcmcan.txMsg.dataLengthCode = g_mcmcan.rxMsg.dataLengthCode;
        g_mcmcan.txMsg.messageId = g_mcmcan.rxMsg.messageId + 1u;
        g_mcmcan.txData[0u] = g_mcmcan.rxData[0u];
        g_mcmcan.txData[1u] = g_mcmcan.rxData[1u] + 0x40u;
        g_mcmcan.txData[2u] = g_mcmcan.rxData[2u];
        g_mcmcan.txData[3u] = g_mcmcan.rxData[3u];
        Can_Tx(g_mcmcan);
        for(uint32 i = 0u; i < 200000u; i ++);
        FBL_DiagService_ER_HardReset();
    }
    else
    {
        /* Do nothing. */
    }
}
