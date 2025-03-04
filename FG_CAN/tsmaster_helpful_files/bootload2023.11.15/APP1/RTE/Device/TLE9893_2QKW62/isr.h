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

/**
 * \file     isr.h
 *
 * \brief    Interrupt Service Routines low level access library
 *
 * \version  V0.4.9
 * \date     12. Nov 2021
 *
 * \note
 */

/*******************************************************************************
**                             Author(s) Identity                             **
********************************************************************************
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** DM           Daniel Mysliwitz                                              **
** BG           Blandine Guillot                                              **
** JO           Julia Ott                                                     **
*******************************************************************************/
                                                                                
/*******************************************************************************
**                          Revision Control History                          **
********************************************************************************
** V0.1.0: 2020-08-24, JO:   Initial version                                  **
** V0.2.0: 2020-09-29, JO:   EP-483: Fixed condition for the 'Check if NVIC   **
**                           node x is enabled' in all                        **
**                           isr_nvic_irqx_handler.c files                    **
** V0.3.0: 2020-10-20, BG:   EP-532: Added function prototypes from NVIC      **
**                           handlers and isr_exceptions.c                    **
** V0.4.0: 2020-10-28, JO:   EP-563: Added NMI_Handler to isr_exceptions.c,   **
**                           Formatted files isr related files                **
** V0.4.1: 2020-11-02, JO:   EP-556: Removed ADC2 EOC Fail interrupts         **
** V0.4.2: 2020-11-12, JO:   EP-590: Removed \param none and \return none to  **
**                           avoid doxygen warning                            **
** V0.4.3: 2020-12-02, JO:   EP-610: Fixed error related to EXTINT on falling **
**                           edge                                             **
**                           Moved callback declarations from c files         **
**                           to header to prevent MISRA warning               **
**                           The following rules are globally deactivated:    **
**                           - Warning 572: Excessive shift value             **
**                             (precision 0 shifted right by ...)             **
** V0.4.4: 2020-12-03, BG:   EP-631: Added interrupt handling for CAN         **
** V0.4.5: 2020-12-18, JO:   EP-599: Defined each *_INT_EN macros to 0 in     **
**                           case it is not defined, done in isr.h            **
** V0.4.6: 2021-02-18, BG:   EP-691: Removed *_INT_EN macros for CANNODE and  **
**                           CANMSGOBJ0                                       **
**                           Removed interrupt handling for CANMSGOBJ1 and    **
**                           CANMSGOBJ1 due to restructuration in tle989x.h   **
** V0.4.7: 2021-05-07, JO:   EP-812: Made u32_globTimestamp_ms volatile       **
** V0.4.8: 2021-08-18, JO:   EP-806: Added function INT_getGlobTimestamp      **
** V0.4.9: 2021-11-12, JO:   EP-937: Updated copyright and branding           **
*******************************************************************************/

#ifndef _ISR_H                                                                  
#define _ISR_H                                                                  

/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/

#include "isr.h"
#include "types.h"
#include "tle989x.h"
#include "tle_variants.h"
#include "isr_defines.h"

                                                                                
/*******************************************************************************
**                          Global Macro Declarations                         **
*******************************************************************************/

#define NMI_INP_NMI 3

#define WARN_INP_NVIC_IRQ0 0
#define WARN_INP_NVIC_IRQ1 1
#define CCU7_INP_NVIC_IRQ2 0
#define CCU7_INP_NVIC_IRQ3 1
#define CCU7_INP_NVIC_IRQ4 2
#define CCU7_INP_NVIC_IRQ5 3
#define MEMCTRL_INP_NVIC_IRQ6 0
#define GPT12_INP_NVIC_IRQ7 0
#define GPT12_INP_NVIC_IRQ8 1
#define ADC2_INP_NVIC_IRQ10 0
#define ADC2_INP_NVIC_IRQ11 1
#define MON_INP_NVIC_IRQ12 0
#define MON_INP_NVIC_IRQ13 1
#define ADC1_INP_NVIC_IRQ14 0
#define ADC1_INP_NVIC_IRQ15 1
#define ADC1_INP_NVIC_IRQ16 2
#define ADC1_INP_NVIC_IRQ17 3
#define BEMF_SDADC_INP_NVIC_IRQ18 0
#define BEMF_SDADC_INP_NVIC_IRQ19 1
#define EXTINT_INP_NVIC_IRQ20 0
#define EXTINT_INP_NVIC_IRQ21 1
#define UART_INP_NVIC_IRQ22 0
#define UART_INP_NVIC_IRQ23 1
#define SSC_INP_NVIC_IRQ24 0
#define SSC_INP_NVIC_IRQ25 1
#define CAN_INP_NVIC_IRQ26 0
#define CAN_INP_NVIC_IRQ27 1
#define CAN_INP_NVIC_IRQ28 2
#define DMA_INP_NVIC_IRQ29 0
#define DMA_INP_NVIC_IRQ30 1
#define T20_INP_NVIC_IRQ9 0
#define T21_INP_NVIC_IRQ31 0

#ifndef SCU_NMICON_NMIXTALEN_NMI_EN
  #define SCU_NMICON_NMIXTALEN_NMI_EN 0
#endif
#ifndef SCU_NMICON_NMIPLL0EN_NMI_EN
  #define SCU_NMICON_NMIPLL0EN_NMI_EN 0
#endif
#ifndef SCU_NMICON_NMIPLL1EN_NMI_EN
  #define SCU_NMICON_NMIPLL1EN_NMI_EN 0
#endif
#ifndef MEMCTRL_NMICON_NMIDSEN_NMI_EN
  #define MEMCTRL_NMICON_NMIDSEN_NMI_EN 0
#endif
#ifndef MEMCTRL_NMICON_NMIPSEN_NMI_EN
  #define MEMCTRL_NMICON_NMIPSEN_NMI_EN 0
#endif
#ifndef MEMCTRL_NMICON_NMICDEN_NMI_EN
  #define MEMCTRL_NMICON_NMICDEN_NMI_EN 0
#endif
#ifndef MEMCTRL_NMICON_NMINVM0EN_NMI_EN
  #define MEMCTRL_NMICON_NMINVM0EN_NMI_EN 0
#endif
#ifndef MEMCTRL_NMICON_NMINVM1EN_NMI_EN
  #define MEMCTRL_NMICON_NMINVM1EN_NMI_EN 0
#endif
#ifndef MEMCTRL_NMICON_NMIMAP0EN_NMI_EN
  #define MEMCTRL_NMICON_NMIMAP0EN_NMI_EN 0
