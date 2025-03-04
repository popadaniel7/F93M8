/*
BSD 2-Clause License

Copyright (c) 2019, xujinpeng1117
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
#include <stdint.h>
#include "mcu_lock.h"




void mcu_lock_init(mcu_lock_t* lock)
{
	*lock = 0;
}


unsigned int mcu_lock_try_lock(register mcu_lock_t* lock)
{
	register volatile cpu_status_t cpu_sr;
	register unsigned int ret = (0==1);
	if(0 == *lock)
	{
		MCU_LOCK_ENTER_CRITICAL;
		if(0 == *lock)
		{
			*lock = 1;
			ret = (1==1);
		}
		MCU_LOCK_EXIT_CRITICAL;
	}
	return ret;
}


void mcu_lock_unlock(mcu_lock_t* lock)
{
	/*cpu_status_t cpu_sr;
	if(true == *lock)
	{
		MCU_LOCK_ENTER_CRITICAL;
		if(true == *lock)
		{
			*lock = false;
		}
		MCU_LOCK_EXIT_CRITICAL;
	}*/
	*lock = 0;
}
