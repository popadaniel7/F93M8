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
#include "uart.h"
#include "pmu.h"
#if ((UART0_STD_EN == 1) || (UART1_STD_EN == 1))
  /* Define __STRICT_ANSI__ for compatibility with ARMCC v5 compiler */
  #ifndef __STRICT_ANSI__
    #define __STRICT_ANSI__
  #endif
  #include <stdio.h>
#endif


/*******************************************************************************
**                        Private Constant Declarations                       **
*******************************************************************************/

/*******************************************************************************
**                          Private Type Declarations                          **
*******************************************************************************/

typedef union UARTx_BCON
{
  uint32_t reg;                         /*!< (@ 0x00000024) Baud Rate Control Register */
    
  struct {
    uint32_t BR_R       : 1;            /*!< [0..0] Baud Rate Generator Enable Bit     */
    uint32_t            : 3;
    uint32_t BR_PRE     : 3;            /*!< [6..4] Prescaler Bit                      */
    uint32_t            : 9;
    uint32_t BG_FD_SEL  : 5;            /*!< [20..16] Fractional Divider Selection     */
    uint32_t BG_BR_VALUE : 11;          /*!< [31..21] Baud Rate Reload Value           */
  } bit;
} tUARTx_BCON;

/*******************************************************************************
**                         Private Macro Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                        Private Variable Definitions                        **
*******************************************************************************/

#if ((UART0_STD_EN == 1) || (UART1_STD_EN == 1))
  #if defined (__CC_ARM) || defined (__ARMCC_VERSION)
    FILE __stdout;
    FILE __stdin;
  #endif
#endif

/*******************************************************************************
**                        Private Function Declarations                       **
*******************************************************************************/

sint8 UARTx_setBaudrate(uint32 u32_baudrate, volatile tUARTx_BCON *tp_baudrateReg);

/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

/** \brief Initialize UART0
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 UART0_init(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;
  
  #if (UART0_GLOBCONF_EN == 1u)
    s8_returnCode = ERR_LOG_SUCCESS;
  
    UART0->INSEL.reg = (uint32)UART0_INSEL;
    UART0->SCON.reg = (uint32)UART0_SCON;
    UART0->IEN.reg = (uint32)UART0_IEN;
    UART0->BCON.reg = (uint32)UART0_BCON & ~UART0_BCON_BR_R_Msk;
    /* In case of variable baudrate, the generator must be enabled --> Write UARTx->SCON.bit.SM1 to UARTx->BCON.bit.BR_R */
    UART0->BCON.bit.BR_R = UART0->SCON.bit.SM1;
  #endif
  
  return s8_returnCode;
}


/** \brief Initialize UART1
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 UART1_init(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;

  #if (UART1_GLOBCONF_EN == 1u)
    s8_returnCode = ERR_LOG_SUCCESS;
  
    UART1->INSEL.reg = (uint32)UART1_INSEL;
    UART1->SCON.reg = (uint32)UART1_SCON;
    UART1->IEN.reg = (uint32)UART1_IEN;
    UART1->BCON.reg = (uint32)UART1_BCON & ~UART1_BCON_BR_R_Msk;
    /* In case of variable baudrate, the generator must be enabled --> Write UARTx->SCON.bit.SM1 to UARTx->BCON.bit.BR_R */
    UART1->BCON.bit.BR_R = UART1->SCON.bit.SM1;
    
  #endif
  
  return s8_returnCode;
}

/** \brief Get the baudrate for UART0
 * Transform equation
 *   (SCU_fUART_MHz * 1000000 / (16 * (1U << (uint8)UART0->BCON.bit.BR_PRE) * (UART0->BCON.bit.BG_BR_VALUE + (UART0->BCON.bit.BG_FD_SEL / 32))))
 * to
 *   ((SCU_fUART_MHz * 1000000 * 2 )  / ((1U << (uint8)UART0->BCON.bit.BR_PRE) * (32 * UART0->BCON.bit.BG_BR_VALUE + (UART0->BCON.bit.BG_FD_SEL))))
 *
 * \return uint32 UART0 baudrate
 */
