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
<<<<<<< Updated upstream

=======
#define DHT_PORT 3
#define DHT_PIN 14
#define DHT_TIMEOUT_US_RESP   100u   // timeout waiting for response edges
#define DHT_TIMEOUT_US_BIT    120u   // timeout per bit edge
#define DHT_START_LOW_US      18000u // 18 ms
#define DHT_PULLUP_WAIT_US    40u    // 20-40 us
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream


=======
//uint8_t DHT11_ReadByte(void)
//{
//    uint8_t value = 0;
//    for (int bit = 0; bit < 8; bit++)
//    {
//        /* Wait for pin to go HIGH (start of bit) */
//        while (!GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN)) ;
//
//        /* Wait 30 us --> determines whether bit is 0 or 1 */
//        SDK_DelayAtLeastUs(50, freq);
//
//        if (GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN))
//            value |= (1 << (7 - bit));   // write 1
//        else
//            value &= ~(1 << (7 - bit));  // write 0
//
//        /* Wait until pin goes LOW (end of bit) */
//       // while (GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN))         ;
//    }
//
//    return value;
//}


//
//static void DHT11Task11111(void *param)
//{
//    PRINTF("DHT11 Task Started\n");
//
//    uint8_t data[5] = {0};
//    uint32_t freq = CLOCK_GetFreq(kCLOCK_CoreSysClk);
//    uint8_t check1 = 0;
//    uint8_t check2 = 0;
//    int check3 = 0;
//    for(;;)
//    {
//    	check1 = 0;
//    	check2 = 0;
//    	check3 = 0;
//        memset(data, 0, sizeof(data));
//        uint32_t counter = 0;
//
//        /* ============================================================
//         *  DHT11 START SIGNAL (Correct Sequence)
//         * ============================================================*/
//
//        // 1. MCU drives LOW for 18 ms
//        gpio_pin_config_t out_cfg = { kGPIO_DigitalOutput, 1 };
//        GPIO_PinInit(GPIO, DHT_PORT, DHT_PIN, &out_cfg);
//        GPIO_PinWrite(GPIO, DHT_PORT, DHT_PIN, 1); // HIgh default
//        vTaskDelay(pdMS_TO_TICKS(2000));
//        GPIO_PinWrite(GPIO, DHT_PORT, DHT_PIN, 0); // 20 ms LOW
//        counter = DEMO_GetUsTimer();
//        while(DEMO_GetUsElapsed(counter) < 18000);
//        gpio_pin_config_t in_cfg = { kGPIO_DigitalInput, 0 };
//        GPIO_PinInit(GPIO, DHT_PORT, DHT_PIN, &in_cfg);
//
//        // IMPORTANT: WAIT 20–40 µs to let pull-up bring line HIGH
//        counter = DEMO_GetUsTimer();
//        while((DEMO_GetUsElapsed(counter) < 80))
//        {
//        	if(!GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN))
//        	{
//        		check1 = 1;
//        	}
//        }
//
//        counter = DEMO_GetUsTimer();
//        while((DEMO_GetUsElapsed(counter) < 80))
//        {
//        	if(GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN))
//        	{
//        		check2 = 1;
//        	}
//        }
//
//
//
//
//        int high_from_pullup = DEMO_GetUsElapsed(counter);
//         //pin = GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN);
//       // PRINTF("LINE: %d high_from_pullup time: %d", pin, high_from_pullup);
//
//        /* ============================================================
//         *  CHECK DHT11 RESPONSE
//         * ============================================================*/
//
//        // DHT11 should pull LOW for 80 µs
////        counter = DEMO_GetUsTimer();
////        while(GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN) == 0);
////         pin = GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN);
////        int res1 = DEMO_GetUsElapsed(counter);
////
////        counter = DEMO_GetUsTimer();
////        while(GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN) == 1);
////         int pin2 = GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN);
////        int res2 = DEMO_GetUsElapsed(counter);
//
//        if(check1 && check2)
//        {
//        	check1 = 0;
//        	check2 = 0;
//        	for (int i = 0; i < 5; ++i)
//        		for(int j = 0; j < 8; ++j)
//        		{
//
//						counter = DEMO_GetUsTimer();
//						//
//
//						while (GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN) == 0);
//						int time = DEMO_GetUsElapsed(counter);
//						if(GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN) == 1) check3 = 1;
//						if(check3)
//						{
//							counter = DEMO_GetUsTimer();
////							if(GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN))
////							{
////								if(DEMO_GetUsElapsed(counter) > 80) return;
////							}
//
//								while(DEMO_GetUsElapsed(counter) < 28);
//								if(GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN))
//								{
//									data[i] = data[i] << 1;// threshold
//									data[i] += 1;
//								}
//								else
//								{
//									data[i] = data[i] << 1;// threshold
//
//								}
//							}
////							if (GPIO_PinRead(GPIO,DHT_PORT, DHT_PIN) )
////							{
////
////
////							}
////							else
////							{
////								data[i] = data[i] << 1;
////							}
//							check3 = 0;
//						}
//
//
//					}
//
//        PRINTF("Humidity: %d %% Temp: %d C\n", data[0], data[2]);
//        memset(data, 0, sizeof(data));
//
//        		}
//
//
//        /* ============================================================
//         *  PRINT RESULT
//         * ============================================================*/
//
//        uint8_t checksum = data[0] + data[1] + data[2] + data[3];
//
//       // if (checksum == data[4])
//
//
//
////
////NEXT_LOOP:
////        SDK_DelayAtLeastUs(2000000, freq);   // 2 seconds
//
//}

