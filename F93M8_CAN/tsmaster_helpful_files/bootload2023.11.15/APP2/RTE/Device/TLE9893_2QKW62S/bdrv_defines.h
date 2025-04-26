/**
 * @cond
 ***********************************************************************************************************************
 *
 * Copyright (c) 2018, Infineon Technologies AG
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
#ifndef BDRV_DEFINES_H
#define BDRV_DEFINES_H

/* XML Version 0.0.7 */
#define BDRV_XML_VERSION (00007)

#define BDRV_ASEQC (0x0u) /*decimal 0*/

#define BDRV_ASEQERRCNT (0x0u) /*decimal 0*/

#define BDRV_ASEQOFFADDDLY (0x1u) /*decimal 1*/

#define BDRV_ASEQOFFIMAX (0x0u) /*decimal 0*/

#define BDRV_ASEQOFFIMIN (0x0u) /*decimal 0*/

#define BDRV_ASEQOFFTMAX (0x0u) /*decimal 0*/

#define BDRV_ASEQOFFTMIN (0x0u) /*decimal 0*/

#define BDRV_ASEQONIMAX (0x0u) /*decimal 0*/

#define BDRV_ASEQONIMIN (0x0u) /*decimal 0*/

#define BDRV_ASEQONTMAX (0x0u) /*decimal 0*/

#define BDRV_ASEQONTMIN (0x0u) /*decimal 0*/

#define BDRV_BEMFC_CTRL (0x0u) /*decimal 0*/

#define BDRV_CP_CLK_CTRL (0x1401Fu) /*decimal 81951*/

#define BDRV_CP_CTRL (0x0u) /*decimal 0*/

#define BDRV_CTRL1 (0x0u) /*decimal 0*/

#define BDRV_CTRL2 (0x11000u) /*decimal 69632*/

#define BDRV_GLOBCONF_EN (0x1u) /*decimal 1*/

#define BDRV_HB1IGATECLMPC (0x404u) /*decimal 1028*/

#define BDRV_HB2IGATECLMPC (0x404u) /*decimal 1028*/

#define BDRV_HB3IGATECLMPC (0x404u) /*decimal 1028*/

#define BDRV_HCDIS (0x1003Fu) /*decimal 65599*/

#define BDRV_HS1AFIC (0x1717u) /*decimal 5911*/

#define BDRV_HS1AFTC (0x1414u) /*decimal 5140*/

#define BDRV_HS1SEQOFFIC (0x70720u) /*decimal 460576*/

#define BDRV_HS1SEQOFFTC (0x50506u) /*decimal 328966*/

#define BDRV_HS1SEQONIC (0x20070720u) /*decimal 537331488*/

#define BDRV_HS1SEQONTC (0x4050506u) /*decimal 67437830*/

#define BDRV_HS2AFIC (0x1717u) /*decimal 5911*/

#define BDRV_HS2AFTC (0x1414u) /*decimal 5140*/

#define BDRV_HS2SEQOFFIC (0x70720u) /*decimal 460576*/

#define BDRV_HS2SEQOFFTC (0x50506u) /*decimal 328966*/

#define BDRV_HS2SEQONIC (0x20070720u) /*decimal 537331488*/

#define BDRV_HS2SEQONTC (0x4050506u) /*decimal 67437830*/

#define BDRV_HS3AFIC (0x1717u) /*decimal 5911*/

#define BDRV_HS3AFTC (0x1414u) /*decimal 5140*/

#define BDRV_HS3SEQOFFIC (0x70720u) /*decimal 460576*/

#define BDRV_HS3SEQOFFTC (0x50506u) /*decimal 328966*/

#define BDRV_HS3SEQONIC (0x20070720u) /*decimal 537331488*/

#define BDRV_HS3SEQONTC (0x4050506u) /*decimal 67437830*/

#define BDRV_LS1AFIC (0x1717u) /*decimal 5911*/

#define BDRV_LS1AFTC (0x1414u) /*decimal 5140*/

#define BDRV_LS1SEQOFFIC (0x70720u) /*decimal 460576*/

#define BDRV_LS1SEQOFFTC (0x50506u) /*decimal 328966*/

#define BDRV_LS1SEQONIC (0x20070720u) /*decimal 537331488*/

#define BDRV_LS1SEQONTC (0x4050506u) /*decimal 67437830*/

#define BDRV_LS2AFIC (0x1717u) /*decimal 5911*/

#define BDRV_LS2AFTC (0x1414u) /*decimal 5140*/

#define BDRV_LS2SEQOFFIC (0x70720u) /*decimal 460576*/

#define BDRV_LS2SEQOFFTC (0x50506u) /*decimal 328966*/

#define BDRV_LS2SEQONIC (0x20070720u) /*decimal 537331488*/

#define BDRV_LS2SEQONTC (0x4050506u) /*decimal 67437830*/

#define BDRV_LS3AFIC (0x1717u) /*decimal 5911*/

#define BDRV_LS3AFTC (0x1414u) /*decimal 5140*/

#define BDRV_LS3SEQOFFIC (0x70720u) /*decimal 460576*/

#define BDRV_LS3SEQOFFTC (0x50506u) /*decimal 328966*/

#define BDRV_LS3SEQONIC (0x20070720u) /*decimal 537331488*/

#define BDRV_LS3SEQONTC (0x4050506u) /*decimal 67437830*/

#define BDRV_PROT_CTRL (0x1F000000u) /*decimal 520093696*/

#define BDRV_PWMSRCSEL (0x261504u) /*decimal 2495748*/

#define BDRV_SEQMAP (0x0u) /*decimal 0*/

#define BDRV_SEQOFFT4I4 (0x0u) /*decimal 0*/

#define BEMFC_GLOBCONF_EN (0x0u) /*decimal 0*/

#endif /* BDRV_DEFINES_H */
