#include "Ifx_Types.h"

#define CHANNELS_NUM                    1u
#define ADC_MAX_VALUE                   4095.0f
#define ADC_VREF_VALUE                  45.0f
#define AIN_ZERO                        0U
#define AIN_GP2Y0A21YK0F_BLINDVOLTAGE   0.20f
#define AIN_INVALIDVALUE                0xFFFFU
#define AIN_GP2Y0A21YK0F_MINDIST        10.0f
#define AIN_GP2Y0A21YK0F_MAXDIST        80.0f
#define AIN_DIVISIONFACTOR_TEN          10.0f

extern float Ain_IRSensorValue;
extern uint32 Ain_AuxBufferDma[CHANNELS_NUM];

extern void Ain_MainFunction(void);
extern float Ain_AdcToVoltage(float rawAdc, float refVoltage);
extern float Ain_ConvertCurrentSense(float rawAdc);
extern float Ain_ConvertVoltageToDistanceGP2Y0A21YK0F(float voltage);
extern void Ain_ProcessIRSensorValue(void);
