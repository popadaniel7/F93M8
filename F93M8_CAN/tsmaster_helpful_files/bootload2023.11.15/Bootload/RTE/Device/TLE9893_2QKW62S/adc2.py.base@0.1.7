#<checksum>91e82adc77a86ecef7ef17ca4466d623acb3202fe944411315425b2b62663858</checksum>
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
# \file     adc2.py
#
# \brief    Script to calculate the ADC2 values
#
# \version  V0.1.7
# \date     15. Dec 2021
#

###############################################################################
#                              Author(s) Identity                             #
#*****************************************************************************#
#  Initials     Name                                                          #
#  -------------------------------------------------------------------------- #
#  JO           Julia Ott                                                     #
#  DM           Daniel Mysliwitz                                              #
#  BG           Blandine Guillot                                              #
###############################################################################

###############################################################################
#                           Revision Control History                          #
#*****************************************************************************#
#  V0.1.0: 2020-11-04, DM:   Initial version                                  #
#  V0.1.1: 2020-11-04, JO:   EP-568: Added checksum                           #
#  V0.1.2: 2020-11-12, BG:   EP-588: Corrected channel number for both VSD    #
#                            and VCP                                          #
#  V0.1.3: 2021-01-28, BG:   EP-672: Updated function names                   #
#                            Renamed "available" to "not assigned"            #
#                            Added timings dependency on frequency change     #
#                            Added function for the class category text       #
#                            Adapted the timings with the number of           #
#                            measurements and not the number of repetition    #
#  V0.1.4: 2021-04-09, JO:   EP-753: Removed generation of bsl_defines.inc    #
#                            from adc2.py (was commented out anyway)          #
#  V0.1.5: 2021-05-05, BG:   EP-798: Added initialization of the config by    #
#                            clicking on all channel tabs                     #
#  V0.1.6: 2021-11-30, JO:   EP-937: Updated copyright and branding           #
#  V0.1.7: 2021-12-15, BG:   EP-980: Locked initialization of written         #
#                            protected registers                              #
###############################################################################

ADC2_CALIB_TICKS = 4
ADC2_FILT_TICKS = 1
ADC2_CMP_TICKS = 1
ADC2_DIGITAL_CHANNEL_MAX = 15
ADC2_registerModeList          = ['math', 'combo', 'combo', 'combo', 'math', 'math', 'math', 'math', 'combo', 'math', 'math', 'math', 'math', 'combo', 'combo' ]
ADC2_channelInselRegisterList  = [ADC2_CHCFG0_INSEL, ADC2_CHCFG1_INSEL, ADC2_CHCFG2_INSEL, ADC2_CHCFG3_INSEL, ADC2_CHCFG4_INSEL, ADC2_CHCFG5_INSEL, ADC2_CHCFG6_INSEL, ADC2_CHCFG7_INSEL, ADC2_CHCFG8_INSEL, ADC2_CHCFG9_INSEL, ADC2_CHCFG10_INSEL, ADC2_CHCFG11_INSEL, ADC2_CHCFG12_INSEL, ADC2_CHCFG13_INSEL, ADC2_CHCFG14_INSEL]
ADC2_channelRepRegisterList    = [ADC2_CHCFG0_REPCH, ADC2_CHCFG1_REPCH, ADC2_CHCFG2_REPCH, ADC2_CHCFG3_REPCH, ADC2_CHCFG4_REPCH, ADC2_CHCFG5_REPCH, ADC2_CHCFG6_REPCH, ADC2_CHCFG7_REPCH, ADC2_CHCFG8_REPCH, ADC2_CHCFG9_REPCH, ADC2_CHCFG10_REPCH, ADC2_CHCFG11_REPCH, ADC2_CHCFG12_REPCH, ADC2_CHCFG13_REPCH, ADC2_CHCFG14_REPCH]
ADC2_filterSelectRegisterList  = [ADC2_CHCFG0_FILSEL, ADC2_CHCFG1_FILSEL, ADC2_CHCFG2_FILSEL, ADC2_CHCFG3_FILSEL, ADC2_CHCFG4_FILSEL, ADC2_CHCFG5_FILSEL, ADC2_CHCFG6_FILSEL, ADC2_CHCFG7_FILSEL, ADC2_CHCFG8_FILSEL, ADC2_CHCFG9_FILSEL, ADC2_CHCFG10_FILSEL, ADC2_CHCFG11_FILSEL, ADC2_CHCFG12_FILSEL, ADC2_CHCFG13_FILSEL, ADC2_CHCFG14_FILSEL]
ADC2_filterSelUserRegisterList = [ADC2_CHCFG0_FILSEL_user, 0, 0, 0, ADC2_CHCFG4_FILSEL_user, ADC2_CHCFG5_FILSEL_user, ADC2_CHCFG6_FILSEL_user, ADC2_CHCFG7_FILSEL_user, 0, ADC2_CHCFG9_FILSEL_user, ADC2_CHCFG10_FILSEL_user, ADC2_CHCFG11_FILSEL_user, ADC2_CHCFG12_FILSEL_user, 0, 0]
ADC2_compareSelectRegisterList = [ADC2_CHCFG0_CMPSEL, ADC2_CHCFG1_CMPSEL, ADC2_CHCFG2_CMPSEL, ADC2_CHCFG3_CMPSEL, ADC2_CHCFG4_CMPSEL, ADC2_CHCFG5_CMPSEL, ADC2_CHCFG6_CMPSEL, ADC2_CHCFG7_CMPSEL, ADC2_CHCFG8_CMPSEL, ADC2_CHCFG9_CMPSEL, ADC2_CHCFG10_CMPSEL, ADC2_CHCFG11_CMPSEL, ADC2_CHCFG12_CMPSEL, ADC2_CHCFG13_CMPSEL, ADC2_CHCFG14_CMPSEL]
ADC2_compareSelUserRegisterList= [ADC2_CHCFG0_CMPSEL_user, 0, 0, 0, ADC2_CHCFG4_CMPSEL_user, ADC2_CHCFG5_CMPSEL_user, ADC2_CHCFG6_CMPSEL_user, ADC2_CHCFG7_CMPSEL_user, 0, ADC2_CHCFG9_CMPSEL_user, ADC2_CHCFG10_CMPSEL_user, ADC2_CHCFG11_CMPSEL_user, ADC2_CHCFG12_CMPSEL_user, 0, 0]
ADC2_classSelectRegisterList   = [ADC2_CHCFG0_CLASSEL, ADC2_CHCFG1_CLASSEL, ADC2_CHCFG2_CLASSEL, ADC2_CHCFG3_CLASSEL, ADC2_CHCFG4_CLASSEL, ADC2_CHCFG5_CLASSEL, ADC2_CHCFG6_CLASSEL, ADC2_CHCFG7_CLASSEL, ADC2_CHCFG8_CLASSEL, ADC2_CHCFG9_CLASSEL, ADC2_CHCFG10_CLASSEL, ADC2_CHCFG11_CLASSEL, ADC2_CHCFG12_CLASSEL, ADC2_CHCFG13_CLASSEL, ADC2_CHCFG14_CLASSEL]
ADC2_channelDurationList       = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

ADC2_calibEnableRegisterList   = [ADC2_CALIB0_EN, ADC2_CALIB1_EN, ADC2_CALIB2_EN, ADC2_CALIB3_EN, ADC2_CALIB4_EN, ADC2_CALIB5_EN, ADC2_CALIB6_EN, ADC2_CALIB7_EN, ADC2_CALIB8_EN, ADC2_CALIB9_EN, ADC2_CALIB10_EN, ADC2_CALIB11_EN, ADC2_CALIB12_EN, ADC2_CALIB13_EN, ADC2_CALIB14_EN]

