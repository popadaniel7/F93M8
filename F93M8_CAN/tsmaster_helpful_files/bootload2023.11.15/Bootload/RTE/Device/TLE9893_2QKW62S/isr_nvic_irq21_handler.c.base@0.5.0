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


/* Check if NVIC node 21 is enabled */
#if ((CPU_NVIC_ISER & CPU_NVIC_ISER_IRQEN21_Msk) == (1u << CPU_NVIC_ISER_IRQEN21_Pos))

/*******************************************************************************
**                        Global Variable Definitions                         **
*******************************************************************************/

#if (NVIC_IRQ21_HANDLER_INT_CHECK == 1)
  uint8 u8_interrupt_cnt_irq21 = 0;
#endif

/*******************************************************************************
**                        Global Function Declarations                        **
*******************************************************************************/

/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

void NVIC_IRQ21_Handler(void)
{
  #if (NVIC_IRQ21_HANDLER_INT_CHECK == 1)
    u8_interrupt_cnt_irq21 = 0;
  #endif
  /* EXTINT0 Rising Edge */
  #if (SCU_EXTINT0_RISING_INT_EN == 1)
    #if (((SCU_INP4 & SCU_INP4_INP_EXINT0_Msk) >>  SCU_INP4_INP_EXINT0_Pos) == EXTINT_INP_NVIC_IRQ21)
      if ((SCU->EXTCON.bit.EXTINT0IEV & (uint8)(1u << 0u)) == 1u)
      {
        if (SCU->EXTIS.bit.EXTINT0R == 1u)
        {
          SCU_EXTINT0_RISING_CALLBACK();
          SCU->EXTISC.bit.EXTINT0RCLR = 1u;
          #if (NVIC_IRQ21_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq21 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* EXTINT0 Falling Edge */
  #if (SCU_EXTINT0_FALLING_INT_EN == 1)
    #if (((SCU_INP4 & SCU_INP4_INP_EXINT0_Msk) >>  SCU_INP4_INP_EXINT0_Pos) == EXTINT_INP_NVIC_IRQ21)
      if (((SCU->EXTCON.bit.EXTINT0IEV & (uint8)(1u << 1u)) >> 1u) == 1u)
      {
        if (SCU->EXTIS.bit.EXTINT0F == 1u)
        {
          SCU_EXTINT0_FALLING_CALLBACK();
          SCU->EXTISC.bit.EXTINT0FCLR = 1u;
          #if (NVIC_IRQ21_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq21 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* EXTINT1 Rising Edge */
  #if (SCU_EXTINT1_RISING_INT_EN == 1)
    #if (((SCU_INP4 & SCU_INP4_INP_EXINT1_Msk) >>  SCU_INP4_INP_EXINT1_Pos) == EXTINT_INP_NVIC_IRQ21)
      if ((SCU->EXTCON.bit.EXTINT1IEV & (uint8)(1u << 0u)) == 1u)
      {
        if (SCU->EXTIS.bit.EXTINT1R == 1u)
        {
          SCU_EXTINT1_RISING_CALLBACK();
          SCU->EXTISC.bit.EXTINT1RCLR = 1u;
          #if (NVIC_IRQ21_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq21 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* EXTINT1 Falling Edge */
  #if (SCU_EXTINT1_FALLING_INT_EN == 1)
    #if (((SCU_INP4 & SCU_INP4_INP_EXINT1_Msk) >>  SCU_INP4_INP_EXINT1_Pos) == EXTINT_INP_NVIC_IRQ21)
      if (((SCU->EXTCON.bit.EXTINT1IEV & (uint8)(1u << 1u)) >> 1u) == 1u)
      {
        if (SCU->EXTIS.bit.EXTINT1F == 1u)
        {
          SCU_EXTINT1_FALLING_CALLBACK();
          SCU->EXTISC.bit.EXTINT1FCLR = 1u;
          #if (NVIC_IRQ21_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq21 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* EXTINT2 Rising Edge */
  #if (SCU_EXTINT2_RISING_INT_EN == 1)
    #if (((SCU_INP4 & SCU_INP4_INP_EXINT2_Msk) >>  SCU_INP4_INP_EXINT2_Pos) == EXTINT_INP_NVIC_IRQ21)
      if ((SCU->EXTCON.bit.EXTINT2IEV & (uint8)(1u << 0u)) == 1u)
      {
        if (SCU->EXTIS.bit.EXTINT2R == 1u)
        {
          SCU_EXTINT2_RISING_CALLBACK();
          SCU->EXTISC.bit.EXTINT2RCLR = 1u;
          #if (NVIC_IRQ21_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq21 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* EXTINT2 Falling Edge */
  #if (SCU_EXTINT2_FALLING_INT_EN == 1)
    #if (((SCU_INP4 & SCU_INP4_INP_EXINT2_Msk) >>  SCU_INP4_INP_EXINT2_Pos) == EXTINT_INP_NVIC_IRQ21)
      if (((SCU->EXTCON.bit.EXTINT2IEV & (uint8)(1u << 1u)) >> 1u) == 1u)
      {
        if (SCU->EXTIS.bit.EXTINT2F == 1u)
        {
          SCU_EXTINT2_FALLING_CALLBACK();
          SCU->EXTISC.bit.EXTINT2FCLR = 1u;
          #if (NVIC_IRQ21_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq21 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* EXTINT3 Rising Edge */
  #if (SCU_EXTINT3_RISING_INT_EN == 1)
    #if (((SCU_INP4 & SCU_INP4_INP_EXINT3_Msk) >>  SCU_INP4_INP_EXINT3_Pos) == EXTINT_INP_NVIC_IRQ21)
      if ((SCU->EXTCON.bit.EXTINT3IEV & (uint8)(1u << 0u)) == 1u)
      {
        if (SCU->EXTIS.bit.EXTINT3R == 1u)
        {
          SCU_EXTINT3_RISING_CALLBACK();
          SCU->EXTISC.bit.EXTINT3RCLR = 1u;
          #if (NVIC_IRQ21_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq21 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* EXTINT3 Falling Edge */
  #if (SCU_EXTINT3_FALLING_INT_EN == 1)
    #if (((SCU_INP4 & SCU_INP4_INP_EXINT3_Msk) >>  SCU_INP4_INP_EXINT3_Pos) == EXTINT_INP_NVIC_IRQ21)
      if (((SCU->EXTCON.bit.EXTINT3IEV & (uint8)(1u << 1u)) >> 1u) == 1u)
      {
        if (SCU->EXTIS.bit.EXTINT3F == 1u)
        {
          SCU_EXTINT3_FALLING_CALLBACK();
          SCU->EXTISC.bit.EXTINT3FCLR = 1u;
          #if (NVIC_IRQ21_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq21 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

}
#endif /* ((CPU_NVIC_ISER & CPU_NVIC_ISER_IRQEN21_Msk) == 1u) */
