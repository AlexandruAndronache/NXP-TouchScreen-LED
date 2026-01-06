################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/draw/sw/lv_draw_sw.c \
../lvgl/src/draw/sw/lv_draw_sw_arc.c \
../lvgl/src/draw/sw/lv_draw_sw_border.c \
../lvgl/src/draw/sw/lv_draw_sw_box_shadow.c \
../lvgl/src/draw/sw/lv_draw_sw_fill.c \
../lvgl/src/draw/sw/lv_draw_sw_gradient.c \
../lvgl/src/draw/sw/lv_draw_sw_img.c \
../lvgl/src/draw/sw/lv_draw_sw_letter.c \
../lvgl/src/draw/sw/lv_draw_sw_line.c \
../lvgl/src/draw/sw/lv_draw_sw_mask.c \
../lvgl/src/draw/sw/lv_draw_sw_mask_rect.c \
../lvgl/src/draw/sw/lv_draw_sw_transform.c \
../lvgl/src/draw/sw/lv_draw_sw_triangle.c \
../lvgl/src/draw/sw/lv_draw_sw_vector.c 

C_DEPS += \
./lvgl/src/draw/sw/lv_draw_sw.d \
./lvgl/src/draw/sw/lv_draw_sw_arc.d \
./lvgl/src/draw/sw/lv_draw_sw_border.d \
./lvgl/src/draw/sw/lv_draw_sw_box_shadow.d \
./lvgl/src/draw/sw/lv_draw_sw_fill.d \
./lvgl/src/draw/sw/lv_draw_sw_gradient.d \
./lvgl/src/draw/sw/lv_draw_sw_img.d \
./lvgl/src/draw/sw/lv_draw_sw_letter.d \
./lvgl/src/draw/sw/lv_draw_sw_line.d \
./lvgl/src/draw/sw/lv_draw_sw_mask.d \
./lvgl/src/draw/sw/lv_draw_sw_mask_rect.d \
./lvgl/src/draw/sw/lv_draw_sw_transform.d \
./lvgl/src/draw/sw/lv_draw_sw_triangle.d \
./lvgl/src/draw/sw/lv_draw_sw_vector.d 

OBJS += \
./lvgl/src/draw/sw/lv_draw_sw.o \
./lvgl/src/draw/sw/lv_draw_sw_arc.o \
./lvgl/src/draw/sw/lv_draw_sw_border.o \
./lvgl/src/draw/sw/lv_draw_sw_box_shadow.o \
./lvgl/src/draw/sw/lv_draw_sw_fill.o \
./lvgl/src/draw/sw/lv_draw_sw_gradient.o \
./lvgl/src/draw/sw/lv_draw_sw_img.o \
./lvgl/src/draw/sw/lv_draw_sw_letter.o \
./lvgl/src/draw/sw/lv_draw_sw_line.o \
./lvgl/src/draw/sw/lv_draw_sw_mask.o \
./lvgl/src/draw/sw/lv_draw_sw_mask_rect.o \
./lvgl/src/draw/sw/lv_draw_sw_transform.o \
./lvgl/src/draw/sw/lv_draw_sw_triangle.o \
./lvgl/src/draw/sw/lv_draw_sw_vector.o 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/draw/sw/%.o: ../lvgl/src/draw/sw/%.c lvgl/src/draw/sw/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__NEWLIB__ -DCPU_LPC54628J512ET180 -DCPU_LPC54628J512ET180_cm4 -DMCUXPRESSO_SDK -DCPU_LPC54628 -D__USE_CMSIS -DSDK_DEBUGCONSOLE=1 -DMCUX_META_BUILD -DLPC54628_SERIES -DSDK_I2C_BASED_COMPONENT_USED=1 -DLV_CONF_INCLUDE_SIMPLE=1 -DSDK_OS_FREE_RTOS -DCR_INTEGER_PRINTF -D__MCUXPRESSO -DDEBUG -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\source" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\drivers" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\CMSIS" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\CMSIS\m-profile" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\device" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\device\periph" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\utilities" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\utilities\str" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\utilities\debug_console_lite" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\component\uart" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\video" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\touchpanel" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\lvgl" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\lvgl\src\draw\nxp\vglite" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\freertos\freertos-kernel\include" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\freertos\freertos-kernel\portable\GCC\ARM_CM4F" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\generated" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\custom" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\generated\guider_customer_fonts" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\board" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\lvgl\template" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\freertos\freertos-kernel\template" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\freertos\freertos-kernel\template\ARM_CM4F_3_priority_bits" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -fno-builtin -Wno-format -fms-extensions -imacros "C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\source\mcux_config.h" -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-lvgl-2f-src-2f-draw-2f-sw

clean-lvgl-2f-src-2f-draw-2f-sw:
	-$(RM) ./lvgl/src/draw/sw/lv_draw_sw.d ./lvgl/src/draw/sw/lv_draw_sw.o ./lvgl/src/draw/sw/lv_draw_sw_arc.d ./lvgl/src/draw/sw/lv_draw_sw_arc.o ./lvgl/src/draw/sw/lv_draw_sw_border.d ./lvgl/src/draw/sw/lv_draw_sw_border.o ./lvgl/src/draw/sw/lv_draw_sw_box_shadow.d ./lvgl/src/draw/sw/lv_draw_sw_box_shadow.o ./lvgl/src/draw/sw/lv_draw_sw_fill.d ./lvgl/src/draw/sw/lv_draw_sw_fill.o ./lvgl/src/draw/sw/lv_draw_sw_gradient.d ./lvgl/src/draw/sw/lv_draw_sw_gradient.o ./lvgl/src/draw/sw/lv_draw_sw_img.d ./lvgl/src/draw/sw/lv_draw_sw_img.o ./lvgl/src/draw/sw/lv_draw_sw_letter.d ./lvgl/src/draw/sw/lv_draw_sw_letter.o ./lvgl/src/draw/sw/lv_draw_sw_line.d ./lvgl/src/draw/sw/lv_draw_sw_line.o ./lvgl/src/draw/sw/lv_draw_sw_mask.d ./lvgl/src/draw/sw/lv_draw_sw_mask.o ./lvgl/src/draw/sw/lv_draw_sw_mask_rect.d ./lvgl/src/draw/sw/lv_draw_sw_mask_rect.o ./lvgl/src/draw/sw/lv_draw_sw_transform.d ./lvgl/src/draw/sw/lv_draw_sw_transform.o ./lvgl/src/draw/sw/lv_draw_sw_triangle.d ./lvgl/src/draw/sw/lv_draw_sw_triangle.o ./lvgl/src/draw/sw/lv_draw_sw_vector.d ./lvgl/src/draw/sw/lv_draw_sw_vector.o

.PHONY: clean-lvgl-2f-src-2f-draw-2f-sw

