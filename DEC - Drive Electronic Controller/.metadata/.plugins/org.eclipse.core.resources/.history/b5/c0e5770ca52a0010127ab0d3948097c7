#include "Nvm.h"
#include "SysMgr.h"
#include "McuSm.h"
#include "IfxCpu.h"
#include "Ain_Filtering.h"
#include "Can.h"
#include "Crc.h"
#include "task_core0.h"
#include "FreeRTOSConfig_core0.h"
#include "Wdg.h"
#include "IfxPmsPm.h"
#include "IfxStm.h"
#include "IfxPort.h"
#include "IfxPort_reg.h"
#include "Dem.h"
#include "SafetyKit_InternalWatchdogs.h"
#include "SafetyKit_Main.h"
#include "DiagMaster.h"

uint32 SysMgr_MainCounter = 0u;
uint32 SysMgr_RunCounter = 0u;
uint32 SysMgr_PostRunCounter = 0u;
SysMgr_EcuState_t SysMgr_EcuState = SYSMGR_INIT;
uint8 SysMgr_NoBusActivity = 0u;
uint8 SysMgr_Core1OnHalt = 0u;
uint8 SysMgr_Core2OnHalt = 0u;
float SysMgr_McuTemperature = 0u;
uint8 SysMgr_Core0OnIdlePowerDown = 0u;
uint8 SysMgr_ReleaseRun = 0u;
uint8 SysMgr_ReleasePostRun = 0u;

void SysMgr_ProcessResetDtc(void);
void SysMgr_EcuStateMachine(void);
void SysMgr_MainFunction(void);
void SysMgr_GoSleep(void);

void SysMgr_GoSleep(void)
{
    Ifx_P *portSfr0 = IfxPort_getAddress(0u);

    serviceCpuWatchdog();
    serviceSafetyWatchdog();
    Wdg_DeInitializeCpu0Watchdog();
    Wdg_DeInitializeSafetyWatchdog();
    Can_Sleep();
    IfxEvadc_disableModule(g_evadc.evadc);
    IfxFce_Crc_deInitModule(&g_fceCrc2.fceCrc);
    vTaskSuspendAll_core0();
    vTaskEndScheduler_core0();
    IfxStm_disableModule(&MODULE_STM0);
    SRC_STM0SR0.B.SRE = 0u;
    SRC_STM0SR1.B.SRE = 0u;
    SRC_STM1SR0.B.SRE = 0u;
    SRC_STM1SR1.B.SRE = 0u;
    SRC_STM2SR0.B.SRE = 0u;
    SRC_STM2SR1.B.SRE = 0u;
    SRC_BCUSPB.B.SRE = 0u;
    SRC_MTUDONE.B.SRE = 0U;
    SRC_PMSDTS.B.SRE = 0U;
    SRC_STM0SR0.B.CLRR = 1U;
    SRC_STM0SR1.B.CLRR = 1U;
    SRC_STM1SR0.B.CLRR = 1U;
    SRC_STM1SR1.B.CLRR = 1U;
    SRC_STM2SR0.B.CLRR = 1U;
    SRC_STM2SR1.B.CLRR = 1U;
    SRC_BCUSPB.B.CLRR = 1U;
    SRC_MTUDONE.B.CLRR = 1U;
    SRC_PMSDTS.B.CLRR = 1U;
    
    IfxPort_setPinMode(portSfr0, 0u, IfxPort_Mode_inputNoPullDevice);
    IfxPort_setPinPadDriver(portSfr0, 0u, IfxPort_PadDriver_cmosAutomotiveSpeed1);
    IfxPort_resetPinControllerSelection(portSfr0, 0u);
    IfxPort_setPinMode(portSfr0, 1u, IfxPort_Mode_inputNoPullDevice);
    IfxPort_setPinPadDriver(portSfr0, 1u, IfxPort_PadDriver_cmosAutomotiveSpeed1);
    IfxPort_resetPinControllerSelection(portSfr0, 1u);
    IfxScuWdt_setCpuEndinit(IfxScuWdt_getCpuWatchdogPassword());
    IfxScuWdt_setSafetyEndinit(IfxScuWdt_getSafetyWatchdogPassword());
    SysMgr_Core0OnIdlePowerDown = 1u;
    IfxCpu_setAllIdleExceptMasterCpu(IfxCpu_getCoreIndex());
    IfxPmsPm_setCoreMode(0u, IfxCpu_CoreMode_idle);
    for (uint32 index = 0U; index < (uint32)90000U; index++){__asm("nop");}
    McuSm_PerformResetHook(0, 0);
}