ADC2_classCategoryVarList      = [ADC2_CONVCFG0_CTRY, ADC2_CONVCFG1_CTRY, ADC2_CONVCFG2_CTRY, ADC2_CONVCFG3_CTRY]
ADC2_classSTCRegisterList      = [ADC2_CONVCFG0_STC, ADC2_CONVCFG1_STC, ADC2_CONVCFG2_STC, ADC2_CONVCFG3_STC]

ADC2_filterCoeffRegisterList   = [ADC2_FILTCFG_COEF_A0, ADC2_FILTCFG_COEF_A1, ADC2_FILTCFG_COEF_A2, ADC2_FILTCFG_COEF_A3, ADC2_FILTCFG_COEF_A4, ADC2_FILTCFG_COEF_A5, ADC2_FILTCFG_COEF_A6, ADC2_FILTCFG_COEF_A7]
ADC2_filterCoeffTextList       = ['1/2', '1/4', '1/8', '1/16']

ADC2_compareInputSelectList    = [ADC2_CMPCFG0_INSEL, ADC2_CMPCFG1_INSEL, ADC2_CMPCFG2_INSEL, ADC2_CMPCFG3_INSEL, ADC2_CMPCFG4_INSEL, ADC2_CMPCFG5_INSEL, ADC2_CMPCFG6_INSEL, ADC2_CMPCFG7_INSEL]
ADC2_compareModeSelRegisterList= [ADC2_CMPCFG0_MODE, ADC2_CMPCFG1_MODE, ADC2_CMPCFG2_MODE, ADC2_CMPCFG3_MODE, ADC2_CMPCFG4_MODE, ADC2_CMPCFG5_MODE, ADC2_CMPCFG6_MODE, ADC2_CMPCFG7_MODE]
ADC2_compareUpThSelRegisterList= [ADC2_UPPER_TH0, ADC2_UPPER_TH1, ADC2_UPPER_TH2, ADC2_UPPER_TH3, ADC2_UPPER_TH4, ADC2_UPPER_TH5, ADC2_UPPER_TH6, ADC2_UPPER_TH7]
ADC2_compareLoThSelRegisterList= [ADC2_LOWER_TH0, ADC2_LOWER_TH1, ADC2_LOWER_TH2, ADC2_LOWER_TH3, ADC2_LOWER_TH4, ADC2_LOWER_TH5, ADC2_LOWER_TH6, ADC2_LOWER_TH7]
ADC2_maxVoltageList            = [25.83, 31.00, 8.15, 51.67, 31.00, 31.00, 31.00, 5.34, 5.34, 5.34, 5.34, 5.34, 5.34, 5.34, 5.34]

ADC2_seqChannelList            = [0, 1, 2, 3, 13, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15]
ADC2_seqTimesList              = [ADC2_S0_TIMES, ADC2_S1_TIMES, ADC2_S2_TIMES, ADC2_S3_TIMES]

ADC2_inBoxWidth                = [160, 160, 160, 160, 240, 240, 240, 160, 160, 160, 160, 160, 240, 240, 300]



def ADC2_calConvTicks(channelTabIdx):
    classIdx = int(ADC2_classSelectRegisterList[channelTabIdx].currentData)
    if (classIdx < 4):
        kernelTicks = int(ADC2_classSTCRegisterList[classIdx].currentText) + 2
    else:
        kernelTicks = 0
    return kernelTicks

def ADC2_calcKernelTime(channelTabIdx):
    fADC2 = float(ADC2_CLK.text.split(' ')[0])
    classIdx = int(ADC2_classSelectRegisterList[channelTabIdx].currentData)
    if (classIdx < 4):
        kernelTicks = ADC2_calConvTicks(channelTabIdx) * ADC2_channelRepRegisterList[channelTabIdx].value
        kernelTime = format(kernelTicks / fADC2, '.4f')
    else:
        kernelTime = 0.0
    return kernelTime

def ADC2_calcResultTicks(channelTabIdx):
    classIdx = int(ADC2_classSelectRegisterList[channelTabIdx].currentData)
    if (classIdx < 4):
        if (ADC2_calibEnableRegisterList[channelTabIdx] == 0):
            in2resTicks_single = ADC2_calConvTicks(channelTabIdx)
        else:
            if (ADC2_calibEnableRegisterList[channelTabIdx].checked == 1):
                in2resTicks_single = ADC2_calConvTicks(channelTabIdx) + ADC2_CALIB_TICKS
            else:
                in2resTicks_single = ADC2_calConvTicks(channelTabIdx)
    else:
        in2resTicks_single = 0
    return in2resTicks_single

def ADC2_calcResultTime(channelTabIdx):
    fADC2 = float(ADC2_CLK.text.split(' ')[0])
    in2resTicks_single = ADC2_calcResultTicks(channelTabIdx)
    in2resTime = format(float(in2resTicks_single * ADC2_channelRepRegisterList[channelTabIdx].value / fADC2), '.4f')
    return in2resTime

def ADC2_calcFilterTicks(channelTabIdx):
    classIdx = int(ADC2_classSelectRegisterList[channelTabIdx].currentData)
    if (classIdx < 4):
        in2filtTicks_single = ADC2_calcResultTicks(channelTabIdx) + ADC2_FILT_TICKS
    else:
        in2filtTicks_single = 0
    return in2filtTicks_single

def ADC2_calcFilterTime(channelTabIdx):
    fADC2 = float(ADC2_CLK.text.split(' ')[0])
    in2filtTicks_single = ADC2_calcFilterTicks(channelTabIdx)
    in2filtTime = format(float(in2filtTicks_single * ADC2_channelRepRegisterList[channelTabIdx].value) / fADC2, '.4f')
    return in2filtTime

def ADC2_calcCompareTicks(channelTabIdx):
    classIdx = int(ADC2_classSelectRegisterList[channelTabIdx].currentData)
    if (classIdx < 4):
        in2resTicks_single = ADC2_calcResultTicks(channelTabIdx)
        in2filtTicks_single = ADC2_calcFilterTicks(channelTabIdx)
        if (ADC2_registerModeList[channelTabIdx] == 'math'):
            filtIdx = int(ADC2_filterSelectRegisterList[channelTabIdx].text)
        else:
            filtIdx = int(ADC2_filterSelectRegisterList[channelTabIdx].currentData)
        if (filtIdx == 8):
            # Only compare
            in2cmpTicks_single = in2resTicks_single + ADC2_CMP_TICKS
        else:
            # Filter + compare
            in2cmpTicks_single = in2filtTicks_single + ADC2_CMP_TICKS
    else:
        in2cmpTicks_single = 0
    return in2cmpTicks_single

def ADC2_calcCompareTime(channelTabIdx):
    fADC2 = float(ADC2_CLK.text.split(' ')[0])
    in2cmpTicks_single = ADC2_calcCompareTicks(channelTabIdx)
    in2cmpTime = format(float(in2cmpTicks_single * ADC2_channelRepRegisterList[channelTabIdx].value) / fADC2, '.4f')
    return in2cmpTime

