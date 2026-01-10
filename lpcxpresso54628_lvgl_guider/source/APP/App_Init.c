#include "App_Init.h"
#include "App_Tasks.h"
#include "../RTE/Rte.h"
#include "FreeRTOS.h"
#include "task.h"

#include "fsl_debug_console.h"
#include "fsl_sctimer.h"
#include "lvgl_support.h"
#include "board.h"
#include "app.h"
#include "lvgl.h"
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"
#include "lvgl_demo_utils.h"
#include "stdio.h"
#include "string.h"

void App_Init(void)
{
	Rte_Init();
	Em_Init();

}
