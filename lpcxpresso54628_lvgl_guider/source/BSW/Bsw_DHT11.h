#ifndef BSW_DHT11_H
#define BSW_DHT11_H

#include "Bsw_Types.h"

#define DHT_PORT 3
#define DHT_PIN 14
#define SEQUENCE_0 18000
#define _40_us 40
#define _80_us 80
#define _100_us 100
#define BYTE_LENGTH 8
typedef struct {
    uint8_t data_raw[5];
} DHT11_DataType_raw;

typedef struct {
    uint8_t humidity;
    uint8_t temperature;
} DHT11_DataType;

Std_ReturnType Bsw_DHT11_Init();
Std_ReturnType Bsw_DHT11_Read(DHT11_DataType_raw *data);

#endif