#endif
#ifndef MEMCTRL_NMICON_NMIMAP1EN_NMI_EN
  #define MEMCTRL_NMICON_NMIMAP1EN_NMI_EN 0
#endif
#ifndef MEMCTRL_NMICON_NMIWDTEN_NMI_EN
  #define MEMCTRL_NMICON_NMIWDTEN_NMI_EN 0
#endif
#ifndef MEMCTRL_NMICON_NMISTOFEN_NMI_EN
  #define MEMCTRL_NMICON_NMISTOFEN_NMI_EN 0
#endif
#ifndef ADC2_UPTH0_INT_EN
  #define ADC2_UPTH0_INT_EN 0
#endif
#ifndef ADC2_LOTH0_INT_EN
  #define ADC2_LOTH0_INT_EN 0
#endif
#ifndef ADC2_LOTH1_INT_EN
  #define ADC2_LOTH1_INT_EN 0
#endif
#ifndef ADC2_UPTH2_INT_EN
  #define ADC2_UPTH2_INT_EN 0
#endif
#ifndef ADC2_LOTH2_INT_EN
  #define ADC2_LOTH2_INT_EN 0
#endif
#ifndef ADC2_LOTH3_INT_EN
  #define ADC2_LOTH3_INT_EN 0
#endif
#ifndef ADC2_UPTH4_INT_EN
  #define ADC2_UPTH4_INT_EN 0
#endif
#ifndef CANTRX_BUS_TO_INT_EN
  #define CANTRX_BUS_TO_INT_EN 0
#endif
#ifndef CANTRX_TXD_TO_INT_EN
  #define CANTRX_TXD_TO_INT_EN 0
#endif
#ifndef CANTRX_OT_INT_EN
  #define CANTRX_OT_INT_EN 0
#endif
#ifndef CANTRX_BUS_ACT_INT_EN
  #define CANTRX_BUS_ACT_INT_EN 0
#endif
#ifndef BDRV_LS1_OC_INT_EN
  #define BDRV_LS1_OC_INT_EN 0
#endif
#ifndef BDRV_LS1_DS_INT_EN
  #define BDRV_LS1_DS_INT_EN 0
#endif
#ifndef BDRV_HS1_OC_INT_EN
  #define BDRV_HS1_OC_INT_EN 0
#endif
#ifndef BDRV_HS1_DS_INT_EN
  #define BDRV_HS1_DS_INT_EN 0
#endif
#ifndef BDRV_LS2_OC_INT_EN
  #define BDRV_LS2_OC_INT_EN 0
#endif
#ifndef BDRV_LS2_DS_INT_EN
  #define BDRV_LS2_DS_INT_EN 0
#endif
#ifndef BDRV_HS2_OC_INT_EN
  #define BDRV_HS2_OC_INT_EN 0
#endif
#ifndef BDRV_HS2_DS_INT_EN
  #define BDRV_HS2_DS_INT_EN 0
#endif
#ifndef BDRV_LS3_OC_INT_EN
  #define BDRV_LS3_OC_INT_EN 0
#endif
#ifndef BDRV_LS3_DS_INT_EN
  #define BDRV_LS3_DS_INT_EN 0
#endif
#ifndef BDRV_HS3_OC_INT_EN
  #define BDRV_HS3_OC_INT_EN 0
#endif
#ifndef BDRV_HS3_DS_INT_EN
  #define BDRV_HS3_DS_INT_EN 0
#endif
#ifndef BDRV_HB1_ASEQ_INT_EN
  #define BDRV_HB1_ASEQ_INT_EN 0
#endif
#ifndef BDRV_HB2_ASEQ_INT_EN
  #define BDRV_HB2_ASEQ_INT_EN 0
#endif
#ifndef BDRV_HB3_ASEQ_INT_EN
  #define BDRV_HB3_ASEQ_INT_EN 0
#endif
#ifndef BDRV_SEQ_ERR_INT_EN
  #define BDRV_SEQ_ERR_INT_EN 0
#endif
#ifndef BDRV_HB1_ACTDRV_INT_EN
  #define BDRV_HB1_ACTDRV_INT_EN 0
#endif
#ifndef BDRV_HB2_ACTDRV_INT_EN
  #define BDRV_HB2_ACTDRV_INT_EN 0
#endif
#ifndef BDRV_HB3_ACTDRV_INT_EN
  #define BDRV_HB3_ACTDRV_INT_EN 0
#endif
#ifndef BDRV_VCP_LOTH2_INT_EN
  #define BDRV_VCP_LOTH2_INT_EN 0
#endif
#ifndef CSACSC_OC_INT_EN
  #define CSACSC_OC_INT_EN 0
#endif
#ifndef CSACSC_PARAM_INT_EN
  #define CSACSC_PARAM_INT_EN 0
#endif
#ifndef PMU_VDDP_UVWARN_INT_EN
  #define PMU_VDDP_UVWARN_INT_EN 0
#endif
#ifndef PMU_VDDP_OV_INT_EN
  #define PMU_VDDP_OV_INT_EN 0
#endif
#ifndef PMU_VDDC_UVWARN_INT_EN
  #define PMU_VDDC_UVWARN_INT_EN 0
#endif
#ifndef PMU_VDDC_OV_INT_EN
  #define PMU_VDDC_OV_INT_EN 0
#endif
#ifndef PMU_VDDEXT_UV_INT_EN
  #define PMU_VDDEXT_UV_INT_EN 0
#endif
#ifndef PMU_VDDEXT_OT_INT_EN
  #define PMU_VDDEXT_OT_INT_EN 0
#endif
#ifndef ARVG_VAREF_OC_INT_EN
  #define ARVG_VAREF_OC_INT_EN 0
#endif
#ifndef CCU7_T12_OM_INT_EN
  #define CCU7_T12_OM_INT_EN 0
#endif
#ifndef CCU7_T12_PM_INT_EN
  #define CCU7_T12_PM_INT_EN 0
#endif
#ifndef CCU7_T13_CM_INT_EN
  #define CCU7_T13_CM_INT_EN 0
#endif
#ifndef CCU7_T13_PM_INT_EN
  #define CCU7_T13_PM_INT_EN 0
#endif
#ifndef CCU7_T14_CM_INT_EN
  #define CCU7_T14_CM_INT_EN 0
#endif
#ifndef CCU7_T14_PM_INT_EN
  #define CCU7_T14_PM_INT_EN 0
#endif
#ifndef CCU7_T15_CM_INT_EN
  #define CCU7_T15_CM_INT_EN 0
#endif
#ifndef CCU7_T15_PM_INT_EN
  #define CCU7_T15_PM_INT_EN 0
