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
 * \file     dma.h
 *
 * \brief    Direct Memory Access low level access library
 *
 * \version  V0.3.1
 * \date     23. Jun 2022
 *
 * \note
 */

/*******************************************************************************
**                             Author(s) Identity                             **
********************************************************************************
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** BG           Blandine Guillot                                              **
** JO           Julia Ott                                                     **
*******************************************************************************/

/*******************************************************************************
**                          Revision Control History                          **
********************************************************************************
** V0.1.0: 2021-03-03, BG:   Initial version                                  **
** V0.2.0: 2021-06-08, BG:   EP-685: Replaced UC_RAM_SIZE with UC_DSRAM_SIZE  **
** V0.2.1: 2021-06-14, BG:   EP-685: Added functions for the endless mode     **
** V0.2.2: 2021-06-21, BG:   EP-685: Updated init function with return code   **
** V0.2.3: 2021-07-30, BG:   EP-877: Corrected MISRA 2012 errors              **
** V0.2.4: 2021-08-11, BG:   EP-905: Added missing scu_defines.h              **
** V0.2.5: 2021-08-16, JO:   EP-860: Added variable u32p_DMA_entriesForTest   **
**                           for unit testing                                 **
** V0.2.6: 2021-09-07, BG:   EP-922: Added support for ARMCC V5               **
** V0.2.7: 2021-11-12, JO:   EP-937: Updated copyright and branding           **
** V0.2.8: 2022-04-27, JO:   EP-1139: Corrected doxygen errors/warnings       **
** V0.2.9: 2022-06-22, JO:   EP-1146: Added initialization of SCU->DMACTRL    **
**                           and DMA->DMA_CFG.bit.MASTER_ENABLE               **
** V0.3.0: 2022-06-23, JO:   EP-1157: Added function DMA_setSWReq             **
** V0.3.1: 2022-06-23, JO:   EP-1150: Removed ARMCC V6.18 warnings            **
*******************************************************************************/

#ifndef _DMA_H
#define _DMA_H

/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/

#include "types.h"
#include "tle989x.h"
#include "tle_variants.h"
#include "dma_defines.h"

/*******************************************************************************
**                        Global Constant Declarations                        **
*******************************************************************************/

/*******************************************************************************
**                          Global Type Declarations                          **
*******************************************************************************/

/** \enum tDMA_transferSize
 *  \brief This enum lists the transfer size options for the DMA
 */
typedef enum DMA_transferSize
{
  DMA_transferSize_8bit   = 0u,        /**< DMA transfer size 8 bit  */
  DMA_transferSize_16bit  = 1u,        /**< DMA transfer size 16 bit */
  DMA_transferSize_32bit  = 2u         /**< DMA transfer size 32 bit */
} tDMA_transferSize;

/** \enum tDMA_incrementSize
 *  \brief This enum lists the increment size options for the DMA
 */
typedef enum DMA_incrementSize
{
  DMA_incrementSize_8bit   = 0u,       /**< DMA increment size 8 bit  */
  DMA_incrementSize_16bit  = 1u,       /**< DMA increment size 16 bit */
  DMA_incrementSize_32bit  = 2u        /**< DMA increment size 32 bit */
} tDMA_incrementSize;

/** \enum tDMA_incrementMode
 *  \brief This enum lists the increment mode options for the DMA
 */
typedef enum DMA_incrementMode
{
  DMA_incrementMode_srcInc      = 0u, /**< DMA increment mode, Source Address Increment */
  DMA_incrementMode_dstInc      = 1u, /**< DMA increment mode, Destination Address Increment */
  DMA_incrementMode_srcDstInc   = 2u, /**< DMA increment mode, Source and Destination Address Increment */
  DMA_incrementMode_noInc       = 3u  /**< DMA increment mode, No Increment */
} tDMA_incrementMode;

/** \enum tDMA_cycleType
 *  \brief This enum lists the cycle type options for the DMA
 */
