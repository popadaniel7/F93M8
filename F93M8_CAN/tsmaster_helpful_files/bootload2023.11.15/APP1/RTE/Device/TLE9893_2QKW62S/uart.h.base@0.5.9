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
 * \file     uart.h
 *
 * \brief    UART low level access library
 *
 * \version  V0.5.9
 * \date     23. Jun 2022
 *
 * \note
 */

/** \addtogroup UART_api
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
** V0.3.0: 2020-05-22, BG:   Added first functions                            **
** V0.4.0: 2020-07-10, BG:   Added inline functions list                      **
** V0.4.1: 2020-09-16, BG:   Added interrupt enable/disable functions         **
** V0.4.2: 2020-10-06, BG:   EP-492: Removed MISRA 2012 errors                **
** V0.4.3: 2020-10-16, JO:   EP-523: Updated parameter names                  **
** V0.4.4: 2020-10-21, BG:   EP-539: Considered the enable checkbox in CW in  **
**                           the initialization function                      **
** V0.4.5: 2020-11-12, JO:   EP-590: Removed \param none and \return none to  **
**                           avoid doxygen warning                            **
**                           Added end of group for doxygen                   **
** V0.4.6: 2020-11-20, BG:   EP-610: Corrected MISRA 2012 errors              **
**                           The following rules are globally deactivated:    **
**                           - Info 774: Boolean within 'if' always evaluates **
**                             to False/True                                  **
** V0.4.7: 2020-12-10, BG:   EP-622: Updated setTXBuffer functions            **
** V0.4.8: 2020-12-18, BG:   EP-652: Corrected name of error code variable    **
** V0.4.9: 2021-01-19, BG:   EP-660: Corrected UARTx_setTXBuffer              **
**                           Added functions to enable/disable baudrate       **
**                           generator                                        **
**                           Corrected initialization to set the bit BR_R     **
**                           separately                                       **
** V0.5.0: 2021-04-06, BG:   EP-760: Replaced if instructions to check if the **
**                           module is enabled with preprocessor directives to**
**                           avoid compiler warnings                          **
** V0.5.1: 2021-04-23, EE:   EP-676: Added stdout_putchar function to put     **
**                           a character to stdout                            **
** V0.5.2: 2021-06-02, BG:   EP-833: Added if conditions for the functions    **
**                           related to STDIN/STDOUT                          **
** V0.5.3: 2021-06-16, BG:   EP-839: Added stdin_getchar()                    **
** V0.5.4: 2021-07-21, BG:   EP-872: Corrected functions to set a user-defined**
**                           baudrate: UART{0/1}_setBaudrate(u32_baudrate)    **
** V0.5.5: 2021-07-30, BG:   EP-877: Corrected MISRA 2012 errors              **
** V0.5.6: 2021-10-19, JO:   EP-810: Updated init functions for unit testing  **
** V0.5.7: 2021-10-20, JO:   EP-966: Corrected functions UARTx_getBaudrate    **
** V0.5.8: 2021-11-12, JO:   EP-937: Updated copyright and branding           **
** V0.5.9: 2022-06-23, JO:   EP-1150: Removed ARMCC V6.18 warnings            **
*******************************************************************************/

#ifndef _UART_H
#define _UART_H

/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/

#include "types.h"
#include "tle989x.h"
#include "tle_variants.h"
#include "uart_defines.h"
#include "scu_defines.h"
#include "isr_defines.h"

/*******************************************************************************
**                        Global Constant Declarations                        **
*******************************************************************************/

/*******************************************************************************
**                          Global Type Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                          Global Macro Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                        Global Function Declarations                        **
*******************************************************************************/

sint8 UART0_init(void);
sint8 UART1_init(void);
uint32 UART0_getBaudrate(void);
uint32 UART1_getBaudrate(void);
sint8 UART0_setBaudrate(uint32 u32_baudrate);
sint8 UART1_setBaudrate(uint32 u32_baudrate);
#if ((UART0_STD_EN == 1) || (UART1_STD_EN == 1))
  sint32 stdout_putchar(sint32 character);
  sint32 stdin_getchar(void);
