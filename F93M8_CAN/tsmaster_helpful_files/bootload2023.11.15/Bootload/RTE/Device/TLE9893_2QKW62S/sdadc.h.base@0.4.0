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
 * \file     sdadc.h
 *
 * \brief    Sigma Delta ADC low level access library
 *
 * \version  V0.4.0
 * \date     19. Apr 2022
 *
 * \note
 */

/** \addtogroup SDADC_api
 *  @{
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
** V0.1.0: 2019-10-28, DM:   Initial version                                  **
** V0.2.0: 2020-04-28, BG:   Updated revision history format                  **
** V0.3.0: 2020-08-24, BG:   Added first functions                            **
** V0.3.1: 2020-09-16, BG:   Added interrupt enable/disable functions         **
** V0.3.2: 2020-10-01, BG:   Corrected output type for timestamp functions    **
**                           (uint8 -> uint16)                                **
** V0.3.3: 2020-10-21, BG:   EP-539: Considered the enable checkbox in CW in  **
**                           the initialization function                      **
** V0.3.4: 2020-11-12, JO:   EP-590: Removed \param none and \return none to  **
**                           avoid doxygen warning                            **
**                           Added end of group for doxygen                   **
** V0.3.5: 2020-11-20, BG:   EP-610: Corrected MISRA 2012 errors              **
**                           The following rules are globally deactivated:    **
**                           - Info 774: Boolean within 'if' always evaluates **
**                             to False/True                                  **
** V0.3.6: 2020-12-18, BG:   EP-652: Corrected name of error code variable    **
** V0.3.7: 2021-04-06, BG:   EP-760: Replaced if instructions to check if the **
**                           module is enabled with preprocessor directives to**
**                           avoid compiler warnings                          **
** V0.3.8: 2021-06-11, JO:   EP-838: Corrected Interrupt En/Dis functions     **
**                           and SDADC_disSuspendMode                         **
** V0.3.9: 2021-11-12, JO:   EP-937: Updated copyright and branding           **
** V0.4.0: 2022-04-19, JO:   EP-999: Changed return value of functions        **
**                           SDADC_getCh0Result/SDADC_getCh1Result to sint16  **
*******************************************************************************/

#ifndef _SDADC_H
#define _SDADC_H

/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/

#include "types.h"
#include "tle989x.h"
#include "tle_variants.h"
#include "sdadc_defines.h"

/*******************************************************************************
**                        Global Constant Declarations                        **
*******************************************************************************/

/*******************************************************************************
**                          Global Type Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                        Global Function Declarations                        **
*******************************************************************************/

