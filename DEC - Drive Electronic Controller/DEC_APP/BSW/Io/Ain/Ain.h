#include "Ifx_Types.h"

#define CHANNELS_NUM                    1u                                  /* Number of used channels                          */
#define ADC_MAX_VALUE                   4095.0f
#define ADC_VREF_VALUE                  50.0f
#define AIN_MAXAVG_CNT                  8U
#define AIN_ZERO                        0U
#define AIN_GP2Y0A21YK0F_BLINDVOLTAGE   0.20f
#define AIN_INVALIDVALUE                0xFFFFU
#define AIN_GP2Y0A21YK0F_MINDIST        10.0f
#define AIN_GP2Y0A21YK0F_MAXDIST        80.0f
#define AIN_DIVISIONFACTOR_TEN          10.0f
#define AIN_IRCYCLECOUNTER              40U

extern float Ain_IRSensorValue;

extern void Ain_MainFunction(void);
extern float Ain_AdcToVoltage(float rawAdc, float refVoltage);
extern float Ain_ConvertCurrentSense(float rawAdc);
extern float Ain_ConvertVoltageToDistanceGP2Y0A21YK0F(float voltage);
extern void Ain_ProcessIRSensorValue(void);
