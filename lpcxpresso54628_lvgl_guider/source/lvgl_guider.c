#include "FreeRTOS.h"
#include "task.h"
#include "stddef.h"
#include "RTE/Rte.h"

//#include "board.h"
#include "app.h"
#include "clock_config.h"
//#include "pin_mux.h"

#include "APP/App_Tasks.h"
#include "lvgl_demo_utils.h"

void Init_Everything();

///*******************************************************************************
// * Main
// ******************************************************************************/
int main(void)
{

	Init_Everything();

    /* Create LVGL task (UI owner) */
    xTaskCreate(
    		LCD_Task,
        "LCD_Task",
        1024,
        NULL,
        tskIDLE_PRIORITY + 1,
        NULL
    );

    xTaskCreate(
    		AppTask,
        "AppTask",
		512,
        NULL,
        tskIDLE_PRIORITY + 2,
        NULL
    );

    xTaskCreate(
    	Logic_Task,
        "Logic_Task",
		512,                 // LVGL needs stack
        NULL,
        tskIDLE_PRIORITY + 3, // Higher than logic
        NULL
    );

    /* Start FreeRTOS scheduler */
    vTaskStartScheduler();

    /* Should never reach here */
    for (;;)
    {
    }
}

void Init_Everything()
{
    /* Basic MCU / board init */
	BOARD_InitHardware();
	DEMO_InitUsTimer();
	Rte_Init();
}
