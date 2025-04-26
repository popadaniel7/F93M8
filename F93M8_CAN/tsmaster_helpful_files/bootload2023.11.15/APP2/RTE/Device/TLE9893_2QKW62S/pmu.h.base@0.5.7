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
 * \file     pmu.h
 *
 * \brief    PMU low level access library
 *
 * \version  V0.5.7
 * \date     17. Nov 2022
 *
 * \note
 */

/** \addtogroup PMU_api
 *  @{
 */

/*******************************************************************************
**                             Author(s) Identity                             **
********************************************************************************
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** JO           Julia Ott                                                     **
** BG           Blandine Guillot                                              **
** DM           Daniel Mysliwitz                                              **
*******************************************************************************/

/*******************************************************************************
**                          Revision Control History                          **
********************************************************************************
** V0.1.0: 2020-06-10, BG:   Initial version                                  **
** V0.2.0: 2020-06-10, BG:   Added declaration of global function             **
** V0.2.1: 2020-09-16, BG:   Added interrupt enable/disable functions         **
**                           Added function for GPIO and MON as wake-up src   **
** V0.2.2: 2020-09-21, JO:   EP-468: Corrected PMU_serviceFailSafeWatchdog()  **
**                           (toggle bit PMU->WD_TRIG.bit.TRIG to service the **
**                           watchdog)                                        **
** V0.2.3: 2020-09-21, JO:   EP-465: Added break commands to switch case      **
**                           statements in setGPIOWakeCfg and setMONWakeCfg   **
** V0.2.4: 2020-10-06, BG:   EP-492: Removed MISRA 2012 errors                **
** V0.2.5: 2020-10-12, BG:   EP-515: Added delay and cleared safe-state status**
**                           for the fail-safe watchdog initialization        **
**                           EP-515: Updated PMU_serviceFailSafeWatchdog()    **
**                           with a safe trigger point calculated in Config   **
**                           Wizard                                           **
**                           EP-515: Updated functions name related to the    **
**                           fail-safe watchdog                               **
** V0.2.6: 2020-10-16, JO:   EP-523: Updated parameter names                  **
** V0.2.7: 2020-10-20, BG:   EP-534: Configured missing register START_CONFIG **
**                           in the initialization function                   **
** V0.2.8: 2020-10-20, JO:   EP-515: Removed the enabling of the watchdog     **
**                           Added toggling of PMU->WD_TRIG.bit.TRIG for      **
**                           initial watchdog trigger                         **
** V0.2.9: 2020-10-21, JO:   EP-536: Applied PMU.WD_CTRL.EN setting in        **
**                           function PMU_initFailSafeWatchdog                **
** V0.3.0: 2020-11-12, JO:   EP-590: Removed \param none and \return none to  **
**                           avoid doxygen warning                            **
** V0.3.1: 2020-11-17, BG:   EP-600: Corrected watchdog initialization        **
** V0.3.2: 2020-11-20, BG:   EP-610: Corrected MISRA 2012 errors              **
**                           The following rules are globally deactivated:    **
**                           - Info 774: Boolean within 'if' always evaluates **
**                             to False/True                                  **
** V0.3.3: 2020-12-02, BG:   EP-626: Updated wake-up sources functions to     **
**                           consider several wake-up sources at once         **
** V0.4.0: 2020-12-04, JO:   EP-626: Reworked PMU_enWakeupSrc and             **
**                           PMU_enWakeupSrc, added defines PMU_WAKEUPSRC_*   **
**                           as parameter for the functions (can be combined  **
**                           with bitwise OR)                                 **
**                           Added functions PMU_enStopModeVDDCReduct         **
**                           and PMU_disStopModeVDDCReduct                    **
** V0.4.1: 2020-12-10, BG:   EP-600: Added a function to clear the fail-safe  **
**                           watchdog fail status                             **
** V0.4.2: 2020-12-18, BG:   EP-652: Corrected name of error code variable    **
** V0.4.3: 2021-01-04, BG:   EP-661: Renamed u32_maxDelay_ticks variable to   **
**                           u32_maxDelay_ms                                  **
** V0.4.4: 2021-01-20, BG:   EP-679: Removed clearing of reset status register**
**                           in the init function                             **
** V0.4.5: 2021-02-10, JO:   EP-696: Changed from anonymous to named typedefs **
**                           to prevent MISRA warning                         **
** V0.4.6: 2021-02-26, BG:   EP-701: Updated function to trigger SOW          **
**                           Added SOW bitfield definition before the first   **
**                           watchdog trigger                                 **
** V0.4.7: 2021-03-08, BG:   EP-733: Added FIFO pull-up enable in PMU_init    **
**                           after removing it from main function             **
** V0.4.8: 2021-03-17, BG:   EP-737: Corrected misspelling for                **
**                           PMU_disWakeupSrc                                 **
** V0.4.9: 2021-06-02, BG:   EP-813: Removed the clearing of status registers **
**                           in the initialization function                   **
** V0.5.0: 2021-06-18, JO:   EP-842: Updated PMU_initFailSafeWatchdog for     **
**                           unit test (API call instead of bit access)       **
** V0.5.1: 2021-06-29, JO:   EP-851: Made u32_failsafeWatchdogCnt volatile    **
** V0.5.2: 2021-07-21, BG:   EP-870: Removed the range check for GPIO number  **
**                           PMU_setGPIOWakeCfg and for MON number for        **
**                           PMU_setMONWakeCfg so that the default case for   **
**                           switch is not empty                              **
** V0.5.3: 2021-09-28, BG:   EP-929: Updated PMU_init() so that checking for  **
**                           possible hardware failure does not block the     **
**                           initialization with Config Wizard defines        **
** V0.5.4: 2021-11-12, JO:   EP-937: Updated copyright and branding           **
** V0.5.5: 2022-04-25, JO:   EP-1139: Corrected definition of variable        **
**                           u32_failsafeWatchdogCnt                          **
**                           Corrected doxygen errors/warnings                **
** V0.5.6: 2022-06-23, JO:   EP-1150: Removed ARMCC V6.18 warnings            **
** V0.5.7: 2022-11-17, JO:   EP-1342: Updated enum documentation to remove    **
**                           doxygen warning                                  **
*******************************************************************************/

#ifndef _PMU_H
#define _PMU_H

/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/
#include "tle_variants.h"
#include "types.h"
#include "pmu_defines.h"
#include "tle989x.h"
#include "scu_defines.h"

/*******************************************************************************
**                          Global Macro Declarations                         **
*******************************************************************************/
/** \brief PMU Wake-up source CAN */
#define PMU_WAKEUPSRC_CAN        PMU_WAKE_CTRL_CAN_WAKE_EN_Msk
/** \brief PMU Wake-up source cyclic sense */
#define PMU_WAKEUPSRC_CYCLICSENSE (2u)
/** \brief PMU Wake-up source cyclic wake */
#define PMU_WAKEUPSRC_CYCLICWAKE PMU_WAKE_CTRL_CYC_WAKE_EN_Msk
/** \brief PMU Wake-up source GPIO0 */
#define PMU_WAKEUPSRC_GPIO0      PMU_WAKE_CTRL_GPIO0_WAKE_EN_Msk
/** \brief PMU Wake-up source GPIO1 */
#define PMU_WAKEUPSRC_GPIO1      PMU_WAKE_CTRL_GPIO1_WAKE_EN_Msk
/** \brief PMU Wake-up source GPIO2 */
#define PMU_WAKEUPSRC_GPIO2      PMU_WAKE_CTRL_GPIO2_WAKE_EN_Msk
/** \brief PMU Wake-up source GPIO3 */
#define PMU_WAKEUPSRC_GPIO3      PMU_WAKE_CTRL_GPIO3_WAKE_EN_Msk
/** \brief PMU Wake-up source GPIO4 */
#define PMU_WAKEUPSRC_GPIO4      PMU_WAKE_CTRL_GPIO4_WAKE_EN_Msk
/** \brief PMU Wake-up source GPIO5 */
#define PMU_WAKEUPSRC_GPIO5      PMU_WAKE_CTRL_GPIO5_WAKE_EN_Msk
/** \brief PMU Wake-up source MON1 */
#define PMU_WAKEUPSRC_MON1       PMU_WAKE_CTRL_MON0_WAKE_EN_Msk
/** \brief PMU Wake-up source MON2 */
#define PMU_WAKEUPSRC_MON2       PMU_WAKE_CTRL_MON1_WAKE_EN_Msk
/** \brief PMU Wake-up source MON3 */
#define PMU_WAKEUPSRC_MON3       PMU_WAKE_CTRL_MON2_WAKE_EN_Msk
/** \brief PMU Wake-up source VDDP UV */
#define PMU_WAKEUPSRC_VDDP_UV    PMU_WAKE_CTRL_VDDP_UVWARN_WAKE_EN_Msk
/** \brief PMU Wake-up source VDP OV */
#define PMU_WAKEUPSRC_VDDP_OV    PMU_WAKE_CTRL_VDDP_OV_WAKE_EN_Msk
/** \brief PMU Wake-up source VDDP HCM */
#define PMU_WAKEUPSRC_VDDP_HCM   PMU_WAKE_CTRL_VDDP_HCM_WAKE_EN_Msk
/** \brief PMU Wake-up source VDDC UV */
#define PMU_WAKEUPSRC_VDDC_UV    PMU_WAKE_CTRL_VDDC_UVWARN_WAKE_EN_Msk
/** \brief PMU Wake-up source VDDC OV */
#define PMU_WAKEUPSRC_VDDC_OV    PMU_WAKE_CTRL_VDDC_OV_WAKE_EN_Msk
/** \brief PMU Wake-up source VDDC HCM */
#define PMU_WAKEUPSRC_VDDC_HCM   PMU_WAKE_CTRL_VDDC_HCM_WAKE_EN_Msk
/** \brief PMU Wake-up source VDDEXT OT */
#define PMU_WAKEUPSRC_VDDEXT_OT  PMU_WAKE_CTRL_VDDEXT_OT_WAKE_EN_Msk
/** \brief PMU Wake-up source VDDEXT UV */
#define PMU_WAKEUPSRC_VDDEXT_UV  PMU_WAKE_CTRL_VDDEXT_UV_WAKE_EN_Msk
/** \brief PMU Wake-up source VSD OV */
#define PMU_WAKEUPSRC_VSD_OV     PMU_WAKE_CTRL_VSDOV_WAKE_EN_Msk
/** \brief PMU Wake-up source all sources */
#define PMU_WAKEUPSRC_ALL_SRC    (0x11FF73F7UL)
/** \brief PMU Wake-up source all GPIOs */
#define PMU_WAKEUPSRC_ALLGPIOS   (0x3F0UL)