//static void DHT11Task_chat(void *param)
//{
//    PRINTF("DHT11 Task Started\n");
//
//    uint8_t data[5];
//    for (;;)
//    {
//        memset(data, 0, sizeof(data));
//        uint32_t start, elapsed;
//
//        /* ===== Ensure IOCON / hardware pull-up is set BEFORE running this task =====
//         * Either:
//         *  - Add an external 10k pull-up from DATA -> 3.3V, OR
//         *  - Configure IOCON PIOx_y with IOCON_PIO_MODE(0x2) (pull-up)
//         *
//         * If the line stays low after release, the sensor will never respond.
//         */
//
//        /* ---------- 1) Send start signal: MCU drives LOW for 18 ms ---------- */
//        gpio_pin_config_t out_cfg = { kGPIO_DigitalOutput, 1 };
//        GPIO_PinInit(GPIO, DHT_PORT, DHT_PIN, &out_cfg);
//
//        GPIO_PinWrite(GPIO, DHT_PORT, DHT_PIN, 0);           // pull LOW
//        start = DEMO_GetUsTimer();
//        while (DEMO_GetUsElapsed(start) < DHT_START_LOW_US)
//        {
//            ; // busy-wait for 18ms (short, allowed)
//        }
//
//        /* release line: drive HIGH then switch to input */
//        GPIO_PinWrite(GPIO, DHT_PORT, DHT_PIN, 1);
//
//        gpio_pin_config_t in_cfg = {  kGPIO_DigitalInput,  0 };
//        GPIO_PinInit(GPIO, DHT_PORT, DHT_PIN, &in_cfg);
//
//        /* let pull-up bring the line HIGH (20-40us) */
//        start = DEMO_GetUsTimer();
//        while (DEMO_GetUsElapsed(start) < DHT_PULLUP_WAIT_US)
//        {
//            ; // small wait
//        }
//
//        /* ---------- 2) Wait for DHT11 response: sensor pulls LOW (~80us) then HIGH (~80us) ---------- */
//
//        /* wait for sensor to pull LOW (should happen quickly) */
//        start = DEMO_GetUsTimer();
//        while (GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN) == 1)
//        {
//            if (DEMO_GetUsElapsed(start) > DHT_TIMEOUT_US_RESP)
//            {
//                PRINTF("DHT11: no response (never went LOW)\n");
//                goto NEXT_LOOP;
//            }
//        }
//
//        /* measure LOW duration (should be ~80us) */
//        start = DEMO_GetUsTimer();
//        while (GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN) == 0)
//        {
//            if (DEMO_GetUsElapsed(start) > DHT_TIMEOUT_US_RESP)
//            {
//                PRINTF("DHT11: response LOW too long\n");
//                goto NEXT_LOOP;
//            }
//        }
//        uint32_t low_resp = DEMO_GetUsElapsed(start);
//
//        /* measure following HIGH (~80us) */
//        start = DEMO_GetUsTimer();
//        while (GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN) == 1)
//        {
//            if (DEMO_GetUsElapsed(start) > DHT_TIMEOUT_US_RESP)
//            {
//                PRINTF("DHT11: response HIGH too long\n");
//                goto NEXT_LOOP;
//            }
//        }
//        uint32_t high_resp = DEMO_GetUsElapsed(start);
//
//        PRINTF("DHT11 response: LOW=%u us, HIGH=%u us\n", low_resp, high_resp);
//
//        /* Accept roughly expected response windows (loose bounds) */
//        if (!(low_resp >= 50 && low_resp <= 120 && high_resp >= 50 && high_resp <= 120))
//        {
//            PRINTF("DHT11: unexpected response timings\n");
//            goto NEXT_LOOP;
//        }
//
//        /* ---------- 3) Read 40 bits (5 bytes) ---------- */
//        for (int byte = 0; byte < 5; ++byte)
//        {
//            for (int bit = 0; bit < 8; ++bit)
//            {
//                /* wait for start of bit (line goes LOW) */
//                start = DEMO_GetUsTimer();
//                while (GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN) == 1)
//                {
//                    if (DEMO_GetUsElapsed(start) > DHT_TIMEOUT_US_BIT)
//                    {
//                        PRINTF("DHT11: timeout waiting for bit start (HIGH->LOW)\n");
//                        goto NEXT_LOOP;
//                    }
//                }
//
//                /* wait for LOW to finish (start measuring HIGH) */
//                start = DEMO_GetUsTimer();
//                while (GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN) == 0)
//                {
//                    if (DEMO_GetUsElapsed(start) > DHT_TIMEOUT_US_BIT)
//                    {
//                        PRINTF("DHT11: timeout while LOW during bit\n");
//                        goto NEXT_LOOP;
//                    }
//                }
//
//                /* now line is HIGH: measure HIGH pulse length */
//                uint32_t tstart = DEMO_GetUsTimer();
//                while (GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN) == 1)
//                {
//                    if (DEMO_GetUsElapsed(tstart) > DHT_TIMEOUT_US_BIT)
//                    {
//                        PRINTF("DHT11: timeout while HIGH during bit\n");
//                        goto NEXT_LOOP;
//                    }
//                }
//                uint32_t high_len = DEMO_GetUsElapsed(tstart);
//
//                /* shift and set bit if pulse indicates '1' (> ~50us) */
//                data[byte] <<= 1;
//                if (high_len > 50) /* threshold ~ 50 us (26us = 0, 70us = 1) */
//                {
//                    data[byte] |= 1;
//                }
//            }
//        }
//
//        /* ---------- 4) Validate checksum and print ---------- */
//        {
//            uint8_t checksum = data[0] + data[1] + data[2] + data[3];
//            if (checksum == data[4])
//            {
//                PRINTF("Humidity: %d.%d %%  Temp: %d.%d C\n",
//                       data[0], data[1] ? (data[1]*10/100) : 0,   // DHT11 integer / no decimal but format kept flexible
//                       data[2], data[3] ? (data[3]*10/100) : 0);
//            }
//            else
//            {
//                PRINTF("DHT11: checksum error (%02X != %02X)\n", checksum, data[4]);
//            }
//        }
//
//    NEXT_LOOP:
//        /* clear buffer before next try */
//        memset(data, 0, sizeof(data));
//
//        /* Wait 2 seconds between reads */
//
//    } /* for(;;) */
//}
//

static void DHT11Task(void *param)
{
	uint8_t check1 = 0;
	uint8_t check2 = 0;
	uint8_t check3 = 0;
	uint32_t counter = 0;
	uint8_t data[5] = {0};
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
		 memset(data, 0, sizeof(data));

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
                    	taskYIELD();
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
        PRINTF("Humidity: %d %% Temp: %d C\n", data[0], data[2]);
		 check1 = 0;
		 check2 = 0;
		 check3 = 0;
		 time1  = 0;
		 time2 = 0;
		 time3 = 0;

		 next_iteration:
		 vTaskDelay(pdMS_TO_TICKS(1000));

	}





}
>>>>>>> Stashed changes
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



    stat = xTaskCreate(AppTask, "lvgl", 1024, NULL, tskIDLE_PRIORITY + 14, NULL);

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


