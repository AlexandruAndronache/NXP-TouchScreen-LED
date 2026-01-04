///*
// * main.c
// *
// *  Created on: 2 dec. 2025
// *      Author: alexa
// */
//
//
//#include "FreeRTOS.h"
//#include "task.h"
//
//#include "fsl_debug_console.h"
//#include "fsl_sctimer.h"
//#include "lvgl_support.h"
//#include "board.h"
//#include "app.h"
//#include "lvgl.h"
//#include "gui_guider.h"
//#include "events_init.h"
//#include "custom.h"
//#include "lvgl_demo_utils.h"
//#include "stdio.h"
//#include "string.h"
//
///*******************************************************************************
// * Definitions
// ******************************************************************************/
//#define DHT_PORT 3
//#define DHT_PIN 14
//#define DHT_TIMEOUT_US_RESP   100u   // timeout waiting for response edges
//#define DHT_TIMEOUT_US_BIT    120u   // timeout per bit edge
//#define DHT_START_LOW_US      18000u // 18 ms
//#define DHT_PULLUP_WAIT_US    40u    // 20-40 us
///*******************************************************************************
// * Variables
// ******************************************************************************/
//static volatile bool s_lvgl_initialized = false;
//lv_ui guider_ui;
//volatile int pwm_value = 50;
//
///*******************************************************************************
// * Prototypes
// ******************************************************************************/
//void print_cb(lv_log_level_t level, const char * buf);
//void ui_fast_update_timer(lv_timer_t *t);
//void ui_slow_update_timer(lv_timer_t *t);
//
//#if LV_USE_LOG
//void print_cb(lv_log_level_t level, const char * buf)
//{
//    LV_UNUSED(level);
//
//    PRINTF("\r%s\n", buf);
//}
//#endif
//
//static void AppTask(void *param)
//{
//    lv_init();
//    lv_port_disp_init();
//    lv_port_indev_init();
//
//#if LV_USE_LOG
//    lv_log_register_print_cb(print_cb);
//#endif
//
//    LV_LOG("lvgl guider demo started\r\n");
//
//    s_lvgl_initialized = true;
//
//    setup_ui(&guider_ui);
//    events_init(&guider_ui);
//    custom_init(&guider_ui);
//
//
//    //lv_label_set_text_fmt(label, str);
//
//
//    lv_timer_create(ui_fast_update_timer, 50, NULL);   // every 50 ms
//    lv_timer_create(ui_slow_update_timer, 500, NULL); // every 500 ms
//
//
//    for (;;)
//    {
//
//
//        vTaskDelay(lv_timer_handler());
//
//
//        //vTaskDelay(pdMS_TO_TICKS(10)); /* adjust as desired */
//
//    }
//}
//
//void ui_fast_update_timer(lv_timer_t *t)
//{
//   // lv_label_set_text(guider_ui.screen_1_label_10, buffer); // fast PWM update
//}
//
//void ui_slow_update_timer(lv_timer_t *t)
//{
//   // lv_label_set_text(guider_ui.screen_1_label_8, data_for_display);
//}
//
//int main(void)
//{
//    /* Init board hardware. */
//    BOARD_InitHardware();
//    DEMO_InitUsTimer();
//
//
//    vTaskStartScheduler();
//
//    for (;;)
//    {
//    } /* should never get here */
//
//}
//
//void vApplicationMallocFailedHook(void)
//{
//    PRINTF("Malloc failed. Increase the heap size.");
//
//    for (;;)
//        ;
//}
//
///*!
// * @brief FreeRTOS tick hook.
// */
//void vApplicationTickHook(void)
//{
//    if (s_lvgl_initialized)
//    {
//        lv_tick_inc(1);
//    }
//}
//
///*!
// * @brief Stack overflow hook.
// */
//void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
//{
//    (void)pcTaskName;
//    (void)xTask;
//
//    for (;;)
//        ;
//}
