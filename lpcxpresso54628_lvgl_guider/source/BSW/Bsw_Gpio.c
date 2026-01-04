#include "Bsw_Types.h"
#include "../../drivers/fsl_gpio.h"

Std_ReturnType Bsw_Gpio_Write(uint8 port, uint8 pin, uint8 value)
{
    GPIO_PinWrite(GPIO, port, pin, value);
    return E_OK;
}

Std_ReturnType Bsw_Gpio_Read(uint8 port, uint8 pin, uint8 *value)
{
    *value = GPIO_PinRead(GPIO, port, pin);
    return E_OK;
}

Std_ReturnType Bsw_Gpio_SetDirectionOutput(uint8 port, uint8 pin)
{
    gpio_pin_config_t cfg = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1
    };
    GPIO_PinInit(GPIO, port, pin, &cfg);
    return E_OK;
}

Std_ReturnType Bsw_Gpio_SetDirectionInput(uint8 port, uint8 pin)
{
    gpio_pin_config_t cfg = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0
    };
    GPIO_PinInit(GPIO, port, pin, &cfg);
    return E_OK;
}
