#ifndef BSW_GPIO_H
#define BSW_GPIO_H

#include "Bsw_Types.h"


Std_ReturnType Bsw_Gpio_Write(uint8_t port, uint8_t pin, uint8_t value);
Std_ReturnType Bsw_Gpio_Read(uint8_t port, uint8_t pin, uint8_t *value);
Std_ReturnType Bsw_Gpio_SetDirectionOutput(uint8_t port, uint8_t pin);
Std_ReturnType Bsw_Gpio_SetDirectionInput(uint8_t port, uint8_t pin);

#endif