#endif
INLINE uint16 UART0_getRXbuffer(void);
INLINE void UART0_setTXbuffer(uint16 u16_value);
INLINE uint16 UART1_getRXbuffer(void);
INLINE void UART1_setTXbuffer(uint16 u16_value);
INLINE bool UART0_isByteReceived(void);
INLINE bool UART0_isByteTransmitted(void);
INLINE bool UART1_isByteReceived(void);
INLINE bool UART1_isByteTransmitted(void);
INLINE void UART0_enBaudrateGen(void);
INLINE void UART0_disBaudrateGen(void);
INLINE void UART1_enBaudrateGen(void);
INLINE void UART1_disBaudrateGen(void);
INLINE void UART0_startTX(void);
INLINE void UART1_startTX(void);
INLINE void UART0_enTXInt(void);
INLINE void UART0_enRXErrInt(void);
INLINE void UART0_enSyncErrInt(void);
INLINE void UART0_enEOSInt(void);
INLINE void UART0_disTXInt(void);
INLINE void UART0_disRXErrInt(void);
INLINE void UART0_disSyncErrInt(void);
INLINE void UART0_disEOSInt(void);
INLINE void UART1_enTXInt(void);
INLINE void UART1_enRXErrInt(void);
INLINE void UART1_enSyncErrInt(void);
INLINE void UART1_enEOSInt(void);
INLINE void UART1_disTXInt(void);
INLINE void UART1_disRXErrInt(void);
INLINE void UART1_disSyncErrInt(void);
INLINE void UART1_disEOSInt(void);
INLINE uint8 UART0_getTXIntSts(void);
INLINE uint8 UART0_getRXIntSts(void);
INLINE uint8 UART0_getSyncErrIntSts(void);
INLINE uint8 UART0_getEOFIntSts(void);
INLINE void UART0_clrTXIntSts(void);
INLINE void UART0_clrRXIntSts(void);
INLINE void UART0_clrSyncErrIntSts(void);
INLINE void UART0_clrEOFIntSts(void);
INLINE uint8 UART1_getTXIntSts(void);
INLINE uint8 UART1_getRXIntSts(void);
INLINE uint8 UART1_getSyncErrIntSts(void);
INLINE uint8 UART1_getEOFIntSts(void);
INLINE void UART1_clrTXIntSts(void);
INLINE void UART1_clrRXIntSts(void);
INLINE void UART1_clrSyncErrIntSts(void);
INLINE void UART1_clrEOFIntSts(void);

/*******************************************************************************
**                       Deprecated Function Declarations                     **
*******************************************************************************/

/** \brief Set UART0 TX Interrupt Node Pointer
 * \warning Do not change this at runtime, use the ConfigWizard to configure this feature!
 */
void UART0_setTXIntSts(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));

/** \brief Set UART0 RX Interrupt Node Pointer
 * \warning Do not change this at runtime, use the ConfigWizard to configure this feature!
 */
void UART0_setRXIntSts(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));

/** \brief Set UART0 Sync Error Interrupt Node Pointer
 * \warning Do not change this at runtime, use the ConfigWizard to configure this feature!
 */
void UART0_setSyncErrIntSts(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));

/** \brief Set UART0 End Of Sync Interrupt Node Pointer
 * \warning Do not change this at runtime, use the ConfigWizard to configure this feature!
 */
void UART0_setEOFIntSts(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));

/** \brief Set UART1 TX Interrupt Node Pointer
 * \warning Do not change this at runtime, use the ConfigWizard to configure this feature!
 */
void UART1_setTXIntSts(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));

/** \brief Set UART1 RX Interrupt Node Pointer
 * \warning Do not change this at runtime, use the ConfigWizard to configure this feature!
 */
