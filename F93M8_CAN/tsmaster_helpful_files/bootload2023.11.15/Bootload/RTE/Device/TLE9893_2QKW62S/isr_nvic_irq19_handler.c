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

#include "tle989x.h"
#include "isr.h"
#include "isr_defines.h"


/* Check if NVIC node 19 is enabled */
#if ((CPU_NVIC_ISER & CPU_NVIC_ISER_IRQEN19_Msk) == (1u << CPU_NVIC_ISER_IRQEN19_Pos))

/*******************************************************************************
**                        Global Variable Definitions                         **
*******************************************************************************/

#if (NVIC_IRQ19_HANDLER_INT_CHECK == 1)
  uint8 u8_interrupt_cnt_irq19 = 0;
#endif

/*******************************************************************************
**                        Global Function Declarations                        **
*******************************************************************************/

/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

void NVIC_IRQ19_Handler(void)
{
  #if (NVIC_IRQ19_HANDLER_INT_CHECK == 1)
    u8_interrupt_cnt_irq19 = 0;
  #endif
  /* BEMF Phase1 Zero Crossing Rising */
  #if (BDRV_PH1_ZC_RISE_INT_EN == 1)
    #if (((SCU_INP3 & SCU_INP3_INP_BEMF0_Msk) >>  SCU_INP3_INP_BEMF0_Pos) == BEMF_SDADC_INP_NVIC_IRQ19)
      if (BDRV->BEMFC_IRQEN.bit.PH1_ZCRISE_IEN == 1u)
      {
        if (BDRV->BEMFC_IRQS.bit.PH1_ZCRISE_IS == 1u)
        {
          BDRV_PH1_ZC_RISE_CALLBACK();
          BDRV->BEMFC_IRQCLR.bit.PH1_ZCRISE_ISC = 1u;
          #if (NVIC_IRQ19_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq19 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* BEMF Phase1 Zero Crossing Falling */
  #if (BDRV_PH1_ZC_FALL_INT_EN == 1)
    #if (((SCU_INP3 & SCU_INP3_INP_BEMF0_Msk) >>  SCU_INP3_INP_BEMF0_Pos) == BEMF_SDADC_INP_NVIC_IRQ19)
      if (BDRV->BEMFC_IRQEN.bit.PH1_ZCFALL_IEN == 1u)
      {
        if (BDRV->BEMFC_IRQS.bit.PH1_ZCFALL_IS == 1u)
        {
          BDRV_PH1_ZC_FALL_CALLBACK();
          BDRV->BEMFC_IRQCLR.bit.PH1_ZCFALL_ISC = 1u;
          #if (NVIC_IRQ19_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq19 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* BEMF Phase2 Zero Crossing Rising */
  #if (BDRV_PH2_ZC_RISE_INT_EN == 1)
    #if (((SCU_INP3 & SCU_INP3_INP_BEMF1_Msk) >>  SCU_INP3_INP_BEMF1_Pos) == BEMF_SDADC_INP_NVIC_IRQ19)
      if (BDRV->BEMFC_IRQEN.bit.PH2_ZCRISE_IEN == 1u)
      {
        if (BDRV->BEMFC_IRQS.bit.PH2_ZCRISE_IS == 1u)
        {
          BDRV_PH2_ZC_RISE_CALLBACK();
          BDRV->BEMFC_IRQCLR.bit.PH2_ZCRISE_ISC = 1u;
          #if (NVIC_IRQ19_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq19 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* BEMF Phase2 Zero Crossing Falling */
  #if (BDRV_PH2_ZC_FALL_INT_EN == 1)
    #if (((SCU_INP3 & SCU_INP3_INP_BEMF1_Msk) >>  SCU_INP3_INP_BEMF1_Pos) == BEMF_SDADC_INP_NVIC_IRQ19)
      if (BDRV->BEMFC_IRQEN.bit.PH2_ZCFALL_IEN == 1u)
      {
        if (BDRV->BEMFC_IRQS.bit.PH2_ZCFALL_IS == 1u)
        {
          BDRV_PH2_ZC_FALL_CALLBACK();
          BDRV->BEMFC_IRQCLR.bit.PH2_ZCFALL_ISC = 1u;
          #if (NVIC_IRQ19_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq19 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* BEMF Phase3 Zero Crossing Rising */
  #if (BDRV_PH3_ZC_RISE_INT_EN == 1)
    #if (((SCU_INP3 & SCU_INP3_INP_BEMF2_Msk) >>  SCU_INP3_INP_BEMF2_Pos) == BEMF_SDADC_INP_NVIC_IRQ19)
      if (BDRV->BEMFC_IRQEN.bit.PH3_ZCRISE_IEN == 1u)
      {
        if (BDRV->BEMFC_IRQS.bit.PH3_ZCRISE_IS == 1u)
        {
          BDRV_PH3_ZC_RISE_CALLBACK();
          BDRV->BEMFC_IRQCLR.bit.PH3_ZCRISE_ISC = 1u;
          #if (NVIC_IRQ19_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq19 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* BEMF Phase3 Zero Crossing Falling */
  #if (BDRV_PH3_ZC_FALL_INT_EN == 1)
    #if (((SCU_INP3 & SCU_INP3_INP_BEMF2_Msk) >>  SCU_INP3_INP_BEMF2_Pos) == BEMF_SDADC_INP_NVIC_IRQ19)
      if (BDRV->BEMFC_IRQEN.bit.PH3_ZCFALL_IEN == 1u)
      {
        if (BDRV->BEMFC_IRQS.bit.PH3_ZCFALL_IS == 1u)
        {
          BDRV_PH3_ZC_FALL_CALLBACK();
          BDRV->BEMFC_IRQCLR.bit.PH3_ZCFALL_ISC = 1u;
          #if (NVIC_IRQ19_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq19 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* SDADC Result0  */
  #if (SDADC_RES0_INT_EN == 1)
    #if (((SCU_INP3 & SCU_INP3_INP_SDADC0_Msk) >>  SCU_INP3_INP_SDADC0_Pos) == BEMF_SDADC_INP_NVIC_IRQ19)
      if (SDADC->IEN.bit.RES0_EN == 1u)
      {
        if (SDADC->IS.bit.RES0_IS == 1u)
        {
          SDADC_RES0_CALLBACK();
          SDADC->ISR.bit.RES0_ISC = 1u;
          #if (NVIC_IRQ19_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq19 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* SDADC Result0 upper threshold */
  #if (SDADC_CMP0_UP_INT_EN == 1)
    #if (((SCU_INP3 & SCU_INP3_INP_SDADC0_Msk) >>  SCU_INP3_INP_SDADC0_Pos) == BEMF_SDADC_INP_NVIC_IRQ19)
      if (SDADC->IEN.bit.CMP0_UP_EN == 1u)
      {
        if (SDADC->IS.bit.CMP0_UP_IS == 1u)
        {
          SDADC_CMP0_UP_CALLBACK();
          SDADC->ISR.bit.CMP0_UP_ISC = 1u;
          #if (NVIC_IRQ19_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq19 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* SDADC Result0 lower threshold */
  #if (SDADC_CMP0_LO_INT_EN == 1)
    #if (((SCU_INP3 & SCU_INP3_INP_SDADC0_Msk) >>  SCU_INP3_INP_SDADC0_Pos) == BEMF_SDADC_INP_NVIC_IRQ19)
      if (SDADC->IEN.bit.CMP0_LO_EN == 1u)
      {
        if (SDADC->IS.bit.CMP0_LO_IS == 1u)
        {
          SDADC_CMP0_LO_CALLBACK();
          SDADC->ISR.bit.CMP0_LO_ISC = 1u;
          #if (NVIC_IRQ19_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq19 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* SDADC Result1 */
  #if (SDADC_RES1_INT_EN == 1)
    #if (((SCU_INP3 & SCU_INP3_INP_SDADC1_Msk) >>  SCU_INP3_INP_SDADC1_Pos) == BEMF_SDADC_INP_NVIC_IRQ19)
      if (SDADC->IEN.bit.RES1_EN == 1u)
      {
        if (SDADC->IS.bit.RES1_IS == 1u)
        {
          SDADC_RES1_CALLBACK();
          SDADC->ISR.bit.RES1_ISC = 1u;
          #if (NVIC_IRQ19_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq19 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* SDADC Result1 upper threshold */
  #if (SDADC_CMP1_UP_INT_EN == 1)
    #if (((SCU_INP3 & SCU_INP3_INP_SDADC1_Msk) >>  SCU_INP3_INP_SDADC1_Pos) == BEMF_SDADC_INP_NVIC_IRQ19)
      if (SDADC->IEN.bit.CMP1_UP_EN == 1u)
      {
        if (SDADC->IS.bit.CMP1_UP_IS == 1u)
        {
          SDADC_CMP1_UP_CALLBACK();
          SDADC->ISR.bit.CMP1_UP_ISC = 1u;
          #if (NVIC_IRQ19_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq19 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* SDADC Result1 lower threshold */
  #if (SDADC_CMP1_LO_INT_EN == 1)
    #if (((SCU_INP3 & SCU_INP3_INP_SDADC1_Msk) >>  SCU_INP3_INP_SDADC1_Pos) == BEMF_SDADC_INP_NVIC_IRQ19)
      if (SDADC->IEN.bit.CMP1_LO_EN == 1u)
      {
        if (SDADC->IS.bit.CMP1_LO_IS == 1u)
        {
          SDADC_CMP1_LO_CALLBACK();
          SDADC->ISR.bit.CMP1_LO_ISC = 1u;
          #if (NVIC_IRQ19_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq19 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

}
#endif /* ((CPU_NVIC_ISER & CPU_NVIC_ISER_IRQEN19_Msk) == 1u) */
