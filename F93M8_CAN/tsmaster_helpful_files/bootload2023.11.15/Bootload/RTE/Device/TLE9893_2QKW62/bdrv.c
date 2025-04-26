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

#include "bdrv.h"
#include "adc2.h"
#include "pmu.h"
#include "scu.h"

/*******************************************************************************
**                        Private Constant Declarations                       **
*******************************************************************************/

/*******************************************************************************
**                         Private Macro Declarations                         **
*******************************************************************************/

/**\brief Minimum output voltage VCP vs VSD for a 1-stage charge pump, with ADC2 type 2 attenuator tolerance (+/-400mV) */
#define BDRV_MINCPVOLT_1STAGE (7600u)
/**\brief Minimum output voltage VCP vs VSD for a 2-stage charge pump, with ADC2 type 2 attenuator tolerance (+/-400mV) */
#define BDRV_MINCPVOLT_2STAGE (11300u)

/*******************************************************************************
**                        Private Variable Definitions                        **
*******************************************************************************/

/*******************************************************************************
**                        Private Function Declarations                       **
*******************************************************************************/

static uint8 BDRV_getCPReadyStateCW(void);
static uint8 BDRV_getCPStagesCW(void);

/*******************************************************************************
**                         Private Function Definitions                       **
*******************************************************************************/

/** \brief Check if the Charge Pump needs to be ready to enable the BDRV in the Config Wizard settings
 *
 * \retval 0u, BDRV can be enabled without CP voltage reached
 * \retval 1u, BDRV can only be enabled when CP is ready
 */
static uint8 BDRV_getCPReadyStateCW(void)
{
  return (uint8)((BDRV_CP_CTRL & BDRV_CP_CTRL_CP_RDY_EN_Msk) >> BDRV_CP_CTRL_CP_RDY_EN_Pos);
}
  
/** \brief Get Charge Pump number of stages in the Config Wizard settings
 *
 * \retval 0u, 2 stages
 * \retval 1u, 1 stage
 */
static uint8 BDRV_getCPStagesCW(void)
{
  return (uint8)((BDRV_CP_CTRL & BDRV_CP_CTRL_CP_1STAGE_Msk) >> BDRV_CP_CTRL_CP_1STAGE_Pos);
} 


/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

/** \brief Initialize the Charge Pump in the BDRV module
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 BDRV_initCP(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;

  #if (BDRV_GLOBCONF_EN == 1u)
    s8_returnCode = ERR_LOG_SUCCESS;
  
    BDRV->CP_CTRL.reg = (uint32)BDRV_CP_CTRL;
    BDRV->CP_CLK_CTRL.reg = (uint32)BDRV_CP_CLK_CTRL;
  #endif
  
  return s8_returnCode;
}

/** \brief Initialize all CW registers of the BDRV module
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 BDRV_init(void)
{
  sint8 s8_returnCode;
  sint8 s8_returnCode1;
  sint8 s8_returnCode2;
  uint16 u16_VCP_mV;
  uint16 u16_VSD_mV;
  uint8 u8_stageNb;
  uint16 u16_voltDiff_mV;
  
  s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;
  s8_returnCode1 = ERR_LOG_SUCCESS;
  s8_returnCode2 = ERR_LOG_SUCCESS;
  u16_VCP_mV = 0;
  u16_VSD_mV = 0;
  u16_voltDiff_mV = 0;
  u8_stageNb = 0;
  
  /* Check if ADC2 and BDRV are enabled in the CW */
  #if (BDRV_GLOBCONF_EN == 1) && ((ADC2_GLOBCONF & ADC2_GLOBCONF_EN_Msk) == 1)
    s8_returnCode = ERR_LOG_CODE_SAFE_SHUTDOWN_ACTIVE;
  
    /* Check if the Safe-Shutdown Status is inactive */
    if (PMU_getSafeShutdownSts() == 0)
    {
      s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
      
      /* Wait for CP sufficient voltage */
      if (BDRV_getCPReadyStateCW() == 1u)
      {
        u8_stageNb = BDRV_getCPStagesCW();
        do
        {
          /* ADC2: VSD measurement with Ch1, VCP measurement with Ch3 */
          s8_returnCode1 = ADC2_getChResult_mV(&u16_VSD_mV, ADC2_DCH1);
          s8_returnCode2 = ADC2_getChResult_mV(&u16_VCP_mV, ADC2_DCH3);
          u16_voltDiff_mV = (uint16)(u16_VCP_mV - u16_VSD_mV);
        } 
        while ((((u8_stageNb == 1u) && (u16_voltDiff_mV < BDRV_MINCPVOLT_1STAGE)) || ((u8_stageNb == 0u) && (u16_voltDiff_mV < BDRV_MINCPVOLT_2STAGE))) && s8_returnCode1 == ERR_LOG_SUCCESS && s8_returnCode2 == ERR_LOG_SUCCESS);
      }
      
      if ((s8_returnCode1 == ERR_LOG_SUCCESS) && (s8_returnCode2 == ERR_LOG_SUCCESS))
      {
        s8_returnCode = ERR_LOG_SUCCESS;
        
        /* Clear ADC2 compare unit status bits */
        ADC2->CMPSTATCLR.reg = (uint32)0xFFFFFFFFu;
      
        /* Clear BDRV status bits */
        BDRV->STSCLR.reg = (uint32)0x80333333u;
        
        /* Configure bridge driver register */
        BDRV->CTRL1.reg = (uint32)BDRV_CTRL1;
        BDRV->CTRL2.reg = (uint32)BDRV_CTRL2;
        BDRV->PWMSRCSEL.reg = (uint32)BDRV_PWMSRCSEL;
        BDRV->SEQMAP.reg = (uint32)BDRV_SEQMAP;
        BDRV->PROT_CTRL.reg = (uint32)BDRV_PROT_CTRL;
        BDRV->HB1IGATECLMPC.reg = (uint32)BDRV_HB1IGATECLMPC;
        BDRV->HB2IGATECLMPC.reg = (uint32)BDRV_HB2IGATECLMPC;
        #if (UC_SERIES == 989)
          BDRV->HB3IGATECLMPC.reg = (uint32)BDRV_HB3IGATECLMPC;
        #endif
        BDRV->LS1AFTC.reg = (uint32)BDRV_LS1AFTC;
        BDRV->LS1AFIC.reg = (uint32)BDRV_LS1AFIC;
        BDRV->HS1AFTC.reg = (uint32)BDRV_HS1AFTC;
        BDRV->HS1AFIC.reg = (uint32)BDRV_HS1AFIC;
        BDRV->LS2AFTC.reg = (uint32)BDRV_LS2AFTC;
        BDRV->LS2AFIC.reg = (uint32)BDRV_LS2AFIC;
        BDRV->HS2AFTC.reg = (uint32)BDRV_HS2AFTC;
        BDRV->HS2AFIC.reg = (uint32)BDRV_HS2AFIC;
        BDRV->LS1SEQOFFTC.reg = (uint32)BDRV_LS1SEQOFFTC;
        BDRV->LS1SEQOFFIC.reg = (uint32)BDRV_LS1SEQOFFIC;
        BDRV->HS1SEQOFFTC.reg = (uint32)BDRV_HS1SEQOFFTC;
        BDRV->HS1SEQOFFIC.reg = (uint32)BDRV_HS1SEQOFFIC;
        BDRV->LS2SEQOFFTC.reg = (uint32)BDRV_LS2SEQOFFTC;
        BDRV->LS2SEQOFFIC.reg = (uint32)BDRV_LS2SEQOFFIC;
        BDRV->HS2SEQOFFTC.reg = (uint32)BDRV_HS2SEQOFFTC;
        BDRV->HS2SEQOFFIC.reg = (uint32)BDRV_HS2SEQOFFIC;
        BDRV->LS1SEQONTC.reg = (uint32)BDRV_LS1SEQONTC;
        BDRV->LS1SEQONIC.reg = (uint32)BDRV_LS1SEQONIC;
        BDRV->HS1SEQONTC.reg = (uint32)BDRV_HS1SEQONTC;
        BDRV->HS1SEQONIC.reg = (uint32)BDRV_HS1SEQONIC;
        BDRV->LS2SEQONTC.reg = (uint32)BDRV_LS2SEQONTC;
        BDRV->LS2SEQONIC.reg = (uint32)BDRV_LS2SEQONIC;
        BDRV->HS2SEQONTC.reg = (uint32)BDRV_HS2SEQONTC;
        BDRV->HS2SEQONIC.reg = (uint32)BDRV_HS2SEQONIC;
        BDRV->SEQOFFT4I4.reg = (uint32)BDRV_SEQOFFT4I4;
        BDRV->HCDIS.reg = (uint32)BDRV_HCDIS;
        BDRV->ASEQC.reg = (uint32)BDRV_ASEQC;
        BDRV->ASEQERRCNT.reg = (uint32)BDRV_ASEQERRCNT;
        BDRV->ASEQONTMIN.reg = (uint32)BDRV_ASEQONTMIN;
        BDRV->ASEQONIMIN.reg = (uint32)BDRV_ASEQONIMIN;
        BDRV->ASEQONTMAX.reg = (uint32)BDRV_ASEQONTMAX;
        BDRV->ASEQONIMAX.reg = (uint32)BDRV_ASEQONIMAX;
        BDRV->ASEQOFFTMIN.reg = (uint32)BDRV_ASEQOFFTMIN;
        BDRV->ASEQOFFIMIN.reg = (uint32)BDRV_ASEQOFFIMIN;
        BDRV->ASEQOFFTMAX.reg = (uint32)BDRV_ASEQOFFTMAX;
        BDRV->ASEQOFFIMAX.reg = (uint32)BDRV_ASEQOFFIMAX;
        BDRV->ASEQOFFADDDLY.reg = (uint32)BDRV_ASEQOFFADDDLY;
        #if (UC_SERIES == 989)
          BDRV->LS3AFTC.reg = (uint32)BDRV_LS3AFTC;
          BDRV->LS3AFIC.reg = (uint32)BDRV_LS3AFIC;
          BDRV->HS3AFTC.reg = (uint32)BDRV_HS3AFTC;
          BDRV->HS3AFIC.reg = (uint32)BDRV_HS3AFIC;
          BDRV->LS3SEQOFFTC.reg = (uint32)BDRV_LS3SEQOFFTC;
          BDRV->LS3SEQOFFIC.reg = (uint32)BDRV_LS3SEQOFFIC;
          BDRV->HS3SEQOFFTC.reg = (uint32)BDRV_HS3SEQOFFTC;
          BDRV->HS3SEQOFFIC.reg = (uint32)BDRV_HS3SEQOFFIC;
          BDRV->LS3SEQONTC.reg = (uint32)BDRV_LS3SEQONTC;
          BDRV->LS3SEQONIC.reg = (uint32)BDRV_LS3SEQONIC;
          BDRV->HS3SEQONTC.reg = (uint32)BDRV_HS3SEQONTC;
          BDRV->HS3SEQONIC.reg = (uint32)BDRV_HS3SEQONIC;
        #endif
        
        #if (BEMFC_GLOBCONF_EN == 1)
          BDRV->BEMFC_CTRL.reg = (uint32)BDRV_BEMFC_CTRL;
        #endif
        
        /* Enable bridge driver */
        #if (UC_SERIES == 988)
          s8_returnCode = BDRV_setBridge(BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_en);
        #elif (UC_SERIES == 989)
          s8_returnCode = BDRV_setBridge(BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_en);
        #endif
      }
    }
  #endif

  return s8_returnCode;
}

