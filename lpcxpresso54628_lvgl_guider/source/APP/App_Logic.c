#include "App_Logic.h"
//#include "Rte.h"


uint8_t g_temp = 0;
uint8_t g_hum = 0;
uint8_t g_pwm_duty_cycle = 0;


void App_Logic_MainLoop(void)
{
/* Future state machines or application logic */
}


/* Acquire sensor values via RTE */
void App_Logic_UpdateSensorValues(void)
{
uint8_t t, h;


	if (Rte_Read_DHT11(&t, &h))
	{
		g_temp = t;
		g_hum = h;
	}
}


uint8_t App_Logic_GetTemperature(void)
{
	return g_temp;
}


uint8_t App_Logic_GetHumidity(void)
{
	return g_hum;
}

uint8_t App_Logic_GetPwmValue()
{
	return g_pwm_duty_cycle;
}


/* Example PWM logic */
void App_Logic_SetMotorPwm(uint8_t dutyPercent)
{
	Rte_Write_PwmDuty(dutyPercent);
}
