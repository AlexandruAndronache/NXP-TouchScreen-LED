#include "App_Init.h"
#include "App_Tasks.h"
#include "../RTE/Rte.h"
#include "FreeRTOS.h"
#include "task.h"

#include "fsl_debug_console.h"
#include "fsl_sctimer.h"
#include "lvgl_support.h"
#include "board.h"
#include "app.h"
#include "lvgl.h"
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"
#include "lvgl_demo_utils.h"
#include "stdio.h"
#include "string.h"

//BaseType_t stat;
//BaseType_t stat_pwm;
//BaseType_t stat_dht11;
//BaseType_t stat_update_values;

void App_Init(void)
{
	Rte_Init();
	/* Create Application Tasks */
	//xTaskCreate(App_MainTask, "APP", 512, NULL, 2, NULL);
	//xTaskCreate(App_DisplayTask,"DISP", 512, NULL, tskIDLE_PRIORITY + 8, NULL);
	//xTaskCreate(App_DhtTask, "DHT", 1024, NULL, tskIDLE_PRIORITY + 10, NULL);
	//xTaskCreate(App_PwmTask, "PWM", 1024, NULL, tskIDLE_PRIORITY + 9, NULL);

//    stat = xTaskCreate(App_DisplayTask, "lvgl", 1024, NULL, tskIDLE_PRIORITY + 8, NULL);
//
//    if (pdPASS != stat)
//    {
//        PRINTF("Failed to create lvgl task");
//        while (1)
//            ;
//    }


}
