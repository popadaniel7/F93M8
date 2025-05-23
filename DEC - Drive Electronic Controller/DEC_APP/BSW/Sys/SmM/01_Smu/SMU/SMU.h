/**********************************************************************************************************************
 * \file SMU.h
 * \copyright Copyright (C) Infineon Technologies AG 2019
 *
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are solely in the form of
 * machine-executable object code generated by a source language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *********************************************************************************************************************/
#ifndef SMU_H_
#define SMU_H_
/*********************************************************************************************************************/
/*----------------------------------Includes-------------------------------------------------------------------------*/
/*********************************************************************************************************************/
#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxSrc_reg.h"
#include "IfxSmu.h"
#include "IfxSmu_cfg.h"
#include "IfxSrc_cfg.h"
#include "IfxMtu_cfg.h"
#include "IfxCpu_Trap.h"
/*********************************************************************************************************************/
/*-----------------------------------Macros--------------------------------------------------------------------------*/
/*********************************************************************************************************************/
#define SOFT_SMU_ALM_CFG_CHECK      IfxSmu_Alarm_Software_Alarm0
#define SOFT_SMU_ALM_SMU            IfxSmu_Alarm_Software_Alarm1
#define SOFT_SMU_ALM_ADC            IfxSmu_Alarm_Software_Alarm2
#define SOFT_SMU_ALM_ADC_BND        IfxSmu_Alarm_Software_Alarm3       /*Broken wire detection*/
#define SOFT_SMU_ALM_GTM_TOM_TIM    IfxSmu_Alarm_Software_Alarm4       /* TOM_TIM and TOM_IOM */
#define SOFT_SMU_ALM_GTM_CCU6_GPT12 IfxSmu_Alarm_Software_Alarm5
#define SOFT_SMU_ALM_GTM_TIM_CCU6   IfxSmu_Alarm_Software_Alarm6       /*TIM_CCU6 or IOM_CCU6 */
#define SOFT_SMU_ALM_GTM_TIM_TIM    IfxSmu_Alarm_Software_Alarm7
#define SOFT_SMU_ALM_GTM_ECKL       IfxSmu_Alarm_Software_Alarm8
#define SOFT_SMU_ALM_DMA            IfxSmu_Alarm_Software_Alarm9
#define SOFT_SMU_ALM_QSPI_SAFE      IfxSmu_Alarm_Software_Alarm10      /* QSPI safe communication */
#define SOFT_SMU_ALM_STM            IfxSmu_Alarm_Software_Alarm11      /* compare two stm ticks */
#define SOFT_SMU_ALM_PFLASH         IfxSmu_Alarm_Software_Alarm12
#define SOFT_SMU_ALM_DTS            IfxSmu_Alarm_Software_Alarm13
#define SOFT_SMU_ALM_PORT_SMs       IfxSmu_Alarm_Software_Alarm14      /* used for port redundancy and loopback*/
#define SOFT_SMU_ALM_CLOCK_PLAUS    IfxSmu_Alarm_Software_Alarm15     /* used the same for QPSI safe communication */
#define USER_ALARM_NUMBER           36u
#define AMOUNT_OF_SMU_ALARMS        (uint16)(IfxSmu_Alarm_XBAR_SOTA_SwapError + 1u)
/* Just took last alarm as default, any alarm can be set here */
#define DEFAULT_ALARM               (uint16)(IfxSmu_Alarm_XBAR_SOTA_SwapError)
#define DEFAULT_ALARM_ACTION        IfxSmu_InternalAlarmAction_nmi

