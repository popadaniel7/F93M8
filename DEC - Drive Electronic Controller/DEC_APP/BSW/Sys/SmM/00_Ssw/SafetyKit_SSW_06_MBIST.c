/**********************************************************************************************************************
 * \file SafetyKit_SSW_06_MBIST.c
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
#include "SafetyKit_SSW_06_MBIST.h"
#include "SafetyKit_Main.h"
#include "IfxMtu.h"
#include "Ifx_Cfg_Ssw.h"
#include "IfxDma_reg.h"
/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*-------------------------------------------------Data Structures---------------------------------------------------*/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
/*********************************************************************************************************************/
/*------------------------------------------------Function Prototypes------------------------------------------------*/
/*********************************************************************************************************************/
IFX_EXTERN const IfxMtu_MbistConfig *const mbistGangConfig[];
void safetyKitClearMbistSshRegisters(void);
/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
#if SAFETYKIT_CFG_SSW_ENABLE_MBIST
/*
 * SM:VMT:MBIST
 * */
void safetyKitSswMbist(void)
{
    g_SafetyKitStatus.sswStatus.mbistStatus = notEvaluated;
    /* Note:
     * - EMEM is per default not included in iLLD MBIST
     * - "For peripherals SRAMs, it shall be ensured that the module does not access the
     *    SRAM under test" (Refer to UM 13.3.8.1) */

    /* Preparations for MBIST */
    /* Disable all other CPUs, but of course not the one which is executing the function */
    IfxCpu_ResourceCpu coreIndex  = IfxCpu_getCoreIndex();

    if(coreIndex != IfxCpu_ResourceCpu_0)
    {
        IfxCpu_setCoreMode(&MODULE_CPU0, IfxCpu_CoreMode_idle);
    }
    else
    {
        /* Do nothing. */
    }
#if (IFXCPU_NUM_MODULES > 1u)
    if(coreIndex != IfxCpu_ResourceCpu_1)
    {
        IfxCpu_setCoreMode(&MODULE_CPU1, IfxCpu_CoreMode_idle);
    }
    else
    {
        /* Do nothing. */
    }
#endif
#if (IFXCPU_NUM_MODULES > 2u)
    if(coreIndex != IfxCpu_ResourceCpu_2)
    {
        IfxCpu_setCoreMode(&MODULE_CPU2, IfxCpu_CoreMode_idle);
    }
    else
    {
        /* Do nothing. */
    }
#endif
    /* Disable CPU caches */
    IfxCpu_setDataCache    (0u);
    IfxCpu_setProgramCache (0u);
    /* If DMA master is enabled disable it */
    boolean dmaWasEnabled = FALSE;

    if(MODULE_DMA.CLC.B.DISS == 0u)
    {
        dmaWasEnabled = TRUE;

        uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();

        IfxScuWdt_clearCpuEndinit(passwd);

        MODULE_DMA.CLC.B.DISR = 1u;

        IfxScuWdt_setCpuEndinit(passwd);
    }
    else
    {
        /* Do nothing. */
    }
    /* MBIST Tests and evaluation */
    boolean nBistError = TRUE;
    /*
     * iLLD: &mbistGang3Config from mbistGangConfig is commented (disable) by default but
     * as this device has EMEM, therefore it is enabled in iLLD (IfxMtu_cfg.c).
     * */
    nBistError = IfxMtu_runMbistAll(mbistGangConfig);
    /* check if there was any error */
    if (nBistError == FALSE)
    {
        g_SafetyKitStatus.sswStatus.mbistStatus = passed;
    }
    else
    {
        g_SafetyKitStatus.sswStatus.mbistStatus = failed;
    }
    /* Clear all ECCD and FAULTSTS registers of the tested memory */
    safetyKitClearMbistSshRegisters();
    /* Enable DMA module again if it got disabled before */
    if(dmaWasEnabled)
    {
        uint16 passwd = IfxScuWdt_getCpuWatchdogPassword();

        IfxScuWdt_clearCpuEndinit(passwd);

        MODULE_DMA.CLC.B.DISR = 0u;

        IfxScuWdt_setCpuEndinit(passwd);
    }
    else
                    {
                        /* Do nothing. */
                    }
    /* Enable CPU caches */
    IfxCpu_setDataCache    (1u);
    IfxCpu_setProgramCache (1u);
    /* Enable all other CPUs, but not the one which is executing the function (of course it is also not disabled) */
    if(coreIndex != IfxCpu_ResourceCpu_0){
        IfxCpu_setCoreMode(&MODULE_CPU0, IfxCpu_CoreMode_run);
    }
#if (IFXCPU_NUM_MODULES > 1u)
    if(coreIndex != IfxCpu_ResourceCpu_1){
        IfxCpu_setCoreMode(&MODULE_CPU1, IfxCpu_CoreMode_run);
    }
#endif
#if (IFXCPU_NUM_MODULES > 2u)
    if(coreIndex != IfxCpu_ResourceCpu_2){
        IfxCpu_setCoreMode(&MODULE_CPU2, IfxCpu_CoreMode_run);
    }
#endif
}
#endif /* SAFETYKIT_CFG_SSW_ENABLE_MBIST */
/*
 * Clear all ECCD and FAULTSTS registers of the memory on which MBIST was executed.
 * Algorithm is based on a combination of the two functions
 * boolean IfxMtu_runMbistAll(const IfxMtu_MbistConfig *const mbistConfig[]) and
 * void safetyKitFwCheckClearSSH(SafetyKitResetType resetType)
 * */
void safetyKitClearMbistSshRegisters(void)
{
    IfxMtu_MbistSel mbistSel;
    Ifx_MTU_MC *mc;
    sint32 count;
    uint16 password;
    unsigned int gangConfigCount = 0;

    while (mbistGangConfig[gangConfigCount] != (void *)0u)
    {
        for (count = 0u; count < mbistGangConfig[gangConfigCount]->numOfSshConfigurations; count++)
        {
            mbistSel = mbistGangConfig[gangConfigCount]->sshConfigurations[count].sshSel;

            mc = &MODULE_MTU.MC[mbistSel];

            /* Clear error flags of tested memory */
            mc->ECCD.U = 0x0u;

            password = IfxScuWdt_getSafetyWatchdogPassword();

            IfxScuWdt_clearSafetyEndinit(password);

            mc->FAULTSTS.U = 0x0u;

            IfxScuWdt_setSafetyEndinit(password);
        }

        gangConfigCount++;
    }
}
