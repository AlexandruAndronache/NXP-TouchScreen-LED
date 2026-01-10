#include "fsl_iap.h"
#include <string.h>
#include <stdint.h>
#include <fsl_debug_console.h>
//#include "App_Error_Manager.h"
#include "../BSW/Bsw_Types.h"
//#include "../../freertos/freertos-kernel/task.h"
#include "FreeRTOS.h"
#include "task.h"


#define ERROR_FLASH_SECTOR 29                           // error flash memory sector
#define FLASH_PAGE_SIZE    256

uint16_t global_error_counter = 0;
static uint32_t s_PageBuf[FLASH_PAGE_SIZE / sizeof(uint32_t)];
static uint32_t s_IapFlashPage = (FLASH_PAGE_SIZE / sizeof(uint32_t)) * 0;  // first page of sector
Em_ErrorEntryType Em_ErrorTable[EM_MAX_ERRORS]; // array pentru erori

void Load_Global_Error(void)
{
    uint16_t stored = *((uint16_t *)((ERROR_FLASH_SECTOR * 32*1024) + s_IapFlashPage * FLASH_PAGE_SIZE));

    if (stored != 0xFFFF)   // erased flash = 0xFFFF
        global_error_counter = stored;
    else
        global_error_counter = 0;
}


void Save_Global_Error(void)
{
    status_t status;

    // 1) Copy current flash page to buffer
    memcpy(s_PageBuf, (void *)((ERROR_FLASH_SECTOR * 32*1024) + s_IapFlashPage * FLASH_PAGE_SIZE), FLASH_PAGE_SIZE);

    // 2) Update counter in buffer (first 2 bytes)
    *((uint16_t *)s_PageBuf) = global_error_counter;

    // 3) Prepare sector for erase
    IAP_PrepareSectorForWrite(ERROR_FLASH_SECTOR, ERROR_FLASH_SECTOR);

    // 4) Erase the sector
    IAP_EraseSector(ERROR_FLASH_SECTOR, ERROR_FLASH_SECTOR, SystemCoreClock);

    // 5) Program page
    status = IAP_CopyRamToFlash(
        (ERROR_FLASH_SECTOR * 32*1024) + s_IapFlashPage * FLASH_PAGE_SIZE,
        s_PageBuf,
        FLASH_PAGE_SIZE,
        SystemCoreClock
    );

    if (status != kStatus_IAP_Success)
    {
        PRINTF("Flash write failed: %d\r\n", status);
    }
}

void Em_Init(void)
{
    for (uint8_t i = 0; i < EM_MAX_ERRORS; i++)
{		Em_ErrorTable[i].time_of_log = 0;
        Em_ErrorTable[i].errorId = EM_ERROR_NONE;
        Em_ErrorTable[i].status = EM_ERROR_NONE;
        memset(Em_ErrorTable[i].function_name,0,sizeof(Em_ErrorTable[i].function_name));
    }
}


void  log_error(Em_ModuleIdType module_name, Em_Error_IdType error_type, const char* function_name )
{
	static uint8_t error_counter = 0;
	Em_ErrorTable[error_counter].time_of_log = (uint32_t)(xTaskGetTickCount() *portTICK_PERIOD_MS); // get tick count and convert to ms
    Em_ErrorTable[error_counter].errorId = module_name;
    Em_ErrorTable[error_counter].status = error_type;
    strcpy(Em_ErrorTable[error_counter].function_name, function_name);
    Em_ErrorTable[error_counter].function_name[strlen(function_name)] = '\0';



    // just print
    //if(Em_ErrorTable[error_counter].status !=EM_ERROR_NONE)
	PRINTF("Time in ms: %d, Module: %d, Error Type: %d, Function name: %s\r\n",
			Em_ErrorTable[error_counter].time_of_log,
			Em_ErrorTable[error_counter].errorId,
			Em_ErrorTable[error_counter].status,
			Em_ErrorTable[error_counter].function_name);


	  error_counter = (error_counter + 1U) % EM_MAX_ERRORS; // ring buffer for overflow

}



void print_error_log()
{
	for(uint8_t i = 0; i < EM_MAX_ERRORS; i++)
	{
		if(Em_ErrorTable[i].status !=EM_ERROR_NONE)
		PRINTF("Time in ms: %d, Module: %d, Error Type: %d\r\n",
				Em_ErrorTable[i].time_of_log,
				Em_ErrorTable[i].errorId,
				Em_ErrorTable[i].status,
				Em_ErrorTable[i].function_name);
	}

}
