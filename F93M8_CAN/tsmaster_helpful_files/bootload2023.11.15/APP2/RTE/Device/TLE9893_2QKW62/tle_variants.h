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
 * \file     tle_variants.h
 *
 * \brief    Device specific memory layout defines and features
 *
 * \version  V0.4.3
 * \date     12. Nov 2021
 *
 * \note
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
** V0.2.0: 2020-08-11, JO:   Added devices TLE9881_2QTW60, TLE9883_2QTW62S,   **
**                           TLE9883QTA62, TLE9891QTA61, TLE9891_2QTW60,      **
**                           TLE9891_2QTW61, TLE9893QTW62, TLE9893QKW62S,     **
**                           TLE9893_2QTA62, TLE9893_2QKW62, TLE9893_2QTW62S, **
**                           TLE9893_2QTA62S, TLE9893_2QKW62S                 **
** V0.3.0: 2020-08-17, BG:   Removed unnecessary series definitions           **
** V0.3.1: 2020-11-12, JO:   EP-587: Added UC_FEATURE_48PIN/UC_FEATURE_64PIN  **
** V0.3.2: 2020-11-27, BG:   EP-610: Corrected MISRA 2012 errors              **
** V0.3.3: 2021-03-17, BG:   EP-746: Removed unofficial devices               **
** V0.4.0: 2021-04-21, JO:   EP-776: Updated memory defines, values           **
**                           UC_FLASH0_UBSL_SIZE, UC_FLASH0_UDATA_START,      **
**                           UC_FLASH0_UDATA_SIZE can be accessed by          **
**                           including tle_device.h, updated function         **
**                           PtrRangeCheck to updated memory defines          **
** V0.4.1: 2021-04-29, JO:   EP-789: Corrected UC_SERIES for TLE988x          **
** V0.4.2: 2021-07-30, BG:   EP-877: Included header file for TLE988x         **
** V0.4.3: 2021-11-12, JO:   EP-937: Updated copyright and branding           **
*******************************************************************************/

#ifndef _TLE_VARIANTS_H
#define _TLE_VARIANTS_H

/* Family definitions  */
#define TLE98      (98)

/* Series definitions  */
#define TLE988     (988)
#define TLE989     (989)

/* Device definitions  */
#define TLE9881    (9881)
#define TLE9883    (9883)
#define TLE9887    (9887)
#define TLE9889    (9889)
#define TLE9891    (9891)
#define TLE9893    (9893)
#define TLE9897    (9897)
#define TLE9899    (9899)

/* Package definitions */
#define BGA144     (1)
#define LQFP144    (2)
#define LQFP100    (3)
#define BGA64      (4)
#define LQFP64     (5)
#define VQFN48     (6)
#define TSSOP38    (7)
#define TSSOP28    (8)
#define TSSOP16    (9)
#define VQFN24     (10)
#define VQFN40     (11)
#define TQFP48     (12)

/* TLE988x/TLE989x devices */
/* supported features:  */
/* UC_FEATURE_CRYPTO_LIB */
/* UC_FEATURE_DATAFLASH */
/* UC_FEATURE_SDADC */
/* UC_FEATURE_48PIN or UC_FEATURE_64PIN */

/* TLE988x devices */
/* TLE9881_2QTW60:  48pin, 16K RAM, 120K Flash1 (no Crypto-Lib), 32K Flash0 (0...28k Data Flash in Flash0), CAN2.0, SDADC */
#if defined(TLE9881_2QTW60)
  #define UC_FAMILY       TLE98
  #define UC_SERIES       TLE988
  #define UC_DEVICE       TLE9893
  #define UC_PACKAGE      TQFP48
  /* RAM */
  /* UC_PSRAM_START, UC_PSRAM_SIZE, UC_DSRAM_START are identical for all devices */
  #define UC_DSRAM_SIZE        (0x2000U)
  /* Flash */
  #define UC_FLASH0_SIZE       (0x8000U)
  #define UC_FLASH1_SIZE       (0x1E000U)  
  /* Features */
  #define UC_FEATURE_DATAFLASH
  #define UC_FEATURE_SDADC
  #define UC_FEATURE_48PIN

  /* TLE9883_2QTW62S: 48pin, 31K RAM, 248K Flash1 (8K Crypto-Lib in Flash1), 32K Flash0 (0...28k Data Flash in Flash0), CAN FD, SDADC */
