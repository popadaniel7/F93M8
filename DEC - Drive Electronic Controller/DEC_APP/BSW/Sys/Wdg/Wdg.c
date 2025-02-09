#include "Wdg.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"
#include "Bsp.h"

void Wdg_InitializeSafetyWatchdog(void);
void Wdg_InitializeCpu0Watchdog(void);
void Wdg_InitializeCpu1Watchdog(void);
void Wdg_InitializeCpu2Watchdog(void);
void Wdg_DeInitializeSafetyWatchdog(void);
void Wdg_DeInitializeCpu0Watchdog(void);
void Wdg_DeInitializeCpu1Watchdog(void);
void Wdg_DeInitializeCpu2Watchdog(void);
void Wdg_ReloadCpu0Watchdog(void);
void Wdg_ReloadCpu1Watchdog(void);
void Wdg_ReloadCpu2Watchdog(void);
void Wdg_ReloadSafetyWatchdog(void);

void Wdg_ReloadSafetyWatchdog(void)
{
    IfxScuWdt_serviceSafetyWatchdog(IfxScuWdt_getSafetyWatchdogPassword());
}

void Wdg_ReloadCpu0Watchdog(void)
{
    IfxScuWdt_serviceCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());           /* Continuously service CPU0WDT */
}

void Wdg_ReloadCpu1Watchdog(void)
{
    IfxScuWdt_serviceCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());           /* Continuously service CPU0WDT */
}

void Wdg_ReloadCpu2Watchdog(void)
{
    IfxScuWdt_serviceCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());           /* Continuously service CPU0WDT */
}

void Wdg_InitializeSafetyWatchdog(void)
{
    uint16 passwd;
    passwd = IfxScuWdt_getSafetyWatchdogPassword();
    /* Reconfigure the reload value (timeout) */
    IfxScuWdt_changeSafetyWatchdogReload(passwd, 15000U);
    /* Enable the safety watchdog if disabled (optional) */
    IfxScuWdt_enableSafetyWatchdog(passwd);
}

void Wdg_InitializeCpu0Watchdog(void)
{
    uint16 passwd;
    /* Get the SCU watchdog password for CPU0 */
    passwd = IfxScuWdt_getCpuWatchdogPassword();
    /* Reconfigure the reload value (timeout) */
    IfxScuWdt_changeCpuWatchdogReload(passwd, 15000U);
    /* Enable the CPU watchdog if disabled (optional) */
    IfxScuWdt_enableCpuWatchdog(passwd);
}

void Wdg_InitializeCpu1Watchdog(void)
{
    uint16 passwd;
    /* Get the SCU watchdog password for CPU0 */
    passwd = IfxScuWdt_getCpuWatchdogPassword();
    /* Reconfigure the reload value (timeout) */
    IfxScuWdt_changeCpuWatchdogReload(passwd, 15000U);
    /* Enable the CPU watchdog if disabled (optional) */
    IfxScuWdt_enableCpuWatchdog(passwd);
}

void Wdg_InitializeCpu2Watchdog(void)
{
    uint16 passwd;
    /* Get the SCU watchdog password for CPU0 */
    passwd = IfxScuWdt_getCpuWatchdogPassword();
    /* Reconfigure the reload value (timeout) */
    IfxScuWdt_changeCpuWatchdogReload(passwd, 15000U);
    /* Enable the CPU watchdog if disabled (optional) */
    IfxScuWdt_enableCpuWatchdog(passwd);
}

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

