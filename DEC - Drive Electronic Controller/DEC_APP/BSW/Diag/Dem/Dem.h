#include "Ifx_Types.h"

#define COLDET_DTC_ID_IR_SENSOR_MALFUNCTION                             0x15u//0
#define COMMASTER_DTC_ID_MESSAGE_0X10A_MISSING                          0x16u//1
#define COMMASTER_DTC_ID_MESSAGE_0X108_MISSING                          0x17u//2
#define COMMASTER_DTC_ID_MESSAGE_0X101_MISSING                          0x18u//3
#define COMMASTER_DTC_ID_MESSAGE_0X100_MISSING                          0x19u//4
#define MCUSM_DTC_ID_SW_ERROR                                           0x1Au//5
#define COMMASTER_DTC_ID_SIGNAL_AUTOCLIMATE_INVALID                     0x1Bu//6
#define COMMASTER_DTC_ID_SIGNAL_CLIMATETEMPERATURE_INVALID              0x1Cu//7
#define COMMASTER_DTC_ID_SIGNAL_DISPLAYMODEREQUEST_INVALID              0x1Du//8
#define COMMASTER_DTC_ID_SIGNAL_FANVALUE_INVALID                        0x1Eu//9
#define COMMASTER_DTC_ID_SIGNAL_RECIRCULATION_INVALID                   0x1Fu//10
#define COMMASTER_DTC_ID_SIGNAL_ROTARYLIGHTSWITCH_INVALID               0x20u//11
#define COMMASTER_DTC_ID_SIGNAL_STATUSIGNITION_INVALID                  0x21u//12
#define COMMASTER_DTC_ID_SIGNAL_STATUSGEARBOX_INVALID                   0x22u//13
#define COMMASTER_DTC_ID_SIGNAL_STATUSDOORLEFT_INVALID                  0x23u//14
#define COMMASTER_DTC_ID_SIGNAL_STATUSDOORRIGHT_INVALID                 0x24u//15
#define COMMASTER_DTC_ID_SIGNAL_STATUSHIGHBEAM_INVALID                  0x25u//16
#define COMMASTER_DTC_ID_SIGNAL_STATUSFOGLIGHTS_INVALID                 0x26u//17
#define COMMASTER_DTC_ID_SIGNAL_STATUSWIPERSTOCK_INVALID                0x27u//18
#define COMMASTER_DTC_ID_SIGNAL_STATUSOUTSIDETEMPERATURE_INVALID        0x28u//19
#define COMMASTER_DTC_ID_SIGNAL_STATUSTURNSIGNALS_INVALID               0x29u//20
#define COMMASTER_DTC_ID_SIGNAL_STATUSHC05_INVALID                      0x2Au//21
#define COMMASTER_DTC_ID_MESSAGE_0X001_MISSING                          0x2Bu//22
#define ENCCAL_INVALID_CODING                                           0x2Cu//23
#define ENCCAL_INVALID_CALIBRATION                                      0x2Du//24
#define ENCCAL_INVALID_VODATA                                           0x2Eu//25
#define COMMASTER_DTC_ID_DMU_NOT_ACTIVE_ON_CAN                          0x2Fu//26
#define COMMASTER_DTC_ID_MESSAGE_0X202_MISSING                          0x30u//27
#define COMMASTER_DTC_ID_SIGNAL_HC05CONNECTIONSTATUS_INVALID            0x31u//28
#define COMMASTER_DTC_ID_SIGNAL_LIGHTSENSORSTATUS_INVALID               0x32u//28
#define COMMASTER_DTC_ID_SIGNAL_E2EERROR_SDTS                           0x33u//28

#define DEM_NUMBER_OF_DTCS 80u

extern uint8 Dem_DtcArray[DEM_NUMBER_OF_DTCS];
extern uint8 Dem_DtcArray_Default[DEM_NUMBER_OF_DTCS];
extern uint8 Dem_ControlDtcSetting;

extern void Dem_SetDtc(uint32 dtcId, uint8 dtcStatus, uint8 index);
extern void Dem_Init(void);
extern void Dem_PreInit(void);
