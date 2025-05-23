#include "Ain_Filtering.h"
#include "Ain.h"

void Ain_Filtering_InitEvAdcModule(void);
void Ain_Filtering_InitEvAdcGroup(void);
void Ain_Filtering_InitEvAdcChannels(void);
void Ain_Filtering_ApplyFiltering(void);

IfxEvadc_Adc g_evadc;
IfxEvadc_Adc_Group g_evadcGroup;
IfxEvadc_Adc_Channel g_evadcChannel[CHANNELS_NUM];
channel g_chn[] =
{
        {&IfxEvadc_G8CH4_P40_6_IN,  IfxEvadc_ChannelResult_4},
};

void Ain_FilteringInit(void)
{
    Ain_Filtering_InitEvAdcModule();
    Ain_Filtering_InitEvAdcGroup();
    Ain_Filtering_InitEvAdcChannels();
    Ain_Filtering_ApplyFiltering();
    /* Start the scan */
    IfxEvadc_Adc_startQueue(&g_evadcGroup, IfxEvadc_RequestSource_queue0);
}

void Ain_Filtering_InitEvAdcModule(void)
{
    IfxEvadc_Adc_Config adcConf;
    IfxEvadc_Adc_initModuleConfig(&adcConf, &MODULE_EVADC);
    IfxEvadc_Adc_initModule(&g_evadc, &adcConf);
}

void Ain_Filtering_InitEvAdcGroup(void)
{
    IfxEvadc_Adc_GroupConfig adcGroupConf;
    IfxEvadc_Adc_initGroupConfig(&adcGroupConf, &g_evadc);
    adcGroupConf.arbiter.requestSlotQueue0Enabled = TRUE;
    adcGroupConf.queueRequest[0].triggerConfig.gatingMode = IfxEvadc_GatingMode_always;
    adcGroupConf.master = IfxEvadc_GroupId_8;
    adcGroupConf.groupId = IfxEvadc_GroupId_8;
    IfxEvadc_Adc_initGroup(&g_evadcGroup, &adcGroupConf);
}

void Ain_Filtering_InitEvAdcChannels(void)
{
    IfxEvadc_Adc_ChannelConfig adcChannelConf;
    uint16 chnNum;

    for(chnNum = 0u; chnNum < CHANNELS_NUM; chnNum++)
    {
        IfxEvadc_Adc_initChannelConfig(&adcChannelConf, &g_evadcGroup);
        adcChannelConf.channelId = g_chn[chnNum].analogInput->channelId;
        adcChannelConf.resultRegister = g_chn[chnNum].resultRegister;
        IfxEvadc_Adc_initChannel(&g_evadcChannel[chnNum], &adcChannelConf);
        IfxEvadc_Adc_addToQueue(&g_evadcChannel[chnNum], IfxEvadc_RequestSource_queue0, IFXEVADC_QUEUE_REFILL);
    }
}

void Ain_Filtering_ApplyFiltering(void)
{
    EVADC_G8_RCR4.B.DMM = IfxEvadc_DataModificationMode_resultFilteringMode;
    EVADC_G8_RCR4.B.DRCTR = IfxEvadc_DataReductionControlMode_15;
}