#endif
#ifndef CCU7_T16_CM_INT_EN
  #define CCU7_T16_CM_INT_EN 0
#endif
#ifndef CCU7_T16_PM_INT_EN
  #define CCU7_T16_PM_INT_EN 0
#endif
#ifndef CCU7_CC70A_CM_R_INT_EN
  #define CCU7_CC70A_CM_R_INT_EN 0
#endif
#ifndef CCU7_CC70A_CM_F_INT_EN
  #define CCU7_CC70A_CM_F_INT_EN 0
#endif
#ifndef CCU7_CC71A_CM_R_INT_EN
  #define CCU7_CC71A_CM_R_INT_EN 0
#endif
#ifndef CCU7_CC71A_CM_F_INT_EN
  #define CCU7_CC71A_CM_F_INT_EN 0
#endif
#ifndef CCU7_CC71A_CM_R_INT_EN
  #define CCU7_CC71A_CM_R_INT_EN 0
#endif
#ifndef CCU7_CC71A_CM_F_INT_EN
  #define CCU7_CC71A_CM_F_INT_EN 0
#endif
#ifndef CCU7_C70B_CM_R_INT_EN
  #define CCU7_C70B_CM_R_INT_EN 0
#endif
#ifndef CCU7_C70B_CM_F_INT_EN
  #define CCU7_C70B_CM_F_INT_EN 0
#endif
#ifndef CCU7_C71B_CM_R_INT_EN
  #define CCU7_C71B_CM_R_INT_EN 0
#endif
#ifndef CCU7_C71B_CM_F_INT_EN
  #define CCU7_C71B_CM_F_INT_EN 0
#endif
#ifndef CCU7_C72B_CM_R_INT_EN
  #define CCU7_C72B_CM_R_INT_EN 0
#endif
#ifndef CCU7_C72B_CM_F_INT_EN
  #define CCU7_C72B_CM_F_INT_EN 0
#endif
#ifndef CCU7_TRAP_INT_EN
  #define CCU7_TRAP_INT_EN 0
#endif
#ifndef CCU7_CORRECT_HALL_INT_EN
  #define CCU7_CORRECT_HALL_INT_EN 0
#endif
#ifndef CCU7_WRONG_HALL_INT_EN
  #define CCU7_WRONG_HALL_INT_EN 0
#endif
#ifndef CCU7_MCM_STR_INT_EN
  #define CCU7_MCM_STR_INT_EN 0
#endif
#ifndef CCU7_LI_INT_EN
  #define CCU7_LI_INT_EN 0
#endif
#ifndef MEMCTRL_NVM0_OP_COMPLETE_INT_EN
  #define MEMCTRL_NVM0_OP_COMPLETE_INT_EN 0
#endif
#ifndef MEMCTRL_NVM1_OP_COMPLETE_INT_EN
  #define MEMCTRL_NVM1_OP_COMPLETE_INT_EN 0
#endif
#ifndef GPT12_GPT1T2_INT_EN
  #define GPT12_GPT1T2_INT_EN 0
#endif
#ifndef GPT12_GPT1T3_INT_EN
  #define GPT12_GPT1T3_INT_EN 0
#endif
#ifndef GPT12_GPT1T4_INT_EN
  #define GPT12_GPT1T4_INT_EN 0
#endif
#ifndef GPT12_GPT2T5_INT_EN
  #define GPT12_GPT2T5_INT_EN 0
#endif
#ifndef GPT12_GPT2T6_INT_EN
  #define GPT12_GPT2T6_INT_EN 0
#endif
#ifndef GPT12_GPT2CAPREL_INT_EN
  #define GPT12_GPT2CAPREL_INT_EN 0
#endif
#ifndef ADC2_CH0_INT_EN
  #define ADC2_CH0_INT_EN 0
#endif
#ifndef ADC2_CH1_INT_EN
  #define ADC2_CH1_INT_EN 0
#endif
#ifndef ADC2_CH2_INT_EN
  #define ADC2_CH2_INT_EN 0
#endif
#ifndef ADC2_CH3_INT_EN
  #define ADC2_CH3_INT_EN 0
#endif
#ifndef ADC2_CH4_INT_EN
  #define ADC2_CH4_INT_EN 0
#endif
#ifndef ADC2_CH5_INT_EN
  #define ADC2_CH5_INT_EN 0
#endif
#ifndef ADC2_CH6_INT_EN
  #define ADC2_CH6_INT_EN 0
#endif
#ifndef ADC2_CH7_INT_EN
  #define ADC2_CH7_INT_EN 0
#endif
#ifndef ADC2_CH8_INT_EN
  #define ADC2_CH8_INT_EN 0
#endif
#ifndef ADC2_CH9_INT_EN
  #define ADC2_CH9_INT_EN 0
#endif
#ifndef ADC2_CH10_INT_EN
  #define ADC2_CH10_INT_EN 0
#endif
#ifndef ADC2_CH11_INT_EN
  #define ADC2_CH11_INT_EN 0
#endif
#ifndef ADC2_CH12_INT_EN
  #define ADC2_CH12_INT_EN 0
#endif
#ifndef ADC2_CH13_INT_EN
  #define ADC2_CH13_INT_EN 0
#endif
#ifndef ADC2_CH14_INT_EN
  #define ADC2_CH14_INT_EN 0
#endif
#ifndef ADC2_SQ0_INT_EN
  #define ADC2_SQ0_INT_EN 0
#endif
#ifndef ADC2_SQ1_INT_EN
  #define ADC2_SQ1_INT_EN 0
#endif
#ifndef ADC2_SQ2_INT_EN
  #define ADC2_SQ2_INT_EN 0
#endif
#ifndef ADC2_SQ3_INT_EN
  #define ADC2_SQ3_INT_EN 0
#endif
#ifndef ADC2_LOTH0_INT_EN
  #define ADC2_LOTH0_INT_EN 0
#endif
#ifndef ADC2_LOTH1_INT_EN
  #define ADC2_LOTH1_INT_EN 0
#endif
#ifndef ADC2_LOTH2_INT_EN
  #define ADC2_LOTH2_INT_EN 0
#endif
#ifndef ADC2_LOTH3_INT_EN
  #define ADC2_LOTH3_INT_EN 0
#endif
#ifndef ADC2_LOTH4_INT_EN
  #define ADC2_LOTH4_INT_EN 0
#endif
#ifndef ADC2_LOTH5_INT_EN
  #define ADC2_LOTH5_INT_EN 0
#endif
#ifndef ADC2_LOTH6_INT_EN
  #define ADC2_LOTH6_INT_EN 0
