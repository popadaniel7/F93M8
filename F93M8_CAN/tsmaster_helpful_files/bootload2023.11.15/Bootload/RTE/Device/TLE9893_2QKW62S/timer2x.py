#<checksum>58fcc88556cac60a58002d22e57d7038235c690a1dbbb1e7bb6ea78321c54c64</checksum>
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
# \file     timer2x.py
#
# \brief    Script to handle timer2x elements in Config Wizard
#
# \version  V0.1.4
# \date     30. Nov 2021
#
###############################################################################
#                              Author(s) Identity                             #
#*****************************************************************************#
#  Initials     Name                                                          #
#  -------------------------------------------------------------------------- #
#  BG           Blandine Guillot                                              #
###############################################################################

###############################################################################
#                           Revision Control History                          #
#*****************************************************************************#
#  V0.1.0: 2020-11-25, BG:   Initial version                                  #
#  V0.1.1: 2021-01-07, BG:   EP-666: Created two separate functions for       #
#                            initialization of timers                         #
#  V0.1.2: 2021-05-07, BG:   EP-796: Added function to calculate the range of #
#                            timer and reload/capture register                #
#  V0.1.3: 2021-10-13, BG:   EP-918: Corrected rounding error for the fT20 and#
#                            fT21 in T2x_updateRange()                        #
#  V0.1.4: 2021-11-30, JO:   EP-937: Updated copyright and branding           #
###############################################################################

# -*- coding: utf-8 -*-

def T2x_updateInput(*args):
    # args[0], T20 or T21
    # args[1], CON_C_T2
    # args[2], _CON_T2INSEL
    if args[1].currentIndex == 0:
        inp = args[0] + 'IN n/a'
    elif args[1].currentIndex == 1:
        inp = args[2].currentText
    return inp

def T2x_updatePrescaler(*args):
    # args[0], T20 or T21
    # args[1], CON_C_T2
    # args[2], MOD_T2PRE_
    if args[1].currentIndex == 0:
        prescaler = [int(s) for s in args[2].currentText.split() if s.isdigit()][0]
    elif args[1].currentIndex == 1:
        prescaler = 12
    return prescaler

def T2x_updateExtInput(*args):
    # args[0], T20 or T21
    # args[1], CON_EXEN2
    # args[2], T20_CON_T2EXINSEL
    if int(args[1].checked) == 0:
        extInp = args[0] + 'EX n/a'
    elif int(args[1].checked) == 1:
        extInp = args[2].currentText
    return extInp

def T2x_updateExtInpEdgeSel(*args):
    # args[0], MODESEL
    # args[1], CON_EXEN2
    # args[2], MOD.EDGESEL
    if args[0].currentIndex == 1:
        args[2].currentIndex = 0
    else:
        if int(args[1].checked) == 0:
            args[2].currentIndex = 0

def T2x_updateExtStartEnable(*args):
    # args[0], CON_EXEN2
    # args[1], MOD_T2RHEN
    if int(args[0].checked) == 0:
        args[1].checked = 0
        
def T2x_updateExtStartEdgeSel(*args):
    # args[0], CON_EXEN2
    # args[1], MOD_T2RHEN
    # args[2], MOD.T2REGS
    if int(args[0].checked) == 0:
        args[2].currentIndex = 0
    elif int(args[0].checked) == 1:
        if int(args[1].checked) == 0:
            args[2].currentIndex = 0
    
def T2x_updateTFIntEnable(*args):
    # args[0], TF2_INT_EN
    # args[1], CON1.TF2EN
    if int(args[0].checked) == 0:
        args[1].checked = 0

def T2x_updateEXFIntEnable(*args):
    # args[0], CON.EXEN2
    # args[1], EXF2_INT_EN
    # args[2], CON1.EXF2EN
    if int(args[0].checked) == 0:
        args[1].checked = 0
        args[2].checked = 0
    elif int(args[0].checked) == 1:
        if int(args[1].checked) == 0:
            args[2].checked = 0

def T2x_updateRange(*args):
    # args[0], T20 or T21
    # args[1], CNTUNIT
    # args[2], CNT_REGVAL
    # args[3], RCUNIT
    # args[4], RC_REGVAL
    # args[5], fT20_Hz or fT21_Hz
    freq_Hz = args[5].text.split('.')[0]
    if args[0] == 'T20':
        # Timer Register
        if args[1].currentIndex == 0: # ticks
            args[2].minimum = 1    
            args[2].maximum = 65536
        else: # us
            args[2].minimum = 1    
            args[2].maximum = math.trunc(65536/round(int(freq_Hz)/1000000, 6))
        # Reload/capture Register
        if args[3].currentIndex == 0: # ticks
            args[4].minimum = 1    
            args[4].maximum = 65536
        else: # us
            args[4].minimum = 1    
            args[4].maximum = math.trunc(65536/round(int(freq_Hz)/1000000, 6))
    elif args[0] == 'T21':
        # Timer Register
        if args[1].currentIndex == 0: # ticks
            args[2].minimum = 1    
            args[2].maximum = 65536
        else: # us
            args[2].minimum = 1    
            args[2].maximum = math.trunc(65536/round(int(freq_Hz)/1000000, 6))
        # Reload/capture Register
        if args[3].currentIndex == 0: # ticks
            args[4].minimum = 1    
            args[4].maximum = 65536
        else: # us
            args[4].minimum = 1    
            args[4].maximum = math.trunc(65536/round(int(freq_Hz)/1000000, 6))
        
    

