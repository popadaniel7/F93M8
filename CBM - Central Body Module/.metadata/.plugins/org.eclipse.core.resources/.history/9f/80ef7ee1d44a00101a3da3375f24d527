/* START OF FILE */
/* INCLUDE START */
#include "Dcm.h"
#include "EcuM.h"
#include "Dem.h"
#include "CanSpi.h"
#include "InputCtrl.h"
#include "TimH.h"
#include "Ain.h"
#include "UartH.h"
#include "tim.h"
#include "Nvm.h"
#include "ActCtrl.h"
#include "string.h"
/* INCLUDE END */
/* VARIABLES START */
/* Diagnostic session state. */
DiagState Dcm_DiagnosticSession __attribute__((section(".ncr")));
/* Time without reset. */
uint32 Dcm_AliveCounter __attribute__((section(".ncr")));
extern uint8 Dem_ControlDtcSettingStatus;
/* Software versions. */
static SWV Dcm_SWVersion =
{
		31, /* SW */
		30, /* FBL */
		30, /* CODING */
		30  /* CALIBRATION */
};
/* FUNCTIONS START */
void Dcm_MainFunction(void);
static void DiagService_DSC_DefaultSession(void);
static void DiagService_DSC_ExtendedSession(void);
static void DiagService_DSC_ProgrammingSession(void);
static void DiagService_DSC_CodingSession(void);
static void DiagService_DSC_CalibrationSession(void);
static void DiagService_ER_HardReset(void);
static void DiagService_ER_SoftReset(void);
static void DiagService_TP_TesterPresent(void);
static void DiagService_CDTCI_ClearDiagnosticInformation(void);
static void DiagService_RDTCI_ReadDTCInformationSupportedDtc(void);
static void DiagService_RDBI_ReadCodingData(void);
static void DiagService_RDBI_ReadCalibrationData(void);
static void DiagService_RDBI_ReadSWVersion(void);
static void DiagService_RDBI_ReadActiveDiagnosticSession(void);
static void DiagService_RDBI_ReadAliveTime(void);
static void DiagService_RDBPI_ReadPeriodicIgnitionCompleteStatus(void);
static void DiagService_RDBPI_ReadPeriodicGearboxSelectorCompleteStatus(void);
static void DiagService_RDBPI_ReadPeriodicDoorLockActuatorStatus(void);
static void DiagService_RDBPI_ReadPeriodicWindshieldWiperActuatorStatus(void);
static void DiagService_RDBPI_ReadPeriodicClimaFanStatus(void);
static void DiagService_RDBPI_ReadPeriodicLS(void);
static void DiagService_RDBPI_ReadPeriodicRS(void);
static void DiagService_CC_CommunicationControl(void);
static void DiagService_CDTCS_ControlDTCSetting(void);
extern void NvM_WriteAll(void);
/* FUNCTIONS STOP */
/* VARIABLES START */
/* Look-up table for RDBPI diagnostic routines. */
Dcm_RDBPI_Table_t Dcm_RDBPI_Table[] =
{
		{DiagService_RDBPI_ReadPeriodicIgnitionCompleteStatus},
		{DiagService_RDBPI_ReadPeriodicGearboxSelectorCompleteStatus},
		{DiagService_RDBPI_ReadPeriodicDoorLockActuatorStatus},
		{DiagService_RDBPI_ReadPeriodicWindshieldWiperActuatorStatus},
		{DiagService_RDBPI_ReadPeriodicClimaFanStatus},
		{DiagService_RDBPI_ReadPeriodicLS},
		{DiagService_RDBPI_ReadPeriodicRS},
};
/* VARIABLES STOP */
/* FUNCTIONS START */
static void DiagService_CDTCS_ControlDTCSetting(void)
{
	if(Dcm_DiagServiceRequest_Frame.frame.data2 == 0x01) Dem_ControlDtcSettingStatus = 1;
	else if(Dcm_DiagServiceRequest_Frame.frame.data2 == 0x02) Dem_ControlDtcSettingStatus = 0;
	else
	{
		/* Do nothing. */
	}
	Dcm_DiagServiceResponse_Frame.frame.dlc = 3;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x02;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0xC5;
	Dcm_DiagServiceResponse_Frame.frame.data2 = Dcm_DiagServiceRequest_Frame.frame.data2;
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	Dcm_DiagServiceResponse_Frame.frame.idType = 0;
	Dcm_DiagServiceResponse_Frame.frame.id = 0;
	Dcm_DiagServiceResponse_Frame.frame.dlc = 0;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data4 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data5 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data6 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data7 = 0;
	Dcm_DiagServiceRequest_Frame.frame.idType = 0;
	Dcm_DiagServiceRequest_Frame.frame.id = 0;
	Dcm_DiagServiceRequest_Frame.frame.dlc = 0;
	Dcm_DiagServiceRequest_Frame.frame.data0 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data1 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data2 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data3 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data4 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data5 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data6 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data7 = 0;
}