sint8 SDADC_init(void);
INLINE void SDADC_enCh0ResInt(void);
INLINE void SDADC_disCh0ResInt(void);
INLINE void SDADC_enCh0CmpUpInt(void);
INLINE void SDADC_disCh0CmpUpInt(void);
INLINE void SDADC_enCh0CmpLoInt(void);
INLINE void SDADC_disCh0CmpLoInt(void);
INLINE void SDADC_enCh1ResInt(void);
INLINE void SDADC_disCh1ResInt(void);
INLINE void SDADC_enCh1CmpUpInt(void);
INLINE void SDADC_disCh1CmpUpInt(void);
INLINE void SDADC_enCh1CmpLoInt(void);
INLINE void SDADC_disCh1CmpLoInt(void);
INLINE uint8 SDADC_getCh0ResIntSts(void);
INLINE uint8 SDADC_getCh0CmpUpIntSts(void);
INLINE uint8 SDADC_getCh0CmpLoIntSts(void);
INLINE uint8 SDADC_getCh1ResIntSts(void);
INLINE uint8 SDADC_getCh1CmpUpIntSts(void);
INLINE uint8 SDADC_getCh1CmpLoIntSts(void);
INLINE void SDADC_clrCh0ResIntSts(void);
INLINE void SDADC_clrCh0CmpUpIntSts(void);
INLINE void SDADC_clrCh0CmpLoIntSts(void);
INLINE void SDADC_clrCh1ResIntSts(void);
INLINE void SDADC_clrCh1CmpUpIntSts(void);
INLINE void SDADC_clrCh1CmpLoIntSts(void);
INLINE void SDADC_enSuspendMode(void);
INLINE void SDADC_disSuspendMode(void);
INLINE uint8 SDADC_getSuspendModeSts(void);
INLINE sint16 SDADC_getCh0Result(void);
INLINE uint16 SDADC_getCh0Timestamp(void);
INLINE uint16 SDADC_getCh0CaptTimestamp(void);
INLINE uint8 SDADC_getCh0ResValidCnt(void);
INLINE uint8 SDADC_getCh0ValidResSts(void);
INLINE sint16 SDADC_getCh1Result(void);
INLINE uint16 SDADC_getCh1Timestamp(void);
INLINE uint16 SDADC_getCh1CaptTimestamp(void);
INLINE uint8 SDADC_getCh1ResValidCnt(void);
INLINE uint8 SDADC_getCh1ValidResSts(void);
INLINE uint8 SDADC_getCh0CmpUpSts(void);
INLINE uint8 SDADC_getCh0CmpLoSts(void);
INLINE uint8 SDADC_getCh0WFRSts(void);
INLINE uint8 SDADC_getCh1CmpUpSts(void);
INLINE uint8 SDADC_getCh1CmpLoSts(void);
INLINE uint8 SDADC_getCh1WFRSts(void);
INLINE void SDADC_clrCh0CmpUpSts(void);
INLINE void SDADC_clrCh0CmpLoSts(void);
INLINE void SDADC_clrCh0WFRSts(void);
INLINE void SDADC_clrCh1CmpUpSts(void);
INLINE void SDADC_clrCh1CmpLoSts(void);
INLINE void SDADC_clrCh1WFRSts(void);

/*******************************************************************************
**                       Deprecated Function Declarations                     **
*******************************************************************************/
/** \brief Set Channel 0 Result Interrupt Node Pointer
 * \warning Do not change this at runtime, use the ConfigWizard to configure this feature!
 */
void SDADC_setCh0ResIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));

/** \brief Set Channel 0 Upper Compare Level Interrupt Node Pointer
 * \warning Do not change this at runtime, use the ConfigWizard to configure this feature!
 */
void SDADC_setCh0CmpUpIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));

/** \brief Set Channel 0 Lower Compare Level Interrupt Node Pointer
 * \warning Do not change this at runtime, use the ConfigWizard to configure this feature!
 */
void SDADC_setCh0CmpLoIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));

/** \brief Set Channel 1 Result Interrupt Node Pointer
 * \warning Do not change this at runtime, use the ConfigWizard to configure this feature!
 */
void SDADC_setCh1ResIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));

/** \brief Set Channel 1 Upper Compare Level Interrupt Node Pointer
 * \warning Do not change this at runtime, use the ConfigWizard to configure this feature!
 */
void SDADC_setCh1CmpUpIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));

/** \brief Set Channel 1 Lower Compare Level Interrupt Node Pointer
 * \warning Do not change this at runtime, use the ConfigWizard to configure this feature!
 */
void SDADC_setCh1CmpLoIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));


/*******************************************************************************
**                     Global Inline Function Definitions                     **
*******************************************************************************/
/** \brief Enable Channel 0 Result Interrupt
 */
INLINE void SDADC_enCh0ResInt(void)
{
  SDADC->IEN.bit.RES0_EN = 1u;
}

/** \brief Disable Channel 0 Result Interrupt
 */
INLINE void SDADC_disCh0ResInt(void)
{
  SDADC->IEN.bit.RES0_EN = 0u;
}

/** \brief Enable Channel 0 Upper Compare Level Interrupt
 */
INLINE void SDADC_enCh0CmpUpInt(void)
{
  SDADC->IEN.bit.CMP0_UP_EN = 1u;
}

/** \brief Disable Channel 0 Upper Compare Level Interrupt
 */
INLINE void SDADC_disCh0CmpUpInt(void)
{
  SDADC->IEN.bit.CMP0_UP_EN = 0u;
}

/** \brief Enable Channel 0 Lower Compare Level Interrupt
 */
INLINE void SDADC_enCh0CmpLoInt(void)
{
  SDADC->IEN.bit.CMP0_LO_EN = 1u;
}

