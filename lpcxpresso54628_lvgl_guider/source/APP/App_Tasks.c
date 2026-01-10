#include "App_Tasks.h"
#include "App_Logic.h"
//#include "../RTE/Rte.h"
#include "FreeRTOS.h"
#include "task.h"
#include "stdint.h"


/* Global logger task handle */
//TaskHandle_t g_loggerTaskHandle = NULL;

//static volatile bool s_lvgl_initialized = false;
//char data_for_display[32];
//char buffer[32];
//char str[8];
//extern volatile uint8_t pwm_value;

/* Main APP task (if needed for periodic supervision) */
void AppTask(void *pv)
{
	for(;;)
	{
		App_Logic_MainLoop();
//		LCD_Display();
		vTaskDelay(pdMS_TO_TICKS(10));
	}
}


// DHT update
void Logic_Task(void *param)
{
	for(;;)
	{
		App_Logic_UpdateSensorValues();

		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}


// LCD
void LCD_Task(void *pv)
{
	LCD_Init();
	for(;;)
	{
		App_Logic_PrepareUiData();
		LCD_Display();
	}
}