static void DiagService_CC_CommunicationControl(void)
{
	if(Dcm_DiagServiceRequest_Frame.frame.data2 == 0x00) CanSpi_Communication_Status = CC_ACTIVE;
	else if(Dcm_DiagServiceRequest_Frame.frame.data2 == 0x01) CanSpi_Communication_Status = FULL_COMMUNICATION;
	else
	{
		/* Do nothing. */
	}
	Dcm_DiagServiceResponse_Frame.frame.dlc = 3;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x02;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x68;
	Dcm_DiagServiceResponse_Frame.frame.data2 = Dcm_DiagServiceRequest_Frame.frame.data2;
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	Dcm_DiagServiceResponse_Frame.frame.idType = 0;
	Dcm_DiagServiceResponse_Frame.frame.id = 0;
	Dcm_DiagServiceResponse_Frame.frame.dlc = 0;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data4 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data5 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data6 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data7 = 0;
	Dcm_DiagServiceRequest_Frame.frame.idType = 0;
	Dcm_DiagServiceRequest_Frame.frame.id = 0;
	Dcm_DiagServiceRequest_Frame.frame.dlc = 0;
	Dcm_DiagServiceRequest_Frame.frame.data0 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data1 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data2 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data3 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data4 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data5 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data6 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data7 = 0;
}
static void DiagService_TP_TesterPresent(void)
{
	Dcm_DiagServiceResponse_Frame.frame.dlc = 3;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x02;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x7E;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0x00;
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	Dcm_DiagServiceResponse_Frame.frame.idType = 0;
	Dcm_DiagServiceResponse_Frame.frame.id = 0;
	Dcm_DiagServiceResponse_Frame.frame.dlc = 0;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data4 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data5 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data6 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data7 = 0;
	Dcm_DiagServiceRequest_Frame.frame.idType = 0;
	Dcm_DiagServiceRequest_Frame.frame.id = 0;
	Dcm_DiagServiceRequest_Frame.frame.dlc = 0;
	Dcm_DiagServiceRequest_Frame.frame.data0 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data1 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data2 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data3 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data4 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data5 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data6 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data7 = 0;
}
static void DiagService_DSC_CodingSession(void)
{
	Dcm_DiagServiceResponse_Frame.frame.dlc = 3;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x02;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x50;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0x04;
	Dcm_DiagnosticSession = CODING;
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	NvM_WriteAll();
	EcuM_PerformReset(0);
}
static void DiagService_DSC_CalibrationSession(void)
{
	Dcm_DiagServiceResponse_Frame.frame.dlc = 3;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x02;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x50;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0x05;
	Dcm_DiagnosticSession = CALIBRATION;
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	NvM_WriteAll();
	EcuM_PerformReset(0);
}
static void DiagService_RDBI_ReadCodingData(void)
{
	Dcm_DiagServiceResponse_Frame.frame.dlc = 8;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x07;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x62;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0x00;
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0x02;
	Dcm_DiagServiceResponse_Frame.frame.data4 = NvMBlock_Coding[0];
	Dcm_DiagServiceResponse_Frame.frame.data5 = NvMBlock_Coding[1];
	Dcm_DiagServiceResponse_Frame.frame.data6 = NvMBlock_Coding[2];
	Dcm_DiagServiceResponse_Frame.frame.data7 = NvMBlock_Coding[3];
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	HAL_Delay(5);
	Dcm_DiagServiceResponse_Frame.frame.dlc = 6;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x05;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x62;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0x00;
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0x02;
	Dcm_DiagServiceResponse_Frame.frame.data4 = NvMBlock_Coding[4];
	Dcm_DiagServiceResponse_Frame.frame.data5 = NvMBlock_Coding[5];
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	Dcm_DiagServiceResponse_Frame.frame.idType = 0;
	Dcm_DiagServiceResponse_Frame.frame.id = 0;
	Dcm_DiagServiceResponse_Frame.frame.dlc = 0;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data4 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data5 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data6 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data7 = 0;
	Dcm_DiagServiceRequest_Frame.frame.idType = 0;
	Dcm_DiagServiceRequest_Frame.frame.id = 0;
	Dcm_DiagServiceRequest_Frame.frame.dlc = 0;
	Dcm_DiagServiceRequest_Frame.frame.data0 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data1 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data2 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data3 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data4 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data5 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data6 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data7 = 0;
}
static void DiagService_RDBI_ReadCalibrationData(void)
{
	Dcm_DiagServiceResponse_Frame.frame.dlc = 8;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x07;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x62;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0x00;
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0x03;
	Dcm_DiagServiceResponse_Frame.frame.data4 = NvMBlock_Calibration[0];
	Dcm_DiagServiceResponse_Frame.frame.data5 = NvMBlock_Calibration[1];
	Dcm_DiagServiceResponse_Frame.frame.data6 = NvMBlock_Calibration[2];
	Dcm_DiagServiceResponse_Frame.frame.data7 = NvMBlock_Calibration[3];
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	HAL_Delay(5);
	Dcm_DiagServiceResponse_Frame.frame.dlc = 8;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x07;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x62;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0x00;
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0x03;
	Dcm_DiagServiceResponse_Frame.frame.data4 = NvMBlock_Calibration[4];
	Dcm_DiagServiceResponse_Frame.frame.data5 = NvMBlock_Calibration[5];
	Dcm_DiagServiceResponse_Frame.frame.data6 = NvMBlock_Calibration[6];
	Dcm_DiagServiceResponse_Frame.frame.data7 = NvMBlock_Calibration[7];
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	HAL_Delay(5);
	Dcm_DiagServiceResponse_Frame.frame.dlc = 6;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x05;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x62;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0x00;
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0x03;
	Dcm_DiagServiceResponse_Frame.frame.data4 = NvMBlock_Calibration[8];
	Dcm_DiagServiceResponse_Frame.frame.data5 = NvMBlock_Calibration[9];
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	Dcm_DiagServiceResponse_Frame.frame.idType = 0;
	Dcm_DiagServiceResponse_Frame.frame.id = 0;
	Dcm_DiagServiceResponse_Frame.frame.dlc = 0;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data4 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data5 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data6 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data7 = 0;
	Dcm_DiagServiceRequest_Frame.frame.idType = 0;
	Dcm_DiagServiceRequest_Frame.frame.id = 0;
	Dcm_DiagServiceRequest_Frame.frame.dlc = 0;
	Dcm_DiagServiceRequest_Frame.frame.data0 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data1 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data2 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data3 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data4 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data5 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data6 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data7 = 0;
}
static void DiagService_RDBI_ReadSWVersion(void)
{
	Dcm_DiagServiceResponse_Frame.frame.dlc = 8;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x07;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x62;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0xF1;
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0x80;
	Dcm_DiagServiceResponse_Frame.frame.data4 = Dcm_SWVersion.FlashBootLoaderVersion;
	Dcm_DiagServiceResponse_Frame.frame.data5 = Dcm_SWVersion.SoftwareVersion;
	Dcm_DiagServiceResponse_Frame.frame.data6 = Dcm_SWVersion.CodingVersion;
	Dcm_DiagServiceResponse_Frame.frame.data7 = Dcm_SWVersion.CalibrationVersion;
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	Dcm_DiagServiceResponse_Frame.frame.idType = 0;
	Dcm_DiagServiceResponse_Frame.frame.id = 0;
	Dcm_DiagServiceResponse_Frame.frame.dlc = 0;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data4 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data5 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data6 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data7 = 0;
	Dcm_DiagServiceRequest_Frame.frame.idType = 0;
	Dcm_DiagServiceRequest_Frame.frame.id = 0;
	Dcm_DiagServiceRequest_Frame.frame.dlc = 0;
	Dcm_DiagServiceRequest_Frame.frame.data0 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data1 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data2 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data3 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data4 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data5 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data6 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data7 = 0;
}
static void DiagService_RDBI_ReadActiveDiagnosticSession(void)
{
	Dcm_DiagServiceResponse_Frame.frame.dlc = 5;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x04;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x62;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0xF1;
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0x86;
	Dcm_DiagServiceResponse_Frame.frame.data4 = Dcm_DiagnosticSession;
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	Dcm_DiagServiceResponse_Frame.frame.idType = 0;
	Dcm_DiagServiceResponse_Frame.frame.id = 0;
	Dcm_DiagServiceResponse_Frame.frame.dlc = 0;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data4 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data5 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data6 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data7 = 0;
	Dcm_DiagServiceRequest_Frame.frame.idType = 0;
	Dcm_DiagServiceRequest_Frame.frame.id = 0;
	Dcm_DiagServiceRequest_Frame.frame.dlc = 0;
	Dcm_DiagServiceRequest_Frame.frame.data0 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data1 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data2 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data3 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data4 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data5 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data6 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data7 = 0;
}
static void DiagService_RDBI_ReadAliveTime(void)
{
	Dcm_DiagServiceResponse_Frame.frame.dlc = 8;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x07;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x62;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0x00;
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0x05;
	Dcm_DiagServiceResponse_Frame.frame.data4 = (uint8)(Dcm_AliveCounter >> 24u);
	Dcm_DiagServiceResponse_Frame.frame.data5 = (uint8)(Dcm_AliveCounter >> 16u);
	Dcm_DiagServiceResponse_Frame.frame.data6 = (uint8)(Dcm_AliveCounter >> 8u);
	Dcm_DiagServiceResponse_Frame.frame.data7 = (uint8)Dcm_AliveCounter;
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	Dcm_DiagServiceResponse_Frame.frame.idType = 0;
	Dcm_DiagServiceResponse_Frame.frame.id = 0;
	Dcm_DiagServiceResponse_Frame.frame.dlc = 0;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data4 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data5 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data6 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data7 = 0;
	Dcm_DiagServiceRequest_Frame.frame.idType = 0;
	Dcm_DiagServiceRequest_Frame.frame.id = 0;
	Dcm_DiagServiceRequest_Frame.frame.dlc = 0;
	Dcm_DiagServiceRequest_Frame.frame.data0 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data1 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data2 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data3 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data4 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data5 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data6 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data7 = 0;
}
static void DiagService_RDBPI_ReadPeriodicIgnitionCompleteStatus(void)
{
	Dcm_DiagServiceResponse_Frame.frame.dlc = 8;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x07;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x6A;
	if(Dcm_DiagServiceRequest_Frame.frame.data2 != 0x04) Dcm_DiagServiceResponse_Frame.frame.data2 = 0x01;
	else if(Dcm_DiagServiceRequest_Frame.frame.data2 == 0x04) Dcm_DiagServiceResponse_Frame.frame.data2 = 0x04;
	else
	{
		/* Do nothing. */
	}
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0x00;
	Dcm_DiagServiceResponse_Frame.frame.data4 = StatusList_ComOutValue[0];
	Dcm_DiagServiceResponse_Frame.frame.data5 = StatusList_RawValue[0];
	Dcm_DiagServiceResponse_Frame.frame.data6 = StatusList_InputStatus[0].errorStatus;
	Dcm_DiagServiceResponse_Frame.frame.data7 = StatusList_InputStatus[0].DCYStatus;
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	Dcm_DiagServiceResponse_Frame.frame.idType = 0;
	Dcm_DiagServiceResponse_Frame.frame.id = 0;
	Dcm_DiagServiceResponse_Frame.frame.dlc = 0;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data4 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data5 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data6 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data7 = 0;
	Dcm_DiagServiceRequest_Frame.frame.idType = 0;
	Dcm_DiagServiceRequest_Frame.frame.id = 0;
	Dcm_DiagServiceRequest_Frame.frame.dlc = 0;
	Dcm_DiagServiceRequest_Frame.frame.data0 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data1 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data2 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data3 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data4 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data5 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data6 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data7 = 0;
}
static void DiagService_RDBPI_ReadPeriodicGearboxSelectorCompleteStatus(void)
{
	Dcm_DiagServiceResponse_Frame.frame.dlc = 8;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x07;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x6A;
	if(Dcm_DiagServiceRequest_Frame.frame.data2 != 0x04) Dcm_DiagServiceResponse_Frame.frame.data2 = 0x01;
	else if(Dcm_DiagServiceRequest_Frame.frame.data2 == 0x04) Dcm_DiagServiceResponse_Frame.frame.data2 = 0x04;
	else
	{
		/* Do nothing. */
	}
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0x01;
	Dcm_DiagServiceResponse_Frame.frame.data4 = StatusList_ComOutValue[2];
	Dcm_DiagServiceResponse_Frame.frame.data5 = StatusList_RawValue[2];
	Dcm_DiagServiceResponse_Frame.frame.data6 = StatusList_InputStatus[2].errorStatus;
	Dcm_DiagServiceResponse_Frame.frame.data7 = StatusList_InputStatus[2].DCYStatus;
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	Dcm_DiagServiceResponse_Frame.frame.idType = 0;
	Dcm_DiagServiceResponse_Frame.frame.id = 0;
	Dcm_DiagServiceResponse_Frame.frame.dlc = 0;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data4 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data5 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data6 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data7 = 0;
	Dcm_DiagServiceRequest_Frame.frame.idType = 0;
	Dcm_DiagServiceRequest_Frame.frame.id = 0;
	Dcm_DiagServiceRequest_Frame.frame.dlc = 0;
	Dcm_DiagServiceRequest_Frame.frame.data0 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data1 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data2 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data3 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data4 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data5 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data6 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data7 = 0;
}
static void DiagService_RDBPI_ReadPeriodicDoorLockActuatorStatus(void)
{
	Dcm_DiagServiceResponse_Frame.frame.dlc = 8;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x07;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x6A;
	if(Dcm_DiagServiceRequest_Frame.frame.data2 != 0x04) Dcm_DiagServiceResponse_Frame.frame.data2 = 0x01;
	else if(Dcm_DiagServiceRequest_Frame.frame.data2 == 0x04) Dcm_DiagServiceResponse_Frame.frame.data2 = 0x04;
	else
	{
		/* Do nothing. */
	}
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0x02;
	Dcm_DiagServiceResponse_Frame.frame.data4 = CmdList_RawValue[2];
	Dcm_DiagServiceResponse_Frame.frame.data5 = CmdList_RawValue[3];
	Dcm_DiagServiceResponse_Frame.frame.data6 = CmdList_ActualValue[2];
	Dcm_DiagServiceResponse_Frame.frame.data7 = CmdList_ActualValue[3];
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	Dcm_DiagServiceResponse_Frame.frame.idType = 0;
	Dcm_DiagServiceResponse_Frame.frame.id = 0;
	Dcm_DiagServiceResponse_Frame.frame.dlc = 0;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data4 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data5 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data6 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data7 = 0;
	Dcm_DiagServiceRequest_Frame.frame.idType = 0;
	Dcm_DiagServiceRequest_Frame.frame.id = 0;
	Dcm_DiagServiceRequest_Frame.frame.dlc = 0;
	Dcm_DiagServiceRequest_Frame.frame.data0 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data1 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data2 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data3 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data4 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data5 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data6 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data7 = 0;
}
static void DiagService_RDBPI_ReadPeriodicWindshieldWiperActuatorStatus(void)
{
	Dcm_DiagServiceResponse_Frame.frame.dlc = 8;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x07;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x6A;
	if(Dcm_DiagServiceRequest_Frame.frame.data2 != 0x04) Dcm_DiagServiceResponse_Frame.frame.data2 = 0x01;
	else if(Dcm_DiagServiceRequest_Frame.frame.data2 == 0x04) Dcm_DiagServiceResponse_Frame.frame.data2 = 0x04;
	else
	{
		/* Do nothing. */
	}
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0x03;
	Dcm_DiagServiceResponse_Frame.frame.data4 = CmdList_RawValue[0];
	Dcm_DiagServiceResponse_Frame.frame.data5 = CmdList_RawValue[1];
	Dcm_DiagServiceResponse_Frame.frame.data6 = CmdList_ActualValue[0];
	Dcm_DiagServiceResponse_Frame.frame.data7 = CmdList_ActualValue[1];
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	Dcm_DiagServiceResponse_Frame.frame.idType = 0;
	Dcm_DiagServiceResponse_Frame.frame.id = 0;
	Dcm_DiagServiceResponse_Frame.frame.dlc = 0;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data4 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data5 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data6 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data7 = 0;
	Dcm_DiagServiceRequest_Frame.frame.idType = 0;
	Dcm_DiagServiceRequest_Frame.frame.id = 0;
	Dcm_DiagServiceRequest_Frame.frame.dlc = 0;
	Dcm_DiagServiceRequest_Frame.frame.data0 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data1 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data2 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data3 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data4 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data5 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data6 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data7 = 0;
}
static void DiagService_RDBPI_ReadPeriodicClimaFanStatus(void)
{
	Dcm_DiagServiceResponse_Frame.frame.dlc = 6;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x05;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x6A;
	if(Dcm_DiagServiceRequest_Frame.frame.data2 != 0x04) Dcm_DiagServiceResponse_Frame.frame.data2 = 0x01;
	else if(Dcm_DiagServiceRequest_Frame.frame.data2 == 0x04) Dcm_DiagServiceResponse_Frame.frame.data2 = 0x04;
	else
	{
		/* Do nothing. */
	}
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0x04;
	Dcm_DiagServiceResponse_Frame.frame.data4 = CmdList_RawValue[4];
	Dcm_DiagServiceResponse_Frame.frame.data5 = CmdList_ActualValue[4];
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	Dcm_DiagServiceResponse_Frame.frame.idType = 0;
	Dcm_DiagServiceResponse_Frame.frame.id = 0;
	Dcm_DiagServiceResponse_Frame.frame.dlc = 0;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data4 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data5 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data6 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data7 = 0;
	Dcm_DiagServiceRequest_Frame.frame.idType = 0;
	Dcm_DiagServiceRequest_Frame.frame.id = 0;
	Dcm_DiagServiceRequest_Frame.frame.dlc = 0;
	Dcm_DiagServiceRequest_Frame.frame.data0 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data1 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data2 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data3 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data4 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data5 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data6 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data7 = 0;
}
static void DiagService_RDBPI_ReadPeriodicLS(void)
{
	Dcm_DiagServiceResponse_Frame.frame.dlc = 8;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x07;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x6A;
	if(Dcm_DiagServiceRequest_Frame.frame.data2 != 0x04) Dcm_DiagServiceResponse_Frame.frame.data2 = 0x01;
	else if(Dcm_DiagServiceRequest_Frame.frame.data2 == 0x04) Dcm_DiagServiceResponse_Frame.frame.data2 = 0x04;
	else
	{
		/* Do nothing. */
	}
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0x05;
	Dcm_DiagServiceResponse_Frame.frame.data4 = StatusList_ComOutValue[1];
	Dcm_DiagServiceResponse_Frame.frame.data5 = StatusList_RawValue[1];
	Dcm_DiagServiceResponse_Frame.frame.data6 = StatusList_InputStatus[1].errorStatus;
	Dcm_DiagServiceResponse_Frame.frame.data7 = StatusList_InputStatus[1].DCYStatus;
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	Dcm_DiagServiceResponse_Frame.frame.idType = 0;
	Dcm_DiagServiceResponse_Frame.frame.id = 0;
	Dcm_DiagServiceResponse_Frame.frame.dlc = 0;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data4 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data5 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data6 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data7 = 0;
	Dcm_DiagServiceRequest_Frame.frame.idType = 0;
	Dcm_DiagServiceRequest_Frame.frame.id = 0;
	Dcm_DiagServiceRequest_Frame.frame.dlc = 0;
	Dcm_DiagServiceRequest_Frame.frame.data0 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data1 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data2 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data3 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data4 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data5 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data6 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data7 = 0;
}
static void DiagService_RDBPI_ReadPeriodicRS(void)
{
	Dcm_DiagServiceResponse_Frame.frame.dlc = 8;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x07;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x6A;
	if(Dcm_DiagServiceRequest_Frame.frame.data2 != 0x04) Dcm_DiagServiceResponse_Frame.frame.data2 = 0x01;
	else if(Dcm_DiagServiceRequest_Frame.frame.data2 == 0x04) Dcm_DiagServiceResponse_Frame.frame.data2 = 0x04;
	else
	{
		/* Do nothing. */
	}
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0x06;
	Dcm_DiagServiceResponse_Frame.frame.data4 = StatusList_ComOutValue[3];
	Dcm_DiagServiceResponse_Frame.frame.data5 = StatusList_RawValue[3];
	Dcm_DiagServiceResponse_Frame.frame.data6 = StatusList_InputStatus[3].errorStatus;
	Dcm_DiagServiceResponse_Frame.frame.data7 = StatusList_InputStatus[3].DCYStatus;
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	Dcm_DiagServiceResponse_Frame.frame.idType = 0;
	Dcm_DiagServiceResponse_Frame.frame.id = 0;
	Dcm_DiagServiceResponse_Frame.frame.dlc = 0;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data4 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data5 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data6 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data7 = 0;
	Dcm_DiagServiceRequest_Frame.frame.idType = 0;
	Dcm_DiagServiceRequest_Frame.frame.id = 0;
	Dcm_DiagServiceRequest_Frame.frame.dlc = 0;
	Dcm_DiagServiceRequest_Frame.frame.data0 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data1 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data2 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data3 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data4 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data5 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data6 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data7 = 0;
}
static void DiagService_DSC_DefaultSession(void)
{
	Dcm_DiagServiceResponse_Frame.frame.dlc = 3;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x02;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x50;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0x01;
	Dcm_DiagnosticSession = DEFAULT;
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	Dcm_DiagServiceResponse_Frame.frame.idType = 0;
	Dcm_DiagServiceResponse_Frame.frame.id = 0;
	Dcm_DiagServiceResponse_Frame.frame.dlc = 0;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data4 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data5 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data6 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data7 = 0;
	Dcm_DiagServiceRequest_Frame.frame.idType = 0;
	Dcm_DiagServiceRequest_Frame.frame.id = 0;
	Dcm_DiagServiceRequest_Frame.frame.dlc = 0;
	Dcm_DiagServiceRequest_Frame.frame.data0 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data1 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data2 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data3 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data4 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data5 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data6 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data7 = 0;
}
static void DiagService_DSC_ExtendedSession(void)
{
	Dcm_DiagServiceResponse_Frame.frame.dlc = 3;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x02;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x50;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0x03;
	Dcm_DiagnosticSession = EXTENDED;
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	Dcm_DiagServiceResponse_Frame.frame.idType = 0;
	Dcm_DiagServiceResponse_Frame.frame.id = 0;
	Dcm_DiagServiceResponse_Frame.frame.dlc = 0;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data4 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data5 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data6 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data7 = 0;
	Dcm_DiagServiceRequest_Frame.frame.idType = 0;
	Dcm_DiagServiceRequest_Frame.frame.id = 0;
	Dcm_DiagServiceRequest_Frame.frame.dlc = 0;
	Dcm_DiagServiceRequest_Frame.frame.data0 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data1 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data2 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data3 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data4 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data5 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data6 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data7 = 0;
}
static void DiagService_DSC_ProgrammingSession(void)
{
	Dcm_DiagServiceResponse_Frame.frame.dlc = 3;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x02;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x50;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0x02;
	Dcm_DiagnosticSession = PROGRAMMING;
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	NvM_WriteAll();
	EcuM_PerformReset(0);
}
static void DiagService_ER_HardReset(void)
{
	Dcm_DiagServiceResponse_Frame.frame.dlc = 3;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x02;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x51;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0x01;
	Dcm_DiagnosticSession = HARDRESET;
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	NvM_WriteAll();
	EcuM_PerformReset(0);
}
static void DiagService_ER_SoftReset(void)
{
	Dcm_DiagServiceResponse_Frame.frame.dlc = 3;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x02;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x51;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0x03;
	Dcm_DiagnosticSession = SOFTRESET;
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	NvM_WriteAll();
	EcuM_PerformReset(0);
}
static void DiagService_CDTCI_ClearDiagnosticInformation(void)
{
	Dcm_DiagServiceResponse_Frame.frame.dlc = 2;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x01;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x54;
	memset(Dem_DTCStoreArray, 0, sizeof(Dem_DTCStoreArray));
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	Dcm_DiagServiceResponse_Frame.frame.idType = 0;
	Dcm_DiagServiceResponse_Frame.frame.id = 0;
	Dcm_DiagServiceResponse_Frame.frame.dlc = 0;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data4 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data5 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data6 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data7 = 0;
	Dcm_DiagServiceRequest_Frame.frame.idType = 0;
	Dcm_DiagServiceRequest_Frame.frame.id = 0;
	Dcm_DiagServiceRequest_Frame.frame.dlc = 0;
	Dcm_DiagServiceRequest_Frame.frame.data0 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data1 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data2 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data3 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data4 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data5 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data6 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data7 = 0;
}
static void DiagService_RDTCI_ReadDTCInformationSupportedDtc(void)
{
	__disable_irq();
	Dcm_DiagServiceResponse_Frame.frame.dlc = 8;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x07;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x59;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0x0A;
	Dcm_DiagServiceResponse_Frame.frame.data3 = Dem_DTCStoreArray[0];
	Dcm_DiagServiceResponse_Frame.frame.data4 = Dem_DTCStoreArray[1];
	Dcm_DiagServiceResponse_Frame.frame.data5 = Dem_DTCStoreArray[2];
	Dcm_DiagServiceResponse_Frame.frame.data6 = Dem_DTCStoreArray[3];
	Dcm_DiagServiceResponse_Frame.frame.data7 = Dem_DTCStoreArray[4];
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	HAL_Delay(5);
	Dcm_DiagServiceResponse_Frame.frame.dlc = 8;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x07;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x59;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0x0A;
	Dcm_DiagServiceResponse_Frame.frame.data3 = Dem_DTCStoreArray[5];
	Dcm_DiagServiceResponse_Frame.frame.data4 = Dem_DTCStoreArray[6];
	Dcm_DiagServiceResponse_Frame.frame.data5 = Dem_DTCStoreArray[7];
	Dcm_DiagServiceResponse_Frame.frame.data6 = Dem_DTCStoreArray[8];
	Dcm_DiagServiceResponse_Frame.frame.data7 = Dem_DTCStoreArray[9];
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	HAL_Delay(5);
	Dcm_DiagServiceResponse_Frame.frame.dlc = 8;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x07;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x59;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0x0A;
	Dcm_DiagServiceResponse_Frame.frame.data3 = Dem_DTCStoreArray[10];
	Dcm_DiagServiceResponse_Frame.frame.data4 = Dem_DTCStoreArray[11];
	Dcm_DiagServiceResponse_Frame.frame.data5 = Dem_DTCStoreArray[12];
	Dcm_DiagServiceResponse_Frame.frame.data6 = Dem_DTCStoreArray[13];
	Dcm_DiagServiceResponse_Frame.frame.data7 = Dem_DTCStoreArray[14];
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	HAL_Delay(5);
	Dcm_DiagServiceResponse_Frame.frame.dlc = 8;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x07;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x59;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0x0A;
	Dcm_DiagServiceResponse_Frame.frame.data3 = Dem_DTCStoreArray[15];
	Dcm_DiagServiceResponse_Frame.frame.data4 = Dem_DTCStoreArray[16];
	Dcm_DiagServiceResponse_Frame.frame.data5 = Dem_DTCStoreArray[17];
	Dcm_DiagServiceResponse_Frame.frame.data6 = Dem_DTCStoreArray[18];
	Dcm_DiagServiceResponse_Frame.frame.data7 = Dem_DTCStoreArray[19];
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	HAL_Delay(5);
	Dcm_DiagServiceResponse_Frame.frame.dlc = 8;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x07;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x59;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0x0A;
	Dcm_DiagServiceResponse_Frame.frame.data3 = Dem_DTCStoreArray[20];
	Dcm_DiagServiceResponse_Frame.frame.data4 = Dem_DTCStoreArray[21];
	Dcm_DiagServiceResponse_Frame.frame.data5 = Dem_DTCStoreArray[22];
	Dcm_DiagServiceResponse_Frame.frame.data6 = Dem_DTCStoreArray[23];
	Dcm_DiagServiceResponse_Frame.frame.data7 = Dem_DTCStoreArray[24];
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	HAL_Delay(5);
	Dcm_DiagServiceResponse_Frame.frame.dlc = 4;
	Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
	Dcm_DiagServiceResponse_Frame.frame.idType = 1;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0x03;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0x59;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0x0A;
	Dcm_DiagServiceResponse_Frame.frame.data3 = Dem_DTCStoreArray[25];
	CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
	HAL_Delay(5);
	Dcm_DiagServiceResponse_Frame.frame.idType = 0;
	Dcm_DiagServiceResponse_Frame.frame.id = 0;
	Dcm_DiagServiceResponse_Frame.frame.dlc = 0;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data4 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data5 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data6 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data7 = 0;
	Dcm_DiagServiceRequest_Frame.frame.idType = 0;
	Dcm_DiagServiceRequest_Frame.frame.id = 0;
	Dcm_DiagServiceRequest_Frame.frame.dlc = 0;
	Dcm_DiagServiceRequest_Frame.frame.data0 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data1 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data2 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data3 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data4 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data5 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data6 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data7 = 0;
	__enable_irq();
}
void Dcm_MainFunction(void)
{
	/* Main counter. */
	static uint32 Dcm_MainCounter = 0;
	/* Increment time without reset. */
	Dcm_AliveCounter += 5;
	/* Set diagnostic session to default. */
	if(Dcm_MainCounter == 0) Dcm_DiagnosticSession = DEFAULT;
	else
	{
		/* Do nothing. */
	}
	if(Dcm_DiagServiceRequest_Frame.frame.data1 == 0x3E) DiagService_TP_TesterPresent();
	else
	{
		/* Do nothing. */
	}
	if(Dcm_DiagServiceRequest_Frame.frame.data1 == 0x28) DiagService_CC_CommunicationControl();
	else
	{
		/* Do nothing. */
	}
	if(Dcm_DiagServiceRequest_Frame.frame.data1 == 0x85) DiagService_CDTCS_ControlDTCSetting();
	else
	{
		/* Do nothing. */
	}
	/* Process diagnostic session control. */
	if(Dcm_DiagServiceRequest_Frame.frame.data1 == 0x10)
	{
		/* DEFAULT */
		if(Dcm_DiagServiceRequest_Frame.frame.data2 == 0x01) DiagService_DSC_DefaultSession();
		else
		{
			/* Do nothing. */
		}
		/* EXTENDED */
		if(Dcm_DiagServiceRequest_Frame.frame.data2 == 0x03) DiagService_DSC_ExtendedSession();
		else
		{
			/* Do nothing. */
		}
		/* PROGRAMMING */
		if(Dcm_DiagServiceRequest_Frame.frame.data2 == 0x02 && Dcm_DiagnosticSession == EXTENDED) DiagService_DSC_ProgrammingSession();
		else
		{
			/* Do nothing. */
		}
		/* CODING */
		if(Dcm_DiagServiceRequest_Frame.frame.data2 == 0x04 && Dcm_DiagnosticSession == EXTENDED) DiagService_DSC_CodingSession();
		else
		{
			/* Do nothing. */
		}
		/* CALIBRATION */
		if(Dcm_DiagServiceRequest_Frame.frame.data2 == 0x05 && Dcm_DiagnosticSession == EXTENDED) DiagService_DSC_CalibrationSession();
		else
		{
			/* Do nothing. */
		}
	}
	else
	{
		/* Do nothing. */
	}

	if(Dcm_DiagServiceRequest_Frame.frame.data3 == 0x86 && Dcm_DiagServiceRequest_Frame.frame.data2 == 0xF1 && Dcm_DiagServiceRequest_Frame.frame.data1 == 0x22) DiagService_RDBI_ReadActiveDiagnosticSession();
	else
	{
		/* Do nothing. */
	}
	/* Execute hard reset. */
	if(Dcm_DiagServiceRequest_Frame.frame.data1 == 0x11 && Dcm_DiagServiceRequest_Frame.frame.data2 == 0x01 &&Dcm_DiagServiceRequest_Frame.frame.data0 == 0x02) DiagService_ER_HardReset();
	else
	{
		/* Do nothing. */
	}
	/* Execute soft reset. */
	if(Dcm_DiagServiceRequest_Frame.frame.data1 == 0x11 && Dcm_DiagServiceRequest_Frame.frame.data2 == 0x03 && Dcm_DiagServiceRequest_Frame.frame.data0 == 0x02) DiagService_ER_SoftReset();
	else
	{
		/* Do nothing. */
	}
	/* Execute clear DTC. */
	if(Dcm_DiagServiceRequest_Frame.frame.data1 == 0x14) DiagService_CDTCI_ClearDiagnosticInformation();
	else
	{
		/* Do nothing. */
	}
	/* Execute read DTC. */
	if(Dcm_DiagServiceRequest_Frame.frame.data1 == 0x19) DiagService_RDTCI_ReadDTCInformationSupportedDtc();
	else
	{
		/* Do nothing. */
	}
	/* Extended session routines. */
	if(Dcm_DiagnosticSession == EXTENDED)
	{
		/* Process RDPBI. */
		if(Dcm_DiagServiceRequest_Frame.frame.data1 == 0x2A)
		{
			if(Dcm_DiagServiceRequest_Frame.frame.data2 == 0x04)
			{
				Dcm_RDBPI_Table[Dcm_DiagServiceRequest_Frame.frame.data3].FuncPtr();
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
		/* Read data routines. */
		if(Dcm_DiagServiceRequest_Frame.frame.data1 == 0x22)
		{
			if(Dcm_DiagServiceRequest_Frame.frame.data2 == 0x00)
			{
				if(Dcm_DiagServiceRequest_Frame.frame.data3 == 0x02) DiagService_RDBI_ReadCodingData();
				else
				{
					/* Do nothing. */
				}
				if(Dcm_DiagServiceRequest_Frame.frame.data3 == 0x03) DiagService_RDBI_ReadCalibrationData();
				else
				{
					/* Do nothing. */
				}
				if(Dcm_DiagServiceRequest_Frame.frame.data3 == 0x05) DiagService_RDBI_ReadAliveTime();
				else
				{
					/* Do nothing. */
				}
			}
			else
			{
				/* Do nothing. */
			}
			if(Dcm_DiagServiceRequest_Frame.frame.data2 == 0xF1)
			{
				if(Dcm_DiagServiceRequest_Frame.frame.data3 == 0x80) DiagService_RDBI_ReadSWVersion();
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
	}
	else
	{/* Send NRC conditionsNotCorrect. */
		if(Dcm_DiagServiceRequest_Frame.frame.data1 == 0x22 || (Dcm_DiagServiceRequest_Frame.frame.data1 == 0x10 && (Dcm_DiagServiceRequest_Frame.frame.data2 != 0x01 || Dcm_DiagServiceRequest_Frame.frame.data2 != 0x03)))
		{
			Dcm_DiagServiceResponse_Frame.frame.dlc = 4;
			Dcm_DiagServiceResponse_Frame.frame.id = 0x701;
			Dcm_DiagServiceResponse_Frame.frame.idType = 1;
			Dcm_DiagServiceResponse_Frame.frame.data0 = 0x03;
			Dcm_DiagServiceResponse_Frame.frame.data1 = 0x7F;
			Dcm_DiagServiceResponse_Frame.frame.data2 = 0x19;
			Dcm_DiagServiceResponse_Frame.frame.data3 = 0x22;
			CanSpi_Transmit(&Dcm_DiagServiceResponse_Frame);
			Dcm_DiagServiceResponse_Frame.frame.idType = 0;
			Dcm_DiagServiceResponse_Frame.frame.id = 0;
			Dcm_DiagServiceResponse_Frame.frame.dlc = 0;
			Dcm_DiagServiceResponse_Frame.frame.data0 = 0;
			Dcm_DiagServiceResponse_Frame.frame.data1 = 0;
			Dcm_DiagServiceResponse_Frame.frame.data2 = 0;
			Dcm_DiagServiceResponse_Frame.frame.data3 = 0;
			Dcm_DiagServiceResponse_Frame.frame.data4 = 0;
			Dcm_DiagServiceResponse_Frame.frame.data5 = 0;
			Dcm_DiagServiceResponse_Frame.frame.data6 = 0;
			Dcm_DiagServiceResponse_Frame.frame.data7 = 0;
			Dcm_DiagServiceRequest_Frame.frame.idType = 0;
			Dcm_DiagServiceRequest_Frame.frame.id = 0;
			Dcm_DiagServiceRequest_Frame.frame.dlc = 0;
			Dcm_DiagServiceRequest_Frame.frame.data0 = 0;
			Dcm_DiagServiceRequest_Frame.frame.data1 = 0;
			Dcm_DiagServiceRequest_Frame.frame.data2 = 0;
			Dcm_DiagServiceRequest_Frame.frame.data3 = 0;
			Dcm_DiagServiceRequest_Frame.frame.data4 = 0;
			Dcm_DiagServiceRequest_Frame.frame.data5 = 0;
			Dcm_DiagServiceRequest_Frame.frame.data6 = 0;
			Dcm_DiagServiceRequest_Frame.frame.data7 = 0;
		}
		else
		{
			/* Do nothing. */
		}
	}
	/* Reset buffers. */
	Dcm_DiagServiceResponse_Frame.frame.idType = 0;
	Dcm_DiagServiceResponse_Frame.frame.id = 0;
	Dcm_DiagServiceResponse_Frame.frame.dlc = 0;
	Dcm_DiagServiceResponse_Frame.frame.data0 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data1 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data2 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data3 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data4 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data5 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data6 = 0;
	Dcm_DiagServiceResponse_Frame.frame.data7 = 0;
	Dcm_DiagServiceRequest_Frame.frame.idType = 0;
	Dcm_DiagServiceRequest_Frame.frame.id = 0;
	Dcm_DiagServiceRequest_Frame.frame.dlc = 0;
	Dcm_DiagServiceRequest_Frame.frame.data0 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data1 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data2 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data3 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data4 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data5 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data6 = 0;
	Dcm_DiagServiceRequest_Frame.frame.data7 = 0;
	Dcm_MainCounter++;
}
/* FUNCTIONS END */
/* STOP OF FILE */
