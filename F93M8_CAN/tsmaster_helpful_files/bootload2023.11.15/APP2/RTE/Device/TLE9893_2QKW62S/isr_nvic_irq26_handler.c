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


/* Check if NVIC node 26 is enabled */
#if ((CPU_NVIC_ISER & CPU_NVIC_ISER_IRQEN26_Msk) == (1u << CPU_NVIC_ISER_IRQEN26_Pos))

/*******************************************************************************
**                        Global Variable Definitions                         **
*******************************************************************************/

#if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
  uint8 u8_interrupt_cnt_irq26 = 0;
#endif

/*******************************************************************************
**                        Global Function Declarations                        **
*******************************************************************************/

/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

void NVIC_IRQ26_Handler(void)
{
  #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
    u8_interrupt_cnt_irq26 = 0;
  #endif
  /* CANNODE Node 0 Successful Transmission */
  #if (((CANNODE_CAN_NIPR0 & CANNODE_CAN_NIPR0_TRINP_Msk) >>  CANNODE_CAN_NIPR0_TRINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANNODE->CAN_NCR0.bit.TRIE == 1u)
    {
      if (CANNODE->CAN_NSR0.bit.TXOK == 1u)
      {
        CANNODE_NODE0_TXOK_CALLBACK();
        CANNODE->CAN_NSR0.bit.TXOK = 0u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANNODE Node 0 Successful Reception */
  #if (((CANNODE_CAN_NIPR0 & CANNODE_CAN_NIPR0_TRINP_Msk) >>  CANNODE_CAN_NIPR0_TRINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANNODE->CAN_NCR0.bit.TRIE == 1u)
    {
      if (CANNODE->CAN_NSR0.bit.RXOK == 1u)
      {
        CANNODE_NODE0_RXOK_CALLBACK();
        CANNODE->CAN_NSR0.bit.RXOK = 0u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANNODE Node 0 Last Error Code */
  #if (((CANNODE_CAN_NIPR0 & CANNODE_CAN_NIPR0_LECINP_Msk) >>  CANNODE_CAN_NIPR0_LECINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANNODE->CAN_NCR0.bit.LECIE == 1u)
    {
      if (CANNODE->CAN_NSR0.bit.LEC == 1u)
      {
        CANNODE_NODE0_LEC_CALLBACK();
        CANNODE->CAN_NSR0.bit.LEC = 0u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANNODE Node 0 Error Warning */
  #if (((CANNODE_CAN_NIPR0 & CANNODE_CAN_NIPR0_ALINP_Msk) >>  CANNODE_CAN_NIPR0_ALINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANNODE->CAN_NCR0.bit.ALIE == 1u)
    {
      if (CANNODE->CAN_NSR0.bit.EWRN == 1u)
      {
        CANNODE_NODE0_EWRN_CALLBACK();
        CANNODE->CAN_NSR0.bit.EWRN = 0u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANNODE Node 0 Bus Off */
  #if (((CANNODE_CAN_NIPR0 & CANNODE_CAN_NIPR0_ALINP_Msk) >>  CANNODE_CAN_NIPR0_ALINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANNODE->CAN_NCR0.bit.ALIE == 1u)
    {
      if (CANNODE->CAN_NSR0.bit.BOFF == 1u)
      {
        CANNODE_NODE0_BOFF_CALLBACK();
        CANNODE->CAN_NSR0.bit.BOFF = 0u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANNODE Node 0 List Length Error */
  #if (((CANNODE_CAN_NIPR0 & CANNODE_CAN_NIPR0_ALINP_Msk) >>  CANNODE_CAN_NIPR0_ALINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANNODE->CAN_NCR0.bit.ALIE == 1u)
    {
      if (CANNODE->CAN_NSR0.bit.LLE == 1u)
      {
        CANNODE_NODE0_LLE_CALLBACK();
        CANNODE->CAN_NSR0.bit.LLE = 0u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANNODE Node 0 List Object Error */
  #if (((CANNODE_CAN_NIPR0 & CANNODE_CAN_NIPR0_ALINP_Msk) >>  CANNODE_CAN_NIPR0_ALINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANNODE->CAN_NCR0.bit.ALIE == 1u)
    {
      if (CANNODE->CAN_NSR0.bit.LOE == 1u)
      {
        CANNODE_NODE0_LOE_CALLBACK();
        CANNODE->CAN_NSR0.bit.LOE = 0u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANNODE Node 0 CAN Frame Counter Overflow */
  #if (((CANNODE_CAN_NIPR0 & CANNODE_CAN_NIPR0_CFCINP_Msk) >>  CANNODE_CAN_NIPR0_CFCINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANNODE->CAN_NFCR0.bit.CFCIE == 1u)
    {
      if (CANNODE->CAN_NFCR0.bit.CFCOV == 1u)
      {
        CANNODE_NODE0_CFCOV_CALLBACK();
        CANNODE->CAN_NFCR0.bit.CFCOV = 0u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 0 Transmitted */
  #if (((CANMSGOBJ0_CAN_MOIPR0 & CANMSGOBJ0_CAN_MOIPR0_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR0_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR0.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ0.CAN_MOSTAT0.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG0_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ0.CAN_MOCTR0.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 0 Received */
  #if (((CANMSGOBJ0_CAN_MOIPR0 & CANMSGOBJ0_CAN_MOIPR0_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR0_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR0.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ0.CAN_MOSTAT0.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG0_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ0.CAN_MOCTR0.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 0 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR0 & CANMSGOBJ0_CAN_MOIPR0_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR0_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR0.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR0.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ0.CAN_MOSTAT0.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG0_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ0.CAN_MOCTR0.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 0 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR0 & CANMSGOBJ0_CAN_MOIPR0_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR0_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR0.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR0.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ0.CAN_MOSTAT0.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG0_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ0.CAN_MOCTR0.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 1 Transmitted */
  #if (((CANMSGOBJ0_CAN_MOIPR1 & CANMSGOBJ0_CAN_MOIPR1_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR1_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR1.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ1.CAN_MOSTAT1.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG1_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ1.CAN_MOCTR1.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 1 Received */
  #if (((CANMSGOBJ0_CAN_MOIPR1 & CANMSGOBJ0_CAN_MOIPR1_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR1_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR1.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ1.CAN_MOSTAT1.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG1_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ1.CAN_MOCTR1.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 1 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR1 & CANMSGOBJ0_CAN_MOIPR1_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR1_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR1.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR1.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ1.CAN_MOSTAT1.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG1_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ1.CAN_MOCTR1.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 1 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR1 & CANMSGOBJ0_CAN_MOIPR1_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR1_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR1.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR1.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ1.CAN_MOSTAT1.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG1_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ1.CAN_MOCTR1.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 2 Transmitted    */
  #if (((CANMSGOBJ0_CAN_MOIPR2 & CANMSGOBJ0_CAN_MOIPR2_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR2_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR2.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ2.CAN_MOSTAT2.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG2_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ2.CAN_MOCTR2.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 2 Received    */
  #if (((CANMSGOBJ0_CAN_MOIPR2 & CANMSGOBJ0_CAN_MOIPR2_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR2_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR2.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ2.CAN_MOSTAT2.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG2_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ2.CAN_MOCTR2.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 2 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR2 & CANMSGOBJ0_CAN_MOIPR2_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR2_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR2.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR2.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ2.CAN_MOSTAT2.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG2_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ2.CAN_MOCTR2.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 2 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR2 & CANMSGOBJ0_CAN_MOIPR2_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR2_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR2.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR2.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ2.CAN_MOSTAT2.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG2_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ2.CAN_MOCTR2.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 3 Transmitted    */
  #if (((CANMSGOBJ0_CAN_MOIPR3 & CANMSGOBJ0_CAN_MOIPR3_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR3_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR3.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ3.CAN_MOSTAT3.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG3_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ3.CAN_MOCTR3.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 3 Received    */
  #if (((CANMSGOBJ0_CAN_MOIPR3 & CANMSGOBJ0_CAN_MOIPR3_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR3_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR3.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ3.CAN_MOSTAT3.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG3_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ3.CAN_MOCTR3.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 3 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR3 & CANMSGOBJ0_CAN_MOIPR3_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR3_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR3.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR3.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ3.CAN_MOSTAT3.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG3_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ3.CAN_MOCTR3.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 3 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR3 & CANMSGOBJ0_CAN_MOIPR3_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR3_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR3.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR3.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ3.CAN_MOSTAT3.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG3_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ3.CAN_MOCTR3.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 4 Transmitted    */
  #if (((CANMSGOBJ0_CAN_MOIPR4 & CANMSGOBJ0_CAN_MOIPR4_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR4_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR4.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ4.CAN_MOSTAT4.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG4_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ4.CAN_MOCTR4.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 4 Received    */
  #if (((CANMSGOBJ0_CAN_MOIPR4 & CANMSGOBJ0_CAN_MOIPR4_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR4_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR4.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ4.CAN_MOSTAT4.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG4_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ4.CAN_MOCTR4.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 4 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR4 & CANMSGOBJ0_CAN_MOIPR4_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR4_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR4.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR4.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ4.CAN_MOSTAT4.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG4_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ4.CAN_MOCTR4.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 4 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR4 & CANMSGOBJ0_CAN_MOIPR4_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR4_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR4.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR4.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ4.CAN_MOSTAT4.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG4_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ4.CAN_MOCTR4.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 5 Transmitted    */
  #if (((CANMSGOBJ0_CAN_MOIPR5 & CANMSGOBJ0_CAN_MOIPR5_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR5_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR5.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ5.CAN_MOSTAT5.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG5_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ5.CAN_MOCTR5.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 5 Received    */
  #if (((CANMSGOBJ0_CAN_MOIPR5 & CANMSGOBJ0_CAN_MOIPR5_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR5_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR5.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ5.CAN_MOSTAT5.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG5_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ5.CAN_MOCTR5.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 5 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR5 & CANMSGOBJ0_CAN_MOIPR5_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR5_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR5.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR5.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ5.CAN_MOSTAT5.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG5_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ5.CAN_MOCTR5.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 5 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR5 & CANMSGOBJ0_CAN_MOIPR5_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR5_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR5.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR5.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ5.CAN_MOSTAT5.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG5_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ5.CAN_MOCTR5.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 6 Transmitted    */
  #if (((CANMSGOBJ0_CAN_MOIPR6 & CANMSGOBJ0_CAN_MOIPR6_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR6_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR6.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ6.CAN_MOSTAT6.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG6_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ6.CAN_MOCTR6.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 6 Received    */
  #if (((CANMSGOBJ0_CAN_MOIPR6 & CANMSGOBJ0_CAN_MOIPR6_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR6_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR6.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ6.CAN_MOSTAT6.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG6_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ6.CAN_MOCTR6.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 6 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR6 & CANMSGOBJ0_CAN_MOIPR6_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR6_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR6.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR6.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ6.CAN_MOSTAT6.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG6_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ6.CAN_MOCTR6.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 6 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR6 & CANMSGOBJ0_CAN_MOIPR6_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR6_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR6.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR6.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ6.CAN_MOSTAT6.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG6_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ6.CAN_MOCTR6.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 7 Transmitted    */
  #if (((CANMSGOBJ0_CAN_MOIPR7 & CANMSGOBJ0_CAN_MOIPR7_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR7_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR7.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ7.CAN_MOSTAT7.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG7_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ7.CAN_MOCTR7.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 7 Received    */
  #if (((CANMSGOBJ0_CAN_MOIPR7 & CANMSGOBJ0_CAN_MOIPR7_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR7_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR7.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ7.CAN_MOSTAT7.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG7_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ7.CAN_MOCTR7.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 7 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR7 & CANMSGOBJ0_CAN_MOIPR7_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR7_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR7.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR7.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ7.CAN_MOSTAT7.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG7_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ7.CAN_MOCTR7.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 7 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR7 & CANMSGOBJ0_CAN_MOIPR7_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR7_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR7.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR7.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ7.CAN_MOSTAT7.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG7_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ7.CAN_MOCTR7.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 8 Transmitted    */
  #if (((CANMSGOBJ0_CAN_MOIPR8 & CANMSGOBJ0_CAN_MOIPR8_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR8_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR8.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ8.CAN_MOSTAT8.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG8_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ8.CAN_MOCTR8.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 8 Received    */
  #if (((CANMSGOBJ0_CAN_MOIPR8 & CANMSGOBJ0_CAN_MOIPR8_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR8_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR8.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ8.CAN_MOSTAT8.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG8_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ8.CAN_MOCTR8.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 8 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR8 & CANMSGOBJ0_CAN_MOIPR8_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR8_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR8.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR8.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ8.CAN_MOSTAT8.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG8_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ8.CAN_MOCTR8.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 8 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR8 & CANMSGOBJ0_CAN_MOIPR8_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR8_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR8.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR8.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ8.CAN_MOSTAT8.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG8_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ8.CAN_MOCTR8.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 9 Transmitted    */
  #if (((CANMSGOBJ0_CAN_MOIPR9 & CANMSGOBJ0_CAN_MOIPR9_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR9_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR9.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ9.CAN_MOSTAT9.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG9_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ9.CAN_MOCTR9.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 9 Received    */
  #if (((CANMSGOBJ0_CAN_MOIPR9 & CANMSGOBJ0_CAN_MOIPR9_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR9_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR9.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ9.CAN_MOSTAT9.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG9_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ9.CAN_MOCTR9.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 9 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR9 & CANMSGOBJ0_CAN_MOIPR9_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR9_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR9.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR9.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ9.CAN_MOSTAT9.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG9_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ9.CAN_MOCTR9.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 9 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR9 & CANMSGOBJ0_CAN_MOIPR9_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR9_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR9.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR9.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ9.CAN_MOSTAT9.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG9_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ9.CAN_MOCTR9.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 10 Transmitted    */
  #if (((CANMSGOBJ0_CAN_MOIPR10 & CANMSGOBJ0_CAN_MOIPR10_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR10_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR10.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ10.CAN_MOSTAT10.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG10_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ10.CAN_MOCTR10.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 10 Received    */
  #if (((CANMSGOBJ0_CAN_MOIPR10 & CANMSGOBJ0_CAN_MOIPR10_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR10_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR10.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ10.CAN_MOSTAT10.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG10_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ10.CAN_MOCTR10.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 10 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR10 & CANMSGOBJ0_CAN_MOIPR10_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR10_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR10.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR10.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ10.CAN_MOSTAT10.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG10_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ10.CAN_MOCTR10.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 10 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR10 & CANMSGOBJ0_CAN_MOIPR10_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR10_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR10.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR10.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ10.CAN_MOSTAT10.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG10_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ10.CAN_MOCTR10.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 11 Transmitted    */
  #if (((CANMSGOBJ0_CAN_MOIPR11 & CANMSGOBJ0_CAN_MOIPR11_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR11_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR11.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ11.CAN_MOSTAT11.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG11_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ11.CAN_MOCTR11.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 11 Received    */
  #if (((CANMSGOBJ0_CAN_MOIPR11 & CANMSGOBJ0_CAN_MOIPR11_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR11_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR11.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ11.CAN_MOSTAT11.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG11_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ11.CAN_MOCTR11.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 11 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR11 & CANMSGOBJ0_CAN_MOIPR11_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR11_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR11.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR11.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ11.CAN_MOSTAT11.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG11_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ11.CAN_MOCTR11.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 11 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR11 & CANMSGOBJ0_CAN_MOIPR11_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR11_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR11.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR11.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ11.CAN_MOSTAT11.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG11_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ11.CAN_MOCTR11.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 12 Transmitted    */
  #if (((CANMSGOBJ0_CAN_MOIPR12 & CANMSGOBJ0_CAN_MOIPR12_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR12_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR12.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ12.CAN_MOSTAT12.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG12_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ12.CAN_MOCTR12.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 12 Received    */
  #if (((CANMSGOBJ0_CAN_MOIPR12 & CANMSGOBJ0_CAN_MOIPR12_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR12_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR12.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ12.CAN_MOSTAT12.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG12_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ12.CAN_MOCTR12.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 12 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR12 & CANMSGOBJ0_CAN_MOIPR12_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR12_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR12.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR12.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ12.CAN_MOSTAT12.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG12_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ12.CAN_MOCTR12.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 12 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR12 & CANMSGOBJ0_CAN_MOIPR12_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR12_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR12.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR12.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ12.CAN_MOSTAT12.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG12_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ12.CAN_MOCTR12.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 13 Transmitted    */
  #if (((CANMSGOBJ0_CAN_MOIPR13 & CANMSGOBJ0_CAN_MOIPR13_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR13_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR13.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ13.CAN_MOSTAT13.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG13_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ13.CAN_MOCTR13.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 13 Received    */
  #if (((CANMSGOBJ0_CAN_MOIPR13 & CANMSGOBJ0_CAN_MOIPR13_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR13_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR13.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ13.CAN_MOSTAT13.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG13_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ13.CAN_MOCTR13.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 13 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR13 & CANMSGOBJ0_CAN_MOIPR13_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR13_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR13.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR13.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ13.CAN_MOSTAT13.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG13_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ13.CAN_MOCTR13.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 13 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR13 & CANMSGOBJ0_CAN_MOIPR13_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR13_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR13.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR13.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ13.CAN_MOSTAT13.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG13_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ13.CAN_MOCTR13.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 14 Transmitted    */
  #if (((CANMSGOBJ0_CAN_MOIPR14 & CANMSGOBJ0_CAN_MOIPR14_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR14_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR14.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ14.CAN_MOSTAT14.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG14_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ14.CAN_MOCTR14.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 14 Received    */
  #if (((CANMSGOBJ0_CAN_MOIPR14 & CANMSGOBJ0_CAN_MOIPR14_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR14_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR14.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ14.CAN_MOSTAT14.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG14_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ14.CAN_MOCTR14.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 14 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR14 & CANMSGOBJ0_CAN_MOIPR14_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR14_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR14.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR14.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ14.CAN_MOSTAT14.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG14_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ14.CAN_MOCTR14.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 14 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR14 & CANMSGOBJ0_CAN_MOIPR14_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR14_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR14.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR14.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ14.CAN_MOSTAT14.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG14_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ14.CAN_MOCTR14.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 15 Transmitted    */
  #if (((CANMSGOBJ0_CAN_MOIPR15 & CANMSGOBJ0_CAN_MOIPR15_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR15_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR15.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ15.CAN_MOSTAT15.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG15_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ15.CAN_MOCTR15.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 15 Received    */
  #if (((CANMSGOBJ0_CAN_MOIPR15 & CANMSGOBJ0_CAN_MOIPR15_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR15_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR15.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ15.CAN_MOSTAT15.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG15_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ15.CAN_MOCTR15.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 15 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR15 & CANMSGOBJ0_CAN_MOIPR15_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR15_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR15.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR15.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ15.CAN_MOSTAT15.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG15_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ15.CAN_MOCTR15.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 15 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR15 & CANMSGOBJ0_CAN_MOIPR15_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR15_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR15.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR15.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ15.CAN_MOSTAT15.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG15_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ15.CAN_MOCTR15.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 16 Transmitted    */
  #if (((CANMSGOBJ0_CAN_MOIPR16 & CANMSGOBJ0_CAN_MOIPR16_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR16_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR16.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ16.CAN_MOSTAT16.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG16_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ16.CAN_MOCTR16.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 16 Received    */
  #if (((CANMSGOBJ0_CAN_MOIPR16 & CANMSGOBJ0_CAN_MOIPR16_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR16_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR16.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ16.CAN_MOSTAT16.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG16_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ16.CAN_MOCTR16.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 16 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR16 & CANMSGOBJ0_CAN_MOIPR16_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR16_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR16.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR16.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ16.CAN_MOSTAT16.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG16_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ16.CAN_MOCTR16.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 16 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR16 & CANMSGOBJ0_CAN_MOIPR16_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR16_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR16.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR16.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ16.CAN_MOSTAT16.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG16_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ16.CAN_MOCTR16.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 17 Transmitted    */
  #if (((CANMSGOBJ0_CAN_MOIPR17 & CANMSGOBJ0_CAN_MOIPR17_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR17_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR17.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ17.CAN_MOSTAT17.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG17_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ17.CAN_MOCTR17.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 17 Received    */
  #if (((CANMSGOBJ0_CAN_MOIPR17 & CANMSGOBJ0_CAN_MOIPR17_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR17_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR17.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ17.CAN_MOSTAT17.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG17_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ17.CAN_MOCTR17.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 17 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR17 & CANMSGOBJ0_CAN_MOIPR17_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR17_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR17.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR17.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ17.CAN_MOSTAT17.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG17_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ17.CAN_MOCTR17.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 17 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR17 & CANMSGOBJ0_CAN_MOIPR17_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR17_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR17.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR17.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ17.CAN_MOSTAT17.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG17_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ17.CAN_MOCTR17.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 18 Transmitted    */
  #if (((CANMSGOBJ0_CAN_MOIPR18 & CANMSGOBJ0_CAN_MOIPR18_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR18_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR18.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ18.CAN_MOSTAT18.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG18_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ18.CAN_MOCTR18.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 18 Received    */
  #if (((CANMSGOBJ0_CAN_MOIPR18 & CANMSGOBJ0_CAN_MOIPR18_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR18_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR18.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ18.CAN_MOSTAT18.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG18_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ18.CAN_MOCTR18.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 18 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR18 & CANMSGOBJ0_CAN_MOIPR18_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR18_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR18.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR18.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ18.CAN_MOSTAT18.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG18_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ18.CAN_MOCTR18.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 18 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR18 & CANMSGOBJ0_CAN_MOIPR18_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR18_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR18.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR18.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ18.CAN_MOSTAT18.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG18_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ18.CAN_MOCTR18.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 19 Transmitted    */
  #if (((CANMSGOBJ0_CAN_MOIPR19 & CANMSGOBJ0_CAN_MOIPR19_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR19_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR19.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ19.CAN_MOSTAT19.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG19_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ19.CAN_MOCTR19.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 19 Received    */
  #if (((CANMSGOBJ0_CAN_MOIPR19 & CANMSGOBJ0_CAN_MOIPR19_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR19_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR19.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ19.CAN_MOSTAT19.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG19_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ19.CAN_MOCTR19.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 19 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR19 & CANMSGOBJ0_CAN_MOIPR19_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR19_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR19.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR19.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ19.CAN_MOSTAT19.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG19_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ19.CAN_MOCTR19.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 19 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR19 & CANMSGOBJ0_CAN_MOIPR19_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR19_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR19.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR19.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ19.CAN_MOSTAT19.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG19_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ19.CAN_MOCTR19.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 20 Transmitted    */
  #if (((CANMSGOBJ0_CAN_MOIPR20 & CANMSGOBJ0_CAN_MOIPR20_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR20_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR20.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ20.CAN_MOSTAT20.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG20_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ20.CAN_MOCTR20.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 20 Received    */
  #if (((CANMSGOBJ0_CAN_MOIPR20 & CANMSGOBJ0_CAN_MOIPR20_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR20_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR20.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ20.CAN_MOSTAT20.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG20_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ20.CAN_MOCTR20.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 20 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR20 & CANMSGOBJ0_CAN_MOIPR20_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR20_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR20.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR20.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ20.CAN_MOSTAT20.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG20_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ20.CAN_MOCTR20.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 20 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR20 & CANMSGOBJ0_CAN_MOIPR20_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR20_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR20.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR20.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ20.CAN_MOSTAT20.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG20_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ20.CAN_MOCTR20.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 21 Transmitted    */
  #if (((CANMSGOBJ0_CAN_MOIPR21 & CANMSGOBJ0_CAN_MOIPR21_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR21_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR21.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ21.CAN_MOSTAT21.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG21_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ21.CAN_MOCTR21.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 21 Received    */
  #if (((CANMSGOBJ0_CAN_MOIPR21 & CANMSGOBJ0_CAN_MOIPR21_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR21_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR21.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ21.CAN_MOSTAT21.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG21_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ21.CAN_MOCTR21.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 21 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR21 & CANMSGOBJ0_CAN_MOIPR21_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR21_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR21.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR21.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ21.CAN_MOSTAT21.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG21_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ21.CAN_MOCTR21.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 21 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR21 & CANMSGOBJ0_CAN_MOIPR21_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR21_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR21.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR21.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ21.CAN_MOSTAT21.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG21_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ21.CAN_MOCTR21.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 22 Transmitted    */
  #if (((CANMSGOBJ0_CAN_MOIPR22 & CANMSGOBJ0_CAN_MOIPR22_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR22_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR22.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ22.CAN_MOSTAT22.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG22_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ22.CAN_MOCTR22.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 22 Received    */
  #if (((CANMSGOBJ0_CAN_MOIPR22 & CANMSGOBJ0_CAN_MOIPR22_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR22_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR22.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ22.CAN_MOSTAT22.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG22_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ22.CAN_MOCTR22.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 22 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR22 & CANMSGOBJ0_CAN_MOIPR22_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR22_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR22.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR22.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ22.CAN_MOSTAT22.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG22_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ22.CAN_MOCTR22.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 22 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR22 & CANMSGOBJ0_CAN_MOIPR22_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR22_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR22.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR22.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ22.CAN_MOSTAT22.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG22_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ22.CAN_MOCTR22.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 23 Transmitted    */
  #if (((CANMSGOBJ0_CAN_MOIPR23 & CANMSGOBJ0_CAN_MOIPR23_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR23_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR23.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ23.CAN_MOSTAT23.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG23_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ23.CAN_MOCTR23.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 23 Received    */
  #if (((CANMSGOBJ0_CAN_MOIPR23 & CANMSGOBJ0_CAN_MOIPR23_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR23_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR23.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ23.CAN_MOSTAT23.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG23_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ23.CAN_MOCTR23.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 23 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR23 & CANMSGOBJ0_CAN_MOIPR23_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR23_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR23.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR23.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ23.CAN_MOSTAT23.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG23_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ23.CAN_MOCTR23.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 23 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR23 & CANMSGOBJ0_CAN_MOIPR23_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR23_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR23.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR23.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ23.CAN_MOSTAT23.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG23_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ23.CAN_MOCTR23.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 24 Transmitted    */
  #if (((CANMSGOBJ0_CAN_MOIPR24 & CANMSGOBJ0_CAN_MOIPR24_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR24_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR24.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ24.CAN_MOSTAT24.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG24_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ24.CAN_MOCTR24.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 24 Received    */
  #if (((CANMSGOBJ0_CAN_MOIPR24 & CANMSGOBJ0_CAN_MOIPR24_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR24_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR24.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ24.CAN_MOSTAT24.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG24_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ24.CAN_MOCTR24.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 24 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR24 & CANMSGOBJ0_CAN_MOIPR24_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR24_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR24.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR24.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ24.CAN_MOSTAT24.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG24_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ24.CAN_MOCTR24.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 24 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR24 & CANMSGOBJ0_CAN_MOIPR24_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR24_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR24.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR24.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ24.CAN_MOSTAT24.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG24_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ24.CAN_MOCTR24.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 25 Transmitted    */
  #if (((CANMSGOBJ0_CAN_MOIPR25 & CANMSGOBJ0_CAN_MOIPR25_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR25_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR25.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ25.CAN_MOSTAT25.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG25_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ25.CAN_MOCTR25.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 25 Received    */
  #if (((CANMSGOBJ0_CAN_MOIPR25 & CANMSGOBJ0_CAN_MOIPR25_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR25_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR25.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ25.CAN_MOSTAT25.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG25_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ25.CAN_MOCTR25.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 25 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR25 & CANMSGOBJ0_CAN_MOIPR25_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR25_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR25.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR25.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ25.CAN_MOSTAT25.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG25_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ25.CAN_MOCTR25.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 25 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR25 & CANMSGOBJ0_CAN_MOIPR25_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR25_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR25.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR25.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ25.CAN_MOSTAT25.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG25_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ25.CAN_MOCTR25.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 26 Transmitted    */
  #if (((CANMSGOBJ0_CAN_MOIPR26 & CANMSGOBJ0_CAN_MOIPR26_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR26_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR26.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ26.CAN_MOSTAT26.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG26_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ26.CAN_MOCTR26.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 26 Received    */
  #if (((CANMSGOBJ0_CAN_MOIPR26 & CANMSGOBJ0_CAN_MOIPR26_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR26_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR26.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ26.CAN_MOSTAT26.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG26_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ26.CAN_MOCTR26.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 26 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR26 & CANMSGOBJ0_CAN_MOIPR26_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR26_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR26.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR26.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ26.CAN_MOSTAT26.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG26_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ26.CAN_MOCTR26.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 26 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR26 & CANMSGOBJ0_CAN_MOIPR26_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR26_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR26.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR26.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ26.CAN_MOSTAT26.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG26_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ26.CAN_MOCTR26.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 27 Transmitted    */
  #if (((CANMSGOBJ0_CAN_MOIPR27 & CANMSGOBJ0_CAN_MOIPR27_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR27_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR27.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ27.CAN_MOSTAT27.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG27_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ27.CAN_MOCTR27.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 27 Received    */
  #if (((CANMSGOBJ0_CAN_MOIPR27 & CANMSGOBJ0_CAN_MOIPR27_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR27_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR27.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ27.CAN_MOSTAT27.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG27_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ27.CAN_MOCTR27.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 27 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR27 & CANMSGOBJ0_CAN_MOIPR27_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR27_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR27.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR27.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ27.CAN_MOSTAT27.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG27_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ27.CAN_MOCTR27.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 27 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR27 & CANMSGOBJ0_CAN_MOIPR27_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR27_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR27.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR27.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ27.CAN_MOSTAT27.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG27_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ27.CAN_MOCTR27.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 28 Transmitted    */
  #if (((CANMSGOBJ0_CAN_MOIPR28 & CANMSGOBJ0_CAN_MOIPR28_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR28_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR28.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ28.CAN_MOSTAT28.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG28_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ28.CAN_MOCTR28.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 28 Received    */
  #if (((CANMSGOBJ0_CAN_MOIPR28 & CANMSGOBJ0_CAN_MOIPR28_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR28_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR28.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ28.CAN_MOSTAT28.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG28_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ28.CAN_MOCTR28.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 28 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR28 & CANMSGOBJ0_CAN_MOIPR28_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR28_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR28.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR28.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ28.CAN_MOSTAT28.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG28_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ28.CAN_MOCTR28.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 28 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR28 & CANMSGOBJ0_CAN_MOIPR28_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR28_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR28.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR28.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ28.CAN_MOSTAT28.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG28_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ28.CAN_MOCTR28.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 29 Transmitted    */
  #if (((CANMSGOBJ0_CAN_MOIPR29 & CANMSGOBJ0_CAN_MOIPR29_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR29_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR29.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ29.CAN_MOSTAT29.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG29_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ29.CAN_MOCTR29.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 29 Received    */
  #if (((CANMSGOBJ0_CAN_MOIPR29 & CANMSGOBJ0_CAN_MOIPR29_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR29_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR29.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ29.CAN_MOSTAT29.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG29_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ29.CAN_MOCTR29.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 29 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR29 & CANMSGOBJ0_CAN_MOIPR29_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR29_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR29.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR29.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ29.CAN_MOSTAT29.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG29_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ29.CAN_MOCTR29.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 29 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR29 & CANMSGOBJ0_CAN_MOIPR29_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR29_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR29.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR29.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ29.CAN_MOSTAT29.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG29_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ29.CAN_MOCTR29.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 30 Transmitted    */
  #if (((CANMSGOBJ0_CAN_MOIPR30 & CANMSGOBJ0_CAN_MOIPR30_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR30_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR30.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ30.CAN_MOSTAT30.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG30_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ30.CAN_MOCTR30.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 30 Received    */
  #if (((CANMSGOBJ0_CAN_MOIPR30 & CANMSGOBJ0_CAN_MOIPR30_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR30_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR30.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ30.CAN_MOSTAT30.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG30_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ30.CAN_MOCTR30.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 30 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR30 & CANMSGOBJ0_CAN_MOIPR30_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR30_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR30.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR30.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ30.CAN_MOSTAT30.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG30_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ30.CAN_MOCTR30.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 30 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR30 & CANMSGOBJ0_CAN_MOIPR30_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR30_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR30.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR30.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ30.CAN_MOSTAT30.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG30_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ30.CAN_MOCTR30.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 31 Transmitted    */
  #if (((CANMSGOBJ0_CAN_MOIPR31 & CANMSGOBJ0_CAN_MOIPR31_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR31_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR31.bit.TXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ31.CAN_MOSTAT31.bit.TXPND == 1u)
      {
        CANMSGOBJ0_MSG31_TXPND_CALLBACK();
        CANMSGOBJ0->OBJ31.CAN_MOCTR31.bit.RESTXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 31 Received    */
  #if (((CANMSGOBJ0_CAN_MOIPR31 & CANMSGOBJ0_CAN_MOIPR31_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR31_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR31.bit.RXIE == 1u)
    {
      if (CANMSGOBJ0->OBJ31.CAN_MOSTAT31.bit.RXPND == 1u)
      {
        CANMSGOBJ0_MSG31_RXPND_CALLBACK();
        CANMSGOBJ0->OBJ31.CAN_MOCTR31.bit.RESRXPND = 1u;
        #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
          u8_interrupt_cnt_irq26 += 1u;
        #endif
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 31 Transmit FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR31 & CANMSGOBJ0_CAN_MOIPR31_RXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR31_RXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR31.bit.MMC == 2u)
    {
      if (CANMSGOBJ0->CAN_MOFCR31.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ31.CAN_MOSTAT31.bit.RXPND == 1u)
        {
          CANMSGOBJ0_MSG31_TXOVF_CALLBACK();
          CANMSGOBJ0->OBJ31.CAN_MOCTR31.bit.RESRXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

  /* CANMSGOBJ0 Message 31 Receive FIFO Buffer Full */
  #if (((CANMSGOBJ0_CAN_MOIPR31 & CANMSGOBJ0_CAN_MOIPR31_TXINP_Msk) >>  CANMSGOBJ0_CAN_MOIPR31_TXINP_Pos) == CAN_INP_NVIC_IRQ26)
    if (CANMSGOBJ0->CAN_MOFCR31.bit.MMC == 1u)
    {
      if (CANMSGOBJ0->CAN_MOFCR31.bit.OVIE == 1u)
      {
        if (CANMSGOBJ0->OBJ31.CAN_MOSTAT31.bit.TXPND == 1u)
        {
          CANMSGOBJ0_MSG31_RXOVF_CALLBACK();
          CANMSGOBJ0->OBJ31.CAN_MOCTR31.bit.RESTXPND = 1u;
          #if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq26 += 1u;
          #endif
        }
      }
    }
  #endif /* Interrupt assigned to this node */

}
#endif /* ((CPU_NVIC_ISER & CPU_NVIC_ISER_IRQEN26_Msk) == 1u) */
