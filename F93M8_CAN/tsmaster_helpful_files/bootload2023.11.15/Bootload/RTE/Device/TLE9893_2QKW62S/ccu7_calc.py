#<checksum>6f508dd6327695888a2517d6561c77408c0444c66ccd0a3d085b57923bf8ec2b</checksum>
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
# \file     ccu7_calc.py
#
# \brief    python script to calculate the CCU7 values
#
# \version  V0.1.6
# \date     30. Nov 2021
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
#  V0.1.0: 2020-10-14, JO:   Initial version with connect functionality       #
#  V0.1.1: 2020-10-23, JO:   Handled underflow warning of T1x period register #
#                            while changing the clock                         #
#  V0.1.2: 2020-11-04, JO:   EP-568: Added checksum                           #
#  V0.1.3: 2020-11-06, JO:   EP-555: Added support for 'T13 modulates ...'    #
#                            to graph                                         #
#                            Restructured Modulation configuration            #
#  V0.1.4: 2020-11-13, JO:   EP-592: Corrected CCU7 output signal graph in    #
#                            case no modulation is selected                   #
#  V0.1.5: 2020-12-02, JO:   EP-630: Added call of calc_ccu7() to             #
#                            initialize the graph                             #
#  V0.1.6: 2021-11-30, JO:   EP-937: Updated copyright and branding           #
###############################################################################

def get_ratio_scaled(a, b, lower_limit, upper_limit):
    if b == 0:
        if a == 0:
            ratio = 1
        else:
            ratio = 1.2
    else:
        ratio = a / b
    if ratio < lower_limit:
        ratio = lower_limit
    if ratio > upper_limit:
        ratio = upper_limit
    return ratio


# classes
class LineClass:
    def __init__(self):
        self.x1 = 0
        self.y1 = 0
        self.x2 = 0
        self.y2 = 0


class CoordinatesClass:
    def __init__(self, x, y):
        self.x = x
        self.y = y


class DotClass:
    def __init__(self):
        self.x1 = 0
        self.x2 = 0
        self.x3 = 0
        self.y = 0


class TrigselClass:
    def __init__(self):
        self.group_coordinates_init = CoordinatesClass(80, 80)
        self.group_coordinates_add = CoordinatesClass(0, 0)
        self.group_coordinates_sum = CoordinatesClass(0, 0)
        self.trigsel_label_text = ''
        self.t12_cntdir_text = ''


class TimerGraphClass:
    width = 150
    height = 60

    def __init__(self):
        self.trigsel = TrigselClass()
        self.up_line = LineClass()
        self.down_line = LineClass()
        self.d_line = LineClass()
        self.n_line = LineClass()
        self.n_dots = DotClass()
        self.arrow = LineClass()
        self.arrow_label_y = 0


