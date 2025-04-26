#<checksum>6d156ce7527100b3a80ce785bc5e29c99a9387a79eed49399060e703ffd26b01</checksum>
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
# \file     adc1.py
#
# \brief    Script to calculate the ADC1 values
#
# \version  V0.1.5
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
#  V0.1.0: 2020-12-14, BG:   Initial version                                  #
#  V0.1.1: 2021-03-04, BG:   EP-724: Added missing color setting              #
#                            Corrected index for channel text display in      #
#                            channel and sequencer diagrams                   #
#  V0.1.2: 2021-03-23, BG:   EP-750: Moved attenuator definition from xml to  #
#                            the Python script                                #
#  V0.1.3: 2021-03-23, BG:   EP-800: Added sequencer timings update when      #
#                            switching channel tabs                           #
#  V0.1.4: 2021-05-20, BG:   EP-801: Reset the compare channel interrupts     #
#                            when the compare channel is not assigned         #
#  V0.1.5: 2021-11-30, JO:   EP-937: Updated copyright and branding           #
###############################################################################

ADC1_DIGITAL_CHANNEL_MAX = 20
ADC1_ANALOG_CHANNEL_MAX = 27
ADC1_CALIB_TICKS = 4
ADC1_FILT_TICKS = 1
ADC1_CMP_TICKS = 1

ADC1_tabConfiguredList        = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
ADC1_inputSelectRegisterList  = [ADC1_CHCFG0_INSEL, ADC1_CHCFG1_INSEL, ADC1_CHCFG2_INSEL, ADC1_CHCFG3_INSEL, ADC1_CHCFG4_INSEL, ADC1_CHCFG5_INSEL, ADC1_CHCFG6_INSEL, ADC1_CHCFG7_INSEL, ADC1_CHCFG8_INSEL, ADC1_CHCFG9_INSEL, ADC1_CHCFG10_INSEL, ADC1_CHCFG11_INSEL, ADC1_CHCFG12_INSEL, ADC1_CHCFG13_INSEL, ADC1_CHCFG14_INSEL, ADC1_CHCFG15_INSEL, ADC1_CHCFG16_INSEL, ADC1_CHCFG17_INSEL, ADC1_CHCFG18_INSEL, ADC1_CHCFG19_INSEL]
ADC1_attenuatorVarList        = [ADC1_ATTENUATOR0, ADC1_ATTENUATOR1, ADC1_ATTENUATOR2, ADC1_ATTENUATOR3, ADC1_ATTENUATOR4, ADC1_ATTENUATOR5, ADC1_ATTENUATOR6, ADC1_ATTENUATOR7, ADC1_ATTENUATOR8, ADC1_ATTENUATOR9, ADC1_ATTENUATOR10, ADC1_ATTENUATOR11, ADC1_ATTENUATOR12, ADC1_ATTENUATOR13, ADC1_ATTENUATOR14, ADC1_ATTENUATOR15, ADC1_ATTENUATOR16, ADC1_ATTENUATOR17, ADC1_ATTENUATOR18, ADC1_ATTENUATOR19]
ADC1_attenuatorValList        = [102, 72, 102, 72, 72, 72, 72, 72, 72, 72, 102, 72, 102, 72, 102, 72, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512]
ADC1_classSelectRegisterList  = [ADC1_CHCFG0_CLASSEL, ADC1_CHCFG1_CLASSEL, ADC1_CHCFG2_CLASSEL, ADC1_CHCFG3_CLASSEL, ADC1_CHCFG4_CLASSEL, ADC1_CHCFG5_CLASSEL, ADC1_CHCFG6_CLASSEL, ADC1_CHCFG7_CLASSEL, ADC1_CHCFG8_CLASSEL, ADC1_CHCFG9_CLASSEL, ADC1_CHCFG10_CLASSEL, ADC1_CHCFG11_CLASSEL, ADC1_CHCFG12_CLASSEL, ADC1_CHCFG13_CLASSEL, ADC1_CHCFG14_CLASSEL, ADC1_CHCFG15_CLASSEL, ADC1_CHCFG16_CLASSEL, ADC1_CHCFG17_CLASSEL, ADC1_CHCFG18_CLASSEL, ADC1_CHCFG19_CLASSEL]
ADC1_channelRepRegisterList    = [ADC1_CHCFG0_REPCH, ADC1_CHCFG1_REPCH, ADC1_CHCFG2_REPCH, ADC1_CHCFG3_REPCH, ADC1_CHCFG4_REPCH, ADC1_CHCFG5_REPCH, ADC1_CHCFG6_REPCH, ADC1_CHCFG7_REPCH, ADC1_CHCFG8_REPCH, ADC1_CHCFG9_REPCH, ADC1_CHCFG10_REPCH, ADC1_CHCFG11_REPCH, ADC1_CHCFG12_REPCH, ADC1_CHCFG13_REPCH, ADC1_CHCFG14_REPCH, ADC1_CHCFG15_REPCH, ADC1_CHCFG16_REPCH, ADC1_CHCFG17_REPCH, ADC1_CHCFG18_REPCH, ADC1_CHCFG19_REPCH]
ADC1_filterSelectRegisterList  = [ADC1_CHCFG0_FILSEL, ADC1_CHCFG1_FILSEL, ADC1_CHCFG2_FILSEL, ADC1_CHCFG3_FILSEL, ADC1_CHCFG4_FILSEL, ADC1_CHCFG5_FILSEL, ADC1_CHCFG6_FILSEL, ADC1_CHCFG7_FILSEL, ADC1_CHCFG8_FILSEL, ADC1_CHCFG9_FILSEL, ADC1_CHCFG10_FILSEL, ADC1_CHCFG11_FILSEL, ADC1_CHCFG12_FILSEL, ADC1_CHCFG13_FILSEL, ADC1_CHCFG14_FILSEL, ADC1_CHCFG15_FILSEL, ADC1_CHCFG16_FILSEL, ADC1_CHCFG17_FILSEL, ADC1_CHCFG18_FILSEL, ADC1_CHCFG19_FILSEL]
ADC1_compareSelectRegisterList = [ADC1_CHCFG0_CMPSEL, ADC1_CHCFG1_CMPSEL, ADC1_CHCFG2_CMPSEL, ADC1_CHCFG3_CMPSEL, ADC1_CHCFG4_CMPSEL, ADC1_CHCFG5_CMPSEL, ADC1_CHCFG6_CMPSEL, ADC1_CHCFG7_CMPSEL, ADC1_CHCFG8_CMPSEL, ADC1_CHCFG9_CMPSEL, ADC1_CHCFG10_CMPSEL, ADC1_CHCFG11_CMPSEL, ADC1_CHCFG12_CMPSEL, ADC1_CHCFG13_CMPSEL, ADC1_CHCFG14_CMPSEL, ADC1_CHCFG15_CMPSEL, ADC1_CHCFG16_CMPSEL, ADC1_CHCFG17_CMPSEL, ADC1_CHCFG18_CMPSEL, ADC1_CHCFG19_CMPSEL]
ADC1_channelDurationList       = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]


ADC1_calibEnableRegisterList   = [0, ADC1_CALIB1_EN, 0, ADC1_CALIB3_EN, 0, ADC1_CALIB5_EN, 0, ADC1_CALIB7_EN, 0, ADC1_CALIB9_EN, 0, ADC1_CALIB11_EN, 0, ADC1_CALIB13_EN, 0, ADC1_CALIB15_EN, ADC1_CALIB16_EN, ADC1_CALIB17_EN, ADC1_CALIB18_EN, ADC1_CALIB19_EN, ADC1_CALIB20_EN, ADC1_CALIB20_EN, ADC1_CALIB21_EN, ADC1_CALIB22_EN, ADC1_CALIB23_EN, ADC1_CALIB24_EN, ADC1_CALIB25_EN, ADC1_CALIB26_EN]

ADC1_classCategoryVarList          = [ADC1_CONVCFG0_CTRY, ADC1_CONVCFG1_CTRY, ADC1_CONVCFG2_CTRY, ADC1_CONVCFG3_CTRY]
ADC1_classSTCRegisterList          = [ADC1_CONVCFG0_STC, ADC1_CONVCFG1_STC, ADC1_CONVCFG2_STC, ADC1_CONVCFG3_STC]
ADC1_classTCOSSelRegisterList      = [ADC1_CONVCFG0_TCOS, ADC1_CONVCFG1_TCOS, ADC1_CONVCFG2_TCOS, ADC1_CONVCFG3_TCOS]
ADC1_classTrackConvRegisterList    = [ADC1_CONVCFG0_TCONF, ADC1_CONVCFG1_TCONF, ADC1_CONVCFG2_TCONF, ADC1_CONVCFG3_TCONF]
ADC1_classOversamplingRegisterList = [ADC1_CONVCFG0_OVERS, ADC1_CONVCFG1_OVERS, ADC1_CONVCFG2_OVERS, ADC1_CONVCFG3_OVERS]
ADC1_classBWDRegisterList          = [ADC1_CONVCFG0_BWD, ADC1_CONVCFG1_BWD, ADC1_CONVCFG2_BWD, ADC1_CONVCFG3_BWD]
ADC1_classPostCalRegisterList      = [ADC1_CONVCFG0_PCAL, ADC1_CONVCFG1_PCAL, ADC1_CONVCFG2_PCAL, ADC1_CONVCFG3_PCAL]
ADC1_classMSBDoubleRegisterList    = [ADC1_CONVCFG0_MSBD, ADC1_CONVCFG1_MSBD, ADC1_CONVCFG2_MSBD, ADC1_CONVCFG3_MSBD]
ADC1_classSESPRegisterList         = [ADC1_CONVCFG0_SESP, ADC1_CONVCFG1_SESP, ADC1_CONVCFG2_SESP, ADC1_CONVCFG3_SESP]

