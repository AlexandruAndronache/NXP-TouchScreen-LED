/*
 * Copyright 2020, 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

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

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
static volatile bool s_lvgl_initialized = false;
lv_ui guider_ui;
volatile int pwm_value = 50;
BaseType_t stat;
BaseType_t stat_pwm;
sctimer_config_t sctimerInfo;
sctimer_pwm_signal_param_t pwmParam;
sctimer_pwm_signal_param_t pwmParam1;
uint32_t event;
uint32_t sctimerClock;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void print_cb(lv_log_level_t level, const char * buf);

#if LV_USE_LOG
void print_cb(lv_log_level_t level, const char * buf)
{
    LV_UNUSED(level);

    PRINTF("\r%s\n", buf);
}
#endif

static void AppTask(void *param)
{
    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();

#if LV_USE_LOG
    lv_log_register_print_cb(print_cb);
#endif

    LV_LOG("lvgl guider demo started\r\n");

    s_lvgl_initialized = true;

    setup_ui(&guider_ui);
    events_init(&guider_ui);
    custom_init(&guider_ui);

    for (;;)
    {
        vTaskDelay(lv_timer_handler());
    }
}

static void PwmTask(void *param)
{

	PRINTF("PwmTask on");

    for (;;)
    {
    	SCTIMER_UpdatePwmDutycycle(SCT0, kSCTIMER_Out_3, (uint8_t)pwm_value, event);
    	SCTIMER_UpdatePwmDutycycle(SCT0, kSCTIMER_Out_4, (uint8_t)pwm_value, event);
        vTaskDelay(50);
    }
}



/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Main function
 */
int main(void)
{


    /* Init board hardware. */
    BOARD_InitHardware();
    DEMO_InitUsTimer();

    sctimerClock = CLOCK_GetFreq(kCLOCK_BusClk);

    // Default values for PWM
    SCTIMER_GetDefaultConfig(&sctimerInfo);

    /* Initialize SCTimer module */
    SCTIMER_Init(SCT0, &sctimerInfo);

    /* Configure first PWM with frequency 24kHZ from first output */
    // P3_10 - J13 - 7
    pwmParam.output           = kSCTIMER_Out_3;
    pwmParam.level            = kSCTIMER_HighTrue;
    pwmParam.dutyCyclePercent = 50;
    uint32_t PWM_signal_frequency_Hz = 5000U;

    // P3_14 - J13 - 7
    pwmParam1.output           = kSCTIMER_Out_4;
    pwmParam1.level            = kSCTIMER_HighTrue;
    pwmParam1.dutyCyclePercent = 50;

    // Setup PWM and guard for fail
    if (SCTIMER_SetupPwm(SCT0, &pwmParam, kSCTIMER_EdgeAlignedPwm, PWM_signal_frequency_Hz, sctimerClock, &event) == kStatus_Fail)
    {
    	PRINTF("\r\nSCTIMER_SetupPwm FAIL");
        return -1;
    }

    // Setup PWM and guard for fail
    if (SCTIMER_SetupPwm(SCT0, &pwmParam1, kSCTIMER_EdgeAlignedPwm, PWM_signal_frequency_Hz, sctimerClock, &event) == kStatus_Fail)
    {
    	PRINTF("\r\nSCTIMER_SetupPwm FAIL");
        return -1;
    }



    stat = xTaskCreate(AppTask, "lvgl", 1024, NULL, tskIDLE_PRIORITY + 2, NULL);

    if (pdPASS != stat)
    {
        PRINTF("Failed to create lvgl task");
        while (1)
            ;
    }

    /* Task 2: PWM updater */
    stat_pwm = xTaskCreate(PwmTask,
                           "pwm",
                           512,              // stack words; adjust if needed
                           NULL,
                           tskIDLE_PRIORITY + 1,
                           NULL);

    if (pdPASS != stat_pwm)
    {
        PRINTF("Failed to create pwm task");
        while (1)
            ;
    }

    vTaskStartScheduler();

    for (;;)
    {
    } /* should never get here */
}

/*!
 * @brief Malloc failed hook.
 */
void vApplicationMallocFailedHook(void)
{
    PRINTF("Malloc failed. Increase the heap size.");

    for (;;)
        ;
}

/*!
 * @brief FreeRTOS tick hook.
 */
void vApplicationTickHook(void)
{
    if (s_lvgl_initialized)
    {
        lv_tick_inc(1);
    }
}

/*!
 * @brief Stack overflow hook.
 */
void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
    (void)pcTaskName;
    (void)xTask;

    for (;;)
        ;
}


