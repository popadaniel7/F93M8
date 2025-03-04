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

#include "pmu.h"

/*******************************************************************************
**                         Private Macro Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                        Private Constant Definitions                        **
*******************************************************************************/

/*******************************************************************************
**                          Private Type Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                        Private Variable Definitions                        **
*******************************************************************************/

static volatile uint32 u32_failsafeWatchdogCnt;
static bool b_SOWactive = false;
static bool b_firstNOW = false;

/*******************************************************************************
**                        Private Function Declarations                       **
*******************************************************************************/

/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

/** \brief Initialize all CW registers of the PMU module
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 PMU_init(void)
{
  sint8 s8_returnCode;

  s8_returnCode = ERR_LOG_SUCCESS;
  
  PMU->START_CONFIG.reg = (uint32)PMU_START_CONFIG;
  
  /* Configure the FIFO pull-up resistor */
  PMU->MISC_CTRL.reg = (uint32)PMU_MISC_CTRL;
  #if defined(UC_FEATURE_48PIN)
  {
    /* 48pin only, FIFO pull-up enabled */
    PMU->MISC_CTRL.bit.FI_PU_EN = 1;
  }
  #endif

  /* Checking for possible reset trigger source(s) and resetting the status flags if necessary can be done in the application */

  PMU->RST_CTRL.reg = (uint32)PMU_RST_CTRL;

  /* Checking for possible hardware failure trigger source(s) and for possible wake-up 
  trigger source(s) and resetting the status flags if necessary can be done in the application */
  if (PMU->WAKE_FAIL_STS.reg != (uint32)0u)
  {
    s8_returnCode = ERR_LOG_ERROR;
  }

  /* Configure the fail-safe watchdog - done in System_init */

  /* The safe-shutdown path is initialized in system_tle989x.c */
  
  /* Configure the voltage regulator */
  PMU->VDDP_CTRL.reg = (uint32)PMU_VDDP_CTRL;
  PMU->VDDC_CTRL.reg = (uint32)PMU_VDDC_CTRL;
  PMU->VDDEXT_CTRL.reg = (uint32)PMU_VDDEXT_CTRL;
  /* Configure the wake-up control unit */
  PMU->WAKE_FILT_CTRL.reg = (uint32)PMU_WAKE_FILT_CTRL;
  PMU->WAKE_GPIO_CTRL0.reg = (uint32)PMU_WAKE_GPIO_CTRL0;
  PMU->WAKE_GPIO_CTRL1.reg = (uint32)PMU_WAKE_GPIO_CTRL1;
  PMU->WAKE_GPIO_CTRL2.reg = (uint32)PMU_WAKE_GPIO_CTRL2;
  PMU->WAKE_GPIO_CTRL3.reg = (uint32)PMU_WAKE_GPIO_CTRL3;
  PMU->WAKE_GPIO_CTRL4.reg = (uint32)PMU_WAKE_GPIO_CTRL4;
  PMU->WAKE_GPIO_CTRL5.reg = (uint32)PMU_WAKE_GPIO_CTRL5;
  PMU->MON_CTRL1.reg = (uint32)PMU_MON_CTRL1;
  PMU->MON_CTRL2.reg = (uint32)PMU_MON_CTRL2;
  PMU->MON_CTRL3.reg = (uint32)PMU_MON_CTRL3;
  PMU->CYC_CTRL.reg = (uint32)PMU_CYC_CTRL;
  PMU->WAKE_CTRL.reg = (uint32)PMU_WAKE_CTRL;

  return s8_returnCode;
}

/** \brief Count up since the last watchdog trigger
 */
void PMU_countFailSafeWatchdog(void)
{
  u32_failsafeWatchdogCnt++;
}