#if (UC_SERIES == 988)
/** \brief Configure the 2 half-bridges of the device TLE988x
 *
 * \param e_ls1Cfg Configuration of the low-side driver 1
 * \param e_hs1Cfg Configuration of the high-side driver 1
 * \param e_ls2Cfg Configuration of the low-side driver 2
 * \param e_hs2Cfg Configuration of the high-side driver 2
 * \return sint8 0: success, <0: error codes
 */
sint8 BDRV_setBridge(tBDRV_chCfg e_ls1Cfg, tBDRV_chCfg e_hs1Cfg, tBDRV_chCfg e_ls2Cfg, tBDRV_chCfg e_hs2Cfg)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  if ((e_ls1Cfg >= BDRV_chCfg_off) && (e_ls1Cfg <= BDRV_chCfg_on) && (e_hs1Cfg >= BDRV_chCfg_off) && (e_hs1Cfg <= BDRV_chCfg_hsDcs) && (e_ls2Cfg >= BDRV_chCfg_off) && (e_ls2Cfg <= BDRV_chCfg_on) && (e_hs2Cfg >= BDRV_chCfg_off) && (e_hs2Cfg <= BDRV_chCfg_hsDcs))
  {
    /* Side 1 */
    if ((e_ls1Cfg == BDRV_chCfg_off) || (e_hs1Cfg == BDRV_chCfg_off))
    {
      BDRV->CTRL1.bit.HB1_EN = 0u;
      /* Low Side 1 */
      BDRV->CTRL1.bit.LS1_ON = 0u;
      BDRV->CTRL1.bit.LS1_PWM = 0u;
      /* High Side 1 */
      BDRV->CTRL1.bit.HS1_ON = 0u;
      BDRV->CTRL1.bit.HS1_PWM = 0u;
      BDRV->CTRL1.bit.HS1_DCS_EN = 0u;
    }
    else
    {
      BDRV->CTRL1.bit.HB1_EN = 1u;
      /* Bits LS1_ON and HS1_ON must be set to 0 before setting LS1_PWM or HS1_PWM */
      BDRV->CTRL1.bit.LS1_ON = 0u;
      BDRV->CTRL1.bit.HS1_ON = 0u;
      /* Checking if LS1 is in PWM mode */
      if (e_ls1Cfg == BDRV_chCfg_pwm)
      {
        BDRV->CTRL1.bit.LS1_PWM = 1u;
      }
      else
      {
        BDRV->CTRL1.bit.LS1_PWM = 0u;
      }
      /* Checking if HS1 is in PWM mode */
      if (e_hs1Cfg == BDRV_chCfg_pwm)
      {
        BDRV->CTRL1.bit.HS1_PWM = 1u;
      }
      else
      {
        BDRV->CTRL1.bit.HS1_PWM = 0u;
      }
      /* Checking if LS1 is in ON mode */
      if (e_ls1Cfg == BDRV_chCfg_on)
      {
        BDRV->CTRL1.bit.LS1_ON = 1u;
      }
      /* Checking if HS1 is in ON mode */
      if (e_hs1Cfg == BDRV_chCfg_on)
      {
        BDRV->CTRL1.bit.HS1_ON = 1u;
      }
      /* Checking if HS1 is in DCS mode */
      if (e_hs1Cfg == BDRV_chCfg_hsDcs)
      {
        /* Clamping off current must be set to 0 before enabling diagnosis current source */
        BDRV->HB1IGATECLMPC.bit.HB1_ICLMPOFF = 0;
        BDRV->CTRL1.bit.HS1_DCS_EN = 1u;
      }
      else
      {
        BDRV->CTRL1.bit.HS1_DCS_EN = 0u;
      }
    }
    
    /* Side 2 */
    if ((e_ls2Cfg == BDRV_chCfg_off) || (e_hs2Cfg == BDRV_chCfg_off))
    {
      BDRV->CTRL1.bit.HB2_EN = 0u;
      /* Low Side 2 */
      BDRV->CTRL1.bit.LS2_ON = 0u;
      BDRV->CTRL1.bit.LS2_PWM = 0u;
      /* High Side 2 */
      BDRV->CTRL1.bit.HS2_ON = 0u;
      BDRV->CTRL1.bit.HS2_PWM = 0u;
      BDRV->CTRL1.bit.HS2_DCS_EN = 0u;
    }
    else
    {
      BDRV->CTRL1.bit.HB2_EN = 1u;
      /* Bits LS2_ON and HS2_ON must be set to 0 before setting LS2_PWM or HS2_PWM */
      BDRV->CTRL1.bit.LS2_ON = 0u;
      BDRV->CTRL1.bit.HS2_ON = 0u;
      /* Checking if LS2 is in PWM mode */
      if (e_ls2Cfg == BDRV_chCfg_pwm)
      {
        BDRV->CTRL1.bit.LS2_PWM = 1u;
      }
      else
      {
        BDRV->CTRL1.bit.LS2_PWM = 0u;
      }
      /* Checking if HS2 is in PWM mode */
      if (e_hs2Cfg == BDRV_chCfg_pwm)
      {
        BDRV->CTRL1.bit.HS2_PWM = 1u;
      }
      else
      {
        BDRV->CTRL1.bit.HS2_PWM = 0u;
      }
      /* Checking if LS2 is in ON mode */
      if (e_ls2Cfg == BDRV_chCfg_on)
      {
        BDRV->CTRL1.bit.LS2_ON = 1u;
      }
      /* Checking if HS2 is in ON mode */
      if (e_hs2Cfg == BDRV_chCfg_on)
      {
        BDRV->CTRL1.bit.HS2_ON = 1u;
      }
      /* Checking if HS2 is in DCS mode */
      if (e_hs2Cfg == BDRV_chCfg_hsDcs)
      {
        /* Clamping off current must be set to 0 before enabling diagnosis current source */
        BDRV->HB2IGATECLMPC.bit.HB2_ICLMPOFF = 0;
        BDRV->CTRL1.bit.HS2_DCS_EN = 1u;
      }
      else
      {
        BDRV->CTRL1.bit.HS2_DCS_EN = 0u;
      }
    }
  }
  else /* arguments out of range */
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}
#elif (UC_SERIES == 989)
/** \brief Configure the 3 half-bridges of the device TLE989x
 *
 * \param e_ls1Cfg Configuration of the low-side driver 1
 * \param e_hs1Cfg Configuration of the high-side driver 1
 * \param e_ls2Cfg Configuration of the low-side driver 2
 * \param e_hs2Cfg Configuration of the high-side driver 2
 * \param e_ls3Cfg Configuration of the low-side driver 3
 * \param e_hs3Cfg Configuration of the high-side driver 3
 * \return sint8 0: success, <0: error codes
 */
