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

#include "adc2.h"

/*******************************************************************************
**                          Private Macro Declarations                        **
*******************************************************************************/

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wpadded"
#endif

typedef union ADC2_RESx
{
  uint32_t reg;                           /*!< Result Register                                                           */

  struct
  {
    uint32_t RESULT     : 12;           /*!< [11..0] Result Value                                                      */
    uint32_t            : 3;
    uint32_t VALID      : 1;            /*!< [15..15] Valid flag                                                       */
  } bit;
} tADC2_RESx;

typedef union ADC2_FILx
{
  uint32_t reg;                           /*!< Filter Result Register                                                    */

  struct
  {
    uint32_t FILRESULT  : 14;           /*!< [13..0] Filter Result Value                                               */
  } bit;
} tADC2_FILx;

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic pop
#endif

/*******************************************************************************
**                         Private Constant Definitions                       **
*******************************************************************************/

static const uint16 cu16_ADC2_analogInput_Att[] = {ADC2_ATT_TYPE0, /* analog input 0, attenuator type 0 */
                                                   ADC2_ATT_TYPE1, /* analog input 1, attenuator type 1 */
                                                   ADC2_ATT_TYPE3, /* analog input 2, attenuator type 3 */
                                                   ADC2_ATT_TYPE2, /* analog input 3, attenuator type 2 */
                                                   ADC2_ATT_TYPE1, /* analog input 4, attenuator type 1 */
                                                   ADC2_ATT_TYPE1, /* analog input 5, attenuator type 1 */
                                                   ADC2_ATT_TYPE1, /* analog input 6, attenuator type 1 */
                                                   ADC2_ATT_TYPE4, /* analog input 7, attenuator type 4 */
                                                   ADC2_ATT_TYPE4, /* analog input 8, attenuator type 4 */
                                                   ADC2_ATT_TYPE4, /* analog input 9, attenuator type 4 */
                                                   ADC2_ATT_TYPE4, /* analog input 10, attenuator type 4 */
                                                   ADC2_ATT_TYPE4, /* analog input 11, attenuator type 4 */
                                                   ADC2_ATT_TYPE4, /* analog input 12, attenuator type 4 */
                                                   ADC2_ATT_TYPE4, /* analog input 13, attenuator type 4 */
                                                   ADC2_ATT_TYPE4, /* analog input 14, attenuator type 4 */
                                                  };

/*******************************************************************************
**                          Private Type Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                         Private Variable Definitions                       **
*******************************************************************************/

/*******************************************************************************
**                         Private Function Declarations                      **
*******************************************************************************/

uint8 ADC2_getFiltIdxFromChannel(uint8 u8_channel);
sint8 ADC2_getFiltChResult(uint16 *u16p_filtDigValue, uint8 u8_filtCh);

/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

/** \brief Initialize all CW registers of the ADC2 module
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 ADC2_init(void)
{
  sint8 s8_returnCode;
  uint16 i;
  s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;
  
  #if ((ADC2_GLOBCONF & ADC2_GLOBCONF_EN_Msk) == ADC2_GLOBCONF_EN_Msk)
    s8_returnCode = ERR_LOG_SUCCESS;
  
    /* Configure ADC2 clock */
    ADC2->CLKCON.reg = (uint32)ADC2_CLKCON;
    /* Enable ADC2 */
    ADC2->GLOBCONF.reg = (uint32)ADC2_GLOBCONF;

    /* Wait 266 + 5133 tADC2 cycles */
    //Delay_us((266 + 5133) / ADC2_CLK );

    for (i = 0; i < 1000; i++)
    {
      CMSIS_NOP();
    }

    /* Debug behavior, tbd */
    //ADC2->SUSCTR.reg = ...;
    /* Configure channel class */
    ADC2->CONVCFG2.reg = (uint32)ADC2_CONVCFG2;
    ADC2->CONVCFG3.reg = (uint32)ADC2_CONVCFG3;
    /* Configure filter class - only configurable for Filter Channel 6 and 7 */
    ADC2->FILTCFG.bit.COEF_A6 = (uint8)(((uint32)ADC2_FILTCFG & ADC2_FILTCFG_COEF_A6_Msk) >> ADC2_FILTCFG_COEF_A6_Pos);
    ADC2->FILTCFG.bit.COEF_A7 = (uint8)((uint32)ADC2_FILTCFG & ADC2_FILTCFG_COEF_A7_Msk) >> ADC2_FILTCFG_COEF_A7_Pos;
    /* Configure compare channel - only configurable for Compare Channel 6 and 7 */
    ADC2->CMPCFG6.reg = (uint32)ADC2_CMPCFG6;
    ADC2->CMPCFG7.reg = (uint32)ADC2_CMPCFG7;
    /* Configure user-defined digital channels */
    ADC2->CHCFG0.reg = (uint32)ADC2_CHCFG0;
    ADC2->CHCFG4.reg = (uint32)ADC2_CHCFG4;
    ADC2->CHCFG5.reg = (uint32)ADC2_CHCFG5;
    ADC2->CHCFG6.reg = (uint32)ADC2_CHCFG6;
    ADC2->CHCFG7.reg = (uint32)ADC2_CHCFG7;
    ADC2->CHCFG9.reg = (uint32)ADC2_CHCFG9;
    ADC2->CHCFG10.reg = (uint32)ADC2_CHCFG10;
    ADC2->CHCFG11.reg = (uint32)ADC2_CHCFG11;
    ADC2->CHCFG12.reg = (uint32)ADC2_CHCFG12;
    /* Configure calibration */
    ADC2->CALEN.reg = (uint32)ADC2_CALEN;
  #endif
  
  return s8_returnCode;
}