typedef enum DMA_cycleType
{
  DMA_cycleType_Invalid       = 0u,    /**< DMA cycle types, Invalid Mode */
  DMA_cycleType_Basic         = 1u,    /**< DMA cycle types, Basic Mode */
  DMA_cycleType_Auto          = 2u,    /**< DMA cycle types, Auto-request Mode */
  DMA_cycleType_PingPong      = 3u,    /**< DMA cycle types, PingPong Mode */
  DMA_cycleType_MemSctGthPrim = 4u,    /**< DMA cycle types, Memory scatter/gather Primary Mode */
  DMA_cycleType_MemSctGthAlt  = 5u,    /**< DMA cycle types, Memory scatter/gather Alternate Mode */
  DMA_cycleType_PerSctGthPrim = 6u,    /**< DMA cycle types, Peripheral scatter/gather Primary Mode */
  DMA_cycleType_PerSctGthAlt  = 7u     /**< DMA cycle types, Peripheral scatter/gather Alternate Mode */
} tDMA_cycleType;

/** \union tDMA_ctrl
 *  \brief This union and its structure lists the bit assignments for the channel_cfg memory location.
 */
typedef union
{
  uint32  reg;
  struct
  {
    uint32 u32_cycleCtrl: 3;           /**< \brief Bit[2..0] */
    uint32 u32_nextUseburst: 1;        /**< \brief Bit[3] */
    uint32 u32_Nminus1: 10;            /**< \brief Bit[13..4] */
    uint32 u32_Rpower: 4;              /**< \brief Bit[17..14] */
    uint32 u32_srcProtCtrl: 3;         /**< \brief Bit[20..18] */
    uint32 u32_dstProtCtrl: 3;         /**< \brief Bit[23..21] */
    uint32 u32_srcSize: 2;             /**< \brief Bit[25..24] */
    uint32 u32_srcInc: 2;              /**< \brief Bit[27..26] */
    uint32 u32_dstSize: 2;             /**< \brief Bit[29..28] */
    uint32 u32_dstInc: 2;              /**< \brief Bit[31..30] */
  } bit;
} tDMA_ctrl;

/** \struct tDMA_entry
 *  \brief This structure lists the DMA transfer memory locations.
 */
typedef struct DMA_entry
{
  uint32 u32_srcEndPtr;
  uint32 u32_dstEndPtr;
  tDMA_ctrl s_ctrl;
  uint32 reserved;
} tDMA_entry;

/*******************************************************************************
**                          Global Macro Declarations                         **
*******************************************************************************/

/**\brief DMA channel selection macro, DMA CH0 */
#define DMA_CH0                       (0u)
/**\brief DMA channel selection macro, DMA CH1 */
#define DMA_CH1                       (1u)
/**\brief DMA channel selection macro, DMA CH2 */
#define DMA_CH2                       (2u)
/**\brief DMA channel selection macro, DMA CH3 */
#define DMA_CH3                       (3u)
/**\brief DMA channel selection macro, DMA CH4 */
#define DMA_CH4                       (4u)
/**\brief DMA channel selection macro, DMA CH5 */
#define DMA_CH5                       (5u)
/**\brief DMA channel selection macro, DMA CH6 */
#define DMA_CH6                       (6u)
/**\brief DMA channel selection macro, DMA CH7 */
#define DMA_CH7                       (7u)

/**\brief DMA channel Mask macro, DMA CH0 MASK */
#define DMA_MASK_CH0                  ((uint16)1u << DMA_CH0)
/**\brief DMA channel Mask macro, DMA CH1 MASK */
#define DMA_MASK_CH1                  ((uint16)1u << DMA_CH1)
/**\brief DMA channel Mask macro, DMA CH2 MASK */
#define DMA_MASK_CH2                  ((uint16)1u << DMA_CH2)
/**\brief DMA channel Mask macro, DMA CH3 MASK */
#define DMA_MASK_CH3                  ((uint16)1u << DMA_CH3)
/**\brief DMA channel Mask macro, DMA CH4 MASK */
#define DMA_MASK_CH4                  ((uint16)1u << DMA_CH4)
/**\brief DMA channel Mask macro, DMA CH5 MASK */
#define DMA_MASK_CH5                  ((uint16)1u << DMA_CH5)
/**\brief DMA channel Mask macro, DMA CH6 MASK */
#define DMA_MASK_CH6                  ((uint16)1u << DMA_CH6)
/**\brief DMA channel Mask macro, DMA CH7 MASK */
#define DMA_MASK_CH7                  ((uint16)1u << DMA_CH7)


/*******************************************************************************
**                        Global Function Declarations                        **
*******************************************************************************/

