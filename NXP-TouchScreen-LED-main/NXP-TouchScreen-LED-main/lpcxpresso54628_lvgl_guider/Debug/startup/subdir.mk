################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../startup/startup_lpc54628.cpp 

CPP_DEPS += \
./startup/startup_lpc54628.d 

OBJS += \
./startup/startup_lpc54628.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.cpp startup/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C++ Compiler'
	arm-none-eabi-c++ -std=gnu++11 -DCPU_LPC54628J512ET180 -DCPU_LPC54628J512ET180_cm4 -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=1 -DMCUX_META_BUILD -DLPC54628_SERIES -DLV_CONF_INCLUDE_SIMPLE=1 -DSDK_OS_FREE_RTOS -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__NEWLIB__ -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\source" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\drivers" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\CMSIS" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\CMSIS\m-profile" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\device" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\device\periph" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\utilities" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\utilities\str" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\utilities\debug_console_lite" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\component\uart" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\video" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\touchpanel" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\lvgl" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\lvgl\src\draw\nxp\vglite" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\freertos\freertos-kernel\include" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\freertos\freertos-kernel\portable\GCC\ARM_CM4F" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\generated" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\custom" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\generated\guider_customer_fonts" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\board" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\lvgl\template" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\freertos\freertos-kernel\template" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\freertos\freertos-kernel\template\ARM_CM4F_3_priority_bits" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -fno-builtin -fno-rtti -fno-exceptions -Wno-format -fms-extensions -imacros "C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\source\mcux_config.h" -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-startup

clean-startup:
	-$(RM) ./startup/startup_lpc54628.d ./startup/startup_lpc54628.o

.PHONY: clean-startup