ADC1_filterCoeffRegisterList   = [ADC1_FILTCFG_COEF_A0, ADC1_FILTCFG_COEF_A1, ADC1_FILTCFG_COEF_A2, ADC1_FILTCFG_COEF_A3]
ADC1_filterCoeffTextList       = ['1/2', '1/4', '1/8', '1/16']

ADC1_compareInputSelectList    = [ADC1_CMPCFG0_INSEL, ADC1_CMPCFG1_INSEL, ADC1_CMPCFG2_INSEL, ADC1_CMPCFG3_INSEL]
ADC1_compareModeSelRegisterList= [ADC1_CMPCFG0_MODE, ADC1_CMPCFG1_MODE, ADC1_CMPCFG2_MODE, ADC1_CMPCFG3_MODE]
ADC1_compareUpThSelRegisterList= [ADC1_UPPER_TH0, ADC1_UPPER_TH1, ADC1_UPPER_TH2, ADC1_UPPER_TH3]
ADC1_compareLoThSelRegisterList= [ADC1_LOWER_TH0, ADC1_LOWER_TH1, ADC1_LOWER_TH2, ADC1_LOWER_TH3]

ADC1_analogChannelNameList     = ['VS (3..25V)', 'VS (3..35V)', 'VDH (3..25V)', 'VDH (3..35V)', '', 'SH1 (Motor Contact 1)', '', 'SH2 (Motor Contact 2)', '', 'SH3 (Motor Contact 3)', 'MON1 (3..25V)', 'MON1 (3..35V)', 'MON2 (3..25V)', 'MON2 (3..35V)', 'MON3 (3..25V)', 'MON3 (3..35V)', 'Ref. Volt. 1.2V', 'VDDEXT', 'CSA', 'P2.0', 'P2.1', 'P2.7', 'P2.3', 'P2.4', 'P2.5', 'P2.6', 'P2.2'] 
ADC1_inBoxWidth                = [160, 160, 200, 200, 0, 300, 0, 300, 0, 300, 240, 240, 240, 240, 240, 240, 240, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160]

ADC1_seqSlotSelectRegisterList = [ADC1_SQSLOT0_CHSEL0, ADC1_SQSLOT0_CHSEL1, ADC1_SQSLOT0_CHSEL2, ADC1_SQSLOT0_CHSEL3, ADC1_SQSLOT1_CHSEL0, ADC1_SQSLOT1_CHSEL1, ADC1_SQSLOT1_CHSEL2, ADC1_SQSLOT1_CHSEL3, ADC1_SQSLOT2_CHSEL0, ADC1_SQSLOT2_CHSEL1, ADC1_SQSLOT2_CHSEL2, ADC1_SQSLOT2_CHSEL3, ADC1_SQSLOT3_CHSEL0, ADC1_SQSLOT3_CHSEL1, ADC1_SQSLOT3_CHSEL2, ADC1_SQSLOT3_CHSEL3]
ADC1_seqNbSlotsRegisterList    = [ADC1_SQCFG0_SLOTS, ADC1_SQCFG1_SLOTS, ADC1_SQCFG2_SLOTS, ADC1_SQCFG3_SLOTS]
ADC1_seqTimesList              = [ADC1_S0_TIMES, ADC1_S1_TIMES, ADC1_S2_TIMES, ADC1_S3_TIMES]


def ADC1_calConvTicks(channelTabIdx):
    classIdx = int(ADC1_classSelectRegisterList[channelTabIdx].currentData)
    if (classIdx < 4):
        tBWD = int(ADC1_classBWDRegisterList[classIdx].currentText)
        tSAMP = int(ADC1_classSTCRegisterList[classIdx].currentText) + 2
        tCONV = 17 + int(ADC1_classMSBDoubleRegisterList[classIdx].checked)
        tNR = 8 * int(ADC1_classTrackConvRegisterList[classIdx].currentText) + tCONV * int(ADC1_classOversamplingRegisterList[classIdx].currentText)
        tPC = 10 * int(ADC1_classPostCalRegisterList[classIdx].checked)
        kernelTicks = tBWD + tSAMP + tCONV + tNR + tPC
    else:
        kernelTicks = 0
    return kernelTicks
    
def ADC1_calcKernelTime(channelTabIdx):
    fADC1 = float(ADC1_CLK.text.partition(' ')[0])
    classIdx = int(ADC1_classSelectRegisterList[channelTabIdx].currentData)
    if (classIdx < 4):
        kernelTicks = ADC1_calConvTicks(channelTabIdx) * ADC1_channelRepRegisterList[channelTabIdx].value
        kernelTime = format(kernelTicks / fADC1, '.4f')
    else:
        kernelTime = 0.0
    return kernelTime

def ADC1_calcResultTicks(channelTabIdx):
    classIdx = int(ADC1_classSelectRegisterList[channelTabIdx].currentData)
    if (classIdx < 4):
        if (ADC1_calibEnableRegisterList[int(ADC1_inputSelectRegisterList[channelTabIdx].currentData)] == 0):
            in2resTicks_single = ADC1_calConvTicks(channelTabIdx)
        else:
            if (ADC1_calibEnableRegisterList[int(ADC1_inputSelectRegisterList[channelTabIdx].currentData)].checked == 1):
                in2resTicks_single = ADC1_calConvTicks(channelTabIdx) + ADC1_CALIB_TICKS
            else:
                in2resTicks_single = ADC1_calConvTicks(channelTabIdx)
    else:
        in2resTicks_single = 0
    return in2resTicks_single

def ADC1_calcResultTime(channelTabIdx):
    fADC1 = float(ADC1_CLK.text.partition(' ')[0])
    in2resTicks_single = ADC1_calcResultTicks(channelTabIdx)
    in2resTime = format(float(in2resTicks_single * ADC1_channelRepRegisterList[channelTabIdx].value / fADC1), '.4f')
    return in2resTime

def ADC1_calcFilterTicks(channelTabIdx):
    classIdx = int(ADC1_classSelectRegisterList[channelTabIdx].currentData)
    if (classIdx < 4):
        in2filtTicks_single = ADC1_calcResultTicks(channelTabIdx) + ADC1_FILT_TICKS
    else:
        in2filtTicks_single = 0
    return in2filtTicks_single

def ADC1_calcFilterTime(channelTabIdx):
    fADC1 = float(ADC1_CLK.text.partition(' ')[0])
    in2filtTicks_single = ADC1_calcFilterTicks(channelTabIdx)
    in2filtTime = format(float(in2filtTicks_single * ADC1_channelRepRegisterList[channelTabIdx].value / fADC1), '.4f')
    return in2filtTime

def ADC1_calcCompareTicks(channelTabIdx):
    classIdx = int(ADC1_classSelectRegisterList[channelTabIdx].currentData)
    if (classIdx < 4):
        in2resTicks_single = ADC1_calcResultTicks(channelTabIdx)
        in2filtTicks_single = ADC1_calcFilterTicks(channelTabIdx)
        if (int(ADC1_filterSelectRegisterList[channelTabIdx].currentData) == 4):
            # Only compare
            in2cmpTicks_single = in2resTicks_single + ADC1_CMP_TICKS
        else:
            # Filter + compare
            in2cmpTicks_single = in2filtTicks_single + ADC1_CMP_TICKS
    else:
        in2cmpTicks_single = 0
    return in2cmpTicks_single

def ADC1_calcCompareTime(channelTabIdx):
    fADC1 = float(ADC1_CLK.text.partition(' ')[0])
    in2cmpTicks_single = ADC1_calcCompareTicks(channelTabIdx)
    in2cmpTime = format(float(in2cmpTicks_single * ADC1_channelRepRegisterList[channelTabIdx].value / fADC1), '.4f')
    return in2cmpTime

def ADC1_changeFreq(idx):
    channelTabIdx = ADC1_CHNCFGCONT.currentIndex
    # Update timings
    for i in range(ADC1_DIGITAL_CHANNEL_MAX):
        if i == channelTabIdx:
            ADC1_calcTimesChx(i)
        else:
            filtIdx = int(ADC1_filterSelectRegisterList[i].currentData)
            cmpIdx = int(ADC1_compareSelectRegisterList[i].currentData)
            if (filtIdx == 4) and (cmpIdx == 4):
                ADC1_channelDurationList[i] = format(float(ADC1_calcResultTime(i)), '.4f')
            else:
                if (filtIdx != 4) and (cmpIdx == 4):
                    ADC1_channelDurationList[i] = format(float(ADC1_calcFilterTime(i)), '.4f')
                else:
                    ADC1_channelDurationList[i] = format(float(ADC1_calcCompareTime(i)), '.4f')
    application.runScript('setDef(ADC1.ADBlock.update=1)')
    # Update sequencer timings
    ADC1_calcTimesSeq()
    
