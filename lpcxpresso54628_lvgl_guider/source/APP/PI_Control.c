/*
 * PI_control.c
 *
 *  Created on: 5 ian. 2026
 *      Author: alexa
 */
#include "PI_Control.h"



uint8_t PI_Controller_Run(uint8_t *sensor_temperature, uint8_t *desired_temperature)
{
    //float measured = 0;
   // float setpoint = 0;
    float error = 0;
    uint8_t control = 0;

//    Rte_Read_Temperature_Value(&measured);
//    Rte_Read_Temperature_Setpoint(&setpoint);

    float placeholder_temp = 20.0;

    error = *desired_temperature - *sensor_temperature;

    // no need to turn on fan
    if (error > 0)
    {
    	 control = PWM_MIN;
    	 return control;
    }



    if (error < 0)
    error = -error;

    if (error > 10)
    {
    	error = 10;
    }


    //float integral += (error * TS); // every 100 ms
    float Kp = 10;

    control =(uint8_t) (Kp * error);

    if (control > PWM_MAX) {
        control = PWM_MAX;
       // integral -= error * Ts;
    }
    else if (control < PWM_MIN) {
        control = PWM_MIN;
       // integral -= error * TS;
    }

    //Rte_Write_FanDuty((uint16)control);

    return control;
}
