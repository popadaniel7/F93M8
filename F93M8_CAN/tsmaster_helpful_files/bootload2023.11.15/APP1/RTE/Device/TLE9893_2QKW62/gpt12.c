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

#include "gpt12.h"

/*******************************************************************************
**                        Private Constant Declarations                       **
*******************************************************************************/

/*******************************************************************************
**                         Private Macro Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                        Private Variable Definitions                        **
*******************************************************************************/

/*******************************************************************************
**                        Private Function Declarations                       **
*******************************************************************************/

/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

/** \brief Initialize all CW registers of the general purpose timer 12 encoder
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 GPT12_init(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;
  
  #if ((SCU_PMCON & SCU_PMCON_GPT12_DIS_Msk) == 0u)
    s8_returnCode = ERR_LOG_SUCCESS;
  
    GPT12->T2CON.reg = GPT12_T2CON;
    GPT12->T2.reg = GPT12_T2;
    GPT12->T3CON.reg = GPT12_T3CON;
    GPT12->T3.reg = GPT12_T3;
    GPT12->T4CON.reg = GPT12_T4CON;
    GPT12->T4.reg = GPT12_T4;
    GPT12->T5CON.reg = GPT12_T5CON;
    GPT12->T5.reg = GPT12_T5;
    GPT12->T6CON.reg = GPT12_T6CON;
    GPT12->T6.reg = GPT12_T6;
    GPT12->CAPREL.reg = GPT12_CAPREL;
    GPT12->PISEL.reg = GPT12_PISEL;
  #endif
  
  return s8_returnCode;
}

/** \brief Define an interval timer with the core timer T3
 *
 * \param u32_timeInterval_us Duration of the core timer T3 in microseconds
 * \return sint8 0: success, <0: error codes
 */
sint8 GPT12_setIntervalTimerT3(uint32 u32_timeInterval_us)
{
  sint8 s8_returnCode;
  uint64 u64_timeInterval_ticks;
  
  /* Calculate T3 individual prescaler: as long as u64_timeInterval_ticks is larger than
   * the T3 value register (16 bits), the individual prescaler value is incremented
   * and u64_timeInterval_ticks is divided by 2 */
  uint8 u8_T3ClkPrescaler = 0u;

  s8_returnCode = ERR_LOG_SUCCESS;

  /* Calculate time interval in ticks */
  u64_timeInterval_ticks = (uint64)u32_timeInterval_us * (uint64)fGPT1;

  while (u64_timeInterval_ticks > (uint64)0xFFFFu)
  {
    u8_T3ClkPrescaler++;
    u64_timeInterval_ticks >>= 1u;
  }

  /* The individual prescaler maximal value is 0b111 */
  if (u8_T3ClkPrescaler <= 7u)
  {
    /* Set T3 mode as Timer mode */
    GPT12->T3CON.bit.T3M = 0u;
    /* Set the calculated T3 individual prescaler */
    GPT12->T3CON.bit.T3I = (uint8)u8_T3ClkPrescaler;
    /* Disable external up/down count control */
    GPT12->T3CON.bit.T3UDE = 0u;
    /* Select down counting */
    GPT12->T3CON.bit.T3UD = 1u;
    /* Set u64_timeInterval_ticks as T3 value */
    GPT12->T3.bit.T3 = (uint16)u64_timeInterval_ticks;
    /* Set T2 mode as Reload mode */
    GPT12->T2CON.bit.T2M = 4u;
    /* Set u64_timeInterval_ticks as T2 reload value */
    GPT12->T2.bit.T2 = (uint16)u64_timeInterval_ticks;
    /* Set T3OTL as reload trigger for T2 */
    GPT12->T3CON.bit.T3OTL = 1u;
    /* Set T2 to trigger reload every T3OTL toggle, for rising and falling edge */
    GPT12->T2CON.bit.T2I = 7u;
  }
  else /* Arguments out of range */
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}

/** \brief Define an interval timer with the core timer T6
 *
 * \param u32_timeInterval_us Duration of the core timer T6 in microseconds
 * \return sint8 0: success, <0: error codes
 */
sint8 GPT12_setIntervalTimerT6(uint32 u32_timeInterval_us)
{
  sint8 s8_returnCode;
  uint64 u64_timeInterval_ticks;
  
  /* Calculate T6 individual prescaler: as long as u64_timeInterval_ticks is larger than
   * the T6 value register (16 bits), the individual prescaler value is incremented
   * and u64_timeInterval_ticks is divided by 2 */
  uint8 u8_T6ClkPrescaler = 0u;

  s8_returnCode = ERR_LOG_SUCCESS;

  /* Calculate time interval in ticks */
  u64_timeInterval_ticks = (uint64)u32_timeInterval_us * (uint64)fGPT2;

  while (u64_timeInterval_ticks > (uint64)0xFFFFu)
  {
    u8_T6ClkPrescaler++;
    u64_timeInterval_ticks >>= 1u;
  }

  /* The individual prescaler maximal value is 0b111 */
  if (u8_T6ClkPrescaler <= 7u)
  {
    /* Set T6 mode as Timer mode */
    GPT12->T6CON.bit.T6M = 0u;
    /* Set the calculated T6 individual prescaler */
    GPT12->T6CON.bit.T6I = (uint8)u8_T6ClkPrescaler;
    /* Disable external up/down count control */
    GPT12->T6CON.bit.T6UDE = 0u;
    /* Select down counting */
    GPT12->T6CON.bit.T6UD = 1u;
    /* Set u64_timeInterval_ticks as T6 value */
    GPT12->T6.bit.T6 = (uint16)u64_timeInterval_ticks;
    /* Set u64_timeInterval_ticks as CAPREL reload value */
    GPT12->CAPREL.bit.CAPREL = (uint16)u64_timeInterval_ticks;
    /* Set T6OTL as reload trigger for T5 */
    GPT12->T6CON.bit.T6OTL = 1u;
    /* Enable T6 reload by CAPREL */
    GPT12->T6CON.bit.T6SR = 1u;
  }
  else /* Arguments out of range */
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}

/*******************************************************************************
**                       Deprecated Function Definitions                      **
*******************************************************************************/

void GPT12_setT2IntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void GPT12_setT3IntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void GPT12_setT4IntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void GPT12_setT5IntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void GPT12_setT6IntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void GPT12_setCapRelIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