/** \brief Get the 12-bit value of the ADC2 Result Register of the selected ADC2 channel and returns the validity info
 *  \note This function violates [MISRA Rule 45]
 *
 * \param u8_channel digital channel number (0..14)
 * \param *u16p_digValue pointer to 12-bit ADC2 digital result value of the selected channel number (0..14)
 * \return sint8 0: success, <0: error codes
 *
 * \brief <b>Example</b><br>
 * \brief This example returns the ADC2 Channel 5 result.
 * ~~~~~~~~~~~~~~~{.c}
 * sint8 Example_Function(void)
 * {
 *   sint8 s8_returnCode = ERR_LOG_SUCCESS;
 *   uint16 u16_var;
 *
 *   if (ADC2_getCh5ResultValidSts() == 1u)
 *   {
 *     s8_returnCode = ADC2_getChResult(&u16_var, ADC2_DCH5);
 *   }
 *
 *   return s8_returnCode;
 * }
 * ~~~~~~~~~~~~~~~
 */
sint8 ADC2_getChResult(uint16 *u16p_digValue, uint8 u8_channel)
{
  uint32 u32_addr;
  const volatile tADC2_RESx *tpResult;
  uint16 u16_offs;
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Check input parameter validity */
  if ((PtrRangeCheck(u16p_digValue) == true) && (u8_channel < (uint8)ADC2_DCH_CNT))
  {
    /* Violation: cast from pointer to unsigned int [MISRA Rule 45]*/
    u32_addr = (uint32)&ADC2->RES0.reg;
    /* Shift channel by 2 (mult by 4) to calculate address offset for channel */
    u16_offs = (uint16)((uint16)u8_channel << 2u);
    /* Increment address by channel offset */
    u32_addr += u16_offs;
    /* Violation: cast from unsigned int to pointer [MISRA Rule 45]*/
    tpResult = (volatile tADC2_RESx *) u32_addr;

    /* Update the value - to get a valid data, the ADC1.RESx.VALID bitfield must be checked before calling this function */
    *u16p_digValue = tpResult->bit.RESULT;
  }
  else
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}

/** \brief Get the value of the ADC2 Result Register of the selected ADC2 channel in millivolt (mV) and returns the validity info
 *  \note This function violates [MISRA Rule 45]
 *
 * \param u8_channel digital channel number(0..14)
 * \param *u16p_digValue_mV pointer to ADC2 Result Register value of the selected channel number converted to millivolt (mV)
 * \return sint8 0: success, <0: error codes
 *
 * \brief <b>Example</b><br>
 * \brief This example returns the ADC2 Channel 5 result in millivolt (mV).
 * ~~~~~~~~~~~~~~~{.c}
 * sint8 Example_Function(void)
 * {
 *   sint8 s8_returnCode = ERR_LOG_SUCCESS;
 *   uint16 u16_var_mV;
 *
 *   if (ADC2_getCh5ResultValidSts() == 1u)
 *   {
 *     s8_returnCode = ADC2_getChResult_mV(&u16_var_mV, ADC2_DCH5);
 *   }
 *
 *   return s8_returnCode;
 * }
 * ~~~~~~~~~~~~~~~
 */
