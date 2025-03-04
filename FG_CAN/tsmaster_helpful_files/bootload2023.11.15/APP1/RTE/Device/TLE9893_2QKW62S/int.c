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

#include "int.h"
#include "isr_defines.h"

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

/** \brief Initialize all interrupt-related registers
 */
void INT_init(void)
{
  /* BDRV, PMU, CANTRX, ARVG, CSA/CSC */
  BDRV->IRQCLR.reg = (uint32)0xFF333333u;
  PMU->VDDC_STS_CLR.reg = (uint32)0x3u;
  PMU->VDDEXT_STS_CLR.reg = (uint32)0x3u;
  PMU->VDDP_STS_CLR.reg = (uint32)0x3u;
  CANTRX->IRQCLR.reg = (uint32)0xFu;
  ARVG->VAREF_IRQ_CLR.reg = (uint32)0x1u;
  CSACSC->IRQCLR.reg = (uint32)0x3u;
  SCU->INP0.reg = (uint32)SCU_INP0;
  BDRV->IRQEN.reg = (uint32)BDRV_IRQEN;
  PMU->VDDC_IRQEN.reg = (uint32)PMU_VDDC_IRQEN;
  PMU->VDDEXT_IRQEN.reg = (uint32)PMU_VDDEXT_IRQEN;
  PMU->VDDP_IRQEN.reg = (uint32)PMU_VDDP_IRQEN;
  CANTRX->IRQEN.reg = (uint32)CANTRX_IRQEN;
  ARVG->VAREF_IEN.reg = (uint32)ARVG_VAREF_IEN;
  CSACSC->IRQEN.reg = (uint32)CSACSC_IRQEN;
  /* EXTINT */
  SCU->EXTISC.reg = (uint32)0xFFu;
  SCU->INP4.reg = SCU_INP4;
  SCU->EXTCON.reg = (uint32)SCU_EXTCON;
  SCU->EXTIEN.reg = SCU_EXTIEN;
  /* NMIs, Core exceptions */
  SCU->NMISRC.reg = (uint32)0x7u;
  MEMCTRL->NMISRC.reg = (uint32)0x1FFu;
  SCU->NMICON.reg = (uint32)SCU_NMICON;
  MEMCTRL->NMICON.reg = (uint32)MEMCTRL_NMICON;
  /* MON */
  SCU->MONISC.reg = (uint32)0x3Fu;
  SCU->INP2.reg = SCU_INP2;
  SCU->MONIEN.reg = (uint32)SCU_MONIEN;
  SCU->MONCON.reg = (uint32)SCU_MONCON;

	
  /* ADC1 */
  ADC1->INP0.reg = (uint32)ADC1_INP0;
  ADC1->INP1.reg = (uint32)ADC1_INP1;
  ADC1->INP2.reg = (uint32)ADC1_INP2;
  ADC1->INP3.reg = (uint32)ADC1_INP3;
  ADC1->CHSTATCLR.reg = (uint32)0xFFFFFu;
  ADC1->SQSTATCLR.reg = (uint32)0xFFFu;
  ADC1->FILSTATCLR.reg = (uint32)0xFu;
  ADC1->CMPSTATCLR.reg = (uint32)0xFF00FFu;
  ADC1->IEN0.reg = (uint32)ADC1_IEN0;
  ADC1->IEN1.reg = (uint32)ADC1_IEN1;
  /* ADC2 */
  ADC2->INP0.reg = (uint32)ADC2_INP0;
  ADC2->INP2.reg = (uint32)ADC2_INP2;
  ADC2->INP3.reg = (uint32)ADC2_INP3;
  ADC2->CHSTATCLR.reg = (uint32)0x3FFFu;
  ADC2->SQSTATCLR.reg = (uint32)0xFu;
  ADC2->FILSTATCLR.reg = (uint32)0xFFu;
  ADC2->CMPSTATCLR.reg = (uint32)0xFFFFFFFFu;
  ADC2->IEN0.reg = (uint32)ADC2_IEN0;
  ADC2->IEN1.reg = (uint32)ADC2_IEN1;
  /* CCU7 */
  CCU7->ISR.reg = (uint32)0x0000F7FFu;
  CCU7->ISR_2.reg = (uint32)0x00003F3Fu;
  CCU7->IGT.reg = (uint32)CCU7_IGT;
  CCU7->INP.reg = (uint32)CCU7_INP;
  CCU7->IEN.reg = (uint32)CCU7_IEN;
  CCU7->INP_2.reg = (uint32)CCU7_INP_2;
  CCU7->IEN_2.reg = (uint32)CCU7_IEN_2;
  CCU7->LI.reg = (uint32)CCU7_LI & (uint32)0xE000u;
  /* BEMFC, SDADC (shared node) */
  BDRV->BEMFC_IRQCLR.reg = (uint32)0x3Fu;
  SCU->INP3.reg = (uint32)SCU_INP3;
  BDRV->BEMFC_IRQEN.reg = (uint32)BDRV_BEMFC_IRQEN;
#ifdef UC_FEATURE_SDADC
  SDADC->ISR.reg = (uint32)0x77u;
  SDADC->IEN.reg = SDADC_IEN;
#endif
  /* GPT12E */
  SCU->GPTISC.reg = (uint32)0x3Fu;
  SCU->INP1.reg = (uint32)SCU_INP1;
  SCU->GPTIEN.reg = (uint32)SCU_GPTIEN;
  /* SSC */
  SSC0->ISC.reg = (uint32)0x3Fu;
  SSC1->ISC.reg = (uint32)0x3Fu;
  SCU->INP6.reg = (uint32)SCU_INP6;
  SSC0->IEN.reg = (uint32)SSC0_IEN;
  SSC1->IEN.reg = (uint32)SSC1_IEN;
  /* Timer2x */
  T20->ICLR.reg = (uint32)0xC0u;
  T21->ICLR.reg = (uint32)0xC0u;
  /* No node selection for Timer20 and Timer21 */
  T20->CON1.reg = (uint32)T20_CON1;
  T21->CON1.reg = (uint32)T21_CON1;
  /* UART */
  UART0->ISC.reg = (uint32)0x303u;
  UART1->ISC.reg = (uint32)0x303u;
  SCU->INP5.reg = (uint32)SCU_INP5;
  UART0->IEN.reg = UART0_IEN;
  UART1->IEN.reg = UART1_IEN;
  /* DMA */
  SCU->DMAISC.reg = (uint32)0xFFu;
  SCU->INP7.reg = (uint32)SCU_INP7;
  SCU->DMAIEN.reg = (uint32)SCU_DMAIEN;
  /* Set NVIC node priorities and enable them */
  CPU->NVIC_IPR0.reg = CPU_NVIC_IPR0;
  CPU->NVIC_IPR1.reg = CPU_NVIC_IPR1;
  CPU->NVIC_IPR2.reg = CPU_NVIC_IPR2;
  CPU->NVIC_IPR3.reg = CPU_NVIC_IPR3;
  CPU->NVIC_IPR4.reg = CPU_NVIC_IPR4;
  CPU->NVIC_IPR5.reg = CPU_NVIC_IPR5;
  CPU->NVIC_IPR6.reg = CPU_NVIC_IPR6;
  CPU->NVIC_IPR7.reg = CPU_NVIC_IPR7;
  CPU->NVIC_ISER.reg = CPU_NVIC_ISER;
}

