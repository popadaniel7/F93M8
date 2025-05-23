/**********************************************************************************************************************
 * \file SafetyKit_SSW.c
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

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "SafetyKit_SSW.h"
#include "SafetyKit_SSW_00_LBIST.h"
#include "SafetyKit_SSW_02_MCU_FW_CHECK.h"
#include "SafetyKit_SSW_03_MCU_STARTUP.h"
#include "SafetyKit_SSW_04_ALIVE_ALARM_TEST.h"
#include "SafetyKit_SSW_05_SMU_REG_MONITOR_TEST.h"
#include "SafetyKit_SSW_06_MBIST.h"
#include "SafetyKit_Main.h"
#include "IfxScuRcu.h"
#include "Ifx_Cfg_Ssw.h"
#include "IfxMtu.h"
#include "IfxStm.h"
#include "Bsp.h"
#include "IfxPort.h"
#include "IfxScuLbist.h"
#include "Ifx_Ssw_Infra.h"
#include "IfxPmsPm.h"
#include "IfxSmu.h"
#include "SMU.h"
#include "SafetyKit_SSW_00_LBIST.h"
/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define PMSWSTAT2_WAKE_UP_FLAGS_MASK     0xFF
/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*-------------------------------------------------Data Structures---------------------------------------------------*/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
SafetyKitResetCode safetyKitEvaluateReset(void);
boolean safetyKitEvaluateStandby(void);
/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
/*
 * Execute the sequence of safety mechanisms when coming from an un-powered state.
 * Refer to Figure 7 in AURIX TC3xx Safety Manual
 * */
void runSafeAppSwStartup(void)
{
    safetyKitSswLbist();
    g_SafetyKitStatus.resetCode = safetyKitEvaluateReset();
    g_SafetyKitStatus.wakeupFromStandby = safetyKitEvaluateStandby();
    g_SafetyKitStatus.sswStatus.monbistStatus = failed;
    Ifx_Ssw_Monbist();
    g_SafetyKitStatus.sswStatus.monbistStatus = passed;
    safetyKitSswMcuFwCheck();
    safetyKitSswMcuStartup();
    safetyKitSswAliveAlarmTest();
    safetyKitSswSmuRegMonitorTest();
    safetyKitSswMbist();
    safetyKitEnableAllSMUAlarms();
}
/*
 * This function Evaluate the Reset and returns reset code which contains Reset type, trigger and reason details.
 */
