
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
        rv = E_NOT_OK;
    }

    /* Nothing else mandatory for DHT11 or display in our wrappers.
       If you later add BSW init functions, call them here. */

    return rv;
}

/* Read both temperature and humidity in one call */
Std_ReturnType Rte_Read_DHT11(uint8 *temperature, uint8 *humidity)
{
    if ((temperature == NULL) || (humidity == NULL))
    {
    	// EM_ERROR_DHT11_READ_ERROR
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
    	return E_NOT_OK;
    }

}

/* Convenience single-value readers */
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
    return E_NOT_OK;
    }
}

/* PWM duty writer */
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
    return E_NOT_OK;
    }
}

/* Display text writer */
//Std_ReturnType Rte_Write_DisplayText(uint8 labelId, const char *text)
//{
//    if (text == NULL)
//        return E_NOT_OK;
//
//    /* Forward to display BSW */
//    if (Bsw_Display_SetText(labelId, text) == E_OK)
//        return E_OK;
//
//    return E_NOT_OK;
//}
