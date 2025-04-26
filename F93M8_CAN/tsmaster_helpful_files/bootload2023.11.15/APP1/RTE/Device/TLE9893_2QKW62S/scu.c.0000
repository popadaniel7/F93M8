/*
 ***********************************************************************************************************************
 *
 * Copyright (c) Infineon Technologies AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the
 * following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, this list of conditions and the  following
 *   disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *   following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *   Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 *   products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 **********************************************************************************************************************/

/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/

#include "scu.h"

/*******************************************************************************
**                        Private Constant Declarations                       **
*******************************************************************************/

/*******************************************************************************
**                         Private Macro Declarations                         **
*******************************************************************************/
#define SYSTICK_DELAY_THRESHOLD 100U

/*******************************************************************************
**                        Private Variable Definitions                        **
*******************************************************************************/

sint8 e_xtalSts;

/*******************************************************************************
**                        Private Function Declarations                       **
*******************************************************************************/

/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

/** \brief Initialize the SCU module
 */
void SCU_init(void)
{
  /* Enable CLKOUT if configured */
  SCU->CLKSEL.reg |= ((uint32)SCU_CLKSEL & SCU_CLKSEL_CLKOUTEN_Msk);
}

/** \brief Initialize the SCU clock
 * \brief If configured in Config Wizard, the function initializes
 * \brief - XTAL
 * \brief - PLL0
 * \brief - PLL1
 * \brief In case of an XTAL error, the XTAL error status
 * is stored in the global variable e_xtalSts
 * \brief The function always initializes
 * \brief - fSYS0 (for core and peripherals except UART, CAN)
 * \brief - fSYS1 (for UART, CAN)
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 SCU_initClk(void)
{
  sint8 s8_returnCode;
  uint8 u8_nmiEnTemp;
  
  /* Prepare for CLK_Init: switch to HP40_Ckl, disable PLL, disable XTAL */
  SCU->CLKSEL.reg = 0x00000000u;
  PLL->CON0.bit.PLLEN = 0;
  PLL->CON1.bit.PLLEN = 0;
  SCU->XTALCON.reg = 0x00000033u;
  
#if ((SCU_XTALCON & SCU_XTALCON_XPD_Msk) == 0u)
  uint32 u32_currentTime_ms;
  uint32 u32_endTime_ms;
#endif
  
  s8_returnCode = ERR_LOG_SUCCESS;
  /* Initialize Clock Sources */
  /* XTAL (only if needed) */
#if ((SCU_XTALCON & SCU_XTALCON_XPD_Msk) == 0u)
  e_xtalSts = ERR_LOG_SUCCESS;
  u8_nmiEnTemp = 0;

  if (SCU->NMICON.bit.NMIXTALEN == 1u)
  {
    SCU->NMICON.bit.NMIXTALEN = 0;
    u8_nmiEnTemp = 1u;
  }

  /* Disable P2.0 and P2.1 input */
  GPIO->P2_INDIS.reg |= 0x3;
  /* Configure XTALOSC, Start XTALOSC, Start XTALWDG */
  SCU->XTALCON.reg = SCU_XTALCON;
  u32_endTime_ms = INT_getGlobTimestamp() + SCU_XTAL_START_TIME_MS;

  do
  {
    /* wait for XTAL ok */
    u32_currentTime_ms = INT_getGlobTimestamp();
  }
  while ((SCU_GetXTALFailSts() == 1u) && (u32_currentTime_ms < u32_endTime_ms));

  /* Check timeout */
  if (u32_currentTime_ms >= u32_endTime_ms)
  {
    s8_returnCode = ERR_LOG_CODE_TIMEOUT;
    e_xtalSts = SCU_checkXTALDiagnosis();
  }

  /* Clear XTAL FAIL status */
  SCU->XTALSTATC.reg = SCU_XTALSTATC_XTAL_FAIL_STSCLR_Msk;
  /* Clear NMIXTAL status */
  SCU->NMISRC.reg = SCU_NMISRC_NMIXTALCLR_Msk;

  /* Enable XTAL NMI if needed */
  if (u8_nmiEnTemp == 1u)
  {
    SCU->NMICON.bit.NMIXTALEN = 1;
  }