uint32 UART0_getBaudrate(void)
{
  return (uint32)((SCU_fUART_MHz * 1000000 * 2 )  / ((1U << (uint8)UART0->BCON.bit.BR_PRE) * (32 * UART0->BCON.bit.BG_BR_VALUE + (UART0->BCON.bit.BG_FD_SEL))));
}


/** \brief Get the baudrate for UART1
 * Transform equation
 *   (SCU_fUART_MHz * 1000000 / (16 * (1U << (uint8)UART1->BCON.bit.BR_PRE) * (UART1->BCON.bit.BG_BR_VALUE + (UART1->BCON.bit.BG_FD_SEL / 32))))
 * to
 *   ((SCU_fUART_MHz * 1000000 * 2 )  / ((1U << (uint8)UART1->BCON.bit.BR_PRE) * (32 * UART1->BCON.bit.BG_BR_VALUE + (UART1->BCON.bit.BG_FD_SEL))))
 *
 * \return uint32 UART1 baudrate
 */
uint32 UART1_getBaudrate(void)
{
  return (uint32)((SCU_fUART_MHz * 1000000 * 2 )  / ((1U << (uint8)UART1->BCON.bit.BR_PRE) * (32 * UART1->BCON.bit.BG_BR_VALUE + (UART1->BCON.bit.BG_FD_SEL))));
}


/** \brief Set the baudrate for UART0/UART1
 *  \brief The maximum allowed deviation is 2.5%. Otherwise return error code ERR_LOG_CODE_PARAM_OUT_OF_RANGE
 *
 * \param u32_baudrate baudrate
 * \param tp_baudrateReg baudrate pointer to baudrate configuration register
 * \return sint8 0: success, <0: error codes
 * \note The resulting SFR values might deviate from a configuration with the ConfigWizard or from User Manual examples. Some specific baudrates can be achieved with different SFR settings.
 */