def ADC1_calcTimesChx(channelTabIdx):
    ADC1_TIME_KERNEL.text = str(ADC1_calcKernelTime(channelTabIdx))
    ADC1_TIME_IN2RES.text = str(ADC1_calcResultTime(channelTabIdx))
    ADC1_TIME_IN2FILT.text = str(ADC1_calcFilterTime(channelTabIdx))
    ADC1_TIME_IN2CMP.text = str(ADC1_calcCompareTime(channelTabIdx))
    if (int(ADC1_filterSelectRegisterList[channelTabIdx].currentData) == 4) and (int(ADC1_compareSelectRegisterList[channelTabIdx].currentData) == 4):
        ADC1_channelDurationList[channelTabIdx] = format(float(ADC1_TIME_IN2RES.text), '.4f')
    else:
        if (int(ADC1_filterSelectRegisterList[channelTabIdx].currentData) != 4) and (int(ADC1_compareSelectRegisterList[channelTabIdx].currentData) == 4):
            ADC1_channelDurationList[channelTabIdx] = format(float(ADC1_TIME_IN2FILT.text), '.4f')
        else:
            ADC1_channelDurationList[channelTabIdx] = format(float(ADC1_TIME_IN2CMP.text), '.4f')
    application.runScript('setDef(ADC1.ADBlock.update=1)')        
    return float(ADC1_channelDurationList[channelTabIdx])

def ADC1_calcTimesSeq():
    cnt = 0
    all_times = 0
    for i in range(4):
        for j in range(4):
            if (int(ADC1_seqSlotSelectRegisterList[4 * i + j].currentData) != 20) and (ADC1_tabConfiguredList[int(ADC1_seqSlotSelectRegisterList[4 * i + j].currentData)] != 0):
                all_times += float(ADC1_channelDurationList[int(ADC1_seqSlotSelectRegisterList[4 * i + j].currentData)])
        ADC1_seqTimesList[i].text = format(all_times, '.4f')
        all_times = 0
    application.runScript('setDef(ADC1.SQBlock.update=1)')

def ADC1_onChannelTabChange(channelTabIdx):
    ADC1_RES_NO.text = str(channelTabIdx)
    # Set the channel as configured
    ADC1_tabConfiguredList[channelTabIdx] = 1
    # Set input according to channel config + calibration settings accordingly
    ADC1_inputCalibSelect(channelTabIdx, ADC1_inputSelectRegisterList[channelTabIdx])
    # Set class tab according to channel config
    ADC1_classSelect(channelTabIdx, ADC1_classSelectRegisterList[channelTabIdx])
    # Set filter tab according to channel config
    ADC1_filtSelect(channelTabIdx, ADC1_filterSelectRegisterList[channelTabIdx])
    # Set compare tab according to channel config
    ADC1_cmpSelect(channelTabIdx, ADC1_compareSelectRegisterList[channelTabIdx])
    # Calculate timings
    ADC1_calcTimesChx(channelTabIdx)
    # Update sequencer timings
    ADC1_calcTimesSeq()
    # Update the Sequencer diagram if needed
    ADC1_updateSeqWithConfig(channelTabIdx)
    application.runScript('setDef(ADC1.SQBlock.update=1)')

def ADC1_inputCalibSelect(channelTabIdx, reg):
    if (channelTabIdx < ADC1_DIGITAL_CHANNEL_MAX):
        inputIdx = int(reg.currentData)
        if (inputIdx < ADC1_ANALOG_CHANNEL_MAX):
            ADC1_CH_NAME.text = ADC1_analogChannelNameList[int(reg.currentData)]
            ADC1_INBOX_WIDTH.value = ADC1_inBoxWidth[int(reg.currentData)]
            # Select the attenuator
            analogChVal = int(ADC1_inputSelectRegisterList[channelTabIdx].currentData)
            ADC1_attenuatorVarList[channelTabIdx].value = ADC1_attenuatorValList[analogChVal]
        # Enable the calibration tab if necessary
        if (ADC1_calibEnableRegisterList[inputIdx] == 0):
            application.runScript('setDef(ADC1.CALIBCONT_NA.visible=1)')
            for idx in range(ADC1_ANALOG_CHANNEL_MAX):
                if (ADC1_calibEnableRegisterList[idx] != 0):
                    application.runScript('setDef(ADC1.CALIBCONT_AI' + str(idx) + '.visible=0)')
            ADC1_USE_CALIBx.value = 0
        else:
            application.runScript('setDef(ADC1.CALIBCONT_AI' + str(inputIdx) + '.visible=1)')
            application.runScript('setDef(ADC1.CALIBCONT_NA.visible=0)')
            for idx in range(ADC1_ANALOG_CHANNEL_MAX):
                if (idx != inputIdx) and (ADC1_calibEnableRegisterList[idx] != 0):
                    application.runScript('setDef(ADC1.CALIBCONT_AI' + str(idx) + '.visible=0)')
            if (int(ADC1_calibEnableRegisterList[inputIdx].checked) == 1):
                ADC1_USE_CALIBx.value = 1
            else:
                ADC1_USE_CALIBx.value = 0
    
def ADC1_classSelect(channelTabIdx, reg):
    if (channelTabIdx < ADC1_DIGITAL_CHANNEL_MAX):
        classIdx = int(reg.currentData)
        if (classIdx < 4):
            application.runScript('SetTab(ADC1.CHCLASSCONT, ' + str(classIdx) + ')')
            ADC1_CHCLS_NO.value = classIdx
            ADC1_CHCLS_CTRY.text = ADC1_classCategoryVarList[classIdx].text
            if ADC1_classTCOSSelRegisterList[classIdx].text == '0':
                ADC1_classOversamplingRegisterList[classIdx].currentIndex = 0
                if ADC1_classTrackConvRegisterList[classIdx].currentText == '0':
                    ADC1_TCOS_TXT.text = '---'
                else:
                    ADC1_TCOS_TXT.text = 'TC' + ADC1_classTrackConvRegisterList[classIdx].currentText
            elif ADC1_classTCOSSelRegisterList[classIdx].text == '1':
                ADC1_classTrackConvRegisterList[classIdx].currentIndex = 0
                if ADC1_classOversamplingRegisterList[classIdx].currentText == '0':
                    ADC1_TCOS_TXT.text = '---'
                else:
                    ADC1_TCOS_TXT.text = 'OS' + ADC1_classOversamplingRegisterList[classIdx].currentText
            ADC1_STC_TXT.text = ADC1_classSTCRegisterList[classIdx].currentText
            if ADC1_classBWDRegisterList[classIdx].currentText == '0':
                ADC1_BWD_TXT.text = '---'
            else:
                ADC1_BWD_TXT.text = 'BW' + ADC1_classBWDRegisterList[classIdx].currentText
            if int(ADC1_classPostCalRegisterList[classIdx].checked) == 0:
                ADC1_PC_TXT.text = '---'
            else:
                ADC1_PC_TXT.text = 'PC'
            if int(ADC1_classMSBDoubleRegisterList[classIdx].checked) == 0:
                ADC1_MSBD_TXT.text = '---'
            else:
                ADC1_MSBD_TXT.text = 'MSBD'
            if int(ADC1_classSESPRegisterList[classIdx].checked) == 0:
                ADC1_SESP_TXT.text = '---'
            else:
                ADC1_SESP_TXT.text = 'SESP'
        
def ADC1_filtSelect(channelTabIdx, reg):
    if (channelTabIdx < ADC1_DIGITAL_CHANNEL_MAX):
        filtIdx = int(reg.currentData)
        if (filtIdx < 4):
            # Select the corresponding filter tab
            application.runScript('SetTab(ADC1.FILTCHCONT, ' + str(filtIdx) + ')')
            ADC1_FILT_NO.value = filtIdx
            ADC1_FILT_TXT.text = ADC1_filterCoeffTextList[ADC1_filterCoeffRegisterList[filtIdx].currentIndex]
            ADC1_USE_FILTx.value = 1
            application.runScript('SetDef(ADC1.FILT' + str(filtIdx) + '_USED_BY_TXT=' + str(channelTabIdx) + ')')
            application.runScript('SetDef(ADC1.FILT' + str(filtIdx) + 'CONT.enabled=1)')
        else:
            ADC1_USE_FILTx.value = 0
            for idx in range(4):
                if idx not in [x.currentIndex for x in ADC1_filterSelectRegisterList]:
                    application.runScript('SetDef(ADC1.FILT' + str(idx) + '_USED_BY_TXT=not assigned)')
                    application.runScript('SetDef(ADC1.FILT' + str(idx) + 'CONT.enabled=0)')
            