def T2x_showMode(*args):
    # args[0], T20 or T21
    # args[1], mode selected
    # args[2], CON_C_T2
    # args[3], CON_EXEN2
    # args[4], _EXF2_INT_EN
    # args[5], MOD_T2RHEN
    # args[6], _TF2_INT_EN
    application.runScript('setDef(' + args[0] + '.' + args[0] + '_CON_T2EXINSEL.visible=1)')
    application.runScript('setDef(T20.T21_CON_T2EXINSEL.visible=0)')
    application.runScript('setDef(T21.T20_CON_T2EXINSEL.visible=0)')
    application.runScript('setDef(' + args[0] + '.' + args[0] + '_EXF2_OUTPUT.visible=1)')
    application.runScript('setDef(T20.T21_EXF2_OUTPUT.visible=0)')
    application.runScript('setDef(T21.T20_EXF2_OUTPUT.visible=0)')
    if (args[1].currentIndex == 0) or (args[1].currentIndex == 2):
        application.runScript('setDef(CONT_' + args[0] + '_CLK.visible=1)')
        application.runScript('setDef(CONT_' + args[0] + '_EDGEEXT.visible=1)')
        if args[2].currentIndex == 0:
            application.runScript('setDef(CONT_' + args[0] + '_PS.visible=1)')
            application.runScript('setDef(CONT_' + args[0] + '_CNTIN.visible=0)')
        elif args[2].currentIndex == 1:
            application.runScript('setDef(CONT_' + args[0] + '_PS.visible=0)')
            application.runScript('setDef(CONT_' + args[0] + '_CNTIN.visible=1)')
            application.runScript('setDef(' + args[0] + '.' + args[0] + '_CON_T2INSEL.visible=1)')
            application.runScript('setDef(T20.T21_CON_T2INSEL.visible=0)')
            application.runScript('setDef(T21.T20_CON_T2INSEL.visible=0)')
    elif args[1].currentIndex == 1:
        application.runScript('setDef(CONT_' + args[0] + '_CLK.visible=0)')
        application.runScript('setDef(CONT_' + args[0] + '_PS.visible=1)')
        application.runScript('setDef(CONT_' + args[0] + '_CNTIN.visible=0)')
        application.runScript('setDef(CONT_' + args[0] + '_EDGEEXT.visible=0)')
    if int(args[3].checked) == 0:
        application.runScript('setDef(CONT_' + args[0] + '_EXTIN.enabled=0)')
        application.runScript('setDef(CONT_' + args[0] + '_EDGEEXT.enabled=0)')
        application.runScript('setDef(CONT_' + args[0] + '_ENEXTSTART.enabled=0)')
        application.runScript('setDef(CONT_' + args[0] + '_EXF2INTEN.enabled=0)')
        application.runScript('setDef(CONT_' + args[0] + '_EXF2EN.enabled=0)')
        application.runScript('setDef(CONT_' + args[0] + '_EXF2CB.enabled=0)')
        application.runScript('setDef(CONT_' + args[0] + '_EXF2OUTPUT.enabled=0)')
        application.runScript('setDef(' + args[0] + '.' + args[0] + '_EXF2_OUTPUT.visible=1)')
        application.runScript('setDef(T20.T21_EXF2_OUTPUT.visible=0)')
        application.runScript('setDef(T21.T20_EXF2_OUTPUT.visible=0)')
    elif int(args[3].checked) == 1:
        application.runScript('setDef(CONT_' + args[0] + '_EXTIN.enabled=1)')
        application.runScript('setDef(CONT_' + args[0] + '_EDGEEXT.enabled=1)')
        application.runScript('setDef(CONT_' + args[0] + '_ENEXTSTART.enabled=1)')
        application.runScript('setDef(CONT_' + args[0] + '_EXF2INTEN.enabled=1)')
        if int(args[4].checked) == 0:
            application.runScript('setDef(CONT_' + args[0] + '_EXF2EN.enabled=0)')
            application.runScript('setDef(CONT_' + args[0] + '_EXF2CB.enabled=0)')
            application.runScript('setDef(CONT_' + args[0] + '_EXF2OUTPUT.enabled=0)')
        elif int(args[4].checked) == 1:
            application.runScript('setDef(CONT_' + args[0] + '_EXF2EN.enabled=1)')
            application.runScript('setDef(CONT_' + args[0] + '_EXF2CB.enabled=1)')
            application.runScript('setDef(CONT_' + args[0] + '_EXF2OUTPUT.enabled=1)')
    if int(args[5].checked) == 0:
        application.runScript('setDef(CONT_' + args[0] + '_EDGEEXTSTART.enabled=0)')
    elif int(args[5].checked) == 1:
        application.runScript('setDef(CONT_' + args[0] + '_EDGEEXTSTART.enabled=1)')
    if int(args[6].checked) == 0:
        application.runScript('setDef(CONT_' + args[0] + '_TF2EN.enabled=0)')
        application.runScript('setDef(CONT_' + args[0] + '_TF2CB.enabled=0)')
    elif int(args[6].checked) == 1:
        application.runScript('setDef(CONT_' + args[0] + '_TF2EN.enabled=1)')
        application.runScript('setDef(CONT_' + args[0] + '_TF2CB.enabled=1)')
        
        