class TimerClass:
    t12_fullper_ticks = 0

    def __init__(self, name, input_val, input_unit, mode, singleshot, trigsel, trigdir, clk):
        # input
        self.name = name
        self.input_val = int(input_val)
        self.input_unit = int(input_unit)
        self.mode = int(mode)
        self.singleshot = int(singleshot)
        self.trigsel = int(trigsel)
        self.trigdir = int(trigdir)
        self.clk = float(clk[:-3])

        # output
        self.regval = 0
        self.per_ticks = 0
        self.fullper_ticks = 0
        self.timer_graph = TimerGraphClass()

        if self.input_unit == 0:  # ticks
            self.fullper_ticks = self.input_val
        if self.input_unit == 1:  # time[us]
            self.fullper_ticks = self.input_val * self.clk
        if self.input_unit == 2:  # frequency[Hz]
            self.fullper_ticks = (self.clk * 1e6 / self.input_val)
        self.per_ticks = int(self.fullper_ticks / (1 + self.mode))  # period = fullper = /2 at mode = 1
        self.regval = self.per_ticks - 1
        if self.regval < 0: # not ok, unterflow in timer period register
            self.per_ticks = 1
            self.fullper_ticks = self.per_ticks * (1 + self.mode)
            self.regval = 0

        if self.name == 't12':
            TimerClass.t12_fullper_ticks = self.fullper_ticks

        ratio = get_ratio_scaled(self.fullper_ticks, TimerClass.t12_fullper_ticks, 0.2, 1.2)

        self.timer_graph.up_line.x1 = 0
        self.timer_graph.up_line.y1 = 0

        if self.mode == 0:  # edge aligned
            self.timer_graph.up_line.x2 = self.timer_graph.up_line.x1 + ratio * self.timer_graph.width
            self.timer_graph.up_line.y2 = self.timer_graph.up_line.y1 - ratio * self.timer_graph.height

            self.timer_graph.down_line.x1 = self.timer_graph.up_line.x1
            self.timer_graph.down_line.y1 = self.timer_graph.up_line.y1
            self.timer_graph.down_line.x2 = self.timer_graph.up_line.x2
            self.timer_graph.down_line.y2 = self.timer_graph.up_line.y2

            self.timer_graph.d_line.x1 = self.timer_graph.up_line.x2
            self.timer_graph.d_line.y1 = self.timer_graph.down_line.y1
            self.timer_graph.d_line.x2 = self.timer_graph.d_line.x1
            self.timer_graph.d_line.y2 = self.timer_graph.down_line.y2

            if self.singleshot == 0:
                # continuous mode, show new period
                self.timer_graph.n_line.x1 = self.timer_graph.d_line.x1
                self.timer_graph.n_line.y1 = self.timer_graph.d_line.y1
                self.timer_graph.n_line.x2 = self.timer_graph.n_line.x1 + ratio * self.timer_graph.width * 0.25
                self.timer_graph.n_line.y2 = self.timer_graph.n_line.y1 - ratio * self.timer_graph.height * 0.25

                self.timer_graph.n_dots.x1 = self.timer_graph.n_line.x2 + 5
                self.timer_graph.n_dots.x2 = self.timer_graph.n_line.x2 + 10
                self.timer_graph.n_dots.x3 = self.timer_graph.n_line.x2 + 15
                self.timer_graph.n_dots.y = self.timer_graph.n_line.y2 + 5
            else:
                # single shot mode, don't show new period
                self.timer_graph.n_line.x1 = self.timer_graph.d_line.x1
                self.timer_graph.n_line.y1 = self.timer_graph.d_line.y1
                self.timer_graph.n_line.x2 = self.timer_graph.n_line.x1
                self.timer_graph.n_line.y2 = self.timer_graph.n_line.y1

                self.timer_graph.n_dots.x1 = self.timer_graph.n_line.x2
                self.timer_graph.n_dots.x2 = self.timer_graph.n_line.x2
                self.timer_graph.n_dots.x3 = self.timer_graph.n_line.x2
                self.timer_graph.n_dots.y = self.timer_graph.n_line.y2

        if self.mode == 1:  # center aligned
            self.timer_graph.up_line.x2 = self.timer_graph.up_line.x1 + ratio * self.timer_graph.width / 2
            self.timer_graph.up_line.y2 = self.timer_graph.up_line.y1 - ratio * self.timer_graph.height

            self.timer_graph.down_line.x1 = self.timer_graph.up_line.x1 + ratio * self.timer_graph.width
            self.timer_graph.down_line.y1 = self.timer_graph.up_line.y1
            self.timer_graph.down_line.x2 = self.timer_graph.up_line.x2
            self.timer_graph.down_line.y2 = self.timer_graph.up_line.y2

            self.timer_graph.d_line.x1 = self.timer_graph.down_line.x1
            self.timer_graph.d_line.y1 = self.timer_graph.down_line.y1
            self.timer_graph.d_line.x2 = self.timer_graph.down_line.x2
            self.timer_graph.d_line.y2 = self.timer_graph.down_line.y2

            if self.singleshot == 0:
                # continuous mode, show new period
                self.timer_graph.n_line.x1 = self.timer_graph.d_line.x1
                self.timer_graph.n_line.y1 = self.timer_graph.d_line.y1
                self.timer_graph.n_line.x2 = self.timer_graph.n_line.x1 + ratio * self.timer_graph.width / 2 * 0.25
                self.timer_graph.n_line.y2 = self.timer_graph.n_line.y1 - ratio * self.timer_graph.height * 0.25

                self.timer_graph.n_dots.x1 = self.timer_graph.n_line.x2 + 5
                self.timer_graph.n_dots.x2 = self.timer_graph.n_line.x2 + 10
                self.timer_graph.n_dots.x3 = self.timer_graph.n_line.x2 + 15
                self.timer_graph.n_dots.y = self.timer_graph.n_line.y2 + 10
            else:
                # single shot mode, don't show new period
                self.timer_graph.n_line.x1 = self.timer_graph.d_line.x1
                self.timer_graph.n_line.y1 = self.timer_graph.d_line.y1
                self.timer_graph.n_line.x2 = self.timer_graph.n_line.x1
                self.timer_graph.n_line.y2 = self.timer_graph.n_line.y1

                self.timer_graph.n_dots.x1 = self.timer_graph.n_line.x2
                self.timer_graph.n_dots.x2 = self.timer_graph.n_line.x2
                self.timer_graph.n_dots.x3 = self.timer_graph.n_line.x2
                self.timer_graph.n_dots.y = self.timer_graph.n_line.y1

        self.timer_graph.arrow.x1 = self.timer_graph.up_line.x1
        self.timer_graph.arrow.y1 = self.timer_graph.up_line.y1 + 5
        self.timer_graph.arrow.x2 = self.timer_graph.d_line.x1
        self.timer_graph.arrow.y2 = self.timer_graph.d_line.y1 + 5
        self.timer_graph.arrow_label_y = self.timer_graph.arrow.y1 + 10

        self.timer_graph.trigsel.group_coordinates_add.y = 0

    def calc_trigsel(self, trigsel_ref):
        if self.name == "t12":
            # self.timer_graph.trigsel.group_coordinates_add.x = 0
            self.timer_graph.trigsel_label_text = ""
        else:
            # check trigsel_ref if trigger event direction =! 0
            # 0 means no trigger, 1: T12 up, 2: T12 down, 3: T12 up/down
            # self.timer_graph.trigsel.group_coordinates_add.x = trigsel_ref[self.name][self.trigsel]['value']
            if self.trigdir == 0:
                # TEC not valid
                self.timer_graph.trigsel.trigsel_label_text = ''
                self.timer_graph.trigsel.t12_cntdir_text = ''
            if self.trigdir == 1:
                # T12 counting up
                self.timer_graph.trigsel.trigsel_label_text = trigsel_ref[self.name][self.trigsel]['label']
                self.timer_graph.trigsel.t12_cntdir_text = 'T12 CDIR=0 (up)'
            if self.trigdir == 2:
                # T12 counting down
                self.timer_graph.trigsel.trigsel_label_text = trigsel_ref[self.name][self.trigsel]['label']
                self.timer_graph.trigsel.t12_cntdir_text = 'T12 CDIR=1 (down)'
            if self.trigdir == 3:
                # T12 counting up/down --> up condition fulfilled first
                self.timer_graph.trigsel.trigsel_label_text = trigsel_ref[self.name][self.trigsel]['label']
                self.timer_graph.trigsel.t12_cntdir_text = 'T12 CDIR=0/1 (up/down)'

        self.timer_graph.trigsel.group_coordinates_sum.x = self.timer_graph.trigsel.group_coordinates_init.x + self.timer_graph.trigsel.group_coordinates_add.x
        self.timer_graph.trigsel.group_coordinates_sum.y = self.timer_graph.trigsel.group_coordinates_init.y + self.timer_graph.trigsel.group_coordinates_add.y

    def save(self):
        # period values
        exec("%s = %s" % ("CCU7_" + self.name.upper() + "_PERIOD_FULL.value", self.fullper_ticks))
        exec("%s = %s" % ("CCU7_" + self.name.upper() + "_PERIOD.value", self.per_ticks))
        
        ref_xml = 'CCU7_GRAPH_' + self.name.upper() + '_'

        exec("%s = %s" % (ref_xml + "OFFSET_x.value", self.timer_graph.trigsel.group_coordinates_sum.x))
        exec("%s = %s" % (ref_xml + "OFFSET_y.value", self.timer_graph.trigsel.group_coordinates_sum.y))
        # string needs quotes
        exec("%s = %s" % (ref_xml + "TRIGSEL_TEXT.text", "self.timer_graph.trigsel.trigsel_label_text"))
        exec("%s = %s" % (ref_xml + "T12_CNTDIR_TEXT.text", "self.timer_graph.trigsel.t12_cntdir_text"))

        exec("%s = %s" % (ref_xml + "UP_BEG_x.value", self.timer_graph.up_line.x1))
        exec("%s = %s" % (ref_xml + "UP_BEG_y.value", self.timer_graph.up_line.y1))
        exec("%s = %s" % (ref_xml + "UP_END_x.value", self.timer_graph.up_line.x2))
        exec("%s = %s" % (ref_xml + "UP_END_y.value", self.timer_graph.up_line.y2))

        exec("%s = %s" % (ref_xml + "DOWN_BEG_x.value", self.timer_graph.down_line.x1))
        exec("%s = %s" % (ref_xml + "DOWN_BEG_y.value", self.timer_graph.down_line.y1))
        exec("%s = %s" % (ref_xml + "DOWN_END_x.value", self.timer_graph.down_line.x2))
        exec("%s = %s" % (ref_xml + "DOWN_END_y.value", self.timer_graph.down_line.y2))

        exec("%s = %s" % (ref_xml + "DUMMY_BEG_x.value", self.timer_graph.d_line.x1))
        exec("%s = %s" % (ref_xml + "DUMMY_BEG_y.value", self.timer_graph.d_line.y1))
        exec("%s = %s" % (ref_xml + "DUMMY_END_x.value", self.timer_graph.d_line.x2))
        exec("%s = %s" % (ref_xml + "DUMMY_END_y.value", self.timer_graph.d_line.y2))

        exec("%s = %s" % (ref_xml + "NEWPER_BEG_x.value", self.timer_graph.n_line.x1))
        exec("%s = %s" % (ref_xml + "NEWPER_BEG_y.value", self.timer_graph.n_line.y1))
        exec("%s = %s" % (ref_xml + "NEWPER_END_x.value", self.timer_graph.n_line.x2))
        exec("%s = %s" % (ref_xml + "NEWPER_END_y.value", self.timer_graph.n_line.y2))

        exec("%s = %s" % (ref_xml + "DOT1_x.value", self.timer_graph.n_dots.x1))
        exec("%s = %s" % (ref_xml + "DOT2_x.value", self.timer_graph.n_dots.x2))
        exec("%s = %s" % (ref_xml + "DOT3_x.value", self.timer_graph.n_dots.x3))
        exec("%s = %s" % (ref_xml + "DOTs_y.value", self.timer_graph.n_dots.y))

        exec("%s = %s" % (ref_xml + "ARROW_BEG_x.value", self.timer_graph.arrow.x1))
        exec("%s = %s" % (ref_xml + "ARROW_BEG_y.value", self.timer_graph.arrow.y1))
        exec("%s = %s" % (ref_xml + "ARROW_END_x.value", self.timer_graph.arrow.x2))
        exec("%s = %s" % (ref_xml + "ARROW_END_y.value", self.timer_graph.arrow.y2))
        exec("%s = %s" % (ref_xml + "ARROW_LABEL_y.value", self.timer_graph.arrow_label_y))