void UART1_setRXIntSts(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));

/** \brief Set UART1 Sync Error Interrupt Node Pointer
 * \warning Do not change this at runtime, use the ConfigWizard to configure this feature!
 */
void UART1_setSyncErrIntSts(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));

/** \brief Set UART1 End Of Sync Interrupt Node Pointer
 * \warning Do not change this at runtime, use the ConfigWizard to configure this feature!
 */
void UART1_setEOFIntSts(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));

/*******************************************************************************
**                     Global Inline Function Definitions                     **
*******************************************************************************/

/** \brief Get the UART0 RX buffer value
 *
 * \return uint16 UART0 RX buffer
*/
INLINE uint16 UART0_getRXbuffer(void)
{
  UART0_clrRXIntSts();
  return (uint16)(UART0->RXBUF.reg);
}

/** \brief Set the UART0 TX buffer value
 *
 * \param u16_value UART0 TX buffer
*/
INLINE void UART0_setTXbuffer(uint16 u16_value)
{
  UART0_clrTXIntSts();
  UART0->TXBUF.reg = u16_value;
}

/** \brief Get the UART1 RX buffer value
 *
 * \return uint16 UART1 RX buffer
*/
INLINE uint16 UART1_getRXbuffer(void)
{
  UART1_clrRXIntSts();
  return (uint16)(UART1->RXBUF.reg);
}

/** \brief Set the UART1 TX buffer value
 *
 * \param u16_value UART1 TX buffer
*/
INLINE void UART1_setTXbuffer(uint16 u16_value)
{
  UART1_clrTXIntSts();
  UART1->TXBUF.reg = u16_value;
}

/** \brief Check if UART0 has received a byte
 *
 * \return true, a byte was received OR false, a byte was not received
*/
INLINE bool UART0_isByteReceived(void)
{
  bool result = false;

  if (UART0_getRXIntSts() == 1u)
  {
    result = true;
  }

  return result;
}

/** \brief Check if UART0 has transmitted a byte
 *
 * \return true, a byte was transmitted OR false, a byte was not transmitted
*/
INLINE bool UART0_isByteTransmitted(void)
{
  bool result = false;

  if (UART0_getTXIntSts() == 1u)
  {
    result = true;
  }

  return result;
}

/** \brief Check if UART1 has received a byte
 *
 * \return true, a byte was received OR false, a byte was not received
*/
INLINE bool UART1_isByteReceived(void)
{
  bool result = false;

  if (UART1_getRXIntSts() == 1u)
  {
    result = true;
  }

  return result;
}

/** \brief Check if UART1 has transmitted a byte
 *
 * \return true, a byte was transmitted OR false, a byte was not transmitted
*/
INLINE bool UART1_isByteTransmitted(void)
{
  bool result = false;

  if (UART1_getTXIntSts() == 1u)
  {
    result = true;
  }

  return result;
}

/** \brief Enable the baudrate generator, UART0.BCON.BR_R
 */
INLINE void UART0_enBaudrateGen(void)
{
  UART0->BCON.bit.BR_R = 1u;
}

/** \brief Disable the baudrate generator, UART0.BCON.BR_R
 */
INLINE void UART0_disBaudrateGen(void)
{
  UART0->BCON.bit.BR_R = 0u;
}

/** \brief Enable the baudrate generator, UART1.BCON.BR_R
 */
INLINE void UART1_enBaudrateGen(void)
{
  UART1->BCON.bit.BR_R = 1u;
}

/** \brief Disable the baudrate generator, UART1.BCON.BR_R
 */
INLINE void UART1_disBaudrateGen(void)
{
  UART1->BCON.bit.BR_R = 0u;
}

/** \brief Start the transmission, UART0.TSTART.TXSTART
 */
INLINE void UART0_startTX(void)
{
  UART0->TSTART.bit.TXSTART = 1u;
}