/*******************************************************************************
**                          Global Type Declarations                          **
*******************************************************************************/

/** \enum PMU_gpioInput
 *  \brief This enum lists the gpio input pointer
 *  \note You can use this type via 'tPMU_gpioInput' or 'enum PMU_gpioInput'
 */
typedef enum PMU_gpioInput
{
  PMU_gpioInput_P0_0 = 0u,
  PMU_gpioInput_P0_1 = 1u,
  PMU_gpioInput_P0_2 = 2u,
  PMU_gpioInput_P0_3 = 3u,
  PMU_gpioInput_P0_4 = 4u,
  PMU_gpioInput_P0_5 = 5u,
  PMU_gpioInput_P0_6 = 6u,
  PMU_gpioInput_P0_7 = 7u,
  PMU_gpioInput_P0_8 = 8u,
  PMU_gpioInput_P0_9 = 9u,
  PMU_gpioInput_P1_0 = 10u,
  PMU_gpioInput_P1_1 = 11u,
  PMU_gpioInput_P1_2 = 12u,
  PMU_gpioInput_P1_3 = 13u,
  PMU_gpioInput_P1_4 = 14u,
  PMU_gpioInput_P2_0 = 15u,
  PMU_gpioInput_P2_1 = 16u,
  PMU_gpioInput_P2_2 = 17u,
  PMU_gpioInput_P2_3 = 18u,
  PMU_gpioInput_P2_4 = 19u,
  PMU_gpioInput_P2_5 = 20u,
  PMU_gpioInput_P2_6 = 21u,
  PMU_gpioInput_P2_7 = 22u,
  PMU_gpioInput_P2_8 = 23u,
  PMU_gpioInput_P2_9 = 24u
} tPMU_gpioInput;

/*******************************************************************************
**                        Global Function Declarations                        **
*******************************************************************************/

sint8 PMU_init(void);
void PMU_countFailSafeWatchdog(void);
sint8 PMU_initFailSafeWatchdog(void);
void PMU_stopFailSafeWatchdog(void);
sint8 PMU_serviceFailSafeWatchdog(void);
void PMU_clrFailSafeWatchdogFailSts(void);
sint8 PMU_serviceFailSafeWatchdogSOW(void);
INLINE void PMU_enVDDPUndervoltageWarnInt(void);
INLINE void PMU_enVDDPOvervoltageInt(void);
INLINE void PMU_disVDDPUndervoltageWarnInt(void);
INLINE void PMU_disVDDPOvervoltageInt(void);
INLINE uint8 PMU_getVDDPUndervoltageWarnIntSts(void);
INLINE uint8 PMU_getVDDPOvervoltageIntSts(void);
INLINE uint8 PMU_getVDDPUndervoltageWarnSts(void);
INLINE uint8 PMU_getVDDPCurrentLimitSts(void);
INLINE uint8 PMU_getVDDPHighCurrentModeSts(void);
INLINE void PMU_clrVDDPUndervoltageWarnIntSts(void);
INLINE void PMU_clrVDDPOvervoltageIntSts(void);
INLINE void PMU_clrVDDPUndervoltageWarnSts(void);
INLINE void PMU_clrVDDPCurrentLimitSts(void);
INLINE void PMU_clrVDDPHighCurrentModeSts(void);
INLINE void PMU_enVDDCUndervoltageWarnInt(void);
INLINE void PMU_enVDDCOvervoltageInt(void);
INLINE void PMU_disVDDCUndervoltageWarnInt(void);
INLINE void PMU_disVDDCOvervoltageInt(void);
INLINE uint8 PMU_getVDDCUndervoltageWarnIntSts(void);
INLINE uint8 PMU_getVDDCOvervoltageIntSts(void);
INLINE uint8 PMU_getVDDCUndervoltageWarnSts(void);
INLINE uint8 PMU_getVDDCHighCurrentModeSts(void);
INLINE void PMU_clrVDDCUndervoltageWarnIntSts(void);
INLINE void PMU_clrVDDCOvervoltageIntSts(void);
INLINE void PMU_clrVDDCUndervoltageWarnSts(void);
INLINE void PMU_clrVDDCHighCurrentModeSts(void);
INLINE void PMU_enVDDEXTUndervoltageInt(void);
INLINE void PMU_enVDDEXTOvertemperatureInt(void);
INLINE void PMU_disVDDEXTUndervoltageInt(void);
INLINE void PMU_disVDDEXTOvertemperatureInt(void);
INLINE uint8 PMU_getVDDEXTUndervoltageIntSts(void);
INLINE uint8 PMU_getVDDEXTOvertemperatureIntSts(void);
INLINE uint8 PMU_getVDDEXTUndervoltageSts(void);
INLINE uint8 PMU_getVDDEXTOvertemperatureSts(void);
INLINE void PMU_clrVDDEXTUndervoltageIntSts(void);
INLINE void PMU_clrVDDEXTOvertemperatureIntSts(void);
INLINE void PMU_clrVDDEXTUndervoltageSts(void);
INLINE void PMU_clrVDDEXTOvertemperatureSts(void);
INLINE uint8 PMU_getVDDPRegulatorTimeoutSts(void);
INLINE uint8 PMU_getVDDCRegulatorTimeoutSts(void);
INLINE uint8 PMU_getHPClkFailSts(void);
INLINE uint8 PMU_getSysOvertemperatureSts(void);
INLINE uint8 PMU_getSeqWdFailSts(void);
INLINE uint8 PMU_getVDDPRegulatorOvertemperatureSts(void);
INLINE uint8 PMU_getVDDCOvercurrentSts(void);
INLINE void PMU_clrVDDPRegulatorTimeoutSts(void);
INLINE void PMU_clrVDDCRegulatorTimeoutSts(void);
INLINE void PMU_clrHPClkFailSts(void);
INLINE void PMU_clrSysOvertemperatureSts(void);
INLINE void PMU_clrSeqWdFailSts(void);
INLINE void PMU_clrVDDPRegulatorOvertemperatureSts(void);
INLINE void PMU_clrVDDCOvercurrentSts(void);
INLINE uint8 PMU_getMstrSupplyUndervoltageRstSts(void);
INLINE uint8 PMU_getMstrClkWDRstSts(void);
INLINE uint8 PMU_getFailSleepExitRstSts(void);
INLINE uint8 PMU_getSleepExitRstSts(void);
INLINE uint8 PMU_getStopExitRstSts(void);
INLINE uint8 PMU_getPinRstSts(void);
INLINE uint8 PMU_getFailSafeWDRstSts(void);
INLINE uint8 PMU_getWDTimerRstSts(void);
INLINE uint8 PMU_getSoftRstSts(void);
INLINE uint8 PMU_getLockupRstSts(void);
INLINE uint8 PMU_getVDDPUndervoltageRstSts(void);
INLINE uint8 PMU_getVDDCUndervoltageRstSts(void);
INLINE uint8 PMU_getSecureStackOverflowRstSts(void);
INLINE void PMU_clrMstrSupplyUndervoltageRstSts(void);
INLINE void PMU_clrMstrClkWDRstSts(void);
INLINE void PMU_clrFailSleepExitRstSts(void);
INLINE void PMU_clrSleepExitRstSts(void);
INLINE void PMU_clrStopExitRstSts(void);
INLINE void PMU_clrPinRstSts(void);
INLINE void PMU_clrFailSafeWDRstSts(void);
INLINE void PMU_clrWDTimerRstSts(void);
INLINE void PMU_clrSoftRstSts(void);
INLINE void PMU_clrLockupRstSts(void);
INLINE void PMU_clrVDDPUndervoltageRstSts(void);
INLINE void PMU_clrVDDCUndervoltageRstSts(void);
INLINE void PMU_clrSecureStackOverflowRstSts(void);
INLINE sint8 PMU_enWakeupSrc(uint32 u32_wakeupSrc);
INLINE sint8 PMU_disWakeupSrc(uint32 u32_wakeupSrc);
INLINE uint32 PMU_getWakeupSrc(void);
INLINE void PMU_enStopModeVDDCReduct(void);
INLINE void PMU_disStopModeVDDCReduct(void);
INLINE sint8 PMU_setGPIOWakeCfg(uint8 u8_GPIO, uint8 u8_enRisingEdge, uint8 u8_enFallingEdge, uint8 u8_enCycSen, tPMU_gpioInput e_gpioInput);
INLINE sint8 PMU_setMONWakeCfg(uint8 u8_MON, uint8 u8_enRisingEdge, uint8 u8_enFallingEdge, uint8 u8_enCycSen, uint8 u8_enPullupCurrSrc, uint8 u8_enPulldownCurrSrc);
INLINE uint8 PMU_getMON1InputSts(void);
INLINE uint8 PMU_getMON2InputSts(void);
INLINE uint8 PMU_getMON3InputSts(void);
INLINE uint8 PMU_getCANWakeSts(void);
INLINE uint8 PMU_getCyclicWakeSts(void);
INLINE uint8 PMU_getGPIO0WakeSts(void);
INLINE uint8 PMU_getGPIO1WakeSts(void);
INLINE uint8 PMU_getGPIO2WakeSts(void);
INLINE uint8 PMU_getGPIO3WakeSts(void);
INLINE uint8 PMU_getGPIO4WakeSts(void);
INLINE uint8 PMU_getGPIO5WakeSts(void);
INLINE uint8 PMU_getMON1WakeSts(void);
INLINE uint8 PMU_getMON2WakeSts(void);
INLINE uint8 PMU_getMON3WakeSts(void);
INLINE uint8 PMU_getVDDPUndervoltageWarnWakeSts(void);
INLINE uint8 PMU_getVDDPOvervoltageWakeSts(void);
INLINE uint8 PMU_getVDDPHighCurrentModeWakeSts(void);
INLINE uint8 PMU_getVDDCUndervoltageWarnWakeSts(void);
INLINE uint8 PMU_getVDDCOvervoltageWakeSts(void);
INLINE uint8 PMU_getVDDCHighCurrentModeWakeSts(void);
INLINE uint8 PMU_getVDDEXTOvertemperatureWakeSts(void);
INLINE uint8 PMU_getVDDEXTUndervoltageWakeSts(void);
INLINE uint8 PMU_getVSDOvervoltageWakeSts(void);
INLINE void PMU_clrCANWakeSts(void);
INLINE void PMU_clrCyclicWakeSts(void);
INLINE void PMU_clrGPIO0WakeSts(void);
INLINE void PMU_clrGPIO1WakeSts(void);
INLINE void PMU_clrGPIO2WakeSts(void);
INLINE void PMU_clrGPIO3WakeSts(void);
INLINE void PMU_clrGPIO4WakeSts(void);
INLINE void PMU_clrGPIO5WakeSts(void);
INLINE void PMU_clrMON1WakeSts(void);
INLINE void PMU_clrMON2WakeSts(void);
INLINE void PMU_clrMON3WakeSts(void);
INLINE void PMU_clrVDDPUndervoltageWarnWakeSts(void);
INLINE void PMU_clrVDDPOvervoltageWakeSts(void);
INLINE void PMU_clrVDDPHighCurrentModeWakeSts(void);
INLINE void PMU_clrVDDCUndervoltageWarnWakeSts(void);
INLINE void PMU_clrVDDCOvervoltageWakeSts(void);
INLINE void PMU_clrVDDCHighCurrentModeWakeSts(void);
INLINE void PMU_clrVDDEXTOvertemperatureWakeSts(void);
INLINE void PMU_clrVDDEXTUndervoltageWakeSts(void);
INLINE void PMU_clrVSDOvervoltageWakeSts(void);
INLINE void PMU_enFailInputPullUp(void);
INLINE void PMU_enStartCfg(void);
INLINE void PMU_enResetPin(void);
INLINE void PMU_disFailInputPullUp(void);
INLINE void PMU_disStartCfg(void);
INLINE void PMU_disResetPin(void);
INLINE uint8 PMU_getMstrClkWDFailSts(void);
INLINE uint8 PMU_getMstrSupplyUndervoltageSts(void);
INLINE uint8 PMU_getMstrSupplyOvervoltageSts(void);
INLINE uint8 PMU_getWDFailSts(void);
INLINE uint8 PMU_getWDSelfTestFailSts(void);
INLINE uint8 PMU_getVDDCUndervoltageSts(void);
INLINE uint8 PMU_getVDDCOvervoltageSts(void);
INLINE uint8 PMU_getVDDPUndervoltageSts(void);
INLINE uint8 PMU_getVDDPOvervoltageSts(void);
INLINE uint8 PMU_getVDDPOvertemperatureSts(void);
INLINE uint8 PMU_getVAREFOvervoltageSts(void);
INLINE uint8 PMU_getCSCOvercurrentSts(void);
INLINE uint8 PMU_getCSCSelfTestFailSts(void);
INLINE uint8 PMU_getCSCEnFailSts(void);
INLINE uint8 PMU_getPinMonitorFailSts(void);
INLINE uint8 PMU_getFOOvercurrentSts(void);
INLINE void PMU_clrMstrClkWDFailSts(void);
INLINE void PMU_clrMstrSupplyUndervoltageSts(void);
INLINE void PMU_clrMstrSupplyOvervoltageSts(void);
INLINE void PMU_clrWDFailSts(void);
INLINE void PMU_clrWDSelfTestFailSts(void);
INLINE void PMU_clrVDDCUndervoltageSts(void);
INLINE void PMU_clrVDDCOvervoltageSts(void);
INLINE void PMU_clrVDDPUndervoltageSts(void);
INLINE void PMU_clrVDDPOvervoltageSts(void);
INLINE void PMU_clrVDDPOvertemperatureSts(void);
INLINE void PMU_clrVAREFOvervoltageSts(void);
INLINE void PMU_clrCSCOvercurrentSts(void);
INLINE void PMU_clrCSCSelfTestFailSts(void);
INLINE void PMU_clrCSCEnFailSts(void);
INLINE void PMU_clrPinMonitorFailSts(void);
INLINE void PMU_clrFOOvercurrentSts(void);
INLINE uint8 PMU_getSafeShutdownSts(void);
INLINE uint8 PMU_getFailOutputSts(void);
INLINE void PMU_clrSafeShutdownSts(void);
INLINE void PMU_clrFailOutputSts(void);