#elif defined(TLE9883_2QTW62S)
  #define UC_FAMILY       TLE98
  #define UC_SERIES       TLE988
  #define UC_DEVICE       TLE9893
  #define UC_PACKAGE      TQFP48
  /* RAM */
  /* UC_PSRAM_START, UC_PSRAM_SIZE, UC_DSRAM_START are identical for all devices */
  #define UC_DSRAM_SIZE        (0x5C00U)
  /* Flash */
  #define UC_FLASH0_SIZE       (0x8000U)
  #define UC_FLASH1_SIZE       (0x3E000U)  
  /* Features */
  #define UC_FEATURE_CRYPTO_LIB
  #define UC_FEATURE_DATAFLASH
  #define UC_FEATURE_SDADC
  #define UC_FEATURE_48PIN

  /* TLE9883QTA62: 48pin, 31K RAM, 248K Flash1 (no Crypto-Lib), 32K Flash0 (0...28k Data Flash in Flash0), CAN FD, No SDADC */
#elif defined(TLE9883QTA62)
  #define UC_FAMILY       TLE98
  #define UC_SERIES       TLE988
  #define UC_DEVICE       TLE9893
  #define UC_PACKAGE      TQFP48
  /* RAM */
  /* UC_PSRAM_START, UC_PSRAM_SIZE, UC_DSRAM_START are identical for all devices */
  #define UC_DSRAM_SIZE        (0x5C00U)
  /* Flash */
  #define UC_FLASH0_SIZE       (0x8000U)
  #define UC_FLASH1_SIZE       (0x3E000U)  
  /* Features */
  #define UC_FEATURE_DATAFLASH
  #define UC_FEATURE_48PIN

  /* TLE989x devices */
  /* TLE9891QTA61: 48pin, 16K RAM, 120K Flash1 (no Crypto-Lib), 32K Flash0 (0...28k Data Flash in Flash0), CAN2.0, No SDADC */
#elif defined(TLE9891QTA61)
  #define UC_FAMILY       TLE98
  #define UC_SERIES       TLE989
  #define UC_DEVICE       TLE9893
  #define UC_PACKAGE      TQFP48
  /* RAM */
  /* UC_PSRAM_START, UC_PSRAM_SIZE, UC_DSRAM_START are identical for all devices */
  #define UC_DSRAM_SIZE        (0x2000U)
  /* Flash */
  #define UC_FLASH0_SIZE       (0x8000U)
  #define UC_FLASH1_SIZE       (0x1E000U)  
  /* Features */
  #define UC_FEATURE_DATAFLASH
  #define UC_FEATURE_48PIN

  /* TLE9891_2QTW60: 48pin, 16K RAM, 120K Flash1 (no Crypto-Lib), 32K Flash0 (0...28k Data Flash in Flash0), CAN2.0, SDADC */
#elif defined(TLE9891_2QTW60)
  #define UC_FAMILY       TLE98
  #define UC_SERIES       TLE989
  #define UC_DEVICE       TLE9893
  #define UC_PACKAGE      TQFP48
  /* RAM */
  /* UC_PSRAM_START, UC_PSRAM_SIZE, UC_DSRAM_START are identical for all devices */
  #define UC_DSRAM_SIZE        (0x2000U)
  /* Flash */
  #define UC_FLASH0_SIZE       (0x8000U)
  #define UC_FLASH1_SIZE       (0x1E000U)  
  /* Features */
  #define UC_FEATURE_DATAFLASH
  #define UC_FEATURE_SDADC
  #define UC_FEATURE_48PIN

  /* TLE9891_2QTW61: 48pin, 16K RAM, 120K Flash1 (no Crypto-Lib), 32K Flash0 (0...28k Data Flash in Flash0), CAN2.0, SDADC */
