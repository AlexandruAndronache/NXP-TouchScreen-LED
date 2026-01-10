
#include "../BSW/Bsw_DHT11.h"
#include "../BSW/Bsw_Gpio.h"
#include "../BSW/Bsw_Pwm.h"
//#include "Bsw_Display.h"
#include <stddef.h>


/* If some BSW modules need initialization, do it here. */
Std_ReturnType Rte_Init(void)
{
    Std_ReturnType rv = E_OK;

    /* Initialize PWM channel 0 (adjust channel if needed) */
    if (Bsw_Pwm_Init(CHANNEL_0) != E_OK)
    {
    	// EM_ERROR_PWM_SETUP_FAILED
    	log_error(EM_MODULE_PWM, EM_ERROR_PWM_SETUP_FAILED, "Rte_Init");
        rv = E_NOT_OK;
    }


    return rv;
}

Std_ReturnType Rte_Read_DHT11(uint8 *temperature, uint8 *humidity)
{
    if ((temperature == NULL) || (humidity == NULL))
    {
    	// EM_ERROR_DHT11_READ_ERROR
    	log_error(EM_MODULE_DHT11, EM_ERROR_DHT11_READ, "Rte_Read_DHT11");
    	return E_NOT_OK;
    }


    DHT11_DataType_raw d;
    if (Bsw_DHT11_Read(&d) == E_OK)
    {
        *temperature = d.data_raw[2];
        *humidity = d.data_raw[0];
        return E_OK;
    }
    else
    {
    	// EM_ERROR_DHT11_READ_TEMP
    	log_error(EM_MODULE_DHT11, EM_ERROR_DHT11_READ, "Rte_Read_DHT11");
    	return E_NOT_OK;
    }

}

Std_ReturnType Rte_Read_Temperature(uint8 *temperature)
{
    DHT11_DataType_raw d;
    if (Bsw_DHT11_Read(&d) == E_OK)
    {
        *temperature = d.data_raw[2];
        return E_OK;
    }
    else
    {
    	// EM_ERROR_DHT11_READ_TEMP
    	log_error(EM_MODULE_DHT11, EM_ERROR_DHT11_READ_TEMP, "Rte_Read_Temperature");
    	return E_NOT_OK;
    }
}

Std_ReturnType Rte_Read_Humidity(uint8 *humidity)
{
    DHT11_DataType_raw d;
    if (Bsw_DHT11_Read(&d) == E_OK)
    {
        *humidity = d.data_raw[0];
        return E_OK;
    }
    else
    {
    	// EM_ERROR_DHT11_READ_HUM
    	log_error(EM_MODULE_DHT11, EM_ERROR_DHT11_READ_HUM, "Rte_Read_Humidity");
    	return E_NOT_OK;
    }
}

Std_ReturnType Rte_Write_PwmDuty(uint8 dutyPercent)
{
    /* Clamp duty to 0..100 */
    if (dutyPercent > MAX_DUTY_CYCLE)
        dutyPercent = MAX_DUTY_CYCLE;
    else if (dutyPercent < MIN_DUTY_CYCLE) dutyPercent = MIN_DUTY_CYCLE;
    if (Bsw_Pwm_SetDuty(dutyPercent) == E_OK)
        return E_OK;
    else
    {
    	// EM_ERROR_PWM_UPDATE_DUTY
    	log_error(EM_MODULE_PWM, EM_ERROR_PWM_UPDATE_DUTY, "Rte_Write_PwmDuty");
    return E_NOT_OK;
    }
}


