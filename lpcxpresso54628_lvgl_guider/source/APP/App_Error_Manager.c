#include "fsl_iap.h"
#include <string.h>
#include <stdint.h>
#include <fsl_debug_console.h>

#define ERROR_FLASH_SECTOR 29                           // error flash memory sector
#define FLASH_PAGE_SIZE    256

uint16_t global_error_counter = 0;
static uint32_t s_PageBuf[FLASH_PAGE_SIZE / sizeof(uint32_t)];
static uint32_t s_IapFlashPage = (FLASH_PAGE_SIZE / sizeof(uint32_t)) * 0;  // first page of sector



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


