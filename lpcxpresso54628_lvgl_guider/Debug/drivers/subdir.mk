################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/fsl_clock.c \
../drivers/fsl_common.c \
../drivers/fsl_common_arm.c \
../drivers/fsl_emc.c \
../drivers/fsl_flexcomm.c \
../drivers/fsl_gpio.c \
../drivers/fsl_i2c.c \
../drivers/fsl_iap.c \
../drivers/fsl_lcdc.c \
../drivers/fsl_power.c \
../drivers/fsl_reset.c \
../drivers/fsl_sctimer.c \
../drivers/fsl_spi.c \
../drivers/fsl_usart.c 

C_DEPS += \
./drivers/fsl_clock.d \
./drivers/fsl_common.d \
./drivers/fsl_common_arm.d \
./drivers/fsl_emc.d \
./drivers/fsl_flexcomm.d \
./drivers/fsl_gpio.d \
./drivers/fsl_i2c.d \
./drivers/fsl_iap.d \
./drivers/fsl_lcdc.d \
./drivers/fsl_power.d \
./drivers/fsl_reset.d \
./drivers/fsl_sctimer.d \
./drivers/fsl_spi.d \
./drivers/fsl_usart.d 

OBJS += \
./drivers/fsl_clock.o \
./drivers/fsl_common.o \
./drivers/fsl_common_arm.o \
./drivers/fsl_emc.o \
./drivers/fsl_flexcomm.o \
./drivers/fsl_gpio.o \
./drivers/fsl_i2c.o \
./drivers/fsl_iap.o \
./drivers/fsl_lcdc.o \
./drivers/fsl_power.o \
./drivers/fsl_reset.o \
./drivers/fsl_sctimer.o \
./drivers/fsl_spi.o \
./drivers/fsl_usart.o 


# Each subdirectory must supply rules for building sources it contributes
drivers/%.o: ../drivers/%.c drivers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__NEWLIB__ -DCPU_LPC54628J512ET180 -DCPU_LPC54628J512ET180_cm4 -DMCUXPRESSO_SDK -DCPU_LPC54628 -D__USE_CMSIS -DSDK_DEBUGCONSOLE=1 -DMCUX_META_BUILD -DLPC54628_SERIES -DSDK_I2C_BASED_COMPONENT_USED=1 -DLV_CONF_INCLUDE_SIMPLE=1 -DSDK_OS_FREE_RTOS -DCR_INTEGER_PRINTF -D__MCUXPRESSO -DDEBUG -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\source" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\drivers" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\CMSIS" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\CMSIS\m-profile" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\device" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\device\periph" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\utilities" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\utilities\str" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\utilities\debug_console_lite" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\component\uart" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\video" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\touchpanel" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\lvgl" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\lvgl\src\draw\nxp\vglite" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\freertos\freertos-kernel\include" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\freertos\freertos-kernel\portable\GCC\ARM_CM4F" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\generated" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\custom" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\generated\guider_customer_fonts" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\board" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\lvgl\template" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\freertos\freertos-kernel\template" -I"C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\freertos\freertos-kernel\template\ARM_CM4F_3_priority_bits" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -fno-builtin -Wno-format -fms-extensions -imacros "C:\Users\alexa\Documents\MCUXpressoIDE_25.6.136\workspace\lpcxpresso54628_lvgl_guider\source\mcux_config.h" -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__NEWLIB__ -fstack-usage -specs=nano.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-drivers

clean-drivers:
	-$(RM) ./drivers/fsl_clock.d ./drivers/fsl_clock.o ./drivers/fsl_common.d ./drivers/fsl_common.o ./drivers/fsl_common_arm.d ./drivers/fsl_common_arm.o ./drivers/fsl_emc.d ./drivers/fsl_emc.o ./drivers/fsl_flexcomm.d ./drivers/fsl_flexcomm.o ./drivers/fsl_gpio.d ./drivers/fsl_gpio.o ./drivers/fsl_i2c.d ./drivers/fsl_i2c.o ./drivers/fsl_iap.d ./drivers/fsl_iap.o ./drivers/fsl_lcdc.d ./drivers/fsl_lcdc.o ./drivers/fsl_power.d ./drivers/fsl_power.o ./drivers/fsl_reset.d ./drivers/fsl_reset.o ./drivers/fsl_sctimer.d ./drivers/fsl_sctimer.o ./drivers/fsl_spi.d ./drivers/fsl_spi.o ./drivers/fsl_usart.d ./drivers/fsl_usart.o

.PHONY: clean-drivers