def ADC2_changeFreq(index):
    channelTabIdx = ADC2_CHNCFGCONT.currentIndex
    # Update timings
    for idx in range(ADC2_DIGITAL_CHANNEL_MAX):
        if idx == channelTabIdx:
            ADC2_calcTimesChx(idx)
        else:
            if (ADC2_registerModeList[idx] == 'math'):
                filtIdx = int(ADC2_filterSelectRegisterList[idx].text)
            else:
                filtIdx = int(ADC2_filterSelectRegisterList[idx].currentData)
            if (ADC2_registerModeList[idx] == 'math'):
                cmpIdx = int(ADC2_compareSelectRegisterList[idx].text)
            else:
                cmpIdx = int(ADC2_compareSelectRegisterList[idx].currentData)
            if (filtIdx == 8) and (cmpIdx == 8):
                ADC2_channelDurationList[idx] = format(float(ADC2_calcResultTime(idx)), '.4f')
            else:
                if (filtIdx != 8) and (cmpIdx == 8):
                    ADC2_channelDurationList[idx] = format(float(ADC2_calcFilterTime(idx)), '.4f')
                else:
                    ADC2_channelDurationList[idx] = format(float(ADC2_calcCompareTime(idx)), '.4f')
    application.runScript('setDef(ADC2.ADBlock.update=1)')
    # Update sequencer timings
    ADC2_calcTimesSeq()


def ADC2_calcTimesChx(channelTabIdx):
    ADC2_TIME_KERNEL.text = str(ADC2_calcKernelTime(channelTabIdx))
    ADC2_TIME_IN2RES.text = str(ADC2_calcResultTime(channelTabIdx))
    ADC2_TIME_IN2FILT.text = str(ADC2_calcFilterTime(channelTabIdx))
    ADC2_TIME_IN2CMP.text = str(ADC2_calcCompareTime(channelTabIdx))
    if (ADC2_registerModeList[channelTabIdx] == 'math'):
        filtIdx = int(ADC2_filterSelectRegisterList[channelTabIdx].text)
    else:
        filtIdx = int(ADC2_filterSelectRegisterList[channelTabIdx].currentData)
    if (ADC2_registerModeList[channelTabIdx] == 'math'):
        cmpIdx = int(ADC2_compareSelectRegisterList[channelTabIdx].text)
    else:
        cmpIdx = int(ADC2_compareSelectRegisterList[channelTabIdx].currentData)
    if (filtIdx == 8) and (cmpIdx == 8):
        ADC2_channelDurationList[channelTabIdx] = format(float(ADC2_TIME_IN2RES.text), '.4f')
    else:
        if (filtIdx != 8) and (cmpIdx == 8):
            ADC2_channelDurationList[channelTabIdx] = format(float(ADC2_TIME_IN2FILT.text), '.4f')
        else:
            ADC2_channelDurationList[channelTabIdx] = format(float(ADC2_TIME_IN2CMP.text), '.4f')
    application.runScript('setDef(ADC2.ADBlock.update=1)')
    return float(ADC2_channelDurationList[channelTabIdx])

def ADC2_calcTimesSeq():
    cnt = 0
    all_times = 0
    for i in range(4):
        for j in range(4):
            if ADC2_seqChannelList[4 * i + j] < ADC2_DIGITAL_CHANNEL_MAX:
                all_times += float(ADC2_channelDurationList[int(ADC2_seqChannelList[4 * i + j])])
        ADC2_seqTimesList[i].text = format(all_times, '.4f')
        all_times = 0
    application.runScript('setDef(ADC2.SQBlock.update=1)')

def ADC2_onChannelTabChange(channelTabIdx):
    ADC2_RES_NO.text = str(channelTabIdx)
    ADC2_INBOX_WIDTH.value = ADC2_inBoxWidth[channelTabIdx]
    ADC2_CH_NAME.text = ADC2_channelInselRegisterList[channelTabIdx].text
    # Evaluate calibration setting
    if (ADC2_calibEnableRegisterList[channelTabIdx].checked == 1):
        ADC2_USE_CALIBx.value = 1
    else:
        ADC2_USE_CALIBx.value = 0
    # Set class tab according to channel config
    classIdx = int(ADC2_classSelectRegisterList[channelTabIdx].currentData)
    if (classIdx < 4):
        application.runScript('SetTab(ADC2.CHCLASSCONT, ' + str(classIdx) + ')')
        ADC2_CHCLS_NO.value = classIdx
        ADC2_CHCLS_CTRY.text = ADC2_classCategoryVarList[classIdx].text
        ADC2_STC_TXT.text = ADC2_classSTCRegisterList[classIdx].currentText
    # Set filter tab according to channel config
    ADC2_filtSelectCh67(channelTabIdx, ADC2_filterSelUserRegisterList[channelTabIdx])
    # Set compare tab according to channel config
    ADC2_cmpSelectCh67(channelTabIdx, ADC2_compareSelUserRegisterList[channelTabIdx])
    # Calculate timings
    ADC2_calcTimesChx(channelTabIdx)
    # Update sequencer timings
    ADC2_calcTimesSeq()

def ADC2_repSelectChx(repValue):
    # Get channel number, equivalent to tab number
    channelTabIdx = ADC2_CHNCFGCONT.currentIndex
    # Update timing for filter
    ADC2_calcTimesChx(channelTabIdx)
    # Update sequencer timings
    ADC2_calcTimesSeq()
   
def ADC2_classSelectChx(itemIdx):
    channelTabIdx = ADC2_CHNCFGCONT.currentIndex
    # Select the relevant class tab
    application.runScript('SetTab(ADC2.CHCLASSCONT, ' + str(itemIdx) + ')')
    # Update the graph with the class number, category and stc
    ADC2_CHCLS_NO.value = itemIdx
    ADC2_CHCLS_CTRY.text = ADC2_classCategoryVarList[itemIdx].text
    # Update the param STC
    ADC2_STC_TXT.text = ADC2_classSTCRegisterList[itemIdx].currentText
    # Update timings
    ADC2_calcTimesChx(channelTabIdx)
    # Update sequencer timings
    ADC2_calcTimesSeq()

def ADC2_changeConvClassCat(txt):
    ADC2_CHCLS_CTRY.text = txt
    application.runScript('setDef(ADC2.ADBlock.update=1)')
    
def ADC2_STCSelectChx(itemIdx):
    # Get channel number, equivalent to tab number
    channelTabIdx = ADC2_CHNCFGCONT.currentIndex
    # Get class channel index
    classTabIdx = ADC2_CHCLASSCONT.currentIndex
    if (ADC2_classSelectRegisterList[channelTabIdx].currentIndex == classTabIdx):
        ADC2_STC_TXT.text = ADC2_classSTCRegisterList[int(classTabIdx)].currentText
        # Update timings
        ADC2_calcTimesChx(channelTabIdx)
        # Update sequencer timings
        ADC2_calcTimesSeq()
    
def ADC2_filtSelectChx(itemIdx):
    # Get channel number, equivalent to tab number
    channelTabIdx = ADC2_CHNCFGCONT.currentIndex
    ADC2_filtSelectCh67(channelTabIdx, ADC2_filterSelUserRegisterList[channelTabIdx])
    # Update timing for filter
    ADC2_calcTimesChx(channelTabIdx)
    # Update sequencer timings
    ADC2_calcTimesSeq()

