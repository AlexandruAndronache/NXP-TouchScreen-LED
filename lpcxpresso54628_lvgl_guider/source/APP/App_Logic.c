#include "App_Logic.h"
#include "..\BSW\Bsw_DHT11.h"


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


///*******************************************************************************
// * Definitions
// ******************************************************************************/
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
//sctimer_config_t sctimerInfo;
//sctimer_pwm_signal_param_t pwmParam;
//sctimer_pwm_signal_param_t pwmParam1;
//uint32_t event;
//uint32_t sctimerClock;
DHT11_DataType_raw data_raw;
DHT11_DataType data_processed;
char data_for_display[32];
char buffer[32];
char str[8];
uint8_t temp;
uint8_t g_temp = 0;
uint8_t g_hum = 0;
//uint8_t g_pwm_duty_cycle = 0;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
//void print_cb(lv_log_level_t level, const char * buf);
//void ui_fast_update_timer(lv_timer_t *t);
//void ui_slow_update_timer(lv_timer_t *t);
void App_Logic_PrepareUiData();
//void App_Logic_MainLoop();

#if LV_USE_LOG
void print_cb(lv_log_level_t level, const char * buf)
{
    LV_UNUSED(level);

    PRINTF("\r%s\n", buf);
}
#endif

void App_Logic_MainLoop()
{
/* Future state machines or application logic */

	//App_Logic_UpdateSensorValues();
	App_Logic_SetMotorPwm();
	//App_Logic_PrepareUiData();
//	LCD_Init();
//	LCD_Display();
}


void App_Logic_PrepareUiData()
{
    /* PWM */
    snprintf(buffer, sizeof(buffer), "PWM: %d %%", pwm_value);


    /* Temperature + Humidity */
	snprintf(data_for_display, sizeof(data_for_display),
							 "T:%d H:%d", g_temp, g_hum);
	PRINTF("T:%d H:%d", g_temp, g_hum);
}

/* Acquire sensor values via RTE */
void App_Logic_UpdateSensorValues(void)
{
    uint8_t t = 0;
    uint8_t h = 0;
    Std_ReturnType status;

    /* Initialize DHT11 sensor */
    status = Bsw_DHT11_Init();
    if (status != E_OK)
    {
        PRINTF("DHT11 initialization failed!\r\n");
        return;
    }

    /* Read data from DHT11 */
    status = Rte_Read_DHT11(&t, &h);
    if (status != E_OK)
    {
        PRINTF("DHT11 read failed!\r\n");
        return;
    }

    /* Update global values */
    g_temp = t;
    g_hum  = h;

}


//Std_ReturnType App_Logic_GetTemperature(void)
//{
//	if (Bsw_DHT11_Init() != E_OK)
//	{
//		return E_NOT_OK;
//	}
//	else
//	{
//		if(Bsw_DHT11_Read(&data_raw) != E_OK)
//		{
//			return E_NOT_OK;
//		}
//		else
//		{
//			data_processed.temperature = data_raw.data_raw[2];
//			return E_OK;
//		}
//	}
//
//	return E_NOT_OK;
//
//}
//
//
//Std_ReturnType App_Logic_GetHumidity(void)
//{
//	if (Bsw_DHT11_Init() != E_OK)
//	{
//		return E_NOT_OK;
//	}
//	else
//	{
//		if(Bsw_DHT11_Read(&data_raw) != E_OK)
//		{
//			return E_NOT_OK;
//		}
//		else
//		{
//			data_processed.humidity = data_raw.data_raw[0];
//			return E_OK;
//		}
//	}
//
//	return E_NOT_OK;
//}

uint8_t App_Logic_GetPwmValue()
{
	return pwm_value;
}


/* Example PWM logic */
void App_Logic_SetMotorPwm(void)
{
	uint8_t pwm_internal = App_Logic_GetPwmValue();
	Rte_Write_PwmDuty(pwm_internal);
}

void ui_fast_update_timer(lv_timer_t *t)
{
    lv_label_set_text(guider_ui.screen_1_label_10, buffer); // fast PWM update
}

void ui_slow_update_timer(lv_timer_t *t)
{
    lv_label_set_text(guider_ui.screen_1_label_8, data_for_display);
}

void LCD_Init(void)
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
	lv_timer_create(ui_fast_update_timer, 50, NULL);   // every 50 ms
	lv_timer_create(ui_slow_update_timer, 50, NULL); // every 500 ms

}

void LCD_Display(void)
{
	vTaskDelay(lv_timer_handler());
}

void vApplicationTickHook(void)
{
    if (s_lvgl_initialized)
    {
        lv_tick_inc(1);
    }
}