/** \brief Disable Channel 0 Lower Compare Level Interrupt
 */
INLINE void SDADC_disCh0CmpLoInt(void)
{
  SDADC->IEN.bit.CMP0_LO_EN = 0u;
}

/** \brief Enable Channel 1 Result Interrupt
 */
INLINE void SDADC_enCh1ResInt(void)
{
  SDADC->IEN.bit.RES1_EN = 1u;
}

/** \brief Disable Channel 1 Result Interrupt
 */
INLINE void SDADC_disCh1ResInt(void)
{
  SDADC->IEN.bit.RES1_EN = 0u;
}

/** \brief Enable Channel 1 Upper Compare Level Interrupt
 */
INLINE void SDADC_enCh1CmpUpInt(void)
{
  SDADC->IEN.bit.CMP1_UP_EN = 1u;
}

/** \brief Disable Channel 1 Upper Compare Level Interrupt
 */
INLINE void SDADC_disCh1CmpUpInt(void)
{
  SDADC->IEN.bit.CMP1_UP_EN = 0u;
}

/** \brief Enable Channel 1 Lower Compare Level Interrupt
 */
INLINE void SDADC_enCh1CmpLoInt(void)
{
  SDADC->IEN.bit.CMP1_LO_EN = 1u;
}

/** \brief Disable Channel 1 Lower Compare Level Interrupt
 */
INLINE void SDADC_disCh1CmpLoInt(void)
{
  SDADC->IEN.bit.CMP1_LO_EN = 0u;
}

/** \brief Get Channel 0 Result Interrupt Status SDADC.IS.RES0_IS
 *
 * \return uint8 Channel 0 Result Interrupt Status
 */
INLINE uint8 SDADC_getCh0ResIntSts(void)
{
  return (uint8)SDADC->IS.bit.RES0_IS;
}

/** \brief Get Channel 0 Upper Compare Level Interrupt Status SDADC.IS.CMP0_UP_IS
 *
 * \return uint8 Channel 0 Upper Compare Level Interrupt Status
 */
INLINE uint8 SDADC_getCh0CmpUpIntSts(void)
{
  return (uint8)SDADC->IS.bit.CMP0_UP_IS;
}

/** \brief Get Channel 0 Lower Compare Level Interrupt Status SDADC.IS.CMP0_LO_IS
 *
 * \return uint8 Channel 0 Lower Compare Level Interrupt Status
 */
INLINE uint8 SDADC_getCh0CmpLoIntSts(void)
{
  return (uint8)SDADC->IS.bit.CMP0_LO_IS;
}

/** \brief Get Channel 1 Result Interrupt Status SDADC.IS.RES1_IS
 *
 * \return uint8 Channel 1 Result Interrupt Status
 */
INLINE uint8 SDADC_getCh1ResIntSts(void)
{
  return (uint8)SDADC->IS.bit.RES1_IS;
}

/** \brief Get Channel 1 Upper Compare Level Interrupt Status SDADC.IS.CMP1_UP_IS
 *
 * \return uint8 Channel 1 Upper Compare Level Interrupt Status
 */
INLINE uint8 SDADC_getCh1CmpUpIntSts(void)
{
  return (uint8)SDADC->IS.bit.CMP1_UP_IS;
}

/** \brief Get Channel 1 Lower Compare Level Interrupt Status SDADC.IS.CMP1_LO_IS
 *
 * \return uint8 Channel 1 Lower Compare Level Interrupt Status
 */
INLINE uint8 SDADC_getCh1CmpLoIntSts(void)
{
  return (uint8)SDADC->IS.bit.CMP1_LO_IS;
}

/** \brief Clear Channel 0 Result Interrupt Status SDADC.ISR.RES0_ISC
 */
INLINE void SDADC_clrCh0ResIntSts(void)
{
  SDADC->ISR.bit.RES0_ISC = 1u;
}

/** \brief Clear Channel 0 Upper Compare Level Interrupt Status SDADC.ISR.CMP0_UP_ISC
 */
INLINE void SDADC_clrCh0CmpUpIntSts(void)
{
  SDADC->ISR.bit.CMP0_UP_ISC = 1u;
}