def ADC1_cmpSelect(channelTabIdx, reg):
    if (channelTabIdx < ADC1_DIGITAL_CHANNEL_MAX):
        cmpIdx = int(reg.currentData)
        if (cmpIdx < 4):
            # Select the corresponding compare tab
            application.runScript('SetTab(ADC1.CMPCHCONT, ' + str(cmpIdx) + ')')
            ADC1_CMP_NO.value = int(reg.currentData)
            if ADC1_compareModeSelRegisterList[cmpIdx].currentIndex == 0:
                ADC1_CMP_MODE_TXT.text = 'OV/UV'
            elif ADC1_compareModeSelRegisterList[cmpIdx].currentIndex == 1:
                ADC1_CMP_MODE_TXT.text = 'UV'
            elif ADC1_compareModeSelRegisterList[cmpIdx].currentIndex == 2:
                ADC1_CMP_MODE_TXT.text = 'OV'
            ADC1_CMP_UTH_TXT.text = ADC1_compareUpThSelRegisterList[cmpIdx].text
            ADC1_CMP_LTH_TXT.text = ADC1_compareLoThSelRegisterList[cmpIdx].text
            ADC1_CMP_SRCx.value = int(ADC1_compareInputSelectList[cmpIdx].text)
            ADC1_USE_CMPx.value = 1
            application.runScript('SetDef(ADC1.CMP' + str(cmpIdx) + '_TXT=' + str(channelTabIdx) + ')')
            application.runScript('SetDef(ADC1.CMP' + str(cmpIdx) + 'CONT.enabled=1)')
        else:
            ADC1_USE_CMPx.value = 0
            # Reset the compare interrupts so that they are not enabled and the corresponding node is not locked
            idxCmpList = [x.currentData for  x in ADC1_compareSelectRegisterList]
            if '0' not in idxCmpList:
                # If the compare channel is not assigned
                application.runScript('SetDef(ADC1.UPTH0_INT_EN=0)')
                application.runScript('SetDef(ADC1.IEN0.IEN_UP0=0)')
                application.runScript('SetDef(ADC1.LOTH0_INT_EN=0)')
                application.runScript('SetDef(ADC1.IEN0.IEN_LO0=0)')
            if '1' not in idxCmpList:
                # If the compare channel is not assigned
                application.runScript('SetDef(ADC1.UPTH1_INT_EN=0)')
                application.runScript('SetDef(ADC1.IEN0.IEN_UP1=0)')
                application.runScript('SetDef(ADC1.LOTH1_INT_EN=0)')
                application.runScript('SetDef(ADC1.IEN0.IEN_LO1=0)')
            if '2' not in idxCmpList:
                # If the compare channel is not assigned
                application.runScript('SetDef(ADC1.UPTH2_INT_EN=0)')
                application.runScript('SetDef(ADC1.IEN0.IEN_UP2=0)')
                application.runScript('SetDef(ADC1.LOTH2_INT_EN=0)')
                application.runScript('SetDef(ADC1.IEN0.IEN_LO2=0)')
            if '3' not in idxCmpList:
                # If the compare channel is not assigned
                application.runScript('SetDef(ADC1.UPTH3_INT_EN=0)')
                application.runScript('SetDef(ADC1.IEN0.IEN_UP3=0)')
                application.runScript('SetDef(ADC1.LOTH3_INT_EN=0)')
                application.runScript('SetDef(ADC1.IEN0.IEN_LO3=0)')
            for idx in range(4):
                if idx not in [x.currentIndex for x in ADC1_compareSelectRegisterList]:
                    application.runScript('SetDef(ADC1.CMP' + str(idx) + '_TXT=not assigned)')
                    application.runScript('SetDef(ADC1.CMP' + str(idx) + 'CONT.enabled=0)')

def ADC1_onCalibEn(state):
    # Get channel number, equivalent to tab number
    channelTabIdx = ADC1_CHNCFGCONT.currentIndex
    if (state == 0):
        ADC1_USE_CALIBx.value = 0
    else:
        ADC1_USE_CALIBx.value = 1
    # Update timing for filter
    ADC1_calcTimesChx(channelTabIdx)
    # Update sequencer timings
    ADC1_calcTimesSeq()

def ADC1_inputSelectChx(analogChIdx):
    # Get channel number, equivalent to tab number
    channelTabIdx = ADC1_CHNCFGCONT.currentIndex
    # Select the analog channel index given as argument
    ADC1_inputSelectRegisterList[channelTabIdx].currentIndex = analogChIdx
    analogChVal = int(ADC1_inputSelectRegisterList[channelTabIdx].currentData)
    # Select the attenuator
    ADC1_attenuatorVarList[channelTabIdx].value = ADC1_attenuatorValList[analogChVal]
    # Adjust the box width
    ADC1_INBOX_WIDTH.value = ADC1_inBoxWidth[analogChVal]
    # Update the graph with the channel name
    ADC1_CH_NAME.text = ADC1_analogChannelNameList[analogChVal]
    # Enable calibration settings if necessary
    if (ADC1_calibEnableRegisterList[analogChVal] == 0):
        application.runScript('setDef(ADC1.CALIBCONT_NA.visible=1)')
        for idx in range(ADC1_ANALOG_CHANNEL_MAX):
            if (ADC1_calibEnableRegisterList[idx] != 0):
                application.runScript('setDef(ADC1.CALIBCONT_AI' + str(idx) + '.visible=0)')
        ADC1_USE_CALIBx.value = 0
    else:
        application.runScript('setDef(ADC1.CALIBCONT_AI' + str(analogChVal) + '.visible=1)')
        application.runScript('setDef(ADC1.CALIBCONT_NA.visible=0)')
        for idx in range(ADC1_ANALOG_CHANNEL_MAX):
            if (idx != analogChVal) and (ADC1_calibEnableRegisterList[idx] != 0):
                application.runScript('setDef(ADC1.CALIBCONT_AI' + str(idx) + '.visible=0)')
        if (int(ADC1_calibEnableRegisterList[analogChVal].checked) == 1):
            ADC1_USE_CALIBx.value = 1
        else:
            ADC1_USE_CALIBx.value = 0
    application.runScript('setDef(ADC1.ADBlock.update=1)')
    # Update the Sequencer diagram if needed
    ADC1_updateSeqWithConfig(channelTabIdx)
    
def ADC1_repSelectChx(repValue):
    # Get channel number, equivalent to tab number
    channelTabIdx = ADC1_CHNCFGCONT.currentIndex
    # Update timing for filter
    ADC1_calcTimesChx(channelTabIdx)
    # Update sequencer timings
    ADC1_calcTimesSeq()

def ADC1_classSelectChx(itemIdx):
    channelTabIdx = ADC1_CHNCFGCONT.currentIndex
    # Select the relevant class tab
    application.runScript('SetTab(ADC1.CHCLASSCONT, ' + str(itemIdx) + ')')
    # Update the graph with the class number, category and stc
    ADC1_CHCLS_NO.value = itemIdx
    ADC1_CHCLS_CTRY.text = ADC1_classCategoryVarList[itemIdx].text
    if ADC1_classTCOSSelRegisterList[itemIdx].text == '0':
        ADC1_classOversamplingRegisterList[itemIdx].currentIndex = 0
        if ADC1_classTrackConvRegisterList[itemIdx].currentText == '0':
            ADC1_TCOS_TXT.text = '---'
        else:
            ADC1_TCOS_TXT.text = 'TC' + ADC1_classTrackConvRegisterList[itemIdx].currentText
    elif ADC1_classTCOSSelRegisterList[itemIdx].text == '1':
        ADC1_classTrackConvRegisterList[itemIdx].currentIndex = 0
        if ADC1_classOversamplingRegisterList[itemIdx].currentText == '0':
            ADC1_TCOS_TXT.text = '---'
        else:
            ADC1_TCOS_TXT.text = 'OS' + ADC1_classOversamplingRegisterList[itemIdx].currentText
    ADC1_STC_TXT.text = ADC1_classSTCRegisterList[itemIdx].currentText
    if ADC1_classBWDRegisterList[itemIdx].currentText == '0':
        ADC1_BWD_TXT.text = '---'
    else:
        ADC1_BWD_TXT.text = 'BW' + ADC1_classBWDRegisterList[itemIdx].currentText
    if int(ADC1_classPostCalRegisterList[itemIdx].checked) == 0:
        ADC1_PC_TXT.text = '---'
    else:
        ADC1_PC_TXT.text = 'PC'
    if int(ADC1_classMSBDoubleRegisterList[itemIdx].checked) == 0:
        ADC1_MSBD_TXT.text = '---'
    else:
        ADC1_MSBD_TXT.text = 'MSBD'
    if int(ADC1_classSESPRegisterList[itemIdx].checked) == 0:
        ADC1_SESP_TXT.text = '---'
    else:
        ADC1_SESP_TXT.text = 'SESP'
    # Update timing for filter
    ADC1_calcTimesChx(channelTabIdx)
    # Update sequencer timings
    ADC1_calcTimesSeq()

def ADC1_changeConvClassCat(txt):
    ADC1_CHCLS_CTRY.text = txt
    application.runScript('setDef(ADC1.ADBlock.update=1)')
    
def ADC1_TCOSSelectChx(itemIdx):
    # Get channel number, equivalent to tab number
    channelTabIdx = ADC1_CHNCFGCONT.currentIndex
    # Get class channel index
    classTabIdx = ADC1_CHCLASSCONT.currentIndex
    if (ADC1_classSelectRegisterList[channelTabIdx].currentIndex == classTabIdx):
        if ADC1_classTCOSSelRegisterList[classTabIdx].text == '0':
            ADC1_classOversamplingRegisterList[classTabIdx].currentIndex = 0
            if ADC1_classTrackConvRegisterList[classTabIdx].currentText == '0':
                ADC1_TCOS_TXT.text = '---'
            else:
                ADC1_TCOS_TXT.text = 'TC' + ADC1_classTrackConvRegisterList[classTabIdx].currentText
        elif ADC1_classTCOSSelRegisterList[classTabIdx].text == '1':
            ADC1_classTrackConvRegisterList[classTabIdx].currentIndex = 0
            if ADC1_classOversamplingRegisterList[classTabIdx].currentText == '0':
                ADC1_TCOS_TXT.text = '---'
            else:
                ADC1_TCOS_TXT.text = 'OS' + ADC1_classOversamplingRegisterList[classTabIdx].currentText
        # Update timings
        ADC1_calcTimesChx(channelTabIdx)
        # Update sequencer timings
        ADC1_calcTimesSeq()
    
def ADC1_STCSelectChx(itemIdx):
    # Get channel number, equivalent to tab number
    channelTabIdx = ADC1_CHNCFGCONT.currentIndex
    # Get class channel index
    classTabIdx = ADC1_CHCLASSCONT.currentIndex
    if (ADC1_classSelectRegisterList[channelTabIdx].currentIndex == classTabIdx):
        ADC1_STC_TXT.text = ADC1_classSTCRegisterList[classTabIdx].currentText
        # Update timings
        ADC1_calcTimesChx(channelTabIdx)
        # Update sequencer timings
        ADC1_calcTimesSeq()