sint8 ADC2_getChResult_mV(uint16 *u16p_digValue_mV, uint8 u8_channel)
{
  uint32 u32_val_mV;
  uint16 u16_val;
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Check input parameter validity */
  if ((PtrRangeCheck(u16p_digValue_mV) == true) && (u8_channel < (uint8)ADC2_DCH_CNT))
  {
    if (ADC2_getChResult(&u16_val, u8_channel) == ERR_LOG_SUCCESS)
    {
      /* ADC2 Voltage(mV) = (12bit_value * ADC2_VAREF(mV)) / ADC2_MAX_RESOLUTION */
      u32_val_mV = (uint32)(((uint32)u16_val * (uint16)ADC2_VAREF_mV) / (uint16)ADC2_MAX_RESOLUTION);
      /* Adjust millivolt value based on attenuator for selected analog intut */
      *u16p_digValue_mV = (uint16)((uint32)(u32_val_mV * (uint16)ADC2_ATT_DENOM) / cu16_ADC2_analogInput_Att[u8_channel]);
    }
    else
    {
      s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
    }
  }
  else
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}

/** \brief Get the 14-bit value of the ADC2 Filter Result Register of the selected ADC2 channel and returns the validity info
 *  \note This function violates [MISRA Rule 45]
 *
 * \param u8_channel digital channel number(0..14)
 * \param *u16p_filtDigValue 12-bit ADC2 digital result value of the selected channel number (0..14)
 * \return sint8 0: success, <0: error codes
 *
 * \brief <b>Example</b><br>
 * \brief This example returns the ADC2 Channel 5 result in millivolt (mV).
 * ~~~~~~~~~~~~~~~{.c}
 * sint8 Example_Function(void)
 * {
 *   sint8 s8_returnCode = ERR_LOG_SUCCESS;
 *   uint16 u16_var_mV;
 *   uint16 u16_var;
 *
 *   if (ADC2_getChFiltResult(&u16_var, ADC2_DCH5) == ERR_LOG_SUCCESS)
 *   {
 *     s8_returnCode = ADC2_getChFiltResult_mV(&u16_var_mV, ADC2_DCH5);
 *   }
 *
 *   return s8_returnCode;
 * }
 * ~~~~~~~~~~~~~~~
 */
sint8 ADC2_getChFiltResult(uint16 *u16p_filtDigValue, uint8 u8_channel)
{
  uint8 u8_fidx;
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Check input parameter validity */
  if ((PtrRangeCheck(u16p_filtDigValue) == true) && (u8_channel < (uint8)ADC2_DCH_CNT))
  {
    /* Read analog input selection for selected channel */
    u8_fidx = ADC2_getFiltIdxFromChannel(u8_channel);

    /* Check analog input range */
    if (u8_fidx < (uint8)ADC2_FILT_CNT)
    {
      s8_returnCode = ADC2_getFiltChResult(u16p_filtDigValue, u8_fidx);
    }
    else
    {
      s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
    }
  }
  else
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}

/** \brief Get the value of the ADC2 Result Filter Register of the selected ADC2 channel in millivolt (mV) and returns the validity info
 *  \note This function violates [MISRA Rule 45]
 *
 * \param u8_channel digital channel number(0..14)
 * \param *u16p_filtDigValue_mV ADC2 Result Register value of the selected channel number converted to millivolt (mV)
 * \return sint8 0: success, <0: error codes
 *
 * \brief <b>Example</b><br>
 * \brief This example returns the ADC2 Channel 5 result in millivolt (mV).
 * ~~~~~~~~~~~~~~~{.c}
 * sint8 Example_Function(void)
 * {
 *   sint8 s8_returnCode = ERR_LOG_SUCCESS;
 *   uint16 u16_var_mV;
 *   uint16 u16_var;
 *
 *   if (ADC2_getChFiltResult(&u16_var, ADC2_DCH5) == ERR_LOG_SUCCESS)
 *   {
 *     s8_returnCode = ADC2_getChFiltResult_mV(&u16_var_mV, ADC2_DCH5);
 *   }
 *
 *   return s8_returnCode;
 * }
 * ~~~~~~~~~~~~~~~
 */