/** \brief Clear Channel 0 Lower Compare Level Interrupt Status SDADC.ISR.CMP0_LO_ISC
 */
INLINE void SDADC_clrCh0CmpLoIntSts(void)
{
  SDADC->ISR.bit.CMP0_LO_ISC = 1u;
}

/** \brief Clear Channel 1 Result Interrupt Status SDADC.ISR.RES1_ISC
 */
INLINE void SDADC_clrCh1ResIntSts(void)
{
  SDADC->ISR.bit.RES1_ISC = 1u;
}

/** \brief Clear Channel 1 Upper Compare Level Interrupt Status SDADC.ISR.CMP1_UP_ISC
 */
INLINE void SDADC_clrCh1CmpUpIntSts(void)
{
  SDADC->ISR.bit.CMP1_UP_ISC = 1u;
}

/** \brief Clear Channel 1 Lower Compare Level Interrupt Status SDADC.ISR.CMP1_LO_ISC
 */
INLINE void SDADC_clrCh1CmpLoIntSts(void)
{
  SDADC->ISR.bit.CMP1_LO_ISC = 1u;
}

/** \brief Enable Suspend Mode SDADC.SUSCTR.EN
 */
INLINE void SDADC_enSuspendMode(void)
{
  SDADC->SUSCTR.bit.EN = 1u;
}

/** \brief Disable Suspend Mode SDADC.SUSCTR.EN
 */
INLINE void SDADC_disSuspendMode(void)
{
  SDADC->SUSCTR.bit.EN = 0u;
}

/** \brief Get Suspend Mode Status SDADC.SUSSTAT.STAT
 *
 * \return uint8 Suspend Mode Status
 */
INLINE uint8 SDADC_getSuspendModeSts(void)
{
  return (uint8)SDADC->SUSSTAT.bit.STAT;
}

/** \brief Get Channel 0 Result SDADC.RES0.RESULT
 *
 * \return sint16 Channel 0 Result
 */
INLINE sint16 SDADC_getCh0Result(void)
{
  return (sint16)SDADC->RES0.bit.RESULT;
}

/** \brief Get Channel 0 Timestamp SDADC.RES0.TIMVAL
 *
 * \return uint16 Channel 0 Timestamp
 */
INLINE uint16 SDADC_getCh0Timestamp(void)
{
  return (uint16)SDADC->RES0.bit.TIMVAL;
}

/** \brief Get Channel 0 Captured Timestamp SDADC.CTIM0.TIMVAL
 *
 * \return uint16 Channel 0 Captured Timestamp
 */
INLINE uint16 SDADC_getCh0CaptTimestamp(void)
{
  return (uint16)SDADC->CTIM0.bit.TIMVAL;
}

/** \brief Get Channel 0 Result Valid Counter SDADC.RES0.VALCNT
 *
 * \return uint8 Channel 0 Result Valid Counter
 */
INLINE uint8 SDADC_getCh0ResValidCnt(void)
{
  return (uint8)SDADC->RES0.bit.VALCNT;
}

/** \brief Get Channel 0 Valid Result Status SDADC.RES0.RESVALID
 *
 * \return uint8 Channel 0 Valid Result Status
 */
INLINE uint8 SDADC_getCh0ValidResSts(void)
{
  return (uint8)SDADC->RES0.bit.RESVALID;
}

/** \brief Get Channel 1 Result SDADC.RES1.RESULT
 *
 * \return sint16 Channel 1 Result
 */
INLINE sint16 SDADC_getCh1Result(void)
{
  return (sint16)SDADC->RES1.bit.RESULT;
}

/** \brief Get Channel 1 Timestamp SDADC.RES1.TIMVAL
 *
 * \return uint16 Channel 1 Timestamp
 */
INLINE uint16 SDADC_getCh1Timestamp(void)
{
  return (uint16)SDADC->RES1.bit.TIMVAL;
}

/** \brief Get Channel 1 Captured Timestamp SDADC.CTIM1.TIMVAL
 *
 * \return uint16 Channel 1 Captured Timestamp
 */
INLINE uint16 SDADC_getCh1CaptTimestamp(void)
{
  return (uint16)SDADC->CTIM1.bit.TIMVAL;
}