class CmpClassGraph:
    def __init__(self):
        self.circle = CoordinatesClass(0, 0)


class CmpClass:
    def __init__(self, name, input_val, input_unit, cmp_group, timer):
        self.name = name.lower()
        self.input_val = int(input_val)
        self.input_unit = int(input_unit)
        self.cmp_group = cmp_group
        self.regval = 0
        self.timer = timer
        self.graph_up = CmpClassGraph()
        self.graph_down = CmpClassGraph()

        if self.input_unit == 0:  # ticks
            self.regval = self.input_val
        if self.input_unit == 1:  # time[us]
            self.regval = self.input_val * self.timer.clk
        if self.input_unit == 2:  # duty cycle[%]
            self.regval = int((self.input_val / 100) * (self.timer.regval + 1))

        # self.timer.regval + 1 because timer counts up to 1 above the register value
        ratio = get_ratio_scaled(self.regval, self.timer.regval + 1, 0, 1.2)

        # always use up_line
        line = self.timer.timer_graph.up_line
        self.graph_up.circle.x = line.x1 + ratio * (line.x2 - line.x1)
        self.graph_up.circle.y = line.y1 + ratio * (line.y2 - line.y1)

        # if center aligned: also use down_line
        if self.timer.mode == 1:
            line = self.timer.timer_graph.down_line
            self.graph_down.circle.x = line.x1 + ratio * (line.x2 - line.x1)
            self.graph_down.circle.y = line.y1 + ratio * (line.y2 - line.y1)

    def save(self):
        # compare value
        ref_xml = 'CCU7_' + self.name.upper() + '_CMPVAL_CALC'
        exec("%s = %s" % (ref_xml + ".value", "self.regval"))
        ref_xml = 'CCU7_GRAPH_' + self.name.upper() + '_'
        exec("%s = %s" % (ref_xml + "UP_x.value", "self.graph_up.circle.x"))
        exec("%s = %s" % (ref_xml + "UP_y.value", "self.graph_up.circle.y"))

        if self.timer.mode == 1:
            exec("%s = %s" % (ref_xml + "DOWN_x.value", "self.graph_down.circle.x"))
            exec("%s = %s" % (ref_xml + "DOWN_y.value", "self.graph_down.circle.y"))
        else:
            # put the circles somewhere where they are not visible
            exec("%s = %d" % (ref_xml + "DOWN_x.value", -100))
            exec("%s = %d" % (ref_xml + "DOWN_y.value", -100))


class DeadtimeGraph:
    def __init__(self):
        self.offset_x = 0
        self.coordinates = []
        self.coordinates.append(CoordinatesClass(0, 0))
        self.coordinates.append(CoordinatesClass(0, 0))
        self.coordinates.append(CoordinatesClass(0, 0))
        self.coordinates.append(CoordinatesClass(0, 0))
        self.coordinates.append(CoordinatesClass(0, 0))
        self.coordinates.append(CoordinatesClass(0, 0))
        self.coordinates.append(CoordinatesClass(0, 0))
        self.coordinates.append(CoordinatesClass(0, 0))
        self.color = 'black'
        self.doublemod_visible = 'hidden'
        self.doublemod_coordinates1 = []
        self.doublemod_coordinates1.append(CoordinatesClass(0, 0))
        self.doublemod_coordinates1.append(CoordinatesClass(0, 0))
        self.doublemod_coordinates1.append(CoordinatesClass(0, 0))
        self.doublemod_coordinates1.append(CoordinatesClass(0, 0))
        self.doublemod_coordinates2 = []
        self.doublemod_coordinates2.append(CoordinatesClass(0, 0))
        self.doublemod_coordinates2.append(CoordinatesClass(0, 0))
        self.doublemod_coordinates2.append(CoordinatesClass(0, 0))
        self.doublemod_coordinates2.append(CoordinatesClass(0, 0))


