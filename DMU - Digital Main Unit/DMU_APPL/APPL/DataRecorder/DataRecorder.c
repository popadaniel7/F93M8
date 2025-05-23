#include "DataRecorder.h"
#include "RevCam.h"
__attribute__((section(".ccmram"))) uint32 DataRecorder_RxSig_VehicleSpeed = 0x00;
__attribute__((section(".ccmram"))) uint8 DataRecorder_RxSig_DriveCycleStatus = 0x00;
__attribute__((section(".ccmram"))) uint32 DataRecorder_MainCounter = 0x00;
__attribute__((section(".ccmram"))) float DataRecorder_SpeedInKmS = 0x00;
__attribute__((section(".ccmram"))) uint32 DataRecorder_SpeedCounterActive = 0x00;
__attribute__((section(".ccmram"))) uint32 DataRecorder_KilometerTotal = 0x00;
__attribute__((section(".ccmram"))) uint32 DataRecorder_KilometerPerDcy = 0x00;
__attribute__((section(".ccmram"))) float aux_km1 = 0;
__attribute__((section(".ccmram"))) float aux_km2 = 0;
__attribute__((section(".ccmram"))) float fin_aux_km1 = 0;
__attribute__((section(".ccmram"))) float fin_aux_km2 = 0;
extern __attribute__((section(".ccmram"))) uint32 RevCam_DcmiStatus;
extern __attribute__((section(".ccmram"))) uint32 RevCam_I2cStatus;
extern __attribute__((section(".ccmram"))) uint32 vehSpeedConv;
void DataRecorder_MainFunction(void);
void DataRecorder_MainFunction(void)
{
	/* Retrieve saved calculated kilometers. */
	if(0 == DataRecorder_MainCounter)
	{
		fin_aux_km1 = DataRecorder_KilometerPerDcy;
		fin_aux_km2 = DataRecorder_KilometerTotal;
	}
	else
	{
		/* Do nothing. */
	}
	/* Value END == 0x03 */
	if(DATARECORDER_DCY_END == DataRecorder_RxSig_DriveCycleStatus)
	{
		DataRecorder_KilometerPerDcy = 0;
	}
	else
	{
		/* Do nothing. */
	}
	/* Start counting kilometers. */
	if(DATARECORDER_DCY_START == DataRecorder_RxSig_DriveCycleStatus)
	{
		/* If vehicle is not stationary. */
		if(0x00 != DataRecorder_RxSig_VehicleSpeed)
		{
			/* Count 10 milliseconds each function call to the timer. */
			DataRecorder_SpeedCounterActive += 10;
			/* Convert KM/H into KM/S. */
			DataRecorder_SpeedInKmS = (float)vehSpeedConv / (float)3600;
			/* Add up into auxiliary variables. */
			aux_km1 += (float)DataRecorder_SpeedInKmS;
			aux_km2 += (float)DataRecorder_SpeedInKmS;
			/* Every second update the kilometer status. */
			if(DataRecorder_SpeedCounterActive % 100 == 0 && DataRecorder_SpeedCounterActive != 0)
			{
				/* Displayed value is uint32 and not float. */
				fin_aux_km1 += (float)aux_km1 / (float)100;
				fin_aux_km2 += (float)aux_km2 / (float)100;
				DataRecorder_KilometerPerDcy = (uint32)fin_aux_km1;
				DataRecorder_KilometerTotal  = (uint32)fin_aux_km2;
				aux_km1 = 0;
				aux_km2 = 0;
			}
			else
			{
				/* Do nothing. */
			}
		}
		else
		{
			/* Do nothing. */
		}
	}
	else
	{
		/* Do nothing. */
	}
	DataRecorder_MainCounter++;
}