sint8 UARTx_setBaudrate(uint32 u32_baudrate, volatile tUARTx_BCON *tp_baudrateReg)
{
  sint8 s8_returnCode;
  uint32 u32_maxBaudrate;
  
  uint8 i;
  uint8 u8_deviation;
  uint8 u8_flag;
  sint8 s8_pre;
  uint8 u8_prescaler;
  uint16 u16_reloadVal;
  uint32 u32_calcBR;
  uint32 u32_minBR;
  uint32 u32_maxBR;

  u32_maxBaudrate = 0;
  u8_deviation = 0u;
  u8_flag = 0u;
  s8_pre = (sint8)5;
  u8_prescaler = 32u;
  u16_reloadVal = 1u;

  s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
    
  u32_maxBaudrate = (uint32)(SCU_fUART_MHz * 1000000 / 16);

  /* Check range for baudrate */
  if ((u32_baudrate <= u32_maxBaudrate) && (u32_baudrate >= 2400u))
  {
    /* While loop on prescaler value to find the reload value/fractional divider */
    /* At each iteration the prescaler is divided by 2 */
    while (u8_prescaler > 0u && u8_deviation < 250)
    {
      /* According to UM, Baudrate = fUART / (16 * prescaler * (reloadVal + fracDiv/32)) */
      u16_reloadVal = (uint16)((uint32)SCU_fUART_MHz * 1000000u / (16u * u8_prescaler * u32_baudrate));
      /* The reload value is an 11-bit value, 0 sets the timer into Bypass mode -> valid values between 1 and 2047 */
      if ((u16_reloadVal <= 2047u) && (u16_reloadVal > 0u))
      {
        /* For-loop on the fractional divider, for given prescaler and reload values */
        for (i = 0; i <= 32; i++)
        {
          /* Calculated baudrate with the given prescaler, reload and fractional divider values */
          u32_calcBR = (SCU_fUART_MHz * 1000000u * 32u) / (16u * u8_prescaler * (32u * u16_reloadVal + i));
          /* Min and max baudrate values for the given deviation */
          u32_minBR = (uint32)(((uint64)u32_baudrate * (uint64)((uint64)10000u - (uint64)u8_deviation)) / 10000u);
          u32_maxBR = (uint32)(((uint64)u32_baudrate * (uint64)((uint64)10000u + (uint64)u8_deviation)) / 10000u);
          /* If the calculated baudrate is below the minimum possible baudrate, the for-loop on the fractional divider is interrupted */
          if (u32_calcBR < u32_minBR)
          {
            break;
          }
          else
          { 
            /* To meet the expected deviation, the calculated baudrate should be between a min and a max baudrate */
            if ((u32_calcBR >= u32_minBR) && (u32_calcBR <= u32_maxBR))
            {
              /* In that case parameters (prescaler, fractional dividers and reload value) are found that meet the given deviation */
              /* The for-loop is interrupted and the u8_flag is set to 1 (to stop the while-loop on line 243 */
              u8_flag = 1u;
              /* Disable baudrate generator */
              tp_baudrateReg->bit.BR_R = 0u;
              /* Set prescaler, fractional divider and reload value */
              tp_baudrateReg->bit.BR_PRE = (uint8)s8_pre;
              if (i == 32)
              {
                tp_baudrateReg->bit.BG_FD_SEL = 0u;
                tp_baudrateReg->bit.BG_BR_VALUE = u16_reloadVal + 1u;
              }
              else
              {
                tp_baudrateReg->bit.BG_FD_SEL = i;
                tp_baudrateReg->bit.BG_BR_VALUE = u16_reloadVal;
              }
              /* Enable baudrate generator */
              tp_baudrateReg->bit.BR_R = 1u;
              /* Set the return code to success */
              s8_returnCode = ERR_LOG_SUCCESS;
              break;
            }
          }
        }
        if (u8_flag == 0u)
        {
          /* At each iteration the prescaler is divided by 2 */
          u8_prescaler /= 2u;
          /* At each iteration the prescaler value is decremented by 1 */
          s8_pre -= (sint8)1;
          if (s8_pre < (sint8)0)
          {
            u8_deviation += 1u;
            /* Reinitialization of variables */
            s8_pre = (sint8)5;
            u8_prescaler = 32u;
            u16_reloadVal = 0u;
          }
        }
        else
        {
          break;
        }
      }
      else
      {
        /* At each iteration the prescaler is divided by 2 */
        u8_prescaler /= 2u;
        /* At each iteration the prescaler value is decremented by 1 */
        s8_pre -= (sint8)1;
      }
    }
  }

  return s8_returnCode;
}


/** \brief Set the baudrate for UART0
 *
 * \param u32_baudrate baudrate
 * \return sint8 0: success, <0: error codes
 */
sint8 UART0_setBaudrate(uint32 u32_baudrate)
{
  sint8 s8_returnCode;
  uint32 u32_addr;
  tUARTx_BCON *tp_baudrateReg;
  
  u32_addr = (uint32)&UART0->BCON.reg;
  tp_baudrateReg = (tUARTx_BCON *) u32_addr;
  
  s8_returnCode = UARTx_setBaudrate(u32_baudrate, tp_baudrateReg);

  return s8_returnCode;
}


/** \brief Set the baudrate for UART1
 *
 * \param u32_baudrate baudrate
 * \return sint8 0: success, <0: error codes
 */
sint8 UART1_setBaudrate(uint32 u32_baudrate)
{
  sint8 s8_returnCode;
  uint32 u32_addr;
  tUARTx_BCON *tp_baudrateReg;
  
  u32_addr = (uint32)&UART1->BCON.reg;
  tp_baudrateReg = (tUARTx_BCON *) u32_addr;
  
  s8_returnCode = UARTx_setBaudrate(u32_baudrate, tp_baudrateReg);

  return s8_returnCode;
}