def T2x_updateColors(*args):
    # args[0], T20 or T21
    # args[1], selected mode
    # args[2], CON_C_T2
    # args[3], CON_EXEN2
    # args[4], MOD_EDGESEL
    # args[5], MOD_T2RHEN
    # args[6], MOD_T2REGS
    # args[7], CON1_TF2EN
    # args[8], CON1_EXF2EN
    application.runScript('setDef(' + args[0] + '_G_5=#000000)')
    application.runScript('setDef(' + args[0] + '_G_7=#F0F0F0)')
    application.runScript('setDef(' + args[0] + '_INT_7=#FFFFF0)')
    if args[1].currentIndex == 0:
        application.runScript('setDef(' + args[0] + '_G_8=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_G_9=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_G_12=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_INT_1=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_INT_3=#000000)')
    elif args[1].currentIndex == 1:
        application.runScript('setDef(' + args[0] + '_G_8=#000000)')
        application.runScript('setDef(' + args[0] + '_G_9=#F0F0F0)')
        application.runScript('setDef(' + args[0] + '_G_12=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_INT_1=#000000)')
        application.runScript('setDef(' + args[0] + '_INT_3=#000000)')
    elif args[1].currentIndex == 2:
        application.runScript('setDef(' + args[0] + '_G_8=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_G_9=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_G_12=#000000)')
        application.runScript('setDef(' + args[0] + '_INT_1=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_INT_3=#FFFFF0)')
    if args[2].currentIndex == 0:
        application.runScript('setDef(' + args[0] + '_G_1=#000000)')
        application.runScript('setDef(' + args[0] + '_G_2=#F0F0F0)')
        application.runScript('setDef(' + args[0] + '_G_3=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_G_4=#FFFFF0)')
    elif args[2].currentIndex == 1:
        application.runScript('setDef(' + args[0] + '_G_1=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_G_2=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_G_3=#000000)')
        application.runScript('setDef(' + args[0] + '_G_4=#F0F0F0)')
    if int(args[3].checked) == 0:
        application.runScript('setDef(' + args[0] + '_EX_1=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_EX_3=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_EX_5=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_EX_6=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_EX_7=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_EX_8=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_EX_9=#FFFFF0)')
    elif int(args[3].checked) == 1:
        application.runScript('setDef(' + args[0] + '_EX_1=#000000)')
        application.runScript('setDef(' + args[0] + '_EX_5=#F0F0F0)')
        if (args[1].currentIndex == 0) or (args[1].currentIndex == 2):
            application.runScript('setDef(' + args[0] + '_EX_3=#000000)')
            application.runScript('setDef(' + args[0] + '_EX_8=#FFFFF0)')
            application.runScript('setDef(' + args[0] + '_EX_9=#FFFFF0)')
        elif args[1].currentIndex == 1:
            application.runScript('setDef(' + args[0] + '_EX_3=#FFFFF0)')
            application.runScript('setDef(' + args[0] + '_EX_8=#000000)')
            application.runScript('setDef(' + args[0] + '_EX_9=#F0F0F0)')
        if args[4].currentIndex == 0:
            application.runScript('setDef(' + args[0] + '_EX_6=#FFFFF0)')
            if (args[1].currentIndex == 0) or (args[1].currentIndex == 2):
                application.runScript('setDef(' + args[0] + '_EX_7=#000000)')
            elif args[1].currentIndex == 1:
                application.runScript('setDef(' + args[0] + '_EX_7=#FFFFF0)')
        elif args[4].currentIndex == 1:
            application.runScript('setDef(' + args[0] + '_EX_7=#FFFFF0)')
            if (args[1].currentIndex == 0) or (args[1].currentIndex == 2):
                application.runScript('setDef(' + args[0] + '_EX_6=#000000)')
            elif args[1].currentIndex == 1:
                application.runScript('setDef(' + args[0] + '_EX_6=#FFFFF0)')
    if int(args[5].checked) == 0:
        application.runScript('setDef(' + args[0] + '_EXSTART_1=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_EXSTART_2=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_EXSTART_3=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_EXSTART_4=#FFFFF0)')
    elif int(args[5].checked) == 1:     
        application.runScript('setDef(' + args[0] + '_EXSTART_1=#000000)')
        application.runScript('setDef(' + args[0] + '_EXSTART_2=#F0F0F0)')
        if args[6].currentIndex == 0:
            application.runScript('setDef(' + args[0] + '_EXSTART_3=#FFFFF0)')
            application.runScript('setDef(' + args[0] + '_EXSTART_4=#000000)')
        elif args[6].currentIndex == 1:
            application.runScript('setDef(' + args[0] + '_EXSTART_3=#000000)')
            application.runScript('setDef(' + args[0] + '_EXSTART_4=#FFFFF0)')
    if int(args[7].checked) == 0:
        application.runScript('setDef(' + args[0] + '_INT_4=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_INT_5=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_INT_6=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_INT_11=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_INT_12=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_INT_14=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_INT_15=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_INT_16=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_INT_17=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_INT_18=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_INT_20=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_INT_21=#FFFFF0)')
        if (args[1].currentIndex == 0) or (args[1].currentIndex == 1):
            application.runScript('setDef(' + args[0] + '_INT_2=#000000)')
        elif args[1].currentIndex == 2:
            application.runScript('setDef(' + args[0] + '_INT_2=#FFFFF0)')
        if int(args[8].checked) == 0:
            application.runScript('setDef(' + args[0] + '_INT_9=#FFFFF0)')
            application.runScript('setDef(' + args[0] + '_INT_10=#FFFFF0)')
            application.runScript('setDef(' + args[0] + '_INT_13=#FFFFF0)')
        elif int(args[8].checked) == 1:
            if (args[1].currentIndex == 0) or (args[1].currentIndex == 2):
                application.runScript('setDef(' + args[0] + '_INT_8=#FFFFF0)')
                application.runScript('setDef(' + args[0] + '_INT_9=#FFFFF0)')
                application.runScript('setDef(' + args[0] + '_INT_10=#FFFFF0)')
                application.runScript('setDef(' + args[0] + '_INT_13=#FFFFF0)')
                application.runScript('setDef(' + args[0] + '_INT_19=#000000)')
                application.runScript('setDef(' + args[0] + '_INT_22=#000000)')
            elif args[1].currentIndex == 0:
                application.runScript('setDef(' + args[0] + '_INT_8=#000000)')
                application.runScript('setDef(' + args[0] + '_INT_9=#000000)')
                application.runScript('setDef(' + args[0] + '_INT_10=#F0F0F0)')
                application.runScript('setDef(' + args[0] + '_INT_13=#000000)')
                application.runScript('setDef(' + args[0] + '_INT_19=#FFFFF0)')
                application.runScript('setDef(' + args[0] + '_INT_22=#FFFFF0)')
    elif int(args[7].checked) == 1:
        application.runScript('setDef(' + args[0] + '_INT_2=#000000)')
        if args[1].currentIndex == 0:
            application.runScript('setDef(' + args[0] + '_INT_4=#FFFFF0)')
            application.runScript('setDef(' + args[0] + '_INT_9=#FFFFF0)')
            application.runScript('setDef(' + args[0] + '_INT_10=#FFFFF0)')
            application.runScript('setDef(' + args[0] + '_INT_11=#FFFFF0)')
            application.runScript('setDef(' + args[0] + '_INT_12=#FFFFF0)')
            application.runScript('setDef(' + args[0] + '_INT_13=#FFFFF0)')
            application.runScript('setDef(' + args[0] + '_INT_14=#000000)')
        elif args[1].currentIndex == 1:
            application.runScript('setDef(' + args[0] + '_INT_4=#FFFFF0)')
            application.runScript('setDef(' + args[0] + '_INT_9=#000000)')
            application.runScript('setDef(' + args[0] + '_INT_10=#F0F0F0)')
            application.runScript('setDef(' + args[0] + '_INT_11=#000000)')
            application.runScript('setDef(' + args[0] + '_INT_12=#000000)')
            application.runScript('setDef(' + args[0] + '_INT_13=#000000)')
            application.runScript('setDef(' + args[0] + '_INT_14=#FFFFF0)')
        elif args[1].currentIndex == 2:
            application.runScript('setDef(' + args[0] + '_INT_4=#000000)')
            application.runScript('setDef(' + args[0] + '_INT_9=#FFFFF0)')
            application.runScript('setDef(' + args[0] + '_INT_10=#FFFFF0)')
            application.runScript('setDef(' + args[0] + '_INT_11=#FFFFF0)')
            application.runScript('setDef(' + args[0] + '_INT_12=#FFFFF0)')
            application.runScript('setDef(' + args[0] + '_INT_13=#FFFFF0)')
            application.runScript('setDef(' + args[0] + '_INT_14=#000000)')
        if int(args[8].checked) == 0:
            application.runScript('setDef(' + args[0] + '_INT_16=#FFFFF0)')
            application.runScript('setDef(' + args[0] + '_INT_17=#FFFFF0)')
            application.runScript('setDef(' + args[0] + '_INT_18=#FFFFF0)')
            application.runScript('setDef(' + args[0] + '_INT_20=#FFFFF0)')
            application.runScript('setDef(' + args[0] + '_INT_21=#FFFFF0)')
            if (args[1].currentIndex == 0) or (args[1].currentIndex == 2):
                application.runScript('setDef(' + args[0] + '_INT_5=#000000)')
                application.runScript('setDef(' + args[0] + '_INT_6=#000000)')
                application.runScript('setDef(' + args[0] + '_INT_15=#000000)')
            elif args[1].currentIndex == 0:
                application.runScript('setDef(' + args[0] + '_INT_5=#FFFFF0)')
                application.runScript('setDef(' + args[0] + '_INT_6=#FFFFF0)')
                application.runScript('setDef(' + args[0] + '_INT_15=#FFFFF0)')
        elif int(args[8].checked) == 1:
            application.runScript('setDef(' + args[0] + '_INT_5=#FFFFF0)')
            application.runScript('setDef(' + args[0] + '_INT_6=#FFFFF0)')
            application.runScript('setDef(' + args[0] + '_INT_15=#FFFFF0)')
            application.runScript('setDef(' + args[0] + '_INT_22=#FFFFF0)')
            if (args[1].currentIndex == 0) or (args[1].currentIndex == 2):
                application.runScript('setDef(' + args[0] + '_INT_8=#FFFFF0)')
                application.runScript('setDef(' + args[0] + '_INT_16=#000000)')
                application.runScript('setDef(' + args[0] + '_INT_17=#000000)')
                application.runScript('setDef(' + args[0] + '_INT_18=#FFFFF0)')
                application.runScript('setDef(' + args[0] + '_INT_19=#000000)')
                application.runScript('setDef(' + args[0] + '_INT_20=#000000)')
                application.runScript('setDef(' + args[0] + '_INT_21=#000000)')
            elif args[1].currentIndex == 0:
                application.runScript('setDef(' + args[0] + '_INT_8=#000000)')
                application.runScript('setDef(' + args[0] + '_INT_16=#FFFFF0)')
                application.runScript('setDef(' + args[0] + '_INT_17=#FFFFF0)')
                application.runScript('setDef(' + args[0] + '_INT_18=#FFFFF0)')
                application.runScript('setDef(' + args[0] + '_INT_19=#FFFFF0)')
                application.runScript('setDef(' + args[0] + '_INT_20=#FFFFF0)')
                application.runScript('setDef(' + args[0] + '_INT_21=#FFFFF0)')
    if int(args[8].checked) == 0:
        application.runScript('setDef(' + args[0] + '_INT_8=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_INT_19=#FFFFF0)')
        application.runScript('setDef(' + args[0] + '_INT_22=#FFFFF0)')
            

