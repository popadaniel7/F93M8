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


/* Check if NVIC node 12 is enabled */
#if ((CPU_NVIC_ISER & CPU_NVIC_ISER_IRQEN12_Msk) == (1u << CPU_NVIC_ISER_IRQEN12_Pos))

/*******************************************************************************
**                        Global Variable Definitions                         **
*******************************************************************************/

#if (NVIC_IRQ12_HANDLER_INT_CHECK == 1)
  uint8 u8_interrupt_cnt_irq12 = 0;
#endif

/*******************************************************************************
**                        Global Function Declarations                        **
*******************************************************************************/

/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

void NVIC_IRQ12_Handler(void)
{
  #if (NVIC_IRQ12_HANDLER_INT_CHECK == 1)
    u8_interrupt_cnt_irq12 = 0;
  #endif
  /* MON1 R */
  #if (MON_MON1_R_INT_EN == 1)
    #if (((SCU_INP2 & SCU_INP2_INP_MON1_Msk) >>  SCU_INP2_INP_MON1_Pos) == MON_INP_NVIC_IRQ12)
      if (SCU->MONIEN.bit.MON1EN == 1u)
      {
        if (SCU->MONIS.bit.MON1R == 1u)
        {
          MON_MON1_R_CALLBACK();
          SCU->MONISC.bit.MON1RCLR = 1u;
          #if (NVIC_IRQ12_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq12 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* MON1 F */
  #if (MON_MON1_F_INT_EN == 1)
    #if (((SCU_INP2 & SCU_INP2_INP_MON1_Msk) >>  SCU_INP2_INP_MON1_Pos) == MON_INP_NVIC_IRQ12)
      if (SCU->MONIEN.bit.MON1EN == 1u)
      {
        if (SCU->MONIS.bit.MON1F == 1u)
        {
          MON_MON1_F_CALLBACK();
          SCU->MONISC.bit.MON1FCLR = 1u;
          #if (NVIC_IRQ12_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq12 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* MON2 R */
  #if (MON_MON2_R_INT_EN == 1)
    #if (((SCU_INP2 & SCU_INP2_INP_MON2_Msk) >>  SCU_INP2_INP_MON2_Pos) == MON_INP_NVIC_IRQ12)
      if (SCU->MONIEN.bit.MON2EN == 1u)
      {
        if (SCU->MONIS.bit.MON2R == 1u)
        {
          MON_MON2_R_CALLBACK();
          SCU->MONISC.bit.MON2RCLR = 1u;
          #if (NVIC_IRQ12_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq12 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* MON2 F */
  #if (MON_MON2_F_INT_EN == 1)
    #if (((SCU_INP2 & SCU_INP2_INP_MON2_Msk) >>  SCU_INP2_INP_MON2_Pos) == MON_INP_NVIC_IRQ12)
      if (SCU->MONIEN.bit.MON2EN == 1u)
      {
        if (SCU->MONIS.bit.MON2F == 1u)
        {
          MON_MON2_F_CALLBACK();
          SCU->MONISC.bit.MON2FCLR = 1u;
          #if (NVIC_IRQ12_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq12 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* MON3 R */
  #if (MON_MON3_R_INT_EN == 1)
    #if (((SCU_INP2 & SCU_INP2_INP_MON3_Msk) >>  SCU_INP2_INP_MON3_Pos) == MON_INP_NVIC_IRQ12)
      if (SCU->MONIEN.bit.MON3EN == 1u)
      {
        if (SCU->MONIS.bit.MON3R == 1u)
        {
          MON_MON3_R_CALLBACK();
          SCU->MONISC.bit.MON3RCLR = 1u;
          #if (NVIC_IRQ12_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq12 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* MON3 F */
  #if (MON_MON3_F_INT_EN == 1)
    #if (((SCU_INP2 & SCU_INP2_INP_MON3_Msk) >>  SCU_INP2_INP_MON3_Pos) == MON_INP_NVIC_IRQ12)
      if (SCU->MONIEN.bit.MON3EN == 1u)
      {
        if (SCU->MONIS.bit.MON3F == 1u)
        {
          MON_MON3_F_CALLBACK();
          SCU->MONISC.bit.MON3FCLR = 1u;
          #if (NVIC_IRQ12_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq12 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

}
#endif /* ((CPU_NVIC_ISER & CPU_NVIC_ISER_IRQEN12_Msk) == 1u) */
