#include "Crc.h"
#include "IfxCpu.h"
#include "Irq.h"

fceCrc g_fceCrc; /* Structure to store information */

void Crc_Init(void);
uint32 Crc_Calculate(const uint32 *crcData, uint16 crcDataLength, uint32 crcStartValue);
uint32 Crc_CalculateFCECRC(const uint32 *crcData, uint16 crcDataLength, uint32 crcStartValue);
/* Initialization of FCE
 * This function is called from main during initialization phase
 */
void Crc_Init(void)
{
    /* Disable interrupts */
    (void)IfxCpu_disableInterrupts();
    /* Create FCE module configuration */
    IfxFce_Crc_Config fceConfig;
    IfxFce_Crc_initModuleConfig(&fceConfig, &MODULE_FCE);
    /* ISR priorities and interrupt target */
    fceConfig.isrPriority = IRQ_PRIO_FCE;
    fceConfig.isrTypeOfService = IfxSrc_Tos_cpu0;
    /* Initialize module */
    IfxFce_Crc_initModule(&g_fceCrc.fce, &fceConfig);
    /* Initialize CRC kernel with default configuration */
    IfxFce_Crc_CrcConfig crcConfig;
    IfxFce_Crc_initCrcConfig(&crcConfig, &g_fceCrc.fce);
    /* For All CRC calculations */
    /* Enable Interrupt in case of CRC Mismatch */
    crcConfig.enabledInterrupts.crcMismatch = TRUE;
    /* Initialize FCE CRC */
    crcConfig.crcKernel = IfxFce_CrcKernel_0;
    crcConfig.fceChannelId = IfxDma_ChannelId_1;
    IfxFce_Crc_initCrc(&g_fceCrc.fceCrc, &crcConfig);
    //IfxCpu_Irq_installInterruptHandler(ISR_FCE_CRC, IRQ_PRIO_FCE);
}
/* Start the calculation
 * This function is called from main, background loop
 */
uint32 Crc_CalculateFCECRC(const uint32 *crcData, uint16 crcDataLength, uint32 crcStartValue)
{
    g_fceCrc.crc_result = Crc_Calculate(crcData, crcDataLength, crcStartValue);
    return g_fceCrc.crc_result;
}

uint32 Crc_Calculate(const uint32 *crcData, uint16 crcDataLength, uint32 crcStartValue)
{
    uint32 crcRet = 0u;

    IfxScuWdt_clearCpuEndinit(IfxScuWdt_getCpuWatchdogPassword());
    IfxScuWdt_clearSafetyEndinit(IfxScuWdt_getSafetyWatchdogPassword());

    crcRet =  IfxFce_Crc_calculateCrc(&g_fceCrc.fceCrc, crcData, crcDataLength, crcStartValue);

    IfxScuWdt_setCpuEndinit(IfxScuWdt_getCpuWatchdogPassword());
    IfxScuWdt_setSafetyEndinit(IfxScuWdt_getSafetyWatchdogPassword());

    return crcRet;
}
