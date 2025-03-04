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

#include "timer2x.h"

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

/** \brief Initialize all CW registers of the timer 20
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 T20_init(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;

  #if ((SCU_PMCON & SCU_PMCON_T2_DIS_Msk) != 0u)
    s8_returnCode = ERR_LOG_SUCCESS;
  
    T20->CON.reg = (uint32)T20_CON;
    T20->MOD.reg = (uint32)T20_MOD;
    T20->RC.reg = (uint32)T20_RC;
    T20->CNT.reg = (uint32)T20_CNT;
  #endif
  
  return s8_returnCode;
}


/** \brief Initialize all CW registers of the timer 21
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 T21_init(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;

  #if ((SCU_PMCON & SCU_PMCON_T21_DIS_Msk) == 0u)
    s8_returnCode = ERR_LOG_SUCCESS;
  
    T21->CON.reg = (uint32)T21_CON;
    T21->MOD.reg = (uint32)T21_MOD;
    T21->RC.reg = (uint32)T21_RC;
    T21->CNT.reg = (uint32)T21_CNT;
  #endif
  
  return s8_returnCode;
}


/** \brief Define an interval timer with the timer T20
 *
 * \param u32_timeInterval_us Duration of the timer T20 in microseconds
 * \return sint8 0: success, <0: error codes
 */
sint8 T20_setIntervalTimer(uint32 u32_timeInterval_us)
{
  sint8 s8_returnCode;
  uint64 u64_timeInterval_ticks;
  /* T20 frequency in Hz */
  uint32 u32_T20Freq_MHz = (uint32)fT20;
  /* Calculate T20 individual prescaler: as long as u64_timeInterval_ticks is larger than
   * the T20 value register (16 bits), the individual prescaler value is incremented
   * and u64_timeInterval_ticks is divided by 2 */
  uint8 u8_T20ClkPrescaler = 0u;

  s8_returnCode = ERR_LOG_SUCCESS;
  /* Calculate time interval in ticks */
  u64_timeInterval_ticks = ((uint64)u32_timeInterval_us * (uint64)u32_T20Freq_MHz);

  while (u64_timeInterval_ticks > (uint64)0xFFFFu)
  {
    u8_T20ClkPrescaler++;
    u64_timeInterval_ticks >>= 1u;
  }

  /* T20 operates in reload mode and is counting up by default */
  u64_timeInterval_ticks = (uint64)0x10000 - u64_timeInterval_ticks;

  /* The individual prescaler maximal value is 0b111 */
  if (u8_T20ClkPrescaler <= 7u)
  {
    /* Select Reload mode */
    T20->CON.bit.CP_RL2 = 0u;
    /* Disable external up/down counter mode */
    T20->MOD.bit.DCEN = 0u;
    /* Enable the T20 clock prescaler */
    T20->MOD.bit.PREN = 1u;
    /* Program the calculated prescaler */
    T20->MOD.bit.T2PRE = (uint8)u8_T20ClkPrescaler;
    /* Program the first period */
    T20->CNT.bit.T2H = (uint16)u64_timeInterval_ticks >> 8u;
    T20->CNT.bit.T2L = (uint16)u64_timeInterval_ticks & 0xFFu;
    /* Program the reload value */
    T20->RC.bit.RCH2 = (uint16)u64_timeInterval_ticks >> 8u;
    T20->RC.bit.RCL2 = (uint16)u64_timeInterval_ticks & 0xFFu;
  }
  else /* arguments out of range */
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}


/** \brief Define an interval timer with the timer T21
 *
 * \param u32_timeInterval_us Duration of the timer T21 in microseconds
 * \return sint8 0: success, <0: error codes
 */
sint8 T21_setIntervalTimer(uint32 u32_timeInterval_us)
{
  sint8 s8_returnCode;
  uint64 u64_timeInterval_ticks;
  /* T21 frequency in Hz */
  uint32 u32_T21Freq_MHz = (uint32)fT21;
  /* Calculate T21 individual prescaler: as long as u64_timeInterval_ticks is larger than
   * the T21 value register (16 bits), the individual prescaler value is incremented
   * and u64_timeInterval_ticks is divided by 2 */
  uint8 u8_T21ClkPrescaler = 0u;
  
  s8_returnCode = ERR_LOG_SUCCESS;
  
  /* Calculate time interval in ticks */
  u64_timeInterval_ticks = ((uint64)u32_timeInterval_us * (uint64)u32_T21Freq_MHz);

  while (u64_timeInterval_ticks > (uint64)0xFFFFu)
  {
    u8_T21ClkPrescaler++;
    u64_timeInterval_ticks >>= 1u;
  }

  /* T21 operates in reload mode and is counting up by default */
  u64_timeInterval_ticks = (uint64)0x10000u - u64_timeInterval_ticks;

  /* The individual prescaler maximal value is 0b111 */
  if (u8_T21ClkPrescaler <= 7u)
  {
    /* Select Reload mode */
    T21->CON.bit.CP_RL2 = 0u;
    /* Disable external up/down counter mode */
    T21->MOD.bit.DCEN = 0u;
    /* Enable the T21 clock prescaler */
    T21->MOD.bit.PREN = 1u;
    /* Program the calculated prescaler */
    T21->MOD.bit.T2PRE = (uint8)u8_T21ClkPrescaler;
    /* Program the first period */
    T21->CNT.bit.T2H = (uint16)u64_timeInterval_ticks >> 8u;
    T21->CNT.bit.T2L = (uint16)u64_timeInterval_ticks & 0xFFu;
    /* Program the reload value */
    T21->RC.bit.RCH2 = (uint16)u64_timeInterval_ticks >> 8u;
    T21->RC.bit.RCL2 = (uint16)u64_timeInterval_ticks & 0xFFu;
  }
  else /* arguments out of range */
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}
