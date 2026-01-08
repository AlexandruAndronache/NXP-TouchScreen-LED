#ifndef APP_LOGIC_H
#define APP_LOGIC_H


#include <stdint.h>
#include "../RTE/Rte.h"


void App_Logic_MainLoop();
void App_Logic_PrepareUiData();
uint8_t App_Logic_GetPwmValue();
void App_Logic_SetMotorPwm(void);
void App_Logic_UpdateSensorValues(void);
void LCD_Init(void);
void LCD_Display(void);
Std_ReturnType App_Init_Variables();


#endif /* APP_LOGIC_H */
