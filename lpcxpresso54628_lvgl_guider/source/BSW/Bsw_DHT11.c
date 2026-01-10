
#include "Bsw_DHT11.h"
#include "Bsw_Gpio.h"
#include"../lvgl_demo_utils.h"
#include"../drivers/fsl_gpio.h"
// include your existing DHT11 function
//extern int DHT11_ReadRaw(uint8 raw[5]);

// HELPER FUNCTION FOR  DELAY
void delay_us(uint32_t period)
{
	uint32_t counter = DEMO_GetUsTimer();
	while(DEMO_GetUsElapsed(counter) < period);
}

Std_ReturnType Bsw_DHT11_Init()
{
	uint8_t  check1  = 0;
	uint8_t  check2  = 0;
	uint8_t  check3  = 0;
	uint32_t time1   = 0;
	uint32_t time2   = 0;
	uint32_t time3   = 0;

	// 1. Configure PIN to be used to communication as OUTPUT.
	if(Bsw_Gpio_SetDirectionOutput(DHT_PORT, DHT_PIN) != E_OK)
	{
//	PRINTF("WAT DA FAK?");
		log_error(EM_MODULE_DHT11, EM_ERROR_DHT11_SET_DIRECTION_FAILED, "Bsw_DHT11_Init");
		return E_NOT_OK;
	}
	if(Bsw_Gpio_Write(DHT_PORT, DHT_PIN, HIGH) != E_OK)
	{
		log_error(EM_MODULE_DHT11, EM_ERROR_DHT11_SET_DIRECTION_FAILED, "Bsw_DHT11_Init");
		return E_NOT_OK;
	}


	// 2. SEQUENCE_0: Set the PIN O/P to LOW and wait for 18 milli-seconds.
	if(Bsw_Gpio_Write(DHT_PORT, DHT_PIN, LOW) != E_OK)
	{
		log_error(EM_MODULE_DHT11, EM_ERROR_DHT11_SET_DIRECTION_FAILED, "Bsw_DHT11_Init");
		return E_NOT_OK;
	}
	delay_us(SEQUENCE_0);

	// 3. Configure the PIN as INPUT. The pull-up resistor will Pull the bus to HIGH.
	Bsw_Gpio_SetDirectionInput(DHT_PORT, DHT_PIN);
	//delay_us(SEQUENCE_0);

    // 4. Wait until DHT11 responds and pulls the line to LOW after around 40 micro-seconds or else exit as timeout error.
    time1 = DEMO_GetUsTimer();
    while((DEMO_GetUsTimer() - time1) <= _40_us ){
    	if(GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN) == LOW) check1 = TRUE;
    }

    if(check1 != TRUE)
    {
    	log_error(EM_MODULE_DHT11, EM_ERROR_DHT11_CHECK1_FAILED, "Bsw_DHT11_Init");
    	// Print Error
    	return E_NOT_OK;
    }

    // 5. Next, check for 80us LOW followed by 80us HIGH from DHT11.
    // This condition denotes that DHT11 is ready to send data next.
    time2 = DEMO_GetUsTimer();
    while((DEMO_GetUsTimer() - time2) <= _80_us ){
    	if(GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN) == LOW) check2 = TRUE; // 80 us LOW
    }

    if(check2 != TRUE)
    {
    	log_error(EM_MODULE_DHT11, EM_ERROR_DHT11_CHECK2_FAILED, "Bsw_DHT11_Init");
    	// Print Error
    	return E_NOT_OK;
    }

    time3 = DEMO_GetUsTimer();
    //check3 = 0;
    while((DEMO_GetUsTimer() - time3) <= _80_us ){
    	if(GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN)) check3 = TRUE; // 80 us HIGH
    }

    if(check3 != TRUE)
    {
    	log_error(EM_MODULE_DHT11, EM_ERROR_DHT11_CHECK3_FAILED, "Bsw_DHT11_Init");
    	// Print Error
    	return E_NOT_OK;
    }

	return E_OK;

}

Std_ReturnType Bsw_DHT11_Read(DHT11_DataType_raw *data)
{


    for (int byte = 0; byte < 5; byte++)
    {
        for (int bit = 0; bit < BYTE_LENGTH; bit++)
        {
            int t0 = DEMO_GetUsTimer();
            while (GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN) == HIGH)
            {
                if (DEMO_GetUsElapsed(t0) > _100_us)
                {
                	// TIMEOUT
                	log_error(EM_MODULE_DHT11, EM_ERROR_DHT11_TIMEOUT_100us, "Bsw_DHT11_Read");
                	return E_NOT_OK;
                }

            }

            // Measure LOW length
            uint32_t low_start = DEMO_GetUsTimer();
            while (GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN) == LOW)
            {
                if (DEMO_GetUsElapsed(low_start) > _100_us)
                	{
                		// TIMEOUT
                		log_error(EM_MODULE_DHT11, EM_ERROR_DHT11_TIMEOUT_100us, "Bsw_DHT11_Read");
                		return E_NOT_OK;
                	}
            }

            /*
            * 2) MEASURE THE HIGH PULSE
            *    (length determines 0 or 1)
            */
           uint32_t high_start = DEMO_GetUsTimer();
           while (GPIO_PinRead(GPIO, DHT_PORT, DHT_PIN) == HIGH)
           {
               if (DEMO_GetUsElapsed(high_start) > _100_us)
               {
            	   // TIMEOUT
            	   log_error(EM_MODULE_DHT11, EM_ERROR_DHT11_TIMEOUT_100us, "Bsw_DHT11_Read");
            	   return E_NOT_OK;
               }
           }
           uint32_t high_len = DEMO_GetUsElapsed(high_start);


            // 3) STORE THE BIT

           data->data_raw[byte] <<= 1;

           if (high_len > 50)   // threshold between 0 and 1
        	   data->data_raw[byte] |= 1; // bit = 1

        }
    }

    return E_OK;
}
