//#include "Bsw_Pwm.h"
//#include "fsl_sctimer.h"
////sctimer_config_t sctimerInfo;
////sctimer_pwm_signal_param_t pwmParam;
//////sctimer_pwm_signal_param_t pwmParam1;
////uint32_t event;
////uint32_t sctimerClock;
//
//
//Std_ReturnType Bsw_Pwm_Init(uint8 channel)
//{
//   // Default values for PWM
//    SCTIMER_GetDefaultConfig(&sctimerInfo);
//
//    /* Initialize SCTimer module */
//    SCTIMER_Init(SCT0, &sctimerInfo);
//    sctimerClock = CLOCK_GetFreq(kCLOCK_BusClk);
//
//    /* Configure first PWM with frequency 20kHZ from first output */
//    // P3_14 - J13 - 7
//    pwmParam.output           = kSCTIMER_Out_3;
//    pwmParam.level            = kSCTIMER_HighTrue;
//    pwmParam.dutyCyclePercent = _50_DUTY_CYCLE;
//    uint32_t PWM_signal_frequency_Hz = _20_000_Hz;
//
//    // P3_10 - J13 - 5
////    pwmParam1.output           = kSCTIMER_Out_4;
////    pwmParam1.level            = kSCTIMER_HighTrue;
////    pwmParam1.dutyCyclePercent = _50_DUTY_CYCLE;
//
//    // Setup PWM and guard for fail
//    if (SCTIMER_SetupPwm(SCT0, &pwmParam, kSCTIMER_EdgeAlignedPwm, PWM_signal_frequency_Hz, sctimerClock, &event) == kStatus_Fail)
//    {
//        return E_NOT_OK;
//    }
//    return E_OK;
//}
//
//Std_ReturnType Bsw_Pwm_SetDuty(uint8 dutyPercent)
//{
//	SCTIMER_UpdatePwmDutycycle(SCT0, kSCTIMER_Out_3, dutyPercent, event);
//    return E_OK;
//}