def ADC1_BWDSelectChx(itemIdx):
    # Get channel number, equivalent to tab number
    channelTabIdx = ADC1_CHNCFGCONT.currentIndex
    # Get class channel index
    classTabIdx = ADC1_CHCLASSCONT.currentIndex
    if (ADC1_classSelectRegisterList[channelTabIdx].currentIndex == classTabIdx):
        if ADC1_classBWDRegisterList[classTabIdx].currentText == '0':
            ADC1_BWD_TXT.text = '---'
        else:
            ADC1_BWD_TXT.text = 'BW' + ADC1_classBWDRegisterList[classTabIdx].currentText
        # Update timings
        ADC1_calcTimesChx(channelTabIdx)
        # Update sequencer timings
        ADC1_calcTimesSeq()

def ADC1_PostCalSelectChx(itemIdx):
    # Get channel number, equivalent to tab number
    channelTabIdx = ADC1_CHNCFGCONT.currentIndex
    # Get class channel index
    classTabIdx = ADC1_CHCLASSCONT.currentIndex
    if (ADC1_classSelectRegisterList[channelTabIdx].currentIndex == classTabIdx):
        if int(ADC1_classPostCalRegisterList[classTabIdx].checked) == 0:
            ADC1_PC_TXT.text = '---'
        else:
            ADC1_PC_TXT.text = 'PC'
        # Update timings
        ADC1_calcTimesChx(channelTabIdx)
        # Update sequencer timings
        ADC1_calcTimesSeq()

def ADC1_MSBDSelectChx(itemIdx):
    # Get channel number, equivalent to tab number
    channelTabIdx = ADC1_CHNCFGCONT.currentIndex
    # Get class channel index
    classTabIdx = ADC1_CHCLASSCONT.currentIndex
    if (ADC1_classSelectRegisterList[channelTabIdx].currentIndex == classTabIdx):
        if int(ADC1_classMSBDoubleRegisterList[classTabIdx].checked) == 0:
            ADC1_MSBD_TXT.text = '---'
        else:
            ADC1_MSBD_TXT.text = 'MSBD'
        # Update timings
        ADC1_calcTimesChx(channelTabIdx)
        # Update sequencer timings
        ADC1_calcTimesSeq()

def ADC1_SESPSelectChx(itemIdx):
    # Get channel number, equivalent to tab number
    channelTabIdx = ADC1_CHNCFGCONT.currentIndex
    # Get class channel index
    classTabIdx = ADC1_CHCLASSCONT.currentIndex
    if (ADC1_classSelectRegisterList[channelTabIdx].currentIndex == classTabIdx):
        if int(ADC1_classSESPRegisterList[classTabIdx].checked) == 0:
            ADC1_SESP_TXT.text = '---'
        else:
            ADC1_SESP_TXT.text = 'SESP'
        # Update timings
        ADC1_calcTimesChx(channelTabIdx)
        # Update sequencer timings
        ADC1_calcTimesSeq()

def ADC1_filtSelectChx(itemIdx):
    # Get channel number, equivalent to tab number
    channelTabIdx = ADC1_CHNCFGCONT.currentIndex
    # Get filter index
    filterIndexList = [int(x.currentData) for x in ADC1_filterSelectRegisterList]
    if (itemIdx != 4) and (filterIndexList.count(itemIdx) > 1):
        # The filter is already in use, it must be reset to 'none'
        application.runScript('MessageBox(Filter ' + str(itemIdx) + ' already in use in channel ' + str(filterIndexList.index(itemIdx)) + ' !)')
        ADC1_filterSelectRegisterList[channelTabIdx].currentIndex = 4
    else:
        ADC1_filtSelect(channelTabIdx, ADC1_filterSelectRegisterList[channelTabIdx])
    # Update timings
    ADC1_calcTimesChx(channelTabIdx)
    # Update sequencer timings
    ADC1_calcTimesSeq()

def ADC1_filtCoeffSelChx(coeffIdx):
    ADC1_FILT_TXT.text = ADC1_filterCoeffTextList[coeffIdx]
    application.runScript('setDef(ADC1.ADBlock.update=1)')

def ADC1_cmpSelectChx(itemIdx):
    # Get channel number, equivalent to tab number
    channelTabIdx = ADC1_CHNCFGCONT.currentIndex
    # Get compare index
    compareIndexList = [int(x.currentData) for x in ADC1_compareSelectRegisterList]
    if (itemIdx != 4) and (compareIndexList.count(itemIdx) > 1):
        # The compare channel is already in use, it must be reset to 'none'
        application.runScript('MessageBox(Compare Channel ' + str(itemIdx) + ' already in use in channel ' + str(compareIndexList.index(itemIdx)) + ' !)')
        ADC1_compareSelectRegisterList[channelTabIdx].currentIndex = 4
    else:
        ADC1_cmpSelect(channelTabIdx, ADC1_compareSelectRegisterList[channelTabIdx])
    # Update timings
    ADC1_calcTimesChx(channelTabIdx)
    # Update sequencer timings
    ADC1_calcTimesSeq()

def ADC1_cmpInputSelChx(txt):
    # Get channel number, equivalent to tab number
    channelTabIdx = ADC1_CHNCFGCONT.currentIndex
    # Get compare tab index
    cmpTabIdx = ADC1_CMPCHCONT.currentIndex
    # Get compare channel index
    cmpIdx = int(ADC1_compareSelectRegisterList[channelTabIdx].currentData)
    if (cmpIdx == cmpTabIdx):
        ADC1_CMP_SRCx.value = int(txt)
        # Update timings
        ADC1_calcTimesChx(channelTabIdx)
        # Update sequencer timings
        ADC1_calcTimesSeq()

def ADC1_cmpModeSelChx(mode):
    # Get channel number, equivalent to tab number
    channelTabIdx = ADC1_CHNCFGCONT.currentIndex
    # Get compare tab index
    cmpTabIdx = ADC1_CMPCHCONT.currentIndex
    # Get compare channel index
    cmpIdx = int(ADC1_compareSelectRegisterList[channelTabIdx].currentData)
    if (cmpIdx == cmpTabIdx):
        if ADC1_compareModeSelRegisterList[cmpIdx].currentIndex == 0:
            ADC1_CMP_MODE_TXT.text = 'OV/UV'
        elif ADC1_compareModeSelRegisterList[cmpIdx].currentIndex == 1:
            ADC1_CMP_MODE_TXT.text = 'UV'
        elif ADC1_compareModeSelRegisterList[cmpIdx].currentIndex == 2:
            ADC1_CMP_MODE_TXT.text = 'OV'
        application.runScript('setDef(ADC1.ADBlock.update=1)')
    
def ADC1_cmpUpThSelChx(value):
    # Get channel number, equivalent to tab number
    channelTabIdx = ADC1_CHNCFGCONT.currentIndex
    # Get compare tab index
    cmpTabIdx = ADC1_CMPCHCONT.currentIndex
    # Get compare channel index
    cmpIdx = int(ADC1_compareSelectRegisterList[channelTabIdx].currentData)
    if (cmpIdx == cmpTabIdx):
        ADC1_CMP_UTH_TXT.text = ADC1_compareUpThSelRegisterList[cmpIdx].text
        application.runScript('setDef(ADC1.ADBlock.update=1)')
    
def ADC1_cmpLoThSelChx(value):
    # Get channel number, equivalent to tab number
    channelTabIdx = ADC1_CHNCFGCONT.currentIndex
    # Get compare tab index
    cmpTabIdx = ADC1_CMPCHCONT.currentIndex
    # Get compare channel index
    cmpIdx = int(ADC1_compareSelectRegisterList[channelTabIdx].currentData)
    if (cmpIdx == cmpTabIdx):
        ADC1_CMP_LTH_TXT.text = ADC1_compareLoThSelRegisterList[cmpIdx].text
        application.runScript('setDef(ADC1.ADBlock.update=1)')

def ADC1_updateSeqWithConfig(channelTabIdx):  
    for idx, seqslot in enumerate(ADC1_seqSlotSelectRegisterList):
        if int(seqslot.currentData) == channelTabIdx:
            application.runScript('setDef(ADC1.S' + str(int(idx/4)) + 'S' + str(idx%4) + '_BOXCOLOR=CCE9AD)')
            application.runScript('setDef(ADC1.S' + str(int(idx/4)) + 'S' + str(idx%4) + '_CH=Channel ' + seqslot.currentData + ')')
            application.runScript('setDef(ADC1.S' + str(int(idx/4)) + 'S' + str(idx%4) + '_NAME_TXT=' + ADC1_analogChannelNameList[int(ADC1_inputSelectRegisterList[int(seqslot.currentData)].currentData)] + ')')
        
    application.runScript('setDef(ADC1.SQBlock.update=1)')

def ADC1_nbSlotSelSeqx(nbSlot):
    # Get sequence number, equivalent to tab number
    seqTabIdx = ADC1_SEQCONT.currentIndex
    if (nbSlot <= 4):
        for idx in range(nbSlot):
            if int(ADC1_seqSlotSelectRegisterList[4 * seqTabIdx + idx].currentData) == 20:
                # Configure the additional slots as active
                application.runScript('setDef(ADC1.SQSLOT' + str(seqTabIdx) + '.CHSEL' + str(idx) + '.enabled=1)')
                application.runScript('setDef(ADC1.S' + str(seqTabIdx) + 'S' + str(idx) + '_COLOR=000000)')
                application.runScript('setDef(ADC1.S' + str(seqTabIdx) + 'S' + str(idx) + '_BOXCOLOR=FFC90E)')
                application.runScript('setDef(ADC1.S' + str(seqTabIdx) + 'S' + str(idx) + '_CH=No channel)')
                application.runScript('setDef(ADC1.S' + str(seqTabIdx) + 'S' + str(idx) + '_NAME_TXT=selected)')
        for idx in range(4 - nbSlot):
            # Consider the removed slots as inactive
            application.runScript('setDef(ADC1.SQSLOT' + str(seqTabIdx) + '.CHSEL' + str(nbSlot + idx) + '.enabled=0)')
            application.runScript('setDef(ADC1.SQSLOT' + str(seqTabIdx) + '.CHSEL' + str(nbSlot + idx) + '=20)')
            application.runScript('setDef(ADC1.S' + str(seqTabIdx) + 'S' + str(nbSlot + idx) + '_COLOR=F1F1F1)')
            application.runScript('setDef(ADC1.S' + str(seqTabIdx) + 'S' + str(nbSlot + idx) + '_BOXCOLOR=F1F1F1)')
    application.runScript('setDef(ADC1.SQBlock.update=1)')
    