/*******************************************************************************
**                       Deprecated Function Declarations                     **
*******************************************************************************/

/** \brief Set VDDP Undervoltage Warning Interrupt Node Pointer
 * \warning Do not change this at runtime, use the ConfigWizard to configure this feature!
 */
void PMU_setVDDPUndervoltageWarnIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));

/** \brief Set VDDP Overvoltage Interrupt Node Pointer
 * \warning Do not change this at runtime, use the ConfigWizard to configure this feature!
 */
void PMU_setVDDPOvervoltageIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));

/** \brief Set VDDC Undervoltage Warning Interrupt Node Pointer
 * \warning Do not change this at runtime, use the ConfigWizard to configure this feature!
 */
void PMU_setVDDCUndervoltageWarnIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));

/** \brief Set VDDC Overvoltage Interrupt Node Pointer
 * \warning Do not change this at runtime, use the ConfigWizard to configure this feature!
 */
void PMU_setVDDCOvervoltageIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));

/** \brief Set VDDEXT Undervoltage Interrupt Node Pointer
 * \warning Do not change this at runtime, use the ConfigWizard to configure this feature!
 */
void PMU_setVDDEXTUndervoltageIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));

/** \brief Set VDDEXT Overtemperature Interrupt Node Pointer
 * \warning Do not change this at runtime, use the ConfigWizard to configure this feature!
 */
void PMU_setVDDEXTOvertemperatureIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));

/*******************************************************************************
**                     Global Inline Function Definitions                     **
*******************************************************************************/

/** \brief Enable VDDP undervoltage warning interrupt
 */
INLINE void PMU_enVDDPUndervoltageWarnInt(void)
{
  PMU->VDDP_IRQEN.bit.UVWARN_IEN = 1u;
}

/** \brief Enable VDDP overvoltage interrupt
 */
INLINE void PMU_enVDDPOvervoltageInt(void)
{
  PMU->VDDP_IRQEN.bit.OV_IEN = 1u;
}

/** \brief Disable VDDP undervoltage warning interrupt
 */
INLINE void PMU_disVDDPUndervoltageWarnInt(void)
{
  PMU->VDDP_IRQEN.bit.UVWARN_IEN = 0u;
}

/** \brief Disable VDDP overvoltage interrupt
 */
INLINE void PMU_disVDDPOvervoltageInt(void)
{
  PMU->VDDP_IRQEN.bit.OV_IEN = 0u;
}

/** \brief Get VDDP undervoltage warning interrupt status
 *
 * \return uint8 VDDP undervoltage warning interrupt status
 */
INLINE uint8 PMU_getVDDPUndervoltageWarnIntSts(void)
{
  return (uint8)PMU->VDDP_STS.bit.UVWARN_IS;
}

/** \brief Get VDDP overvoltage interrupt status
 *
 * \return uint8 VDDP overvoltage interrupt status
 */
INLINE uint8 PMU_getVDDPOvervoltageIntSts(void)
{
  return (uint8)PMU->VDDP_STS.bit.OV_IS;
}

/** \brief Get VDDP undervoltage warning status
 *
 * \return uint8 VDDP undervoltage warning status
 */
INLINE uint8 PMU_getVDDPUndervoltageWarnSts(void)
{
  return (uint8)PMU->VDDP_STS.bit.UVWARN_STS;
}

/** \brief Get VDDP current limitation status
 *
 * \return uint8 VDDP current limitation status
 */
INLINE uint8 PMU_getVDDPCurrentLimitSts(void)
{
  return (uint8)PMU->VDDP_STS.bit.ILIM_STS;
}

/** \brief Get VDDP high current mode status
 *
 * \return uint8 VDDP high current mode status
 */