#endif
  /* PLL0 (only if needed) */
#if (SCU_PLL0_EN == 1u)
  /* Disable PLLx NMI */
  u8_nmiEnTemp = 0u;

  if (SCU->NMICON.bit.NMIPLL0EN == 1u)
  {
    SCU->NMICON.bit.NMIPLL0EN = 0;
    u8_nmiEnTemp = 1u;
  }

  /* Configure PLLx */
  PLL->CON0.reg = (uint32)PLL_CON0 & (~PLL_CON0_PLLEN_Msk);
  PLL->SPCTR.reg |= (uint32)PLL_SPCTR & ((~(uint32)PLL_SPCTR_SPEN0_Msk) & 0x0000FFFFu);
  PLL->SPCTR.reg |= (uint32)PLL_SPCTR & PLL_SPCTR_SPEN0_Msk;
  /* Start PLLx */
  PLL->CON0.bit.PLLEN = 1;

  while (SCU_GetPLL0LockSts() == 0u) // TODO && no timeout
  {
    /* wait for PLLx being locked */
    CMSIS_NOP();
  }

  /* Clear PLLx Loss of Lock status */
  PLL->STATC.reg = PLL_STATC_PLL0_LOL_STSCLR_Msk;
  /* Clear PLLx NMI status */
  SCU->NMISRC.reg = SCU_NMISRC_NMIPLL0CLR_Msk;

  /* Enable PLLx NMI if needed */
  if (u8_nmiEnTemp == 1u)
  {
    SCU->NMICON.bit.NMIPLL0EN = 1;
  }

#endif
  /* PLL1 (only if needed) */
#if (SCU_PLL1_EN == 1u)
  /* Disable PLLx NMI */
  u8_nmiEnTemp = 0u;

  if (SCU->NMICON.bit.NMIPLL1EN == 1u)
  {
    SCU->NMICON.bit.NMIPLL1EN = 0;
    u8_nmiEnTemp = 1u;
  }

  /* Configure PLLx */
  PLL->CON1.reg = (uint32)PLL_CON1 & (~PLL_CON1_PLLEN_Msk);
  PLL->SPCTR.reg |= (uint32)PLL_SPCTR & ((~(uint32)PLL_SPCTR_SPEN1_Msk) & 0xFFFF0000u);
  PLL->SPCTR.reg |= (uint32)PLL_SPCTR & PLL_SPCTR_SPEN1_Msk;
  /* Start PLLx */
  PLL->CON1.bit.PLLEN = 1;

  while (SCU_GetPLL1LockSts() == 0u)
  {
    /* wait for PLLx being locked */
    CMSIS_NOP();
  }

  /* Clear PLLx Loss of Lock status */
  PLL->STATC.reg = PLL_STATC_PLL1_LOL_STSCLR_Msk;
  /* Clear PLLx NMI status */
  SCU->NMISRC.reg = SCU_NMISRC_NMIPLL1CLR_Msk;

  /* Enable PLLx NMI if needed */
  if (u8_nmiEnTemp == 1u)
  {
    SCU->NMICON.bit.NMIPLL1EN = 1;
  }

#endif
  /* Initialize Clock tree Configuration */
  /* Don't enable CLKOUT here, done ein SCU_init */
  SCU->CLKSEL.reg = ((uint32)SCU_CLKSEL) & (~SCU_CLKSEL_CLKOUTEN_Msk);
  /* Write CLKCON=0 before setting CLKCON (PRECAN/PREUART can only be written when CANCLKEN/UARTCLKEN=0 */
  SCU->CLKEN.reg = (uint32)0u;
  SCU->CLKCON.reg = (uint32)SCU_CLKCON;
  SCU->CLKEN.reg = (uint32)SCU_CLKEN;
  return s8_returnCode;
}

