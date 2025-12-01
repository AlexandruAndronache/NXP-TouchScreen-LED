#ifndef APP_LOGIC_H
#define APP_LOGIC_H


#include <stdint.h>
#include "../RTE/Rte.h"


void App_Logic_MainLoop(void);


/* Sensor/logic updates */
void App_Logic_UpdateSensorValues(void);


/* Getters */
uint8_t App_Logic_GetTemperature(void);
uint8_t App_Logic_GetHumidity(void);
uint8_t App_Logic_GetMotorPwm(void);
void App_Logic_SetMotorPwm(uint8_t dutyPercent);

#endif /* APP_LOGIC_H */