def T2x_updateVisibility(*args):
    # args[0], T20 or T21
    # args[1], selected mode
    # args[2], CON_EXEN2
    # args[3], MOD_EDGESEL
    # args[4], MOD_T2RHEN
    # args[5], MOD_T2REGS
    application.runScript('setDef(VIS_' + args[0] + '_10=hidden)')
    if args[1].currentIndex == 0:
        application.runScript('setDef(VIS_' + args[0] + '_1=visible)')
        application.runScript('setDef(VIS_' + args[0] + '_4=hidden)')
        application.runScript('setDef(VIS_' + args[0] + '_7=visible)')
        application.runScript('setDef(VIS_' + args[0] + '_8=hidden)')
    elif args[1].currentIndex == 1:
        application.runScript('setDef(VIS_' + args[0] + '_1=hidden)')
        application.runScript('setDef(VIS_' + args[0] + '_4=visible)')
        application.runScript('setDef(VIS_' + args[0] + '_7=visible)')
        application.runScript('setDef(VIS_' + args[0] + '_8=hidden)')
    elif args[1].currentIndex == 2:
        application.runScript('setDef(VIS_' + args[0] + '_1=visible)')
        application.runScript('setDef(VIS_' + args[0] + '_4=hidden)')
        application.runScript('setDef(VIS_' + args[0] + '_7=hidden)')
        application.runScript('setDef(VIS_' + args[0] + '_8=visible)')
    if int(args[2].checked) == 0:
        application.runScript('setDef(VIS_' + args[0] + '_2=hidden)')
        application.runScript('setDef(VIS_' + args[0] + '_3=hidden)')
    elif int(args[2].checked) == 1:
        if args[3].currentIndex == 0:
            application.runScript('setDef(VIS_' + args[0] + '_2=hidden)')
            if (args[1].currentIndex == 0) or (args[1].currentIndex == 2):
                application.runScript('setDef(VIS_' + args[0] + '_3=visible)')
            elif args[1].currentIndex == 1:
                application.runScript('setDef(VIS_' + args[0] + '_3=hidden)')
        elif args[3].currentIndex == 1:
            application.runScript('setDef(VIS_' + args[0] + '_3=hidden)')
            if (args[1].currentIndex == 0) or (args[1].currentIndex == 2):
                application.runScript('setDef(VIS_' + args[0] + '_2=visible)')
            elif args[1].currentIndex == 1:
                application.runScript('setDef(VIS_' + args[0] + '_2=hidden)')
    if int(args[4].checked) == 0:
        application.runScript('setDef(VIS_' + args[0] + '_5=hidden)')
        application.runScript('setDef(VIS_' + args[0] + '_6=hidden)')
    elif int(args[4].checked) == 1:      
        if args[5].currentIndex == 0:
            application.runScript('setDef(VIS_' + args[0] + '_5=hidden)')
            application.runScript('setDef(VIS_' + args[0] + '_6=visible)')
        elif args[5].currentIndex == 1:
            application.runScript('setDef(VIS_' + args[0] + '_5=visible)')
            application.runScript('setDef(VIS_' + args[0] + '_6=hidden)')
    
