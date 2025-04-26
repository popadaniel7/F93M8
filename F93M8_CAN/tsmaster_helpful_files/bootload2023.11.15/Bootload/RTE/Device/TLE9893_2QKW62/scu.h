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
 * \file     scu.h
 *
 * \brief    System Control Unit low level access library
 *
 * \version  V0.5.2
 * \date     12. Nov 2021
 *
 * \note
 */

/** \addtogroup SCU_api
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
** V0.2.1: 2020-09-28, JO:   EP-477: Removed definition of variable           **
**                           u32_globtimestamp_ms from scu.c (defined in      **
**                           file isr_exceptions.c)                           **
** V0.2.2: 2020-10-06, BG:   EP-492: Removed MISRA 2012 errors                **
** V0.2.3: 2020-10-20, BG:   EP-532: Added missing function prototypes        **
** V0.3.0: 2020-10-20, JO:   EP-524: Added parameter for SysTick reload value **
**                           to function SCU_initSysTick                      **
** V0.3.1: 2020-10-21, BG:   EP-535: Corrected initialization of XTAL         **
** V0.3.2: 2020-11-12, JO:   EP-590: Removed \param none and \return none to  **
**                           avoid doxygen warning                            **
**                           Added end of group for doxygen                   **
** V0.3.3: 2020-11-16, JO:   EP-582: Applied renaming of System_init to       **
**                           SystemInit, applied removal of return value of   **
**                           SystemInit                                       **
** V0.3.3: 2020-11-27, BG:   EP-610: Corrected MISRA 2012 errors              **
** V0.3.4: 2020-12-04, JO:   EP-626: Applied parameter change of function     **
**                           PMU_getWakeupSrc()                               **
**                           Changed parameter type of SCU_enterSleepMode     **
**                           from tPMU_wakeupSrc to uint32                    **
** V0.3.5: 2020-12-18, BG:   EP-652: Corrected name of error code variable    **
** V0.3.6: 2021-02-03, JO:   EP-684: Fixed ARMCC v6 compiler warning about    **
**                           unused variables                                 **
** V0.3.7: 2021-03-04, BG:   EP-717: Replaced the for-loop in the function    **
**                           SCU_enterSleepMode and removed the wake-up source**
**                           as parameter (configured in the Config Wizard)   **
**                           Removed the return parameter for the functions:  **
**                           - SCU_enterDeepSleepMode                         **
**                           - SCU_enterStopModeWithResetWakeup               **
**                           - SCU_enterStopModeWithoutResetWakeup            **
**                           - SCU_exitStopModeWithoutResetWakeup             **
**                           - SCU_enterSleepMode                             **
**                           Removed the function to exit sleep mode          **
** V0.4.0: 2021-03-11, JO:   EP-692: Added switch to HP40_Clk and disabling   **
**                           of PLL/XTAL at the  beginning of SCU_initClk     **
**                           to support Reset in Debugger (don't reprogram    **
**                           PLL while using it)                              **
** V0.4.1: 2021-04-09, JO:   EP-753: Added Cache APIs                         **
** V0.4.2: 2021-04-15, BG:   EP-728: Removed the function to exit stop mode   **
**                           w/o reset SCU_exitStopModeWithoutResetWakeup and **
**                           put the code at the end of the function          **
**                           SCU_enterStopModeWithoutResetWakeup              **
**                           Removed the function to exit stop mode with reset**
** V0.4.3: 2021-07-07, JO:   EP-873: Replaced intrinsics by CMSIS wrappers    **
** V0.4.4: 2021-07-27, BG:   EP-852: Corrected initialization of SPCTR        **
** V0.4.5: 2021-07-27, BG:   EP-814: Corrected the value to clear the register**
**                           WAKE_STS_CLR                                     **
** V0.4.6: 2021-08-03, BG:   EP-883: Removed SCU_exitFailSleepMode() as it is **
**                           widely related to the application                **
** V0.4.7: 2021-08-18, JO:   EP-914: Removed function CACHE_getCacheNCTBBits  **
** V0.4.8: 2021-08-18, JO:   EP-806: Added functions SCU_GetXTALFailSts,      **
**                           SCU_GetPLL0LockSts, SCU_GetPLL1LockSts           **
**                           Use APIs in SCU_initClk                          **
** V0.4.9: 2021-09-24, BG:   EP-882: Updated SCU_enterStopModeWithResetWakeup,**
**                           SCU_enterStopModeWithoutResetWakeup and          **
**                           SCU_enterSleepMode functions according to UM v0.2**
** V0.5.0: 2021-09-29, BG:   EP-881: Corrected wrong bitfield assignment in   **
**                           SCU_checkXTALDiagnosis()                         **
** V0.5.1: 2021-10-20, JO:   EP-770: Corrected function delay in case the     **
**                           current systick value is 0 or the reload value   **
**                           Updated local variable names                     **
** V0.5.2: 2021-11-12, JO:   EP-937: Updated copyright and branding           **
*******************************************************************************/

