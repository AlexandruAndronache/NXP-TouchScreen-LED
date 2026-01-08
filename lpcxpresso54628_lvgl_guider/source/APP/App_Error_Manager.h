/*
 * App_Error_Manager.h
 *
 *  Created on: 8 ian. 2026
 *      Author: alexa
 */

#ifndef APP_APP_ERROR_MANAGER_H_
#define APP_APP_ERROR_MANAGER_H_


#define EM_MAX_ERRORS 10

typedef enum
{
    EM_MODULE_DHT11 = 1,
    EM_MODULE_GPIO = 2 ,
	EM_MODULE_PWM = 3,
	EM_MODULE_CONTROL = 4,

	EM_MODULE_RTE = 3,
	EM_MODULE_APP = 4
} Em_ModuleIdType;

typedef enum
{
    EM_ERROR_NONE = 0,

	EM_ERROR_DHT11_SET_DIRECTION_FAILED = 1,
	EM_ERROR_DHT11_CHECK1_FAILED = 2,
	EM_ERROR_DHT11_CHECK2_FAILED = 3,
	EM_ERROR_DHT11_CHECK3_FAILED = 4,

	EM_ERROR_DHT11_TIMEOUT_100us = 5,

	EM_ERROR_DHT11_READ = 6,
	EM_ERROR_DHT11_READ_TEMP = 7,
	EM_ERROR_DHT11_READ_HUM = 8,

	EM_ERROR_PWM_SETUP_FAILED = 9,
	EM_ERROR_PWM_SETUP_FAILED = 10,
	EM_ERROR_PWM_UPDATE_DUTY = 11

} Em_Error_IdType;

typedef struct
{
	Em_ModuleIdType errorId;
	Em_Error_IdType status;
    char function_name[25];
} Em_ErrorEntryType;


Em_ErrorEntryType Em_ErrorTable[EM_MAX_ERRORS]; // array pentru erori

void Em_Init(void)
{
    for (uint8 i = 0; i < EM_MAX_ERRORS; i++)
    {
        Em_ErrorTable[i].errorId = EM_ERROR_NONE;
        Em_ErrorTable[i].status = EM_STATUS_PASSED;
        memset(Em_ErrorTable[i].function_name,0,seizeof(Em_ErrorTable[i].function_name));
    }
}


void  log_error(Em_ModuleIdType module_name, Em_Error_IdType error_type, char* function_name )
{
	static uint8_t error_counter = 0;
    Em_ErrorTable[error_counter].errorId = module_name;
    Em_ErrorTable[error_counter].status = error_type;
    strcpy(Em_ErrorTable[error_counter].function_name, function_name);
    error_counter++;

}

void Load_Global_Error(void);
void Save_Global_Error(void);

#endif /* APP_APP_ERROR_MANAGER_H_ */