class DeadtimeClass:
    def __init__(self, channel_name, dtinsel, passive_state, passive_level, cmp_a, cmp_b, c73, timer, timercmp, dten,
                 t12moden, t13moden, capcom_mode):
        self.channel_name = channel_name.lower()
        self.dtinsel = int(dtinsel)
        self.passive_state = int(passive_state) # 0: before cmp, 1: after cmp
        self.passive_level = int(passive_level) # 0:low, 1: high
        self.cmp_a = cmp_a
        self.cmp_b = cmp_b
        self.c73 = c73
        self.timer = timer
        self.timercmp = timercmp
        self.dten = dten
        self.polyline = DeadtimeGraph()
        self.t12moden = int(t12moden)
        self.t13moden = int(t13moden)
        self.capcom_mode = int(capcom_mode)
        self.doublemod = "hidden"

        # set color to black if compare output enabled, else grey
        if 'cout' in self.channel_name:
            # values 2 and 3
            if self.capcom_mode == 2 or self.capcom_mode == 3:
                self.polyline.color = 'black'
            else:
                self.polyline.color = 'grey'
        else:
            # values 1 and 3
            if self.capcom_mode == 1 or self.capcom_mode == 3:
                self.polyline.color = 'black'
            else:
                self.polyline.color = 'grey'

        def ba_line(change1, end, dten):
            # _|-| line / -|_| line
            self.polyline.coordinates[3].x = change1
            self.polyline.coordinates[4].x = change1
            self.polyline.coordinates[4].y = y_aftercmp
            self.polyline.coordinates[5].x = end
            self.polyline.coordinates[5].y = y_aftercmp
            self.polyline.coordinates[6].x = end
            self.polyline.coordinates[7].x = end

            if dten == 1:
                if self.passive_state == 0:
                    # passive state before cmp, active state begins at 3/4
                    distance = self.polyline.coordinates[5].x - self.polyline.coordinates[4].x
                    if distance < 10:
                        self.polyline.coordinates[3].x = self.polyline.coordinates[5].x
                        self.polyline.coordinates[4].x = self.polyline.coordinates[5].x
                    else:
                        self.polyline.coordinates[3].x += 10
                        self.polyline.coordinates[4].x += 10
                else:
                    # passive state after cmp, active state begins at 0/1
                    self.polyline.coordinates[0].y = y_aftercmp
                    self.polyline.coordinates[1].y = y_aftercmp
                    distance = self.polyline.coordinates[3].x - self.polyline.coordinates[2].x
                    if distance < 10:
                        self.polyline.coordinates[1].x = self.polyline.coordinates[3].x
                        self.polyline.coordinates[2].x = self.polyline.coordinates[3].x
                    else:
                        self.polyline.coordinates[1].x += 10
                        self.polyline.coordinates[2].x += 10
                        
            if self.passive_state == 0: 
                # pasive state before cmp --> active state after cmp (3/4 to 5/6), coord2 is equal to coord1
                self.polyline.doublemod_coordinates1[0].x = self.polyline.coordinates[3].x
                self.polyline.doublemod_coordinates1[0].y = self.polyline.coordinates[3].y
                self.polyline.doublemod_coordinates1[1].x = self.polyline.coordinates[4].x
                self.polyline.doublemod_coordinates1[1].y = self.polyline.coordinates[4].y
                self.polyline.doublemod_coordinates1[2].x = self.polyline.coordinates[5].x
                self.polyline.doublemod_coordinates1[2].y = self.polyline.coordinates[5].y
                self.polyline.doublemod_coordinates1[3].x = self.polyline.coordinates[6].x
                self.polyline.doublemod_coordinates1[3].y = self.polyline.coordinates[6].y
            else:
                # pasive state after cmp --> active state before cmp (1/2 to 3/4), coord2 is equal to coord1
                self.polyline.doublemod_coordinates1[0].x = self.polyline.coordinates[1].x
                self.polyline.doublemod_coordinates1[0].y = self.polyline.coordinates[4].y # take y coord. from 4
                self.polyline.doublemod_coordinates1[1].x = self.polyline.coordinates[2].x
                self.polyline.doublemod_coordinates1[1].y = self.polyline.coordinates[2].y
                self.polyline.doublemod_coordinates1[2].x = self.polyline.coordinates[3].x
                self.polyline.doublemod_coordinates1[2].y = self.polyline.coordinates[3].y
                self.polyline.doublemod_coordinates1[3].x = self.polyline.coordinates[4].x
                self.polyline.doublemod_coordinates1[3].y = self.polyline.coordinates[4].y
                

        def bab_line(change1, change2, end, dten):
            # _|-|_ line / -|_|- line
            self.polyline.coordinates[3].x = change1
            self.polyline.coordinates[4].x = change1
            self.polyline.coordinates[4].y = y_aftercmp
            self.polyline.coordinates[5].x = change2
            self.polyline.coordinates[5].y = y_aftercmp
            self.polyline.coordinates[6].x = change2
            self.polyline.coordinates[7].x = end

            if dten == 1:
                if self.passive_state == 0:
                    # passive state before cmp, active state begins at 3/4
                    distance = self.polyline.coordinates[5].x - self.polyline.coordinates[4].x
                    if distance < 10:
                        self.polyline.coordinates[3].x = self.polyline.coordinates[5].x
                        self.polyline.coordinates[4].x = self.polyline.coordinates[5].x
                    else:
                        self.polyline.coordinates[3].x += 10
                        self.polyline.coordinates[4].x += 10
                else:
                    # passive state after cmp, active state begins at 5/6
                    distance = self.polyline.coordinates[7].x - self.polyline.coordinates[6].x
                    if distance < 10:
                        self.polyline.coordinates[5].x = self.polyline.coordinates[7].x
                        self.polyline.coordinates[6].x = self.polyline.coordinates[7].x
                    else:
                        self.polyline.coordinates[5].x += 10
                        self.polyline.coordinates[6].x += 10
                        
            if self.passive_state == 0: 
                # pasive state after cmp --> active state in the middle (3/4 to 5/6)
                self.polyline.doublemod_coordinates1[0].x = self.polyline.coordinates[3].x
                self.polyline.doublemod_coordinates1[0].y = self.polyline.coordinates[3].y
                self.polyline.doublemod_coordinates1[1].x = self.polyline.coordinates[4].x
                self.polyline.doublemod_coordinates1[1].y = self.polyline.coordinates[4].y
                self.polyline.doublemod_coordinates1[2].x = self.polyline.coordinates[5].x
                self.polyline.doublemod_coordinates1[2].y = self.polyline.coordinates[5].y
                self.polyline.doublemod_coordinates1[3].x = self.polyline.coordinates[6].x
                self.polyline.doublemod_coordinates1[3].y = self.polyline.coordinates[6].y
            else:
                # pasive state before cmp --> two boxes (1/2 to 3/4 and 5/6 to 7/7-4mix)
                self.polyline.doublemod_coordinates1[0].x = self.polyline.coordinates[1].x
                self.polyline.doublemod_coordinates1[0].y = self.polyline.coordinates[4].y # take y coord. from 4
                self.polyline.doublemod_coordinates1[1].x = self.polyline.coordinates[2].x
                self.polyline.doublemod_coordinates1[1].y = self.polyline.coordinates[2].y
                self.polyline.doublemod_coordinates1[2].x = self.polyline.coordinates[3].x
                self.polyline.doublemod_coordinates1[2].y = self.polyline.coordinates[3].y
                self.polyline.doublemod_coordinates1[3].x = self.polyline.coordinates[4].x
                self.polyline.doublemod_coordinates1[3].y = self.polyline.coordinates[4].y
                
                self.polyline.doublemod_coordinates2[0].x = self.polyline.coordinates[5].x
                self.polyline.doublemod_coordinates2[0].y = self.polyline.coordinates[5].y
                self.polyline.doublemod_coordinates2[1].x = self.polyline.coordinates[6].x
                self.polyline.doublemod_coordinates2[1].y = self.polyline.coordinates[6].y
                self.polyline.doublemod_coordinates2[2].x = self.polyline.coordinates[7].x
                self.polyline.doublemod_coordinates2[2].y = self.polyline.coordinates[7].y
                self.polyline.doublemod_coordinates2[3].x = self.polyline.coordinates[7].x
                self.polyline.doublemod_coordinates2[3].y = self.polyline.coordinates[5].y # take y coord. from 5

        # calc
        # hide all doublemod related elements, polyline box has 0 size
        self.polyline.doublemod_visible = 'hidden'
        for coordinate in self.polyline.doublemod_coordinates1:
            coordinate.x = 0
            coordinate.y = 0
        for coordinate in self.polyline.doublemod_coordinates2:
            coordinate.x = 0
            coordinate.y = 0
        
        # no modulation
        if self.t12moden == 0 and self.t13moden == 0:
            # cc7x: high = 10, low = 30; cout7x: high = 40, low = 60
            y_beforecmp = 30

            if 'cout' in self.channel_name:
                # cout7x channel --> y_beforecmp += 30
                y_beforecmp = y_beforecmp + 30
            
            # currently low, subtract 20 to reach high
            if self.passive_level == 1:
                y_beforecmp = y_beforecmp - 20
                
            # set all coordinates to the 'end point' (x = timer peak, y = level before cmp)
            for coordinate in self.polyline.coordinates:
                coordinate.x = self.cmp_a.timer.timer_graph.n_line.x1
                coordinate.y = y_beforecmp

            # create always passive signal over the timer length, for coord0/1/2
            
            self.polyline.coordinates[0].x = self.cmp_a.timer.timer_graph.up_line.x1
            self.polyline.coordinates[1].x = self.cmp_a.timer.timer_graph.up_line.x1
            self.polyline.coordinates[2].x = self.cmp_a.timer.timer_graph.up_line.x1
            self.polyline.offset_x = 80

        # t12 modulation, with or without T13 modulation
        if self.t12moden == 1:
            # draw T12 line
            # cc7x: high = 10, low = 30; cout7x: high = 40, low = 60
            if (self.passive_level == 0 and self.passive_state == 0) or (
                    self.passive_level == 1 and self.passive_state == 1):
                y_beforecmp = 30
                y_aftercmp = 10
            else:
                y_beforecmp = 10
                y_aftercmp = 30

            if 'cout' in self.channel_name:
                # cout7x channel --> y_beforecmp += 30
                y_beforecmp = y_beforecmp + 30
                y_aftercmp = y_aftercmp + 30

            # set all coordinates to the 'end point' (x = timer peak, y = level before cmp)
            for coordinate in self.polyline.coordinates:
                coordinate.x = self.cmp_a.timer.timer_graph.n_line.x1
                coordinate.y = y_beforecmp

            # create always before cmp signal over the timer length, for coord0/1/2
            self.polyline.coordinates[0].x = self.cmp_a.timer.timer_graph.up_line.x1
            self.polyline.coordinates[1].x = self.cmp_a.timer.timer_graph.up_line.x1
            self.polyline.coordinates[2].x = self.cmp_a.timer.timer_graph.up_line.x1
            self.polyline.offset_x = 80

            # x values depend on dtinsel, cmp values, timer period value
            # create variables with short names --> easier to access
            a_reg = self.cmp_a.regval
            b_reg = self.cmp_b.regval
            pv_reg = self.cmp_a.timer.regval

            if self.dtinsel == 0:
                # A state selected
                self.polyline.offset_x = self.cmp_a.timer.timer_graph.trigsel.group_coordinates_sum.x
                if self.cmp_a.timer.mode == 0:
                    # edge aligned
                    if a_reg < pv_reg:
                        # _|-| signal
                        ba_line(self.cmp_a.graph_up.circle.x, self.cmp_a.timer.timer_graph.n_line.x1, self.dten)
                    else:
                        # ____ signal (always before cmp), nothing to do here
                        pass
                else:
                    # center aligned
                    if a_reg < pv_reg:
                        # _|-|_ signal
                        bab_line(self.cmp_a.graph_up.circle.x, self.cmp_a.graph_down.circle.x,
                                 self.cmp_a.timer.timer_graph.n_line.x1, self.dten)
                    else:
                        # ____ signal (always before cmp), nothing to do here
                        pass
            if self.dtinsel == 1:
                # B state selected
                self.polyline.offset_x = self.cmp_a.timer.timer_graph.trigsel.group_coordinates_sum.x
                if self.cmp_a.timer.mode == 0:
                    # edge aligned
                    if (a_reg < pv_reg) and (b_reg < pv_reg) and (a_reg < b_reg):
                        # _|-|_ signal
                        bab_line(self.cmp_a.graph_up.circle.x, self.cmp_b.graph_up.circle.x,
                                 self.cmp_a.timer.timer_graph.n_line.x1, self.dten)
                    elif ((a_reg < pv_reg) and (b_reg > pv_reg) or (a_reg < pv_reg)) and (
                            (b_reg < pv_reg) and (a_reg > b_reg)):
                        # _|-| signal
                        ba_line(self.cmp_a.graph_up.circle.x, self.cmp_a.timer.timer_graph.n_line.x1, self.dten)
                    else:
                        # ____ signal (always before cmp), nothing to do here
                        pass
                else:
                    # center aligned
                    if (a_reg < pv_reg) and (b_reg < pv_reg):
                        # _|-|_ signal
                        bab_line(self.cmp_a.graph_up.circle.x, self.cmp_b.graph_down.circle.x,
                                 self.cmp_a.timer.timer_graph.n_line.x1, self.dten)
                    elif (a_reg < pv_reg) and (b_reg > pv_reg):
                        # _|-| signal
                        ba_line(self.cmp_a.graph_up.circle.x, self.cmp_a.timer.timer_graph.n_line.x1, self.dten)
                    else:
                        # ____ signal (always before cmp), nothing to do here
                        pass
            if self.dtinsel == 2:
                # timer (T14/15/16) Run bit selected
                self.polyline.offset_x = self.timer.timer_graph.trigsel.group_coordinates_sum.x
                # |-| signal
                bab_line(self.polyline.coordinates[0].x, self.timer.timer_graph.n_line.x1,
                         self.timer.timer_graph.n_line.x1, self.dten)
            if self.dtinsel == 3:
                # timer (T14/15/16) state bit selected
                self.polyline.offset_x = self.timer.timer_graph.trigsel.group_coordinates_sum.x
                # _|-| signal
                ba_line(self.timercmp.graph_up.circle.x, self.timer.timer_graph.n_line.x1, self.dten)
            
            # check for T13 as well
            if self.t13moden == 1:
                self.polyline.doublemod_visible = 'visible'

        # t13 modulation
        if self.t12moden == 0 and self.t13moden == 1:
            # cc7x: high = 10, low = 30; cout7x: high = 40, low = 60
            if (self.passive_level == 0 and self.passive_state == 0) or (
                    self.passive_level == 1 and self.passive_state == 1):
                y_beforecmp = 30
                y_aftercmp = 10
            else:
                y_beforecmp = 10
                y_aftercmp = 30

            if 'cout' in self.channel_name:
                # cout7x channel --> y_beforecmp += 30
                y_beforecmp = y_beforecmp + 30
                y_aftercmp = y_aftercmp + 30

            # set all coordinates to the 'end point' (x = timer peak, y = level before cmp)
            for coordinate in self.polyline.coordinates:
                coordinate.x = self.c73.timer.timer_graph.n_line.x1
                coordinate.y = y_beforecmp

            # create always before cmp signal over the timer length, for coord0/1/2
            self.polyline.coordinates[0].x = self.c73.timer.timer_graph.up_line.x1
            self.polyline.coordinates[1].x = self.c73.timer.timer_graph.up_line.x1
            self.polyline.coordinates[2].x = self.c73.timer.timer_graph.up_line.x1
            self.polyline.offset_x = 80

            # x values depend on dtinsel, cmp values, timer period value
            # create variables with short names --> easier to access
            a_reg = self.c73.regval
            pv_reg = self.c73.timer.regval

            self.polyline.offset_x = self.cmp_a.timer.timer_graph.trigsel.group_coordinates_sum.x
            # edge aligned
            if a_reg < pv_reg:
                # _|-| signal
                ba_line(self.c73.graph_up.circle.x, self.c73.timer.timer_graph.n_line.x1, 0)
            else:
                # ____ signal (always before cmp), nothing to do here
                pass

        # save
        ref_xml = 'CCU7_DTGRAPH_' + self.channel_name.upper() + '_PL_COLOR.text'
        exec("%s = %s" % (ref_xml, "self.polyline.color"))
        ref_xml = 'CCU7_DTGRAPH_' + self.channel_name.upper() + '_PL_CORNER'
        exec("%s = %s" % (ref_xml + "0_x.value", self.polyline.coordinates[0].x))
        exec("%s = %s" % (ref_xml + "0_y.value", self.polyline.coordinates[0].y))
        exec("%s = %s" % (ref_xml + "1_x.value", self.polyline.coordinates[1].x))
        exec("%s = %s" % (ref_xml + "1_y.value", self.polyline.coordinates[1].y))
        exec("%s = %s" % (ref_xml + "2_x.value", self.polyline.coordinates[2].x))
        exec("%s = %s" % (ref_xml + "2_y.value", self.polyline.coordinates[2].y))
        exec("%s = %s" % (ref_xml + "3_x.value", self.polyline.coordinates[3].x))
        exec("%s = %s" % (ref_xml + "3_y.value", self.polyline.coordinates[3].y))
        exec("%s = %s" % (ref_xml + "4_x.value", self.polyline.coordinates[4].x))
        exec("%s = %s" % (ref_xml + "4_y.value", self.polyline.coordinates[4].y))
        exec("%s = %s" % (ref_xml + "5_x.value", self.polyline.coordinates[5].x))
        exec("%s = %s" % (ref_xml + "5_y.value", self.polyline.coordinates[5].y))
        exec("%s = %s" % (ref_xml + "6_x.value", self.polyline.coordinates[6].x))
        exec("%s = %s" % (ref_xml + "6_y.value", self.polyline.coordinates[6].y))
        exec("%s = %s" % (ref_xml + "7_x.value", self.polyline.coordinates[7].x))
        exec("%s = %s" % (ref_xml + "7_y.value", self.polyline.coordinates[7].y))

        ref_xml = 'CCU7_DTGRAPH_' + self.channel_name.upper() + '_DOUBLEMOD_VISIBLE.text'
        exec("%s = %s" % (ref_xml, "self.polyline.doublemod_visible"))
        ref_xml = 'CCU7_DTGRAPH_' + self.channel_name.upper() + '_DOUBLEMOD_PL1_CORNER'
        exec("%s = %s" % (ref_xml + "0_x.value", self.polyline.doublemod_coordinates1[0].x))
        exec("%s = %s" % (ref_xml + "0_y.value", self.polyline.doublemod_coordinates1[0].y))
        exec("%s = %s" % (ref_xml + "1_x.value", self.polyline.doublemod_coordinates1[1].x))
        exec("%s = %s" % (ref_xml + "1_y.value", self.polyline.doublemod_coordinates1[1].y))
        exec("%s = %s" % (ref_xml + "2_x.value", self.polyline.doublemod_coordinates1[2].x))
        exec("%s = %s" % (ref_xml + "2_y.value", self.polyline.doublemod_coordinates1[2].y))
        exec("%s = %s" % (ref_xml + "3_x.value", self.polyline.doublemod_coordinates1[3].x))
        exec("%s = %s" % (ref_xml + "3_y.value", self.polyline.doublemod_coordinates1[3].y))
        ref_xml = 'CCU7_DTGRAPH_' + self.channel_name.upper() + '_DOUBLEMOD_PL2_CORNER'
        exec("%s = %s" % (ref_xml + "0_x.value", self.polyline.doublemod_coordinates2[0].x))
        exec("%s = %s" % (ref_xml + "0_y.value", self.polyline.doublemod_coordinates2[0].y))
        exec("%s = %s" % (ref_xml + "1_x.value", self.polyline.doublemod_coordinates2[1].x))
        exec("%s = %s" % (ref_xml + "1_y.value", self.polyline.doublemod_coordinates2[1].y))
        exec("%s = %s" % (ref_xml + "2_x.value", self.polyline.doublemod_coordinates2[2].x))
        exec("%s = %s" % (ref_xml + "2_y.value", self.polyline.doublemod_coordinates2[2].y))
        exec("%s = %s" % (ref_xml + "3_x.value", self.polyline.doublemod_coordinates2[3].x))
        exec("%s = %s" % (ref_xml + "3_y.value", self.polyline.doublemod_coordinates2[3].y))

        ref_xml = 'CCU7_DTGRAPH_' + self.channel_name.upper() + '_OFFSET_x'
        exec("%s = %s" % (ref_xml + ".value", self.polyline.offset_x))