sint8 DMA_init(void);
void DMA_setBasicTransfer(uint8 u8_chIdx, uint32 u32_srcAddr, uint32 u32_dstAddr, uint32 u32_transferCnt, tDMA_transferSize e_transferSize, tDMA_incrementMode e_incrementMode);
void DMA_resetChannel(uint8 u8_chIdx, uint32 u32_transferCnt);
void DMA_setMemSctGth(uint8 u8_chIdx, tDMA_entry *s_taskList, uint32 u32_taskCnt);
void DMA_setPerSctGth(uint8 u8_chIdx, tDMA_entry *s_taskList, uint32 u32_taskCnt);
tDMA_entry *DMA_setPrimaryTaskSctGth(tDMA_entry *s_primEntry, uint8 u8_chIdx, tDMA_entry *s_taskList, uint32 u32_taskCnt);
tDMA_entry *DMA_setTaskSctGth(tDMA_entry *s_entry, tDMA_cycleType e_cycleType, uint8 u8_Rpower, uint32 u32_srcAddr, uint32 u32_dstAddr, uint32 u32_transferCnt, tDMA_transferSize e_transferSize, tDMA_incrementMode e_incrementMode);
INLINE void DMA_enMaster(void);
INLINE void DMA_enCh0EndlessMode(void);
INLINE void DMA_disCh0EndlessMode(void);
INLINE void DMA_enCh1EndlessMode(void);
INLINE void DMA_disCh1EndlessMode(void);
INLINE void DMA_enCh2EndlessMode(void);
INLINE void DMA_disCh2EndlessMode(void);
INLINE void DMA_enCh3EndlessMode(void);
INLINE void DMA_disCh3EndlessMode(void);
INLINE void DMA_enCh4EndlessMode(void);
INLINE void DMA_disCh4EndlessMode(void);
INLINE void DMA_enCh5EndlessMode(void);
INLINE void DMA_disCh5EndlessMode(void);
INLINE void DMA_enCh6EndlessMode(void);
INLINE void DMA_disCh6EndlessMode(void);
INLINE void DMA_enCh7EndlessMode(void);
INLINE void DMA_disCh7EndlessMode(void);
INLINE void DMA_enCh0Int(void);
INLINE void DMA_disCh0Int(void);
INLINE void DMA_enCh1Int(void);
INLINE void DMA_disCh1Int(void);
INLINE void DMA_enCh2Int(void);
INLINE void DMA_disCh2Int(void);
INLINE void DMA_enCh3Int(void);
INLINE void DMA_disCh3Int(void);
INLINE void DMA_enCh4Int(void);
INLINE void DMA_disCh4Int(void);
INLINE void DMA_enCh5Int(void);
INLINE void DMA_disCh5Int(void);
INLINE void DMA_enCh6Int(void);
INLINE void DMA_disCh6Int(void);
INLINE void DMA_enCh7Int(void);
INLINE void DMA_disCh7Int(void);
INLINE void DMA_enErrInt(void);
INLINE void DMA_disErrInt(void);
INLINE uint8 DMA_getCh0IntSts(void);
INLINE uint8 DMA_getCh1IntSts(void);
INLINE uint8 DMA_getCh2IntSts(void);
INLINE uint8 DMA_getCh3IntSts(void);
INLINE uint8 DMA_getCh4IntSts(void);
INLINE uint8 DMA_getCh5IntSts(void);
INLINE uint8 DMA_getCh6IntSts(void);
INLINE uint8 DMA_getCh7IntSts(void);
INLINE void DMA_clrCh0IntSts(void);
INLINE void DMA_clrCh1IntSts(void);
INLINE void DMA_clrCh2IntSts(void);
INLINE void DMA_clrCh3IntSts(void);
INLINE void DMA_clrCh4IntSts(void);
INLINE void DMA_clrCh5IntSts(void);
INLINE void DMA_clrCh6IntSts(void);
INLINE void DMA_clrCh7IntSts(void);
INLINE void DMA_setSWReq(uint8 u8_chIdx);

/*******************************************************************************
**                       Deprecated Function Declarations                     **
*******************************************************************************/

/** \brief Set Channel 0 Interrupt Node Pointer
 * \warning Do not change this at runtime, use the ConfigWizard to configure this feature!
 */
void DMA_setCh0IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));