/*********************************************************************************************************************/
/*--------------------------------Enumerations-----------------------------------------------------------------------*/
/*********************************************************************************************************************/
typedef enum
{
    SmuSR0       = 1u,
    SmuSR1       = 2u,
    SmuSR0SR1    = 3u,
    SmuSR2       = 4u,
    SmuSR0SR2    = 5u,
    SmuSR1SR2    = 6u,
    SmuSR0SR1SR2 = 7u,
    SmuNAN       = 8u,
} SmuSR;
typedef enum
{
    disablePES     = 0x0u,
    onPESIGCS0     = 0x1u,
    onPESIGCS1     = 0x2u,
    onPESIGCS2     = 0x4u,
    onPESNMI       = 0x8u,
    onPESCPU_RESET = 0x10u,
} TargetPES;
typedef enum
{
    NA     = -1,
    fail   = 0u,
    pass   = 1u,
} SmuStatusType;
typedef enum
{
    notPending = 0u,
    pending    = 1u,
} AlarmStatSMU;
/*********************************************************************************************************************/
/*-----------------------------Data Structures-----------------------------------------------------------------------*/
/*********************************************************************************************************************/
/* Holds the config of an alarm */
typedef struct
{
    IfxSmu_Alarm                alarm;
    IfxSmu_InternalAlarmAction  alarmReaction;
    boolean                     externalReactionEnabled;
    boolean                     triggerRecoveryTimer;
    void                        (*functionToCallOnDetection)(void);
} AlarmConfigStruct;
/* Bind an IGCS reaction with its config */
typedef struct {
    IfxSmu_InternalAlarmAction  igcs_id;
    SmuSR                      igcs_config;
} IGCSisrBindingStruct;
/* Store the state of an user configured alarm with its config (const) */
typedef struct {
    const AlarmConfigStruct*  alarmConfig;
    AlarmStatSMU             alarmState;
} RuntimeAlarmHandle;
/* Hold records of all the alarm raised */
typedef struct
{
    RuntimeAlarmHandle  *lastAlarmRaised[USER_ALARM_NUMBER];
    uint16              alarmCounter;
} SmuAlarmPendingType;
/* Store function execution status */
typedef struct
{
    SmuStatusType regMonitorTestSmu;
    SmuStatusType structInitSts;
    SmuStatusType unlockConfigRegisterSMU;
    SmuStatusType smuCoreAlarmConfigSts;
    SmuStatusType smuCoreAliveTestSts;
    SmuStatusType smuCoreAliveTestClearSts;
    SmuStatusType smuCoreKeysTestSts;
    SmuStatusType smuCoreKeysTestClearSts;
    SmuStatusType stdbySmuFspReactionEnableSts;
    SmuStatusType smuStdbyFSP0DrivingEnableSts;
    SmuStatusType smuStdbyFSP1DrivingEnableSts;
    SmuStatusType smuCoreInitSts;
    SmuStatusType smuCoreAlarmPESSetSts;
    SmuStatusType smuCoreFSPConfigSts;
    SmuStatusType smuCoreFSPReactionToAlarmConfigSts;
    SmuStatusType smuSafetyFlipFlopTriggerTestSts;
    SmuStatusType smuSafetyFlipFlopTestResultCheckSts;
    SmuStatusType smuSafetyFlipFlopTestAlarmFlagClearSts;
    SmuStatusType smuRecoveryTimerConfigSts;
    SmuStatusType smuCoreSWAlarmTriggerSts;
} SmuExecutionStatusType;
/*********************************************************************************************************************/
/*------------------------------Global variables---------------------------------------------------------------------*/
/*********************************************************************************************************************/

/*********************************************************************************************************************/
/*-------------------------Function Prototypes-----------------------------------------------------------------------*/
/*********************************************************************************************************************/
void safetyKitEnableAllSMUAlarms(void);
void initSMUModule(void);
SmuStatusType softwareCoreAlarmTriggerSMU(IfxSmu_Alarm alarm);
uint16 detectAlarmSourcSMU(RuntimeAlarmHandle *alarm_array, uint16 nbr_alarms);
SmuStatusType coreAlarmReactionClearSMU(RuntimeAlarmHandle *active_alarm);
SmuStatusType resetAllAlarmsSMU(void);
#endif /* SMU_H_ */
