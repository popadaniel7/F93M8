#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"
#include "Os.h"
#include "Wdg.h"
#include "task_core2.h"
#include "SafetyKit_InternalWatchdogs.h"
#include "McuSm.h"

extern uint8 OsInit_C1;
uint8 OsInit_C2 = 0u;

void core2_main(void)
{
    IfxCpu_enableInterrupts();
    initCpuWatchdog(2u);
    while(OsInit_C1 == 0u) serviceCpuWatchdog();
    Os_Init_C2();
    OsInit_C2 = 1u;
    serviceCpuWatchdog();
    /* Start the scheduler */
    vTaskStartScheduler_core2();
}
