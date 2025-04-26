#<checksum>79d371c56ff489327ad395cf0ce87cb4d85cdad145871b0c0ae830ed4abb9786</checksum>
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
# \file     scu.py
#
# \brief    python script to calculate the CCU7 values
#
# \version  V0.1.1
# \date     20. Jul 2022
#

###############################################################################
#                              Author(s) Identity                             #
#*****************************************************************************#
#  Initials     Name                                                          #
#  -------------------------------------------------------------------------- #
#  JO           Julia Ott                                                     #
###############################################################################

###############################################################################
#                           Revision Control History                          #
#*****************************************************************************#
#  V0.1.0: 2022-05-03, JO:   EP-836: Initial version                          #
#  V0.1.1: 2022-07-20, JO:   EP-836: Apply value to SCU_fCPU_MHz_SPIN only in #
#                            case the calculated value is > 0                 #
#                            Moved range checks to python                     #
###############################################################################

# check clock settings
# define limits (Limits from datasheet)
SCU_PLL0_fREF_MHz_MIN = 0.8
SCU_PLL0_fREF_MHz_MAX = 1.27
SCU_PLL0_fVCO_MHz_MIN = 48
SCU_PLL0_fVCO_MHz_MAX = 160
SCU_PLL0_fPLL_MHz_MIN = 5
SCU_PLL0_fPLL_MHz_MAX = 80
SCU_PLL1_fREF_MHz_MIN = 0.8
SCU_PLL1_fREF_MHz_MAX = 1.27
SCU_PLL1_fVCO_MHz_MIN = 48
SCU_PLL1_fVCO_MHz_MAX = 160
SCU_PLL1_fPLL_MHz_MIN = 5
SCU_PLL1_fPLL_MHz_MAX = 80
SCU_fSYS0_MHz_MIN = 5
SCU_fSYS0_MHz_MAX = 60      
SCU_fSYS1_MHz_MIN = 5
SCU_fSYS1_MHz_MAX = 80
# SCU_fOSC_ANALOG_MHz_MAX and SCU_fOSC_DIGITAL_MHz_MAX used in xml directly (var as max in input field)
  
  
def check_range(name, test_val, min, max):
  if (test_val < min) or (test_val > max):
    application.runScript('MessageBox(' + name + ' not in range! \nCurrent value is ' + str(test_val) + '\nValid Range is [' + str(min) + '...' + str(max) + '] \nPlease update your configuration.')
  
  
