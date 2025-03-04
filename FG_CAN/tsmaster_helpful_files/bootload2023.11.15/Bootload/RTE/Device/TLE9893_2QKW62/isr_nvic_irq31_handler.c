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


/* Check if NVIC node 31 is enabled */
#if ((CPU_NVIC_ISER & CPU_NVIC_ISER_IRQEN31_Msk) == (1u << CPU_NVIC_ISER_IRQEN31_Pos))

/*******************************************************************************
**                        Global Variable Definitions                         **
*******************************************************************************/

#if (NVIC_IRQ31_HANDLER_INT_CHECK == 1)
  uint8 u8_interrupt_cnt_irq31;
#endif

/*******************************************************************************
**                        Global Function Declarations                        **
*******************************************************************************/

/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

void NVIC_IRQ31_Handler(void)
{
  #if (NVIC_IRQ31_HANDLER_INT_CHECK == 1)
    u8_interrupt_cnt_irq31 = 0;
  #endif
  /* External Int */
  #if (T21_EXF2_INT_EN == 1)
      if (T21->CON1.bit.EXF2EN == 1u)
      {
        if (T21->CON.bit.EXF2 == 1u)
        {
          T21_EXF2_CALLBACK();
          T21->ICLR.bit.EXF2CLR = 1u;
          #if (NVIC_IRQ31_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq31 += 1u;
          #endif
        }
      }
  #endif /* Interrupt enabled */

  /* Over-/Underflow Int */
  #if (T21_TF2_INT_EN == 1)
      if (T21->CON1.bit.TF2EN == 1u)
      {
        if (T21->CON.bit.TF2 == 1u)
        {
          T21_TF2_CALLBACK();
          T21->ICLR.bit.TF2CLR = 1u;
          #if (NVIC_IRQ31_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq31 += 1u;
          #endif
        }
      }
  #endif /* Interrupt enabled */

}
#endif /* ((CPU_NVIC_ISER & CPU_NVIC_ISER_IRQEN31_Msk) == 1u) */