def updateModeT20_connect(idx):
    T2x_updateExtInpEdgeSel(T20_MODESEL, T20_CON_EXEN2, T20_MOD_EDGESEL)
    T20IN.text = T2x_updateInput('T20', T20_CON_C_T2, T20_T20_CON_T2INSEL)
    T20PS.text = T2x_updatePrescaler('T20', T20_CON_C_T2, T20_MOD_T2PRE_)
    T20EX.text = T2x_updateExtInput('T20', T20_CON_EXEN2, T20_T20_CON_T2EXINSEL)
    T2x_showMode('T20', T20_MODESEL, T20_CON_C_T2, T20_CON_EXEN2, T20_EXF2_INT_EN, T20_MOD_T2RHEN, T20_TF2_INT_EN)
    T2x_updateColors('T20', T20_MODESEL, T20_CON_C_T2, T20_CON_EXEN2, T20_MOD_EDGESEL, T20_MOD_T2RHEN, T20_MOD_T2REGS, T20_CON1_TF2EN, T20_CON1_EXF2EN)
    T2x_updateVisibility('T20', T20_MODESEL, T20_CON_EXEN2, T20_MOD_EDGESEL, T20_MOD_T2RHEN, T20_MOD_T2REGS)
    application.runScript('setDef(T20_Block.update=1)')

