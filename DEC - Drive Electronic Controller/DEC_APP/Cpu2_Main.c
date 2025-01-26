#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"
#include "Os.h"
#include "Wdg.h"

extern IfxCpu_syncEvent g_cpuSyncEvent;
extern IfxCpu_syncEvent g_cpuSyncEvent1;
extern IfxCpu_syncEvent g_cpuSyncEvent2;
IFX_ALIGN(4u) IfxCpu_syncEvent g_cpuSyncEvent3 = 0u;

void core2_main(void)
{
    IfxCpu_enableInterrupts();
    /* Wait for CPU sync event */
    IfxCpu_emitEvent(&g_cpuSyncEvent);
    IfxCpu_waitEvent(&g_cpuSyncEvent, 1);
    Wdg_InitializeCpu1Watchdog();
    Wdg_ReloadCpu2Watchdog();
    Os_Init_C2();
    Wdg_ReloadCpu2Watchdog();
    IfxCpu_emitEvent(&g_cpuSyncEvent1);
    IfxCpu_waitEvent(&g_cpuSyncEvent2, 1);
    IfxCpu_emitEvent(&g_cpuSyncEvent2);
    IfxCpu_waitEvent(&g_cpuSyncEvent2, 1);
    IfxCpu_emitEvent(&g_cpuSyncEvent3);
    IfxCpu_waitEvent(&g_cpuSyncEvent3, 1);
    Wdg_ReloadCpu1Watchdog();
    /* Start the scheduler */
    vTaskStartScheduler();
}
