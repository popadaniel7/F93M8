/*
BSD 2-Clause License

*    Copyright (c) 2023, LiangXinpeng
						    All rights reserved.
*    FileName:  JumpToAPP.c
*     Version:  v1.0
*        Date:  2023.04
* Description:  Go to the APP handler.

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

#include "JumpToAPP.h"

/*******************************************************************************
**                         Private Function Definitions                       **
*******************************************************************************/

/* Assembly function to jump execution to a location */
__attribute__( ( naked, noreturn ) ) void BootJumpASM( uint32_t SP, uint32_t RH )
{
		__asm("MSR      MSP,r0");
		__asm("BX       r1");
}

/**
 * @brief  Jump function.
 * @param  user_jump_flag: 
 * @return           None.
 * @private
 */
 void app_jump(uint32_t user_jump_flag)
{
		uint32_t * Address=0;
		if(user_jump_flag==0xbb)
		{
			Address=(uint32*)USER_APPLICATION_VTAB_ADDRESS;
		}
		else if(user_jump_flag==0xdd)
		{		
			Address=(uint32*)USER_BOOTLOADER_VTAB_ADDRESS;
		}
		else
		{		
			Address=(uint32*)USER_APPLICATION_VTAB_ADDRESS;
		}
		if(Address[0] >= RAM_START_ADRESS && 
			Address[0] < RAM_END_ADDRESS && 
			Address[1] >= FLASH1_START_ADDRESS && 
			Address[1] < FLASH1_END_ADDRESS)
    {
        /* Service Watchdog */
        PMU_serviceFailSafeWatchdogSOW();
        GPIO->P1_OMR.reg = 0x00010001;
        
        /* Disable all interrupts */
        __disable_irq();
        
        /* point VTOR to new vector table */
        CPU->VTOR.reg = USER_APPLICATION_VTAB_ADDRESS;
        
        /*Jump to new application */
        BootJumpASM( Address[ 0 ], Address[ 1 ] ) ;
     }
     else
     {
        /* Error hadling in case of wrong stack pointer or reset handler address */
     }
}