def updateModeT21_connect(idx):
    T2x_updateExtInpEdgeSel(T21_MODESEL, T21_CON_EXEN2, T21_MOD_EDGESEL)
    T21IN.text = T2x_updateInput('T21', T21_CON_C_T2, T21_T21_CON_T2INSEL)
    T21PS.text = T2x_updatePrescaler('T21', T21_CON_C_T2, T21_MOD_T2PRE_)
    T21EX.text = T2x_updateExtInput('T21', T21_CON_EXEN2, T21_T21_CON_T2EXINSEL)
    T2x_showMode('T21', T21_MODESEL, T21_CON_C_T2, T21_CON_EXEN2, T21_EXF2_INT_EN, T21_MOD_T2RHEN, T21_TF2_INT_EN)
    T2x_updateColors('T21', T21_MODESEL, T21_CON_C_T2, T21_CON_EXEN2, T21_MOD_EDGESEL, T21_MOD_T2RHEN, T21_MOD_T2REGS, T21_CON1_TF2EN, T21_CON1_EXF2EN)
    T2x_updateVisibility('T21', T21_MODESEL, T21_CON_EXEN2, T21_MOD_EDGESEL, T21_MOD_T2RHEN, T21_MOD_T2REGS)
    application.runScript('setDef(T21_Block.update=1)')

def updateClockT20_connect(idx):
    T20IN.text = T2x_updateInput('T20', T20_CON_C_T2, T20_T20_CON_T2INSEL)
    T20PS.text = T2x_updatePrescaler('T20', T20_CON_C_T2, T20_MOD_T2PRE_)
    T2x_showMode('T20', T20_MODESEL, T20_CON_C_T2, T20_CON_EXEN2, T20_EXF2_INT_EN, T20_MOD_T2RHEN, T20_TF2_INT_EN)
    T2x_updateColors('T20', T20_MODESEL, T20_CON_C_T2, T20_CON_EXEN2, T20_MOD_EDGESEL, T20_MOD_T2RHEN, T20_MOD_T2REGS, T20_CON1_TF2EN, T20_CON1_EXF2EN)
    T2x_updateVisibility('T20', T20_MODESEL, T20_CON_EXEN2, T20_MOD_EDGESEL, T20_MOD_T2RHEN, T20_MOD_T2REGS)
    application.runScript('setDef(T20_Block.update=1)')

def updateClockT21_connect(idx):
    T21IN.text = T2x_updateInput('T21', T21_CON_C_T2, T21_T21_CON_T2INSEL)
    T21PS.text = T2x_updatePrescaler('T21', T21_CON_C_T2, T21_MOD_T2PRE_)
    T2x_showMode('T21', T21_MODESEL, T21_CON_C_T2, T21_CON_EXEN2, T21_EXF2_INT_EN, T21_MOD_T2RHEN, T21_TF2_INT_EN)
    T2x_updateColors('T21', T21_MODESEL, T21_CON_C_T2, T21_CON_EXEN2, T21_MOD_EDGESEL, T21_MOD_T2RHEN, T21_MOD_T2REGS, T21_CON1_TF2EN, T21_CON1_EXF2EN)
    T2x_updateVisibility('T21', T21_MODESEL, T21_CON_EXEN2, T21_MOD_EDGESEL, T21_MOD_T2RHEN, T21_MOD_T2REGS)
    application.runScript('setDef(T21_Block.update=1)')
    
