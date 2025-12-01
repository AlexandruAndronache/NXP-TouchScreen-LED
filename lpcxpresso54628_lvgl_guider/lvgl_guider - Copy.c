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
#include "stdio.h"
#include "string.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DHT_PORT 3
#define DHT_PIN 14
#define DHT_TIMEOUT_US_RESP   100u   // timeout waiting for response edges
#define DHT_TIMEOUT_US_BIT    120u   // timeout per bit edge
#define DHT_START_LOW_US      18000u // 18 ms
#define DHT_PULLUP_WAIT_US    40u    // 20-40 us
/*******************************************************************************
 * Variables
 ******************************************************************************/
static volatile bool s_lvgl_initialized = false;
lv_ui guider_ui;
volatile int pwm_value = 50;
BaseType_t stat;
BaseType_t stat_pwm;
BaseType_t stat_dht11;
BaseType_t stat_update_values;
sctimer_config_t sctimerInfo;
sctimer_pwm_signal_param_t pwmParam;
sctimer_pwm_signal_param_t pwmParam1;
uint32_t event;
uint32_t sctimerClock;
uint8_t data[5];
char data_for_display[32];
char buffer[32];
char str[8];
uint8_t temp;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void print_cb(lv_log_level_t level, const char * buf);
void ui_fast_update_timer(lv_timer_t *t);
void ui_slow_update_timer(lv_timer_t *t);

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


    //lv_label_set_text_fmt(label, str);


    lv_timer_create(ui_fast_update_timer, 50, NULL);   // every 50 ms
    lv_timer_create(ui_slow_update_timer, 500, NULL); // every 500 ms


    for (;;)
    {


        vTaskDelay(lv_timer_handler());


        //vTaskDelay(pdMS_TO_TICKS(10)); /* adjust as desired */

    }
}

void ui_fast_update_timer(lv_timer_t *t)
{
    lv_label_set_text(guider_ui.screen_1_label_10, buffer); // fast PWM update
}

void ui_slow_update_timer(lv_timer_t *t)
{
    lv_label_set_text(guider_ui.screen_1_label_8, data_for_display);
}



static void PwmTask(void *param)
{

	PRINTF("PwmTask on");

    for (;;)
    {
    	SCTIMER_UpdatePwmDutycycle(SCT0, kSCTIMER_Out_3, (uint8_t)pwm_value, event);
        snprintf(buffer, sizeof(buffer),"PWM:%d", pwm_value);
        vTaskDelay(50);
    }
}