INLINE uint8 PMU_getVDDPHighCurrentModeSts(void)
{
  return (uint8)PMU->VDDP_STS.bit.HCM_STS;
}

/** \brief Clear VDDP undervoltage warning interrupt status
 */
INLINE void PMU_clrVDDPUndervoltageWarnIntSts(void)
{
  PMU->VDDP_STS_CLR.bit.UVWARN_IS_CLR = 1u;
}

/** \brief Clear VDDP overvoltage interrupt status
 */
INLINE void PMU_clrVDDPOvervoltageIntSts(void)
{
  PMU->VDDP_STS_CLR.bit.OV_IS_CLR = 1u;
}

/** \brief Clear VDDP undervoltage warning status
 */
INLINE void PMU_clrVDDPUndervoltageWarnSts(void)
{
  PMU->VDDP_STS_CLR.bit.UVWARN_STS_CLR = 1u;
}

/** \brief Clear VDDP current limitation status
 */
INLINE void PMU_clrVDDPCurrentLimitSts(void)
{
  PMU->VDDP_STS_CLR.bit.ILIM_STS_CLR = 1u;
}

/** \brief Clear VDDP high current mode status
 */
INLINE void PMU_clrVDDPHighCurrentModeSts(void)
{
  PMU->VDDP_STS_CLR.bit.HCM_STS_CLR = 1u;
}

/** \brief Enable VDDC undervoltage warning interrupt
 */
INLINE void PMU_enVDDCUndervoltageWarnInt(void)
{
  PMU->VDDC_IRQEN.bit.UVWARN_IEN = 1u;
}

/** \brief Enable VDDC overvoltage interrupt
 */
INLINE void PMU_enVDDCOvervoltageInt(void)
{
  PMU->VDDC_IRQEN.bit.OV_IEN = 1u;
}

/** \brief Disable VDDC undervoltage warning interrupt
 */
INLINE void PMU_disVDDCUndervoltageWarnInt(void)
{
  PMU->VDDC_IRQEN.bit.UVWARN_IEN = 0u;
}

/** \brief Disable VDDC overvoltage interrupt
 */
INLINE void PMU_disVDDCOvervoltageInt(void)
{
  PMU->VDDC_IRQEN.bit.OV_IEN = 0u;
}

/** \brief Get VDDC undervoltage warning interrupt status
 *
 * \return uint8 VDDC undervoltage warning interrupt status
 */
INLINE uint8 PMU_getVDDCUndervoltageWarnIntSts(void)
{
  return (uint8)PMU->VDDC_STS.bit.UVWARN_IS;
}

/** \brief Get VDDC overvoltage interrupt status
 *
 * \return uint8 VDDC overvoltage interrupt status
 */
INLINE uint8 PMU_getVDDCOvervoltageIntSts(void)
{
  return (uint8)PMU->VDDC_STS.bit.OV_IS;
}

/** \brief Get VDDC undervoltage warning status
 *
 * \return uint8 VDDC undervoltage warning status
 */
INLINE uint8 PMU_getVDDCUndervoltageWarnSts(void)
{
  return (uint8)PMU->VDDC_STS.bit.UVWARN_STS;
}

/** \brief Get VDDC high current mode status
 *
 * \return uint8 VDDC high current mode status
 */
INLINE uint8 PMU_getVDDCHighCurrentModeSts(void)
{
  return (uint8)PMU->VDDC_STS.bit.HCM_STS;
}

/** \brief Clear VDDC undervoltage warning interrupt status
 */
INLINE void PMU_clrVDDCUndervoltageWarnIntSts(void)
{
  PMU->VDDC_STS_CLR.bit.UVWARN_IS_CLR = 1u;
}

/** \brief Clear VDDC overvoltage interrupt status
 */
INLINE void PMU_clrVDDCOvervoltageIntSts(void)
{
  PMU->VDDC_STS_CLR.bit.OV_IS_CLR = 1u;
}

/** \brief Clear VDDC undervoltage warning status
 */
INLINE void PMU_clrVDDCUndervoltageWarnSts(void)
{
  PMU->VDDC_STS_CLR.bit.UVWARN_STS_CLR = 1u;
}

/** \brief Clear VDDC high current mode status
 */
INLINE void PMU_clrVDDCHighCurrentModeSts(void)
{
  PMU->VDDC_STS_CLR.bit.HCM_STS_CLR = 1u;
}

/** \brief Enable VDDEXT undervoltage interrupt
 */
INLINE void PMU_enVDDEXTUndervoltageInt(void)
{
  PMU->VDDEXT_IRQEN.bit.UV_IEN = 1u;
}

/** \brief Enable VDDEXT overtemperature interrupt
 */
INLINE void PMU_enVDDEXTOvertemperatureInt(void)
{
  PMU->VDDEXT_IRQEN.bit.OT_IEN = 1u;
}

/** \brief Disable VDDEXT undervoltage interrupt
 */
INLINE void PMU_disVDDEXTUndervoltageInt(void)
{
  PMU->VDDEXT_IRQEN.bit.UV_IEN = 0u;
}

/** \brief Disable VDDEXT overtemperature interrupt
 */
INLINE void PMU_disVDDEXTOvertemperatureInt(void)
{
  PMU->VDDEXT_IRQEN.bit.OT_IEN = 0u;
}

/** \brief Get VDDEXT undervoltage interrupt status
 *
 * \return uint8 VDDEXT undervoltage interrupt status
 */
INLINE uint8 PMU_getVDDEXTUndervoltageIntSts(void)
{
  return (uint8)PMU->VDDEXT_STS.bit.UV_IS;
}

/** \brief Get VDDEXT overtemperature interrupt status
 *
 * \return uint8 VDDEXT overtemperature interrupt status
 */
INLINE uint8 PMU_getVDDEXTOvertemperatureIntSts(void)
{
  return (uint8)PMU->VDDEXT_STS.bit.OT_IS;
}

/** \brief Get VDDEXT undervoltage status
 *
 * \return uint8 VDDEXT undervoltage status
 */
INLINE uint8 PMU_getVDDEXTUndervoltageSts(void)
{
  return (uint8)PMU->VDDEXT_STS.bit.UV_STS;
}

/** \brief Get VDDEXT overtemperature status
 *
 * \return uint8 VDDEXT overtemperature status
 */
INLINE uint8 PMU_getVDDEXTOvertemperatureSts(void)
{
  return (uint8)PMU->VDDEXT_STS.bit.OT_STS;
}

/** \brief Clear VDDEXT undervoltage interrupt status
 */
INLINE void PMU_clrVDDEXTUndervoltageIntSts(void)
{
  PMU->VDDEXT_STS_CLR.bit.UV_IS_CLR = 1u;
}

/** \brief Clear VDDEXT overtemperature interrupt status
 */
INLINE void PMU_clrVDDEXTOvertemperatureIntSts(void)
{
  PMU->VDDEXT_STS_CLR.bit.OT_IS_CLR = 1u;
}

/** \brief Clear VDDEXT undervoltage status
 */
INLINE void PMU_clrVDDEXTUndervoltageSts(void)
{
  PMU->VDDEXT_STS_CLR.bit.UV_STS_CLR = 1u;
}

/** \brief Clear VDDEXT overtemperature status
 */
INLINE void PMU_clrVDDEXTOvertemperatureSts(void)
{
  PMU->VDDEXT_STS_CLR.bit.OT_STS_CLR = 1u;
}

/** \brief Get VDDP regulator timeout status
 *
 * \return uint8 VDDP regulator timeout status
 */
INLINE uint8 PMU_getVDDPRegulatorTimeoutSts(void)
{
  return (uint8)PMU->WAKE_FAIL_STS.bit.VDDP_TMOUT;
}

/** \brief Get VDDC regulator timeout status
 *
 * \return uint8 VDDC regulator timeout status
 */
INLINE uint8 PMU_getVDDCRegulatorTimeoutSts(void)
{
  return (uint8)PMU->WAKE_FAIL_STS.bit.VDDC_TMOUT;
}

/** \brief Get HP clock fail status
 *
 * \return uint8 HP clock fail status
 */
INLINE uint8 PMU_getHPClkFailSts(void)
{
  return (uint8)PMU->WAKE_FAIL_STS.bit.HPCLK_FAIL;
}

/** \brief Get system overtemperature status
 *
 * \return uint8 system overtemperature status
 */
INLINE uint8 PMU_getSysOvertemperatureSts(void)
{
  return (uint8)PMU->WAKE_FAIL_STS.bit.SYS_OT;
}

/** \brief Get sequential watchdog fail status
 *
 * \return uint8 sequential watchdog fail status
 */
INLINE uint8 PMU_getSeqWdFailSts(void)
{
  return (uint8)PMU->WAKE_FAIL_STS.bit.FSWD_SEQ_FAIL;
}

/** \brief Get VDDP regulator overtemperature status
 *
 * \return uint8 VDDP regulator overtemperature status
 */
INLINE uint8 PMU_getVDDPRegulatorOvertemperatureSts(void)
{
  return (uint8)PMU->WAKE_FAIL_STS.bit.VDDP_OT;
}

/** \brief Get VDDC overcurrent status
 *
 * \return uint8 VDDC overcurrent status
 */
INLINE uint8 PMU_getVDDCOvercurrentSts(void)
{
  return (uint8)PMU->WAKE_FAIL_STS.bit.VDDC_OC;
}

/** \brief Clear VDDP regulator timeout status
 */