/** \brief Get Channel 1 Result Valid Counter SDADC.RES1.VALCNT
 *
 * \return uint8 Channel 1 Result Valid Counter
 */
INLINE uint8 SDADC_getCh1ResValidCnt(void)
{
  return (uint8)SDADC->RES1.bit.VALCNT;
}

/** \brief Get Channel 1 Valid Result Status SDADC.RES1.RESVALID
 *
 * \return uint8 Channel 1 Valid Result Status
 */
INLINE uint8 SDADC_getCh1ValidResSts(void)
{
  return (uint8)SDADC->RES1.bit.RESVALID;
}

/** \brief Get Channel 0 Upper Compare Level Status SDADC.STS.CMP0_UP_STS
 *
 * \return uint8 Channel 0 Upper Compare Level Status
 */
INLINE uint8 SDADC_getCh0CmpUpSts(void)
{
  return (uint8)SDADC->STS.bit.CMP0_UP_STS;
}

/** \brief Get Channel 0 Lower Compare Level Status SDADC.STS.CMP0_LO_STS
 *
 * \return uint8 Channel 0 Lower Compare Level Status
 */
INLINE uint8 SDADC_getCh0CmpLoSts(void)
{
  return (uint8)SDADC->STS.bit.CMP0_LO_STS;
}

/** \brief Get Channel 0 Wait For Read Status SDADC.STS.WFR0_STS
 *
 * \return uint8 Channel 0 Wait For Read Status
 */
INLINE uint8 SDADC_getCh0WFRSts(void)
{
  return (uint8)SDADC->STS.bit.WFR0_STS;
}

/** \brief Get Channel 1 Upper Compare Level Status SDADC.STS.CMP1_UP_STS
 *
 * \return uint8 Channel 1 Upper Compare Level Status
 */
INLINE uint8 SDADC_getCh1CmpUpSts(void)
{
  return (uint8)SDADC->STS.bit.CMP1_UP_STS;
}

/** \brief Get Channel 1 Lower Compare Level Status SDADC.STS.CMP1_LO_STS
 *
 * \return uint8 Channel 1 Lower Compare Level Status
 */
INLINE uint8 SDADC_getCh1CmpLoSts(void)
{
  return (uint8)SDADC->STS.bit.CMP1_LO_STS;
}

/** \brief Get Channel 1 Wait For Read Status SDADC.STS.WFR1_STS
 *
 * \return uint8 Channel 1 Wait For Read Status
 */
INLINE uint8 SDADC_getCh1WFRSts(void)
{
  return (uint8)SDADC->STS.bit.WFR1_STS;
}

/** \brief Clear Channel 0 Upper Compare Level Status SDADC.STSR.CMP0_UP_SC
 */
INLINE void SDADC_clrCh0CmpUpSts(void)
{
  SDADC->STSR.bit.CMP0_UP_SC = 1u;
}

/** \brief Clear Channel 0 Lower Compare Level Status SDADC.STSR.CMP0_LO_SC
 */
INLINE void SDADC_clrCh0CmpLoSts(void)
{
  SDADC->STSR.bit.CMP0_LO_SC = 1u;
}

/** \brief Clear Channel 0 Wait For Read Status SDADC.STSR.WFR0_SC
 */
INLINE void SDADC_clrCh0WFRSts(void)
{
  SDADC->STSR.bit.WFR0_SC = 1u;
}

/** \brief Clear Channel 1 Upper Compare Level Status SDADC.STSR.CMP1_UP_SC
 */
INLINE void SDADC_clrCh1CmpUpSts(void)
{
  SDADC->STSR.bit.CMP1_UP_SC = 1u;
}

/** \brief Clear Channel 1 Lower Compare Level Status SDADC.STSR.CMP1_LO_SC
 */
INLINE void SDADC_clrCh1CmpLoSts(void)
{
  SDADC->STSR.bit.CMP1_LO_SC = 1u;
}

/** \brief Clear Channel 1 Wait For Read Status SDADC.STSR.WFR1_SC
 */
INLINE void SDADC_clrCh1WFRSts(void)
{
  SDADC->STSR.bit.WFR1_SC = 1u;
}

/** @}*/

#endif /* _SDADC_H */
