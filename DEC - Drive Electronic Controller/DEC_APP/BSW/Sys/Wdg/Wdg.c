#include "Wdg.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"
#include "Bsp.h"

void Wdg_DeInitializeSafetyWatchdog(void);
void Wdg_DeInitializeCpu0Watchdog(void);
void Wdg_DeInitializeCpu1Watchdog(void);
void Wdg_DeInitializeCpu2Watchdog(void);

void Wdg_DeInitializeSafetyWatchdog(void)
{
    uint16 safetyWdtPw = IfxScuWdt_getSafetyWatchdogPassword();
    IfxScuWdt_clearSafetyEndinit(safetyWdtPw);
    IfxScuWdt_disableSafetyWatchdog(safetyWdtPw);
    IfxScuWdt_setSafetyEndinit(safetyWdtPw);
}

void Wdg_DeInitializeCpu0Watchdog(void)
{
    uint16 passwd;
    /* Get the SCU watchdog password for CPU0 */
    passwd = IfxScuWdt_getCpuWatchdogPassword();
    /* Reconfigure the reload value (timeout) */
    IfxScuWdt_changeCpuWatchdogReload(passwd, 15000U);
    /* Enable the CPU watchdog if disabled (optional) */
    IfxScuWdt_disableCpuWatchdog(passwd);
}

void Wdg_DeInitializeCpu1Watchdog(void)
{
    uint16 passwd;
    /* Get the SCU watchdog password for CPU0 */
    passwd = IfxScuWdt_getCpuWatchdogPassword();
    /* Reconfigure the reload value (timeout) */
    IfxScuWdt_changeCpuWatchdogReload(passwd, 15000U);
    /* Enable the CPU watchdog if disabled (optional) */
    IfxScuWdt_disableCpuWatchdog(passwd);
}

void Wdg_DeInitializeCpu2Watchdog(void)
{
    uint16 passwd;
    /* Get the SCU watchdog password for CPU0 */
    passwd = IfxScuWdt_getCpuWatchdogPassword();
    /* Reconfigure the reload value (timeout) */
    IfxScuWdt_changeCpuWatchdogReload(passwd, 15000U);
    /* Enable the CPU watchdog if disabled (optional) */
    IfxScuWdt_disableCpuWatchdog(passwd);
}