INLINE void PMU_clrVDDPRegulatorTimeoutSts(void)
{
  PMU->WAKE_FAIL_CLR.bit.VDDP_TMOUT_CLR = 1u;
}

/** \brief Clear VDDC regulator timeout status
 */
INLINE void PMU_clrVDDCRegulatorTimeoutSts(void)
{
  PMU->WAKE_FAIL_CLR.bit.VDDC_TMOUT_CLR = 1u;
}

/** \brief Clear HP clock fail status
 */
INLINE void PMU_clrHPClkFailSts(void)
{
  PMU->WAKE_FAIL_CLR.bit.HPCLK_FAIL_CLR = 1u;
}

/** \brief Clear system overtemperature status
 */
INLINE void PMU_clrSysOvertemperatureSts(void)
{
  PMU->WAKE_FAIL_CLR.bit.SYS_OT_CLR = 1u;
}

/** \brief Clear sequential watchdog fail status
 */
INLINE void PMU_clrSeqWdFailSts(void)
{
  PMU->WAKE_FAIL_CLR.bit.FSWD_SEQ_FAIL_CLR = 1u;
}

/** \brief Clear VDDP regulator overtemperature status
 */
INLINE void PMU_clrVDDPRegulatorOvertemperatureSts(void)
{
  PMU->WAKE_FAIL_CLR.bit.VDDP_OT_CLR = 1u;
}

/** \brief Clear VDDC overcurrent status
 */
INLINE void PMU_clrVDDCOvercurrentSts(void)
{
  PMU->WAKE_FAIL_CLR.bit.VDDC_OC_CLR = 1u;
}

/** \brief Get master supply undervoltage reset status
 *
 * \return uint8 master supply undervoltage reset status
 */
INLINE uint8 PMU_getMstrSupplyUndervoltageRstSts(void)
{
  return (uint8)PMU->RESET_STS.bit.VMSUP_UV_RST;
}

/** \brief Get master clock watchdog reset status
 *
 * \return uint8 master clock watchdog reset status
 */
INLINE uint8 PMU_getMstrClkWDRstSts(void)
{
  return (uint8)PMU->RESET_STS.bit.MCLK_WD_RST;
}

/** \brief Get fail sleep mode exit reset status
 *
 * \return uint8 fail sleep mode exit reset status
 */
INLINE uint8 PMU_getFailSleepExitRstSts(void)
{
  return (uint8)PMU->RESET_STS.bit.FS_SLEEPEX_RST;
}

/** \brief Get sleep mode exit reset status
 *
 * \return uint8 sleep mode exit reset status
 */
INLINE uint8 PMU_getSleepExitRstSts(void)
{
  return (uint8)PMU->RESET_STS.bit.SLEEPEX_RST;
}

/** \brief Get stop mode exit reset status
 *
 * \return uint8 stop mode exit reset status
 */
INLINE uint8 PMU_getStopExitRstSts(void)
{
  return (uint8)PMU->RESET_STS.bit.STOPEX_RST;
}

/** \brief Get pin reset status
 *
 * \return uint8 pin reset status
 */
INLINE uint8 PMU_getPinRstSts(void)
{
  return (uint8)PMU->RESET_STS.bit.PIN_RST;
}

/** \brief Get fail safe watchdog reset status
 *
 * \return uint8 fail safe watchdog reset status
 */
INLINE uint8 PMU_getFailSafeWDRstSts(void)
{
  return (uint8)PMU->RESET_STS.bit.FSWD_RST;
}

/** \brief Get MCU watchdog timer reset status
 *
 * \return uint8 MCU watchdog timer reset status
 */
INLINE uint8 PMU_getWDTimerRstSts(void)
{
  return (uint8)PMU->RESET_STS.bit.WDT_MCU_RST;
}

/** \brief Get soft reset status
 *
 * \return uint8 soft reset status
 */
INLINE uint8 PMU_getSoftRstSts(void)
{
  return (uint8)PMU->RESET_STS.bit.SOFT_RST;
}

/** \brief Get ARM core lockup reset status
 *
 * \return uint8 ARM core lockup reset status
 */
INLINE uint8 PMU_getLockupRstSts(void)
{
  return (uint8)PMU->RESET_STS.bit.LOCKUP_RST;
}

/** \brief Get VDDP undervoltage reset status
 *
 * \return uint8 VDDP undervoltage reset status
 */
INLINE uint8 PMU_getVDDPUndervoltageRstSts(void)
{
  return (uint8)PMU->RESET_STS.bit.VDDP_UV_RST;
}

/** \brief Get VDDC undervoltage reset status
 *
 * \return uint8 VDDC undervoltage reset status
 */
INLINE uint8 PMU_getVDDCUndervoltageRstSts(void)
{
  return (uint8)PMU->RESET_STS.bit.VDDC_UV_RST;
}

/** \brief Get secure stack overflow reset status
 *
 * \return uint8 secure stack overflow reset status
 */
INLINE uint8 PMU_getSecureStackOverflowRstSts(void)
{
  return (uint8)PMU->RESET_STS.bit.SEC_STACK_RST;
}

/** \brief Clear master supply undervoltage reset status
 */
INLINE void PMU_clrMstrSupplyUndervoltageRstSts(void)
{
  PMU->RESET_STS_CLR.bit.VMSUP_UV_RST_CLR = 1u;
}

/** \brief Clear master clock watchdog reset status
 */
INLINE void PMU_clrMstrClkWDRstSts(void)
{
  PMU->RESET_STS_CLR.bit.MCLK_WD_RST_CLR = 1u;
}

/** \brief Clear fail sleep mode exit reset status
 */
INLINE void PMU_clrFailSleepExitRstSts(void)
{
  PMU->RESET_STS_CLR.bit.FS_SLEEPEX_RST_CLR = 1u;
}

/** \brief Clear sleep mode exit reset status
 */
INLINE void PMU_clrSleepExitRstSts(void)
{
  PMU->RESET_STS_CLR.bit.SLEEPEX_RST_CLR = 1u;
}

/** \brief Clear stop mode exit reset status
 */
INLINE void PMU_clrStopExitRstSts(void)
{
  PMU->RESET_STS_CLR.bit.STOPEX_RST_CLR = 1u;
}

/** \brief Clear pin reset status
 */
INLINE void PMU_clrPinRstSts(void)
{
  PMU->RESET_STS_CLR.bit.PIN_RST_CLR = 1u;
}

/** \brief Clear fail safe watchdog reset status
 */
INLINE void PMU_clrFailSafeWDRstSts(void)
{
  PMU->RESET_STS_CLR.bit.FSWD_RST_CLR = 1u;
}

/** \brief Clear MCU watchdog timer reset status
 */
INLINE void PMU_clrWDTimerRstSts(void)
{
  PMU->RESET_STS_CLR.bit.WDT_MCU_RST_CLR = 1u;
}

/** \brief Clear soft reset status
 */
INLINE void PMU_clrSoftRstSts(void)
{
  PMU->RESET_STS_CLR.bit.SOFT_RST_CLR = 1u;
}

/** \brief Clear ARM core lockup reset status
 */
INLINE void PMU_clrLockupRstSts(void)
{
  PMU->RESET_STS_CLR.bit.LOCKUP_RST_CLR = 1u;
}

/** \brief Clear VDDP undervoltage reset status
 */
INLINE void PMU_clrVDDPUndervoltageRstSts(void)
{
  PMU->RESET_STS_CLR.bit.VDDP_UV_RST_CLR = 1u;
}

/** \brief Clear VDDC undervoltage reset status
 */
INLINE void PMU_clrVDDCUndervoltageRstSts(void)
{
  PMU->RESET_STS_CLR.bit.VDDC_UV_RST_CLR = 1u;
}

/** \brief Clear secure stack overflow reset status
 */
INLINE void PMU_clrSecureStackOverflowRstSts(void)
{
  PMU->RESET_STS_CLR.bit.SEC_STACK_RST_CLR = 1u;
}

/** \brief Enable a wake-up source
 *
 * \param u32_wakeupSrc Wake-up sources to be enabled, defines prepared (PMU_WAKEUPSRC_*)
 * \return sint8 0: success, <0: error codes
 */
INLINE sint8 PMU_enWakeupSrc(uint32 u32_wakeupSrc)
{
  sint8 s8_returnCode;
  uint32 u32_wakeupSrcWithoutCycSense;
  s8_returnCode = ERR_LOG_SUCCESS;
  /* PMU_WAKEUPSRC_CYCLICSENSE is not part of register PMU->WAKE_CTRL */
  u32_wakeupSrcWithoutCycSense = u32_wakeupSrc & (~PMU_WAKEUPSRC_CYCLICSENSE);

  if ((u32_wakeupSrc & (~PMU_WAKEUPSRC_ALL_SRC)) == 0u)
  {
    PMU->WAKE_CTRL.reg |= u32_wakeupSrcWithoutCycSense;
    /* PMU_WAKEUPSRC_CYCLICSENSE is in register CYC_CTRL */
    if ((u32_wakeupSrc & PMU_WAKEUPSRC_CYCLICSENSE) == PMU_WAKEUPSRC_CYCLICSENSE)
    {
     PMU->CYC_CTRL.bit.CYC_SENSE_EN = 1u;
    }
  }
  else
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}

/** \brief Disable a wake-up source
 *
 * \param u32_wakeupSrc Wake-up sources to be disabled, defines prepared (PMU_WAKEUPSRC_*)
 * \return sint8 0: success, <0: error codes
 */
