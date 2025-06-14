#include "Bsw_Wrapper.h"
#include "SysMgr.h"
#include "Wdg.h"
#include "IfxCpu.h"
#include "IfxStm.h"
#include "task_core0.h"
#include "FreeRTOSConfig_core0.h"
#include "task_core1.h"
#include "FreeRTOSConfig_core1.h"
#include "task_core2.h"
#include "FreeRTOSConfig_core2.h"
#include "ComMaster.h"
#include "Iven.h"
#include "DcyHandler.h"
#include "ColDet.h"
#include "DiagMaster.h"
#include "McuSm.h"
#include "SafetyKit_InternalWatchdogs.h"
#include "EncCal.h"

static uint32 Bsw_Wrapper_MainCounter_C0 = 0u;
static uint32 Bsw_Wrapper_MainCounter_C1 = 0u;
static uint32 Bsw_Wrapper_MainCounter_C2 = 0u;

void Bsw_Wrapper_MainFunction_C0(void);
void Bsw_Wrapper_MainFunction_C1(void);
void Bsw_Wrapper_MainFunction_C2(void);

void Bsw_Wrapper_MainFunction_C0(void)
{
    static uint8 pIven_CanTx_DecMcuError = 0u;

    IfxCpu_disableInterrupts();

    memcpy(ComMaster_ReceiveTable, Can_ReceiveTable, sizeof(ComMaster_ReceiveTable));

    for(uint8 i = 0u; i < COMMASTER_NO_RX_MSG; i ++)
    {
        Can_ReceiveTable[i].receiveMessage.rxMsg.messageId = 0u;
    }

    ComMaster_TxSignal_ICM_ID = Iven_CanTx_IcmId;
    ComMaster_TxSignal_IrSenStat = ColDet_CanTx_IrSenStat;
    ComMaster_TxSignal_VehicleStatus = DcyHandler_CanTx_VehicleState;
    DcyHandler_CanRx_IgnitionState = Iven_CanTx_InVehicleSafetyError;
    ComMaster_TxSignal_DcyStatus = DcyHandler_CanTx_DcyStatus;
    DcyHandler_CanRx_VehicleSpeed = ComMaster_RxSignal_Speed;
    DcyHandler_CanRx_GearboxState = ComMaster_TxSignal_Gear;
    DcyHandler_CanRx_IgnitionState = ComMaster_TxSignal_Ignition;
    DcyHandler_CanTx_InVehicleSafetyErrorFlag = Iven_CanTx_InVehicleSafetyError;
    ComMaster_CanTx_InVehicleSafetyErrorFlag = Iven_CanTx_InVehicleSafetyError;
    DiagMaster_GearboxStatus = DcyHandler_CanRx_GearboxState;
    DiagMaster_VehicleSpeed = ComMaster_RxSignal_Speed;
    ColDet_CanRx_CalculatedSpeed = ComMaster_RxSignal_Speed;
    ComMaster_TxSignal_SbaBrakeLevel = ColDet_CanTx_BrakeLevel;
    Iven_CanRx_ErrorDetectedCbm = ComMaster_RxSignal_Err701_ID;
    ComMaster_RxSignal_Err701_ID = 0u;
    Iven_CanTx_IrSenStat = ColDet_CanTx_IrSenStat;
    Iven_CanRx_GearboxControl = ComMaster_TxSignal_Gear;
    Iven_CanRx_IgnitionControl = ComMaster_TxSignal_Ignition;
    Iven_CanRx_StatusDoorLeft = ComMaster_RxSignal_StatusDoorLeft;
    Iven_CanRx_StatusDoorRight = ComMaster_RxSignal_StatusDoorRight;
    DcyHandler_CanRx_StatusDoorLeft = ComMaster_RxSignal_StatusDoorLeft;
    DcyHandler_CanRx_StatusDoorRight = ComMaster_RxSignal_StatusDoorRight;

    if(0u != McuSm_LastResetReason
            && 0xEFEFU != McuSm_LastResetReason
            && 0xDFDFu != McuSm_LastResetReason
            && 0u == pIven_CanTx_DecMcuError)
    {
        Iven_CanTx_DecMcuError = 1u;
        pIven_CanTx_DecMcuError = 1u;
    }
    else
    {
        /* Do nothing. */
    }

    Iven_StatusDriveControlMessageState = ComMaster_StatusDriveControlMessageState;
    Iven_StatusActuatorMessageState = ComMaster_StatusActuatorMessageState;
    Iven_CanTx_DiagnosticMode = DiagMaster_DiagnosticModeActivated;
    DcyHandler_CanRx_RequestDiagnosisMode = DiagMaster_DiagnosticModeActivated;
    DcyHandler_CanRx_ResetDcy = DiagMaster_ResetDcy;

    serviceCpuWatchdog();
    serviceSafetyWatchdog();

    IfxCpu_enableInterrupts();

    Bsw_Wrapper_MainCounter_C0++;
}
void Bsw_Wrapper_MainFunction_C1(void)
{
    serviceCpuWatchdog();

    if(SYSMGR_SLEEP == SysMgr_EcuState)
    {
        Wdg_DeInitializeCpu1Watchdog();
        vTaskSuspendAll_core1();
        vTaskEndScheduler_core1();
        IfxStm_disableModule(&MODULE_STM1);
        SysMgr_Core1OnHalt = 1u;
        IfxCpu_setCoreMode(&MODULE_CPU1, IfxCpu_CoreMode_idle);
    }
    else
    {
        /* Do nothing. */
    }

    Bsw_Wrapper_MainCounter_C1++;
}
void Bsw_Wrapper_MainFunction_C2(void)
{
    serviceCpuWatchdog();

    if(SYSMGR_SLEEP == SysMgr_EcuState)
    {
        Wdg_DeInitializeCpu1Watchdog();
        vTaskSuspendAll_core2();
        vTaskEndScheduler_core2();
        IfxStm_disableModule(&MODULE_STM2);
        SysMgr_Core2OnHalt = 1u;
        IfxCpu_setCoreMode(&MODULE_CPU2, IfxCpu_CoreMode_idle);
    }
    else
    {
        /* Do nothing. */
    }

    Bsw_Wrapper_MainCounter_C2++;
}