#elif defined(TLE9891_2QTW61)
  #define UC_FAMILY       TLE98
  #define UC_SERIES       TLE989
  #define UC_DEVICE       TLE9893
  #define UC_PACKAGE      TQFP48
  /* RAM */
  /* UC_PSRAM_START, UC_PSRAM_SIZE, UC_DSRAM_START are identical for all devices */
  #define UC_DSRAM_SIZE        (0x2000U)
  /* Flash */
  #define UC_FLASH0_SIZE       (0x8000U)
  #define UC_FLASH1_SIZE       (0x1E000U)  
  /* Features */
  #define UC_FEATURE_DATAFLASH
  #define UC_FEATURE_SDADC
  #define UC_FEATURE_48PIN

  /* TLE9893QKW62S: 64pin, 31K RAM, 248K Flash1 (8K Crypto-Lib in Flash1), 32K Flash0 (0...28k Data Flash in Flash0), CAN FD, No SDADC */
#elif defined(TLE9893QKW62S)
  #define UC_FAMILY       TLE98
  #define UC_SERIES       TLE989
  #define UC_DEVICE       TLE9893
  #define UC_PACKAGE      LQFP64
  /* RAM */
  /* UC_PSRAM_START, UC_PSRAM_SIZE, UC_DSRAM_START are identical for all devices */
  #define UC_DSRAM_SIZE        (0x5C00U)
  /* Flash */
  #define UC_FLASH0_SIZE       (0x8000U)
  #define UC_FLASH1_SIZE       (0x3E000U)  
  /* Features */
  #define UC_FEATURE_CRYPTO_LIB
  #define UC_FEATURE_DATAFLASH
  #define UC_FEATURE_64PIN

  /* TLE9893_2QTA62: 48pin, 31K RAM, 248K Flash1 (no Crypto-Lib), 32K Flash0 (0...28k Data Flash in Flash0), CAN FD, SDADC */
#elif defined(TLE9893_2QTA62)
  #define UC_FAMILY       TLE98
  #define UC_SERIES       TLE989
  #define UC_DEVICE       TLE9893
  #define UC_PACKAGE      TQFP48
  /* RAM */
  /* UC_PSRAM_START, UC_PSRAM_SIZE, UC_DSRAM_START are identical for all devices */
  #define UC_DSRAM_SIZE        (0x5C00U)
  /* Flash */
  #define UC_FLASH0_SIZE       (0x8000U)
  #define UC_FLASH1_SIZE       (0x3E000U)  
  /* Features */
  #define UC_FEATURE_DATAFLASH
  #define UC_FEATURE_SDADC
  #define UC_FEATURE_48PIN

  /* TLE9893_2QTW62S: 48pin, 31K RAM, 248K Flash1 (8K Crypto-Lib in Flash1), 32K Flash0 (0...28k Data Flash in Flash0), CAN FD, SDADC */
#elif defined(TLE9893_2QTW62S)
  #define UC_FAMILY       TLE98
  #define UC_SERIES       TLE989
  #define UC_DEVICE       TLE9893
  #define UC_PACKAGE      TQFP48
  /* RAM */
  /* UC_PSRAM_START, UC_PSRAM_SIZE, UC_DSRAM_START are identical for all devices */
  #define UC_DSRAM_SIZE        (0x5C00U)
  /* Flash */
  #define UC_FLASH0_SIZE       (0x8000U)
  #define UC_FLASH1_SIZE       (0x3E000U)  
  /* Features */
  #define UC_FEATURE_CRYPTO_LIB
  #define UC_FEATURE_DATAFLASH
  #define UC_FEATURE_SDADC
  #define UC_FEATURE_48PIN

  /* TLE9893_2QTA62S: 48pin, 31K RAM, 248K Flash1 (8K Crypto-Lib in Flash1), 32K Flash0 (0...28k Data Flash in Flash0), CAN FD, SDADC */
