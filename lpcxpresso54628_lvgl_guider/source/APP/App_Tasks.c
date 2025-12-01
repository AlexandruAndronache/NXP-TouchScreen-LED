#include "App_Tasks.h"
#include "App_Logic.h"
#include "../RTE/Rte.h"
#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>

//static volatile bool s_lvgl_initialized = false;
//char data_for_display[32];
//char buffer[32];
//char str[8];
//volatile int pwm_value;

/* Main APP task (if needed for periodic supervision) */
//void App_MainTask(void *pv)
//{
//	for(;;)
//	{
//		App_Logic_MainLoop();
//		vTaskDelay(pdMS_TO_TICKS(100));
//	}
//}


/* Motor PWM control */
void App_PwmTask(void *param)
{
	for(;;)
	{
		App_Logic_SetMotorPwm(pwm_value);
		vTaskDelay(pdMS_TO_TICKS(50));
	}
}


/* DHT11 acquisition */
void App_DhtTask(void *param)
{
	for(;;)
	{
		App_Logic_UpdateSensorValues();
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}


/* Display Update Task (high‑level UI) */
void App_DisplayTask1(void *param)
{
	char buf[32];


	for(;;)
	{
	uint8_t t = App_Logic_GetTemperature();
	uint8_t h = App_Logic_GetHumidity();


	snprintf(buf, sizeof(buf), "T:%uC H:%u%%", t, h);
	//Rte_Display_SetText(RTE_LABEL_DHT, buf);


	vTaskDelay(pdMS_TO_TICKS(500));
	}
}


//void ui_fast_update_timer(lv_timer_t *t)
//{
//    lv_label_set_text(guider_ui.screen_1_label_10, buffer); // fast PWM update
//}
//
//void ui_slow_update_timer(lv_timer_t *t)
//{
//    lv_label_set_text(guider_ui.screen_1_label_8, data_for_display);
//}

void App_DisplayTask(void *param)
{
    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();

#if LV_USE_LOG
    lv_log_register_print_cb(print_cb);
#endif

    LV_LOG("lvgl guider demo started\r\n");

//    s_lvgl_initialized = true;

    setup_ui(&guider_ui);
    events_init(&guider_ui);
    custom_init(&guider_ui);


    //lv_label_set_text_fmt(label, str);


//    lv_timer_create(ui_fast_update_timer, 50, NULL);   // every 50 ms
//    lv_timer_create(ui_slow_update_timer, 500, NULL); // every 500 ms


    for (;;)
    {


        vTaskDelay(lv_timer_handler());


        //vTaskDelay(pdMS_TO_TICKS(10)); /* adjust as desired */

    }
}