INLINE sint8 PMU_disWakeupSrc(uint32 u32_wakeupSrc)
{
  sint8 s8_returnCode;
  uint32 u32_wakeupSrcWithoutCycSense;
  s8_returnCode = ERR_LOG_SUCCESS;
  /* PMU_WAKEUPSRC_CYCLICSENSE is not part of register PMU->WAKE_CTRL */
  u32_wakeupSrcWithoutCycSense = u32_wakeupSrc &~PMU_WAKEUPSRC_CYCLICSENSE;

  if ((u32_wakeupSrc & (~PMU_WAKEUPSRC_ALL_SRC)) == 0u)
  {
    PMU->WAKE_CTRL.reg &= (~u32_wakeupSrcWithoutCycSense);
    /* PMU_WAKEUPSRC_CYCLICSENSE is in register CYC_CTRL */
    if ((u32_wakeupSrc & PMU_WAKEUPSRC_CYCLICSENSE) == PMU_WAKEUPSRC_CYCLICSENSE)
    {
     PMU->CYC_CTRL.bit.CYC_SENSE_EN = 0u;
    }
  }
  else
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}

/** \brief Get a wake-up source
 *
 * \return uint32 Selected wake-up source
 */
INLINE uint32 PMU_getWakeupSrc(void)
{
  return PMU->WAKE_CTRL.reg;
}

/** \brief Enable VDDC reduction in Stop Mode 
 */
INLINE void PMU_enStopModeVDDCReduct(void)
{
  PMU->WAKE_CTRL.bit.VDDC_RED_EN = 1u;
}

/** \brief Disable VDDC reduction in Stop Mode 
 */
INLINE void PMU_disStopModeVDDCReduct(void)
{
  PMU->WAKE_CTRL.bit.VDDC_RED_EN = 0u;
}

/** \brief Set a GPIO wake configuration
 *
 * \param u8_GPIO GPIO number
 * \param u8_enRisingEdge 1 to enable the wake-up on rising edge, 0 to disable the wake-up on rising edge
 * \param u8_enFallingEdge 1 to enable the wake-up on falling edge, 0 to disable the wake-up on falling edge
 * \param u8_enCycSen 1 to enable the cyclic sense, 0 to disable the cyclic sense
 * \param e_gpioInput GPIO input pointer
 * \return sint8 0: success, <0: error codes
 */
INLINE sint8 PMU_setGPIOWakeCfg(uint8 u8_GPIO, uint8 u8_enRisingEdge, uint8 u8_enFallingEdge, uint8 u8_enCycSen, tPMU_gpioInput e_gpioInput)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  if ((u8_enRisingEdge <= 1) && (u8_enFallingEdge <= 1) && (u8_enCycSen <= 1) && (e_gpioInput <= PMU_gpioInput_P2_9))
  {
    switch (u8_GPIO)
    {
      case 0:
      {
        PMU->WAKE_GPIO_CTRL0.bit.RI = u8_enRisingEdge;
        PMU->WAKE_GPIO_CTRL0.bit.FA = u8_enFallingEdge;
        PMU->WAKE_GPIO_CTRL0.bit.CYC = u8_enCycSen;
        PMU->WAKE_GPIO_CTRL0.bit.INP = (uint8)e_gpioInput;
        break;
      }

      case 1:
      {
        PMU->WAKE_GPIO_CTRL1.bit.RI = u8_enRisingEdge;
        PMU->WAKE_GPIO_CTRL1.bit.FA = u8_enFallingEdge;
        PMU->WAKE_GPIO_CTRL1.bit.CYC = u8_enCycSen;
        PMU->WAKE_GPIO_CTRL1.bit.INP = (uint8)e_gpioInput;
        break;
      }

      case 2:
      {
        PMU->WAKE_GPIO_CTRL2.bit.RI = u8_enRisingEdge;
        PMU->WAKE_GPIO_CTRL2.bit.FA = u8_enFallingEdge;
        PMU->WAKE_GPIO_CTRL2.bit.CYC = u8_enCycSen;
        PMU->WAKE_GPIO_CTRL2.bit.INP = (uint8)e_gpioInput;
        break;
      }

      case 3:
      {
        PMU->WAKE_GPIO_CTRL3.bit.RI = u8_enRisingEdge;
        PMU->WAKE_GPIO_CTRL3.bit.FA = u8_enFallingEdge;
        PMU->WAKE_GPIO_CTRL3.bit.CYC = u8_enCycSen;
        PMU->WAKE_GPIO_CTRL3.bit.INP = (uint8)e_gpioInput;
        break;
      }

      case 4:
      {
        PMU->WAKE_GPIO_CTRL4.bit.RI = u8_enRisingEdge;
        PMU->WAKE_GPIO_CTRL4.bit.FA = u8_enFallingEdge;
        PMU->WAKE_GPIO_CTRL4.bit.CYC = u8_enCycSen;
        PMU->WAKE_GPIO_CTRL4.bit.INP = (uint8)e_gpioInput;
        break;
      }

      case 5:
      {
        PMU->WAKE_GPIO_CTRL5.bit.RI = u8_enRisingEdge;
        PMU->WAKE_GPIO_CTRL5.bit.FA = u8_enFallingEdge;
        PMU->WAKE_GPIO_CTRL5.bit.CYC = u8_enCycSen;
        PMU->WAKE_GPIO_CTRL5.bit.INP = (uint8)e_gpioInput;
        break;
      }

      default:
      {
        s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
        break;
      }
    }
  }
  else
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}

/** \brief Set a MON wake configuration
 *
 * \param u8_MON MON number
 * \param u8_enRisingEdge 1 to enable the wake-up on rising edge, 0 to disable the wake-up on rising edge
 * \param u8_enFallingEdge 1 to enable the wake-up on falling edge, 0 to disable the wake-up on falling edge
 * \param u8_enCycSen 1 to enable the cyclic sense, 0 to disable the cyclic sense
 * \param u8_enPullupCurrSrc 1 to enable the input pull up current source, 0 to disable it
 * \param u8_enPulldownCurrSrc 1 to enable the input pull down current source, 0 to disable it
 * \return sint8 0: success, <0: error codes
 */
INLINE sint8 PMU_setMONWakeCfg(uint8 u8_MON, uint8 u8_enRisingEdge, uint8 u8_enFallingEdge, uint8 u8_enCycSen, uint8 u8_enPullupCurrSrc, uint8 u8_enPulldownCurrSrc)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  if ((u8_enRisingEdge <= 1) && (u8_enFallingEdge <= 1) && (u8_enCycSen <= 1) && (u8_enPullupCurrSrc <= 1) && (u8_enPulldownCurrSrc <= 1))
  {
    switch (u8_MON)
    {
      case 1:
      {
        PMU->MON_CTRL1.bit.WAKE_RISE = u8_enRisingEdge;
        PMU->MON_CTRL1.bit.WAKE_FALL = u8_enFallingEdge;
        PMU->MON_CTRL1.bit.CYC_SENSE_EN = u8_enCycSen;
        PMU->MON_CTRL1.bit.PU = u8_enPullupCurrSrc;
        PMU->MON_CTRL1.bit.PD = u8_enPulldownCurrSrc;
        break;
      }

      case 2:
      {
        PMU->MON_CTRL2.bit.WAKE_RISE = u8_enRisingEdge;
        PMU->MON_CTRL2.bit.WAKE_FALL = u8_enFallingEdge;
        PMU->MON_CTRL2.bit.CYC_SENSE_EN = u8_enCycSen;
        PMU->MON_CTRL2.bit.PU = u8_enPullupCurrSrc;
        PMU->MON_CTRL2.bit.PD = u8_enPulldownCurrSrc;
        break;
      }

      case 3:
      {
        PMU->MON_CTRL3.bit.WAKE_RISE = u8_enRisingEdge;
        PMU->MON_CTRL3.bit.WAKE_FALL = u8_enFallingEdge;
        PMU->MON_CTRL3.bit.CYC_SENSE_EN = u8_enCycSen;
        PMU->MON_CTRL3.bit.PU = u8_enPullupCurrSrc;
        PMU->MON_CTRL3.bit.PD = u8_enPulldownCurrSrc;
        break;
      }

      default:
      {
        s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
        break;
      }
    }
  }
  else
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}

/** \brief Get MON1 input status
 *
 * \return uint8 MON1 input status
 */
INLINE uint8 PMU_getMON1InputSts(void)
{
  return (uint8)PMU->MON_STS.bit.MON1_STS;
}

/** \brief Get MON2 input status
 *
 * \return uint8 MON2 input status
 */
INLINE uint8 PMU_getMON2InputSts(void)
{
  return (uint8)PMU->MON_STS.bit.MON2_STS;
}

/** \brief Get MON3 input status
 *
 * \return uint8 MON3 input status
 */
INLINE uint8 PMU_getMON3InputSts(void)
{
  return (uint8)PMU->MON_STS.bit.MON3_STS;
}

/** \brief Get CAN wake-up status
 *
 * \return uint8 CAN wake-up status
 */
INLINE uint8 PMU_getCANWakeSts(void)
{
  return (uint8)PMU->WAKE_STS.bit.CAN;
}

/** \brief Get  cyclic wake-up status
 *
 * \return uint8  cyclic wake-up status
 */
INLINE uint8 PMU_getCyclicWakeSts(void)
{
  return (uint8)PMU->WAKE_STS.bit.CYC_WAKE;
}

/** \brief Get GPIO0 wake-up status
 *
 * \return uint8 GPIO0 wake-up status
 */
INLINE uint8 PMU_getGPIO0WakeSts(void)
{
  return (uint8)PMU->WAKE_STS.bit.GPIO0;
}