/** \brief Start the transmission, UART1.TSTART.TXSTART
 */
INLINE void UART1_startTX(void)
{
  UART1->TSTART.bit.TXSTART = 1u;
}

/** \brief Enable UART0 Transmit Interrupt
 */
INLINE void UART0_enTXInt(void)
{
  UART0->IEN.bit.TIEN = 1u;
}

/** \brief Enable UART0 Receive Interrupt
 */
INLINE void UART0_enRXErrInt(void)
{
  UART0->IEN.bit.RIEN = 1u;
}

/** \brief Enable UART0 Sync Error Interrupt
 */
INLINE void UART0_enSyncErrInt(void)
{
  UART0->IEN.bit.ERRSYNEN = 1u;
}

/** \brief Enable UART0 End of Sync Interrupt
 */
INLINE void UART0_enEOSInt(void)
{
  UART0->IEN.bit.EOFSYNEN = 1u;
}

/** \brief Disable UART0 Transmit Interrupt
 */
INLINE void UART0_disTXInt(void)
{
  UART0->IEN.bit.TIEN = 0u;
}

/** \brief Disable UART0 Receive Interrupt
 */
INLINE void UART0_disRXErrInt(void)
{
  UART0->IEN.bit.RIEN = 0u;
}

/** \brief Disable UART0 Sync Error Interrupt
 */
INLINE void UART0_disSyncErrInt(void)
{
  UART0->IEN.bit.ERRSYNEN = 0u;
}

/** \brief Disable UART0 End of Sync Interrupt
 */
INLINE void UART0_disEOSInt(void)
{
  UART0->IEN.bit.EOFSYNEN = 0u;
}

/** \brief Enable UART1 Transmit Interrupt
 */
INLINE void UART1_enTXInt(void)
{
  UART1->IEN.bit.TIEN = 1u;
}

/** \brief Enable UART1 Receive Interrupt
 */
INLINE void UART1_enRXErrInt(void)
{
  UART1->IEN.bit.RIEN = 1u;
}

/** \brief Enable UART1 Sync Error Interrupt
 */
INLINE void UART1_enSyncErrInt(void)
{
  UART1->IEN.bit.ERRSYNEN = 1u;
}

/** \brief Enable UART1 End of Sync Interrupt
 */
INLINE void UART1_enEOSInt(void)
{
  UART1->IEN.bit.EOFSYNEN = 1u;
}

/** \brief Disable UART1 Transmit Interrupt
 */
INLINE void UART1_disTXInt(void)
{
  UART1->IEN.bit.TIEN = 0u;
}

/** \brief Disable UART1 Receive Interrupt
 */
INLINE void UART1_disRXErrInt(void)
{
  UART1->IEN.bit.RIEN = 0u;
}

/** \brief Disable UART1 Sync Error Interrupt
 */
INLINE void UART1_disSyncErrInt(void)
{
  UART1->IEN.bit.ERRSYNEN = 0u;
}

/** \brief Disable UART1 End of Sync Interrupt
 */
INLINE void UART1_disEOSInt(void)
{
  UART1->IEN.bit.EOFSYNEN = 0u;
}

/** \brief Get the UART0 Empty Transmit Buffer Interrupt Status, UART0.IS.TI
 *
 * \return uint8 Empty Transmit Buffer Interrupt Status, UART0.IS.TI
 */
INLINE uint8 UART0_getTXIntSts(void)
{
  return (uint8)UART0->IS.bit.TI;
}

/** \brief Get the UART0 Empty Receive Buffer Interrupt Status, UART0.IS.RI
 *
 * \return uint8 Empty Receive Buffer Interrupt Status, UART0.IS.RI
 */
INLINE uint8 UART0_getRXIntSts(void)
{
  return (uint8)UART0->IS.bit.RI;
}

/** \brief Get the UART0 Sync Error Interrupt Status, UART0.IS.ERRSYN
 *
 * \return uint8 Sync Error Interrupt Status, UART0.IS.ERRSYN
 */
