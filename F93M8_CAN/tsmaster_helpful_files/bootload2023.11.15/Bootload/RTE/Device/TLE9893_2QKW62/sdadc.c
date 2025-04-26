/*
 ***********************************************************************************************************************
 *
 * Copyright (c) 2015, Infineon Technologies AG
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

#include "sdadc.h"

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

/** \brief Initialize all CW registers of the SDADC module
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 SDADC_init(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;
  
  /* Violation: Boolean within 'if' always evaluates to False [MISRA Rule 14.3]*/
  if (SDADC_GLOBCONF_EN == 1u)
  {
    SDADC->CFG0.reg = (uint32)SDADC_CFG0;
    SDADC->CFG1.reg = (uint32)SDADC_CFG1;
    SDADC->CMP0_CTRL.reg = (uint32)SDADC_CMP0_CTRL;
    SDADC->CMP1_CTRL.reg = (uint32)SDADC_CMP1_CTRL;
    SDADC->ALTSEL.reg = (uint32)SDADC_ALTSEL;
    SDADC->INSEL.reg = (uint32)SDADC_INSEL;
    SDADC->DITHCFG.reg = (uint32)SDADC_DITHCFG;
  }
  else
  {
    s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;
  }
  
  return s8_returnCode;
}

/*******************************************************************************
**                       Deprecated Function Definitions                      **
*******************************************************************************/

void SDADC_setCh0ResIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void SDADC_setCh0CmpUpIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void SDADC_setCh0CmpLoIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void SDADC_setCh1ResIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void SDADC_setCh1CmpUpIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void SDADC_setCh1CmpLoIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}
