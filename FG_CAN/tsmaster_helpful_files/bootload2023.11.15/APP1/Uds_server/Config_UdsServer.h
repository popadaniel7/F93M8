/*
BSD 2-Clause License

Copyright (c) 2023, LiangXenpeng
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef __CONFIG_UDSSERVER_H__
#define __CONFIG_UDSSERVER_H__
#include "tle_device.h"
/*
	FLASH0_START address: 0x11000000U
	FLASH1_START address: 0x12002000U
	SRAM_START   address: 0x18000000U
	DSRAM_START  address: 0x18002000U
*/

/* FLASH1 start address */
#define Jump_APPSTART_ADRESS  0x12010000

/* FLASH1 size */
#define UC_FLASH1_SIZE_APP 		0x3E000

/* FLASH0 start address */ 
#define Jump_BOOTSTART_ADRESS  0x11000000

#define UC_FLASH1_SIZE_BOOT		 0x0D000

#define BOOTSTART_ADRESS  		 0x10002000//

/* APP vector start address */
#define USER_APPLICATION_VTAB_ADDRESS (Jump_APPSTART_ADRESS + 0x100U)

/* Bootload vector start address */
#define USER_BOOTLOADER_VTAB_ADDRESS ( Jump_BOOTSTART_ADRESS  + 0x100U)

#define RAM_START_ADRESS              (UC_PSRAM_START)
#define RAM_END_ADDRESS               (UC_DSRAM_START + UC_DSRAM_SIZE)

#define FLASH1_START_ADDRESS          (UC_FLASH1_START)
#define FLASH1_END_ADDRESS            (UC_FLASH1_START + UC_FLASH1_SIZE)


/* The MCU is powered back on 27 service guard time */
#define Config_UDS27_Timelock_count 1000

/* 3E Service online time */
#define Config_ServerOnline 5000 

/* Download address limit (the APP download address should be larger than the current address) */
#define DownloadStartAddress  0x12002000 

#define ReservedRAM *((uint8_t *)0x18000000)  //0x18000000~0x1800000C

/* Whether to enable CRC validation configuration parameters */
#define CRC 1

#define BOOT 0

#endif