sint8 ADC2_getChFiltResult_mV(uint16 *u16p_filtDigValue_mV, uint8 u8_channel)
{
  uint32 u32_val_mV;
  uint16 u16_val;
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Check input parameter validity */
  if ((PtrRangeCheck(u16p_filtDigValue_mV) == true) && (u8_channel < (uint8)ADC2_DCH_CNT))
  {
    if (ADC2_getChFiltResult(&u16_val, u8_channel) == ERR_LOG_SUCCESS)
    {
      /* ADC2 Voltage(mV) = (10bit_value * ADC2_VAREF(mV)) / ADC2_MAX_RESOLUTION */
      u32_val_mV = (uint32)(((uint32)u16_val * (uint16)ADC2_VAREF_mV) / (uint16)ADC2_MAX_RESOLUTION);
      /* Adjust millivolt value based on attenuator for selected analog intut */
      *u16p_filtDigValue_mV = (uint16)((uint32)(u32_val_mV * (uint16)ADC2_ATT_DENOM) / cu16_ADC2_analogInput_Att[u8_channel]);
    }
    else
    {
      s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
    }
  }
  else
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}

/** \brief Get the 12-bit value of the ADC2 Result Register of the selected slot in the sequencer and returns the validity info
 *  \note This function violates [MISRA Rule 45]
 *
 * \param u8_seqIdx sequencer channel number (0..3)
 * \param u8_slotIdx slot inside sequencer (0..3)
 * \param *u16p_DigValue 12-bit ADC2 digital result value of the channel from the sequence and slot
 * \return sint8 0: success, <0: error codes
 *
 * \brief <b>Example</b><br>
 * \brief This example returns the ADC2 result for the channel in slot3 of sequence 2.
 * ~~~~~~~~~~~~~~~{.c}
 * sint8 Example_Function(void)
 * {
 *   sint8 s8_returnCode = ERR_LOG_SUCCESS;
 *   uint16 u16_var;
 *
 *   if (ADC2_getSeqResult(&u16_var, ADC2_SEQ2, ADC2_SEQ_SLOT3) == ERR_LOG_SUCCESS)
 *   {
 *   }
 *
 *   return s8_returnCode;
 * }
 * ~~~~~~~~~~~~~~~
 */
sint8 ADC2_getSeqResult(uint16 *u16p_DigValue, uint8 u8_seqIdx, uint8 u8_slotIdx)
{
  uint32 u32_addr;
  const volatile tADC2_SQCFGx *tpSqCfg;
  const volatile tADC2_SQSLOTx *tpSqSlot;
  uint16 u16_offs;
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Check input parameter validity */
  if ((PtrRangeCheck(u16p_DigValue) == true) && (u8_seqIdx < (uint8)ADC2_SEQ_CNT))
  {
    /* Violation: cast from pointer to unsigned int [MISRA Rule 45]*/
    u32_addr = (uint32)&ADC2->SQCFG0.reg;
    /* Shift seq. index by 2 (mult by 4) to calculate address offset for SQCFGx */
    u16_offs = (uint16)((uint16)u8_seqIdx << 2u);
    /* Increment address by channel offset */
    u32_addr += u16_offs;
    /* Violation: cast from unsigned int to pointer [MISRA Rule 45]*/
    tpSqCfg = (volatile tADC2_SQCFGx *) u32_addr;

    /* Check if selected slot is enabled */
    if (u8_slotIdx < tpSqCfg->bit.SLOTS)
    {
      /* Violation: cast from pointer to unsigned int [MISRA Rule 45]*/
      u32_addr = (uint32)&ADC2->SQSLOT0.reg;
      /* Shift slot index by 2 (mult by 4) to calculate address offset for SQSLOTx */
      u16_offs = (uint16)((uint16)u8_seqIdx << 2u);
      /* Increment address by channel offset */
      u32_addr += u16_offs;
      /* Violation: cast from unsigned int to pointer [MISRA Rule 45]*/
      tpSqSlot = (volatile tADC2_SQSLOTx *) u32_addr;

      switch (u8_slotIdx)
      {
        case 0:
        {
          s8_returnCode = ADC2_getChResult(u16p_DigValue, (uint8)tpSqSlot->bit.CHSEL0);
        }
        break;

        case 1:
        {
          s8_returnCode = ADC2_getChResult(u16p_DigValue, (uint8)tpSqSlot->bit.CHSEL1);
        }
        break;

        case 2:
        {
          s8_returnCode = ADC2_getChResult(u16p_DigValue, (uint8)tpSqSlot->bit.CHSEL2);
        }
        break;

        case 3:
        {
          s8_returnCode = ADC2_getChResult(u16p_DigValue, (uint8)tpSqSlot->bit.CHSEL3);
        }
        break;

        default:
        {
          s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
        }
      }
    }
    else
    {
      s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
    }
  }
  else
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}

