#ifndef APP_TASKS_H
#define APP_TASKS_H

//#include "app.h"
//#include "lvgl.h"
//#include "gui_guider.h"
//#include "events_init.h"
//#include "custom.h"
//#include "lvgl_demo_utils.h"
//#include "lvgl_support.h"

//static volatile bool s_lvgl_initialized = false;
//char data_for_display[32];
//char buffer[32];
//char str[8];

void AppTask(void *pv);
void Logic_Task(void *pv);
void App_DhtTask(void *pv);
void App_Logic_MainLoop();
void LCD_Task(void *param);
//void App_DisplayTask(void *pv);


#endif /* APP_TASKS_H */