def ADC2_filtSelectCh67(channelTabIdx, reg):
    if (channelTabIdx < ADC2_DIGITAL_CHANNEL_MAX):
        reg = ADC2_filterSelUserRegisterList[channelTabIdx]
        if (reg != 0):
            if (reg.currentIndex == 0): # Filter Channel 6
                if (ADC2_FILT6_USED_TXT.text == 'not assigned'):
                    if (ADC2_FILT7_USED_TXT.text == str(channelTabIdx)):
                        ADC2_FILT7_USED_TXT.text = 'not assigned'
                    ADC2_FILT6_USED_TXT.text = str(channelTabIdx)
                    application.runScript('SetTab(ADC2.FILTCHCONT, 6)')
                    ADC2_FILT_NO.value = 6
                    ADC2_FILT_TXT.text = ADC2_filterCoeffTextList[ADC2_filterCoeffRegisterList[6].currentIndex]
                    ADC2_USE_FILTx.value = 1
                    application.runScript('SetDef(ADC2.FILT6CONT.enabled=1)')
                else:
                    if (ADC2_FILT6_USED_TXT.text != str(channelTabIdx)):
                        application.runScript('ShowConsole(1);MessageBox(Filter Channel 6 already used)')
                        reg.currentIndex = 2
                        ADC2_USE_FILTx.value = 0
                        application.runScript('SetDef(ADC2.FILT6CONT.enabled=0)')
            elif (reg.currentIndex == 1): # Filter Channel 7
                if (ADC2_FILT7_USED_TXT.text == 'not assigned'):
                    if (ADC2_FILT6_USED_TXT.text == str(channelTabIdx)):
                        ADC2_FILT6_USED_TXT.text = 'not assigned'
                    ADC2_FILT7_USED_TXT.text = str(channelTabIdx)
                    application.runScript('SetTab(ADC2.FILTCHCONT, 7)')
                    ADC2_FILT_NO.value = 7
                    ADC2_FILT_TXT.text = ADC2_filterCoeffTextList[ADC2_filterCoeffRegisterList[7].currentIndex]
                    ADC2_USE_FILTx.value = 1
                    application.runScript('SetDef(ADC2.FILT7CONT.enabled=1)')
                else:
                    if (ADC2_FILT7_USED_TXT.text != str(channelTabIdx)):
                        application.runScript('ShowConsole(1);MessageBox(Filter Channel 7 already used)')
                        reg.currentIndex = 2
                        ADC2_USE_FILTx.value = 0
                        application.runScript('SetDef(ADC2.FILT7CONT.enabled=0)')
            else:
                if (ADC2_FILT6_USED_TXT.text == str(channelTabIdx)):
                    ADC2_FILT6_USED_TXT.text = 'not assigned'
                    application.runScript('SetDef(ADC2.FILT6CONT.enabled=0)')
                if (ADC2_FILT7_USED_TXT.text == str(channelTabIdx)):
                    ADC2_FILT7_USED_TXT.text = 'not assigned'
                    application.runScript('SetDef(ADC2.FILT7CONT.enabled=0)')
                ADC2_USE_FILTx.value = 0
        if (ADC2_registerModeList[channelTabIdx] == 'math'):
            filtIdx = int(ADC2_filterSelectRegisterList[channelTabIdx].text)
        else:
            filtIdx = int(ADC2_filterSelectRegisterList[channelTabIdx].currentData)
        if (filtIdx < 8):
            application.runScript('SetTab(ADC2.FILTCHCONT, ' + str(filtIdx) + ')')
            ADC2_FILT_NO.value = int(filtIdx)
            ADC2_FILT_TXT.text = ADC2_filterCoeffTextList[ADC2_filterCoeffRegisterList[filtIdx].currentIndex]
            ADC2_USE_FILTx.value = 1
        else:
            ADC2_USE_FILTx.value = 0

def ADC2_filtCoeffSelChx(coeffIdx):
    ADC2_FILT_TXT.text = ADC2_filterCoeffTextList[coeffIdx]
    application.runScript('setDef(ADC2.ADBlock.update=1)')
    
def ADC2_cmpSelectChx(itemIdx):
    # Get channel number, equivalent to tab number
    channelTabIdx = ADC2_CHNCFGCONT.currentIndex
    ADC2_cmpSelectCh67(channelTabIdx, ADC2_compareSelUserRegisterList[channelTabIdx])
    # Update timing for filter
    ADC2_calcTimesChx(channelTabIdx)
    # Update sequencer timings
    ADC2_calcTimesSeq()

def ADC2_cmpSelectCh67(channelTabIdx, reg):
    if (channelTabIdx < ADC2_DIGITAL_CHANNEL_MAX):
        reg = ADC2_compareSelUserRegisterList[channelTabIdx]
        if (reg != 0):
            if (reg.currentIndex == 0): # Compare Channel 6
                if (ADC2_CMP6_USED_TXT.text == 'not assigned'):
                    if (ADC2_CMP7_USED_TXT.text == str(channelTabIdx)):
                        ADC2_CMP7_USED_TXT.text = 'not assigned'
                    ADC2_CMP6_USED_TXT.text = str(channelTabIdx)
                    application.runScript('SetTab(ADC2.CMPCHCONT, 6)')
                    ADC2_CMP_NO.value = 6
                    ADC2_CMP_MODE_TXT.text = ADC2_compareModeSelRegisterList[6].currentText
                    ADC2_CMP_UTH_TXT.text = ADC2_compareUpThSelRegisterList[6].text
                    ADC2_CMP_LTH_TXT.text = ADC2_compareLoThSelRegisterList[6].text
                    ADC2_USE_CMPx.value = 1
                    ADC2_compareUpThSelRegisterList[6].maximum = ADC2_maxVoltageList[channelTabIdx]
                    application.runScript('SetDef(ADC2.CMP6CONT.enabled=1)')
                else:
                    if (ADC2_CMP6_USED_TXT.text != str(channelTabIdx)):
                        application.runScript('ShowConsole(1);MessageBox(Compare Channel 6 already used)')
                        reg.currentIndex = 2
                        application.runScript('SetDef(ADC2.CMP6CONT.enabled=0)')
            elif (reg.currentIndex == 1): # Compare Channel 7
                if (ADC2_CMP7_USED_TXT.text == 'not assigned'):
                    if (ADC2_CMP6_USED_TXT.text == str(channelTabIdx)):
                        ADC2_CMP6_USED_TXT.text = 'not assigned'
                    ADC2_CMP7_USED_TXT.text = str(channelTabIdx)
                    application.runScript('SetTab(ADC2.CMPCHCONT, 7)')
                    ADC2_CMP_NO.value = 7
                    ADC2_CMP_MODE_TXT.text = ADC2_compareModeSelRegisterList[7].currentText
                    ADC2_CMP_UTH_TXT.text = ADC2_compareUpThSelRegisterList[7].text
                    ADC2_CMP_LTH_TXT.text = ADC2_compareLoThSelRegisterList[7].text
                    ADC2_USE_CMPx.value = 1
                    ADC2_compareUpThSelRegisterList[7].maximum = ADC2_maxVoltageList[channelTabIdx]
                    application.runScript('SetDef(ADC2.CMP7CONT.enabled=1)')
                else:
                    if (ADC2_CMP7_USED_TXT.text != str(channelTabIdx)):
                        application.runScript('ShowConsole(1);MessageBox(Compare Channel 7 already used)')
                        reg.currentIndex = 2
                        application.runScript('SetDef(ADC2.CMP7CONT.enabled=0)')
            else:
                if (ADC2_CMP6_USED_TXT.text == str(channelTabIdx)):
                    ADC2_CMP6_USED_TXT.text = 'not assigned'
                    application.runScript('SetDef(ADC2.CMP6CONT.enabled=0)')
                if (ADC2_CMP7_USED_TXT.text == str(channelTabIdx)):
                    ADC2_CMP7_USED_TXT.text = 'not assigned'
                    application.runScript('SetDef(ADC2.CMP7CONT.enabled=0)')
                ADC2_USE_CMPx.value = 0
        if (ADC2_registerModeList[channelTabIdx] == 'math'):
            cmpIdx = int(ADC2_compareSelectRegisterList[channelTabIdx].text)
        else:
            cmpIdx = int(ADC2_compareSelectRegisterList[channelTabIdx].currentData)
        if (cmpIdx < 8):
            application.runScript('SetTab(ADC2.CMPCHCONT, ' + str(cmpIdx) + ')')
            ADC2_CMP_NO.value = cmpIdx
            ADC2_CMP_MODE_TXT.text = ADC2_compareModeSelRegisterList[cmpIdx].currentText
            ADC2_CMP_UTH_TXT.text = ADC2_compareUpThSelRegisterList[cmpIdx].text
            ADC2_CMP_LTH_TXT.text = ADC2_compareLoThSelRegisterList[cmpIdx].text
            ADC2_CMP_SRCx.value = int(ADC2_compareInputSelectList[cmpIdx].text)
            ADC2_USE_CMPx.value = 1
        else:
            ADC2_USE_CMPx.value = 0