/** \brief Get the 12-bit value of the ADC2 Result Register in mV of the selected slot in the sequencer and returns the validity info
 *  \note This function violates [MISRA Rule 45]
 *
 * \param u8_seqIdx sequencer channel number (0..3)
 * \param u8_slotIdx slot inside sequencer (0..3)
 * \param *u16p_digValue_mV 12-bit ADC2 digital result value in mV of the channel from the sequence and slot
 * \return sint8 0: success, <0: error codes
 *
 * \brief <b>Example</b><br>
 * \brief This example returns the ADC2 result for the channel in slot3 of sequence 2.
 * ~~~~~~~~~~~~~~~{.c}
 * sint8 Example_Function(void)
 * {
 *   sint8 s8_returnCode = ERR_LOG_SUCCESS;
 *   uint16 u16_var_mV;
 *
 *   if (ADC2_getSeqResult_mV(&u16_var_mV, ADC2_SEQ2, ADC2_SEQ_SLOT3) == ERR_LOG_SUCCESS)
 *   {
 *   }
 *
 *   return s8_returnCode;
 * }
 * ~~~~~~~~~~~~~~~
 */
sint8 ADC2_getSeqResult_mV(uint16 *u16p_digValue_mV, uint8 u8_seqIdx, uint8 u8_slotIdx)
{
  uint32 u32_addr;
  const volatile tADC2_SQCFGx *tpSqCfg;
  const volatile tADC2_SQSLOTx *tpSqSlot;
  uint16 u16_offs;
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Check input parameter validity */
  if ((PtrRangeCheck(u16p_digValue_mV) == true) && (u8_seqIdx < (uint8)ADC2_SEQ_CNT))
  {
    /* Violation: cast from pointer to unsigned int [MISRA Rule 45]*/
    u32_addr = (uint32)&ADC2->SQCFG0.reg;
    /* Shift seq. index by 2 (mult by 4) to calculate address offset for SQCFGx register  */
    u16_offs = (uint16)((uint16)u8_seqIdx << 2u);
    /* Increment address by channel offset */
    u32_addr += u16_offs;
    /* Violation: cast from unsigned int to pointer [MISRA Rule 45]*/
    tpSqCfg = (volatile tADC2_SQCFGx *) u32_addr;

    /* Check if selected slot is enabled */
    if (u8_slotIdx < tpSqCfg->bit.SLOTS)
    {
      /* Violation: cast from pointer to unsigned int [MISRA Rule 45]*/
      u32_addr = (uint32)&ADC2->SQSLOT0.reg;
      /* Shift slot index by 2(mult by 4) to calculate address offset for SQSLOTx register */
      u16_offs = (uint16)((uint16)u8_seqIdx << 2u);
      /* Increment address by channel offset */
      u32_addr += u16_offs;
      /* Violation: cast from unsigned int to pointer [MISRA Rule 45]*/
      tpSqSlot = (volatile tADC2_SQSLOTx *) u32_addr;

      switch (u8_slotIdx)
      {
        case 0:
        {
          s8_returnCode = ADC2_getChResult_mV(u16p_digValue_mV, (uint8)tpSqSlot->bit.CHSEL0);
        }
        break;

        case 1:
        {
          s8_returnCode = ADC2_getChResult_mV(u16p_digValue_mV, (uint8)tpSqSlot->bit.CHSEL1);
        }
        break;

        case 2:
        {
          s8_returnCode = ADC2_getChResult_mV(u16p_digValue_mV, (uint8)tpSqSlot->bit.CHSEL2);
        }
        break;

        case 3:
        {
          s8_returnCode = ADC2_getChResult_mV(u16p_digValue_mV, (uint8)tpSqSlot->bit.CHSEL3);
        }
        break;

        default:
        {
          s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
        }
      }
    }
    else
    {
      s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
    }
  }
  else
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}