/** \brief Get GPIO1 wake-up status
 *
 * \return uint8 GPIO1 wake-up status
 */
INLINE uint8 PMU_getGPIO1WakeSts(void)
{
  return (uint8)PMU->WAKE_STS.bit.GPIO1;
}

/** \brief Get GPIO2 wake-up status
 *
 * \return uint8 GPIO2 wake-up status
 */
INLINE uint8 PMU_getGPIO2WakeSts(void)
{
  return (uint8)PMU->WAKE_STS.bit.GPIO2;
}

/** \brief Get GPIO3 wake-up status
 *
 * \return uint8 GPIO3 wake-up status
 */
INLINE uint8 PMU_getGPIO3WakeSts(void)
{
  return (uint8)PMU->WAKE_STS.bit.GPIO3;
}

/** \brief Get GPIO4 wake-up status
 *
 * \return uint8 GPIO4 wake-up status
 */
INLINE uint8 PMU_getGPIO4WakeSts(void)
{
  return (uint8)PMU->WAKE_STS.bit.GPIO4;
}

/** \brief Get GPIO5 wake-up status
 *
 * \return uint8 GPIO5 wake-up status
 */
INLINE uint8 PMU_getGPIO5WakeSts(void)
{
  return (uint8)PMU->WAKE_STS.bit.GPIO5;
}

/** \brief Get MON1 wake-up status
 *
 * \return uint8 MON1 wake-up status
 */
INLINE uint8 PMU_getMON1WakeSts(void)
{
  return (uint8)PMU->WAKE_STS.bit.MON1;
}

/** \brief Get MON2 wake-up status
 *
 * \return uint8 MON2 wake-up status
 */
INLINE uint8 PMU_getMON2WakeSts(void)
{
  return (uint8)PMU->WAKE_STS.bit.MON2;
}

/** \brief Get MON3 wake-up status
 *
 * \return uint8 MON3 wake-up status
 */
INLINE uint8 PMU_getMON3WakeSts(void)
{
  return (uint8)PMU->WAKE_STS.bit.MON3;
}

/** \brief Get VDDP undervoltage warning wake-up status
 *
 * \return uint8 VDDP undervoltage warning wake-up status
 */
INLINE uint8 PMU_getVDDPUndervoltageWarnWakeSts(void)
{
  return (uint8)PMU->WAKE_STS.bit.VDDP_UVWARN;
}

/** \brief Get VDDP overvoltage wake-up status
 *
 * \return uint8 VDDP overvoltage wake-up status
 */
INLINE uint8 PMU_getVDDPOvervoltageWakeSts(void)
{
  return (uint8)PMU->WAKE_STS.bit.VDDP_OV;
}

/** \brief Get VDDP high current mode wake-up status
 *
 * \return uint8 VDDP high current mode wake-up status
 */
INLINE uint8 PMU_getVDDPHighCurrentModeWakeSts(void)
{
  return (uint8)PMU->WAKE_STS.bit.VDDP_HCM;
}

/** \brief Get VDDC undervoltage warning wake-up status
 *
 * \return uint8 VDDC undervoltage warning wake-up status
 */
INLINE uint8 PMU_getVDDCUndervoltageWarnWakeSts(void)
{
  return (uint8)PMU->WAKE_STS.bit.VDDC_UVWARN;
}

/** \brief Get VDDC overvoltage wake-up status
 *
 * \return uint8 VDDC overvoltage wake-up status
 */
INLINE uint8 PMU_getVDDCOvervoltageWakeSts(void)
{
  return (uint8)PMU->WAKE_STS.bit.VDDC_OV;
}

/** \brief Get VDDC high current mode wake-up status
 *
 * \return uint8 VDDC high current mode wake-up status
 */
INLINE uint8 PMU_getVDDCHighCurrentModeWakeSts(void)
{
  return (uint8)PMU->WAKE_STS.bit.VDDC_HCM;
}

/** \brief Get VDDEXT overtemperature wake-up status
 *
 * \return uint8 VDDEXT overtemperature wake-up status
 */
INLINE uint8 PMU_getVDDEXTOvertemperatureWakeSts(void)
{
  return (uint8)PMU->WAKE_STS.bit.VDDEXT_OT;
}

/** \brief Get VDDEXT undervoltage wake-up status
 *
 * \return uint8 VDDEXT undervoltage wake-up status
 */
INLINE uint8 PMU_getVDDEXTUndervoltageWakeSts(void)
{
  return (uint8)PMU->WAKE_STS.bit.VDDEXT_UV;
}

/** \brief Get VSD overvoltage wake-up status
 *
 * \return uint8 VSD overvoltage wake-up status
 */
INLINE uint8 PMU_getVSDOvervoltageWakeSts(void)
{
  return (uint8)PMU->WAKE_STS.bit.VSD_OV;
}

/** \brief Clear CAN wake-up status
 */
INLINE void PMU_clrCANWakeSts(void)
{
  PMU->WAKE_STS_CLR.bit.CAN_CLR = 1u;
}

/** \brief Clear  cyclic wake-up status
 */
INLINE void PMU_clrCyclicWakeSts(void)
{
  PMU->WAKE_STS_CLR.bit.CYC_WAKE_CLR = 1u;
}

/** \brief Clear GPIO0 wake-up status
 */
INLINE void PMU_clrGPIO0WakeSts(void)
{
  PMU->WAKE_STS_CLR.bit.GPIO0_CLR = 1u;
}

/** \brief Clear GPIO1 wake-up status
 */
INLINE void PMU_clrGPIO1WakeSts(void)
{
  PMU->WAKE_STS_CLR.bit.GPIO1_CLR = 1u;
}

/** \brief Clear GPIO2 wake-up status
 */
INLINE void PMU_clrGPIO2WakeSts(void)
{
  PMU->WAKE_STS_CLR.bit.GPIO2_CLR = 1u;
}

/** \brief Clear GPIO3 wake-up status
 */
INLINE void PMU_clrGPIO3WakeSts(void)
{
  PMU->WAKE_STS_CLR.bit.GPIO3_CLR = 1u;
}

/** \brief Clear GPIO4 wake-up status
 */
INLINE void PMU_clrGPIO4WakeSts(void)
{
  PMU->WAKE_STS_CLR.bit.GPIO4_CLR = 1u;
}

/** \brief Clear GPIO5 wake-up status
 */
INLINE void PMU_clrGPIO5WakeSts(void)
{
  PMU->WAKE_STS_CLR.bit.GPIO5_CLR = 1u;
}

/** \brief Clear MON1 wake-up status
 */
INLINE void PMU_clrMON1WakeSts(void)
{
  PMU->WAKE_STS_CLR.bit.MON1_CLR = 1u;
}

/** \brief Clear MON2 wake-up status
 */
INLINE void PMU_clrMON2WakeSts(void)
{
  PMU->WAKE_STS_CLR.bit.MON2_CLR = 1u;
}

/** \brief Clear MON3 wake-up status
 */
INLINE void PMU_clrMON3WakeSts(void)
{
  PMU->WAKE_STS_CLR.bit.MON3_CLR = 1u;
}

/** \brief Clear VDDP undervoltage warning wake-up status
 */
INLINE void PMU_clrVDDPUndervoltageWarnWakeSts(void)
{
  PMU->WAKE_STS_CLR.bit.VDDP_UVWARN_CLR = 1u;
}

/** \brief Clear VDDP overvoltage wake-up status
 */
INLINE void PMU_clrVDDPOvervoltageWakeSts(void)
{
  PMU->WAKE_STS_CLR.bit.VDDP_OV_CLR = 1u;
}

/** \brief Clear VDDP high current mode wake-up status
 */
INLINE void PMU_clrVDDPHighCurrentModeWakeSts(void)
{
  PMU->WAKE_STS_CLR.bit.VDDP_HCM_CLR = 1u;
}

/** \brief Clear VDDC undervoltage warning wake-up status
 */
INLINE void PMU_clrVDDCUndervoltageWarnWakeSts(void)
{
  PMU->WAKE_STS_CLR.bit.VDDC_UVWARN_CLR = 1u;
}

/** \brief Clear VDDC overvoltage wake-up status
 */
INLINE void PMU_clrVDDCOvervoltageWakeSts(void)
{
  PMU->WAKE_STS_CLR.bit.VDDC_OV_CLR = 1u;
}

/** \brief Clear VDDC high current mode wake-up status
 */
INLINE void PMU_clrVDDCHighCurrentModeWakeSts(void)
{
  PMU->WAKE_STS_CLR.bit.VDDC_HCM_CLR = 1u;
}

/** \brief Clear VDDEXT overtemperature wake-up status
 */
INLINE void PMU_clrVDDEXTOvertemperatureWakeSts(void)
{
  PMU->WAKE_STS_CLR.bit.VDDEXT_OT_CLR = 1u;
}

/** \brief Clear VDDEXT undervoltage wake-up status
 */
INLINE void PMU_clrVDDEXTUndervoltageWakeSts(void)
{
  PMU->WAKE_STS_CLR.bit.VDDEXT_UV_CLR = 1u;
}

/** \brief Clear VSD overvoltage wake-up status
 */
INLINE void PMU_clrVSDOvervoltageWakeSts(void)
{
  PMU->WAKE_STS_CLR.bit.VSD_OV_CLR = 1u;
}

/** \brief Enable the failure input pull up
 */
INLINE void PMU_enFailInputPullUp(void)
{
  PMU->MISC_CTRL.bit.FI_PU_EN = 1u;
}

/** \brief Enable the RAM test after wake-up from Stop mode
 */