static void DHT11Task(void *param)
{
	uint8_t check1 = 0;
	uint8_t check2 = 0;
	uint8_t check3 = 0;
	uint32_t counter = 0;
	uint32_t time1  = 0;
	uint32_t time2 = 0;
	uint32_t time3 = 0;
	for(;;)
	{


		 check1 = 0;
		 check2 = 0;
		 check3 = 0;
		 time1  = 0;
		 time2 = 0;
		 time3 = 0;
		 //memset(data, 0, sizeof(data));

		 //taskENTER_CRITICAL();
		// 1. Configure PIN to be used to communication as OUTPUT.
        gpio_pin_config_t out_cfg = { kGPIO_DigitalOutput, 1 };
        GPIO_PinInit(GPIO, DHT_PORT, DHT_PIN, &out_cfg);
        GPIO_PinWrite(GPIO, DHT_PORT, DHT_PIN, 1); // HIgh default

        // 2. Set the PIN O/P to LOW and wait for 18 milli-seconds.
        GPIO_PinWrite(GPIO, DHT_PORT, DHT_PIN, 0); // 20 ms LOW
        counter = DEMO_GetUsTimer();
        while(DEMO_GetUsElapsed(counter) < 18000);

        // 3. Configure the PIN as INPUT. The pull-up resistor will Pull the bus to HIGH.
        gpio_pin_config_t in_cfg = { kGPIO_DigitalInput, 0 };
        GPIO_PinInit(GPIO, DHT_PORT, DHT_PIN, &in_cfg);

        // 4. Wait until DHT11 responds and pulls the line to LOW after around 40 micro-seconds or else exit as timeout error.
        time1 = DEMO_GetUsTimer();
        while(DEMO_GetUsTimer() - time1 < 40 ){
        	if(GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN) == 0) check1 = 1;
        }

        // 5. Next, check for 80us LOW followed by 80us HIGH from DHT11.
        // This condition denotes that DHT11 is ready to send data next.
        time2 = DEMO_GetUsTimer();
        //check2 = 0;
        while(DEMO_GetUsTimer() - time2 < 80 ){
        	if(GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN) == 0) check2 = 1; // 80 us LOW
        }

        time3 = DEMO_GetUsTimer();
        //check3 = 0;
        while(DEMO_GetUsTimer() - time3 < 80 ){
        	if(GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN)) check3 = 1; // 80 us HIGH
        }

        // 6. Now, check for 50us LOW followed by 26us to 28us HIGH denoting data bit ‘0’ or 50us LOW followed 70us HIGH
        // denoting data bit ‘1’.
        //Store the interpreted bit in an array. Repeat this for each of 40 bits.
        // Read 40 bits
        if(check1 && check2 &&check3)
        for (int byte = 0; byte < 5; byte++)
        {
            for (int bit = 0; bit < 8; bit++)
            {
                int t0 = DEMO_GetUsTimer();
                while (GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN) == 1)
                {
                    if (DEMO_GetUsElapsed(t0) > 100)
                    {
                    	PRINTF("TIMEOUT");
                    	goto next_iteration;
                    }
                    	//taskYIELD();
                }

                // Measure LOW length
                uint32_t low_start = DEMO_GetUsTimer();
                while (GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN) == 0)
                {
                    if (DEMO_GetUsElapsed(low_start) > 100)
                    	{
                    	PRINTF("TIMEOUT0");
                    	goto next_iteration;
                    	}
                }

                /*
                * 2) MEASURE THE HIGH PULSE
                *    (length determines 0 or 1)
                */
               uint32_t high_start = DEMO_GetUsTimer();
               while (GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN) == 1)
               {
                   if (DEMO_GetUsElapsed(high_start) > 100)
                   {
                	   PRINTF("TIMEOUT1");
                	   goto next_iteration;
                   }
               }
               uint32_t high_len = DEMO_GetUsElapsed(high_start);


                // 3) STORE THE BIT

               data[byte] <<= 1;

               if (high_len > 50)   // threshold between 0 and 1
                   data[byte] |= 1; // bit = 1

            }
        }


        // DEBUG
        PRINTF("Humidity: %d %% Temp: %d C\n", data[0], data[2]);

        // WRITE DATA INTO STRING FOR DISPLAY
        snprintf(data_for_display, sizeof(data_for_display),
                                 "T:%d H:%d", data[2], data[0]);

        //snprintf(str, sizeof(str), "%d", data[2]);
        //lv_label_set_text(guider_ui.screen_1_label_8, str);
        //lv_ui *ui;
       // lv_label_set_text(ui->screen_1_label_8, str);
		 check1 = 0;
		 check2 = 0;
		 check3 = 0;
		 time1  = 0;
		 time2 = 0;
		 time3 = 0;


		 // IF ANYTHING GOES WRONG WITH SENSOR DATA EXCHANGE WAIT 1 SECOND AND START OVER
		 next_iteration:
		 vTaskDelay(pdMS_TO_TICKS(1000));

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

    /* Configure first PWM with frequency 20kHZ from first output */
    // P3_14 - J13 - 7
    pwmParam.output           = kSCTIMER_Out_3;
    pwmParam.level            = kSCTIMER_HighTrue;
    pwmParam.dutyCyclePercent = 50;
    uint32_t PWM_signal_frequency_Hz = 20000U;

    // P3_10 - J13 - 5
    pwmParam1.output           = kSCTIMER_Out_4;
    pwmParam1.level            = kSCTIMER_HighTrue;
    pwmParam1.dutyCyclePercent = 50;

    // Setup PWM and guard for fail
    if (SCTIMER_SetupPwm(SCT0, &pwmParam, kSCTIMER_EdgeAlignedPwm, PWM_signal_frequency_Hz, sctimerClock, &event) == kStatus_Fail)
    {
    	PRINTF("\r\nSCTIMER_SetupPwm FAIL");
        return -1;
    }




    stat = xTaskCreate(AppTask, "lvgl", 1024, NULL, tskIDLE_PRIORITY + 8, NULL);

    if (pdPASS != stat)
    {
        PRINTF("Failed to create lvgl task");
        while (1)
            ;
    }

    /* Task 14: PWM updater */
    stat_pwm = xTaskCreate(PwmTask,
                           "pwm",
                           512,              // stack words; adjust if needed
                           NULL,
                           tskIDLE_PRIORITY + 9,
                           NULL);

    if (pdPASS != stat_pwm)
    {
        PRINTF("Failed to create pwm task");
        while (1)
            ;
    }

    stat_dht11 = xTaskCreate(DHT11Task, "pwm", 512, NULL,tskIDLE_PRIORITY + 10,NULL );
    if (pdPASS != stat_dht11)
    {
        PRINTF("Failed to create stat_dht11 task");
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