/** \brief Check XTAL Diagnosis as describen in the User Manual
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 SCU_checkXTALDiagnosis(void)
{
  sint8 s8_returnCode;
  uint32 u32_gpioP2Pud;
  uint32 u32_gpioP2Indis;

  s8_returnCode = ERR_LOG_SUCCESS;
  /* Store register values */
  u32_gpioP2Pud = GPIO->P2_PUD.reg;
  u32_gpioP2Indis = GPIO->P2_INDIS.reg;
  
  GPIO->P2_PUD.bit.PUDEN0 = 1u;
  GPIO->P2_INDIS.bit.INDIS0 = 0u;
  GPIO->P2_PUD.bit.PUDSEL0 = 1u;
  SCU_delay_us(5);

  if (GPIO->P2_IN.bit.PI0 == 0u)
  {
    s8_returnCode = ERR_LOG_ERROR;
  }

  GPIO->P2_PUD.bit.PUDSEL0 = 0u;
  SCU_delay_us(5);

  if (GPIO->P2_IN.bit.PI0 == 1u)
  {
    s8_returnCode = ERR_LOG_ERROR;
  }

  GPIO->P2_PUD.bit.PUDEN0 = 0u;
  GPIO->P2_INDIS.bit.INDIS0 = 1u;
  GPIO->P2_PUD.bit.PUDEN1 = 1u;
  GPIO->P2_INDIS.bit.INDIS1 = 0u;
  GPIO->P2_PUD.bit.PUDSEL1 = 1u;
  SCU_delay_us(5);

  if (GPIO->P2_IN.bit.PI1 == 0u)
  {
    s8_returnCode = ERR_LOG_ERROR;
  }

  GPIO->P2_PUD.bit.PUDSEL1 = 0u;
  SCU_delay_us(5);

  if (GPIO->P2_IN.bit.PI1 == 1u)
  {
    s8_returnCode = ERR_LOG_ERROR;
  }

  GPIO->P2_PUD.bit.PUDEN1 = 0u;
  GPIO->P2_INDIS.bit.INDIS1 = 1u;
  
  /* Restore register values */
  GPIO->P2_PUD.reg = u32_gpioP2Pud;
  GPIO->P2_INDIS.reg = u32_gpioP2Indis;
  
  return s8_returnCode;
}

/** \brief Delays the regular program execution by a given number of Microseconds
 * \brief the function returns if the given time has elapsed
 * \brief Too small delay times are being falsified by execution time
 * \brief of the function itself
 *
 * \warning Handle this function with care, as the watchdog will not be serviced during the delay time.
 * \warning The user has to take care of WDT1/WDT service by himself.
 *
 * \param u32_time_us Delay time in Microseconds
 *
 * \brief <b>Example</b><br>
 * \brief This example sets a delay of 100 us.
 * ~~~~~~~~~~~~~~~{.c}
 * void Example_Function(void)
 * {
 *     SCU_delay_us(100);
 * }
 * ~~~~~~~~~~~~~~~
 */
void SCU_delay_us(uint32 u32_time_us)
{
  uint32 u32_systickTargetVal;
  uint32 u32_systickVal;
  uint32 u32_delayCnt;
  uint32 u32_systickCur;
  uint32 u32_systickRelVal;
  /* Get current systick value */
  u32_systickRelVal = SCU_getSysTickRelVal();
  /* Adapt systick value into range SYSTICK_DELAY_THRESHOLD...reload value-SYSTICK_DELAY_THRESHOLD to avoid getting stuck in a while, wait in case needed */
  do
  {
    u32_systickVal = SCU_getSysTickCntVal();
  }while((u32_systickVal < SYSTICK_DELAY_THRESHOLD) || (u32_systickVal > (u32_systickRelVal - SYSTICK_DELAY_THRESHOLD)));

  while (u32_time_us >= (uint32)1000)
  {
    /* Wait for underflow */
    while (SCU_getSysTickCntVal() < u32_systickVal)
    {}

    /* Wait target underflowed */
    while (SCU_getSysTickCntVal() > u32_systickVal)
    {}

    u32_time_us -= (uint32)1000;
  }

  u32_delayCnt = u32_time_us * (uint32)MULTIPLIER_US_TO_TICKS;
  
  /* Adapt systick value into range SYSTICK_DELAY_THRESHOLD...reload value-SYSTICK_DELAY_THRESHOLD to avoid getting stuck in a while, wait in case needed */
  u32_systickVal = SCU_getSysTickCntVal();

  if (u32_systickVal >= u32_delayCnt)
  {
    u32_systickTargetVal = u32_systickVal - u32_delayCnt;

    /* Wait underflow with 1 countdown detection */
    do
    {
      u32_systickCur = SCU_getSysTickCntVal();
    }
    while ((u32_systickCur > u32_systickTargetVal) && (u32_systickCur < u32_systickVal));
  }
  else
  {
    u32_systickTargetVal = SCU_getSysTickRelVal() - (u32_delayCnt - u32_systickVal);

    /* Wait for underflow */
    while (SCU_getSysTickCntVal() < u32_systickVal)
    {}

    /* Wait target underflowed */
    while (SCU_getSysTickCntVal() > u32_systickTargetVal)
    {}
  }

  return;
}