/** \brief Initialize the fail-safe watchdog
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 PMU_initFailSafeWatchdog(void)
{
  sint8 s8_returnCode;
  uint32 u32_maxDelay_ms;

  s8_returnCode = ERR_LOG_SUCCESS;
  /* Maximum delay for the self-test of 2 seconds */
  u32_maxDelay_ms = (uint32)2000u;
  /* Initialisation of the tick counter */
  u32_failsafeWatchdogCnt = 0u;

  /* A successful self-test of the fail-safe watchdog sets the FS_STS.WD_FAIL_STS bit */
  while (u32_failsafeWatchdogCnt < u32_maxDelay_ms)
  {
    if (PMU_getWDFailSts() == 1u)
    {
      /* The watchdog starts in Long Open Window (typically 180 ms) */
      /* The fail-safe watchdog period can only be programmed during the LOW phase */
      /* wd_en is masked: the FW automatically resets the EN bit when entering debug mode or sets it when entering user mode */
      PMU->WD_CTRL.bit.WDP = (uint8)(((uint32)PMU_WD_CTRL & PMU_WD_CTRL_WDP_Msk) >> PMU_WD_CTRL_WDP_Pos);
      /* The number of SOW must be set before the first fail-safe watchdog in the LOW */
      PMU->WD_CTRL.bit.SOW = (uint8)(((uint32)PMU_WD_CTRL & PMU_WD_CTRL_SOW_Msk) >> PMU_WD_CTRL_SOW_Pos);
      /* The bit TRIG needs to be toggled to provide a proper trigger */
      PMU->WD_TRIG.bit.TRIG ^= 1u;
      /* The fail-safe watchdog counter must be reset, since a new window starts */
      u32_failsafeWatchdogCnt = 0;       
		
      break;
    }
  }

  if (u32_failsafeWatchdogCnt == u32_maxDelay_ms)
  {
    /* Failed initialization of the fail-safe watchdog */
    s8_returnCode = ERR_LOG_CODE_TIMEOUT;
  }

  return s8_returnCode;
}


/** \brief Stop the fail-safe watchdog
 */
void PMU_stopFailSafeWatchdog(void)
{
  /* Disable the SysTick Timer */
  CPU->SYSTICK_CS.bit.ENABLE = 0u;
}

/** \brief Service the fail-safe watchdog
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 PMU_serviceFailSafeWatchdog(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Check if the counter is within the effective open window (safe trigger point) or if a SOW service has been done before */
  if ((u32_failsafeWatchdogCnt > PMU_SAFE_TRIGGER) || (b_SOWactive == true))
  {
    /* Service watchdog by toggling bit PMU->WD_TRIG.bit.TRIG */
    PMU->WD_TRIG.bit.TRIG ^= 1u;
    /* Reset the fail-safe watchdog counter */
    u32_failsafeWatchdogCnt = (uint32)0;
    /* Reset "short open window" active flag */
    b_SOWactive = false;
    /* For the first normal window, the initialization of the fail-safe watchdog has to be completed */
    if (b_firstNOW == false)
    {
      /* Clear WD_FAIL after self test */
      PMU->FS_STS_CLR.bit.WD_FAIL_STS_CLR = (uint8)1;
      /* Clear SSD_STS and FO_STS bits */
      PMU->FS_SSD_CLR.reg = (uint32)(PMU_FS_SSD_CLR_SSD_STS_CLR_Msk | PMU_FS_SSD_CLR_FO_STS_CLR_Msk);
      /* The first normal open window has happened */
      b_firstNOW = true;
    }
  }
  else
  {
    s8_returnCode = ERR_LOG_CODE_NO_TRIGGER;
  }

  return s8_returnCode;
}

/** \brief Clear the fail-safe watchdog fail status
 */
void PMU_clrFailSafeWatchdogFailSts(void)
{
  if(PMU->FS_STS.bit.WD_FAIL_STS == 1u)
  {
    if (PMU_serviceFailSafeWatchdog() == ERR_LOG_SUCCESS)
    {
      PMU->FS_STS_CLR.bit.WD_FAIL_STS_CLR = 1u;
    }
  }
}

/** \brief Service a Short Open Window for the watchdog
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 PMU_serviceFailSafeWatchdogSOW(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  if (PMU->WD_CTRL.bit.SOW != 0u)
  {
    PMU->WD_TRIG_SOW.bit.TRIG ^= 1u;
    b_SOWactive = true;
  }
  else
  {
    s8_returnCode = ERR_LOG_CODE_SOW_DISABLED;
  }

  return s8_returnCode;
}
/*******************************************************************************
**                        Private Function Definitions                        **
*******************************************************************************/

/*******************************************************************************
**                       Deprecated Function Definitions                      **
*******************************************************************************/

void PMU_setVDDPUndervoltageWarnIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void PMU_setVDDPOvervoltageIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void PMU_setVDDCUndervoltageWarnIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void PMU_setVDDCOvervoltageIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void PMU_setVDDEXTUndervoltageIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void PMU_setVDDEXTOvertemperatureIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