def ADC1_slotSelSeqx(channelIdx):
    # Get sequence number, equivalent to tab number
    seqTabIdx = ADC1_SEQCONT.currentIndex
    # Get number of enabled slots
    nbSlots = int(ADC1_seqNbSlotsRegisterList[seqTabIdx].currentData)
    if (channelIdx < ADC1_DIGITAL_CHANNEL_MAX):
        for idx in range(nbSlots):
            if int(ADC1_seqSlotSelectRegisterList[4 * seqTabIdx + idx].currentData) == 20:
                application.runScript('setDef(ADC1.S' + str(seqTabIdx) + 'S' + str(idx) + '_COLOR=000000)')
                application.runScript('setDef(ADC1.S' + str(seqTabIdx) + 'S' + str(idx) + '_BOXCOLOR=FFC90E)')
                application.runScript('setDef(ADC1.S' + str(seqTabIdx) + 'S' + str(idx) + '_CH=No channel)')
                application.runScript('setDef(ADC1.S' + str(seqTabIdx) + 'S' + str(idx) + '_NAME_TXT=selected)')
            else:
                if ADC1_tabConfiguredList[int(ADC1_seqSlotSelectRegisterList[4 * seqTabIdx + idx].currentData)] == 0:
                    application.runScript('setDef(ADC1.S' + str(seqTabIdx) + 'S' + str(idx) + '_COLOR=000000)')
                    application.runScript('setDef(ADC1.S' + str(seqTabIdx) + 'S' + str(idx) + '_BOXCOLOR=FFC90E)')
                    application.runScript('setDef(ADC1.S' + str(seqTabIdx) + 'S' + str(idx) + '_CH=Channel ' + ADC1_seqSlotSelectRegisterList[4 * seqTabIdx + idx].currentData + ')')
                    application.runScript('setDef(ADC1.S' + str(seqTabIdx) + 'S' + str(idx) + '_NAME_TXT=not configured yet)')
                else:
                    application.runScript('setDef(ADC1.S' + str(seqTabIdx) + 'S' + str(idx) + '_COLOR=000000)')
                    application.runScript('setDef(ADC1.S' + str(seqTabIdx) + 'S' + str(idx) + '_BOXCOLOR=CCE9AD)')
                    application.runScript('setDef(ADC1.S' + str(seqTabIdx) + 'S' + str(idx) + '_CH=Channel ' + ADC1_seqSlotSelectRegisterList[4 * seqTabIdx + idx].currentData + ')')
                    application.runScript('setDef(ADC1.S' + str(seqTabIdx) + 'S' + str(idx) + '_NAME_TXT=' + ADC1_analogChannelNameList[int(ADC1_inputSelectRegisterList[int(ADC1_seqSlotSelectRegisterList[4 * seqTabIdx + idx].currentData)].currentData)] + ')')
    # In the case 'none' is selected
    if channelIdx == 20:
        for idx in range(nbSlots):
            if int(ADC1_seqSlotSelectRegisterList[4 * seqTabIdx + idx].currentData) == 20:
                application.runScript('setDef(ADC1.S' + str(seqTabIdx) + 'S' + str(idx) + '_COLOR=000000)')
                application.runScript('setDef(ADC1.S' + str(seqTabIdx) + 'S' + str(idx) + '_BOXCOLOR=FFC90E)')
                application.runScript('setDef(ADC1.S' + str(seqTabIdx) + 'S' + str(idx) + '_CH=No channel)')
                application.runScript('setDef(ADC1.S' + str(seqTabIdx) + 'S' + str(idx) + '_NAME_TXT=selected)')
    # Update sequencer timings
    ADC1_calcSeqTimes(channelIdx)
    application.runScript('setDef(ADC1.SQBlock.update=1)')

def ADC1_calcSeqTimes(channelIdx):
    # Get sequence number, equivalent to tab number
    seqTabIdx = ADC1_SEQCONT.currentIndex
    # Get number of enabled slots
    nbSlots = int(ADC1_seqNbSlotsRegisterList[seqTabIdx].currentData)
    all_times = 0
    if (channelIdx < ADC1_DIGITAL_CHANNEL_MAX):
        for idx in range(nbSlots):
            if (int(ADC1_seqSlotSelectRegisterList[4 * seqTabIdx + idx].currentData) != 20) and (ADC1_tabConfiguredList[int(ADC1_seqSlotSelectRegisterList[4 * seqTabIdx + idx].currentData)] != 0):
                all_times += float(ADC1_channelDurationList[int(ADC1_seqSlotSelectRegisterList[4 * seqTabIdx + idx].currentData)])
    if nbSlots != 0:
        ADC1_seqTimesList[seqTabIdx].text = format(all_times, '.4f')
 
 
#print('Run adc1.py')

ADC1_CLK_EDIT.connect('textChanged(QString)', ADC1_changeFreq)

ADC1_CHNCFGCONT.connect('currentChanged(int)', ADC1_onChannelTabChange)

ADC1_CHCFG0_INSEL.connect('currentIndexChanged(int)', ADC1_inputSelectChx)
ADC1_CHCFG1_INSEL.connect('currentIndexChanged(int)', ADC1_inputSelectChx)
ADC1_CHCFG2_INSEL.connect('currentIndexChanged(int)', ADC1_inputSelectChx)
ADC1_CHCFG3_INSEL.connect('currentIndexChanged(int)', ADC1_inputSelectChx)
ADC1_CHCFG4_INSEL.connect('currentIndexChanged(int)', ADC1_inputSelectChx)
ADC1_CHCFG5_INSEL.connect('currentIndexChanged(int)', ADC1_inputSelectChx)
ADC1_CHCFG6_INSEL.connect('currentIndexChanged(int)', ADC1_inputSelectChx)
ADC1_CHCFG7_INSEL.connect('currentIndexChanged(int)', ADC1_inputSelectChx)
ADC1_CHCFG8_INSEL.connect('currentIndexChanged(int)', ADC1_inputSelectChx)
ADC1_CHCFG9_INSEL.connect('currentIndexChanged(int)', ADC1_inputSelectChx)
ADC1_CHCFG10_INSEL.connect('currentIndexChanged(int)', ADC1_inputSelectChx)
ADC1_CHCFG11_INSEL.connect('currentIndexChanged(int)', ADC1_inputSelectChx)
ADC1_CHCFG12_INSEL.connect('currentIndexChanged(int)', ADC1_inputSelectChx)
ADC1_CHCFG13_INSEL.connect('currentIndexChanged(int)', ADC1_inputSelectChx)
ADC1_CHCFG14_INSEL.connect('currentIndexChanged(int)', ADC1_inputSelectChx)
ADC1_CHCFG15_INSEL.connect('currentIndexChanged(int)', ADC1_inputSelectChx)
ADC1_CHCFG16_INSEL.connect('currentIndexChanged(int)', ADC1_inputSelectChx)
ADC1_CHCFG17_INSEL.connect('currentIndexChanged(int)', ADC1_inputSelectChx)
ADC1_CHCFG18_INSEL.connect('currentIndexChanged(int)', ADC1_inputSelectChx)
ADC1_CHCFG19_INSEL.connect('currentIndexChanged(int)', ADC1_inputSelectChx)

ADC1_CHCFG0_REPCH.connect('valueChanged(int)', ADC1_repSelectChx)
ADC1_CHCFG1_REPCH.connect('valueChanged(int)', ADC1_repSelectChx)
ADC1_CHCFG2_REPCH.connect('valueChanged(int)', ADC1_repSelectChx)
ADC1_CHCFG3_REPCH.connect('valueChanged(int)', ADC1_repSelectChx)
ADC1_CHCFG4_REPCH.connect('valueChanged(int)', ADC1_repSelectChx)
ADC1_CHCFG5_REPCH.connect('valueChanged(int)', ADC1_repSelectChx)
ADC1_CHCFG6_REPCH.connect('valueChanged(int)', ADC1_repSelectChx)
ADC1_CHCFG7_REPCH.connect('valueChanged(int)', ADC1_repSelectChx)
ADC1_CHCFG8_REPCH.connect('valueChanged(int)', ADC1_repSelectChx)
ADC1_CHCFG9_REPCH.connect('valueChanged(int)', ADC1_repSelectChx)
ADC1_CHCFG10_REPCH.connect('valueChanged(int)', ADC1_repSelectChx)
ADC1_CHCFG11_REPCH.connect('valueChanged(int)', ADC1_repSelectChx)
ADC1_CHCFG12_REPCH.connect('valueChanged(int)', ADC1_repSelectChx)
ADC1_CHCFG13_REPCH.connect('valueChanged(int)', ADC1_repSelectChx)
ADC1_CHCFG14_REPCH.connect('valueChanged(int)', ADC1_repSelectChx)
ADC1_CHCFG15_REPCH.connect('valueChanged(int)', ADC1_repSelectChx)
ADC1_CHCFG16_REPCH.connect('valueChanged(int)', ADC1_repSelectChx)
ADC1_CHCFG17_REPCH.connect('valueChanged(int)', ADC1_repSelectChx)
ADC1_CHCFG18_REPCH.connect('valueChanged(int)', ADC1_repSelectChx)
ADC1_CHCFG19_REPCH.connect('valueChanged(int)', ADC1_repSelectChx)