def ADC2_cmpInputSelChx(text):
    # Get channel number, equivalent to tab number
    channelTabIdx = ADC2_CHNCFGCONT.currentIndex
    # Get compare channel number, equivalent to tab number
    cmpTabIdx = ADC2_CMPCHCONT.currentIndex
    if (ADC2_registerModeList[channelTabIdx] == 'math'):
        cmpIdx = int(ADC2_compareSelectRegisterList[channelTabIdx].text)
    else:
        cmpIdx = int(ADC2_compareSelectRegisterList[channelTabIdx].currentData)
    if (cmpIdx == cmpTabIdx):
        ADC2_CMP_SRCx.value = int(text)
        # Update timing for filter
        ADC2_calcTimesChx(channelTabIdx)
        # Update sequencer timings
        ADC2_calcTimesSeq()

def ADC2_cmpModeSelChx(mode):
    # Get channel number, equivalent to tab number
    channelTabIdx = ADC2_CHNCFGCONT.currentIndex
    # Get compare channel number, equivalent to tab number
    cmpTabIdx = ADC2_CMPCHCONT.currentIndex
    if (ADC2_registerModeList[channelTabIdx] == 'math'):
        cmpIdx = int(ADC2_compareSelectRegisterList[channelTabIdx].text)
    else:
        cmpIdx = int(ADC2_compareSelectRegisterList[channelTabIdx].currentData)
    if (cmpIdx == cmpTabIdx):
        ADC2_CMP_MODE_TXT.text = ADC2_compareModeSelRegisterList[cmpIdx].currentText
        application.runScript('setDef(ADC2.ADBlock.update=1)')
    
def ADC2_cmpUpThSelChx(value):
    # Get channel number, equivalent to tab number
    channelTabIdx = ADC2_CHNCFGCONT.currentIndex
    # Get compare channel number, equivalent to tab number
    cmpTabIdx = ADC2_CMPCHCONT.currentIndex
    if (ADC2_registerModeList[channelTabIdx] == 'math'):
        cmpIdx = int(ADC2_compareSelectRegisterList[channelTabIdx].text)
    else:
        cmpIdx = int(ADC2_compareSelectRegisterList[channelTabIdx].currentData)
    if (cmpIdx == cmpTabIdx):
        ADC2_CMP_UTH_TXT.text = ADC2_compareUpThSelRegisterList[cmpIdx].text
        application.runScript('setDef(ADC2.ADBlock.update=1)')
    
def ADC2_cmpLoThSelChx(value):
    # Get channel number, equivalent to tab number
    channelTabIdx = ADC2_CHNCFGCONT.currentIndex
    # Get compare channel number, equivalent to tab number
    cmpTabIdx = ADC2_CMPCHCONT.currentIndex
    if (ADC2_registerModeList[channelTabIdx] == 'math'):
        cmpIdx = int(ADC2_compareSelectRegisterList[channelTabIdx].text)
    else:
        cmpIdx = int(ADC2_compareSelectRegisterList[channelTabIdx].currentData)
    if (cmpIdx == cmpTabIdx):
        ADC2_CMP_LTH_TXT.text = ADC2_compareLoThSelRegisterList[cmpIdx].text
        application.runScript('setDef(ADC2.ADBlock.update=1)')
    
def ADC2_onCalibEn(state):
    # Get channel number, equivalent to tab number
    channelTabIdx = ADC2_CHNCFGCONT.currentIndex
    if (state == 0):
        ADC2_USE_CALIBx.value = 0
    else:
        ADC2_USE_CALIBx.value = 1
    # Update timing for filter
    ADC2_calcTimesChx(channelTabIdx)
    # Update sequencer timings
    ADC2_calcTimesSeq()

def ADC2_updateSeq3Slot3(channelIdx):
    if (channelIdx < ADC2_DIGITAL_CHANNEL_MAX):
        ADC2_S3S3_CH.value = channelIdx
        ADC2_S3S3_NAME_TXT.text = ADC2_channelInselRegisterList[channelIdx].text
        ADC2_S3S3_COLOR.text = ADC2_BLACK_COLOR.text
        ADC2_S3S3_BOXCOLOR.text = ADC2_GREEN_COLOR.text;
    else:
        ADC2_S3S3_COLOR.text = ADC2_BOXCOLOR.text
        ADC2_S3S3_BOXCOLOR.text = ADC2_BOXCOLOR.text;
    # Update sequencer timings
    ADC2_calcTimesSeq()
    
  
#print('Run adc2.py...')
ADC2_CLK_EDIT.connect('textChanged(QString)', ADC2_changeFreq)

ADC2_CHNCFGCONT.connect('currentChanged(int)', ADC2_onChannelTabChange)

ADC2_CHCFG0_REPCH.connect('valueChanged(int)', ADC2_repSelectChx)
ADC2_CHCFG4_REPCH.connect('valueChanged(int)', ADC2_repSelectChx)
ADC2_CHCFG5_REPCH.connect('valueChanged(int)', ADC2_repSelectChx)
ADC2_CHCFG6_REPCH.connect('valueChanged(int)', ADC2_repSelectChx)
ADC2_CHCFG7_REPCH.connect('valueChanged(int)', ADC2_repSelectChx)
ADC2_CHCFG9_REPCH.connect('valueChanged(int)', ADC2_repSelectChx)
ADC2_CHCFG10_REPCH.connect('valueChanged(int)', ADC2_repSelectChx)
ADC2_CHCFG11_REPCH.connect('valueChanged(int)', ADC2_repSelectChx)
ADC2_CHCFG12_REPCH.connect('valueChanged(int)', ADC2_repSelectChx)

ADC2_CALIB0_EN.connect('stateChanged(int)', ADC2_onCalibEn)
ADC2_CALIB1_EN.connect('stateChanged(int)', ADC2_onCalibEn)
ADC2_CALIB2_EN.connect('stateChanged(int)', ADC2_onCalibEn)
ADC2_CALIB3_EN.connect('stateChanged(int)', ADC2_onCalibEn)
ADC2_CALIB4_EN.connect('stateChanged(int)', ADC2_onCalibEn)
ADC2_CALIB5_EN.connect('stateChanged(int)', ADC2_onCalibEn)
ADC2_CALIB6_EN.connect('stateChanged(int)', ADC2_onCalibEn)
ADC2_CALIB7_EN.connect('stateChanged(int)', ADC2_onCalibEn)
ADC2_CALIB8_EN.connect('stateChanged(int)', ADC2_onCalibEn)
ADC2_CALIB9_EN.connect('stateChanged(int)', ADC2_onCalibEn)
ADC2_CALIB10_EN.connect('stateChanged(int)', ADC2_onCalibEn)
ADC2_CALIB11_EN.connect('stateChanged(int)', ADC2_onCalibEn)
ADC2_CALIB12_EN.connect('stateChanged(int)', ADC2_onCalibEn)
ADC2_CALIB13_EN.connect('stateChanged(int)', ADC2_onCalibEn)
ADC2_CALIB14_EN.connect('stateChanged(int)', ADC2_onCalibEn)