SafetyKitResetCode safetyKitEvaluateReset(void)
{
    static boolean resetEvaluated = FALSE;
    static SafetyKitResetCode resetCode;
    /* This function guarantees that reset type will be evaluated only once
     * and that its value will not change during runtime.
     * The first time this function is called, it evaluate the reset type and
     *  clears RSTSTAT register.
     */
    if (resetEvaluated == FALSE)
    {
        Ifx_SCU_RSTCON rstCon;
        Ifx_SCU_RSTSTAT rstStat;

        resetCode.cpuSafeState = (((MODULE_SCU.RSTCON2.U >> IFX_SCU_RSTCON2_CSSX_OFF) & IFX_SCU_RSTCON2_CSSX_MSK) == IFX_SCU_RSTCON2_CSSX_MSK);
        resetCode.resetType = safetyKitResetTypeUndefined;
        resetCode.resetTrigger = IfxScuRcu_Trigger_undefined;
        resetCode.resetReason = 0;
        rstStat.U = MODULE_SCU.RSTSTAT.U;
        rstCon.U = MODULE_SCU.RSTCON.U;

        /* Evaluate the warm reset conditions first */
        if (rstStat.B.ESR0)
        {
            resetCode.resetType = (SafetyKitResetType) rstCon.B.ESR0;
            resetCode.resetTrigger = IfxScuRcu_Trigger_esr0;
            resetCode.resetReason = 0;
        }
        else if (rstStat.B.ESR1)
        {
            resetCode.resetType = (SafetyKitResetType) rstCon.B.ESR1;
            resetCode.resetTrigger = IfxScuRcu_Trigger_esr1;
            resetCode.resetReason = 0;
        }
        else if (rstStat.B.SMU)
        {
            resetCode.resetType = (SafetyKitResetType) rstCon.B.SMU;
            resetCode.resetTrigger = IfxScuRcu_Trigger_smu;
            resetCode.resetReason = 0;
        }
        else if (rstStat.B.SW)
        {
            resetCode.resetType = (SafetyKitResetType) rstCon.B.SW;
            resetCode.resetTrigger = IfxScuRcu_Trigger_sw;
            resetCode.resetReason = MODULE_SCU.RSTCON2.B.USRINFO;
        }
        else if (rstStat.B.STM0)
        {
            resetCode.resetType = (SafetyKitResetType) rstCon.B.STM0;
            resetCode.resetTrigger = IfxScuRcu_Trigger_stm0;
            resetCode.resetReason = 0;
        }
        else if (rstStat.B.STM1)
        {
            resetCode.resetType = (SafetyKitResetType) rstCon.B.STM1;
            resetCode.resetTrigger = IfxScuRcu_Trigger_stm1;
            resetCode.resetReason = 0;
        }
        else if (rstStat.B.STM2)
        {
            resetCode.resetType = (SafetyKitResetType) rstCon.B.STM2;
            resetCode.resetTrigger = IfxScuRcu_Trigger_stm2;
            resetCode.resetReason = 0;
        }
        else if (rstStat.B.CB0)
        {
            resetCode.resetType = safetyKitResetTypeSystem;
            resetCode.resetTrigger = IfxScuRcu_Trigger_cb0;
            resetCode.resetReason = 0;
        }
        else if (rstStat.B.CB1)
        {
            resetCode.resetType = safetyKitResetTypeDebug;
            resetCode.resetTrigger = IfxScuRcu_Trigger_cb1;
            resetCode.resetReason = 0;
        }
        else if (rstStat.B.CB3)
        {
            resetCode.resetType = safetyKitResetTypeApplication;
            resetCode.resetTrigger = IfxScuRcu_Trigger_cb3;
            resetCode.resetReason = 0;
        }
        else if (rstStat.B.LBTERM)
        {
            resetCode.resetType = safetyKitResetTypeLbist;
            resetCode.resetTrigger = IfxScuRcu_Trigger_swd;
            resetCode.resetReason = 0;
        }
        else
        {
            /* Now evaluate for Cold reset conditions */
            if (rstStat.B.EVRC)
            {
                resetCode.resetType = safetyKitResetTypeColdpoweron;
                resetCode.resetTrigger = IfxScuRcu_Trigger_evrc;
                resetCode.resetReason = 0;
            }
            else if (rstStat.B.EVR33)
            {
                resetCode.resetType = safetyKitResetTypeColdpoweron;
                resetCode.resetTrigger = IfxScuRcu_Trigger_evr33;
                resetCode.resetReason = 0;
            }
            else if (rstStat.B.SWD)
            {
                resetCode.resetType = safetyKitResetTypeColdpoweron;
                resetCode.resetTrigger = IfxScuRcu_Trigger_swd;
                resetCode.resetReason = 0;
            }
            else if (rstStat.B.STBYR)
            {
                resetCode.resetType = safetyKitResetTypeColdpoweron;
                resetCode.resetTrigger = IfxScuRcu_Trigger_stbyr;
                resetCode.resetReason = 0;
            }
            else
            {
                /* Do nothing. */
            }
        }
        /* Finally - Evaluate selectively for PORST */
        if (rstStat.B.PORST)
        {
            if (resetCode.resetType != safetyKitResetTypeColdpoweron
                    && resetCode.resetType != safetyKitResetTypeLbist )
            {
                resetCode.resetType = safetyKitResetTypeWarmpoweron;
                resetCode.resetTrigger = IfxScuRcu_Trigger_portst;
            }
            else
            {
                /* Do nothing. */
            }

            resetCode.resetReason = 0;
        }
        else
        {
            /* Do nothing. */
        }

        resetEvaluated = TRUE;
        /* Clear COLD PORST reason */
        IfxScuRcu_clearColdResetStatus();
    }
    else
    {
        /* Do nothing. */
    }

    return resetCode;
}
/*
 * This function evaluates if software execution is continuing after being in Standby mode
 * */
boolean safetyKitEvaluateStandby(void)
{
    static boolean standbyEvaluated = FALSE;
    static boolean comingFromStandby = FALSE;

    if(standbyEvaluated == FALSE)
    {
        if ((PMS_PMSWSTAT2.U & PMSWSTAT2_WAKE_UP_FLAGS_MASK) > 0)
        {
            /* Clear standby flag */
            uint16 endinitSfty_pw = IfxScuWdt_getSafetyWatchdogPassword();

            IfxScuWdt_clearSafetyEndinit(endinitSfty_pw);

            PMS_PMSWSTATCLR.U |= (PMS_PMSWSTAT2.U & PMSWSTAT2_WAKE_UP_FLAGS_MASK);

            IfxScuWdt_setSafetyEndinit(endinitSfty_pw);

            comingFromStandby = TRUE;
        }
        else
        {
            comingFromStandby = FALSE;
        }
    }

    return comingFromStandby;
}
/*
 * Triggering a Warm PORST via the LBIST.
 * Note: As stated in Errata BROM_TC.H017 : "In AURIX™ TC3xx devices, LBIST execution terminates [..]
 * with a warm reset." but
 * "The Startup Software executed afterwards follows the flow as after cold power-on [..]"
 * */
void safetyKitTriggerWarmPorst(void)
{
    safetyKitTriggerLbist();
    /* Note: MCU_FW_CHECK (safetyKitSswMcuFwCheck()) will fail, as FW_CHECK compares expected register
     * values as if no LBIST was executed before. */
}