ADC1_CALIB1_EN.connect('stateChanged(int)', ADC1_onCalibEn)
ADC1_CALIB3_EN.connect('stateChanged(int)', ADC1_onCalibEn)
ADC1_CALIB5_EN.connect('stateChanged(int)', ADC1_onCalibEn)
ADC1_CALIB7_EN.connect('stateChanged(int)', ADC1_onCalibEn)
ADC1_CALIB9_EN.connect('stateChanged(int)', ADC1_onCalibEn)
ADC1_CALIB11_EN.connect('stateChanged(int)', ADC1_onCalibEn)
ADC1_CALIB13_EN.connect('stateChanged(int)', ADC1_onCalibEn)
ADC1_CALIB15_EN.connect('stateChanged(int)', ADC1_onCalibEn)
ADC1_CALIB16_EN.connect('stateChanged(int)', ADC1_onCalibEn)
ADC1_CALIB17_EN.connect('stateChanged(int)', ADC1_onCalibEn)
ADC1_CALIB18_EN.connect('stateChanged(int)', ADC1_onCalibEn)
ADC1_CALIB19_EN.connect('stateChanged(int)', ADC1_onCalibEn)
ADC1_CALIB20_EN.connect('stateChanged(int)', ADC1_onCalibEn)
ADC1_CALIB20_EN.connect('stateChanged(int)', ADC1_onCalibEn)
ADC1_CALIB21_EN.connect('stateChanged(int)', ADC1_onCalibEn)
ADC1_CALIB22_EN.connect('stateChanged(int)', ADC1_onCalibEn)
ADC1_CALIB23_EN.connect('stateChanged(int)', ADC1_onCalibEn)
ADC1_CALIB24_EN.connect('stateChanged(int)', ADC1_onCalibEn)
ADC1_CALIB25_EN.connect('stateChanged(int)', ADC1_onCalibEn)
ADC1_CALIB26_EN.connect('stateChanged(int)', ADC1_onCalibEn)

ADC1_CHCFG0_CLASSEL.connect('currentIndexChanged(int)', ADC1_classSelectChx)
ADC1_CHCFG1_CLASSEL.connect('currentIndexChanged(int)', ADC1_classSelectChx)
ADC1_CHCFG2_CLASSEL.connect('currentIndexChanged(int)', ADC1_classSelectChx)
ADC1_CHCFG3_CLASSEL.connect('currentIndexChanged(int)', ADC1_classSelectChx)
ADC1_CHCFG4_CLASSEL.connect('currentIndexChanged(int)', ADC1_classSelectChx)
ADC1_CHCFG5_CLASSEL.connect('currentIndexChanged(int)', ADC1_classSelectChx)
ADC1_CHCFG6_CLASSEL.connect('currentIndexChanged(int)', ADC1_classSelectChx)
ADC1_CHCFG7_CLASSEL.connect('currentIndexChanged(int)', ADC1_classSelectChx)
ADC1_CHCFG8_CLASSEL.connect('currentIndexChanged(int)', ADC1_classSelectChx)
ADC1_CHCFG9_CLASSEL.connect('currentIndexChanged(int)', ADC1_classSelectChx)
ADC1_CHCFG10_CLASSEL.connect('currentIndexChanged(int)', ADC1_classSelectChx)
ADC1_CHCFG11_CLASSEL.connect('currentIndexChanged(int)', ADC1_classSelectChx)
ADC1_CHCFG12_CLASSEL.connect('currentIndexChanged(int)', ADC1_classSelectChx)
ADC1_CHCFG13_CLASSEL.connect('currentIndexChanged(int)', ADC1_classSelectChx)
ADC1_CHCFG14_CLASSEL.connect('currentIndexChanged(int)', ADC1_classSelectChx)
ADC1_CHCFG15_CLASSEL.connect('currentIndexChanged(int)', ADC1_classSelectChx)
ADC1_CHCFG16_CLASSEL.connect('currentIndexChanged(int)', ADC1_classSelectChx)
ADC1_CHCFG17_CLASSEL.connect('currentIndexChanged(int)', ADC1_classSelectChx)
ADC1_CHCFG18_CLASSEL.connect('currentIndexChanged(int)', ADC1_classSelectChx)
ADC1_CHCFG19_CLASSEL.connect('currentIndexChanged(int)', ADC1_classSelectChx)

ADC1_CONVCFG0_CTRY.connect('textChanged(QString)', ADC1_changeConvClassCat)
ADC1_CONVCFG1_CTRY.connect('textChanged(QString)', ADC1_changeConvClassCat)
ADC1_CONVCFG2_CTRY.connect('textChanged(QString)', ADC1_changeConvClassCat)
ADC1_CONVCFG3_CTRY.connect('textChanged(QString)', ADC1_changeConvClassCat)

ADC1_CONVCFG0_STC.connect('currentIndexChanged(int)', ADC1_STCSelectChx)
ADC1_CONVCFG1_STC.connect('currentIndexChanged(int)', ADC1_STCSelectChx)
ADC1_CONVCFG2_STC.connect('currentIndexChanged(int)', ADC1_STCSelectChx)
ADC1_CONVCFG3_STC.connect('currentIndexChanged(int)', ADC1_STCSelectChx)

ADC1_CONVCFG0_TCOS.connect('textChanged(QString)', ADC1_TCOSSelectChx)
ADC1_CONVCFG1_TCOS.connect('textChanged(QString)', ADC1_TCOSSelectChx)
ADC1_CONVCFG2_TCOS.connect('textChanged(QString)', ADC1_TCOSSelectChx)
ADC1_CONVCFG3_TCOS.connect('textChanged(QString)', ADC1_TCOSSelectChx)

ADC1_CONVCFG0_TCONF.connect('currentIndexChanged(int)', ADC1_TCOSSelectChx)
ADC1_CONVCFG1_TCONF.connect('currentIndexChanged(int)', ADC1_TCOSSelectChx)
ADC1_CONVCFG2_TCONF.connect('currentIndexChanged(int)', ADC1_TCOSSelectChx)
ADC1_CONVCFG3_TCONF.connect('currentIndexChanged(int)', ADC1_TCOSSelectChx)

ADC1_CONVCFG0_OVERS.connect('currentIndexChanged(int)', ADC1_TCOSSelectChx)
ADC1_CONVCFG1_OVERS.connect('currentIndexChanged(int)', ADC1_TCOSSelectChx)
ADC1_CONVCFG2_OVERS.connect('currentIndexChanged(int)', ADC1_TCOSSelectChx)
ADC1_CONVCFG3_OVERS.connect('currentIndexChanged(int)', ADC1_TCOSSelectChx)

ADC1_CONVCFG0_BWD.connect('currentIndexChanged(int)', ADC1_BWDSelectChx)
ADC1_CONVCFG1_BWD.connect('currentIndexChanged(int)', ADC1_BWDSelectChx)
ADC1_CONVCFG2_BWD.connect('currentIndexChanged(int)', ADC1_BWDSelectChx)
ADC1_CONVCFG3_BWD.connect('currentIndexChanged(int)', ADC1_BWDSelectChx)

ADC1_CONVCFG0_PCAL.connect('stateChanged(int)', ADC1_PostCalSelectChx)
ADC1_CONVCFG1_PCAL.connect('stateChanged(int)', ADC1_PostCalSelectChx)
ADC1_CONVCFG2_PCAL.connect('stateChanged(int)', ADC1_PostCalSelectChx)
ADC1_CONVCFG3_PCAL.connect('stateChanged(int)', ADC1_PostCalSelectChx)

ADC1_CONVCFG0_MSBD.connect('stateChanged(int)', ADC1_MSBDSelectChx)
ADC1_CONVCFG1_MSBD.connect('stateChanged(int)', ADC1_MSBDSelectChx)
ADC1_CONVCFG2_MSBD.connect('stateChanged(int)', ADC1_MSBDSelectChx)
ADC1_CONVCFG3_MSBD.connect('stateChanged(int)', ADC1_MSBDSelectChx)

ADC1_CONVCFG0_SESP.connect('stateChanged(int)', ADC1_SESPSelectChx)
ADC1_CONVCFG1_SESP.connect('stateChanged(int)', ADC1_SESPSelectChx)
ADC1_CONVCFG2_SESP.connect('stateChanged(int)', ADC1_SESPSelectChx)
ADC1_CONVCFG3_SESP.connect('stateChanged(int)', ADC1_SESPSelectChx)

