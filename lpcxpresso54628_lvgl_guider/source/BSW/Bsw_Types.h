#ifndef BSW_TYPES_H
#define BSW_TYPES_H

typedef unsigned char  uint8;
typedef unsigned short uint16;
typedef unsigned int   uint32;
typedef long           BaseType_t;

#include "fsl_debug_console.h"
#include "stdint.h"
#include "../APP/App_Error_Manager.h"

typedef enum {
    E_OK = 0,
    E_NOT_OK = 1
} Std_ReturnType;


#define HIGH 1
#define LOW 0
#define TRUE 1
#define FALSE 0

#define CHANNEL_0 0

#define MAX_DUTY_CYCLE 100
#define _50_DUTY_CYCLE 50U
#define MIN_DUTY_CYCLE 0
#define _0_DUTY_CYCLE 0



#endif