/** \brief Set Channel 1 Interrupt Node Pointer
 * \warning Do not change this at runtime, use the ConfigWizard to configure this feature!
 */
void DMA_setCh1IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));

/** \brief Set Channel 2 Interrupt Node Pointer
 * \warning Do not change this at runtime, use the ConfigWizard to configure this feature!
 */
void DMA_setCh2IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));

/** \brief Set Channel 3 Interrupt Node Pointer
 * \warning Do not change this at runtime, use the ConfigWizard to configure this feature!
 */
void DMA_setCh3IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));

/** \brief Set Channel 4 Interrupt Node Pointer
 * \warning Do not change this at runtime, use the ConfigWizard to configure this feature!
 */
void DMA_setCh4IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));

/** \brief Set Channel 5 Interrupt Node Pointer
 * \warning Do not change this at runtime, use the ConfigWizard to configure this feature!
 */
void DMA_setCh5IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));

/** \brief Set Channel 6 Interrupt Node Pointer
 * \warning Do not change this at runtime, use the ConfigWizard to configure this feature!
 */
void DMA_setCh6IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));

/** \brief Set Channel 7 Interrupt Node Pointer
 * \warning Do not change this at runtime, use the ConfigWizard to configure this feature!
 */
void DMA_setCh7IntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));

/** \brief Set Channel Bus Error Interrupt Node Pointer
 * \warning Do not change this at runtime, use the ConfigWizard to configure this feature!
 */
void DMA_setErrIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));

/*******************************************************************************
**                     Global Inline Function Definitions                     **
*******************************************************************************/

/** \brief Enable DMA Master
 */
INLINE void DMA_enMaster(void)
{
  DMA->DMA_CFG.bit.MASTER_ENABLE = 1u;
}

/** \brief Enable DMA Channel 0 Endless Mode
 */
INLINE void DMA_enCh0EndlessMode(void)
{
  SCU->DMACTRL.bit.DEMEN_CH0 = 1u;
}

/** \brief Disable DMA Channel 0 Endless Mode
 */
INLINE void DMA_disCh0EndlessMode(void)
{
  SCU->DMACTRL.bit.DEMEN_CH0 = 0u;
}

/** \brief Enable DMA Channel 1 Endless Mode
 */
INLINE void DMA_enCh1EndlessMode(void)
{
  SCU->DMACTRL.bit.DEMEN_CH1 = 1u;
}

/** \brief Disable DMA Channel 1 Endless Mode
 */
INLINE void DMA_disCh1EndlessMode(void)
{
  SCU->DMACTRL.bit.DEMEN_CH1 = 0u;
}

/** \brief Enable DMA Channel 2 Endless Mode
 */
INLINE void DMA_enCh2EndlessMode(void)
{
  SCU->DMACTRL.bit.DEMEN_CH2 = 1u;
}

/** \brief Disable DMA Channel 2 Endless Mode
 */
INLINE void DMA_disCh2EndlessMode(void)
{
  SCU->DMACTRL.bit.DEMEN_CH2 = 0u;
}

/** \brief Enable DMA Channel 3 Endless Mode
 */
INLINE void DMA_enCh3EndlessMode(void)
{
  SCU->DMACTRL.bit.DEMEN_CH3 = 1u;
}

/** \brief Disable DMA Channel 3 Endless Mode
 */
INLINE void DMA_disCh3EndlessMode(void)
{
  SCU->DMACTRL.bit.DEMEN_CH3 = 0u;
}

/** \brief Enable DMA Channel 4 Endless Mode
 */
INLINE void DMA_enCh4EndlessMode(void)
{
  SCU->DMACTRL.bit.DEMEN_CH4 = 1u;
}

/** \brief Disable DMA Channel 4 Endless Mode
 */
INLINE void DMA_disCh4EndlessMode(void)
{
  SCU->DMACTRL.bit.DEMEN_CH4 = 0u;
}

/** \brief Enable DMA Channel 5 Endless Mode
 */
INLINE void DMA_enCh5EndlessMode(void)
{
  SCU->DMACTRL.bit.DEMEN_CH5 = 1u;
}

/** \brief Disable DMA Channel 5 Endless Mode
 */
INLINE void DMA_disCh5EndlessMode(void)
{
  SCU->DMACTRL.bit.DEMEN_CH5 = 0u;
}