ADC2_CHCFG0_CLASSEL.connect('currentIndexChanged(int)', ADC2_classSelectChx)
ADC2_CHCFG4_CLASSEL.connect('currentIndexChanged(int)', ADC2_classSelectChx)
ADC2_CHCFG5_CLASSEL.connect('currentIndexChanged(int)', ADC2_classSelectChx)
ADC2_CHCFG6_CLASSEL.connect('currentIndexChanged(int)', ADC2_classSelectChx)
ADC2_CHCFG7_CLASSEL.connect('currentIndexChanged(int)', ADC2_classSelectChx)
ADC2_CHCFG9_CLASSEL.connect('currentIndexChanged(int)', ADC2_classSelectChx)
ADC2_CHCFG10_CLASSEL.connect('currentIndexChanged(int)', ADC2_classSelectChx)
ADC2_CHCFG11_CLASSEL.connect('currentIndexChanged(int)', ADC2_classSelectChx)
ADC2_CHCFG12_CLASSEL.connect('currentIndexChanged(int)', ADC2_classSelectChx)

ADC2_CONVCFG2_CTRY.connect('textChanged(QString)', ADC2_changeConvClassCat)
ADC2_CONVCFG3_CTRY.connect('textChanged(QString)', ADC2_changeConvClassCat)

ADC2_CONVCFG2_STC.connect('currentIndexChanged(int)', ADC2_STCSelectChx)
ADC2_CONVCFG3_STC.connect('currentIndexChanged(int)', ADC2_STCSelectChx)

ADC2_CHCFG0_FILSEL_user.connect('currentIndexChanged(int)', ADC2_filtSelectChx)
ADC2_CHCFG4_FILSEL_user.connect('currentIndexChanged(int)', ADC2_filtSelectChx)
ADC2_CHCFG5_FILSEL_user.connect('currentIndexChanged(int)', ADC2_filtSelectChx)
ADC2_CHCFG6_FILSEL_user.connect('currentIndexChanged(int)', ADC2_filtSelectChx)
ADC2_CHCFG7_FILSEL_user.connect('currentIndexChanged(int)', ADC2_filtSelectChx)
ADC2_CHCFG9_FILSEL_user.connect('currentIndexChanged(int)', ADC2_filtSelectChx)
ADC2_CHCFG10_FILSEL_user.connect('currentIndexChanged(int)', ADC2_filtSelectChx)
ADC2_CHCFG11_FILSEL_user.connect('currentIndexChanged(int)', ADC2_filtSelectChx)
ADC2_CHCFG12_FILSEL_user.connect('currentIndexChanged(int)', ADC2_filtSelectChx)

ADC2_FILTCFG_COEF_A6.connect('currentIndexChanged(int)', ADC2_filtCoeffSelChx)
ADC2_FILTCFG_COEF_A7.connect('currentIndexChanged(int)', ADC2_filtCoeffSelChx)

ADC2_CHCFG0_CMPSEL_user.connect('currentIndexChanged(int)', ADC2_cmpSelectChx)
ADC2_CHCFG4_CMPSEL_user.connect('currentIndexChanged(int)', ADC2_cmpSelectChx)
ADC2_CHCFG5_CMPSEL_user.connect('currentIndexChanged(int)', ADC2_cmpSelectChx)
ADC2_CHCFG6_CMPSEL_user.connect('currentIndexChanged(int)', ADC2_cmpSelectChx)
ADC2_CHCFG7_CMPSEL_user.connect('currentIndexChanged(int)', ADC2_cmpSelectChx)
ADC2_CHCFG9_CMPSEL_user.connect('currentIndexChanged(int)', ADC2_cmpSelectChx)
ADC2_CHCFG10_CMPSEL_user.connect('currentIndexChanged(int)', ADC2_cmpSelectChx)
ADC2_CHCFG11_CMPSEL_user.connect('currentIndexChanged(int)', ADC2_cmpSelectChx)
ADC2_CHCFG12_CMPSEL_user.connect('currentIndexChanged(int)', ADC2_cmpSelectChx)

ADC2_CMPCFG6_INSEL.connect('textChanged(QString)', ADC2_cmpInputSelChx)
ADC2_CMPCFG7_INSEL.connect('textChanged(QString)', ADC2_cmpInputSelChx)

ADC2_CMPCFG6_MODE.connect('currentIndexChanged(int)', ADC2_cmpModeSelChx)
ADC2_CMPCFG7_MODE.connect('currentIndexChanged(int)', ADC2_cmpModeSelChx)

ADC2_UPPER_TH6.connect('valueChanged(double)', ADC2_cmpUpThSelChx)
ADC2_UPPER_TH7.connect('valueChanged(double)', ADC2_cmpUpThSelChx)

ADC2_LOWER_TH6.connect('valueChanged(double)', ADC2_cmpLoThSelChx)
ADC2_LOWER_TH7.connect('valueChanged(double)', ADC2_cmpLoThSelChx)

ADC2_SQSLOT3_CHSEL3_user.connect('currentIndexChanged(int)', ADC2_updateSeq3Slot3)


# Initialization
# Conversion class
ADC2_CHCFG1_CLASSEL.currentIndex = 1
application.runScript('lock(ADC2.CHCFG1.CLASSEL.value=1)')
ADC2_CHCFG2_CLASSEL.currentIndex = 1
application.runScript('lock(ADC2.CHCFG2.CLASSEL.value=1)')
ADC2_CHCFG3_CLASSEL.currentIndex = 1
application.runScript('lock(ADC2.CHCFG3.CLASSEL.value=1)')
ADC2_CHCFG8_CLASSEL.currentIndex = 0
application.runScript('lock(ADC2.CHCFG8.CLASSEL.value=0)')
ADC2_CHCFG13_CLASSEL.currentIndex = 0
application.runScript('lock(ADC2.CHCFG13.CLASSEL.value=0)')
ADC2_CHCFG14_CLASSEL.currentIndex = 0
application.runScript('lock(ADC2.CHCFG14.CLASSEL.value=0)')

# Number of repetitions
ADC2_CHCFG1_REPCH.value = 1
application.runScript('lock(ADC2.CHCFG1_REPCH.value=1)')
ADC2_CHCFG2_REPCH.value = 1
application.runScript('lock(ADC2.CHCFG2_REPCH.value=1)')
ADC2_CHCFG3_REPCH.value = 1
application.runScript('lock(ADC2.CHCFG3_REPCH.value=1)')
ADC2_CHCFG8_REPCH.value = 1
application.runScript('lock(ADC2.CHCFG8_REPCH.value=1)')
ADC2_CHCFG13_REPCH.value = 1
application.runScript('lock(ADC2.CHCFG13_REPCH.value=1)')
ADC2_CHCFG14_REPCH.value = 1
application.runScript('lock(ADC2.CHCFG14_REPCH.value=1)')

# Filter channels
ADC2_CHCFG1_FILSEL.currentIndex = 0
application.runScript('lock(ADC2.CHCFG1.FILSEL.value=0)')
ADC2_CHCFG2_FILSEL.currentIndex = 1
application.runScript('lock(ADC2.CHCFG2.FILSEL.value=1)')
ADC2_CHCFG3_FILSEL.currentIndex = 2
application.runScript('lock(ADC2.CHCFG3.FILSEL.value=2)')
ADC2_CHCFG8_FILSEL.currentIndex = 3
application.runScript('lock(ADC2.CHCFG8.FILSEL.value=3)')
ADC2_CHCFG13_FILSEL.currentIndex = 4
application.runScript('lock(ADC2.CHCFG13.FILSEL.value=4)')
ADC2_CHCFG14_FILSEL.currentIndex = 5
application.runScript('lock(ADC2.CHCFG14.FILSEL.value=5)')

