#ifndef ADC_FILTERING_H_
#define ADC_FILTERING_H_

#include "Ifx_Types.h"
#include "IfxEvadc_Adc.h"

typedef struct
{
        IfxEvadc_Vadcg_In *analogInput;
        IfxEvadc_ChannelResult resultRegister;
}channel;

typedef struct
{
        uint16 currentValue;
        uint16 max;
        uint16 min;
}measureStats;

extern IfxEvadc_Adc g_evadc;

extern void Ain_FilteringInit(void);
#endif /* ADC_FILTERING_H_ */