sint8 BDRV_setBridge(tBDRV_chCfg e_ls1Cfg, tBDRV_chCfg e_hs1Cfg, tBDRV_chCfg e_ls2Cfg, tBDRV_chCfg e_hs2Cfg, tBDRV_chCfg e_ls3Cfg, tBDRV_chCfg e_hs3Cfg)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  if ((e_ls1Cfg <= BDRV_chCfg_on) && (e_hs1Cfg <= BDRV_chCfg_hsDcs) && (e_ls2Cfg <= BDRV_chCfg_on) && (e_hs2Cfg <= BDRV_chCfg_hsDcs) && (e_ls3Cfg <= BDRV_chCfg_on) && (e_hs3Cfg <= BDRV_chCfg_hsDcs))
  {
    /* Side 1 */
    if ((e_ls1Cfg == BDRV_chCfg_off) || (e_hs1Cfg == BDRV_chCfg_off))
    {
      BDRV->CTRL1.bit.HB1_EN = 0u;
      /* Low Side 1 */
      BDRV->CTRL1.bit.LS1_ON = 0u;
      BDRV->CTRL1.bit.LS1_PWM = 0u;
      /* High Side 1 */
      BDRV->CTRL1.bit.HS1_ON = 0u;
      BDRV->CTRL1.bit.HS1_PWM = 0u;
      BDRV->CTRL1.bit.HS1_DCS_EN = 0u;
    }
    else
    {
      BDRV->CTRL1.bit.HB1_EN = 1u;
      /* Bits LS1_ON and HS1_ON must be set to 0 before setting LS1_PWM or HS1_PWM */
      BDRV->CTRL1.bit.LS1_ON = 0u;
      BDRV->CTRL1.bit.HS1_ON = 0u;
      /* Checking if LS1 is in PWM mode */
      if (e_ls1Cfg == BDRV_chCfg_pwm)
      {
        BDRV->CTRL1.bit.LS1_PWM = 1u;
      }
      else
      {
        BDRV->CTRL1.bit.LS1_PWM = 0u;
      }
      /* Checking if HS1 is in PWM mode */
      if (e_hs1Cfg == BDRV_chCfg_pwm)
      {
        BDRV->CTRL1.bit.HS1_PWM = 1u;
      }
      else
      {
        BDRV->CTRL1.bit.HS1_PWM = 0u;
      }
      /* Checking if LS1 is in ON mode */
      if (e_ls1Cfg == BDRV_chCfg_on)
      {
        BDRV->CTRL1.bit.LS1_ON = 1u;
      }
      /* Checking if HS1 is in ON mode */
      if (e_hs1Cfg == BDRV_chCfg_on)
      {
        BDRV->CTRL1.bit.HS1_ON = 1u;
      }
      /* Checking if HS1 is in DCS mode */
      if (e_hs1Cfg == BDRV_chCfg_hsDcs)
      {
        /* Clamping off current must be set to 0 before enabling diagnosis current source */
        BDRV->HB1IGATECLMPC.bit.HB1_ICLMPOFF = 0;
        BDRV->CTRL1.bit.HS1_DCS_EN = 1u;
      }
      else
      {
        BDRV->CTRL1.bit.HS1_DCS_EN = 0u;
      }
    }
    
    /* Side 2 */
    if ((e_ls2Cfg == BDRV_chCfg_off) || (e_hs2Cfg == BDRV_chCfg_off))
    {
      BDRV->CTRL1.bit.HB2_EN = 0u;
      /* Low Side 2 */
      BDRV->CTRL1.bit.LS2_ON = 0u;
      BDRV->CTRL1.bit.LS2_PWM = 0u;
      /* High Side 2 */
      BDRV->CTRL1.bit.HS2_ON = 0u;
      BDRV->CTRL1.bit.HS2_PWM = 0u;
      BDRV->CTRL1.bit.HS2_DCS_EN = 0u;
    }
    else
    {
      BDRV->CTRL1.bit.HB2_EN = 1u;
      /* Bits LS2_ON and HS2_ON must be set to 0 before setting LS2_PWM or HS2_PWM */
      BDRV->CTRL1.bit.LS2_ON = 0u;
      BDRV->CTRL1.bit.HS2_ON = 0u;
      /* Checking if LS2 is in PWM mode */
      if (e_ls2Cfg == BDRV_chCfg_pwm)
      {
        BDRV->CTRL1.bit.LS2_PWM = 1u;
      }
      else
      {
        BDRV->CTRL1.bit.LS2_PWM = 0u;
      }
      /* Checking if HS2 is in PWM mode */
      if (e_hs2Cfg == BDRV_chCfg_pwm)
      {
        BDRV->CTRL1.bit.HS2_PWM = 1u;
      }
      else
      {
        BDRV->CTRL1.bit.HS2_PWM = 0u;
      }
      /* Checking if LS2 is in ON mode */
      if (e_ls2Cfg == BDRV_chCfg_on)
      {
        BDRV->CTRL1.bit.LS2_ON = 1u;
      }
      /* Checking if HS2 is in ON mode */
      if (e_hs2Cfg == BDRV_chCfg_on)
      {
        BDRV->CTRL1.bit.HS2_ON = 1u;
      }
      /* Checking if HS2 is in DCS mode */
      if (e_hs2Cfg == BDRV_chCfg_hsDcs)
      {
        /* Clamping off current must be set to 0 before enabling diagnosis current source */
        BDRV->HB2IGATECLMPC.bit.HB2_ICLMPOFF = 0;
        BDRV->CTRL1.bit.HS2_DCS_EN = 1u;
      }
      else
      {
        BDRV->CTRL1.bit.HS2_DCS_EN = 0u;
      }
    }
    
    /* Side 3 */
    if ((e_ls3Cfg == BDRV_chCfg_off) || (e_hs3Cfg == BDRV_chCfg_off))
    {
      BDRV->CTRL1.bit.HB3_EN = 0u;
      /* Low Side 3 */
      BDRV->CTRL1.bit.LS3_ON = 0u;
      BDRV->CTRL1.bit.LS3_PWM = 0u;
      /* High Side 3 */
      BDRV->CTRL1.bit.HS3_ON = 0u;
      BDRV->CTRL1.bit.HS3_PWM = 0u;
      BDRV->CTRL1.bit.HS3_DCS_EN = 0u;
    }
    else
    {
      BDRV->CTRL1.bit.HB3_EN = 1u;
      /* Bits LS3_ON and HS3_ON must be set to 0 before setting LS3_PWM or HS3_PWM */
      BDRV->CTRL1.bit.LS3_ON = 0u;
      BDRV->CTRL1.bit.HS3_ON = 0u;
      /* Checking if LS3 is in PWM mode */
      if (e_ls3Cfg == BDRV_chCfg_pwm)
      {
        BDRV->CTRL1.bit.LS3_PWM = 1u;
      }
      else
      {
        BDRV->CTRL1.bit.LS3_PWM = 0u;
      }
      /* Checking if HS3 is in PWM mode */
      if (e_hs3Cfg == BDRV_chCfg_pwm)
      {
        BDRV->CTRL1.bit.HS3_PWM = 1u;
      }
      else
      {
        BDRV->CTRL1.bit.HS3_PWM = 0u;
      }
      /* Checking if LS3 is in ON mode */
      if (e_ls3Cfg == BDRV_chCfg_on)
      {
        BDRV->CTRL1.bit.LS3_ON = 1u;
      }
      /* Checking if HS3 is in ON mode */
      if (e_hs3Cfg == BDRV_chCfg_on)
      {
        BDRV->CTRL1.bit.HS3_ON = 1u;
      }
      /* Checking if HS3 is in DCS mode */
      if (e_hs3Cfg == BDRV_chCfg_hsDcs)
      {
        /* Clamping off current must be set to 0 before enabling diagnosis current source */
        BDRV->HB3IGATECLMPC.bit.HB3_ICLMPOFF = 0;
        BDRV->CTRL1.bit.HS3_DCS_EN = 1u;
      }
      else
      {
        BDRV->CTRL1.bit.HS3_DCS_EN = 0u;
      }
    }
  }
  else /* arguments out of range */
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}
#endif

/* The following warning is disabled for ARMCC v6 Compiler */
#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6000000)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wcovered-switch-default"
#endif

/** \brief Set low-side charge times and currents for constant mode
 *
 * \param e_hb Selection of the half-bridge (HB1, HB2 or HB3)
 * \param s_constChrgCfg Configuration of the constant mode for charge
 * \return sint8 0: success, <0: error codes
 */