/** \brief Enable DMA Channel 6 Endless Mode
 */
INLINE void DMA_enCh6EndlessMode(void)
{
  SCU->DMACTRL.bit.DEMEN_CH6 = 1u;
}

/** \brief Disable DMA Channel 6 Endless Mode
 */
INLINE void DMA_disCh6EndlessMode(void)
{
  SCU->DMACTRL.bit.DEMEN_CH6 = 0u;
}

/** \brief Enable DMA Channel 7 Endless Mode
 */
INLINE void DMA_enCh7EndlessMode(void)
{
  SCU->DMACTRL.bit.DEMEN_CH7 = 1u;
}

/** \brief Disable DMA Channel 7 Endless Mode
 */
INLINE void DMA_disCh7EndlessMode(void)
{
  SCU->DMACTRL.bit.DEMEN_CH7 = 0u;
}

/** \brief Enable DMA Channel 0 Interrupt
 */
INLINE void DMA_enCh0Int(void)
{
  SCU->DMAIEN.bit.DMACH0EN = 1u;
}

/** \brief Disable DMA Channel 0 Interrupt
 */
INLINE void DMA_disCh0Int(void)
{
  SCU->DMAIEN.bit.DMACH0EN = 0u;
}

/** \brief Enable DMA Channel 1 Interrupt
 */
INLINE void DMA_enCh1Int(void)
{
  SCU->DMAIEN.bit.DMACH1EN = 1u;
}

/** \brief Disable DMA Channel 1 Interrupt
 */
INLINE void DMA_disCh1Int(void)
{
  SCU->DMAIEN.bit.DMACH1EN = 0u;
}

/** \brief Enable DMA Channel 2 Interrupt
 */
INLINE void DMA_enCh2Int(void)
{
  SCU->DMAIEN.bit.DMACH2EN = 1u;
}

/** \brief Disable DMA Channel 2 Interrupt
 */
INLINE void DMA_disCh2Int(void)
{
  SCU->DMAIEN.bit.DMACH2EN = 0u;
}

/** \brief Enable DMA Channel 3 Interrupt
 */
INLINE void DMA_enCh3Int(void)
{
  SCU->DMAIEN.bit.DMACH3EN = 1u;
}

/** \brief Disable DMA Channel 3 Interrupt
 */
INLINE void DMA_disCh3Int(void)
{
  SCU->DMAIEN.bit.DMACH3EN = 0u;
}

/** \brief Enable DMA Channel 4 Interrupt
 */
INLINE void DMA_enCh4Int(void)
{
  SCU->DMAIEN.bit.DMACH4EN = 1u;
}

/** \brief Disable DMA Channel 4 Interrupt
 */
INLINE void DMA_disCh4Int(void)
{
  SCU->DMAIEN.bit.DMACH4EN = 0u;
}

/** \brief Enable DMA Channel 5 Interrupt
 */
INLINE void DMA_enCh5Int(void)
{
  SCU->DMAIEN.bit.DMACH5EN = 1u;
}

/** \brief Disable DMA Channel 5 Interrupt
 */
INLINE void DMA_disCh5Int(void)
{
  SCU->DMAIEN.bit.DMACH5EN = 0u;
}

/** \brief Enable DMA Channel 6 Interrupt
 */
INLINE void DMA_enCh6Int(void)
{
  SCU->DMAIEN.bit.DMACH6EN = 1u;
}

/** \brief Disable DMA Channel 6 Interrupt
 */
INLINE void DMA_disCh6Int(void)
{
  SCU->DMAIEN.bit.DMACH6EN = 0u;
}

/** \brief Enable DMA Channel 7 Interrupt
 */
INLINE void DMA_enCh7Int(void)
{
  SCU->DMAIEN.bit.DMACH7EN = 1u;
}

/** \brief Disable DMA Channel 7 Interrupt
 */
INLINE void DMA_disCh7Int(void)
{
  SCU->DMAIEN.bit.DMACH7EN = 0u;
}

/** \brief Enable DMA Transfer Error Interrupt
 */
INLINE void DMA_enErrInt(void)
{
  SCU->DMAIEN.bit.DMATRERREN = 1u;
}

/** \brief Disable DMA Transfer Error Interrupt
 */
INLINE void DMA_disErrInt(void)
{
  SCU->DMAIEN.bit.DMATRERREN = 0u;
}