#endif
#ifndef ADC2_LOTH7_INT_EN
  #define ADC2_LOTH7_INT_EN 0
#endif
#ifndef ADC2_UPTH0_INT_EN
  #define ADC2_UPTH0_INT_EN 0
#endif
#ifndef ADC2_UPTH1_INT_EN
  #define ADC2_UPTH1_INT_EN 0
#endif
#ifndef ADC2_UPTH2_INT_EN
  #define ADC2_UPTH2_INT_EN 0
#endif
#ifndef ADC2_UPTH3_INT_EN
  #define ADC2_UPTH3_INT_EN 0
#endif
#ifndef ADC2_UPTH4_INT_EN
  #define ADC2_UPTH4_INT_EN 0
#endif
#ifndef ADC2_UPTH5_INT_EN
  #define ADC2_UPTH5_INT_EN 0
#endif
#ifndef ADC2_UPTH6_INT_EN
  #define ADC2_UPTH6_INT_EN 0
#endif
#ifndef ADC2_UPTH7_INT_EN
  #define ADC2_UPTH7_INT_EN 0
#endif
#ifndef MON_MON1_R_INT_EN
  #define MON_MON1_R_INT_EN 0
#endif
#ifndef MON_MON1_F_INT_EN
  #define MON_MON1_F_INT_EN 0
#endif
#ifndef MON_MON2_R_INT_EN
  #define MON_MON2_R_INT_EN 0
#endif
#ifndef MON_MON2_F_INT_EN
  #define MON_MON2_F_INT_EN 0
#endif
#ifndef MON_MON3_R_INT_EN
  #define MON_MON3_R_INT_EN 0
#endif
#ifndef MON_MON3_F_INT_EN
  #define MON_MON3_F_INT_EN 0
#endif
#ifndef ADC1_CH0_INT_EN
  #define ADC1_CH0_INT_EN 0
#endif
#ifndef ADC1_CH1_INT_EN
  #define ADC1_CH1_INT_EN 0
#endif
#ifndef ADC1_CH2_INT_EN
  #define ADC1_CH2_INT_EN 0
#endif
#ifndef ADC1_CH3_INT_EN
  #define ADC1_CH3_INT_EN 0
#endif
#ifndef ADC1_CH4_INT_EN
  #define ADC1_CH4_INT_EN 0
#endif
#ifndef ADC1_CH5_INT_EN
  #define ADC1_CH5_INT_EN 0
#endif
#ifndef ADC1_CH6_INT_EN
  #define ADC1_CH6_INT_EN 0
#endif
#ifndef ADC1_CH7_INT_EN
  #define ADC1_CH7_INT_EN 0
#endif
#ifndef ADC1_CH8_INT_EN
  #define ADC1_CH8_INT_EN 0
#endif
#ifndef ADC1_CH9_INT_EN
  #define ADC1_CH9_INT_EN 0
#endif
#ifndef ADC1_CH10_INT_EN
  #define ADC1_CH10_INT_EN 0
#endif
#ifndef ADC1_CH11_INT_EN
  #define ADC1_CH11_INT_EN 0
#endif
#ifndef ADC1_CH12_INT_EN
  #define ADC1_CH12_INT_EN 0
#endif
#ifndef ADC1_CH13_INT_EN
  #define ADC1_CH13_INT_EN 0
#endif
#ifndef ADC1_CH14_INT_EN
  #define ADC1_CH14_INT_EN 0
#endif
#ifndef ADC1_CH15_INT_EN
  #define ADC1_CH15_INT_EN 0
#endif
#ifndef ADC1_CH16_INT_EN
  #define ADC1_CH16_INT_EN 0
#endif
#ifndef ADC1_CH17_INT_EN
  #define ADC1_CH17_INT_EN 0
#endif
#ifndef ADC1_CH18_INT_EN
  #define ADC1_CH18_INT_EN 0
#endif
#ifndef ADC1_CH19_INT_EN
  #define ADC1_CH19_INT_EN 0
#endif
#ifndef ADC1_SQ0_INT_EN
  #define ADC1_SQ0_INT_EN 0
#endif
#ifndef ADC1_SQ1_INT_EN
  #define ADC1_SQ1_INT_EN 0
#endif
#ifndef ADC1_SQ2_INT_EN
  #define ADC1_SQ2_INT_EN 0
#endif
#ifndef ADC1_SQ3_INT_EN
  #define ADC1_SQ3_INT_EN 0
#endif
#ifndef ADC1_LOTH0_INT_EN
  #define ADC1_LOTH0_INT_EN 0
#endif
#ifndef ADC1_LOTH1_INT_EN
  #define ADC1_LOTH1_INT_EN 0
#endif
#ifndef ADC1_LOTH2_INT_EN
  #define ADC1_LOTH2_INT_EN 0
#endif
#ifndef ADC1_LOTH3_INT_EN
  #define ADC1_LOTH3_INT_EN 0
#endif
#ifndef ADC1_UPTH0_INT_EN
  #define ADC1_UPTH0_INT_EN 0
#endif
#ifndef ADC1_UPTH1_INT_EN
  #define ADC1_UPTH1_INT_EN 0
#endif
#ifndef ADC1_UPTH2_INT_EN
  #define ADC1_UPTH2_INT_EN 0
#endif
#ifndef ADC1_UPTH3_INT_EN
  #define ADC1_UPTH3_INT_EN 0
#endif
#ifndef ADC1_COLL0_INT_EN
  #define ADC1_COLL0_INT_EN 0
#endif
#ifndef ADC1_COLL1_INT_EN
  #define ADC1_COLL1_INT_EN 0
#endif
#ifndef ADC1_COLL2_INT_EN
  #define ADC1_COLL2_INT_EN 0
#endif
#ifndef ADC1_COLL3_INT_EN
  #define ADC1_COLL3_INT_EN 0
#endif
#ifndef ADC1_WFR0_INT_EN
  #define ADC1_WFR0_INT_EN 0
#endif
#ifndef ADC1_WFR1_INT_EN
  #define ADC1_WFR1_INT_EN 0
#endif
#ifndef ADC1_WFR2_INT_EN
  #define ADC1_WFR2_INT_EN 0
#endif
#ifndef ADC1_WFR3_INT_EN
  #define ADC1_WFR3_INT_EN 0
#endif
#ifndef BDRV_PH1_ZC_RISE_INT_EN
  #define BDRV_PH1_ZC_RISE_INT_EN 0
#endif
#ifndef BDRV_PH1_ZC_FALL_INT_EN
  #define BDRV_PH1_ZC_FALL_INT_EN 0