sint8 BDRV_setLSChrgConstMode(tBDRV_hb e_hb, tBDRV_constCfg s_constChrgCfg)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Violation: Relational operator '<=' always evaluates to 'true' [MISRA 2012 Rule 14.3, required] */
  if ((s_constChrgCfg.e_constCurrentAct <= BDRV_currentCfg_350mA) && (s_constChrgCfg.u16_constTimeAct_ns >= (uint16)50) && (s_constChrgCfg.u16_constTimeAct_ns <= (uint16)12800) 
    && (s_constChrgCfg.e_constCurrentFW <= BDRV_currentCfg_350mA) && (s_constChrgCfg.u16_constTimeFW_ns >= (uint16)50) && (s_constChrgCfg.u16_constTimeFW_ns <= (uint16)12800))
  {
    switch(e_hb)
    {
      case BDRV_hb_1:
      {
        BDRV->LS1SEQONTC.bit.LS1_T1ON = (s_constChrgCfg.u16_constTimeAct_ns / 50u) - 1u;
        BDRV->LS1SEQONIC.bit.LS1_I1ON = (uint8)s_constChrgCfg.e_constCurrentAct;
        BDRV->LS1AFTC.bit.LS1_TAFON = (s_constChrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->LS1AFIC.bit.LS1_IAFON = (uint8)s_constChrgCfg.e_constCurrentFW;
        break;
      }
      
      case BDRV_hb_2:
      {
        BDRV->LS2SEQONTC.bit.LS2_T1ON = (s_constChrgCfg.u16_constTimeAct_ns / 50u) - 1u;
        BDRV->LS2SEQONIC.bit.LS2_I1ON = (uint8)s_constChrgCfg.e_constCurrentAct;
        BDRV->LS2AFTC.bit.LS2_TAFON = (s_constChrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->LS2AFIC.bit.LS2_IAFON = (uint8)s_constChrgCfg.e_constCurrentFW;
        break;
      }
      
#if (UC_SERIES == 989)
      case BDRV_hb_3:
      {
        BDRV->LS3SEQONTC.bit.LS3_T1ON = (s_constChrgCfg.u16_constTimeAct_ns / 50u) - 1u;
        BDRV->LS3SEQONIC.bit.LS3_I1ON = (uint8)s_constChrgCfg.e_constCurrentAct;
        BDRV->LS3AFTC.bit.LS3_TAFON = (s_constChrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->LS3AFIC.bit.LS3_IAFON = (uint8)s_constChrgCfg.e_constCurrentFW;
        break;
      }
#endif

      default:
      {
        s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
        break;
      }
    }
  }
  else /* arguments out of range */
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }
  
  return s8_returnCode;
}

/** \brief Set high-side charge times and currents for constant mode
 *
 * \param e_hb Selection of the half-bridge (HB1, HB2 or HB3)
 * \param s_constChrgCfg Configuration of the constant mode for charge
 * \return sint8 0: success, <0: error codes
 */
sint8 BDRV_setHSChrgConstMode(tBDRV_hb e_hb, tBDRV_constCfg s_constChrgCfg)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Violation: Relational operator '<=' always evaluates to 'true' [MISRA 2012 Rule 14.3, required] */
  if ((s_constChrgCfg.e_constCurrentAct <= BDRV_currentCfg_350mA) && (s_constChrgCfg.u16_constTimeAct_ns >= (uint16)50) && (s_constChrgCfg.u16_constTimeAct_ns <= (uint16)12800) 
    && (s_constChrgCfg.e_constCurrentFW <= BDRV_currentCfg_350mA) && (s_constChrgCfg.u16_constTimeFW_ns >= (uint16)50) && (s_constChrgCfg.u16_constTimeFW_ns <= (uint16)12800))
  {
    switch(e_hb)
    {
      case BDRV_hb_1:
      {
        BDRV->HS1SEQONTC.bit.HS1_T1ON = (s_constChrgCfg.u16_constTimeAct_ns / 50u) - 1u;
        BDRV->HS1SEQONIC.bit.HS1_I1ON = (uint8)s_constChrgCfg.e_constCurrentAct;
        BDRV->HS1AFTC.bit.HS1_TAFON = (s_constChrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->HS1AFIC.bit.HS1_IAFON = (uint8)s_constChrgCfg.e_constCurrentFW;
        break;
      }
      
      case BDRV_hb_2:
      {
        BDRV->HS2SEQONTC.bit.HS2_T1ON = (s_constChrgCfg.u16_constTimeAct_ns / 50u) - 1u;
        BDRV->HS2SEQONIC.bit.HS2_I1ON = (uint8)s_constChrgCfg.e_constCurrentAct;
        BDRV->HS2AFTC.bit.HS2_TAFON = (s_constChrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->HS2AFIC.bit.HS2_IAFON = (uint8)s_constChrgCfg.e_constCurrentFW;
        break;
      }
      
#if (UC_SERIES == 989)
      case BDRV_hb_3:
      {
        BDRV->HS3SEQONTC.bit.HS3_T1ON = (s_constChrgCfg.u16_constTimeAct_ns / 50u) - 1u;
        BDRV->HS3SEQONIC.bit.HS3_I1ON = (uint8)s_constChrgCfg.e_constCurrentAct;
        BDRV->HS3AFTC.bit.HS3_TAFON = (s_constChrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->HS3AFIC.bit.HS3_IAFON = (uint8)s_constChrgCfg.e_constCurrentFW;
        break;
      }
#endif

      default:
      {
        s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
        break;
      }
    }
  }
  else /* arguments out of range */
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }
  
  return s8_returnCode;
}

/** \brief Set low-side discharge times and currents for constant mode
 *
 * \param e_hb Selection of the half-bridge (HB1, HB2 or HB3)
 * \param s_constDischrgCfg Configuration of the constant mode for discharge
 * \return sint8 0: success, <0: error codes
 */
sint8 BDRV_setLSDischrgConstMode(tBDRV_hb e_hb, tBDRV_constCfg s_constDischrgCfg)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Violation: Relational operator '<=' always evaluates to 'true' [MISRA 2012 Rule 14.3, required] */
  if ((s_constDischrgCfg.e_constCurrentAct <= BDRV_currentCfg_350mA) && (s_constDischrgCfg.u16_constTimeAct_ns >= (uint16)50) && (s_constDischrgCfg.u16_constTimeAct_ns <= (uint16)12800) 
    && (s_constDischrgCfg.e_constCurrentFW <= BDRV_currentCfg_350mA) && (s_constDischrgCfg.u16_constTimeFW_ns >= (uint16)50) && (s_constDischrgCfg.u16_constTimeFW_ns <= (uint16)12800))
  {
    switch(e_hb)
    {
      case BDRV_hb_1:
      {
        BDRV->LS1SEQOFFTC.bit.LS1_T1OFF = (s_constDischrgCfg.u16_constTimeAct_ns / 50u) - 1u;
        BDRV->LS1SEQOFFIC.bit.LS1_I1OFF = (uint8)s_constDischrgCfg.e_constCurrentAct;
        BDRV->LS1AFTC.bit.LS1_TAFOFF = (s_constDischrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->LS1AFIC.bit.LS1_IAFOFF = (uint8)s_constDischrgCfg.e_constCurrentFW;
        break;
      }
      
      case BDRV_hb_2:
      {
        BDRV->LS2SEQOFFTC.bit.LS2_T1OFF = (s_constDischrgCfg.u16_constTimeAct_ns / 50u) - 1u;
        BDRV->LS2SEQOFFIC.bit.LS2_I1OFF = (uint8)s_constDischrgCfg.e_constCurrentAct;
        BDRV->LS2AFTC.bit.LS2_TAFOFF = (s_constDischrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->LS2AFIC.bit.LS2_IAFOFF = (uint8)s_constDischrgCfg.e_constCurrentFW;
        break;
      }
      
#if (UC_SERIES == 989)
      case BDRV_hb_3:
      {
        BDRV->LS3SEQOFFTC.bit.LS3_T1OFF = (s_constDischrgCfg.u16_constTimeAct_ns / 50u) - 1u;
        BDRV->LS3SEQOFFIC.bit.LS3_I1OFF = (uint8)s_constDischrgCfg.e_constCurrentAct;
        BDRV->LS3AFTC.bit.LS3_TAFOFF = (s_constDischrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->LS3AFIC.bit.LS3_IAFOFF = (uint8)s_constDischrgCfg.e_constCurrentFW;
        break;
      }
#endif

      default:
      {
        s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
        break;
      }
    }
  }
  else /* arguments out of range */
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }
  
  return s8_returnCode;
}

/** \brief Set high-side discharge times and currents for constant mode
 *
 * \param e_hb Selection of the half-bridge (HB1, HB2 or HB3)
 * \param s_constDischrgCfg Configuration of the constant mode for discharge
 * \return sint8 0: success, <0: error codes
 */
sint8 BDRV_setHSDischrgConstMode(tBDRV_hb e_hb, tBDRV_constCfg s_constDischrgCfg)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Violation: Relational operator '<=' always evaluates to 'true' [MISRA 2012 Rule 14.3, required] */
  if ((s_constDischrgCfg.e_constCurrentAct <= BDRV_currentCfg_350mA) && (s_constDischrgCfg.u16_constTimeAct_ns >= (uint16)50) && (s_constDischrgCfg.u16_constTimeAct_ns <= (uint16)12800) 
    && (s_constDischrgCfg.e_constCurrentFW <= BDRV_currentCfg_350mA) && (s_constDischrgCfg.u16_constTimeFW_ns >= (uint16)50) && (s_constDischrgCfg.u16_constTimeFW_ns <= (uint16)12800))
  {
    switch(e_hb)
    {
      case BDRV_hb_1:
      {
        BDRV->HS1SEQOFFTC.bit.HS1_T1OFF = (s_constDischrgCfg.u16_constTimeAct_ns / 50u) - 1u;
        BDRV->HS1SEQOFFIC.bit.HS1_I1OFF = (uint8)s_constDischrgCfg.e_constCurrentAct;
        BDRV->HS1AFTC.bit.HS1_TAFOFF = (s_constDischrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->HS1AFIC.bit.HS1_IAFOFF = (uint8)s_constDischrgCfg.e_constCurrentFW;
        break;
      }
      
      case BDRV_hb_2:
      {
        BDRV->HS2SEQOFFTC.bit.HS2_T1OFF = (s_constDischrgCfg.u16_constTimeAct_ns / 50u) - 1u;
        BDRV->HS2SEQOFFIC.bit.HS2_I1OFF = (uint8)s_constDischrgCfg.e_constCurrentAct;
        BDRV->HS2AFTC.bit.HS2_TAFOFF = (s_constDischrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->HS2AFIC.bit.HS2_IAFOFF = (uint8)s_constDischrgCfg.e_constCurrentFW;
        break;
      }
      
#if (UC_SERIES == 989)
      case BDRV_hb_3:
      {
        BDRV->HS3SEQOFFTC.bit.HS3_T1OFF = (s_constDischrgCfg.u16_constTimeAct_ns / 50u) - 1u;
        BDRV->HS3SEQOFFIC.bit.HS3_I1OFF = (uint8)s_constDischrgCfg.e_constCurrentAct;
        BDRV->HS3AFTC.bit.HS3_TAFOFF = (s_constDischrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->HS3AFIC.bit.HS3_IAFOFF = (uint8)s_constDischrgCfg.e_constCurrentFW;
        break;
      }
#endif

      default:
      {
        s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
        break;
      }
    }
  }
  else /* arguments out of range */
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }
  
  return s8_returnCode;
}

/* Disable MISRA rule Note 9031 manually for the functions BDRV_setLSChrgSeqMode, 
   BDRV_setHSChrgSeqMode, BDRV_setLSDischrgSeqMode, BDRV_setHSDischrgSeqMode */
//lint -e9031
/** \brief Set low-side charge times and currents for sequencer mode
 *
 * \param e_hb Selection of the half-bridge (HB1, HB2 or HB3)
 * \param s_seqChrgCfg Configuration of the sequencer mode for charge
 * \return sint8 0: success, <0: error codes
 */
sint8 BDRV_setLSChrgSeqMode(tBDRV_hb e_hb, tBDRV_seqCfg s_seqChrgCfg)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Violation: Relational operator '<=' always evaluates to 'true' [MISRA 2012 Rule 14.3, required] */
  if ((s_seqChrgCfg.e_seqPhase1CurrentAct <= BDRV_currentCfg_350mA)
      && (s_seqChrgCfg.e_seqPhase2CurrentAct <= BDRV_currentCfg_350mA)
      && (s_seqChrgCfg.e_seqPhase3CurrentAct <= BDRV_currentCfg_350mA)
      && (s_seqChrgCfg.e_seqPhase4CurrentAct <= BDRV_currentCfg_350mA)
      && (s_seqChrgCfg.u16_seqPhase1TimeAct_ns >= (uint16)50) && (s_seqChrgCfg.u16_seqPhase1TimeAct_ns <= (uint16)3200)
      && (s_seqChrgCfg.u16_seqPhase2TimeAct_ns >= (uint16)50) && (s_seqChrgCfg.u16_seqPhase2TimeAct_ns <= (uint16)3200)
      && (s_seqChrgCfg.u16_seqPhase3TimeAct_ns >= (uint16)50) && (s_seqChrgCfg.u16_seqPhase3TimeAct_ns <= (uint16)3200)
      && (s_seqChrgCfg.u16_seqPhase4TimeAct_ns >= (uint16)50) && (s_seqChrgCfg.u16_seqPhase4TimeAct_ns <= (uint16)3200)
      && (s_seqChrgCfg.e_constCurrentFW <= BDRV_currentCfg_350mA)
      && (s_seqChrgCfg.u16_constTimeFW_ns >= (uint16)50) && (s_seqChrgCfg.u16_constTimeFW_ns <= (uint16)12800))
  {
    switch(e_hb)
    {
      case BDRV_hb_1:
      {
        BDRV->LS1SEQONTC.bit.LS1_T1ON = (uint8)((s_seqChrgCfg.u16_seqPhase1TimeAct_ns / 50u) - 1u);
        BDRV->LS1SEQONTC.bit.LS1_T2ON = (uint8)((s_seqChrgCfg.u16_seqPhase2TimeAct_ns / 50u) - 1u);
        BDRV->LS1SEQONTC.bit.LS1_T3ON = (uint8)((s_seqChrgCfg.u16_seqPhase3TimeAct_ns / 50u) - 1u);
        BDRV->LS1SEQONTC.bit.LS1_T4ON = (uint8)((s_seqChrgCfg.u16_seqPhase4TimeAct_ns / 50u) - 1u);
        BDRV->LS1SEQONIC.bit.LS1_I1ON = (uint8)s_seqChrgCfg.e_seqPhase1CurrentAct;
        BDRV->LS1SEQONIC.bit.LS1_I2ON = (uint8)s_seqChrgCfg.e_seqPhase2CurrentAct;
        BDRV->LS1SEQONIC.bit.LS1_I3ON = (uint8)s_seqChrgCfg.e_seqPhase3CurrentAct;
        BDRV->LS1SEQONIC.bit.LS1_I4ON = (uint8)s_seqChrgCfg.e_seqPhase4CurrentAct;
        BDRV->LS1AFTC.bit.LS1_TAFON = (s_seqChrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->LS1AFIC.bit.LS1_IAFON = (uint8)s_seqChrgCfg.e_constCurrentFW;
        break;
      }
      
      case BDRV_hb_2:
      {
        BDRV->LS2SEQONTC.bit.LS2_T1ON = (uint8)((s_seqChrgCfg.u16_seqPhase1TimeAct_ns / 50u) - 1u);
        BDRV->LS2SEQONTC.bit.LS2_T2ON = (uint8)((s_seqChrgCfg.u16_seqPhase2TimeAct_ns / 50u) - 1u);
        BDRV->LS2SEQONTC.bit.LS2_T3ON = (uint8)((s_seqChrgCfg.u16_seqPhase3TimeAct_ns / 50u) - 1u);
        BDRV->LS2SEQONTC.bit.LS2_T4ON = (uint8)((s_seqChrgCfg.u16_seqPhase4TimeAct_ns / 50u) - 1u);
        BDRV->LS2SEQONIC.bit.LS2_I1ON = (uint8)s_seqChrgCfg.e_seqPhase1CurrentAct;
        BDRV->LS2SEQONIC.bit.LS2_I2ON = (uint8)s_seqChrgCfg.e_seqPhase2CurrentAct;
        BDRV->LS2SEQONIC.bit.LS2_I3ON = (uint8)s_seqChrgCfg.e_seqPhase3CurrentAct;
        BDRV->LS2SEQONIC.bit.LS2_I4ON = (uint8)s_seqChrgCfg.e_seqPhase4CurrentAct;
        BDRV->LS2AFTC.bit.LS2_TAFON = (s_seqChrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->LS2AFIC.bit.LS2_IAFON = (uint8)s_seqChrgCfg.e_constCurrentFW;
        break;
      }

#if (UC_SERIES == 989)
      case BDRV_hb_3:
      {
        BDRV->LS3SEQONTC.bit.LS3_T1ON = (uint8)((s_seqChrgCfg.u16_seqPhase1TimeAct_ns / 50u) - 1u);
        BDRV->LS3SEQONTC.bit.LS3_T2ON = (uint8)((s_seqChrgCfg.u16_seqPhase2TimeAct_ns / 50u) - 1u);
        BDRV->LS3SEQONTC.bit.LS3_T3ON = (uint8)((s_seqChrgCfg.u16_seqPhase3TimeAct_ns / 50u) - 1u);
        BDRV->LS3SEQONTC.bit.LS3_T4ON = (uint8)((s_seqChrgCfg.u16_seqPhase4TimeAct_ns / 50u) - 1u);
        BDRV->LS3SEQONIC.bit.LS3_I1ON = (uint8)s_seqChrgCfg.e_seqPhase1CurrentAct;
        BDRV->LS3SEQONIC.bit.LS3_I2ON = (uint8)s_seqChrgCfg.e_seqPhase2CurrentAct;
        BDRV->LS3SEQONIC.bit.LS3_I3ON = (uint8)s_seqChrgCfg.e_seqPhase3CurrentAct;
        BDRV->LS3SEQONIC.bit.LS3_I4ON = (uint8)s_seqChrgCfg.e_seqPhase4CurrentAct;
        BDRV->LS3AFTC.bit.LS3_TAFON = (s_seqChrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->LS3AFIC.bit.LS3_IAFON = (uint8)s_seqChrgCfg.e_constCurrentFW;
        break;
      }
#endif

      default:
      {
        s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
        break;
      }
    }
  }
  else /* arguments out of range */
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}

/** \brief Set high-side charge times and currents for sequencer mode
 *
 * \param e_hb Selection of the half-bridge (HB1, HB2 or HB3)
 * \param s_seqChrgCfg Configuration of the sequencer mode for charge
 * \return sint8 0: success, <0: error codes
 */
sint8 BDRV_setHSChrgSeqMode(tBDRV_hb e_hb, tBDRV_seqCfg s_seqChrgCfg)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Violation: Relational operator '<=' always evaluates to 'true' [MISRA 2012 Rule 14.3, required] */
  if ((s_seqChrgCfg.e_seqPhase1CurrentAct <= BDRV_currentCfg_350mA)
      && (s_seqChrgCfg.e_seqPhase2CurrentAct <= BDRV_currentCfg_350mA)
      && (s_seqChrgCfg.e_seqPhase3CurrentAct <= BDRV_currentCfg_350mA)
      && (s_seqChrgCfg.e_seqPhase4CurrentAct <= BDRV_currentCfg_350mA)
      && (s_seqChrgCfg.u16_seqPhase1TimeAct_ns >= (uint16)50) && (s_seqChrgCfg.u16_seqPhase1TimeAct_ns <= (uint16)3200)
      && (s_seqChrgCfg.u16_seqPhase2TimeAct_ns >= (uint16)50) && (s_seqChrgCfg.u16_seqPhase2TimeAct_ns <= (uint16)3200)
      && (s_seqChrgCfg.u16_seqPhase3TimeAct_ns >= (uint16)50) && (s_seqChrgCfg.u16_seqPhase3TimeAct_ns <= (uint16)3200)
      && (s_seqChrgCfg.u16_seqPhase4TimeAct_ns >= (uint16)50) && (s_seqChrgCfg.u16_seqPhase4TimeAct_ns <= (uint16)3200)
      && (s_seqChrgCfg.e_constCurrentFW <= BDRV_currentCfg_350mA) && (s_seqChrgCfg.u16_constTimeFW_ns >= (uint16)50) 
      && (s_seqChrgCfg.u16_constTimeFW_ns <= (uint16)12800))
  {
    switch(e_hb)
    {
      case BDRV_hb_1:
      {
        BDRV->HS1SEQONTC.bit.HS1_T1ON = (uint8)((s_seqChrgCfg.u16_seqPhase1TimeAct_ns / 50u) - 1u);
        BDRV->HS1SEQONTC.bit.HS1_T2ON = (uint8)((s_seqChrgCfg.u16_seqPhase2TimeAct_ns / 50u) - 1u);
        BDRV->HS1SEQONTC.bit.HS1_T3ON = (uint8)((s_seqChrgCfg.u16_seqPhase3TimeAct_ns / 50u) - 1u);
        BDRV->HS1SEQONTC.bit.HS1_T4ON = (uint8)((s_seqChrgCfg.u16_seqPhase4TimeAct_ns / 50u) - 1u);
        BDRV->HS1SEQONIC.bit.HS1_I1ON = (uint8)s_seqChrgCfg.e_seqPhase1CurrentAct;
        BDRV->HS1SEQONIC.bit.HS1_I2ON = (uint8)s_seqChrgCfg.e_seqPhase2CurrentAct;
        BDRV->HS1SEQONIC.bit.HS1_I3ON = (uint8)s_seqChrgCfg.e_seqPhase3CurrentAct;
        BDRV->HS1SEQONIC.bit.HS1_I4ON = (uint8)s_seqChrgCfg.e_seqPhase4CurrentAct;
        BDRV->HS1AFTC.bit.HS1_TAFON = (s_seqChrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->HS1AFIC.bit.HS1_IAFON = (uint8)s_seqChrgCfg.e_constCurrentFW;
        break;
      }
      
      case BDRV_hb_2:
      {
        BDRV->HS2SEQONTC.bit.HS2_T1ON = (uint8)((s_seqChrgCfg.u16_seqPhase1TimeAct_ns / 50u) - 1u);
        BDRV->HS2SEQONTC.bit.HS2_T2ON = (uint8)((s_seqChrgCfg.u16_seqPhase2TimeAct_ns / 50u) - 1u);
        BDRV->HS2SEQONTC.bit.HS2_T3ON = (uint8)((s_seqChrgCfg.u16_seqPhase3TimeAct_ns / 50u) - 1u);
        BDRV->HS2SEQONTC.bit.HS2_T4ON = (uint8)((s_seqChrgCfg.u16_seqPhase4TimeAct_ns / 50u) - 1u);
        BDRV->HS2SEQONIC.bit.HS2_I1ON = (uint8)s_seqChrgCfg.e_seqPhase1CurrentAct;
        BDRV->HS2SEQONIC.bit.HS2_I2ON = (uint8)s_seqChrgCfg.e_seqPhase2CurrentAct;
        BDRV->HS2SEQONIC.bit.HS2_I3ON = (uint8)s_seqChrgCfg.e_seqPhase3CurrentAct;
        BDRV->HS2SEQONIC.bit.HS2_I4ON = (uint8)s_seqChrgCfg.e_seqPhase4CurrentAct;
        BDRV->HS2AFTC.bit.HS2_TAFON = (s_seqChrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->HS2AFIC.bit.HS2_IAFON = (uint8)s_seqChrgCfg.e_constCurrentFW;
        break;
      }

#if (UC_SERIES == 989)
      case BDRV_hb_3:
      {
        BDRV->HS3SEQONTC.bit.HS3_T1ON = (uint8)((s_seqChrgCfg.u16_seqPhase1TimeAct_ns / 50u) - 1u);
        BDRV->HS3SEQONTC.bit.HS3_T2ON = (uint8)((s_seqChrgCfg.u16_seqPhase2TimeAct_ns / 50u) - 1u);
        BDRV->HS3SEQONTC.bit.HS3_T3ON = (uint8)((s_seqChrgCfg.u16_seqPhase3TimeAct_ns / 50u) - 1u);
        BDRV->HS3SEQONTC.bit.HS3_T4ON = (uint8)((s_seqChrgCfg.u16_seqPhase4TimeAct_ns / 50u) - 1u);
        BDRV->HS3SEQONIC.bit.HS3_I1ON = (uint8)s_seqChrgCfg.e_seqPhase1CurrentAct;
        BDRV->HS3SEQONIC.bit.HS3_I2ON = (uint8)s_seqChrgCfg.e_seqPhase2CurrentAct;
        BDRV->HS3SEQONIC.bit.HS3_I3ON = (uint8)s_seqChrgCfg.e_seqPhase3CurrentAct;
        BDRV->HS3SEQONIC.bit.HS3_I4ON = (uint8)s_seqChrgCfg.e_seqPhase4CurrentAct;
        BDRV->HS3AFTC.bit.HS3_TAFON = (s_seqChrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->HS3AFIC.bit.HS3_IAFON = (uint8)s_seqChrgCfg.e_constCurrentFW;
        break;
      }
#endif

      default:
      {
        s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
        break;
      }
    }
  }
  else /* arguments out of range */
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}

/** \brief Set low-side discharge times and currents for sequencer mode
 *
 * \param e_hb Selection of the half-bridge (HB1, HB2 or HB3)
 * \param s_seqDischrgCfg Configuration of the sequencer mode for discharge
 * \return sint8 0: success, <0: error codes
 */
sint8 BDRV_setLSDischrgSeqMode(tBDRV_hb e_hb, tBDRV_seqCfg s_seqDischrgCfg)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Violation: Relational operator '<=' always evaluates to 'true' [MISRA 2012 Rule 14.3, required] */
  if ((s_seqDischrgCfg.e_seqPhase1CurrentAct <= BDRV_currentCfg_350mA)
      && (s_seqDischrgCfg.e_seqPhase2CurrentAct <= BDRV_currentCfg_350mA)
      && (s_seqDischrgCfg.e_seqPhase3CurrentAct <= BDRV_currentCfg_350mA)
      && (s_seqDischrgCfg.u16_seqPhase1TimeAct_ns >= (uint16)50) && (s_seqDischrgCfg.u16_seqPhase1TimeAct_ns <= (uint16)3200)
      && (s_seqDischrgCfg.u16_seqPhase2TimeAct_ns >= (uint16)50) && (s_seqDischrgCfg.u16_seqPhase2TimeAct_ns <= (uint16)3200)
      && (s_seqDischrgCfg.u16_seqPhase3TimeAct_ns >= (uint16)50) && (s_seqDischrgCfg.u16_seqPhase3TimeAct_ns <= (uint16)3200)
      && (s_seqDischrgCfg.e_constCurrentFW <= BDRV_currentCfg_350mA) && (s_seqDischrgCfg.u16_constTimeFW_ns >= (uint16)50) 
      && (s_seqDischrgCfg.u16_constTimeFW_ns <= (uint16)12800))
  {
    switch(e_hb)
    {
      case BDRV_hb_1:
      {
        BDRV->LS1SEQOFFTC.bit.LS1_T1OFF = (uint8)((s_seqDischrgCfg.u16_seqPhase1TimeAct_ns / 50u) - 1u);
        BDRV->LS1SEQOFFTC.bit.LS1_T2OFF = (uint8)((s_seqDischrgCfg.u16_seqPhase2TimeAct_ns / 50u) - 1u);
        BDRV->LS1SEQOFFTC.bit.LS1_T3OFF = (uint8)((s_seqDischrgCfg.u16_seqPhase3TimeAct_ns / 50u) - 1u);
        BDRV->LS1SEQOFFIC.bit.LS1_I1OFF = (uint8)s_seqDischrgCfg.e_seqPhase1CurrentAct;
        BDRV->LS1SEQOFFIC.bit.LS1_I2OFF = (uint8)s_seqDischrgCfg.e_seqPhase2CurrentAct;
        BDRV->LS1SEQOFFIC.bit.LS1_I3OFF = (uint8)s_seqDischrgCfg.e_seqPhase3CurrentAct;
        BDRV->LS1AFTC.bit.LS1_TAFOFF = (s_seqDischrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->LS1AFIC.bit.LS1_IAFOFF = (uint8)s_seqDischrgCfg.e_constCurrentFW;
        break;
      }
      
      case BDRV_hb_2:
      {
        BDRV->LS2SEQOFFTC.bit.LS2_T1OFF = (uint8)((s_seqDischrgCfg.u16_seqPhase1TimeAct_ns / 50u) - 1u);
        BDRV->LS2SEQOFFTC.bit.LS2_T2OFF = (uint8)((s_seqDischrgCfg.u16_seqPhase2TimeAct_ns / 50u) - 1u);
        BDRV->LS2SEQOFFTC.bit.LS2_T3OFF = (uint8)((s_seqDischrgCfg.u16_seqPhase3TimeAct_ns / 50u) - 1u);
        BDRV->LS2SEQOFFIC.bit.LS2_I1OFF = (uint8)s_seqDischrgCfg.e_seqPhase1CurrentAct;
        BDRV->LS2SEQOFFIC.bit.LS2_I2OFF = (uint8)s_seqDischrgCfg.e_seqPhase2CurrentAct;
        BDRV->LS2SEQOFFIC.bit.LS2_I3OFF = (uint8)s_seqDischrgCfg.e_seqPhase3CurrentAct;
        BDRV->LS2AFTC.bit.LS2_TAFOFF = (s_seqDischrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->LS2AFIC.bit.LS2_IAFOFF = (uint8)s_seqDischrgCfg.e_constCurrentFW;
        break;
      }

#if (UC_SERIES == 989)
      case BDRV_hb_3:
      {
        BDRV->LS3SEQOFFTC.bit.LS3_T1OFF = (uint8)((s_seqDischrgCfg.u16_seqPhase1TimeAct_ns / 50u) - 1u);
        BDRV->LS3SEQOFFTC.bit.LS3_T2OFF = (uint8)((s_seqDischrgCfg.u16_seqPhase2TimeAct_ns / 50u) - 1u);
        BDRV->LS3SEQOFFTC.bit.LS3_T3OFF = (uint8)((s_seqDischrgCfg.u16_seqPhase3TimeAct_ns / 50u) - 1u);
        BDRV->LS3SEQOFFIC.bit.LS3_I1OFF = (uint8)s_seqDischrgCfg.e_seqPhase1CurrentAct;
        BDRV->LS3SEQOFFIC.bit.LS3_I2OFF = (uint8)s_seqDischrgCfg.e_seqPhase2CurrentAct;
        BDRV->LS3SEQOFFIC.bit.LS3_I3OFF = (uint8)s_seqDischrgCfg.e_seqPhase3CurrentAct;
        BDRV->LS3AFTC.bit.LS3_TAFOFF = (s_seqDischrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->LS3AFIC.bit.LS3_IAFOFF = (uint8)s_seqDischrgCfg.e_constCurrentFW;
        break;
      }
#endif

      default:
      {
        s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
        break;
      }
    }
  }
  else /* arguments out of range */
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}

/** \brief Set high-side discharge times and currents for sequencer mode
 *
 * \param e_hb Selection of the half-bridge (HB1, HB2 or HB3)
 * \param s_seqDischrgCfg Configuration of the sequencer mode for discharge
 * \return sint8 0: success, <0: error codes
 */
sint8 BDRV_setHSDischrgSeqMode(tBDRV_hb e_hb, tBDRV_seqCfg s_seqDischrgCfg)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Violation: Relational operator '<=' always evaluates to 'true' [MISRA 2012 Rule 14.3, required] */
  if ((s_seqDischrgCfg.e_seqPhase1CurrentAct <= BDRV_currentCfg_350mA)
      && (s_seqDischrgCfg.e_seqPhase2CurrentAct <= BDRV_currentCfg_350mA)
      && (s_seqDischrgCfg.e_seqPhase3CurrentAct <= BDRV_currentCfg_350mA)
      && (s_seqDischrgCfg.u16_seqPhase1TimeAct_ns >= (uint16)50) && (s_seqDischrgCfg.u16_seqPhase1TimeAct_ns <= (uint16)3200)
      && (s_seqDischrgCfg.u16_seqPhase2TimeAct_ns >= (uint16)50) && (s_seqDischrgCfg.u16_seqPhase2TimeAct_ns <= (uint16)3200)
      && (s_seqDischrgCfg.u16_seqPhase3TimeAct_ns >= (uint16)50) && (s_seqDischrgCfg.u16_seqPhase3TimeAct_ns <= (uint16)3200)
      && (s_seqDischrgCfg.e_constCurrentFW <= BDRV_currentCfg_350mA) && (s_seqDischrgCfg.u16_constTimeFW_ns >= (uint16)50)
      && (s_seqDischrgCfg.u16_constTimeFW_ns <= (uint16)12800))
  {
    switch(e_hb)
    {
      case BDRV_hb_1:
      {
        BDRV->HS1SEQOFFTC.bit.HS1_T1OFF = (uint8)((s_seqDischrgCfg.u16_seqPhase1TimeAct_ns / 50u) - 1u);
        BDRV->HS1SEQOFFTC.bit.HS1_T2OFF = (uint8)((s_seqDischrgCfg.u16_seqPhase2TimeAct_ns / 50u) - 1u);
        BDRV->HS1SEQOFFTC.bit.HS1_T3OFF = (uint8)((s_seqDischrgCfg.u16_seqPhase3TimeAct_ns / 50u) - 1u);
        BDRV->HS1SEQOFFIC.bit.HS1_I1OFF = (uint8)s_seqDischrgCfg.e_seqPhase1CurrentAct;
        BDRV->HS1SEQOFFIC.bit.HS1_I2OFF = (uint8)s_seqDischrgCfg.e_seqPhase2CurrentAct;
        BDRV->HS1SEQOFFIC.bit.HS1_I3OFF = (uint8)s_seqDischrgCfg.e_seqPhase3CurrentAct;
        BDRV->HS1AFTC.bit.HS1_TAFOFF = (s_seqDischrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->HS1AFIC.bit.HS1_IAFOFF = (uint8)s_seqDischrgCfg.e_constCurrentFW;
        break;
      }
      
      case BDRV_hb_2:
      {
        BDRV->HS2SEQOFFTC.bit.HS2_T1OFF = (uint8)((s_seqDischrgCfg.u16_seqPhase1TimeAct_ns / 50u) - 1u);
        BDRV->HS2SEQOFFTC.bit.HS2_T2OFF = (uint8)((s_seqDischrgCfg.u16_seqPhase2TimeAct_ns / 50u) - 1u);
        BDRV->HS2SEQOFFTC.bit.HS2_T3OFF = (uint8)((s_seqDischrgCfg.u16_seqPhase3TimeAct_ns / 50u) - 1u);
        BDRV->HS2SEQOFFIC.bit.HS2_I1OFF = (uint8)s_seqDischrgCfg.e_seqPhase1CurrentAct;
        BDRV->HS2SEQOFFIC.bit.HS2_I2OFF = (uint8)s_seqDischrgCfg.e_seqPhase2CurrentAct;
        BDRV->HS2SEQOFFIC.bit.HS2_I3OFF = (uint8)s_seqDischrgCfg.e_seqPhase3CurrentAct;
        BDRV->HS2AFTC.bit.HS2_TAFOFF = (s_seqDischrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->HS2AFIC.bit.HS2_IAFOFF = (uint8)s_seqDischrgCfg.e_constCurrentFW;
        break;
      }

#if (UC_SERIES == 989)
      case BDRV_hb_3:
      {
        BDRV->HS3SEQOFFTC.bit.HS3_T1OFF = (uint8)((s_seqDischrgCfg.u16_seqPhase1TimeAct_ns / 50u) - 1u);
        BDRV->HS3SEQOFFTC.bit.HS3_T2OFF = (uint8)((s_seqDischrgCfg.u16_seqPhase2TimeAct_ns / 50u) - 1u);
        BDRV->HS3SEQOFFTC.bit.HS3_T3OFF = (uint8)((s_seqDischrgCfg.u16_seqPhase3TimeAct_ns / 50u) - 1u);
        BDRV->HS3SEQOFFIC.bit.HS3_I1OFF = (uint8)s_seqDischrgCfg.e_seqPhase1CurrentAct;
        BDRV->HS3SEQOFFIC.bit.HS3_I2OFF = (uint8)s_seqDischrgCfg.e_seqPhase2CurrentAct;
        BDRV->HS3SEQOFFIC.bit.HS3_I3OFF = (uint8)s_seqDischrgCfg.e_seqPhase3CurrentAct;
        BDRV->HS3AFTC.bit.HS3_TAFOFF = (s_seqDischrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->HS3AFIC.bit.HS3_IAFOFF = (uint8)s_seqDischrgCfg.e_constCurrentFW;
        break;
      }
#endif

      default:
      {
        s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
        break;
      }
    }
  }
  else /* arguments out of range */
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}
//lint +e9031
#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6000000)
  #pragma clang diagnostic pop
#endif

/** \brief Set adaptive sequencer for charge
 *
 * \param s_aseqChrgCfg Configuration of the adaptive sequencer mode for charge
 * \return sint8 0: success, <0: error codes
 */
sint8 BDRV_setChrgAdaptSeqMode(tBDRV_aseqCfg s_aseqChrgCfg)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Violation: Relational operator '<=' always evaluates to 'true' [MISRA 2012 Rule 14.3, required] */
  if ((s_aseqChrgCfg.e_aseqMinCurrent <= BDRV_currentCfg_350mA)
      && (s_aseqChrgCfg.e_aseqMaxCurrent <= BDRV_currentCfg_350mA)
      && (s_aseqChrgCfg.u16_aseqMinTime_ns >= (uint16)50) && (s_aseqChrgCfg.u16_aseqMinTime_ns <= (uint16)12800)
      && (s_aseqChrgCfg.u16_aseqMaxTime_ns >= (uint16)50) && (s_aseqChrgCfg.u16_aseqMaxTime_ns <= (uint16)12800))
  {
    BDRV->ASEQONTMIN.bit.T12ONMIN = (s_aseqChrgCfg.u16_aseqMinTime_ns / 50u) - 1u;
    BDRV->ASEQONTMAX.bit.T12ONMAX = (s_aseqChrgCfg.u16_aseqMaxTime_ns / 50u) - 1u;
    BDRV->ASEQONIMIN.bit.I1ONMIN = (uint8)s_aseqChrgCfg.e_aseqMinCurrent;
    BDRV->ASEQONIMAX.bit.I1ONMAX = (uint8)s_aseqChrgCfg.e_aseqMaxCurrent;
  }
  else /* arguments out of range */
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}

/** \brief Set adaptive sequencer for discharge
 *
 * \param s_aseqDischrgCfg Configuration of the adaptive sequencer mode for discharge
 * \return sint8 0: success, <0: error codes
 */
sint8 BDRV_setDischrgAdaptSeqMode(tBDRV_aseqCfg s_aseqDischrgCfg)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Violation: Relational operator '<=' always evaluates to 'true' [MISRA 2012 Rule 14.3, required] */
  if ((s_aseqDischrgCfg.e_aseqMinCurrent <= BDRV_currentCfg_350mA)
      && (s_aseqDischrgCfg.e_aseqMaxCurrent <= BDRV_currentCfg_350mA)
      && (s_aseqDischrgCfg.u16_aseqMinTime_ns >= (uint16)50) && (s_aseqDischrgCfg.u16_aseqMinTime_ns <= (uint16)12800)
      && (s_aseqDischrgCfg.u16_aseqMaxTime_ns >= (uint16)50) && (s_aseqDischrgCfg.u16_aseqMaxTime_ns <= (uint16)12800))
  {
    BDRV->ASEQOFFTMIN.bit.T1OFFMIN = (s_aseqDischrgCfg.u16_aseqMinTime_ns / 50u) - 1u;
    BDRV->ASEQOFFTMAX.bit.T1OFFMAX = (s_aseqDischrgCfg.u16_aseqMaxTime_ns / 50u) - 1u;
    BDRV->ASEQOFFIMIN.bit.I1OFFMIN = (uint8)s_aseqDischrgCfg.e_aseqMinCurrent;
    BDRV->ASEQOFFIMAX.bit.I1OFFMAX = (uint8)s_aseqDischrgCfg.e_aseqMaxCurrent;
  }
  else /* arguments out of range */
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}

/** \brief Off-State Diagnosis - Short to Ground or Short to Vbattery Detection
 *
 * \return tBDRV_offState Off-state diagnosis status for every phase
 */
tBDRV_offState BDRV_checkShortDiagnosis(void)
{
  sint8 s8_returnCode;
  tBDRV_offState s_offStateDiag;
  uint32 u32_intEnNode0 = 0;
  uint32 u32_intEnNode1 = 0;

  s8_returnCode = ERR_LOG_SUCCESS;
  s_offStateDiag.b_globFailSts = false;
  s_offStateDiag.e_offStateDiagPhase1 = BDRV_offStateDiag_ok;
  s_offStateDiag.e_offStateDiagPhase2 = BDRV_offStateDiag_ok;
#if (UC_SERIES == 989)
  s_offStateDiag.e_offStateDiagPhase3 = BDRV_offStateDiag_ok;
#endif
  /* Save BDRV interrupt enable */
  u32_intEnNode0 = CPU->NVIC_ISER.bit.IRQEN0;
  u32_intEnNode1 = CPU->NVIC_ISER.bit.IRQEN1;
  /* Disable BDRV interrupt */
  CPU->NVIC_ICER.bit.IRQCLREN0 = 1u;
  CPU->NVIC_ICER.bit.IRQCLREN1 = 1u;
  /* Set Drain-Source comparator threshold to value < 1V */
  BDRV->CTRL2.bit.DSMONVTH = 3;
  /* Enable all gate drivers */
#if (UC_SERIES == 988)
  s8_returnCode = BDRV_setBridge(BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_en);
#elif (UC_SERIES == 989)
  s8_returnCode = BDRV_setBridge(BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_en);
#endif

  if (s8_returnCode == ERR_LOG_SUCCESS)
  {
    /* Activate diagnosis current sources */
#if (UC_SERIES == 988)
    s8_returnCode = BDRV_setBridge(BDRV_chCfg_en, BDRV_chCfg_hsDcs, BDRV_chCfg_en, BDRV_chCfg_hsDcs);
#elif (UC_SERIES == 989)
    s8_returnCode = BDRV_setBridge(BDRV_chCfg_en, BDRV_chCfg_hsDcs, BDRV_chCfg_en, BDRV_chCfg_hsDcs, BDRV_chCfg_en, BDRV_chCfg_hsDcs);
#endif

    if (s8_returnCode == ERR_LOG_SUCCESS)
    {
      /* Delay for the diagnosis current source to settle - it depends on the attached motor */
      SCU_delay_us(800u);
      /* Clear status flags */
      BDRV_clrFaultSts();

      /* Check status flags */
      if (BDRV_getLS1DrainSrcMonitoringSts() == 1u)
      {
        s_offStateDiag.b_globFailSts = true;
        s_offStateDiag.e_offStateDiagPhase1 = BDRV_offStateDiag_short2gnd;
      }

      if (BDRV_getHS1DrainSrcMonitoringSts() == 1u)
      {
        s_offStateDiag.b_globFailSts = true;
        s_offStateDiag.e_offStateDiagPhase1 = BDRV_offStateDiag_short2bat;
      }

      if (BDRV_getLS2DrainSrcMonitoringSts() == 1u)
      {
        s_offStateDiag.b_globFailSts = true;
        s_offStateDiag.e_offStateDiagPhase2 = BDRV_offStateDiag_short2gnd;
      }

      if (BDRV_getHS2DrainSrcMonitoringSts() == 1u)
      {
        s_offStateDiag.b_globFailSts = true;
        s_offStateDiag.e_offStateDiagPhase2 = BDRV_offStateDiag_short2bat;
      }

#if (UC_SERIES == 989)

      if (BDRV_getLS3DrainSrcMonitoringSts() == 1u)
      {
        s_offStateDiag.b_globFailSts = true;
        s_offStateDiag.e_offStateDiagPhase3 = BDRV_offStateDiag_short2gnd;
      }

      if (BDRV_getHS3DrainSrcMonitoringSts() == 1u)
      {
        s_offStateDiag.b_globFailSts = true;
        s_offStateDiag.e_offStateDiagPhase3 = BDRV_offStateDiag_short2bat;
      }

#endif
      /* Switch-off all drivers */
#if (UC_SERIES == 988)
      s8_returnCode = BDRV_setBridge(BDRV_chCfg_off, BDRV_chCfg_off, BDRV_chCfg_off, BDRV_chCfg_off);
#elif (UC_SERIES == 989)
      s8_returnCode = BDRV_setBridge(BDRV_chCfg_off, BDRV_chCfg_off, BDRV_chCfg_off, BDRV_chCfg_off, BDRV_chCfg_off, BDRV_chCfg_off);
#endif

      if (s8_returnCode == ERR_LOG_SUCCESS)
      {
        /* Restore BDRV interrupt enable */
        if (u32_intEnNode0 == (uint32)1u)
        {
          CPU->NVIC_ISER.bit.IRQEN0 = 1u;
        }

        if (u32_intEnNode1 == (uint32)1u)
        {
          CPU->NVIC_ISER.bit.IRQEN1 = 1u;
        }
      }
    }
  }

  return s_offStateDiag;
}

/** \brief Off-State Diagnosis - Open-Load Detection
 *
 * \return tBDRV_offState Off-state diagnosis status for every phase
 */
tBDRV_offState BDRV_checkOpenLoad(void)
{
  sint8 s8_returnCode;
  tBDRV_offState s_offStateDiag;
  uint32 u32_intEnNode0 = 0;
  uint32 u32_intEnNode1 = 0;

  s8_returnCode = ERR_LOG_SUCCESS;
  s_offStateDiag.b_globFailSts = false;
  s_offStateDiag.e_offStateDiagPhase1 = BDRV_offStateDiag_ok;
  s_offStateDiag.e_offStateDiagPhase2 = BDRV_offStateDiag_ok;
#if (UC_SERIES == 989)
  s_offStateDiag.e_offStateDiagPhase3 = BDRV_offStateDiag_ok;
#endif
  /* Save BDRV interrupt enable */
  u32_intEnNode0 = CPU->NVIC_ISER.bit.IRQEN0;
  u32_intEnNode1 = CPU->NVIC_ISER.bit.IRQEN1;
  /* Disable BDRV interrupt */
  CPU->NVIC_ICER.bit.IRQCLREN0 = 1u;
  CPU->NVIC_ICER.bit.IRQCLREN1 = 1u;
  /* Set Drain-Source comparator threshold to smallest value */
  BDRV->CTRL2.bit.DSMONVTH = 0u;
  /* CHECK PHASE 1 */
#if (UC_SERIES == 988)
  /* TLE988x: Enable HS2 diagnosis current source */
  s8_returnCode = BDRV_setBridge(BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_hsDcs);
#elif (UC_SERIES == 989)
  /* TLE989x: Enable HS2 (&& HS3) diagnosis current source */
  s8_returnCode = BDRV_setBridge(BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_hsDcs, BDRV_chCfg_en, BDRV_chCfg_hsDcs);
#endif

  if (s8_returnCode == ERR_LOG_SUCCESS)
  {
    /* Delay for the diagnosis current source to settle - it depends on the attached motor */
    SCU_delay_us(800u);
    /* Clear status flags */
    BDRV_clrFaultSts();

    /* Check status flags */
    if (BDRV_getHS1DrainSrcMonitoringSts() == 1u)
    {
      s_offStateDiag.b_globFailSts = true;
      s_offStateDiag.e_offStateDiagPhase1 = BDRV_offStateDiag_openload;
    }

    /* CHECK PHASE 2 */
#if (UC_SERIES == 988)
    /* TLE988x: Enable HS1 diagnosis current source */
    s8_returnCode = BDRV_setBridge(BDRV_chCfg_en, BDRV_chCfg_hsDcs, BDRV_chCfg_en, BDRV_chCfg_en);
#elif (UC_SERIES == 989)
    /* TLE989x: Enable HS1 (&& HS3) diagnosis current source */
    s8_returnCode = BDRV_setBridge(BDRV_chCfg_en, BDRV_chCfg_hsDcs, BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_hsDcs);
#endif

    if (s8_returnCode == ERR_LOG_SUCCESS)
    {
      /* Delay for the diagnosis current source to settle - it depends on the attached motor */
      SCU_delay_us(800u);
      /* Clear status flags */
      BDRV_clrFaultSts();

      /* Check status flags */
      if (BDRV_getHS2DrainSrcMonitoringSts() == 1u)
      {
        s_offStateDiag.b_globFailSts = true;
        s_offStateDiag.e_offStateDiagPhase2 = BDRV_offStateDiag_openload;
      }

#if (UC_SERIES == 989)
      /* CHECK PHASE 3 */
      /* TLE989x: Enable HS2 (&& HS3) diagnosis current source */
      s8_returnCode = BDRV_setBridge(BDRV_chCfg_en, BDRV_chCfg_hsDcs, BDRV_chCfg_en, BDRV_chCfg_hsDcs, BDRV_chCfg_en, BDRV_chCfg_en);

      if (s8_returnCode == ERR_LOG_SUCCESS)
      {
        /* Delay for the diagnosis current source to settle - it depends on the attached motor */
        SCU_delay_us(800u);
        /* Clear status flags */
        BDRV_clrFaultSts();

        /* Check status flags */
        if (BDRV_getHS3DrainSrcMonitoringSts() == 1u)
        {
          s_offStateDiag.b_globFailSts = true;
          s_offStateDiag.e_offStateDiagPhase3 = BDRV_offStateDiag_openload;
        }
      }

#endif
      /* Switch-off all drivers */
#if (UC_SERIES == 988)
      s8_returnCode = BDRV_setBridge(BDRV_chCfg_off, BDRV_chCfg_off, BDRV_chCfg_off, BDRV_chCfg_off);
#elif (UC_SERIES == 989)
      s8_returnCode = BDRV_setBridge(BDRV_chCfg_off, BDRV_chCfg_off, BDRV_chCfg_off, BDRV_chCfg_off, BDRV_chCfg_off, BDRV_chCfg_off);
#endif

      if (s8_returnCode == ERR_LOG_SUCCESS)
      {
        if (u32_intEnNode0 == (uint32)1u)
        {
          CPU->NVIC_ISER.bit.IRQEN0 = 1u;
        }

        if (u32_intEnNode1 == (uint32)1u)
        {
          CPU->NVIC_ISER.bit.IRQEN1 = 1u;
        }
      }
    }
  }

  return s_offStateDiag;
}

/** \brief Read all status flags related to bridge driver and charge pump and return true if at least one is active, otherwise false
 *
 * \return bool True if one status flag is active otherwise false
 */
bool BDRV_getFaultSts(void)
{
  bool status = false;

  if (BDRV->STS.reg > (uint32)0)
  {
    status = true;
  }

  return status;
}

/** \brief Read the fault information related to bridge driver and charge pump and provides them encoded in the return value
 *
 * \return uint8 Fault information related to bridge driver and charge pump
 * \return Bit0: Over Current LS1
 * \return Bit1: Over Current HS1
 * \return Bit2: Over Current LS2
 * \return Bit3: Over Current HS2
 * \return Bit4: Over Current LS3
 * \return Bit5: Over Current HS3
 * \return Bit6: Under Voltage Charge Pump (incl. VSD and VCP)
 * \return Bit7: Over Voltage Charge Pump (incl. VSD and VCP)
 */
uint8 BDRV_getFaults(void)
{
  uint8 u8_res1;
  uint8 u8_res2;
  uint8 u8_res3;
  uint8 u8_res4;
  uint8 u8_res5;
  uint8 u8_res6;
  uint8 u8_res7;
  uint8 u8_res;
  
  u8_res7 = BDRV->STS.bit.VCP_UPTH_STS;
  u8_res7 |= BDRV->STS.bit.VSD_UPTH_STS;
  u8_res7 |= BDRV->STS.bit.VSD_OV_STS;
  u8_res7 <<= 7u;
  u8_res6 = BDRV->STS.bit.VCP_LOTH1_STS;
  u8_res6 |= BDRV->STS.bit.VCP_LOTH2_STS;
  u8_res6 |= BDRV->STS.bit.VSD_LOTH_STS;
  u8_res6 <<= 6u;
  u8_res5 = (uint8)(BDRV->STS.bit.HS3_OC_STS << 5u);
  u8_res4 = (uint8)(BDRV->STS.bit.LS3_OC_STS << 4u);
  u8_res3 = (uint8)(BDRV->STS.bit.HS2_OC_STS << 3u);
  u8_res2 = (uint8)(BDRV->STS.bit.LS2_OC_STS << 2u);
  u8_res1 = (uint8)(BDRV->STS.bit.HS1_OC_STS << 1u);
  u8_res = BDRV->STS.bit.LS1_OC_STS | u8_res1;
  u8_res |= u8_res2;
  u8_res |= u8_res3;
  u8_res |= u8_res4;
  u8_res |= u8_res5;
  u8_res |= u8_res6;
  u8_res |= u8_res7;
  return (uint8)u8_res;
}

/** \brief Clear all status bits related to bridge driver and charge pump
 */
void BDRV_clrFaultSts(void)
{
  BDRV->STSCLR.reg = (uint32)0x80333333u;
}

/*******************************************************************************
**                       Deprecated Function Definitions                      **
*******************************************************************************/

/*=================================== BDRV ===================================*/

void BDRV_setExternalLS1MosfetOvercurrentIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void BDRV_setExternalHS1MosfetOvercurrentIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void BDRV_setExternalLS2MosfetOvercurrentIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void BDRV_setExternalHS2MosfetOvercurrentIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void BDRV_setExternalLS3MosfetOvercurrentIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void BDRV_setExternalHS3MosfetOvercurrentIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void BDRV_setLS1DrainSrcMonitoringIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void BDRV_setHS1DrainSrcMonitoringIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void BDRV_setLS2DrainSrcMonitoringIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void BDRV_setHS2DrainSrcMonitoringIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void BDRV_setLS3DrainSrcMonitoringIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void BDRV_setHS3DrainSrcMonitoringIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void BDRV_setHB1AdaptSeqIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void BDRV_setHB2AdaptSeqIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void BDRV_setHB3AdaptSeqIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void BDRV_setHB1ActDrvDetectIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void BDRV_setHB2ActDrvDetectIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void BDRV_setHB3ActDrvDetectIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void BDRV_setDrvSeqErrIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

/*================================== BEMFC ===================================*/

void BDRV_setPh1ZCFallIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void BDRV_setPh2ZCFallIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void BDRV_setPh3ZCFallIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void BDRV_setPh1ZCRiseIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void BDRV_setPh2ZCRiseIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void BDRV_setPh3ZCRiseIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}


