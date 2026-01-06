#ifndef BSW_PWM_H
#define BSW_PWM_H

#include "Bsw_Types.h"

//#include "portmacro.h"
//#include "LPC54628_COMMON.H"

// DC MOTOR FREQUENCY
#define _20_000_Hz 20000U
#define _50_DUTY_CYCLE 50U

//BaseType_t stat;
//BaseType_t stat_pwm;
//BaseType_t stat_dht11;
//BaseType_t stat_update_values;
//sctimer_config_t sctimerInfo;
//sctimer_pwm_signal_param_t pwmParam;
//sctimer_pwm_signal_param_t pwmParam1;
//uint32_t event;
//uint32_t sctimerClock;


Std_ReturnType Bsw_Pwm_Init(uint8_t channel);
Std_ReturnType Bsw_Pwm_SetDuty(uint8_t dutyPercent);

#endif
