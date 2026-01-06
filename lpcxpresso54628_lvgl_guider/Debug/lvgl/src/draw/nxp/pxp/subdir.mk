################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/draw/nxp/pxp/lv_draw_buf_pxp.c \
../lvgl/src/draw/nxp/pxp/lv_draw_pxp.c \
../lvgl/src/draw/nxp/pxp/lv_draw_pxp_fill.c \
../lvgl/src/draw/nxp/pxp/lv_draw_pxp_img.c \
../lvgl/src/draw/nxp/pxp/lv_draw_pxp_layer.c \
../lvgl/src/draw/nxp/pxp/lv_pxp_cfg.c \
../lvgl/src/draw/nxp/pxp/lv_pxp_osa.c \
../lvgl/src/draw/nxp/pxp/lv_pxp_utils.c 

C_DEPS += \
./lvgl/src/draw/nxp/pxp/lv_draw_buf_pxp.d \
./lvgl/src/draw/nxp/pxp/lv_draw_pxp.d \
./lvgl/src/draw/nxp/pxp/lv_draw_pxp_fill.d \
./lvgl/src/draw/nxp/pxp/lv_draw_pxp_img.d \
./lvgl/src/draw/nxp/pxp/lv_draw_pxp_layer.d \
./lvgl/src/draw/nxp/pxp/lv_pxp_cfg.d \
./lvgl/src/draw/nxp/pxp/lv_pxp_osa.d \
./lvgl/src/draw/nxp/pxp/lv_pxp_utils.d 

OBJS += \
./lvgl/src/draw/nxp/pxp/lv_draw_buf_pxp.o \
./lvgl/src/draw/nxp/pxp/lv_draw_pxp.o \
./lvgl/src/draw/nxp/pxp/lv_draw_pxp_fill.o \
./lvgl/src/draw/nxp/pxp/lv_draw_pxp_img.o \
./lvgl/src/draw/nxp/pxp/lv_draw_pxp_layer.o \
./lvgl/src/draw/nxp/pxp/lv_pxp_cfg.o \
./lvgl/src/draw/nxp/pxp/lv_pxp_osa.o \
./lvgl/src/draw/nxp/pxp/lv_pxp_utils.o 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/draw/nxp/pxp/%.o: ../lvgl/src/draw/nxp/pxp/%.c lvgl/src/draw/nxp/pxp/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__NEWLIB__ -DCPU_LPC54628J512ET180 -DCPU_LPC54628J512ET180_cm4 -DMCUXPRESSO_SDK -DCPU_LPC54628 -D__USE_CMSIS -DSDK_DEBUGCONSOLE=1 -DMCUX_META_BUILD -DLPC54628_SERIES -DSDK_I2C_BASED_COMPONENT_USED=1 -DLV_CONF_INCLUDE_SIMPLE=1 -DSDK_OS_FREE_RTOS -DCR_INTEGER_PRINTF -D__MCUXPRESSO -DDEBUG -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\source" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\drivers" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\CMSIS" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\CMSIS\m-profile" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\device" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\device\periph" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\utilities" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\utilities\str" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\utilities\debug_console_lite" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\component\uart" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\video" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\touchpanel" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\lvgl" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\lvgl\src\draw\nxp\vglite" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\freertos\freertos-kernel\include" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\freertos\freertos-kernel\portable\GCC\ARM_CM4F" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\generated" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\custom" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\generated\guider_customer_fonts" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\board" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\lvgl\template" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\freertos\freertos-kernel\template" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\freertos\freertos-kernel\template\ARM_CM4F_3_priority_bits" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -fno-builtin -Wno-format -fms-extensions -imacros "C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\source\mcux_config.h" -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-lvgl-2f-src-2f-draw-2f-nxp-2f-pxp

clean-lvgl-2f-src-2f-draw-2f-nxp-2f-pxp:
	-$(RM) ./lvgl/src/draw/nxp/pxp/lv_draw_buf_pxp.d ./lvgl/src/draw/nxp/pxp/lv_draw_buf_pxp.o ./lvgl/src/draw/nxp/pxp/lv_draw_pxp.d ./lvgl/src/draw/nxp/pxp/lv_draw_pxp.o ./lvgl/src/draw/nxp/pxp/lv_draw_pxp_fill.d ./lvgl/src/draw/nxp/pxp/lv_draw_pxp_fill.o ./lvgl/src/draw/nxp/pxp/lv_draw_pxp_img.d ./lvgl/src/draw/nxp/pxp/lv_draw_pxp_img.o ./lvgl/src/draw/nxp/pxp/lv_draw_pxp_layer.d ./lvgl/src/draw/nxp/pxp/lv_draw_pxp_layer.o ./lvgl/src/draw/nxp/pxp/lv_pxp_cfg.d ./lvgl/src/draw/nxp/pxp/lv_pxp_cfg.o ./lvgl/src/draw/nxp/pxp/lv_pxp_osa.d ./lvgl/src/draw/nxp/pxp/lv_pxp_osa.o ./lvgl/src/draw/nxp/pxp/lv_pxp_utils.d ./lvgl/src/draw/nxp/pxp/lv_pxp_utils.o

.PHONY: clean-lvgl-2f-src-2f-draw-2f-nxp-2f-pxp