class CCU7Class:
    def __init__(self):
        temp_0 = 0
        temp_1 = 1
        temp_2 = 2
        temp_3 = 3

        self.t12 = TimerClass("t12", CCU7_T12_PERVAL.value, CCU7_T12_PERVAL_UNIT.currentData,
                              CCU7_TCTR0_CTM.currentData,
                              CCU7_TCTR2_T12SSC.currentData, 0, 0, CCU7_T12_CLK.text)
        self.cc70a = CmpClass("cc70a", CCU7_CC70A_CMPVAL.value, CCU7_CC70A_CMPVAL_UNIT.currentData, 'A', self.t12)
        self.c70b  = CmpClass("c70b", CCU7_C70B_CMPVAL.value, CCU7_C70B_CMPVAL_UNIT.currentData, 'B', self.t12)
        self.cc71a = CmpClass("cc71a", CCU7_CC71A_CMPVAL.value, CCU7_CC71A_CMPVAL_UNIT.currentData, 'A', self.t12)
        self.c71b  = CmpClass("c71b", CCU7_C71B_CMPVAL.value, CCU7_C71B_CMPVAL_UNIT.currentData, 'B', self.t12)
        self.cc72a = CmpClass("cc72a", CCU7_CC72A_CMPVAL.value, CCU7_CC72A_CMPVAL_UNIT.currentData, 'A', self.t12)
        self.c72b  = CmpClass("c72b", CCU7_C72B_CMPVAL.value, CCU7_C72B_CMPVAL_UNIT.currentData, 'B', self.t12)

        self.t13 = TimerClass('t13', CCU7_T13_PERVAL.value, CCU7_T13_PERVAL_UNIT.currentData, 0,
                              CCU7_TCTR2_T13SSC.currentData,
                              CCU7_TCTR2_T13TEC.currentData, CCU7_TCTR2_T13TED.currentData, CCU7_T13_CLK.text)
        self.c73 = CmpClass("c73", CCU7_C73_CMPVAL.value, CCU7_C73_CMPVAL_UNIT.currentData, 'A', self.t13)

        self.t14 = TimerClass('t14', CCU7_T14_PERVAL.value, CCU7_T14_PERVAL_UNIT.currentData, 0,
                              CCU7_TCTR24_T1xSSC.currentData,
                              CCU7_TCTR24_T1xTEC.currentData, CCU7_TCTR24_T1xTED.currentData, CCU7_T14_CLK.text)
        self.c74 = CmpClass("c74", CCU7_C74_CMPVAL.value, CCU7_C74_CMPVAL_UNIT.currentData, 'A', self.t14)

        self.t15 = TimerClass('t15', CCU7_T15_PERVAL.value, CCU7_T15_PERVAL_UNIT.currentData, 0,
                              CCU7_TCTR25_T1xSSC.currentData,
                              CCU7_TCTR25_T1xTEC.currentData, CCU7_TCTR25_T1xTED.currentData, CCU7_T15_CLK.text)
        self.c75 = CmpClass("c75", CCU7_C75_CMPVAL.value, CCU7_C75_CMPVAL_UNIT.currentData, 'A', self.t15)

        self.t16 = TimerClass('t16', CCU7_T16_PERVAL.value, CCU7_T16_PERVAL_UNIT.currentData, 0,
                              CCU7_TCTR26_T1xSSC.currentData,
                              CCU7_TCTR26_T1xTEC.currentData, CCU7_TCTR26_T1xTED.currentData, CCU7_T16_CLK.text)
        self.c76 = CmpClass("c76", CCU7_C76_CMPVAL.value, CCU7_C76_CMPVAL_UNIT.currentData, 'A', self.t16)

        # create reference to all timer/compare instances
        trigsel_ref = {'t13': {0: {'label': 'SR[0]', 'value': temp_0},
                               1: {'label': 'CC70A CM', 'value': self.cc70a.graph_up.circle.x},
                               2: {'label': 'CC71A CM', 'value': self.cc71a.graph_up.circle.x},
                               3: {'label': 'CC72A CM', 'value': self.cc72a.graph_up.circle.x},
                               4: {'label': 'Any T12 Cmp. Event', 'value': temp_1},
                               5: {'label': 'T12 PM', 'value': self.t12.timer_graph.up_line.x2},
                               6: {'label': 'T12_ZM and CDIR = 0', 'value': temp_2},
                               7: {'label': 'Any Hall State Change', 'value': temp_3}, },
                       't14': {0: {'label': 'SR[1]', 'value': temp_0},
                               1: {'label': 'CC70A CM', 'value': self.cc70a.graph_up.circle.x},
                               2: {'label': 'C70B CM', 'value': self.c70b.graph_up.circle.x},
                               3: {'label': 'C75 CM', 'value': temp_1},
                               4: {'label': 'C76 CM', 'value': temp_2},
                               5: {'label': 'T12 PM', 'value': self.t12.timer_graph.up_line.x2},
                               6: {'label': 'T12_ZM and CDIR = 0', 'value': temp_3},
                               7: {'label': 'T13 PM',
                                   'value': self.t13.timer_graph.up_line.x2 + self.t13.timer_graph.trigsel.group_coordinates_add.x}, },
                       't15': {0: {'label': 'SR[2]', 'value': temp_0},
                               1: {'label': 'CC71A CM', 'value': self.cc71a.graph_up.circle.x},
                               2: {'label': 'C71B CM', 'value': self.c71b.graph_up.circle.x},
                               3: {'label': 'C74 CM', 'value': temp_1},
                               4: {'label': 'C76 CM', 'value': temp_2},
                               5: {'label': 'T12 PM', 'value': self.t12.timer_graph.up_line.x2},
                               6: {'label': 'T12_ZM and CDIR = 0', 'value': temp_3},
                               7: {'label': 'T14 PM',
                                   'value': self.t14.timer_graph.up_line.x2 + self.t14.timer_graph.trigsel.group_coordinates_add.x}, },
                       't16': {0: {'label': 'SR[3]', 'value': temp_0},
                               1: {'label': 'CC72A CM', 'value': self.cc72a.graph_up.circle.x},
                               2: {'label': 'C72B CM', 'value': self.c72b.graph_up.circle.x},
                               3: {'label': 'C74 CM', 'value': temp_1},
                               4: {'label': 'C75 CM', 'value': temp_2},
                               5: {'label': 'T12 PM', 'value': self.t12.timer_graph.up_line.x2},
                               6: {'label': 'T12_ZM and CDIR = 0', 'value': temp_3},
                               7: {'label': 'T15 PM',
                                   'value': self.t15.timer_graph.up_line.x2 + self.t15.timer_graph.trigsel.group_coordinates_add.x}, }}

        # calculate the offset caused by trigsel
        self.t12.calc_trigsel(trigsel_ref)
        self.t13.calc_trigsel(trigsel_ref)
        self.t14.calc_trigsel(trigsel_ref)
        self.t15.calc_trigsel(trigsel_ref)
        self.t16.calc_trigsel(trigsel_ref)

        # deadtime
        self.dt_ch0_cc70 =   DeadtimeClass('cc70', CCU7_T12DTINSEL_DTINSEL0.currentData,
                                           CCU7_CMPSTAT_CC70PS.currentData, CCU7_PSLR_PSL_CC70.currentData,
                                           self.cc70a, self.c70b, self.c73, self.t14, self.c74, CCU7_T12DTC_DTE0.checked,
                                           CCU7_MODCTR_T12MODEN_CC70.checked, CCU7_MODCTR_T13MODEN_CC70.checked, CCU7_T12MSEL_MSEL70.currentData)
        self.dt_ch0_cout70 = DeadtimeClass('cout70', CCU7_T12DTINSEL_DTINSEL0.currentData,
                                           CCU7_CMPSTAT_COUT70PS.currentData, CCU7_PSLR_PSL_COUT70.currentData,
                                           self.cc70a, self.c70b, self.c73, self.t14, self.c74, CCU7_T12DTC_DTE0.checked,
                                           CCU7_MODCTR_T12MODEN_COUT70.checked, CCU7_MODCTR_T13MODEN_COUT70.checked, CCU7_T12MSEL_MSEL70.currentData)
        self.dt_ch0_cc71 =   DeadtimeClass('cc71', CCU7_T12DTINSEL_DTINSEL1.currentData,
                                           CCU7_CMPSTAT_CC71PS.currentData, CCU7_PSLR_PSL_CC71.currentData,
                                           self.cc71a, self.c71b, self.c73, self.t15, self.c75, CCU7_T12DTC_DTE1.checked,
                                           CCU7_MODCTR_T12MODEN_CC71.checked, CCU7_MODCTR_T13MODEN_CC71.checked, CCU7_T12MSEL_MSEL71.currentData)
        self.dt_ch0_cout71 = DeadtimeClass('cout71', CCU7_T12DTINSEL_DTINSEL1.currentData,
                                           CCU7_CMPSTAT_COUT71PS.currentData, CCU7_PSLR_PSL_COUT71.currentData,
                                           self.cc71a, self.c71b, self.c73, self.t15, self.c75, CCU7_T12DTC_DTE1.checked,
                                           CCU7_MODCTR_T12MODEN_COUT71.checked, CCU7_MODCTR_T13MODEN_COUT71.checked, CCU7_T12MSEL_MSEL71.currentData)
        self.dt_ch0_cc72 =   DeadtimeClass('cc72', CCU7_T12DTINSEL_DTINSEL2.currentData,
                                           CCU7_CMPSTAT_CC72PS.currentData, CCU7_PSLR_PSL_CC72.currentData,
                                           self.cc72a, self.c72b, self.c73, self.t16, self.c76, CCU7_T12DTC_DTE2.checked,
                                           CCU7_MODCTR_T12MODEN_CC72.checked, CCU7_MODCTR_T13MODEN_CC72.checked, CCU7_T12MSEL_MSEL72.currentData)
        self.dt_ch0_cout72 = DeadtimeClass('cout72', CCU7_T12DTINSEL_DTINSEL2.currentData,
                                           CCU7_CMPSTAT_COUT72PS.currentData, CCU7_PSLR_PSL_COUT72.currentData,
                                           self.cc72a, self.c72b, self.c73, self.t16, self.c76, CCU7_T12DTC_DTE2.checked,
                                           CCU7_MODCTR_T12MODEN_COUT72.checked, CCU7_MODCTR_T13MODEN_COUT72.checked, CCU7_T12MSEL_MSEL72.currentData)

    def save(self):
        self.t12.save()
        self.t13.save()
        self.t14.save()
        self.t15.save()
        self.t16.save()
        self.cc70a.save()
        self.c70b.save()
        self.cc71a.save()
        self.c71b.save()
        self.cc72a.save()
        self.c72b.save()
        self.c73.save()
        self.c74.save()
        self.c75.save()
        self.c76.save()
        application.runScript("setDef(timer_graph_t12.update=1)")
        application.runScript("setDef(timer_graph_t13.update=1)")
        application.runScript("setDef(timer_graph_t14.update=1)")
        application.runScript("setDef(timer_graph_t15.update=1)")
        application.runScript("setDef(timer_graph_t16.update=1)")
        application.runScript("setDef(DT_graph_Ch0.update=1)")
        application.runScript("setDef(DT_graph_Ch1.update=1)")
        application.runScript("setDef(DT_graph_Ch2.update=1)")


