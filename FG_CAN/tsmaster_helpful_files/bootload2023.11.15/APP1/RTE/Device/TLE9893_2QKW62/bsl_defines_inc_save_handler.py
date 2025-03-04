#<checksum>de637f58af6d8c650ef4dc3e170a2219ff2b555e82b6a0931bb9994ea2a97ff6</checksum>
#                                                                                
# Copyright (c) Infineon Technologies AG                                   
# All rights reserved.                                                           
#                                                                                
# Redistribution and use in source and binary forms, with or without modification,
# are permitted provided that the following conditions are met:                  
#                                                                                
#  Redistributions of source code must retain the above copyright notice, this   
#  list of conditions and the following disclaimer.                              
#                                                                                
#  Redistributions in binary form must reproduce the above copyright notice,     
#  this list of conditions and the following disclaimer in the documentation     
#  and/or other materials provided with the distribution.                        
#                                                                                
#  Neither the name of the copyright holders nor the names of its contributors   
#  may be used to endorse or promote products derived from this software without 
#  specific prior written permission.                                            
#                                                                                
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE         
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE   
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL     
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR     
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER     
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.           
#
#
# \file     bsl_defines_inc_save_handler.py
#
# \brief    Script to generate the file bsl_defines.inc
#
# \version  V0.2.2
# \date     30. Nov 2021
#

###############################################################################
#                              Author(s) Identity                             #
#*****************************************************************************#
#  Initials     Name                                                          #
#  -------------------------------------------------------------------------- #
#  JO           Julia Ott                                                     #
#  BG           Blandine Guillot                                              #
###############################################################################

###############################################################################
#                           Revision Control History                          #
#*****************************************************************************#
#  V0.1.0: 2021-04-09, JO:   Initial version with FLASH1_CACHE_EN             #
#  V0.1.1: 2021-06-21, JO:   EP-846: Updated SECBOOT_KEY to 0xFFFFFFFF        #
#  V0.2.0: 2021-06-21, JO:   EP-847: Added generation of BSL_NAD_NAC          #
#  V0.2.1: 2021-07-12, BG:   EP-716: Added generation of two files - the .inc #
#                            file for IAR must not have an END at the end     #
#  V0.2.2: 2021-11-30, JO:   EP-937: Updated copyright and branding           #
###############################################################################


def bsl_defines_inc_save_handler():
    if FLASH1_CACHE_EN.checked == False:
      FLASH1_CACHE_EN_value = '0x00000000'
    else:
      FLASH1_CACHE_EN_value = '0x00000004'
    with open('bsl_defines_ARM.inc', 'w+') as file:
        file.write('BSL_NAD_NAC     EQU     ' + hex(int(BSL_NAD_NAC_REG.text.replace('\u202c', ''))).upper().replace('X', 'x') + '\n')
        file.write('SECBOOT_KEY     EQU     0xFFFFFFFF\n')
        file.write('FLASH1_CACHE_EN EQU     ' + FLASH1_CACHE_EN_value + '\n')
        file.write('                END\n')
    with open('bsl_defines_IAR.inc', 'w+') as file:
        file.write('BSL_NAD_NAC     EQU     ' + hex(int(BSL_NAD_NAC_REG.text.replace('\u202c', ''))).upper().replace('X', 'x') + '\n')
        file.write('SECBOOT_KEY     EQU     0xFFFFFFFF\n')
        file.write('FLASH1_CACHE_EN EQU     ' + FLASH1_CACHE_EN_value + '\n')
    
  

FILE_SAVE.connect('triggered()', bsl_defines_inc_save_handler)