/** \brief Start the conversion of a sequence by software.
 *  \note A sequence can only be started by software if the trigger selection is set to software trigger.
 *  \note This function violates [MISRA Rule 45]
 *
 * \param u8_seqIdx sequencer channel number (0..3)
 * \return sint8 0: success, <0: error codes
 *
 * \brief <b>Example</b><br>
 * \brief This example starts sequence 0
 * ~~~~~~~~~~~~~~~{.c}
 * sint8 Example_Function(void)
 * {
 *   sint8 s8_returnCode = ERR_LOG_SUCCESS;
 *
 *   if (ADC2_startSequence(ADC2_SEQ0) == ERR_LOG_SUCCESS)
 *   {
 *     //sequence successfully started
 *   }
 *
 *   return s8_returnCode;
 * }
 * ~~~~~~~~~~~~~~~
 */
sint8 ADC2_startSequence(uint8 u8_seqIdx)
{
  uint32 u32_addr;
  volatile tADC2_SQCFGx *tpSqCfg;
  uint16 u16_offs;
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Check input parameter validity */
  if (u8_seqIdx < (uint8)ADC2_SEQ_CNT)
  {
    /* Violation: cast from pointer to unsigned int [MISRA Rule 45]*/
    u32_addr = (uint32)&ADC2->SQCFG0.reg;
    /* Shift seq. index by 2 (mult by 4) to calculate address offset for SQCFGx register */
    u16_offs = (uint16)((uint16)u8_seqIdx << 2u);
    /* Increment address by channel offset */
    u32_addr += u16_offs;
    /* Violation: cast from unsigned int to pointer [MISRA Rule 45]*/
    tpSqCfg = (volatile tADC2_SQCFGx *) u32_addr;

    /* Check if software trigger is selected */
    if (ADC2_SW_TRIGGER == tpSqCfg->bit.TRGSEL)
    {
      /* Trigger start of conversion by software */
      tpSqCfg->bit.TRGSW = 1u;
      /* Sequence start triggered */
      s8_returnCode = ERR_LOG_SUCCESS;
    }
  }
  else
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}

/** \brief Get End-of-Convertion status for selected sequence and slot
 *  \note This function violates [MISRA Rule 45]
 *
 * \param u8_seqIdx sequencer channel number (0..3)
 * \param u8_slotIdx slot number (0..3)
 * \return uint8 End-of-Convertion status for selected sequence and slot
 *
 * \brief <b>Example</b><br>
 * \brief This example starts sequence 0, checks slot0's EOC status and reads its result
 * ~~~~~~~~~~~~~~~{.c}
 * uint8 Example_Function(void)
 * {
 *   uint16 u16_val_mV;
 *
 *   if (ADC2_startSequence(ADC2_SEQ0) == ERR_LOG_SUCCESS)
 *   {
 *     while (ADC2_getEndOfConvSts(ADC2_SEQ0, ADC2_SEQ_SLOT0) == 0u) {}
 *
 *     ADC2_getSeqResult_mV(&u16_val_mV, ADC2_SEQ0, ADC2_SEQ_SLOT0);
 *   }
 *
 *   return u8_EOCSts;
 * }
 * ~~~~~~~~~~~~~~~
 */
uint8 ADC2_getEndOfConvSts(uint8 u8_seqIdx, uint8 u8_slotIdx)
{
  uint8 u8_channel;
  uint32 u32_addr;
  const volatile tADC2_SQSLOTx *tpSqSlt;
  uint16 u16_offs;
  uint8 u8_EOCSts;
  u8_EOCSts = 0u;

  /* Check input parameter validity */
  if (u8_seqIdx < (uint8)ADC2_SEQ_CNT)
  {
    /* Violation: cast from pointer to unsigned int [MISRA Rule 45]*/
    u32_addr = (uint32)&ADC2->SQSLOT0.reg;
    /* Shift seq. index by 2 (mult by 4) to calculate address offset for SQSLOTx register */
    u16_offs = (uint16)((uint16)u8_seqIdx << 2u);
    /* Increment address by channel offset */
    u32_addr += u16_offs;
    /* Violation: cast from unsigned int to pointer [MISRA Rule 45]*/
    tpSqSlt = (volatile tADC2_SQSLOTx *) u32_addr;

    /* Check input parameter validity */
    if (u8_slotIdx < (uint8)ADC2_SLOT_CNT)
    {
      /* Get digital channel out of slot configuration */
      u8_channel = (uint8)((tpSqSlt->reg >> (u8_slotIdx * 8u)) & (uint8)0xFF);

      /* Check input parameter validity */
      if (u8_channel < (uint8)ADC2_DCH_CNT)
      {
        /* get status register for configured channel */
        u8_EOCSts = (uint8)((ADC2->CHSTAT.reg >> u8_channel) & 1u);
      }
    }
  }

  return u8_EOCSts;
}