def calc_ccu7():
    # print('Run calc_ccu7.py...')
    ccu7 = CCU7Class()
    ccu7.save()
    # print('Finished!')

CCU7_EN.connect('stateChanged(int)', calc_ccu7)
# connect with GUI elements
# checkbox --> stateChanged(int)       .connect('stateChanged', calc_ccu7)
# spinbox --> valueChanged(int)        .connect('valueChanged(int)', calc_ccu7)
# combo --> currentIndexChanged(int)   .connect('currentIndexChanged(int)', calc_ccu7)
# CCU7 enable
CCU7_EN.connect('stateChanged(int)', calc_ccu7)
# t12
CCU7_T12_PERVAL.connect('valueChanged(int)', calc_ccu7)
CCU7_T12_PERVAL_UNIT.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_TCTR0_CTM.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_TCTR2_T12SSC.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_T12_CLK_EDIT.connect('textChanged(QString)', calc_ccu7)
# cc70a
CCU7_CC70A_CMPVAL.connect('valueChanged(int)', calc_ccu7)
CCU7_CC70A_CMPVAL_UNIT.connect('currentIndexChanged(int)', calc_ccu7)
# c70b
CCU7_C70B_CMPVAL.connect('valueChanged(int)', calc_ccu7)
CCU7_C70B_CMPVAL_UNIT.connect('currentIndexChanged(int)', calc_ccu7)
# cc71a
CCU7_CC71A_CMPVAL.connect('valueChanged(int)', calc_ccu7)
CCU7_CC71A_CMPVAL_UNIT.connect('currentIndexChanged(int)', calc_ccu7)
# c71b
CCU7_C71B_CMPVAL.connect('valueChanged(int)', calc_ccu7)
CCU7_C71B_CMPVAL_UNIT.connect('currentIndexChanged(int)', calc_ccu7)
# cc72a
CCU7_CC72A_CMPVAL.connect('valueChanged(int)', calc_ccu7)
CCU7_CC72A_CMPVAL_UNIT.connect('currentIndexChanged(int)', calc_ccu7)
# c72b
CCU7_C72B_CMPVAL.connect('valueChanged(int)', calc_ccu7)
CCU7_C72B_CMPVAL_UNIT.connect('currentIndexChanged(int)', calc_ccu7)
# t13
CCU7_T13_PERVAL.connect('valueChanged(int)', calc_ccu7)
CCU7_T13_PERVAL_UNIT.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_TCTR2_T13SSC.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_TCTR2_T13TEC.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_TCTR2_T13TED.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_T13_CLK_EDIT.connect('textChanged(QString)', calc_ccu7)
# c73
CCU7_C73_CMPVAL.connect('valueChanged(int)', calc_ccu7)
CCU7_C73_CMPVAL_UNIT.connect('currentIndexChanged(int)', calc_ccu7)
# t14
CCU7_T14_PERVAL.connect('valueChanged(int)', calc_ccu7)
CCU7_T14_PERVAL_UNIT.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_TCTR24_T1xSSC.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_TCTR24_T1xTEC.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_TCTR24_T1xTED.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_T14_CLK_EDIT.connect('textChanged(QString)', calc_ccu7)
# c74
CCU7_C74_CMPVAL.connect('valueChanged(int)', calc_ccu7)
CCU7_C74_CMPVAL_UNIT.connect('currentIndexChanged(int)', calc_ccu7)
# t15
CCU7_T15_PERVAL.connect('valueChanged(int)', calc_ccu7)
CCU7_T15_PERVAL_UNIT.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_TCTR25_T1xSSC.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_TCTR25_T1xTEC.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_TCTR25_T1xTED.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_T15_CLK_EDIT.connect('textChanged(QString)', calc_ccu7)
# c75
CCU7_C75_CMPVAL.connect('valueChanged(int)', calc_ccu7)
CCU7_C75_CMPVAL_UNIT.connect('currentIndexChanged(int)', calc_ccu7)
# t16
CCU7_T16_PERVAL.connect('valueChanged(int)', calc_ccu7)
CCU7_T16_PERVAL_UNIT.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_TCTR26_T1xSSC.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_TCTR26_T1xTEC.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_TCTR26_T1xTED.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_T16_CLK_EDIT.connect('textChanged(QString)', calc_ccu7)
# c76
CCU7_C76_CMPVAL.connect('valueChanged(int)', calc_ccu7)
CCU7_C76_CMPVAL_UNIT.connect('currentIndexChanged(int)', calc_ccu7)

