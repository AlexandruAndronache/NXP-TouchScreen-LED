#ifndef RTE_H
#define RTE_H

#include "../BSW/Bsw_Types.h"

//#include "lvgl_demo_utils.h"


/* RTE logical IDs (example mapping) */
#define RTE_LABEL_PWM      0u
#define RTE_LABEL_DHT      1u

/* Initialize RTE (calls underlying BSW init where required) */
Std_ReturnType Rte_Init(void);

/* Sensor read API */
Std_ReturnType Rte_Read_DHT11(uint8_t *temperature, uint8_t *humidity);

/* PWM control API */
Std_ReturnType Rte_Write_PwmDuty(uint8_t dutyPercent);

/* Display API: write text to a label (labelId from RTE_LABEL_*) */
Std_ReturnType Rte_Write_DisplayText(uint8_t labelId, const char *text);

/* Optional convenience wrappers */
Std_ReturnType Rte_Read_Temperature(uint8_t *temperature);
Std_ReturnType Rte_Read_Humidity(uint8_t *humidity);

#endif /* RTE_H */