/*******************************************************************************
**                         Private Function Definitions                       **
*******************************************************************************/

/** \brief Get the index of the filter channel configured for a given digital channel
 *
 * \param u8_channel digital channel number(0..14)
 * \return u8_fidx index of the filter channel configured for a given digital channel
 */
uint8 ADC2_getFiltIdxFromChannel(uint8 u8_channel)
{
  const volatile tADC2_CHCFGx *tpChCfg;
  uint32 u32_addr;
  uint16 u16_offs;
  uint8 u8_fidx;
  /* Initialize the return value to a not used index in the filter channel selection */
  u8_fidx = (uint8)ADC2_FILT_CH_DIS;

  /* Check input parameter validity */
  if (u8_channel < (uint8)ADC2_DCH_CNT)
  {
    /* Violation: cast from pointer to unsigned int [MISRA Rule 45]*/
    u32_addr = (uint32)&ADC2->CHCFG0.reg;
    /* Shift channel by 2 (mult by 4) to calculate address offset for channel */
    u16_offs = (uint16)((uint16)u8_channel << 2u);
    /* Increment address by channel offset */
    u32_addr += u16_offs;
    /* Violation: cast from unsigned int to pointer [MISRA Rule 45]*/
    tpChCfg = (volatile tADC2_CHCFGx *) u32_addr;
    /* Read analog input selection for selected channel */
    u8_fidx = tpChCfg->bit.FILSEL;
  }

  return (u8_fidx);
}

/** \brief Get the result value from the given filter channel
 *  \note This function violates [MISRA Rule 45]
 *
 * \param u8_filtCh filter channel number (0..3)
 * \param *u16p_filtDigValue filter digital value
 * \return sint8 0: success, <0: error codes
 */
sint8 ADC2_getFiltChResult(uint16 *u16p_filtDigValue, uint8 u8_filtCh)
{
  uint32 u32_addr;
  const volatile tADC2_FILx *tpResult;
  uint16 u16_offs;
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Check input parameter validity */
  if ((PtrRangeCheck(u16p_filtDigValue) == true) &&  (u8_filtCh < (uint8)ADC2_FILT_CNT))
  {
    /* Violation: cast from pointer to unsigned int [MISRA Rule 45]*/
    u32_addr = (uint32)&ADC2->FIL0.reg;
    /* Shift channel by to (mult by 4) to calculate address offset for channel */
    u16_offs = (uint16)((uint16)u8_filtCh << 2u);
    /* Increment address by channel offset */
    u32_addr += u16_offs;
    /* Violation: cast from unsigned int to pointer [MISRA Rule 45]*/
    tpResult = (volatile tADC2_FILx *) u32_addr;
    /* Update the value only if there is valid data in result register **
    ** The filter value is stored as a 14bit value, shifting it down   **
    ** to a 12bit value for proper postprocessing                      */
    *u16p_filtDigValue = (uint16)(tpResult->bit.FILRESULT  >> 2u);
  }
  else
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}

/*******************************************************************************
**                       Deprecated Function Definitions                      **
*******************************************************************************/

void ADC2_setCh0IntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setCh1IntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setCh2IntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setCh3IntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setCh4IntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setCh5IntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setCh6IntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setCh7IntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setCh8IntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setCh9IntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setCh10IntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setCh11IntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setCh12IntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setCh13IntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setCh14IntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setCmp0LoIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setCmp1LoIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setCmp2LoIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setCmp3LoIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setCmp4LoIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setCmp5LoIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setCmp6LoIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setCmp7LoIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setCmp0UpIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setCmp1UpIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setCmp2UpIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setCmp3UpIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setCmp4UpIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setCmp5UpIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setCmp6UpIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setCmp7UpIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setSeq0IntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setSeq1IntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setSeq2IntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void ADC2_setSeq3IntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

