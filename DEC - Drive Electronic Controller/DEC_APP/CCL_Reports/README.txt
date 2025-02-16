ChipCoach Library (CCL) configuration file.

During the execution of CCL, default parameters are not sufficient for all tests to pass and they need to be configured by the user.
This can be done, by changing the parameters manually on the Python script or using a configuration file that will be described in this document.

The configuration file must be placed in <project>/CCL_Reports/ccl_parameters.json

The configuration will be stored in a JSON file with the following format: Each parameter and the assigned values will represent an object/value in the JSON file.
Let's say, we want to change CclTc3xxCpCpuBasic.param_CpuMemProtNotEn parameter, the default value given by CCL is an empty list [], but we want to set it for some CPUs.
Then the JSON file would look like this:

{
	"CclTc3xxCpCpuBasic.param_CpuMemProtNotEn":[1,2,3]  
}

If we want to add more parameters, follow the same pattern:

{
	"CclTc3xxCpCpuBasic.param_CpuMemProtNotEn":[1,2,3],
	"CclTc3xxCpCpuRunning.param_CpuNotRunning":[4,5],
	"CclTc3xxCpPFlashWait.param_AccessCyclesMarginMax": 5,
}

Parameters can be obtained inside CCL report folder inside CCLLog_Raw.txt file. All the checked parameters are shown for example.
A good baseline for parameters generating errors can be obtained from "soH" related file e.g.:
CclTc3xxCpClc.soH_ClcEnabledBySw=['ASCLIN0_CLC', 'EMEM_CLC']  
CclTc3xxCpClc.param_ClcEnabledBySw=[] 
For more information about CCL, open ADS help and search for CCL in the search box 