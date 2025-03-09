#ifndef ADC_FILTERING_H_
#define ADC_FILTERING_H_

#include "Ifx_Types.h"
#include "IfxEvadc_Adc.h"

#define AN0                 0u
#define DIV_FACTOR_AVRG     4u   /* Divider factor for AN39: 4 accumulated conversions lead to a gain of 4           */
#define DIV_FACTOR_FIR      3u   /* Gain of the FIR filter (The DC gain is equal to the sum of its coefficients)     */
#define DIV_FACTOR_IIR      4u   /* Gain of the IIR filter (The selectable IIR coefficients lead to a gain of 4)     */
#define EVADC_MAX           4095u            /* Maximum value (conversion results are expressed in 12-bit format)    */
#define EVADC_MIN           0u               /* Minimum value of a conversion result                                 */
#define VAREF_VOLTAGE       3.3u             /* Maximum voltage value measurable by the EVADC                        */
#define VOLT_CONVERSION     VAREF_VOLTAGE / EVADC_MAX   /* Conversion factor from ADC value to voltage (V)          */
/* Structure to store the selected channel and its assigned result register */
typedef struct
{
    IfxEvadc_Vadcg_In *analogInput;
    IfxEvadc_ChannelResult resultRegister;
}channel;
/* Structure to store the processed values of the conversions */
typedef struct
{
    uint16 currentValue;
    uint16 max;
    uint16 min;
}measureStats;
extern IfxEvadc_Adc g_evadc;                                     /* Global variable for configuring the EVADC module       */

extern void Ain_FilteringInit(void);                                         /* Function to initialize the EVADC module                  */
#endif /* ADC_FILTERING_H_ */