def updateExternalEventT20_connect(idx):
    T2x_updateExtInpEdgeSel(T20_MODESEL, T20_CON_EXEN2, T20_MOD_EDGESEL)
    T2x_updateExtStartEnable(T20_CON_EXEN2, T20_MOD_T2RHEN)
    T2x_updateExtStartEdgeSel(T20_CON_EXEN2, T20_MOD_T2RHEN, T20_MOD_T2REGS)
    T2x_updateTFIntEnable(T20_TF2_INT_EN, T20_CON1_TF2EN)
    T2x_updateEXFIntEnable(T20_CON_EXEN2, T20_EXF2_INT_EN, T20_CON1_EXF2EN)
    T20EX.text = T2x_updateExtInput('T20', T20_CON_EXEN2, T20_T20_CON_T2EXINSEL)
    T2x_showMode('T20', T20_MODESEL, T20_CON_C_T2, T20_CON_EXEN2, T20_EXF2_INT_EN, T20_MOD_T2RHEN, T20_TF2_INT_EN)
    T2x_updateColors('T20', T20_MODESEL, T20_CON_C_T2, T20_CON_EXEN2, T20_MOD_EDGESEL, T20_MOD_T2RHEN, T20_MOD_T2REGS, T20_CON1_TF2EN, T20_CON1_EXF2EN)
    T2x_updateVisibility('T20', T20_MODESEL, T20_CON_EXEN2, T20_MOD_EDGESEL, T20_MOD_T2RHEN, T20_MOD_T2REGS)
    application.runScript('setDef(T20_Block.update=1)')

def updateExternalEventT21_connect(idx):
    T2x_updateExtInpEdgeSel(T21_MODESEL, T21_CON_EXEN2, T21_MOD_EDGESEL)
    T2x_updateExtStartEnable(T21_CON_EXEN2, T21_MOD_T2RHEN)
    T2x_updateExtStartEdgeSel(T21_CON_EXEN2, T21_MOD_T2RHEN, T21_MOD_T2REGS)
    T2x_updateTFIntEnable(T21_TF2_INT_EN, T21_CON1_TF2EN)
    T2x_updateEXFIntEnable(T21_CON_EXEN2, T21_EXF2_INT_EN, T21_CON1_EXF2EN)
    T21EX.text = T2x_updateExtInput('T21', T21_CON_EXEN2, T21_T21_CON_T2EXINSEL)
    T2x_showMode('T21', T21_MODESEL, T21_CON_C_T2, T21_CON_EXEN2, T21_EXF2_INT_EN, T21_MOD_T2RHEN, T21_TF2_INT_EN)
    T2x_updateColors('T21', T21_MODESEL, T21_CON_C_T2, T21_CON_EXEN2, T21_MOD_EDGESEL, T21_MOD_T2RHEN, T21_MOD_T2REGS, T21_CON1_TF2EN, T21_CON1_EXF2EN)
    T2x_updateVisibility('T21', T21_MODESEL, T21_CON_EXEN2, T21_MOD_EDGESEL, T21_MOD_T2RHEN, T21_MOD_T2REGS)
    application.runScript('setDef(T21_Block.update=1)')

def updateInterruptT20_connect(idx):
    T2x_updateTFIntEnable(T20_TF2_INT_EN, T20_CON1_TF2EN)
    T2x_updateEXFIntEnable(T20_CON_EXEN2, T20_EXF2_INT_EN, T20_CON1_EXF2EN)
    T2x_showMode('T20', T20_MODESEL, T20_CON_C_T2, T20_CON_EXEN2, T20_EXF2_INT_EN, T20_MOD_T2RHEN, T20_TF2_INT_EN)
    T2x_updateColors('T20', T20_MODESEL, T20_CON_C_T2, T20_CON_EXEN2, T20_MOD_EDGESEL, T20_MOD_T2RHEN, T20_MOD_T2REGS, T20_CON1_TF2EN, T20_CON1_EXF2EN)
    T2x_updateVisibility('T20', T20_MODESEL, T20_CON_EXEN2, T20_MOD_EDGESEL, T20_MOD_T2RHEN, T20_MOD_T2REGS)
    application.runScript('setDef(T20_Block.update=1)')

def updateInterruptT21_connect(idx):
    T2x_updateTFIntEnable(T21_TF2_INT_EN, T21_CON1_TF2EN)
    T2x_updateEXFIntEnable(T21_CON_EXEN2, T21_EXF2_INT_EN, T21_CON1_EXF2EN)
    T2x_showMode('T21', T21_MODESEL, T21_CON_C_T2, T21_CON_EXEN2, T21_EXF2_INT_EN, T21_MOD_T2RHEN, T21_TF2_INT_EN)
    T2x_updateColors('T21', T21_MODESEL, T21_CON_C_T2, T21_CON_EXEN2, T21_MOD_EDGESEL, T21_MOD_T2RHEN, T21_MOD_T2REGS, T21_CON1_TF2EN, T21_CON1_EXF2EN)
    T2x_updateVisibility('T21', T21_MODESEL, T21_CON_EXEN2, T21_MOD_EDGESEL, T21_MOD_T2RHEN, T21_MOD_T2REGS)
    application.runScript('setDef(T21_Block.update=1)')

