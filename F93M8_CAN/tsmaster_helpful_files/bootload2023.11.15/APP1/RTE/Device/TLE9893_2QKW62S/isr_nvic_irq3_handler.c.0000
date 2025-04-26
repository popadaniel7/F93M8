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

#include "isr.h"
#include "tle989x.h"
#include "isr_defines.h"


/* Check if NVIC node 3 is enabled */
#if ((CPU_NVIC_ISER & CPU_NVIC_ISER_IRQEN3_Msk) == (1u << CPU_NVIC_ISER_IRQEN3_Pos))

/*******************************************************************************
**                        Global Variable Definitions                         **
*******************************************************************************/

#if (NVIC_IRQ3_HANDLER_INT_CHECK == 1)
  uint8 u8_interrupt_cnt_irq3;
#endif

/*******************************************************************************
**                        Global Function Declarations                        **
*******************************************************************************/

/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

void NVIC_IRQ3_Handler(void)
{
  #if (NVIC_IRQ3_HANDLER_INT_CHECK == 1)
    u8_interrupt_cnt_irq3 = 0;
  #endif
  /* T12 OM */
  #if (CCU7_T12_OM_INT_EN == 1)
    #if (((CCU7_INP & CCU7_INP_INPT12_Msk) >>  CCU7_INP_INPT12_Pos) == CCU7_INP_NVIC_IRQ3)
      if (CCU7->IEN.bit.ENT12OM == 1u)
      {
        if (CCU7->IS.bit.T12OM == 1u)
        {
          CCU7_T12_OM_CALLBACK();
          CCU7->ISR.bit.RT12OM = 1u;
          #if (NVIC_IRQ3_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq3 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* T12 PM */
  #if (CCU7_T12_PM_INT_EN == 1)
    #if (((CCU7_INP & CCU7_INP_INPT12_Msk) >>  CCU7_INP_INPT12_Pos) == CCU7_INP_NVIC_IRQ3)
      if (CCU7->IEN.bit.ENT12PM == 1u)
      {
        if (CCU7->IS.bit.T12PM == 1u)
        {
          CCU7_T12_PM_CALLBACK();
          CCU7->ISR.bit.RT12PM = 1u;
          #if (NVIC_IRQ3_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq3 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* T13 CM */
  #if (CCU7_T13_CM_INT_EN == 1)
    #if (((CCU7_INP & CCU7_INP_INPT13_Msk) >>  CCU7_INP_INPT13_Pos) == CCU7_INP_NVIC_IRQ3)
      if (CCU7->IEN.bit.ENT13CM == 1u)
      {
        if (CCU7->IS.bit.T13CM == 1u)
        {
          CCU7_T13_CM_CALLBACK();
          CCU7->ISR.bit.RT13CM = 1u;
          #if (NVIC_IRQ3_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq3 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* T13 PM */
  #if (CCU7_T13_PM_INT_EN == 1)
    #if (((CCU7_INP & CCU7_INP_INPT13_Msk) >>  CCU7_INP_INPT13_Pos) == CCU7_INP_NVIC_IRQ3)
      if (CCU7->IEN.bit.ENT13PM == 1u)
      {
        if (CCU7->IS.bit.T13PM == 1u)
        {
          CCU7_T13_PM_CALLBACK();
          CCU7->ISR.bit.RT13PM = 1u;
          #if (NVIC_IRQ3_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq3 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* T14 CM */
  #if (CCU7_T14_CM_INT_EN == 1)
    #if (((CCU7_INP_2 & CCU7_INP_2_INPT14_Msk) >>  CCU7_INP_2_INPT14_Pos) == CCU7_INP_NVIC_IRQ3)
      if (CCU7->IEN_2.bit.ENT14CM == 1u)
      {
        if (CCU7->IS_2.bit.T14CM == 1u)
        {
          CCU7_T14_CM_CALLBACK();
          CCU7->ISR_2.bit.RT14CM = 1u;
          #if (NVIC_IRQ3_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq3 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* T14 PM */
  #if (CCU7_T14_PM_INT_EN == 1)
    #if (((CCU7_INP_2 & CCU7_INP_2_INPT14_Msk) >>  CCU7_INP_2_INPT14_Pos) == CCU7_INP_NVIC_IRQ3)
      if (CCU7->IEN_2.bit.ENT14PM == 1u)
      {
        if (CCU7->IS_2.bit.T14PM == 1u)
        {
          CCU7_T14_PM_CALLBACK();
          CCU7->ISR_2.bit.RT14PM = 1u;
          #if (NVIC_IRQ3_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq3 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* T15 CM */
  #if (CCU7_T15_CM_INT_EN == 1)
    #if (((CCU7_INP_2 & CCU7_INP_2_INPT15_Msk) >>  CCU7_INP_2_INPT15_Pos) == CCU7_INP_NVIC_IRQ3)
      if (CCU7->IEN_2.bit.ENT15CM == 1u)
      {
        if (CCU7->IS_2.bit.T15CM == 1u)
        {
          CCU7_T15_CM_CALLBACK();
          CCU7->ISR_2.bit.RT15CM = 1u;
          #if (NVIC_IRQ3_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq3 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* T15 PM */
  #if (CCU7_T15_PM_INT_EN == 1)
    #if (((CCU7_INP_2 & CCU7_INP_2_INPT15_Msk) >>  CCU7_INP_2_INPT15_Pos) == CCU7_INP_NVIC_IRQ3)
      if (CCU7->IEN_2.bit.ENT15PM == 1u)
      {
        if (CCU7->IS_2.bit.T15PM == 1u)
        {
          CCU7_T15_PM_CALLBACK();
          CCU7->ISR_2.bit.RT15PM = 1u;
          #if (NVIC_IRQ3_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq3 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* T16 CM */
  #if (CCU7_T16_CM_INT_EN == 1)
    #if (((CCU7_INP_2 & CCU7_INP_2_INPT16_Msk) >>  CCU7_INP_2_INPT16_Pos) == CCU7_INP_NVIC_IRQ3)
      if (CCU7->IEN_2.bit.ENT16CM == 1u)
      {
        if (CCU7->IS_2.bit.T16CM == 1u)
        {
          CCU7_T16_CM_CALLBACK();
          CCU7->ISR_2.bit.RT16CM = 1u;
          #if (NVIC_IRQ3_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq3 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* T16 PM */
  #if (CCU7_T16_PM_INT_EN == 1)
    #if (((CCU7_INP_2 & CCU7_INP_2_INPT16_Msk) >>  CCU7_INP_2_INPT16_Pos) == CCU7_INP_NVIC_IRQ3)
      if (CCU7->IEN_2.bit.ENT16PM == 1u)
      {
        if (CCU7->IS_2.bit.T16PM == 1u)
        {
          CCU7_T16_PM_CALLBACK();
          CCU7->ISR_2.bit.RT16PM = 1u;
          #if (NVIC_IRQ3_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq3 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* C70A CCM R */
  #if (CCU7_CC70A_CM_R_INT_EN == 1)
    #if (((CCU7_INP & CCU7_INP_INPCC70_Msk) >>  CCU7_INP_INPCC70_Pos) == CCU7_INP_NVIC_IRQ3)
      if (CCU7->IEN.bit.ENCC70R == 1u)
      {
        if (CCU7->IS.bit.ICC70R == 1u)
        {
          CCU7_CC70A_CM_R_CALLBACK();
          CCU7->ISR.bit.RCC70R = 1u;
          #if (NVIC_IRQ3_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq3 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* C70A CCM F */
  #if (CCU7_CC70A_CM_F_INT_EN == 1)
    #if (((CCU7_INP & CCU7_INP_INPCC70_Msk) >>  CCU7_INP_INPCC70_Pos) == CCU7_INP_NVIC_IRQ3)
      if (CCU7->IEN.bit.ENCC70F == 1u)
      {
        if (CCU7->IS.bit.ICC70F == 1u)
        {
          CCU7_CC70A_CM_F_CALLBACK();
          CCU7->ISR.bit.RCC70F = 1u;
          #if (NVIC_IRQ3_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq3 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* C71A CCM R */
  #if (CCU7_CC71A_CM_R_INT_EN == 1)
    #if (((CCU7_INP & CCU7_INP_INPCC71_Msk) >>  CCU7_INP_INPCC71_Pos) == CCU7_INP_NVIC_IRQ3)
      if (CCU7->IEN.bit.ENCC71R == 1u)
      {
        if (CCU7->IS.bit.ICC71R == 1u)
        {
          CCU7_CC71A_CM_R_CALLBACK();
          CCU7->ISR.bit.RCC71R = 1u;
          #if (NVIC_IRQ3_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq3 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* C71A CCM F */
  #if (CCU7_CC71A_CM_F_INT_EN == 1)
    #if (((CCU7_INP & CCU7_INP_INPCC71_Msk) >>  CCU7_INP_INPCC71_Pos) == CCU7_INP_NVIC_IRQ3)
      if (CCU7->IEN.bit.ENCC71F == 1u)
      {
        if (CCU7->IS.bit.ICC71F == 1u)
        {
          CCU7_CC71A_CM_F_CALLBACK();
          CCU7->ISR.bit.RCC71F = 1u;
          #if (NVIC_IRQ3_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq3 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* C72A CCM R */
  #if (CCU7_CC71A_CM_R_INT_EN == 1)
    #if (((CCU7_INP & CCU7_INP_INPCC72_Msk) >>  CCU7_INP_INPCC72_Pos) == CCU7_INP_NVIC_IRQ3)
      if (CCU7->IEN.bit.ENCC72R == 1u)
      {
        if (CCU7->IS.bit.ICC72R == 1u)
        {
          CCU7_CC72A_CM_R_CALLBACK();
          CCU7->ISR.bit.RCC72R = 1u;
          #if (NVIC_IRQ3_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq3 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* C72A CCM F */
  #if (CCU7_CC71A_CM_F_INT_EN == 1)
    #if (((CCU7_INP & CCU7_INP_INPCC72_Msk) >>  CCU7_INP_INPCC72_Pos) == CCU7_INP_NVIC_IRQ3)
      if (CCU7->IEN.bit.ENCC72F == 1u)
      {
        if (CCU7->IS.bit.ICC72F == 1u)
        {
          CCU7_CC72A_CM_F_CALLBACK();
          CCU7->ISR.bit.RCC72F = 1u;
          #if (NVIC_IRQ3_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq3 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* C70B CM R */
  #if (CCU7_C70B_CM_R_INT_EN == 1)
    #if (((CCU7_INP_2 & CCU7_INP_2_INPCC70B_Msk) >>  CCU7_INP_2_INPCC70B_Pos) == CCU7_INP_NVIC_IRQ3)
      if (CCU7->IEN_2.bit.ENCC70BR == 1u)
      {
        if (CCU7->IS_2.bit.ICC70BR == 1u)
        {
          CCU7_C70B_CM_R_CALLBACK();
          CCU7->ISR_2.bit.RCC70BR = 1u;
          #if (NVIC_IRQ3_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq3 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* C70B CM F */
  #if (CCU7_C70B_CM_F_INT_EN == 1)
    #if (((CCU7_INP_2 & CCU7_INP_2_INPCC70B_Msk) >>  CCU7_INP_2_INPCC70B_Pos) == CCU7_INP_NVIC_IRQ3)
      if (CCU7->IEN_2.bit.ENCC70BF == 1u)
      {
        if (CCU7->IS_2.bit.ICC70BF == 1u)
        {
          CCU7_C70B_CM_F_CALLBACK();
          CCU7->ISR_2.bit.RCC70BF = 1u;
          #if (NVIC_IRQ3_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq3 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* C71B CM R */
  #if (CCU7_C71B_CM_R_INT_EN == 1)
    #if (((CCU7_INP_2 & CCU7_INP_2_INPCC71B_Msk) >>  CCU7_INP_2_INPCC71B_Pos) == CCU7_INP_NVIC_IRQ3)
      if (CCU7->IEN_2.bit.ENCC71BR == 1u)
      {
        if (CCU7->IS_2.bit.ICC71BR == 1u)
        {
          CCU7_C71B_CM_R_CALLBACK();
          CCU7->ISR_2.bit.RCC71BR = 1u;
          #if (NVIC_IRQ3_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq3 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* C71B CM F */
  #if (CCU7_C71B_CM_F_INT_EN == 1)
    #if (((CCU7_INP_2 & CCU7_INP_2_INPCC71B_Msk) >>  CCU7_INP_2_INPCC71B_Pos) == CCU7_INP_NVIC_IRQ3)
      if (CCU7->IEN_2.bit.ENCC71BF == 1u)
      {
        if (CCU7->IS_2.bit.ICC71BF == 1u)
        {
          CCU7_C71B_CM_F_CALLBACK();
          CCU7->ISR_2.bit.RCC71BF = 1u;
          #if (NVIC_IRQ3_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq3 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* C72B CM R */
  #if (CCU7_C72B_CM_R_INT_EN == 1)
    #if (((CCU7_INP_2 & CCU7_INP_2_INPCC72B_Msk) >>  CCU7_INP_2_INPCC72B_Pos) == CCU7_INP_NVIC_IRQ3)
      if (CCU7->IEN_2.bit.ENCC72BR == 1u)
      {
        if (CCU7->IS_2.bit.ICC72BR == 1u)
        {
          CCU7_C72B_CM_R_CALLBACK();
          CCU7->ISR_2.bit.RCC72BR = 1u;
          #if (NVIC_IRQ3_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq3 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* C72B CM F */
  #if (CCU7_C72B_CM_F_INT_EN == 1)
    #if (((CCU7_INP_2 & CCU7_INP_2_INPCC72B_Msk) >>  CCU7_INP_2_INPCC72B_Pos) == CCU7_INP_NVIC_IRQ3)
      if (CCU7->IEN_2.bit.ENCC72BF == 1u)
      {
        if (CCU7->IS_2.bit.ICC72BF == 1u)
        {
          CCU7_C72B_CM_F_CALLBACK();
          CCU7->ISR_2.bit.RCC72BF = 1u;
          #if (NVIC_IRQ3_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq3 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* Trap Flag */
  #if (CCU7_TRAP_INT_EN == 1)
    #if (((CCU7_INP & CCU7_INP_INPERR_Msk) >>  CCU7_INP_INPERR_Pos) == CCU7_INP_NVIC_IRQ3)
      if (CCU7->IEN.bit.ENTRPF == 1u)
      {
        if (CCU7->IS.bit.TRPF == 1u)
        {
          CCU7_TRAP_CALLBACK();
          CCU7->ISR.bit.RTRPF = 1u;
          #if (NVIC_IRQ3_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq3 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* Correct Hall Event */
  #if (CCU7_CORRECT_HALL_INT_EN == 1)
    #if (((CCU7_INP & CCU7_INP_INPCHE_Msk) >>  CCU7_INP_INPCHE_Pos) == CCU7_INP_NVIC_IRQ3)
      if (CCU7->IEN.bit.ENCHE == 1u)
      {
        if (CCU7->IS.bit.CHE == 1u)
        {
          CCU7_CORRECT_HALL_CALLBACK();
          CCU7->ISR.bit.RCHE = 1u;
          #if (NVIC_IRQ3_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq3 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* Wrong Hall Event */
  #if (CCU7_WRONG_HALL_INT_EN == 1)
    #if (((CCU7_INP & CCU7_INP_INPERR_Msk) >>  CCU7_INP_INPERR_Pos) == CCU7_INP_NVIC_IRQ3)
      if (CCU7->IEN.bit.ENWHE == 1u)
      {
        if (CCU7->IS.bit.WHE == 1u)
        {
          CCU7_WRONG_HALL_CALLBACK();
          CCU7->ISR.bit.RWHE = 1u;
          #if (NVIC_IRQ3_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq3 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* MCM Shadow Transfer */
  #if (CCU7_MCM_STR_INT_EN == 1)
    #if (((CCU7_INP & CCU7_INP_INPCHE_Msk) >>  CCU7_INP_INPCHE_Pos) == CCU7_INP_NVIC_IRQ3)
      if (CCU7->IEN.bit.ENSTR == 1u)
      {
        if (CCU7->IS.bit.STR == 1u)
        {
          CCU7_MCM_STR_CALLBACK();
          CCU7->ISR.bit.RSTR = 1u;
          #if (NVIC_IRQ3_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq3 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

  /* Lost Bit Event */
  #if (CCU7_LI_INT_EN == 1)
    #if (((CCU7_LI & CCU7_LI_INPLBE_Msk) >>  CCU7_LI_INPLBE_Pos) == CCU7_INP_NVIC_IRQ3)
      if (CCU7->LI.bit.LBEEN == 1u)
      {
        if (CCU7->IMON.bit.LBE == 1u)
        {
          CCU7_LI_CALLBACK();
          CCU7->IMON.bit.LBE = 1u;
          #if (NVIC_IRQ3_HANDLER_INT_CHECK == 1)
            u8_interrupt_cnt_irq3 += 1u;
          #endif
        }
      }
    #endif /* Interrupt assigned to this node */
  #endif /* Interrupt enabled */

}
#endif /* ((CPU_NVIC_ISER & CPU_NVIC_ISER_IRQEN3_Msk) == 1u) */