INLINE uint8 UART0_getSyncErrIntSts(void)
{
  return (uint8)UART0->IS.bit.ERRSYN;
}

/** \brief Get the UART0 End of Sync Interrupt Status, UART0.IS.EOFSYN
 *
 * \return uint8 End of Sync Interrupt Status, UART0.IS.EOFSYN
 */
INLINE uint8 UART0_getEOFIntSts(void)
{
  return (uint8)UART0->IS.bit.EOFSYN;
}

/** \brief Clear the UART0 Empty Transmit Buffer Interrupt Status, UART0.ISC.TICLR
 */
INLINE void UART0_clrTXIntSts(void)
{
  UART0->ISC.bit.TICLR = 1u;
}

/** \brief Clear the UART0 Empty Receive Buffer Interrupt Status, UART0.ISC.RICLR
 */
INLINE void UART0_clrRXIntSts(void)
{
  UART0->ISC.bit.RICLR = 1u;
}

/** \brief Clear the UART0 Sync Error Interrupt Status, UART0.ISC.ERRSYNCLR
 */
INLINE void UART0_clrSyncErrIntSts(void)
{
  UART0->ISC.bit.ERRSYNCLR = 1u;
}

/** \brief Clear the UART0 End of Sync Interrupt Status, UART0.ISC.EOFSYNCLR
 */
INLINE void UART0_clrEOFIntSts(void)
{
  UART0->ISC.bit.EOFSYNCLR = 1u;
}

/** \brief Get the UART1 Empty Transmit Buffer Interrupt Status, UART1.IS.TI
 *
 * \return uint8 Empty Transmit Buffer Interrupt Status, UART1.IS.TI
 */
INLINE uint8 UART1_getTXIntSts(void)
{
  return (uint8)UART1->IS.bit.TI;
}

/** \brief Get the UART1 Empty Receive Buffer Interrupt Status, UART1.IS.RI
 *
 * \return uint8 Empty Receive Buffer Interrupt Status, UART1.IS.RI
 */
INLINE uint8 UART1_getRXIntSts(void)
{
  return (uint8)UART1->IS.bit.RI;
}

/** \brief Get the UART1 Sync Error Interrupt Status, UART1.IS.ERRSYN
 *
 * \return uint8 Sync Error Interrupt Status, UART1.IS.ERRSYN
 */
INLINE uint8 UART1_getSyncErrIntSts(void)
{
  return (uint8)UART1->IS.bit.ERRSYN;
}

/** \brief Get the UART1 End of Sync Interrupt Status, UART1.IS.EOFSYN
 *
 * \return uint8 End of Sync Interrupt Status, UART1.IS.EOFSYN
 */
INLINE uint8 UART1_getEOFIntSts(void)
{
  return (uint8)UART1->IS.bit.EOFSYN;
}

/** \brief Clear the UART1 Empty Transmit Buffer Interrupt Status, UART1.ISC.TICLR
 */
INLINE void UART1_clrTXIntSts(void)
{
  UART1->ISC.bit.TICLR = 1u;
}

/** \brief Clear the UART1 Empty Receive Buffer Interrupt Status, UART1.ISC.RICLR
 */
INLINE void UART1_clrRXIntSts(void)
{
  UART1->ISC.bit.RICLR = 1u;
}

/** \brief Clear the UART1 Sync Error Interrupt Status, UART1.ISC.ERRSYNCLR
 */
INLINE void UART1_clrSyncErrIntSts(void)
{
  UART1->ISC.bit.ERRSYNCLR = 1u;
}

/** \brief Clear the UART1 End of Sync Interrupt Status, UART1.ISC.EOFSYNCLR
 */
INLINE void UART1_clrEOFIntSts(void)
{
  UART1->ISC.bit.EOFSYNCLR = 1u;
}

/** @}*/

#endif /* _UART_H */