# Compare Channels
ADC2_CHCFG1_CMPSEL.currentIndex = 0
application.runScript('lock(ADC2.CHCFG1.CMPSEL.value=0)')
ADC2_CHCFG2_CMPSEL.currentIndex = 1
application.runScript('lock(ADC2.CHCFG2.CMPSEL.value=1)')
ADC2_CHCFG3_CMPSEL.currentIndex = 2
application.runScript('lock(ADC2.CHCFG3.CMPSEL.value=2)')
ADC2_CHCFG8_CMPSEL.currentIndex = 3
application.runScript('lock(ADC2.CHCFG8.CMPSEL.value=3)')
ADC2_CHCFG13_CMPSEL.currentIndex = 4
application.runScript('lock(ADC2.CHCFG13.CMPSEL.value=4)')
ADC2_CHCFG14_CMPSEL.currentIndex = 5
application.runScript('lock(ADC2.CHCFG14.CMPSEL.value=5)')

# Conversion class category
if ADC2_CONVCFG0_CTRY.text == '':
    ADC2_CONVCFG0_CTRY.text = 'Low voltage inputs'
    application.runScript('lock(ADC2.CONVCFG0_CTRY.value=Low voltage inputs)')
if ADC2_CONVCFG1_CTRY.text == '':
    ADC2_CONVCFG1_CTRY.text = 'High voltage inputs'
    application.runScript('lock(ADC2.CONVCFG1_CTRY.value=High voltage inputs)')
if ADC2_CONVCFG2_CTRY.text == '':
    ADC2_CONVCFG2_CTRY.text = 'User definable'
if ADC2_CONVCFG3_CTRY.text == '':
    ADC2_CONVCFG3_CTRY.text = 'User definable'

# Sample ticks
ADC2_CONVCFG0_STC.currentIndex = 3
application.runScript('lock(ADC2.CONVCFG0.STC.value=3)')
ADC2_CONVCFG1_STC.currentIndex = 5
application.runScript('lock(ADC2.CONVCFG1.STC.value=5)')

# Filter channels
ADC2_FILTCFG_COEF_A0.currentIndex = 0
application.runScript('lock(ADC2.FILTCFG.COEF_A0.value=0)')
ADC2_FILTCFG_COEF_A1.currentIndex = 0
application.runScript('lock(ADC2.FILTCFG.COEF_A1.value=0)')
ADC2_FILTCFG_COEF_A2.currentIndex = 0
application.runScript('lock(ADC2.FILTCFG.COEF_A2.value=0)')
ADC2_FILTCFG_COEF_A3.currentIndex = 0
application.runScript('lock(ADC2.FILTCFG.COEF_A3.value=0)')
ADC2_FILTCFG_COEF_A4.currentIndex = 0
application.runScript('lock(ADC2.FILTCFG.COEF_A4.value=0)')
ADC2_FILTCFG_COEF_A5.currentIndex = 0
application.runScript('lock(ADC2.FILTCFG.COEF_A5.value=0)')

# Compare channels
ADC2_CMPCFG0_INSEL.text = '1'
application.runScript('lock(ADC2.CMPCFG0.INP_SEL.value=1)')
ADC2_CMPCFG0_MODE.currentIndex = 2
application.runScript('lock(ADC2.CMPCFG0.MODE.value=2)')
ADC2_UPPER_TH0.value = 28.98
application.runScript('lock(ADC2.UPPER_TH0.value=28.98)')
ADC2_CMPCFG0_HYST_UP.currentIndex = 2
application.runScript('lock(ADC2.CMPCFG0.HYST_UP.value=2)')
ADC2_LOWER_TH0.value = 18.07
application.runScript('lock(ADC2.LOWER_TH0.value=18.07)')
ADC2_CMPCFG0_HYST_LO.currentIndex = 2
application.runScript('lock(ADC2.CMPCFG0.HYST_LO.value=2)')
ADC2_CMPCFG0_RST_BLANK_TIME.checked = 0
application.runScript('lock(ADC2.CMPCFG0.RST_BLANK_TIME.value=0)')
ADC2_CMPCFG0_BLANK_TIME.currentIndex = 1
application.runScript('lock(ADC2.CMPCFG0.BLANK_TIME.value=1)')

ADC2_CMPCFG1_INSEL.text = '1'
application.runScript('lock(ADC2.CMPCFG1.INP_SEL.value=1)')
ADC2_CMPCFG1_MODE.currentIndex = 1
application.runScript('lock(ADC2.CMPCFG1.MODE.value=1)')
ADC2_UPPER_TH1.value = 5.30
application.runScript('lock(ADC2.UPPER_TH1.value=5.30)')
ADC2_CMPCFG1_HYST_UP.currentIndex = 2
application.runScript('lock(ADC2.CMPCFG1.HYST_UP.value=2)')
ADC2_LOWER_TH1.value = 5.30
application.runScript('lock(ADC2.LOWER_TH1.value=5.30)')
ADC2_CMPCFG1_HYST_LO.currentIndex = 2
application.runScript('lock(ADC2.CMPCFG1.HYST_LO.value=2)')
ADC2_CMPCFG1_RST_BLANK_TIME.checked = 0
application.runScript('lock(ADC2.CMPCFG1.RST_BLANK_TIME.value=0)')
ADC2_CMPCFG1_BLANK_TIME.currentIndex = 1
application.runScript('lock(ADC2.CMPCFG1.BLANK_TIME.value=1)')

ADC2_CMPCFG2_INSEL.text = '1'
application.runScript('lock(ADC2.CMPCFG2.INP_SEL.value=1)')
ADC2_CMPCFG2_MODE.currentIndex = 0
application.runScript('lock(ADC2.CMPCFG2.MODE.value=0)')
ADC2_UPPER_TH2.value = 44.05
application.runScript('lock(ADC2.UPPER_TH2.value=44.05)')
ADC2_CMPCFG2_HYST_UP.currentIndex = 2
application.runScript('lock(ADC2.CMPCFG2.HYST_UP.value=2)')
ADC2_LOWER_TH2.value = 14.15
application.runScript('lock(ADC2.LOWER_TH2.value=14.15)')
ADC2_CMPCFG2_HYST_LO.currentIndex = 2
application.runScript('lock(ADC2.CMPCFG2.HYST_LO.value=2)')
ADC2_CMPCFG2_RST_BLANK_TIME.checked = 0
application.runScript('lock(ADC2.CMPCFG2.RST_BLANK_TIME.value=0)')
ADC2_CMPCFG2_BLANK_TIME.currentIndex = 1
application.runScript('lock(ADC2.CMPCFG2.BLANK_TIME.value=1)')

