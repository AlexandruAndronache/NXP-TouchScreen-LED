#ifndef BSW_TYPES_H
#define BSW_TYPES_H

typedef unsigned char  uint8;
typedef unsigned short uint16;
typedef unsigned int   uint32;
typedef long           BaseType_t;

#include "fsl_debug_console.h"
#include "stdint.h"
//#include "lvgl_demo_utils.h"
//#include "stddef.h"
//#include "LPC54628_COMMON.h"
//#include "fsl_gpio.h"
typedef enum {
    E_OK = 0,
    E_NOT_OK = 1
} Std_ReturnType;


//#include "Bsw_DHT11.h"
//#include "Bsw_Gpio.h"
//#include "Bsw_Pwm.h"
//#include "lvgl_demo_utils.h"

#define HIGH 1
#define LOW 0
#define TRUE 1
#define FALSE 0



#endif
