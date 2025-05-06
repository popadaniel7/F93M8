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
time_t rawtime = time(NULL);
struct tm* timeinfo = localtime(&rawtime);
int full_year = timeinfo->tm_year + 1900;
int year_two_digits = full_year % 100;    

com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/TCB/RealDateAndTime/Real_Year", (u8)year_two_digits);
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/TCB/RealDateAndTime/Real_Month", (u8)(timeinfo->tm_mon + 1));
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/TCB/RealDateAndTime/Real_Day", (u8)timeinfo->tm_mday);
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/TCB/RealDateAndTime/Real_Hour", (u8)timeinfo->tm_hour);
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/TCB/RealDateAndTime/Real_Minute", (u8)timeinfo->tm_min);
com.can_rbs_set_signal_value_by_address("0/F93M8_CAN_DEC/TCB/RealDateAndTime/Real_Second", (u8)timeinfo->tm_sec);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END Step_Function 