/** \brief Get DMA Channel 0 Interrupt Status
 *
 * \return uint8 DMA Channel 0 Interrupt Status
 */
INLINE uint8 DMA_getCh0IntSts(void)
{
  return (uint8)SCU->DMAIS.bit.DMACH0;
}

/** \brief Get DMA Channel 1 Interrupt Status
 *
 * \return uint8 DMA Channel 1 Interrupt Status
 */
INLINE uint8 DMA_getCh1IntSts(void)
{
  return (uint8)SCU->DMAIS.bit.DMACH1;
}

/** \brief Get DMA Channel 2 Interrupt Status
 *
 * \return uint8 DMA Channel 2 Interrupt Status
 */
INLINE uint8 DMA_getCh2IntSts(void)
{
  return (uint8)SCU->DMAIS.bit.DMACH2;
}

/** \brief Get DMA Channel 3 Interrupt Status
 *
 * \return uint8 DMA Channel 3 Interrupt Status
 */
INLINE uint8 DMA_getCh3IntSts(void)
{
  return (uint8)SCU->DMAIS.bit.DMACH3;
}

/** \brief Get DMA Channel 4 Interrupt Status
 *
 * \return uint8 DMA Channel 4 Interrupt Status
 */
INLINE uint8 DMA_getCh4IntSts(void)
{
  return (uint8)SCU->DMAIS.bit.DMACH4;
}

/** \brief Get DMA Channel 5 Interrupt Status
 *
 * \return uint8 DMA Channel 5 Interrupt Status
 */
INLINE uint8 DMA_getCh5IntSts(void)
{
  return (uint8)SCU->DMAIS.bit.DMACH5;
}

/** \brief Get DMA Channel 6 Interrupt Status
 *
 * \return uint8 DMA Channel 6 Interrupt Status
 */
INLINE uint8 DMA_getCh6IntSts(void)
{
  return (uint8)SCU->DMAIS.bit.DMACH6;
}

/** \brief Get DMA Channel 7 Interrupt Status
 *
 * \return uint8 DMA Channel 7 Interrupt Status
 */
INLINE uint8 DMA_getCh7IntSts(void)
{
  return (uint8)SCU->DMAIS.bit.DMACH7;
}

/** \brief Clear DMA Channel 0 Interrupt Status
 */
INLINE void DMA_clrCh0IntSts(void)
{
  SCU->DMAISC.bit.DMACH0CLR = 1u;
}

/** \brief Clear DMA Channel 1 Interrupt Status
 */
INLINE void DMA_clrCh1IntSts(void)
{
  SCU->DMAISC.bit.DMACH1CLR = 1u;
}

/** \brief Clear DMA Channel 2 Interrupt Status
 */
INLINE void DMA_clrCh2IntSts(void)
{
  SCU->DMAISC.bit.DMACH2CLR = 1u;
}

/** \brief Clear DMA Channel 3 Interrupt Status
 */
INLINE void DMA_clrCh3IntSts(void)
{
  SCU->DMAISC.bit.DMACH3CLR = 1u;
}

/** \brief Clear DMA Channel 4 Interrupt Status
 */
INLINE void DMA_clrCh4IntSts(void)
{
  SCU->DMAISC.bit.DMACH4CLR = 1u;
}

/** \brief Clear DMA Channel 5 Interrupt Status
 */
INLINE void DMA_clrCh5IntSts(void)
{
  SCU->DMAISC.bit.DMACH5CLR = 1u;
}

/** \brief Clear DMA Channel 6 Interrupt Status
 */
INLINE void DMA_clrCh6IntSts(void)
{
  SCU->DMAISC.bit.DMACH6CLR = 1u;
}

/** \brief Clear DMA Channel 7 Interrupt Status
 */
INLINE void DMA_clrCh7IntSts(void)
{
  SCU->DMAISC.bit.DMACH7CLR = 1u;
}
/** \brief Sets the SW request for the given channel
 *
 * \param u8_chIdx DMA channel number, recommended to use the defines DMA_CHx
 */
INLINE void DMA_setSWReq(uint8 u8_chIdx)
{
  DMA->CHNL_SW_REQUEST.reg = (uint32)((uint32)1u << u8_chIdx);
}

#endif /* _DMA_H */