#if ((UART0_STD_EN == 1) || (UART1_STD_EN == 1))
/** \brief Put a character to the stdout
 *
 * \param s32_character Character to output
 * \return The written character
 */
sint32 stdout_putchar(sint32 s32_character)
{
  if (UART0_GLOBCONF_EN == (1u) && (UART0_STD_EN == 1))
  {
    /* Fill buffer */
    UART0_setTXbuffer((uint16) s32_character);
    /* Handle line feed case */
    if (s32_character == (sint32)'\n')
    {
      (void)PMU_serviceFailSafeWatchdogSOW();
      /* Wait until new line is sent out */
      while (UART0_isByteTransmitted() == false)
      {
        /* Wait for byte to be transmitted */
      }
      (void)PMU_serviceFailSafeWatchdog();
      /* Fill buffer with carriage return */
      UART0_setTXbuffer((uint8) '\r');
    }
    /* Wait until character is sent out */
    while (UART0_isByteTransmitted() == false)
    {
      (void)PMU_serviceFailSafeWatchdog();
    }
  }
  else if (UART1_GLOBCONF_EN == (1u) && (UART1_STD_EN == 1))
  {
    /* Fill buffer */
    UART1_setTXbuffer((uint16) s32_character);
    /* Handle line feed case */
    if (s32_character == (sint32)'\n')
    {
      (void)PMU_serviceFailSafeWatchdogSOW();
      /* Wait until new line is sent out */
      while (UART1_isByteTransmitted() == false)
      {
        /* Wait for byte to be transmitted */
      }
      (void)PMU_serviceFailSafeWatchdog();
      /* Fill buffer with carriage return */
      UART1_setTXbuffer((uint8) '\r');
    }
    /* Wait until character is sent out */
    while (UART1_isByteTransmitted() == false)
    {
      (void)PMU_serviceFailSafeWatchdog();
    }
  }
  else
  {
  }

  return s32_character;
}

/** \brief Receive a character via stdin
 *
 * \return The written character
 */
sint32 stdin_getchar(void)
{
  sint32 s32_character = 0;
  
  if (UART0_GLOBCONF_EN == (1u) && (UART0_STD_EN == 1))
  {
    while (UART0_isByteReceived() == false)
    {
      /* Service the watchdog until the character is received */
      (void)PMU_serviceFailSafeWatchdog();
    }
    /* Clear RX interrupt status and get character */
    s32_character = (sint32)UART0_getRXbuffer();
  }
  else if (UART1_GLOBCONF_EN == (1u) && (UART1_STD_EN == 1))
  {
    while (UART1_isByteReceived() == false)
    {
      /* Service the watchdog until the character is received */
      (void)PMU_serviceFailSafeWatchdog();
    }
    /* Clear RX interrupt status and get character */
    s32_character = (sint32)UART1_getRXbuffer();
  }
  else
  {
  }
  
  return s32_character;
}

/** \brief  Write a character to a data stream
 */
int fputc(int ch, FILE *f __attribute__((unused))) 
{
  return stdout_putchar(ch);
}


/** \brief  Receive a character from a data stream
 */
int fgetc(FILE *f __attribute__((unused))) 
{
  return stdin_getchar();
}

#endif

#if ((UART0_STD_EN == 1) && (UART1_STD_EN == 1))
  #error Only one UART can be selected as STDIN/STDOUT device at a time
#endif

/*******************************************************************************
**                       Deprecated Function Definitions                      **
*******************************************************************************/

void UART0_setTXIntSts(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void UART0_setRXIntSts(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void UART0_setSyncErrIntSts(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void UART0_setEOFIntSts(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void UART1_setTXIntSts(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void UART1_setRXIntSts(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void UART1_setSyncErrIntSts(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void UART1_setEOFIntSts(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}