ADC1_CHCFG0_FILSEL.connect('currentIndexChanged(int)', ADC1_filtSelectChx)
ADC1_CHCFG1_FILSEL.connect('currentIndexChanged(int)', ADC1_filtSelectChx)
ADC1_CHCFG2_FILSEL.connect('currentIndexChanged(int)', ADC1_filtSelectChx)
ADC1_CHCFG3_FILSEL.connect('currentIndexChanged(int)', ADC1_filtSelectChx)
ADC1_CHCFG4_FILSEL.connect('currentIndexChanged(int)', ADC1_filtSelectChx)
ADC1_CHCFG5_FILSEL.connect('currentIndexChanged(int)', ADC1_filtSelectChx)
ADC1_CHCFG6_FILSEL.connect('currentIndexChanged(int)', ADC1_filtSelectChx)
ADC1_CHCFG7_FILSEL.connect('currentIndexChanged(int)', ADC1_filtSelectChx)
ADC1_CHCFG8_FILSEL.connect('currentIndexChanged(int)', ADC1_filtSelectChx)
ADC1_CHCFG9_FILSEL.connect('currentIndexChanged(int)', ADC1_filtSelectChx)
ADC1_CHCFG10_FILSEL.connect('currentIndexChanged(int)', ADC1_filtSelectChx)
ADC1_CHCFG11_FILSEL.connect('currentIndexChanged(int)', ADC1_filtSelectChx)
ADC1_CHCFG12_FILSEL.connect('currentIndexChanged(int)', ADC1_filtSelectChx)
ADC1_CHCFG13_FILSEL.connect('currentIndexChanged(int)', ADC1_filtSelectChx)
ADC1_CHCFG14_FILSEL.connect('currentIndexChanged(int)', ADC1_filtSelectChx)
ADC1_CHCFG15_FILSEL.connect('currentIndexChanged(int)', ADC1_filtSelectChx)
ADC1_CHCFG16_FILSEL.connect('currentIndexChanged(int)', ADC1_filtSelectChx)
ADC1_CHCFG17_FILSEL.connect('currentIndexChanged(int)', ADC1_filtSelectChx)
ADC1_CHCFG18_FILSEL.connect('currentIndexChanged(int)', ADC1_filtSelectChx)
ADC1_CHCFG19_FILSEL.connect('currentIndexChanged(int)', ADC1_filtSelectChx)

ADC1_FILTCFG_COEF_A0.connect('currentIndexChanged(int)', ADC1_filtCoeffSelChx)
ADC1_FILTCFG_COEF_A1.connect('currentIndexChanged(int)', ADC1_filtCoeffSelChx)
ADC1_FILTCFG_COEF_A2.connect('currentIndexChanged(int)', ADC1_filtCoeffSelChx)
ADC1_FILTCFG_COEF_A3.connect('currentIndexChanged(int)', ADC1_filtCoeffSelChx)

ADC1_CHCFG0_CMPSEL.connect('currentIndexChanged(int)', ADC1_cmpSelectChx)
ADC1_CHCFG1_CMPSEL.connect('currentIndexChanged(int)', ADC1_cmpSelectChx)
ADC1_CHCFG2_CMPSEL.connect('currentIndexChanged(int)', ADC1_cmpSelectChx)
ADC1_CHCFG3_CMPSEL.connect('currentIndexChanged(int)', ADC1_cmpSelectChx)
ADC1_CHCFG4_CMPSEL.connect('currentIndexChanged(int)', ADC1_cmpSelectChx)
ADC1_CHCFG5_CMPSEL.connect('currentIndexChanged(int)', ADC1_cmpSelectChx)
ADC1_CHCFG6_CMPSEL.connect('currentIndexChanged(int)', ADC1_cmpSelectChx)
ADC1_CHCFG7_CMPSEL.connect('currentIndexChanged(int)', ADC1_cmpSelectChx)
ADC1_CHCFG8_CMPSEL.connect('currentIndexChanged(int)', ADC1_cmpSelectChx)
ADC1_CHCFG9_CMPSEL.connect('currentIndexChanged(int)', ADC1_cmpSelectChx)
ADC1_CHCFG10_CMPSEL.connect('currentIndexChanged(int)', ADC1_cmpSelectChx)
ADC1_CHCFG11_CMPSEL.connect('currentIndexChanged(int)', ADC1_cmpSelectChx)
ADC1_CHCFG12_CMPSEL.connect('currentIndexChanged(int)', ADC1_cmpSelectChx)
ADC1_CHCFG13_CMPSEL.connect('currentIndexChanged(int)', ADC1_cmpSelectChx)
ADC1_CHCFG14_CMPSEL.connect('currentIndexChanged(int)', ADC1_cmpSelectChx)
ADC1_CHCFG15_CMPSEL.connect('currentIndexChanged(int)', ADC1_cmpSelectChx)
ADC1_CHCFG16_CMPSEL.connect('currentIndexChanged(int)', ADC1_cmpSelectChx)
ADC1_CHCFG17_CMPSEL.connect('currentIndexChanged(int)', ADC1_cmpSelectChx)
ADC1_CHCFG18_CMPSEL.connect('currentIndexChanged(int)', ADC1_cmpSelectChx)
ADC1_CHCFG19_CMPSEL.connect('currentIndexChanged(int)', ADC1_cmpSelectChx)

ADC1_CMPCFG0_INSEL.connect('textChanged(QString)', ADC1_cmpInputSelChx)
ADC1_CMPCFG1_INSEL.connect('textChanged(QString)', ADC1_cmpInputSelChx)
ADC1_CMPCFG2_INSEL.connect('textChanged(QString)', ADC1_cmpInputSelChx)
ADC1_CMPCFG3_INSEL.connect('textChanged(QString)', ADC1_cmpInputSelChx)

ADC1_CMPCFG0_MODE.connect('currentIndexChanged(int)', ADC1_cmpModeSelChx)
ADC1_CMPCFG1_MODE.connect('currentIndexChanged(int)', ADC1_cmpModeSelChx)
ADC1_CMPCFG2_MODE.connect('currentIndexChanged(int)', ADC1_cmpModeSelChx)
ADC1_CMPCFG3_MODE.connect('currentIndexChanged(int)', ADC1_cmpModeSelChx)

ADC1_UPPER_TH0.connect('valueChanged(double)', ADC1_cmpUpThSelChx)
ADC1_UPPER_TH1.connect('valueChanged(double)', ADC1_cmpUpThSelChx)
ADC1_UPPER_TH2.connect('valueChanged(double)', ADC1_cmpUpThSelChx)
ADC1_UPPER_TH3.connect('valueChanged(double)', ADC1_cmpUpThSelChx)

ADC1_LOWER_TH0.connect('valueChanged(double)', ADC1_cmpLoThSelChx)
ADC1_LOWER_TH1.connect('valueChanged(double)', ADC1_cmpLoThSelChx)
ADC1_LOWER_TH2.connect('valueChanged(double)', ADC1_cmpLoThSelChx)
ADC1_LOWER_TH3.connect('valueChanged(double)', ADC1_cmpLoThSelChx)

ADC1_SQCFG0_SLOTS.connect('currentIndexChanged(int)', ADC1_nbSlotSelSeqx)
ADC1_SQCFG1_SLOTS.connect('currentIndexChanged(int)', ADC1_nbSlotSelSeqx)
ADC1_SQCFG2_SLOTS.connect('currentIndexChanged(int)', ADC1_nbSlotSelSeqx)
ADC1_SQCFG3_SLOTS.connect('currentIndexChanged(int)', ADC1_nbSlotSelSeqx)

ADC1_SQSLOT0_CHSEL0.connect('currentIndexChanged(int)', ADC1_slotSelSeqx)
ADC1_SQSLOT0_CHSEL1.connect('currentIndexChanged(int)', ADC1_slotSelSeqx)
ADC1_SQSLOT0_CHSEL2.connect('currentIndexChanged(int)', ADC1_slotSelSeqx)
ADC1_SQSLOT0_CHSEL3.connect('currentIndexChanged(int)', ADC1_slotSelSeqx)
ADC1_SQSLOT1_CHSEL0.connect('currentIndexChanged(int)', ADC1_slotSelSeqx)
ADC1_SQSLOT1_CHSEL1.connect('currentIndexChanged(int)', ADC1_slotSelSeqx)
ADC1_SQSLOT1_CHSEL2.connect('currentIndexChanged(int)', ADC1_slotSelSeqx)
ADC1_SQSLOT1_CHSEL3.connect('currentIndexChanged(int)', ADC1_slotSelSeqx)
ADC1_SQSLOT2_CHSEL0.connect('currentIndexChanged(int)', ADC1_slotSelSeqx)
ADC1_SQSLOT2_CHSEL1.connect('currentIndexChanged(int)', ADC1_slotSelSeqx)
ADC1_SQSLOT2_CHSEL2.connect('currentIndexChanged(int)', ADC1_slotSelSeqx)
ADC1_SQSLOT2_CHSEL3.connect('currentIndexChanged(int)', ADC1_slotSelSeqx)
ADC1_SQSLOT3_CHSEL0.connect('currentIndexChanged(int)', ADC1_slotSelSeqx)
ADC1_SQSLOT3_CHSEL1.connect('currentIndexChanged(int)', ADC1_slotSelSeqx)
ADC1_SQSLOT3_CHSEL2.connect('currentIndexChanged(int)', ADC1_slotSelSeqx)
ADC1_SQSLOT3_CHSEL3.connect('currentIndexChanged(int)', ADC1_slotSelSeqx)

# Initialization
# Conversion class category
if ADC1_CONVCFG0_CTRY.text == '':
    ADC1_CONVCFG0_CTRY.text = 'Low voltage inputs'
if ADC1_CONVCFG1_CTRY.text == '':
    ADC1_CONVCFG1_CTRY.text = 'High voltage inputs'
if ADC1_CONVCFG2_CTRY.text == '':
    ADC1_CONVCFG2_CTRY.text = 'Internal CSA'
if ADC1_CONVCFG3_CTRY.text == '':
    ADC1_CONVCFG3_CTRY.text = 'User definable'

for i in range(20):
    ADC1_onChannelTabChange(i)
ADC1_onChannelTabChange(0)

#print('Done')