# dt_ch0_cc70
CCU7_T12DTINSEL_DTINSEL0.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_CMPSTAT_CC70PS.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_PSLR_PSL_CC70.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_T12DTC_DTE0.connect('stateChanged(int)', calc_ccu7)
CCU7_MODCTR_T12MODEN_CC70.connect('stateChanged(int)', calc_ccu7)
CCU7_MODCTR_T13MODEN_CC70.connect('stateChanged(int)', calc_ccu7)
CCU7_T12MSEL_MSEL70.connect('currentIndexChanged(int)', calc_ccu7)
# dt_ch0_cout70
CCU7_T12DTINSEL_DTINSEL0.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_CMPSTAT_COUT70PS.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_PSLR_PSL_COUT70.connect('currentIndexChanged(int)', calc_ccu7)
# CCU7_T12DTC_DTE0.connect('stateChanged(int)', calc_ccu7) already in dt_ch0_cc70
CCU7_MODCTR_T12MODEN_COUT70.connect('stateChanged(int)', calc_ccu7)
CCU7_MODCTR_T13MODEN_COUT70.connect('stateChanged(int)', calc_ccu7)
CCU7_T12MSEL_MSEL70.connect('currentIndexChanged(int)', calc_ccu7)
# dt_ch0_cc71
CCU7_T12DTINSEL_DTINSEL1.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_CMPSTAT_CC71PS.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_PSLR_PSL_CC71.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_T12DTC_DTE1.connect('stateChanged(int)', calc_ccu7)
CCU7_MODCTR_T12MODEN_CC71.connect('stateChanged(int)', calc_ccu7)
CCU7_MODCTR_T13MODEN_CC71.connect('stateChanged(int)', calc_ccu7)
CCU7_T12MSEL_MSEL71.connect('currentIndexChanged(int)', calc_ccu7)
# dt_ch0_cout71
CCU7_T12DTINSEL_DTINSEL1.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_CMPSTAT_COUT71PS.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_PSLR_PSL_COUT71.connect('currentIndexChanged(int)', calc_ccu7)
# CCU7_T12DTC_DTE1.connect('stateChanged(int)', calc_ccu7) already in dt_ch0_cc71
CCU7_MODCTR_T12MODEN_COUT71.connect('stateChanged(int)', calc_ccu7)
CCU7_MODCTR_T13MODEN_COUT71.connect('stateChanged(int)', calc_ccu7)
CCU7_T12MSEL_MSEL71.connect('currentIndexChanged(int)', calc_ccu7)
# dt_ch0_cc72
CCU7_T12DTINSEL_DTINSEL2.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_CMPSTAT_CC72PS.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_PSLR_PSL_CC72.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_T12DTC_DTE2.connect('stateChanged(int)', calc_ccu7),
CCU7_MODCTR_T12MODEN_CC72.connect('stateChanged(int)', calc_ccu7)
CCU7_MODCTR_T13MODEN_CC72.connect('stateChanged(int)', calc_ccu7)
CCU7_T12MSEL_MSEL72.connect('currentIndexChanged(int)', calc_ccu7)
# dt_ch0_cout72
CCU7_T12DTINSEL_DTINSEL2.connect('currentIndexChanged(int)', calc_ccu7),
CCU7_CMPSTAT_COUT72PS.connect('currentIndexChanged(int)', calc_ccu7)
CCU7_PSLR_PSL_COUT72.connect('currentIndexChanged(int)', calc_ccu7)
# CCU7_T12DTC_DTE2.connect('stateChanged(int)', calc_ccu7) already in dt_ch0_cc72
CCU7_MODCTR_T12MODEN_COUT72.connect('stateChanged(int)', calc_ccu7)
CCU7_MODCTR_T13MODEN_COUT72.connect('stateChanged(int)', calc_ccu7)
CCU7_T12MSEL_MSEL72.connect('currentIndexChanged(int)', calc_ccu7)

# call calc_ccu7() to initialize everything
calc_ccu7()

# print("CONNECTED!!")