void SysMgr_ProcessResetDtc(void)
{
    if(0u == SysMgr_MainCounter)
    {
        if(0xEFEFU != McuSm_LastResetReason &&
                0u != McuSm_LastResetReason)
        {
            Dem_SetDtc(MCUSM_DTC_ID_SW_ERROR, 1u, 5u);
        }
        else
        {
            Dem_SetDtc(MCUSM_DTC_ID_SW_ERROR, 0u, 5u);
        }
    }
    else
    {
        /* Do nothing. */
    }
}

void SysMgr_EcuStateMachine(void)
{
    if(1u == Can_ActivityOnTheBus)
    {
        SysMgr_EcuState = SYSMGR_RUN;
    }
    else
    {
        /* Do nothing. */
    }

    switch(SysMgr_EcuState)
    {
        case SYSMGR_INIT:
        case SYSMGR_STARTUP:
            SysMgr_EcuState = SYSMGR_RUN;
            SysMgr_RunCounter = 2000u;
            SysMgr_PostRunCounter = 2000u;
            SysMgr_ReleaseRun = 1u;
            SysMgr_ReleasePostRun = 1u;
            break;
        case SYSMGR_RUN:
            if(1u == SysMgr_NoBusActivity || 1u <= DiagMaster_RequestDiagnosticMode)
            {
                SysMgr_RunCounter = 2000u;
                SysMgr_PostRunCounter = 2000u;
                SysMgr_ReleaseRun = 1u;
                SysMgr_ReleasePostRun = 1u;
                Nvm_WriteAllFinished = 0u;
            }
            else
            {
                SysMgr_ReleaseRun = 0u;
                SysMgr_ReleasePostRun = 1u;
            }

            if(0u == SysMgr_ReleaseRun)
            {
                if(0u != SysMgr_RunCounter)
                {
                    SysMgr_RunCounter--;
                }
                else
                {
                    SysMgr_PostRunCounter = 2000u;
                    SysMgr_ReleasePostRun = 1u;
                    SysMgr_EcuState = SYSMGR_POSTRUN;
                }
            }
            else
            {
                /* Do nothing.*/
            }
            break;
        case SYSMGR_POSTRUN:
            if(0u == Nvm_WriteAllFinished)
            {
                Nvm_WriteAll();
            }
            else if(2u == Nvm_WriteAllFinished)
            {
                SysMgr_ReleasePostRun = 0u;
            }
            else
            {
                /* Do nothing. */
            }

            if(0u == SysMgr_ReleasePostRun)
            {
                if(0u != SysMgr_PostRunCounter)
                {
                    SysMgr_PostRunCounter--;
                }
                else
                {
                    SysMgr_EcuState = SYSMGR_SLEEP;
                }
            }
            else
            {
                /* Do nothing. */
            }
            break;
        case SYSMGR_SLEEP:
            if(1u == SysMgr_Core1OnHalt &&
                    1u == SysMgr_Core2OnHalt)
            {
                SysMgr_GoSleep();
            }
            else
            {
                /* Do nothing.*/
            }
            break;
        default:
            break;
    }
}

void SysMgr_MainFunction(void)
{
    SysMgr_EcuStateMachine();
    SysMgr_McuTemperature = g_SafetyKitStatus.dieTempStatus.dieTemperatureCore;
    SysMgr_MainCounter++;
}