def updateRangeT20_connect(idx):
    T2x_updateRange('T20', T20_CNTUNIT, T20_CNT_REGVAL, T20_RCUNIT, T20_RC_REGVAL, fT20_Hz)

def updateRangeT21_connect(idx):
    T2x_updateRange('T21', T21_CNTUNIT, T21_CNT_REGVAL, T21_RCUNIT, T21_RC_REGVAL, fT21_Hz)

   
def T20_updateConfig_connect(state):
    updateModeT20_connect(0)
    
def T21_updateConfig_connect(state):
    updateModeT21_connect(0)
    
T20_MODESEL.connect('currentIndexChanged(int)', updateModeT20_connect)
T21_MODESEL.connect('currentIndexChanged(int)', updateModeT21_connect)

# Module enable
SCU_PMCON_T2_DIS.connect('stateChanged(int)', T20_updateConfig_connect)
SCU_PMCON_T21_DIS.connect('stateChanged(int)', T21_updateConfig_connect)

# Frequency
T2x_FREQ_EDIT.connect('textChanged(QString)', updateClockT20_connect)
T2x_FREQ_EDIT.connect('textChanged(QString)', updateClockT21_connect)

# Clock Selection
T20_CON_C_T2.connect('currentIndexChanged(int)', updateClockT20_connect)
T20_MOD_T2PRE_.connect('currentIndexChanged(int)', updateClockT20_connect)
T20_T20_CON_T2INSEL.connect('currentIndexChanged(int)', updateClockT20_connect)

T21_CON_C_T2.connect('currentIndexChanged(int)', updateClockT21_connect)
T21_MOD_T2PRE_.connect('currentIndexChanged(int)', updateClockT21_connect)
T21_T21_CON_T2INSEL.connect('currentIndexChanged(int)', updateClockT21_connect)

# External Event
T20_CON_EXEN2.connect('stateChanged(int)', updateExternalEventT20_connect)
T20_T20_CON_T2EXINSEL.connect('currentIndexChanged(int)', updateExternalEventT20_connect)
T20_MOD_EDGESEL.connect('currentIndexChanged(int)', updateExternalEventT20_connect)
T20_MOD_T2RHEN.connect('stateChanged(int)', updateExternalEventT20_connect)
T20_MOD_T2REGS.connect('currentIndexChanged(int)', updateExternalEventT20_connect)

T21_CON_EXEN2.connect('stateChanged(int)', updateExternalEventT21_connect)
T21_T21_CON_T2EXINSEL.connect('currentIndexChanged(int)', updateExternalEventT21_connect)
T21_MOD_EDGESEL.connect('currentIndexChanged(int)', updateExternalEventT21_connect)
T21_MOD_T2RHEN.connect('stateChanged(int)', updateExternalEventT21_connect)
T21_MOD_T2REGS.connect('currentIndexChanged(int)', updateExternalEventT21_connect)

# Interrupts
T20_TF2_INT_EN.connect('stateChanged(int)', updateInterruptT20_connect)
T20_CON1_TF2EN.connect('stateChanged(int)', updateInterruptT20_connect)
T20_EXF2_INT_EN.connect('stateChanged(int)', updateInterruptT20_connect)
T20_CON1_EXF2EN.connect('stateChanged(int)', updateInterruptT20_connect)
T20_T20_EXF2_OUTPUT.connect('currentIndexChanged(int)', updateInterruptT20_connect)

T21_TF2_INT_EN.connect('stateChanged(int)', updateInterruptT21_connect)
T21_CON1_TF2EN.connect('stateChanged(int)', updateInterruptT21_connect)
T21_EXF2_INT_EN.connect('stateChanged(int)', updateInterruptT21_connect)
T21_CON1_EXF2EN.connect('stateChanged(int)', updateInterruptT21_connect)
T21_T21_EXF2_OUTPUT.connect('currentIndexChanged(int)', updateInterruptT21_connect)

# Timer Registers
T20_CNT_REGVAL.connect('valueChanged(int)', updateRangeT20_connect)
T20_CNTUNIT.connect('currentIndexChanged(int)', updateRangeT20_connect)
T20_RC_REGVAL.connect('valueChanged(int)', updateRangeT20_connect)
T20_RCUNIT.connect('currentIndexChanged(int)', updateRangeT20_connect)
T21_CNT_REGVAL.connect('valueChanged(int)', updateRangeT21_connect)
T21_CNTUNIT.connect('currentIndexChanged(int)', updateRangeT21_connect)
T21_RC_REGVAL.connect('valueChanged(int)', updateRangeT21_connect)
T21_RCUNIT.connect('currentIndexChanged(int)', updateRangeT21_connect)




T20_updateConfig_connect(2)
T21_updateConfig_connect(2)





