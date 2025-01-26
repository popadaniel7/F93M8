#include "Ifx_Types.h"
#include "IfxSrc.h"
#include "IfxScuEru.h"

#define REQ_IN                      &IfxScu_REQ4A_P33_7_IN
#define TRIGGER_PIN                 &MODULE_P33,7
#define REQ_IN2                     &IfxScu_REQ6D_P11_10_IN
#define TRIGGER_PIN2                &MODULE_P11,10
#define REQ_IN3                     &IfxScu_REQ0A_P15_4_IN
#define TRIGGER_PIN3                &MODULE_P15,4

typedef struct
{
    IfxScu_Req_In *reqPin;                      /* External request pin                                             */
    IfxScuEru_InputChannel inputChannel;        /* Input channel EICRm depending on input pin                       */
    IfxScuEru_InputNodePointer triggerSelect;   /* Input node pointer                                               */
    IfxScuEru_OutputChannel outputChannel;      /* Output channel                                                   */
    volatile Ifx_SRC_SRCR *src;                 /* Service request register                                         */
}ERUconfig;

extern ERUconfig g_ERUconfig;   /* ERU configuration for Encoder A */
extern ERUconfig g_ERUconfig2;   /* ERU configuration for Encoder B */
extern ERUconfig g_ERUconfig3;   /* ERU configuration */
extern ERUconfig g_ERUconfig4;   /* ERU configuration */
/* Global Variables for Encoder */
extern volatile sint32 encoderCount;
extern volatile sint8 direction; // 1 for forward, -1 for backward
extern volatile uint8 lastEncodedA;
extern volatile uint8 lastEncodedB;
extern uint32 Eru_PpsSpeedSenStat;

extern void Eru_Init(void);
extern void Eru_EncoderA(void);
extern void Eru_EncoderB(void);
extern void Eru_SpeedSen(void);