#ifndef _SCU_H
#define _SCU_H

/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/

#include "types.h"
#include "tle989x.h"
#include "tle_variants.h"
#include "system_tle989x.h"
#include "bdrv.h"
#include "csacsc.h"
#include "isr.h" /* for u32_globTimestamp_ms */
#include "pmu.h"
#include "isr_defines.h" /* for CPU_SYSTICK_RL */
#include "scu_defines.h"

/*******************************************************************************
**                        Global Constant Declarations                        **
*******************************************************************************/

/*******************************************************************************
**                          Global Type Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                          Global Macro Declarations                         **
*******************************************************************************/

/** \brief Multiplier can use fCPU in MHz directly (Mhz <-> us) */
#define MULTIPLIER_US_TO_TICKS SCU_fCPU_MHz

/*******************************************************************************
**                        Global Variable Declarations                        **
*******************************************************************************/

/** \brief XTAL status */
extern sint8 e_xtalSts;

/*******************************************************************************
**                        Global Function Declarations                        **
*******************************************************************************/

void SCU_init(void);
sint8 SCU_initClk(void);
sint8 SCU_checkXTALDiagnosis(void);
void SCU_delay_us(uint32 u32_time_us);
void SCU_initSysTick(uint32 u32_value);
sint8 SCU_enSafeSwitchOffSeq(void);
void SCU_enterDeepSleepMode(void);
void SCU_enterStopModeWithResetWakeup(void);
sint8 SCU_enterStopModeWithoutResetWakeup(void);
void SCU_enterSleepMode(uint8 u8_enRAMTest);
INLINE uint8 SCU_GetXTALFailSts(void);
INLINE uint8 SCU_GetPLL0LockSts(void);
INLINE uint8 SCU_GetPLL1LockSts(void);
INLINE uint32 SCU_getSysTickCntVal(void);
INLINE uint32 SCU_getSysTickRelVal(void);
INLINE void   CACHE_setCleanAll(void);
INLINE void   CACHE_setLockBlock(uint32 u32_value);
INLINE void   CACHE_setTouchBlock(uint32 u32_value);
INLINE void   CACHE_setUnlockBlock(uint32 u32_value);
INLINE void   CACHE_setCleanSet(uint32 u32_value);

/*******************************************************************************
**                     Global Inline Function Definitions                     **
*******************************************************************************/

/** \brief Get the XTAL Fail Status
 *
 * \return XTAL Fail Status (0: no Fail, 1: Fail)
 */
INLINE uint8 SCU_GetXTALFailSts(void)
{
  return (uint8)SCU->XTALSTAT.bit.XTALFAIL;
}

/** \brief Get the PLL0 Lock Status
 *
 * \return PLL0 Lock Status (0: not locked, 1: locked)
 */
INLINE uint8 SCU_GetPLL0LockSts(void)
{
  return (uint8)PLL->STAT.bit.LCK0;
}

/** \brief Get the PLL1 Lock Status
 *
 * \return PLL1 Lock Status (0: not locked, 1: locked)
 */
INLINE uint8 SCU_GetPLL1LockSts(void)
{
  return (uint8)PLL->STAT.bit.LCK1;
}

/** \brief Get the current SysTick Count Value
 *
 * \return current SysTick Count Value
 */
INLINE uint32 SCU_getSysTickCntVal(void)
{
  return (uint32)CPU->SYSTICK_CUR.bit.CURRENT;
}

/** \brief Get the current SysTick Reload Value
 *
 * \return SysTick Reload Value
 */
INLINE uint32 SCU_getSysTickRelVal(void)
{
  return (uint32)CPU->SYSTICK_RL.bit.RELOAD;
}

/** \brief Set Cache clean All
 */
INLINE void CACHE_setCleanAll(void)
{
  CACHE->CACHE_AC.bit.Clean = 1u;
}

/** \brief Set Address of Cache lock Block
 * 
 *  \param u32_value Address of Cache lock Block
 */
INLINE void CACHE_setLockBlock(uint32 u32_value)
{
  CACHE->CACHE_BL.bit.ADDR = u32_value;
}

/** \brief Set Address of Cache touch Block (load Block to Cache)
 * 
 *  \param u32_value Address of Cache touch Block (load Block to Cache)
 */
INLINE void CACHE_setTouchBlock(uint32 u32_value)
{
  CACHE->CACHE_BT.bit.ADDR = u32_value;
}

/** \brief Set Address of Cache unlock Block
 * 
 *  \param u32_value Address of Cache unlock Block
 */
INLINE void CACHE_setUnlockBlock(uint32 u32_value)
{
  CACHE->CACHE_BU.bit.ADDR = u32_value;
}

/** \brief Set Address of Cache clean Set
 * 
 *  \param u32_value Address of Cache clean Set
 */
INLINE void CACHE_setCleanSet(uint32 u32_value)
{
  CACHE->CACHE_SC.bit.ADDR = u32_value;
}

/** @}*/

#endif /* _SCU_H */