#elif defined(TLE9893_2QTA62S)
  #define UC_FAMILY       TLE98
  #define UC_SERIES       TLE989
  #define UC_DEVICE       TLE9893
  #define UC_PACKAGE      TQFP48
  /* RAM */
  /* UC_PSRAM_START, UC_PSRAM_SIZE, UC_DSRAM_START are identical for all devices */
  #define UC_DSRAM_SIZE        (0x5C00U)
  /* Flash */
  #define UC_FLASH0_SIZE       (0x8000U)
  #define UC_FLASH1_SIZE       (0x3E000U)  
  /* Features */
  #define UC_FEATURE_CRYPTO_LIB
  #define UC_FEATURE_DATAFLASH
  #define UC_FEATURE_SDADC
  #define UC_FEATURE_48PIN

  /* TLE9893_2QKW62S: 64pin, 31K RAM, 248K Flash1 (8K Crypto-Lib in Flash1), 32K Flash0 (0...28k Data Flash in Flash0), CAN FD, SDADC */
#elif defined(TLE9893_2QKW62S)
  #define UC_FAMILY       TLE98
  #define UC_SERIES       TLE989
  #define UC_DEVICE       TLE9893
  #define UC_PACKAGE      LQFP64
  /* RAM */
  /* UC_PSRAM_START, UC_PSRAM_SIZE, UC_DSRAM_START are identical for all devices */
  #define UC_DSRAM_SIZE        (0x5C00U)
  /* Flash */
  #define UC_FLASH0_SIZE       (0x8000U)
  #define UC_FLASH1_SIZE       (0x3E000U)  
  /* Features */
  #define UC_FEATURE_CRYPTO_LIB
  #define UC_FEATURE_DATAFLASH
  #define UC_FEATURE_SDADC
  #define UC_FEATURE_64PIN

  /* TLE9893_2QKW62S_internal: 64pin, 31K RAM, 248K Flash1 (8K Crypto-Lib in Flash1), 32K Flash0 (0...28k Data Flash in Flash0), CAN FD, SDADC */
#elif defined(TLE9893_2QKW62S_internal)
  #define UC_FAMILY       TLE98
  #define UC_SERIES       TLE989
  #define UC_DEVICE       TLE9893
  #define UC_PACKAGE      LQFP64
  /* RAM */
  /* UC_PSRAM_START, UC_PSRAM_SIZE, UC_DSRAM_START are identical for all devices */
  #define UC_DSRAM_SIZE        (0x5C00U)
  /* Flash */
  #define UC_FLASH0_SIZE       (0x8000U)
  #define UC_FLASH1_SIZE       (0x3E000U)  
  /* Features */
  #define UC_FEATURE_CRYPTO_LIB
  #define UC_FEATURE_DATAFLASH
  #define UC_FEATURE_SDADC
  #define UC_FEATURE_64PIN

#else
  #error "tle_device.h: device not supported"
#endif

/* Define Memory - common for all TLE988x/9x devices */
/* RAM */
#define UC_PSRAM_START        (0x18000000U)
#define UC_PSRAM_SIZE         (0x2000U)
#define UC_DSRAM_START        (0x18002000U)
/* Flash */
#define UC_FLASH_PAGE_SIZE    (128U)
#define UC_FLASH_SECTOR_SIZE  (0x1000U)
#define UC_FLASH0_START       (0x11000000U)
#define UC_FLASH0_UBSL_START  (UC_FLASH0_START)
#define UC_FLASH1_START       (0x12002000U)
/* UC_FLASH0_UBSL_SIZE, UC_FLASH0_UDATA_START, UC_FLASH0_UDATA_SIZE depend on UBSL size setting */

/*******************************************************************************
**                   Definition of first page in FLASH0                       **
*******************************************************************************/
#define UC_SNAC_START   ".ARM.__at_0x11000000"


#if (UC_SERIES == 988)
  #include "tle989x.h"
#elif (UC_SERIES == 989)
  #include "tle989x.h"
#endif
#include "types.h"

INLINE bool PtrRangeCheck(const void *ptr)
{
  bool b_res;
  b_res = false;

  /* check is input pointer resides inside the RAM */
  if ((((uint32)ptr >= UC_PSRAM_START) && ((uint32)ptr < (UC_PSRAM_START + UC_PSRAM_SIZE))) || (((uint32)ptr >= UC_DSRAM_START) && ((uint32)ptr < (UC_DSRAM_START + UC_DSRAM_SIZE))))
  {
    b_res = true;
  }

  return (b_res);
}
#endif