def calc_clock_tree():
  # XTAL
  local_SCU_fXTAL_MHz = int(SCU_fXTAL_MHz.text)

  # PLL0
  VIS_HP40_2_PLL0.text = "hidden"
  VIS_XTAL_2_PLL0.text = "hidden"
  # fREF
  local_SCU_PLL0_fREF_MHz = 0
  local_SCU_fHP_MHz = int(SCU_fHP_MHz.text.split(' ')[0])
  if PLL_CON0_INSEL.currentData == '1':
    local_SCU_PLL0_fREF_MHz = local_SCU_fXTAL_MHz/int(PLL_CON0_PDIV.value)
    VIS_XTAL_2_PLL0.text = "visible"
  else:
    local_SCU_PLL0_fREF_MHz = local_SCU_fHP_MHz/8/int(PLL_CON0_PDIV.value)
    VIS_HP40_2_PLL0.text = "visible"
  SCU_PLL0_fREF_MHz_SPIN.value = local_SCU_PLL0_fREF_MHz
  # fVCO
  local_SCU_PLL0_fVCO_MHz = local_SCU_PLL0_fREF_MHz*int(PLL_CON0_NDIV.value)
  SCU_PLL0_fVCO_MHz_SPIN.value = local_SCU_PLL0_fVCO_MHz
  # fPLL
  local_SCU_PLL0_fPLL_MHz = local_SCU_PLL0_fVCO_MHz/(int(PLL_CON0_K2DIV.currentIndex)+2)
  SCU_PLL0_fPLL_MHz_SPIN.value = local_SCU_PLL0_fPLL_MHz
  
  # PLL1
  VIS_HP40_2_PLL1.text = "hidden"
  VIS_XTAL_2_PLL1.text = "hidden"
  # fREF
  local_SCU_PLL1_fREF_MHz = 0
  if PLL_CON1_INSEL.currentData == '1':
    local_SCU_PLL1_fREF_MHz = local_SCU_fXTAL_MHz/int(PLL_CON1_PDIV.value)
    VIS_XTAL_2_PLL1.text = "visible"
  else:
    local_SCU_PLL1_fREF_MHz = local_SCU_fHP_MHz/8/int(PLL_CON1_PDIV.value)
    VIS_HP40_2_PLL1.text = "visible"
  SCU_PLL1_fREF_MHz_SPIN.value = local_SCU_PLL1_fREF_MHz
  # fVCO
  local_SCU_PLL1_fVCO_MHz = local_SCU_PLL1_fREF_MHz*int(PLL_CON1_NDIV.value)
  SCU_PLL1_fVCO_MHz_SPIN.value = local_SCU_PLL1_fVCO_MHz
  # fPLL
  local_SCU_PLL1_fPLL_MHz = local_SCU_PLL1_fVCO_MHz/(int(PLL_CON1_K2DIV.currentIndex)+2)
  SCU_PLL1_fPLL_MHz_SPIN.value = local_SCU_PLL1_fPLL_MHz
  
  # fSYS0
  VIS_HP40_2_SYS0.text = "hidden"
  VIS_XTAL_2_SYS0.text = "hidden"
  VIS_PLL0_2_SYS0.text = "hidden"
  VIS_PLL1_2_SYS0.text = "hidden"
  local_SCU_fSYS0_MHz = 0
  if SCU_CLKSEL_SELSYS0.currentIndex == 0:
    local_SCU_fSYS0_MHz = local_SCU_fHP_MHz
    VIS_HP40_2_SYS0.text = "visible"
  elif SCU_CLKSEL_SELSYS0.currentIndex == 1:
    VIS_XTAL_2_SYS0.text = "visible"
    local_SCU_fSYS0_MHz = local_SCU_fXTAL_MHz
  elif SCU_CLKSEL_SELSYS0.currentIndex == 2:
    VIS_PLL0_2_SYS0.text = "visible"
    local_SCU_fSYS0_MHz = local_SCU_PLL0_fPLL_MHz
  else:
    VIS_PLL1_2_SYS0.text = "visible"
    local_SCU_fSYS0_MHz = local_SCU_PLL1_fPLL_MHz
  SCU_fSYS0_MHz_SPIN.value = local_SCU_fSYS0_MHz
  
  # fSYS1
  VIS_HP40_2_SYS1.text = "hidden"
  VIS_XTAL_2_SYS1.text = "hidden"
  VIS_PLL0_2_SYS1.text = "hidden"
  VIS_PLL1_2_SYS1.text = "hidden"
  local_SCU_fSYS1_MHz = 0
  if SCU_CLKSEL_SELSYS1.currentIndex == 0:
    VIS_HP40_2_SYS1.text = "visible"
    local_SCU_fSYS1_MHz = local_SCU_fHP_MHz
  elif SCU_CLKSEL_SELSYS1.currentIndex == 1:
    VIS_XTAL_2_SYS1.text = "visible"
    local_SCU_fSYS1_MHz = local_SCU_fXTAL_MHz
  elif SCU_CLKSEL_SELSYS1.currentIndex == 2:
    VIS_PLL0_2_SYS1.text = "visible"
    local_SCU_fSYS1_MHz = local_SCU_PLL0_fPLL_MHz
  else:
    VIS_PLL1_2_SYS1.text = "visible"
    local_SCU_fSYS1_MHz = local_SCU_PLL1_fPLL_MHz
  SCU_fSYS1_MHz_SPIN.value = local_SCU_fSYS1_MHz
  
  # additional prescaler
  SCU_fX_MHz_presc_array = [1, 2, 3, 4, 5, 8, 16, 20]
  # fCPU, fPER
  SCU_fCPU_MHz_presc_idx = SCU_CLKCON_PRECPU.currentIndex
  freq_temp = local_SCU_fSYS0_MHz / SCU_fX_MHz_presc_array[SCU_fCPU_MHz_presc_idx]
  if freq_temp > 0:
    SCU_fCPU_MHz_SPIN.value = local_SCU_fSYS0_MHz / SCU_fX_MHz_presc_array[SCU_fCPU_MHz_presc_idx]
  # fMI
  SCU_fMI_MHz_presc_idx = SCU_CLKCON_PREMI.currentIndex
  SCU_fMI_MHz_SPIN.value = local_SCU_fSYS0_MHz / SCU_fX_MHz_presc_array[SCU_fMI_MHz_presc_idx]
  # fTFILT done in XML
  # fCAN
  SCU_fCAN_MHz_presc_idx = SCU_CLKCON_PRECAN.currentIndex
  SCU_fCAN_MHz_SPIN.value = local_SCU_fSYS1_MHz / SCU_fX_MHz_presc_array[SCU_fCAN_MHz_presc_idx]
  # fUART
  SCU_fUART_MHz_presc_idx = SCU_CLKCON_PREUART.currentIndex
  SCU_fUART_MHz_SPIN.value = local_SCU_fSYS1_MHz / SCU_fX_MHz_presc_array[SCU_fUART_MHz_presc_idx]
    
  # check range
  check_range('PLL0 fREF', local_SCU_PLL0_fREF_MHz, SCU_PLL0_fREF_MHz_MIN, SCU_PLL0_fREF_MHz_MAX)
  check_range('PLL0 fVCO', local_SCU_PLL0_fVCO_MHz, SCU_PLL0_fVCO_MHz_MIN, SCU_PLL0_fVCO_MHz_MAX)
  check_range('PLL0 fPLL', local_SCU_PLL0_fPLL_MHz, SCU_PLL0_fPLL_MHz_MIN, SCU_PLL0_fPLL_MHz_MAX)
  check_range('PLL1 fREF', local_SCU_PLL1_fREF_MHz, SCU_PLL1_fREF_MHz_MIN, SCU_PLL1_fREF_MHz_MAX)
  check_range('PLL1 fVCO', local_SCU_PLL1_fVCO_MHz, SCU_PLL1_fVCO_MHz_MIN, SCU_PLL1_fVCO_MHz_MAX)
  check_range('PLL1 fPLL', local_SCU_PLL1_fPLL_MHz, SCU_PLL1_fPLL_MHz_MIN, SCU_PLL1_fPLL_MHz_MAX)
  check_range('fSYS0', local_SCU_fSYS0_MHz, SCU_fSYS0_MHz_MIN, SCU_fSYS0_MHz_MAX)
  check_range('fSYS1', local_SCU_fSYS1_MHz, SCU_fSYS1_MHz_MIN, SCU_fSYS1_MHz_MAX)

  application.runScript("setDef(scu_clk_graph.update=1)")





