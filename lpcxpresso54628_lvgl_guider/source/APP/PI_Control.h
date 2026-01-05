/*
 * PI_Control.h
 *
 *  Created on: 5 ian. 2026
 *      Author: alexa
 */

#include "stdint.h"

#ifndef APP_PI_CONTROL_H_
#define APP_PI_CONTROL_H_

#define PWM_MAX 100
#define PWM_MIN 0
#define TS 0.1

uint8_t PI_Controller_Run(uint8_t *sensor_temperature, uint8_t *desired_temperature);

#endif /* APP_PI_CONTROL_H_ */
