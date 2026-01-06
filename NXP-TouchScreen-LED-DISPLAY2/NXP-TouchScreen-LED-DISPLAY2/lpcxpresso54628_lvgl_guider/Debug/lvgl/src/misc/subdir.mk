################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/misc/lv_anim.c \
../lvgl/src/misc/lv_anim_timeline.c \
../lvgl/src/misc/lv_area.c \
../lvgl/src/misc/lv_array.c \
../lvgl/src/misc/lv_async.c \
../lvgl/src/misc/lv_bidi.c \
../lvgl/src/misc/lv_color.c \
../lvgl/src/misc/lv_color_op.c \
../lvgl/src/misc/lv_event.c \
../lvgl/src/misc/lv_fs.c \
../lvgl/src/misc/lv_ll.c \
../lvgl/src/misc/lv_log.c \
../lvgl/src/misc/lv_lru.c \
../lvgl/src/misc/lv_math.c \
../lvgl/src/misc/lv_matrix.c \
../lvgl/src/misc/lv_palette.c \
../lvgl/src/misc/lv_profiler_builtin.c \
../lvgl/src/misc/lv_rb.c \
../lvgl/src/misc/lv_style.c \
../lvgl/src/misc/lv_style_gen.c \
../lvgl/src/misc/lv_templ.c \
../lvgl/src/misc/lv_text.c \
../lvgl/src/misc/lv_text_ap.c \
../lvgl/src/misc/lv_timer.c \
../lvgl/src/misc/lv_utils.c 

C_DEPS += \
./lvgl/src/misc/lv_anim.d \
./lvgl/src/misc/lv_anim_timeline.d \
./lvgl/src/misc/lv_area.d \
./lvgl/src/misc/lv_array.d \
./lvgl/src/misc/lv_async.d \
./lvgl/src/misc/lv_bidi.d \
./lvgl/src/misc/lv_color.d \
./lvgl/src/misc/lv_color_op.d \
./lvgl/src/misc/lv_event.d \
./lvgl/src/misc/lv_fs.d \
./lvgl/src/misc/lv_ll.d \
./lvgl/src/misc/lv_log.d \
./lvgl/src/misc/lv_lru.d \
./lvgl/src/misc/lv_math.d \
./lvgl/src/misc/lv_matrix.d \
./lvgl/src/misc/lv_palette.d \
./lvgl/src/misc/lv_profiler_builtin.d \
./lvgl/src/misc/lv_rb.d \
./lvgl/src/misc/lv_style.d \
./lvgl/src/misc/lv_style_gen.d \
./lvgl/src/misc/lv_templ.d \
./lvgl/src/misc/lv_text.d \
./lvgl/src/misc/lv_text_ap.d \
./lvgl/src/misc/lv_timer.d \
./lvgl/src/misc/lv_utils.d 