INLINE void PMU_enStartCfg(void)
{
  PMU->START_CONFIG.bit.CONF = 1u;
}

/** \brief Enable the Reset pin
 */
INLINE void PMU_enResetPin(void)
{
  PMU->START_CONFIG.bit.RST_PIN_EN = 1u;
}

/** \brief Disable the failure input pull up
 */
INLINE void PMU_disFailInputPullUp(void)
{
  PMU->MISC_CTRL.bit.FI_PU_EN = 0u;
}

/** \brief Disable the RAM test after wake-up from Stop mode
 */
INLINE void PMU_disStartCfg(void)
{
  PMU->START_CONFIG.bit.CONF = 0u;
}

/** \brief Disable the Reset Pin
 */
INLINE void PMU_disResetPin(void)
{
  PMU->START_CONFIG.bit.RST_PIN_EN = 0u;
}

/** \brief Get master clock watchdog fail status
 *
 * \return uint8 master clock watchdog fail status
 */
INLINE uint8 PMU_getMstrClkWDFailSts(void)
{
  return (uint8)PMU->FS_STS.bit.MCLK_FAIL_STS;
}

/** \brief Get master supply undervoltage status
 *
 * \return uint8 master supply undervoltage status
 */
INLINE uint8 PMU_getMstrSupplyUndervoltageSts(void)
{
  return (uint8)PMU->FS_STS.bit.VMSUP_UV_STS;
}

/** \brief Get master supply overvoltage status
 *
 * \return uint8 master supply overvoltage status
 */
INLINE uint8 PMU_getMstrSupplyOvervoltageSts(void)
{
  return (uint8)PMU->FS_STS.bit.VMSUP_OV_STS;
}

/** \brief Get watchdog fail status
 *
 * \return uint8 watchdog fail status
 */
INLINE uint8 PMU_getWDFailSts(void)
{
  return (uint8)PMU->FS_STS.bit.WD_FAIL_STS;
}

/** \brief Get watchdog self-test fail status
 *
 * \return uint8 watchdog self-test fail status
 */
INLINE uint8 PMU_getWDSelfTestFailSts(void)
{
  return (uint8)PMU->FS_STS.bit.WD_TEST_FAIL_STS;
}

/** \brief Get VDDC undervoltage status
 *
 * \return uint8 VDDC undervoltage status
 */
INLINE uint8 PMU_getVDDCUndervoltageSts(void)
{
  return (uint8)PMU->FS_STS.bit.VDDC_UV_STS;
}

/** \brief Get VDDC overvoltage status
 *
 * \return uint8 VDDC overvoltage status
 */
INLINE uint8 PMU_getVDDCOvervoltageSts(void)
{
  return (uint8)PMU->FS_STS.bit.VDDC_OV_STS;
}

/** \brief Get VDDP undervoltage status
 *
 * \return uint8 VDDP undervoltage status
 */
INLINE uint8 PMU_getVDDPUndervoltageSts(void)
{
  return (uint8)PMU->FS_STS.bit.VDDP_UV_STS;
}

/** \brief Get VDDP overvoltage status
 *
 * \return uint8 VDDP overvoltage status
 */
INLINE uint8 PMU_getVDDPOvervoltageSts(void)
{
  return (uint8)PMU->FS_STS.bit.VDDP_OV_STS;
}

/** \brief Get VDDP overtemperature status
 *
 * \return uint8 VDDP overtemperature status
 */
INLINE uint8 PMU_getVDDPOvertemperatureSts(void)
{
  return (uint8)PMU->FS_STS.bit.VDDP_OT_STS;
}

/** \brief Get VAREF overvoltage status
 *
 * \return uint8 VAREF overvoltage status
 */
INLINE uint8 PMU_getVAREFOvervoltageSts(void)
{
  return (uint8)PMU->FS_STS.bit.VAREF_OV_STS;
}

/** \brief Get CSC overcurrent status
 *
 * \return uint8 CSC overcurrent status
 */
INLINE uint8 PMU_getCSCOvercurrentSts(void)
{
  return (uint8)PMU->FS_STS.bit.CSC_OC_STS;
}

/** \brief Get CSC self-test fail status
 *
 * \return uint8 CSC self-test fail status
 */
INLINE uint8 PMU_getCSCSelfTestFailSts(void)
{
  return (uint8)PMU->FS_STS.bit.CSC_BIST_FAIL_STS;
}

/** \brief Get CSC enabling fail status
 *
 * \return uint8 CSC enabling fail status
 */
INLINE uint8 PMU_getCSCEnFailSts(void)
{
  return (uint8)PMU->FS_STS.bit.CSC_EN_FAIL_STS;
}

/** \brief Get pin monitor fail status
 *
 * \return uint8 pin monitor fail status
 */
INLINE uint8 PMU_getPinMonitorFailSts(void)
{
  return (uint8)PMU->FS_STS.bit.PIN_MON_STS;
}

/** \brief Get FO overcurrent status
 *
 * \return uint8 FO overcurrent status
 */
INLINE uint8 PMU_getFOOvercurrentSts(void)
{
  return (uint8)PMU->FS_STS.bit.FO_OC_STS;
}

/** \brief Clear master clock watchdog fail status
 */
INLINE void PMU_clrMstrClkWDFailSts(void)
{
  PMU->FS_STS_CLR.bit.MCLK_FAIL_STS_CLR = 1u;
}

/** \brief Clear master supply undervoltage status
 */
INLINE void PMU_clrMstrSupplyUndervoltageSts(void)
{
  PMU->FS_STS_CLR.bit.VMSUP_UV_STS_CLR = 1u;
}

/** \brief Clear master supply overvoltage status
 */
INLINE void PMU_clrMstrSupplyOvervoltageSts(void)
{
  PMU->FS_STS_CLR.bit.VMSUP_OV_STS_CLR = 1u;
}

/** \brief Clear watchdog fail status
 */
INLINE void PMU_clrWDFailSts(void)
{
  PMU->FS_STS_CLR.bit.WD_FAIL_STS_CLR = 1u;
}

/** \brief Clear watchdog self-test fail status
 */
INLINE void PMU_clrWDSelfTestFailSts(void)
{
  PMU->FS_STS_CLR.bit.WD_TEST_FAIL_STS_CLR = 1u;
}

/** \brief Clear VDDC undervoltage status
 */
INLINE void PMU_clrVDDCUndervoltageSts(void)
{
  PMU->FS_STS_CLR.bit.VDDC_UV_STS_CLR = 1u;
}

/** \brief Clear VDDC overvoltage status
 */
INLINE void PMU_clrVDDCOvervoltageSts(void)
{
  PMU->FS_STS_CLR.bit.VDDC_OV_STS_CLR = 1u;
}

/** \brief Clear VDDP undervoltage status
 */
INLINE void PMU_clrVDDPUndervoltageSts(void)
{
  PMU->FS_STS_CLR.bit.VDDP_UV_STS_CLR = 1u;
}

/** \brief Clear VDDP overvoltage status
 */
INLINE void PMU_clrVDDPOvervoltageSts(void)
{
  PMU->FS_STS_CLR.bit.VDDP_OV_STS_CLR = 1u;
}

/** \brief Clear VDDP overtemperature status
 */
INLINE void PMU_clrVDDPOvertemperatureSts(void)
{
  PMU->FS_STS_CLR.bit.VDDP_OT_STS_CLR = 1u;
}

/** \brief Clear VAREF overvoltage status
 */
INLINE void PMU_clrVAREFOvervoltageSts(void)
{
  PMU->FS_STS_CLR.bit.VAREF_OV_STS_CLR = 1u;
}

/** \brief Clear CSC overcurrent status
 */
INLINE void PMU_clrCSCOvercurrentSts(void)
{
  PMU->FS_STS_CLR.bit.CSC_OC_STS_CLR = 1u;
}

/** \brief Clear CSC self-test fail status
 */
INLINE void PMU_clrCSCSelfTestFailSts(void)
{
  PMU->FS_STS_CLR.bit.CSC_BIST_FAIL_STS_CLR = 1u;
}

/** \brief Clear CSC enabling fail status
 */
INLINE void PMU_clrCSCEnFailSts(void)
{
  PMU->FS_STS_CLR.bit.CSC_EN_FAIL_STS_CLR = 1u;
}

/** \brief Clear pin monitor fail status
 */
INLINE void PMU_clrPinMonitorFailSts(void)
{
  PMU->FS_STS_CLR.bit.PIN_MON_STS_CLR = 1u;
}

/** \brief Clear FO overcurrent status
 */
INLINE void PMU_clrFOOvercurrentSts(void)
{
  PMU->FS_STS_CLR.bit.FO_OC_STS_CLR = 1u;
}

/** \brief Get safe shutdown status
 *
 * \return uint8 safe shutdown status
 */
INLINE uint8 PMU_getSafeShutdownSts(void)
{
  return (uint8)PMU->FS_SSD.bit.SSD_STS;
}

/** \brief Get fail output status
 *
 * \return uint8 fail output status
 */
INLINE uint8 PMU_getFailOutputSts(void)
{
  return (uint8)PMU->FS_SSD.bit.FO_STS;
}

/** \brief Clear safe shutdown status
 */
INLINE void PMU_clrSafeShutdownSts(void)
{
  PMU->FS_SSD_CLR.bit.SSD_STS_CLR = 1u;
}

/** \brief Clear fail output status
 */
INLINE void PMU_clrFailOutputSts(void)
{
  PMU->FS_SSD_CLR.bit.FO_STS_CLR = 1u;
}

/** @}*/

#endif /* _PMU_H */

