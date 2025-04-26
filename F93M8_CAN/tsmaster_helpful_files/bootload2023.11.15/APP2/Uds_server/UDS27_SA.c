/*
BSD 2-Clause License

*    Copyright (c) 2023, LiangXinpeng
						    All rights reserved.
*    FileName:  UDS27_SA.c
*     Version:  v1.0
*        Date:  2023.04
* Description:  This is the content of security unlock in UDS27 service. 
								The user can change the seed generation rules and the key
								required by the secure unlock algorithm.

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

#include "UDS27_SA.h"

uint32_t UDS27_RN=0;//Simulate random number generation


uint8_t UDS_SericeAccess_Seed[Access_num]={0};
uint8_t UDS_SericeAccess_Key[Access_num]={0};


/**
 * @brief  Generate random seeds
 * @param  
 * @return None.
 * @private
 */
void  Creating_Seed(uint8_t UDS_SericeAccess_Seednum[],uint8_t keynum)
{
	//You can modify the Seed required for production by yourself
	if(keynum==4)
	{
	UDS_SericeAccess_Seednum[0]=(uint8_t)(UDS27_RN%256);
	UDS_SericeAccess_Seednum[1]=(uint8_t)(UDS27_RN%100);
	UDS_SericeAccess_Seednum[2]=(uint8_t)(UDS27_RN%55);
	UDS_SericeAccess_Seednum[3]=(uint8_t)(UDS27_RN%8);
	}
}

/**
 * @brief  Keys are generated according to the algorithm, and the algorithm for generating keys can be changed
 * @param  
 * @return None.
 * @private
 */
 void  PasswordGenerator(const uint8_t UDS_SericeAccess_Seednum[],uint8_t UDS_SericeAccess_keynum[],uint8_t keynum)
{
	//You can modify the Key according to the Seed
	for(int i=0;i<keynum;i++)
	{
	UDS_SericeAccess_keynum[i]=UDS_SericeAccess_Seednum[i];
	}
}

/**
 * @brief  Check that the key is authentic
 * @param  
 * @return 0:success
					 1:false
 * @private
 */
uint8_t  SecurityAccess_unlock(uint8_t UDS_SericeAccess_TX[],uint8_t UDS_SericeAccess_Keynum[],uint8_t keynum)
{
	
	for(int i=0;i<keynum;i++)
	{
		if (UDS_SericeAccess_TX[i]==UDS_SericeAccess_Keynum[i])
		{

	}
		else
		{
			return 1;
		}
	}

	return 0;

}
