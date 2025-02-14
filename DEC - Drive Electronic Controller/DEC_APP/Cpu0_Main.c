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
#include "Smu.h"
#include "Crc.h"

uint8 OsInit_C0 = 0u;

void core0_main(void)
{
    SysMgr_EcuState = SYSMGR_STARTUP;
    IfxCpu_enableInterrupts();
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
    IfxScuWdt_disableSafetyWatchdog(IfxScuWdt_getSafetyWatchdogPassword());
    //McuSm_MbistManager();
    McuSm_InitializeDts();
    Ain_FilteringInit();
    Dma_Init();
    Smu_Init();
    McuSm_InitializeBusMpu();
    Eru_Init();
    Can_Init();
    Crc_Init();
    Nvm_ReadAll();
    Dem_Init();
    Dcm_Init();
    EncCal_MainFunction();
    SysMgr_WakeupInitScr();
    SysMgr_ProcessResetDtc();
    Os_Init_C0();
    OsInit_C0 = 1u;
    vTaskStartScheduler_core0();
}