calc_clock_tree()


# connect
# combo.connect('currentIndexChanged(int)', function)
# checkbox.connect('stateChanged(int)', function)
# edit.connect('textChanged(QString)', function)
# Clock sources --> XTAL
SCU_XTALCON_XPD.connect('stateChanged(int)', calc_clock_tree)
SCU_fXTAL_MHz.connect('valueChanged(int)', calc_clock_tree)

# Clock sources --> PLL0
SCU_PLL0_EN.connect('stateChanged(int)', calc_clock_tree)
PLL_CON0_INSEL.connect('currentIndexChanged(int)', calc_clock_tree)
PLL_CON0_PDIV.connect('valueChanged(int)', calc_clock_tree)
PLL_CON0_NDIV.connect('valueChanged(int)', calc_clock_tree)
PLL_CON0_K2DIV.connect('currentIndexChanged(int)', calc_clock_tree)

# Clock sources --> PLL1
SCU_PLL1_EN.connect('stateChanged(int)', calc_clock_tree)
PLL_CON1_INSEL.connect('currentIndexChanged(int)', calc_clock_tree)
PLL_CON1_PDIV.connect('valueChanged(int)', calc_clock_tree)
PLL_CON1_NDIV.connect('valueChanged(int)', calc_clock_tree)
PLL_CON1_K2DIV.connect('currentIndexChanged(int)', calc_clock_tree)

# Clock tree --> fSYS0
SCU_CLKSEL_SELSYS0.connect('currentIndexChanged(int)', calc_clock_tree)
SCU_CLKCON_PRECPU.connect('currentIndexChanged(int)', calc_clock_tree)
SCU_CLKCON_PREMI.connect('currentIndexChanged(int)', calc_clock_tree)
SCU_fTFILT_PRESCALER.connect('valueChanged(int)', calc_clock_tree)

# Clock tree --> fSYS0
SCU_CLKSEL_SELSYS1.connect('currentIndexChanged(int)', calc_clock_tree)
SCU_CLKCON_PREUART.connect('currentIndexChanged(int)', calc_clock_tree)
SCU_CLKCON_PRECAN.connect('currentIndexChanged(int)', calc_clock_tree)