ADC2_CMPCFG3_INSEL.text = '1'
application.runScript('lock(ADC2.CMPCFG3.INP_SEL.value=1)')
ADC2_CMPCFG3_MODE.currentIndex = 0
application.runScript('lock(ADC2.CMPCFG3.MODE.value=0)')
ADC2_UPPER_TH3.value = 5.31
application.runScript('lock(ADC2.UPPER_TH3.value=5.31)')
ADC2_CMPCFG3_HYST_UP.currentIndex = 1
application.runScript('lock(ADC2.CMPCFG3.HYST_UP.value=1)')
ADC2_LOWER_TH3.value = 4.60
application.runScript('lock(ADC2.LOWER_TH3.value=4.60)')
ADC2_CMPCFG3_HYST_LO.currentIndex = 1
application.runScript('lock(ADC2.CMPCFG3.HYST_LO.value=1)')
ADC2_CMPCFG3_RST_BLANK_TIME.checked = 0
application.runScript('lock(ADC2.CMPCFG3.RST_BLANK_TIME.value=0)')
ADC2_CMPCFG3_BLANK_TIME.currentIndex = 2
application.runScript('lock(ADC2.CMPCFG3.BLANK_TIME.value=2)')

ADC2_CMPCFG4_INSEL.text = '1'
application.runScript('lock(ADC2.CMPCFG4.INP_SEL.value=1)')
ADC2_CMPCFG4_MODE.currentIndex = 2
application.runScript('lock(ADC2.CMPCFG4.MODE.value=2)')
ADC2_UPPER_TH4.value = 1.07
application.runScript('lock(ADC2.UPPER_TH4.value=1.07)')
ADC2_CMPCFG4_HYST_UP.currentIndex = 1
application.runScript('lock(ADC2.CMPCFG4.HYST_UP.value=1)')
ADC2_LOWER_TH4.value = 0.95
application.runScript('lock(ADC2.LOWER_TH4.value=0.95)')
ADC2_CMPCFG4_HYST_LO.currentIndex = 1
application.runScript('lock(ADC2.CMPCFG4.HYST_LO.value=1)')
ADC2_CMPCFG4_RST_BLANK_TIME.checked = 0
application.runScript('lock(ADC2.CMPCFG4.RST_BLANK_TIME.value=0)')
ADC2_CMPCFG4_BLANK_TIME.currentIndex = 1
application.runScript('lock(ADC2.CMPCFG4.BLANK_TIME.value=1)')

ADC2_CMPCFG5_INSEL.text = '1'
application.runScript('lock(ADC2.CMPCFG5.INP_SEL.value=1)')
ADC2_CMPCFG5_MODE.currentIndex = 2
application.runScript('lock(ADC2.CMPCFG5.MODE.value=2)')
ADC2_UPPER_TH5.value = 1.07
application.runScript('lock(ADC2.UPPER_TH5.value=1.07)')
ADC2_CMPCFG5_HYST_UP.currentIndex = 1
application.runScript('lock(ADC2.CMPCFG5.HYST_UP.value=1)')
ADC2_LOWER_TH5.value = 0.95
application.runScript('lock(ADC2.LOWER_TH5.value=0.95)')
ADC2_CMPCFG5_HYST_LO.currentIndex = 1
application.runScript('lock(ADC2.CMPCFG5.HYST_LO.value=1)')
ADC2_CMPCFG5_RST_BLANK_TIME.checked = 0
application.runScript('lock(ADC2.CMPCFG5.RST_BLANK_TIME.value=0)')
ADC2_CMPCFG5_BLANK_TIME.currentIndex = 1
application.runScript('lock(ADC2.CMPCFG5.BLANK_TIME.value=1)')

# Sequencer
application.runScript('lock(ADC2.SQSLOT0_CHSEL0_user.value=0)')
ADC2_S0S0_CH.value = 0
ADC2_S0S0_NAME_TXT.text = ADC2_channelInselRegisterList[0].text
application.runScript('lock(ADC2.SQSLOT0_CHSEL1_user.value=1)')
ADC2_S0S1_CH.value = 1
ADC2_S0S1_NAME_TXT.text = ADC2_channelInselRegisterList[1].text
application.runScript('lock(ADC2.SQSLOT0_CHSEL2_user.value=2)')
ADC2_S0S2_CH.value = 2
ADC2_S0S2_NAME_TXT.text = ADC2_channelInselRegisterList[2].text
application.runScript('lock(ADC2.SQSLOT0_CHSEL3_user.value=3)')
ADC2_S0S3_CH.value = 3
ADC2_S0S3_NAME_TXT.text = ADC2_channelInselRegisterList[3].text

application.runScript('lock(ADC2.SQSLOT1_CHSEL0_user.value=13)')
ADC2_S1S0_CH.value = 13
ADC2_S1S0_NAME_TXT.text = ADC2_channelInselRegisterList[13].text
application.runScript('lock(ADC2.SQSLOT1_CHSEL1_user.value=4)')
ADC2_S1S1_CH.value = 4
ADC2_S1S1_NAME_TXT.text = ADC2_channelInselRegisterList[4].text
application.runScript('lock(ADC2.SQSLOT1_CHSEL2_user.value=5)')
ADC2_S1S2_CH.value = 5
ADC2_S1S2_NAME_TXT.text = ADC2_channelInselRegisterList[5].text
application.runScript('lock(ADC2.SQSLOT1_CHSEL3_user.value=6)')
ADC2_S1S3_CH.value = 6
ADC2_S1S3_NAME_TXT.text = ADC2_channelInselRegisterList[6].text

application.runScript('lock(ADC2.SQSLOT2_CHSEL0_user.value=7)')
ADC2_S2S0_CH.value = 7
ADC2_S2S0_NAME_TXT.text = ADC2_channelInselRegisterList[7].text
application.runScript('lock(ADC2.SQSLOT2_CHSEL1_user.value=8)')
ADC2_S2S1_CH.value = 8
ADC2_S2S1_NAME_TXT.text = ADC2_channelInselRegisterList[8].text
application.runScript('lock(ADC2.SQSLOT2_CHSEL2_user.value=9)')
ADC2_S2S2_CH.value = 9
ADC2_S2S2_NAME_TXT.text = ADC2_channelInselRegisterList[9].text
application.runScript('lock(ADC2.SQSLOT2_CHSEL3_user.value=10)')
ADC2_S2S3_CH.value = 10
ADC2_S2S3_NAME_TXT.text = ADC2_channelInselRegisterList[10].text

application.runScript('lock(ADC2.SQSLOT3_CHSEL0_user.value=11)')
ADC2_S3S0_CH.value = 11
ADC2_S3S0_NAME_TXT.text = ADC2_channelInselRegisterList[11].text
application.runScript('lock(ADC2.SQSLOT3_CHSEL1_user.value=12)')
ADC2_S3S1_CH.value = 12
ADC2_S3S1_NAME_TXT.text = ADC2_channelInselRegisterList[12].text
application.runScript('lock(ADC2.SQSLOT3_CHSEL2_user.value=14)')
ADC2_S3S2_CH.value = 14
ADC2_S3S2_NAME_TXT.text = ADC2_channelInselRegisterList[14].text
application.runScript('lock(ADC2.SQSLOT3_CHSEL3_user.value=15)')
ADC2_S3S3_CH.value = 15
ADC2_S3S3_NAME_TXT.text = 'none'

application.runScript('lock(ADC2.SQCFG0.SLOTS.value=4)')
application.runScript('lock(ADC2.SQCFG1.SLOTS.value=4)')
application.runScript('lock(ADC2.SQCFG2.SLOTS.value=4)')
application.runScript('setDef(ADC2.SQCFG3.SLOTS.value=3)')

for i, val in enumerate(ADC2_channelDurationList):
    val = ADC2_calcTimesChx(i)

ADC2_INBOX_WIDTH.value = ADC2_inBoxWidth[0]
# Initialize the config by clicking on all channel tabs
for i in range(15):
    ADC2_onChannelTabChange(i)
# Make the tab for Channel 0 active when loading the icwp/xml
ADC2_onChannelTabChange(0)

