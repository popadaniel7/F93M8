#include "Ifx_Types.h"
#include "IfxGtm_Atom_Pwm.h"

#define CLK_FREQ            1000000.0f  /* CMU clock frequency, in Hertz */
/* PWM periods based on CLK_FREQ = 1,000,000 Hz */
#define PWM_PERIOD          50         /* PWM period for ATOM1_0 (20 KHz)          */
#define PWM_PERIOD2         50         /* PWM period for ATOM1_6N (20 KHz)         */
#define PWM_PERIOD3         50         /* PWM period for ATOM3_1N (20 KHz)         */
#define PWM_PERIOD4         50         /* PWM period for ATOM3_2N (20 KHz)         */
#define PWM_PERIOD5         20000         /* PWM period for ATOM3_2N (20 KHz)         */

extern IfxGtm_Atom_Pwm_Config g_atomConfig;                            /* Timer configuration structure                    */
extern IfxGtm_Atom_Pwm_Driver g_atomDriver;                            /* Timer Driver structure                           */
extern IfxGtm_Atom_Pwm_Config g_atomConfig2;                           /* Timer configuration structure                    */
extern IfxGtm_Atom_Pwm_Driver g_atomDriver2;                           /* Timer Driver structure                           */
extern IfxGtm_Atom_Pwm_Config g_atomConfig3;                           /* Timer configuration structure                    */
extern IfxGtm_Atom_Pwm_Driver g_atomDriver3;                           /* Timer Driver structure                           */
extern IfxGtm_Atom_Pwm_Config g_atomConfig4;                           /* Timer configuration structure                    */
extern IfxGtm_Atom_Pwm_Driver g_atomDriver4;                           /* Timer Driver structure                           */
extern IfxGtm_Atom_Pwm_Config g_atomConfig5;                           /* Timer configuration structure                    */
extern IfxGtm_Atom_Pwm_Driver g_atomDriver5;                           /* Timer Driver structure                           */

extern void Gtm_Pwm_Init(void);
extern void Gtm_Pwm_SetDutyCycle(uint32 dutyCycle, IfxGtm_Atom_Pwm_Config* gATOMCfg, IfxGtm_Atom_Pwm_Driver* gATOMDriver);

