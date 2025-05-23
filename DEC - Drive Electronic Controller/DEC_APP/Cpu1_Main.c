#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"
#include "Os.h"
#include "Wdg.h"
#include "task_core1.h"
#include "SafetyKit_InternalWatchdogs.h"
#include "McuSm.h"

extern uint8 OsInit_C0;
uint8 OsInit_C1 = 0u;

void core1_main(void)
{
    IfxCpu_enableInterrupts();
    initCpuWatchdog(1u);
    while(OsInit_C0 == 0u) serviceCpuWatchdog();
    Os_Init_C1();
    OsInit_C1 = 1u;
    serviceCpuWatchdog();
    vTaskStartScheduler_core1();
}
