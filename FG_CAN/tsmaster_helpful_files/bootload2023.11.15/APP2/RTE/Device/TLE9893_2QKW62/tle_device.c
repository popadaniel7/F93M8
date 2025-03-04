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

#include "tle_device.h"

/*******************************************************************************
**                        Private Constant Declarations                       **
*******************************************************************************/

/*******************************************************************************
**                         Private Macro Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                         Global Variable Definitions                        **
*******************************************************************************/
uint32 UC_FLASH0_UBSL_SIZE;
uint32 UC_FLASH0_UDATA_START;
uint32 UC_FLASH0_UDATA_SIZE;

/*******************************************************************************
**                        Private Function Declarations                       **
*******************************************************************************/

/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

/** \brief Initialize all modules of the device
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 TLE_init(void)
{
  uint8 u8_ubslSizeSectors;
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  #ifdef RTE_DEVICE_TLELIB_SCU
    SCU_init();
  #endif
  #ifdef RTE_DEVICE_TLELIB_PMU
    s8_returnCode |= PMU_init();
  #endif
  #ifdef RTE_DEVICE_TLELIB_ADC1
    s8_returnCode |= ADC1_init();
  #endif
  #ifdef RTE_DEVICE_TLELIB_ADC2
    s8_returnCode |= ADC2_init();
  #endif
  #ifdef RTE_DEVICE_TLELIB_BDRV
    s8_returnCode |= BDRV_initCP();
  #endif
  #ifdef RTE_DEVICE_TLELIB_CSACSC
    s8_returnCode |= CSACSC_init();
  #endif
  #ifdef RTE_DEVICE_TLELIB_BDRV
    s8_returnCode |= BDRV_init();
  #endif
  #ifdef RTE_DEVICE_TLELIB_CCU7
    s8_returnCode |= CCU7_init();
  #endif
  #ifdef RTE_DEVICE_TLELIB_CANTRX
    s8_returnCode |= CANTRX_init();
  #endif
  #ifdef RTE_DEVICE_TLELIB_DMA
    s8_returnCode |= DMA_init();
  #endif
  #ifdef RTE_DEVICE_TLELIB_GPIO
    GPIO_init();
  #endif
  #ifdef RTE_DEVICE_TLELIB_GPT12
    s8_returnCode |= GPT12_init();
  #endif
  #ifdef RTE_DEVICE_TLELIB_MON
    MON_init();
  #endif
  #ifdef RTE_DEVICE_TLELIB_SDADC
    s8_returnCode |= SDADC_init();
  #endif
  #ifdef RTE_DEVICE_TLELIB_SSC
    s8_returnCode |= SSC0_init();
    s8_returnCode |= SSC1_init();
  #endif
  #ifdef RTE_DEVICE_TLELIB_TIMER2X
    s8_returnCode |= T20_init();
    s8_returnCode |= T21_init();
  #endif
  #ifdef RTE_DEVICE_TLELIB_UART
    s8_returnCode |= UART0_init();
    s8_returnCode |= UART1_init();
  #endif
  #ifdef RTE_DEVICE_TLELIB_INT
    INT_init();
  #endif
  
  /* Initialize variables for memory map that can be configured */
  u8_ubslSizeSectors = (uint8) (MEMCTRL->NVM_PROT_STS.bit.UBSL_SIZE + 1);
  UC_FLASH0_UBSL_SIZE = (uint32) (u8_ubslSizeSectors) * UC_FLASH_SECTOR_SIZE;
  UC_FLASH0_UDATA_START = UC_FLASH0_UBSL_START + UC_FLASH0_UBSL_SIZE;
  UC_FLASH0_UDATA_SIZE = UC_FLASH0_SIZE - UC_FLASH0_UBSL_SIZE;
  
  return s8_returnCode;
}