/** \brief Initialize the SysTick
 * 
 * \param u32_value SysTick Reload Value
 */
void SCU_initSysTick(uint32 u32_value)
{
  /* Program the SysTick reload value */
  CPU->SYSTICK_RL.reg = u32_value;
  /* Reset the SysTick current value */
  CPU->SYSTICK_CUR.reg = (uint32)0u;
  /* Define the SysTick timer clock as the CPU clock */
  CPU->SYSTICK_CS.bit.CLKSOURCE = 1u;
  /* Enable the SysTick exception request */
  CPU->SYSTICK_CS.bit.TICKINT = 1u;
  /* Enable the SysTick counter */
  CPU->SYSTICK_CS.bit.ENABLE = 1u;
}

/** \brief Configure the Safe Switch-Off release sequence (SSO release sequence)
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 SCU_enSafeSwitchOffSeq(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;
  
  /* Initialize the Fail-Safe Watchdog */
  s8_returnCode = PMU_initFailSafeWatchdog();

  if (s8_returnCode == ERR_LOG_SUCCESS)
  {
    /* Initialize the CSA/CSC module */
    s8_returnCode = CSACSC_init();

    if (s8_returnCode == ERR_LOG_SUCCESS)
    {
      /* Initialize the Bridge Driver module */
      s8_returnCode = BDRV_init();
    }
  }

  return s8_returnCode;
}

/** \brief Enter the Deep Sleep mode
 */
void SCU_enterDeepSleepMode(void)
{
  /* Free up the pipeline */
  CMSIS_NOP();
  CMSIS_NOP();
  CMSIS_NOP();
  /* Set send event */
  CMSIS_SEV();
  /* Clear send event */
  CMSIS_WFE();
  /* Enter CPU Deep Sleep */
  CMSIS_WFE();
}

/** \brief Enter the Stop mode with Reset Wake-up
 */
void SCU_enterStopModeWithResetWakeup(void)
{
  /* The RAM reduction is configured by default in the Config Wizard */
  /* Enable the Wake-up with Reset */
  PMU->WAKE_CTRL.bit.WAKE_W_RST = 1u;
  /* Disable RAM init test */
  PMU->START_CONFIG.bit.CONF = 0u;
  /* Select HP_CLK as system clock*/
  /* As the system will start the HP_CLK after the reset anyway, it is to avoid any problems with the PLL clocks in between */
  SCU->CLKSEL.bit.SELSYS0 = 0u;
  SCU->CLKSEL.bit.SELSYS1 = 0u;
  /* Disable XTAL_OSC */
  SCU->XTALCON.bit.XWDGEN = 0u;
  SCU->XTALCON.bit.XPD = 1u;
  /* Disable all interrupts */
  CPU->NVIC_ICER.reg = (uint32)0xFFFFFFFFu;
  /* Enter Stop Mode */
  SCU->PMCON0.bit.STOP = 1u;
  /* Free up pipeline */
  CMSIS_NOP();
  CMSIS_NOP();
  CMSIS_NOP();
  /* Set send event */
  CMSIS_SEV();
  /* Clear send event */
  CMSIS_WFE();
  /* Enter CPU Deep Sleep */
  CMSIS_WFE();
}