OBJS += \
./lvgl/src/misc/lv_anim.o \
./lvgl/src/misc/lv_anim_timeline.o \
./lvgl/src/misc/lv_area.o \
./lvgl/src/misc/lv_array.o \
./lvgl/src/misc/lv_async.o \
./lvgl/src/misc/lv_bidi.o \
./lvgl/src/misc/lv_color.o \
./lvgl/src/misc/lv_color_op.o \
./lvgl/src/misc/lv_event.o \
./lvgl/src/misc/lv_fs.o \
./lvgl/src/misc/lv_ll.o \
./lvgl/src/misc/lv_log.o \
./lvgl/src/misc/lv_lru.o \
./lvgl/src/misc/lv_math.o \
./lvgl/src/misc/lv_matrix.o \
./lvgl/src/misc/lv_palette.o \
./lvgl/src/misc/lv_profiler_builtin.o \
./lvgl/src/misc/lv_rb.o \
./lvgl/src/misc/lv_style.o \
./lvgl/src/misc/lv_style_gen.o \
./lvgl/src/misc/lv_templ.o \
./lvgl/src/misc/lv_text.o \
./lvgl/src/misc/lv_text_ap.o \
./lvgl/src/misc/lv_timer.o \
./lvgl/src/misc/lv_utils.o 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/misc/%.o: ../lvgl/src/misc/%.c lvgl/src/misc/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__NEWLIB__ -DCPU_LPC54628J512ET180 -DCPU_LPC54628J512ET180_cm4 -DMCUXPRESSO_SDK -DCPU_LPC54628 -D__USE_CMSIS -DSDK_DEBUGCONSOLE=1 -DMCUX_META_BUILD -DLPC54628_SERIES -DSDK_I2C_BASED_COMPONENT_USED=1 -DLV_CONF_INCLUDE_SIMPLE=1 -DSDK_OS_FREE_RTOS -DCR_INTEGER_PRINTF -D__MCUXPRESSO -DDEBUG -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\source" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\drivers" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\CMSIS" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\CMSIS\m-profile" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\device" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\device\periph" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\utilities" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\utilities\str" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\utilities\debug_console_lite" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\component\uart" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\video" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\touchpanel" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\lvgl" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\lvgl\src\draw\nxp\vglite" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\freertos\freertos-kernel\include" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\freertos\freertos-kernel\portable\GCC\ARM_CM4F" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\generated" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\custom" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\generated\guider_customer_fonts" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\board" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\lvgl\template" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\freertos\freertos-kernel\template" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\freertos\freertos-kernel\template\ARM_CM4F_3_priority_bits" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -fno-builtin -Wno-format -fms-extensions -imacros "C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\source\mcux_config.h" -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-lvgl-2f-src-2f-misc

clean-lvgl-2f-src-2f-misc:
	-$(RM) ./lvgl/src/misc/lv_anim.d ./lvgl/src/misc/lv_anim.o ./lvgl/src/misc/lv_anim_timeline.d ./lvgl/src/misc/lv_anim_timeline.o ./lvgl/src/misc/lv_area.d ./lvgl/src/misc/lv_area.o ./lvgl/src/misc/lv_array.d ./lvgl/src/misc/lv_array.o ./lvgl/src/misc/lv_async.d ./lvgl/src/misc/lv_async.o ./lvgl/src/misc/lv_bidi.d ./lvgl/src/misc/lv_bidi.o ./lvgl/src/misc/lv_color.d ./lvgl/src/misc/lv_color.o ./lvgl/src/misc/lv_color_op.d ./lvgl/src/misc/lv_color_op.o ./lvgl/src/misc/lv_event.d ./lvgl/src/misc/lv_event.o ./lvgl/src/misc/lv_fs.d ./lvgl/src/misc/lv_fs.o ./lvgl/src/misc/lv_ll.d ./lvgl/src/misc/lv_ll.o ./lvgl/src/misc/lv_log.d ./lvgl/src/misc/lv_log.o ./lvgl/src/misc/lv_lru.d ./lvgl/src/misc/lv_lru.o ./lvgl/src/misc/lv_math.d ./lvgl/src/misc/lv_math.o ./lvgl/src/misc/lv_matrix.d ./lvgl/src/misc/lv_matrix.o ./lvgl/src/misc/lv_palette.d ./lvgl/src/misc/lv_palette.o ./lvgl/src/misc/lv_profiler_builtin.d ./lvgl/src/misc/lv_profiler_builtin.o ./lvgl/src/misc/lv_rb.d ./lvgl/src/misc/lv_rb.o ./lvgl/src/misc/lv_style.d ./lvgl/src/misc/lv_style.o ./lvgl/src/misc/lv_style_gen.d ./lvgl/src/misc/lv_style_gen.o ./lvgl/src/misc/lv_templ.d ./lvgl/src/misc/lv_templ.o ./lvgl/src/misc/lv_text.d ./lvgl/src/misc/lv_text.o ./lvgl/src/misc/lv_text_ap.d ./lvgl/src/misc/lv_text_ap.o ./lvgl/src/misc/lv_timer.d ./lvgl/src/misc/lv_timer.o ./lvgl/src/misc/lv_utils.d ./lvgl/src/misc/lv_utils.o

.PHONY: clean-lvgl-2f-src-2f-misc

