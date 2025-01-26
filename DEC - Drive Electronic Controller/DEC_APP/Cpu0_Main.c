#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"
#include "Os.h"
#include "Ain_Filtering.h"
#include "Dma.h"
#include "Eru.h"
#include "Gtm_Atom.h"
#include "Gtm_Pwm.h"
#include "Can.h"
#include "Nvm.h"
#include "Dem.h"
#include "Dcm.h"
#include "McuSm.h"
#include "EncCal.h"
#include "SysMgr.h"
#include "Wdg.h"

IFX_ALIGN(4u) IfxCpu_syncEvent g_cpuSyncEvent = 0u;
IFX_ALIGN(4u) IfxCpu_syncEvent g_cpuSyncEvent1 = 0u;
extern IfxCpu_syncEvent g_cpuSyncEvent2;
extern IfxCpu_syncEvent g_cpuSyncEvent3;

void core0_main(void)
{
    SysMgr_EcuState = SYSMGR_STARTUP;
    IfxCpu_enableInterrupts();
    /* Wait for CPU sync event */
    IfxCpu_emitEvent(&g_cpuSyncEvent);
    IfxCpu_waitEvent(&g_cpuSyncEvent, 1);
    Wdg_InitializeCpu0Watchdog();
    Wdg_ReloadCpu0Watchdog();
    McuSm_InitializeDts();
    McuSm_MbistManager();
    Ain_FilteringInit();
    Dma_Init();
    Eru_Init();
    Gtm_Atom_Init();
    Gtm_Pwm_Init();
    Can_Init();
    Nvm_ReadAll();
    Wdg_ReloadCpu0Watchdog();
    Dem_Init();
    Dcm_Init();
    EncCal_MainFunction();
    Wdg_ReloadCpu0Watchdog();
    SysMgr_WakeupInitScr();
    SysMgr_ProcessResetDtc();
    Os_Init_C0();
    Wdg_ReloadCpu0Watchdog();
    McuSm_InitializeBusMpu();
    IfxCpu_emitEvent(&g_cpuSyncEvent1);
    IfxCpu_waitEvent(&g_cpuSyncEvent2, 1);
    IfxCpu_emitEvent(&g_cpuSyncEvent2);
    IfxCpu_waitEvent(&g_cpuSyncEvent2, 1);
    IfxCpu_emitEvent(&g_cpuSyncEvent3);
    IfxCpu_waitEvent(&g_cpuSyncEvent3, 1);
    Wdg_ReloadCpu0Watchdog();
    /* Start the scheduler */
    vTaskStartScheduler();
}
