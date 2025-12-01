#include "Rte.h"
#include "../BSW/Bsw_DHT11.h"
#include "../BSW/Bsw_Gpio.h"
#include "../BSW/Bsw_Pwm.h"
//#include "Bsw_Display.h"

/* If some BSW modules need initialization, do it here. */
Std_ReturnType Rte_Init(void)
{
    Std_ReturnType rv = E_OK;

    /* Initialize PWM channel 0 (adjust channel if needed) */
    if (Bsw_Pwm_Init(0) != E_OK)
    {
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
        return E_NOT_OK;

    DHT11_DataType_raw d;
    if (Bsw_DHT11_Read(&d) == E_OK)
    {
        *temperature = d.data_raw[2];
        *humidity = d.data_raw[0];
        return E_OK;
    }

    return E_NOT_OK;
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
    return E_NOT_OK;
}

Std_ReturnType Rte_Read_Humidity(uint8 *humidity)
{
    DHT11_DataType_raw d;
    if (Bsw_DHT11_Read(&d) == E_OK)
    {
        *humidity = d.data_raw[0];
        return E_OK;
    }
    return E_NOT_OK;
}

/* PWM duty writer */
Std_ReturnType Rte_Write_PwmDuty(uint8 dutyPercent)
{
    /* Clamp duty to 0..100 */
    if (dutyPercent > 100u)
        dutyPercent = 100u;

    if (Bsw_Pwm_SetDuty(dutyPercent) == E_OK)
        return E_OK;

    return E_NOT_OK;
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