#endif
#ifndef BDRV_PH2_ZC_RISE_INT_EN
  #define BDRV_PH2_ZC_RISE_INT_EN 0
#endif
#ifndef BDRV_PH2_ZC_FALL_INT_EN
  #define BDRV_PH2_ZC_FALL_INT_EN 0
#endif
#ifndef BDRV_PH3_ZC_RISE_INT_EN
  #define BDRV_PH3_ZC_RISE_INT_EN 0
#endif
#ifndef BDRV_PH3_ZC_FALL_INT_EN
  #define BDRV_PH3_ZC_FALL_INT_EN 0
#endif
#ifndef SDADC_RES0_INT_EN
  #define SDADC_RES0_INT_EN 0
#endif
#ifndef SDADC_CMP0_UP_INT_EN
  #define SDADC_CMP0_UP_INT_EN 0
#endif
#ifndef SDADC_CMP0_LO_INT_EN
  #define SDADC_CMP0_LO_INT_EN 0
#endif
#ifndef SDADC_RES1_INT_EN
  #define SDADC_RES1_INT_EN 0
#endif
#ifndef SDADC_CMP1_UP_INT_EN
  #define SDADC_CMP1_UP_INT_EN 0
#endif
#ifndef SDADC_CMP1_LO_INT_EN
  #define SDADC_CMP1_LO_INT_EN 0
#endif
#ifndef SCU_EXTINT0_RISING_INT_EN
  #define SCU_EXTINT0_RISING_INT_EN 0
#endif
#ifndef SCU_EXTINT0_FALLING_INT_EN
  #define SCU_EXTINT0_FALLING_INT_EN 0
#endif
#ifndef SCU_EXTINT1_RISING_INT_EN
  #define SCU_EXTINT1_RISING_INT_EN 0
#endif
#ifndef SCU_EXTINT1_FALLING_INT_EN
  #define SCU_EXTINT1_FALLING_INT_EN 0
#endif
#ifndef SCU_EXTINT2_RISING_INT_EN
  #define SCU_EXTINT2_RISING_INT_EN 0
#endif
#ifndef SCU_EXTINT2_FALLING_INT_EN
  #define SCU_EXTINT2_FALLING_INT_EN 0
#endif
#ifndef SCU_EXTINT3_RISING_INT_EN
  #define SCU_EXTINT3_RISING_INT_EN 0
#endif
#ifndef SCU_EXTINT3_FALLING_INT_EN
  #define SCU_EXTINT3_FALLING_INT_EN 0
#endif
#ifndef UART0_TI_INT_EN
  #define UART0_TI_INT_EN 0
#endif
#ifndef UART0_RI_INT_EN
  #define UART0_RI_INT_EN 0
#endif
#ifndef UART0_EOS_INT_EN
  #define UART0_EOS_INT_EN 0
#endif
#ifndef UART0_SYNCERR_INT_EN
  #define UART0_SYNCERR_INT_EN 0
#endif
#ifndef UART1_TI_INT_EN
  #define UART1_TI_INT_EN 0
#endif
#ifndef UART1_RI_INT_EN
  #define UART1_RI_INT_EN 0
#endif
#ifndef UART1_EOS_INT_EN
  #define UART1_EOS_INT_EN 0
#endif
#ifndef UART1_SYNCERR_INT_EN
  #define UART1_SYNCERR_INT_EN 0
#endif
#ifndef SSC0_TI_INT_EN
  #define SSC0_TI_INT_EN 0
#endif
#ifndef SSC0_RI_INT_EN
  #define SSC0_RI_INT_EN 0
#endif
#ifndef SSC0_ERR_INT_EN
  #define SSC0_ERR_INT_EN 0
#endif
#ifndef SSC0_ERR_INT_EN
  #define SSC0_ERR_INT_EN 0
#endif
#ifndef SSC0_ERR_INT_EN
  #define SSC0_ERR_INT_EN 0
#endif
#ifndef SSC0_ERR_INT_EN
  #define SSC0_ERR_INT_EN 0
#endif
#ifndef SSC1_TI_INT_EN
  #define SSC1_TI_INT_EN 0
#endif
#ifndef SSC1_RI_INT_EN
  #define SSC1_RI_INT_EN 0
#endif
#ifndef SSC1_ERR_INT_EN
  #define SSC1_ERR_INT_EN 0
#endif
#ifndef SSC1_ERR_INT_EN
  #define SSC1_ERR_INT_EN 0
#endif
#ifndef SSC1_ERR_INT_EN
  #define SSC1_ERR_INT_EN 0
#endif
#ifndef SSC1_ERR_INT_EN
  #define SSC1_ERR_INT_EN 0
#endif
#ifndef DMA_CH0_INT_EN
  #define DMA_CH0_INT_EN 0
#endif
#ifndef DMA_CH1_INT_EN
  #define DMA_CH1_INT_EN 0
#endif
#ifndef DMA_CH2_INT_EN
  #define DMA_CH2_INT_EN 0
#endif
#ifndef DMA_CH3_INT_EN
  #define DMA_CH3_INT_EN 0
#endif
#ifndef DMA_CH4_INT_EN
  #define DMA_CH4_INT_EN 0
#endif
#ifndef DMA_CH5_INT_EN
  #define DMA_CH5_INT_EN 0
#endif
#ifndef DMA_CH6_INT_EN
  #define DMA_CH6_INT_EN 0
#endif
#ifndef DMA_CH7_INT_EN
  #define DMA_CH7_INT_EN 0
#endif
#ifndef DMA_ERROR_INT_EN
  #define DMA_ERROR_INT_EN 0
#endif
#ifndef T20_EXF2_INT_EN
  #define T20_EXF2_INT_EN 0
#endif
#ifndef T20_TF2_INT_EN
  #define T20_TF2_INT_EN 0
#endif
#ifndef T21_EXF2_INT_EN
  #define T21_EXF2_INT_EN 0
#endif
#ifndef T21_TF2_INT_EN
  #define T21_TF2_INT_EN 0
#endif


                                                                                
/*******************************************************************************
**                        Global Variable Declarations                        **
*******************************************************************************/

/* global counter variable for ms, can count ~1.5 months, requirement EMPS-SHRQ-66 */
extern volatile uint32 u32_globTimestamp_ms;

