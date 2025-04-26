// GEN BLOCK BEGIN Include
#define TSMP_IMPL
#include "TSMaster.h"
#include "MPLibrary.h"
#include "Database.h"
#include "TSMasterBaseInclude.h"
#include "Configuration.h"
// GEN BLOCK END Include

#include <time.h>

// CODE BLOCK BEGIN Step_Function  NQ__
// Main step function being executed every 5 ms
void step(void) { try { // interval = 5 ms
unsigned long long nm3Value = 0;
unsigned long long nm3Pn1Value = 0;
time_t rawtime = time(NULL);
struct tm* timeinfo = localtime(&rawtime);
TCAN msg;
int full_year = timeinfo->tm_year + 1900;
int year_two_digits = full_year % 100;
com.can_rbs_get_signal_raw_by_address("0/F93M8_CAN_DEC/CBM/Networkmanagement3/NM3", &nm3Value);
com.can_rbs_get_signal_raw_by_address("0/F93M8_CAN_DEC/DMU/Networkmanagement3/NM3_PN1", &nm3Pn1Value);

if (nm3Value != 0 || nm3Pn1Value != 0)
{ 
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/TCB/RealDateAndTime/Real_Year", (u8)year_two_digits);
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/TCB/RealDateAndTime/Real_Month", (u8)(timeinfo->tm_mon + 1));
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/TCB/RealDateAndTime/Real_Day", (u8)timeinfo->tm_mday);
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/TCB/RealDateAndTime/Real_Hour", (u8)timeinfo->tm_hour);
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/TCB/RealDateAndTime/Real_Minute", (u8)timeinfo->tm_min);
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/TCB/RealDateAndTime/Real_Second", (u8)timeinfo->tm_sec);
}
else
{
// Node: TCB
com.can_rbs_activate_node_by_name(CH1, false, "F93M8_CAN_DEC", "TCB", false);
// Message: RealDateAndTime
com.can_rbs_set_message_cycle_by_name(CH1, 900, "F93M8_CAN_DEC", "TCB", "RealDateAndTime");
com.can_rbs_activate_message_by_name(CH1, false, "F93M8_CAN_DEC", "TCB", "RealDateAndTime");
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/TCB/RealDateAndTime/Real_Year", 0);
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/TCB/RealDateAndTime/Real_Month", 0);
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/TCB/RealDateAndTime/Real_Day", 0);
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/TCB/RealDateAndTime/Real_Hour", 0);
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/TCB/RealDateAndTime/Real_Minute", 0);
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/TCB/RealDateAndTime/Real_Second", 0);
// Node: Tester
com.can_rbs_activate_node_by_name(CH1, false, "F93M8_CAN_DEC", "Tester", false);
// Message: DiagCAN_Request_DiagMaster
com.can_rbs_activate_message_by_name(CH1, false, "F93M8_CAN_DEC", "Tester", "DiagCAN_Request_DiagMaster");
// Message: DiagCAN_Request_702
com.can_rbs_activate_message_by_name(CH1, false, "F93M8_CAN_DEC", "Tester", "DiagCAN_Request_702");
// Message: DiagCAN_Request_700
com.can_rbs_activate_message_by_name(CH1, false, "F93M8_CAN_DEC", "Tester", "DiagCAN_Request_700");
// Node: EMC
com.can_rbs_activate_node_by_name(CH1, false, "F93M8_CAN_DEC", "EMC", false);
// Message: SafeDriveTrainStatus
com.can_rbs_set_message_cycle_by_name(CH1, 100, "F93M8_CAN_DEC", "EMC", "SafeDriveTrainStatus");
com.can_rbs_activate_message_by_name(CH1, false, "F93M8_CAN_DEC", "EMC", "SafeDriveTrainStatus");
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/EMC/SafeDriveTrainStatus/Sdts_Crc", 0);
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/EMC/SafeDriveTrainStatus/Sdts_SeqCnt", 0);
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/EMC/SafeDriveTrainStatus/Sdts_VehSpeed", 0);
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/EMC/SafeDriveTrainStatus/Sdts_MotorRpm", 0);
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/EMC/SafeDriveTrainStatus/Sdts_DriveTrainStatus", 0);
// Node: CBS
com.can_rbs_activate_node_by_name(CH1, false, "F93M8_CAN_DEC", "CBS", false);
// Message: ClimateWiperControl
com.can_rbs_set_message_cycle_by_name(CH1, 500, "F93M8_CAN_DEC", "CBS", "ClimateWiperControl");
com.can_rbs_activate_message_by_name(CH1, false, "F93M8_CAN_DEC", "CBS", "ClimateWiperControl");
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/CBS/ClimateWiperControl/AutoClimate", 0);
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/CBS/ClimateWiperControl/ClimateTemperature", 0);
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/CBS/ClimateWiperControl/DisplayMode", 0);
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/CBS/ClimateWiperControl/FanValue", 0);
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/CBS/ClimateWiperControl/Recirculation", 0);
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/CBS/ClimateWiperControl/RotaryLightSwitch", 0);
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/CBS/ClimateWiperControl/WiperStock", 0);
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/CBS/ClimateWiperControl/OutTemp", 0);
// Node: FRBE
com.can_rbs_activate_node_by_name(CH1, false, "F93M8_CAN_DEC", "FRBE", false);
// Message: LightStatus
com.can_rbs_set_message_cycle_by_name(CH1, 50, "F93M8_CAN_DEC", "FRBE", "LightStatus");
com.can_rbs_activate_message_by_name(CH1, false, "F93M8_CAN_DEC", "FRBE", "LightStatus");
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/FRBE/LightStatus/StatusFogLights", 0);
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/FRBE/LightStatus/StatusHighBeam", 0);
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/FRBE/LightStatus/StatusTurnSignals", 0);
}

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END Step_Function 