/** \brief Enter the Stop mode without Reset Wake-up
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 SCU_enterStopModeWithoutResetWakeup(void)
{
  sint8 s8_returnCode;
  uint32 u32_p0Dir;
  uint32 u32_p1Dir;
  uint32 u32_p0Pud;
  uint32 u32_p1Pud;
  uint32 u32_p2Pud;
  uint32 u32_int;
  
  s8_returnCode = ERR_LOG_SUCCESS;
  /* Saving the GPIOs settings */
  u32_p0Dir = GPIO->P0_DIR.reg;
  u32_p1Dir = GPIO->P1_DIR.reg;
  u32_p0Pud = GPIO->P0_PUD.reg;
  u32_p1Pud = GPIO->P1_PUD.reg;
  u32_p2Pud = GPIO->P2_PUD.reg;
  /* Saving the interrupt settings */
  u32_int = CPU->NVIC_ISER.reg;

  /* Select HP_CLK as system clock */
  SCU->CLKSEL.bit.SELSYS0 = 0u;
  SCU->CLKSEL.bit.SELSYS1 = 0u;
  /* Disable XTAL_OSC */
  SCU->XTALCON.bit.XPD = 1u;
  /* Disable all interrupts */
  CPU->NVIC_ICER.reg = (uint32)0xFFFFFFFFu;
  /* Enter Stop Mode */
  SCU->PMCON0.bit.STOP = 1u;
  /* Free up pipeline */
  CMSIS_NOP();
  CMSIS_NOP();
  CMSIS_NOP();
  /* Set send event */
  CMSIS_SEV();
  /* Clear send event */
  CMSIS_WFE();
  /* Enter CPU Deep Sleep */
  CMSIS_WFE();

  /* Exit Stop Mode */
  /* Free up the pipeline */
  CMSIS_NOP();
  CMSIS_NOP();
  CMSIS_NOP();
  /* Initialize the system */
  SystemInit();
  /* Release Safe Switch-Off path */
  s8_returnCode = SCU_enSafeSwitchOffSeq();
  /* Enable the interrupts to their state before stop mode*/
  CPU->NVIC_ISER.reg = u32_int;
  /* Program GPIOs to their state before stop mode */
  GPIO->P0_DIR.reg = u32_p0Dir;
  GPIO->P0_PUD.reg = u32_p0Pud;
  GPIO->P1_DIR.reg = u32_p1Dir;
  GPIO->P1_PUD.reg = u32_p1Pud;
  GPIO->P2_PUD.reg = u32_p2Pud;
  
  return s8_returnCode;
}

/** \brief Enter the Sleep mode
 * \note Before entering sleep mode, you can store data in the GPUDATAx [x=0..2] registers.
 *
 * \param u8_enRAMTest Start configuration: 0(disable)/1(enable) RAM test after wake from Stop mode
 */
void SCU_enterSleepMode(uint8 u8_enRAMTest)
{
  /* Option: RAM init at bootup */
  PMU->START_CONFIG.bit.CONF = u8_enRAMTest;
  /* Clear all wake-up status flags */
  PMU->WAKE_STS_CLR.reg = (uint32)0x1FF73F5u;
  /* Select HP_CLK as system clock */
  SCU->CLKSEL.bit.SELSYS0 = 0u;
  SCU->CLKSEL.bit.SELSYS1 = 0u;
  /* Disable XTAL_OSC */
  SCU->XTALCON.bit.XPD = 1u;
  /* Disable all interrupts */
  CPU->NVIC_ICER.reg = (uint32)0xFFFFFFFFu;
  /* Enter Sleep mode */
  SCU->PMCON0.bit.SLEEP = 1u;
  /* Set send event */
  CMSIS_SEV();
  /* Clear send event */
  CMSIS_WFE();
  /* Enter CPU Deep Sleep */
  CMSIS_WFE();
}