#if (NVIC_IRQ0_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq0;
#endif
#if (NVIC_IRQ1_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq1;
#endif
#if (NVIC_IRQ2_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq2;
#endif
#if (NVIC_IRQ3_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq3;
#endif
#if (NVIC_IRQ4_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq4;
#endif
#if (NVIC_IRQ5_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq5;
#endif
#if (NVIC_IRQ6_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq6;
#endif
#if (NVIC_IRQ7_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq7;
#endif
#if (NVIC_IRQ8_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq8;
#endif
#if (NVIC_IRQ10_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq10;
#endif
#if (NVIC_IRQ11_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq11;
#endif
#if (NVIC_IRQ12_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq12;
#endif
#if (NVIC_IRQ13_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq13;
#endif
#if (NVIC_IRQ14_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq14;
#endif
#if (NVIC_IRQ15_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq15;
#endif
#if (NVIC_IRQ16_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq16;
#endif
#if (NVIC_IRQ17_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq17;
#endif
#if (NVIC_IRQ18_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq18;
#endif
#if (NVIC_IRQ19_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq19;
#endif
#if (NVIC_IRQ20_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq20;
#endif
#if (NVIC_IRQ21_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq21;
#endif
#if (NVIC_IRQ22_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq22;
#endif
#if (NVIC_IRQ23_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq23;
#endif
#if (NVIC_IRQ24_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq24;
#endif
#if (NVIC_IRQ25_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq25;
#endif
#if (NVIC_IRQ26_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq26;
#endif
#if (NVIC_IRQ27_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq27;
#endif
#if (NVIC_IRQ28_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq28;
#endif
#if (NVIC_IRQ29_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq29;
#endif
#if (NVIC_IRQ30_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq30;
#endif
#if (NVIC_IRQ9_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq9;
#endif
#if (NVIC_IRQ31_HANDLER_INT_CHECK == 1)
  extern uint8 u8_interrupt_cnt_irq31;
#endif

/*******************************************************************************
**                        Global Function Declarations                        **
*******************************************************************************/
INLINE uint32 INT_getGlobTimestamp(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void NMI_Handler(void);
void SysTick_Handler(void);
void PendSV_Handler(void);
void NVIC_IRQ0_Handler(void);
void NVIC_IRQ1_Handler(void);
void NVIC_IRQ2_Handler(void);
void NVIC_IRQ3_Handler(void);
void NVIC_IRQ4_Handler(void);
void NVIC_IRQ5_Handler(void);
void NVIC_IRQ6_Handler(void);
void NVIC_IRQ7_Handler(void);
void NVIC_IRQ8_Handler(void);
void NVIC_IRQ9_Handler(void);
void NVIC_IRQ10_Handler(void);
void NVIC_IRQ11_Handler(void);
void NVIC_IRQ12_Handler(void);
void NVIC_IRQ13_Handler(void);
void NVIC_IRQ14_Handler(void);
void NVIC_IRQ15_Handler(void);
void NVIC_IRQ16_Handler(void);
void NVIC_IRQ17_Handler(void);
void NVIC_IRQ18_Handler(void);
void NVIC_IRQ19_Handler(void);
void NVIC_IRQ20_Handler(void);
void NVIC_IRQ21_Handler(void);
void NVIC_IRQ22_Handler(void);
void NVIC_IRQ23_Handler(void);
void NVIC_IRQ24_Handler(void);
void NVIC_IRQ25_Handler(void);
void NVIC_IRQ26_Handler(void);
void NVIC_IRQ27_Handler(void);
void NVIC_IRQ28_Handler(void);
void NVIC_IRQ29_Handler(void);
void NVIC_IRQ30_Handler(void);
void NVIC_IRQ31_Handler(void);
extern void CPU_HARDFAULT_CALLBACK(void);
extern void CPU_MEMMANAGE_CALLBACK(void);
extern void CPU_BUSFAULT_CALLBACK(void);
extern void CPU_USAGEFAULT_CALLBACK(void);
void CPU_SYSTICK_CALLBACK(void);
void CPU_PENDSV_CALLBACK(void);
extern void SCU_NMICON_NMIXTALEN_CALLBACK(void);
extern void SCU_NMICON_NMIPLL0EN_CALLBACK(void);
extern void SCU_NMICON_NMIPLL1EN_CALLBACK(void);
extern void MEMCTRL_NMICON_NMIDSEN_CALLBACK(void);
extern void MEMCTRL_NMICON_NMIPSEN_CALLBACK(void);
extern void MEMCTRL_NMICON_NMICDEN_CALLBACK(void);
extern void MEMCTRL_NMICON_NMINVM0EN_CALLBACK(void);
extern void MEMCTRL_NMICON_NMINVM1EN_CALLBACK(void);
extern void MEMCTRL_NMICON_NMIMAP0EN_CALLBACK(void);
extern void MEMCTRL_NMICON_NMIMAP1EN_CALLBACK(void);
extern void MEMCTRL_NMICON_NMIWDTEN_CALLBACK(void);
extern void MEMCTRL_NMICON_NMISTOFEN_CALLBACK(void);
extern void ADC2_UPTH0_CALLBACK(void);
extern void ADC2_LOTH0_CALLBACK(void);
extern void ADC2_LOTH1_CALLBACK(void);
extern void ADC2_UPTH2_CALLBACK(void);
extern void ADC2_LOTH2_CALLBACK(void);
extern void ADC2_LOTH3_CALLBACK(void);
extern void ADC2_UPTH4_CALLBACK(void);
extern void CANTRX_BUS_TO_CALLBACK(void);
extern void CANTRX_TXD_TO_CALLBACK(void);
extern void CANTRX_OT_CALLBACK(void);
extern void CANTRX_BUS_ACT_CALLBACK(void);
extern void BDRV_LS1_OC_CALLBACK(void);
extern void BDRV_LS1_DS_CALLBACK(void);
extern void BDRV_HS1_OC_CALLBACK(void);
extern void BDRV_HS1_DS_CALLBACK(void);
extern void BDRV_LS2_OC_CALLBACK(void);
extern void BDRV_LS2_DS_CALLBACK(void);
extern void BDRV_HS2_OC_CALLBACK(void);
extern void BDRV_HS2_DS_CALLBACK(void);
extern void BDRV_LS3_OC_CALLBACK(void);
extern void BDRV_LS3_DS_CALLBACK(void);
extern void BDRV_HS3_OC_CALLBACK(void);
extern void BDRV_HS3_DS_CALLBACK(void);
extern void BDRV_HB1_ASEQ_CALLBACK(void);
extern void BDRV_HB2_ASEQ_CALLBACK(void);
extern void BDRV_HB3_ASEQ_CALLBACK(void);
extern void BDRV_SEQ_ERR_CALLBACK(void);
extern void BDRV_HB1_ACTDRV_CALLBACK(void);
extern void BDRV_HB2_ACTDRV_CALLBACK(void);
extern void BDRV_HB3_ACTDRV_CALLBACK(void);
extern void BDRV_VCP_LOTH2_CALLBACK(void);
extern void CSACSC_OC_CALLBACK(void);
extern void CSACSC_PARAM_CALLBACK(void);
extern void PMU_VDDP_UVWARN_CALLBACK(void);
extern void PMU_VDDP_OV_CALLBACK(void);
extern void PMU_VDDC_UVWARN_CALLBACK(void);
extern void PMU_VDDC_OV_CALLBACK(void);
extern void PMU_VDDEXT_UV_CALLBACK(void);
extern void PMU_VDDEXT_OT_CALLBACK(void);
extern void ARVG_VAREF_OC_CALLBACK(void);
extern void CCU7_T12_OM_CALLBACK(void);
extern void CCU7_T12_PM_CALLBACK(void);
extern void CCU7_T13_CM_CALLBACK(void);
extern void CCU7_T13_PM_CALLBACK(void);
extern void CCU7_T14_CM_CALLBACK(void);
extern void CCU7_T14_PM_CALLBACK(void);
extern void CCU7_T15_CM_CALLBACK(void);
extern void CCU7_T15_PM_CALLBACK(void);
extern void CCU7_T16_CM_CALLBACK(void);
extern void CCU7_T16_PM_CALLBACK(void);
extern void CCU7_CC70A_CM_R_CALLBACK(void);
extern void CCU7_CC70A_CM_F_CALLBACK(void);
extern void CCU7_CC71A_CM_R_CALLBACK(void);
extern void CCU7_CC71A_CM_F_CALLBACK(void);
extern void CCU7_CC72A_CM_R_CALLBACK(void);
extern void CCU7_CC72A_CM_F_CALLBACK(void);
extern void CCU7_C70B_CM_R_CALLBACK(void);
extern void CCU7_C70B_CM_F_CALLBACK(void);
extern void CCU7_C71B_CM_R_CALLBACK(void);
extern void CCU7_C71B_CM_F_CALLBACK(void);
extern void CCU7_C72B_CM_R_CALLBACK(void);
extern void CCU7_C72B_CM_F_CALLBACK(void);
extern void CCU7_TRAP_CALLBACK(void);
extern void CCU7_CORRECT_HALL_CALLBACK(void);
extern void CCU7_WRONG_HALL_CALLBACK(void);
extern void CCU7_MCM_STR_CALLBACK(void);
extern void CCU7_LI_CALLBACK(void);
extern void MEMCTRL_NVM0_OP_COMPLETE_CALLBACK(void);
extern void MEMCTRL_NVM1_OP_COMPLETE_CALLBACK(void);
extern void GPT12_GPT1T2_CALLBACK(void);
extern void GPT12_GPT1T3_CALLBACK(void);
extern void GPT12_GPT1T4_CALLBACK(void);
extern void GPT12_GPT2T5_CALLBACK(void);
extern void GPT12_GPT2T6_CALLBACK(void);
extern void GPT12_GPT2CAPREL_CALLBACK(void);
extern void ADC2_CH0_CALLBACK(void);
extern void ADC2_CH1_CALLBACK(void);
extern void ADC2_CH2_CALLBACK(void);
extern void ADC2_CH3_CALLBACK(void);
extern void ADC2_CH4_CALLBACK(void);
extern void ADC2_CH5_CALLBACK(void);
extern void ADC2_CH6_CALLBACK(void);
extern void ADC2_CH7_CALLBACK(void);
extern void ADC2_CH8_CALLBACK(void);
extern void ADC2_CH9_CALLBACK(void);
extern void ADC2_CH10_CALLBACK(void);
extern void ADC2_CH11_CALLBACK(void);
extern void ADC2_CH12_CALLBACK(void);
extern void ADC2_CH13_CALLBACK(void);
extern void ADC2_CH14_CALLBACK(void);
extern void ADC2_SQ0_CALLBACK(void);
extern void ADC2_SQ1_CALLBACK(void);
extern void ADC2_SQ2_CALLBACK(void);
extern void ADC2_SQ3_CALLBACK(void);
extern void ADC2_LOTH0_CALLBACK(void);
extern void ADC2_LOTH1_CALLBACK(void);
extern void ADC2_LOTH2_CALLBACK(void);
extern void ADC2_LOTH3_CALLBACK(void);
extern void ADC2_LOTH4_CALLBACK(void);
extern void ADC2_LOTH5_CALLBACK(void);
extern void ADC2_LOTH6_CALLBACK(void);
extern void ADC2_LOTH7_CALLBACK(void);
extern void ADC2_UPTH0_CALLBACK(void);
extern void ADC2_UPTH1_CALLBACK(void);
extern void ADC2_UPTH2_CALLBACK(void);
extern void ADC2_UPTH3_CALLBACK(void);
extern void ADC2_UPTH4_CALLBACK(void);
extern void ADC2_UPTH5_CALLBACK(void);
extern void ADC2_UPTH6_CALLBACK(void);
extern void ADC2_UPTH7_CALLBACK(void);
extern void MON_MON1_R_CALLBACK(void);
extern void MON_MON1_F_CALLBACK(void);
extern void MON_MON2_R_CALLBACK(void);
extern void MON_MON2_F_CALLBACK(void);
extern void MON_MON3_R_CALLBACK(void);
extern void MON_MON3_F_CALLBACK(void);
extern void ADC1_CH0_CALLBACK(void);
extern void ADC1_CH1_CALLBACK(void);
extern void ADC1_CH2_CALLBACK(void);
extern void ADC1_CH3_CALLBACK(void);
extern void ADC1_CH4_CALLBACK(void);
extern void ADC1_CH5_CALLBACK(void);
extern void ADC1_CH6_CALLBACK(void);
extern void ADC1_CH7_CALLBACK(void);
extern void ADC1_CH8_CALLBACK(void);
extern void ADC1_CH9_CALLBACK(void);
extern void ADC1_CH10_CALLBACK(void);
extern void ADC1_CH11_CALLBACK(void);
extern void ADC1_CH12_CALLBACK(void);
extern void ADC1_CH13_CALLBACK(void);
extern void ADC1_CH14_CALLBACK(void);
extern void ADC1_CH15_CALLBACK(void);
extern void ADC1_CH16_CALLBACK(void);
extern void ADC1_CH17_CALLBACK(void);
extern void ADC1_CH18_CALLBACK(void);
extern void ADC1_CH19_CALLBACK(void);
extern void ADC1_SQ0_CALLBACK(void);
extern void ADC1_SQ1_CALLBACK(void);
extern void ADC1_SQ2_CALLBACK(void);
extern void ADC1_SQ3_CALLBACK(void);
extern void ADC1_LOTH0_CALLBACK(void);
extern void ADC1_LOTH1_CALLBACK(void);
extern void ADC1_LOTH2_CALLBACK(void);
extern void ADC1_LOTH3_CALLBACK(void);
extern void ADC1_UPTH0_CALLBACK(void);
extern void ADC1_UPTH1_CALLBACK(void);
extern void ADC1_UPTH2_CALLBACK(void);
extern void ADC1_UPTH3_CALLBACK(void);
extern void ADC1_COLL0_CALLBACK(void);
extern void ADC1_COLL1_CALLBACK(void);
extern void ADC1_COLL2_CALLBACK(void);
extern void ADC1_COLL3_CALLBACK(void);
extern void ADC1_WFR0_CALLBACK(void);
extern void ADC1_WFR1_CALLBACK(void);
extern void ADC1_WFR2_CALLBACK(void);
extern void ADC1_WFR3_CALLBACK(void);
extern void BDRV_PH1_ZC_RISE_CALLBACK(void);
extern void BDRV_PH1_ZC_FALL_CALLBACK(void);
extern void BDRV_PH2_ZC_RISE_CALLBACK(void);
extern void BDRV_PH2_ZC_FALL_CALLBACK(void);
extern void BDRV_PH3_ZC_RISE_CALLBACK(void);
extern void BDRV_PH3_ZC_FALL_CALLBACK(void);
extern void SDADC_RES0_CALLBACK(void);
extern void SDADC_CMP0_UP_CALLBACK(void);
extern void SDADC_CMP0_LO_CALLBACK(void);
extern void SDADC_RES1_CALLBACK(void);
extern void SDADC_CMP1_UP_CALLBACK(void);
extern void SDADC_CMP1_LO_CALLBACK(void);
extern void SCU_EXTINT0_RISING_CALLBACK(void);
extern void SCU_EXTINT0_FALLING_CALLBACK(void);
extern void SCU_EXTINT1_RISING_CALLBACK(void);
extern void SCU_EXTINT1_FALLING_CALLBACK(void);
extern void SCU_EXTINT2_RISING_CALLBACK(void);
extern void SCU_EXTINT2_FALLING_CALLBACK(void);
extern void SCU_EXTINT3_RISING_CALLBACK(void);
extern void SCU_EXTINT3_FALLING_CALLBACK(void);
extern void UART0_TI_CALLBACK(void);
extern void UART0_RI_CALLBACK(void);
extern void UART0_EOS_CALLBACK(void);
extern void UART0_SYNCERR_CALLBACK(void);
extern void UART1_TI_CALLBACK(void);
extern void UART1_RI_CALLBACK(void);
extern void UART1_EOS_CALLBACK(void);
extern void UART1_SYNCERR_CALLBACK(void);
extern void SSC0_TI_CALLBACK(void);
extern void SSC0_RI_CALLBACK(void);
extern void SSC0_TEI_CALLBACK(void);
extern void SSC0_REI_CALLBACK(void);
extern void SSC0_PEI_CALLBACK(void);
extern void SSC0_BEI_CALLBACK(void);
extern void SSC1_TI_CALLBACK(void);
extern void SSC1_RI_CALLBACK(void);
extern void SSC1_TEI_CALLBACK(void);
extern void SSC1_REI_CALLBACK(void);
extern void SSC1_PEI_CALLBACK(void);
extern void SSC1_BEI_CALLBACK(void);
extern void CANNODE_NODE0_TXOK_CALLBACK(void);
extern void CANNODE_NODE0_RXOK_CALLBACK(void);
extern void CANNODE_NODE0_LEC_CALLBACK(void);
extern void CANNODE_NODE0_EWRN_CALLBACK(void);
extern void CANNODE_NODE0_BOFF_CALLBACK(void);
extern void CANNODE_NODE0_LLE_CALLBACK(void);
extern void CANNODE_NODE0_LOE_CALLBACK(void);
extern void CANNODE_NODE0_CFCOV_CALLBACK(void);
extern void CANMSGOBJ0_MSG0_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG0_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG0_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG0_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG1_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG1_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG1_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG1_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG2_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG2_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG2_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG2_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG3_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG3_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG3_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG3_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG4_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG4_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG4_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG4_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG5_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG5_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG5_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG5_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG6_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG6_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG6_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG6_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG7_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG7_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG7_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG7_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG8_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG8_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG8_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG8_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG9_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG9_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG9_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG9_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG10_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG10_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG10_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG10_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG11_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG11_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG11_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG11_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG12_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG12_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG12_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG12_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG13_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG13_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG13_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG13_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG14_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG14_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG14_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG14_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG15_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG15_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG15_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG15_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG16_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG16_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG16_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG16_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG17_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG17_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG17_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG17_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG18_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG18_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG18_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG18_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG19_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG19_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG19_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG19_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG20_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG20_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG20_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG20_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG21_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG21_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG21_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG21_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG22_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG22_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG22_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG22_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG23_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG23_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG23_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG23_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG24_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG24_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG24_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG24_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG25_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG25_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG25_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG25_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG26_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG26_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG26_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG26_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG27_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG27_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG27_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG27_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG28_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG28_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG28_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG28_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG29_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG29_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG29_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG29_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG30_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG30_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG30_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG30_RXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG31_TXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG31_RXPND_CALLBACK(void);
extern void CANMSGOBJ0_MSG31_TXOVF_CALLBACK(void);
extern void CANMSGOBJ0_MSG31_RXOVF_CALLBACK(void);
extern void DMA_CH0_CALLBACK(void);
extern void DMA_CH1_CALLBACK(void);
extern void DMA_CH2_CALLBACK(void);
extern void DMA_CH3_CALLBACK(void);
extern void DMA_CH4_CALLBACK(void);
extern void DMA_CH5_CALLBACK(void);
extern void DMA_CH6_CALLBACK(void);
extern void DMA_CH7_CALLBACK(void);
extern void DMA_ERROR_CALLBACK(void);
extern void T20_EXF2_CALLBACK(void);
extern void T20_TF2_CALLBACK(void);
extern void T21_EXF2_CALLBACK(void);
extern void T21_TF2_CALLBACK(void);

/*******************************************************************************
**                        Global Function Definitions                         **
*******************************************************************************/
/** \brief Get the global timestamp value
 *
 * \return global timestamp value
 */
INLINE uint32 INT_getGlobTimestamp(void)
{
	return u32_globTimestamp_ms;
}

#endif /* _ISR_H */

