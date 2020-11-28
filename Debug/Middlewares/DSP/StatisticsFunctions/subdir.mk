################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/DSP/StatisticsFunctions/arm_max_f32.c \
../Middlewares/DSP/StatisticsFunctions/arm_max_q15.c \
../Middlewares/DSP/StatisticsFunctions/arm_max_q31.c \
../Middlewares/DSP/StatisticsFunctions/arm_max_q7.c \
../Middlewares/DSP/StatisticsFunctions/arm_mean_f32.c \
../Middlewares/DSP/StatisticsFunctions/arm_mean_q15.c \
../Middlewares/DSP/StatisticsFunctions/arm_mean_q31.c \
../Middlewares/DSP/StatisticsFunctions/arm_mean_q7.c \
../Middlewares/DSP/StatisticsFunctions/arm_min_f32.c \
../Middlewares/DSP/StatisticsFunctions/arm_min_q15.c \
../Middlewares/DSP/StatisticsFunctions/arm_min_q31.c \
../Middlewares/DSP/StatisticsFunctions/arm_min_q7.c \
../Middlewares/DSP/StatisticsFunctions/arm_power_f32.c \
../Middlewares/DSP/StatisticsFunctions/arm_power_q15.c \
../Middlewares/DSP/StatisticsFunctions/arm_power_q31.c \
../Middlewares/DSP/StatisticsFunctions/arm_power_q7.c \
../Middlewares/DSP/StatisticsFunctions/arm_rms_f32.c \
../Middlewares/DSP/StatisticsFunctions/arm_rms_q15.c \
../Middlewares/DSP/StatisticsFunctions/arm_rms_q31.c \
../Middlewares/DSP/StatisticsFunctions/arm_std_f32.c \
../Middlewares/DSP/StatisticsFunctions/arm_std_q15.c \
../Middlewares/DSP/StatisticsFunctions/arm_std_q31.c \
../Middlewares/DSP/StatisticsFunctions/arm_var_f32.c \
../Middlewares/DSP/StatisticsFunctions/arm_var_q15.c \
../Middlewares/DSP/StatisticsFunctions/arm_var_q31.c 

OBJS += \
./Middlewares/DSP/StatisticsFunctions/arm_max_f32.o \
./Middlewares/DSP/StatisticsFunctions/arm_max_q15.o \
./Middlewares/DSP/StatisticsFunctions/arm_max_q31.o \
./Middlewares/DSP/StatisticsFunctions/arm_max_q7.o \
./Middlewares/DSP/StatisticsFunctions/arm_mean_f32.o \
./Middlewares/DSP/StatisticsFunctions/arm_mean_q15.o \
./Middlewares/DSP/StatisticsFunctions/arm_mean_q31.o \
./Middlewares/DSP/StatisticsFunctions/arm_mean_q7.o \
./Middlewares/DSP/StatisticsFunctions/arm_min_f32.o \
./Middlewares/DSP/StatisticsFunctions/arm_min_q15.o \
./Middlewares/DSP/StatisticsFunctions/arm_min_q31.o \
./Middlewares/DSP/StatisticsFunctions/arm_min_q7.o \
./Middlewares/DSP/StatisticsFunctions/arm_power_f32.o \
./Middlewares/DSP/StatisticsFunctions/arm_power_q15.o \
./Middlewares/DSP/StatisticsFunctions/arm_power_q31.o \
./Middlewares/DSP/StatisticsFunctions/arm_power_q7.o \
./Middlewares/DSP/StatisticsFunctions/arm_rms_f32.o \
./Middlewares/DSP/StatisticsFunctions/arm_rms_q15.o \
./Middlewares/DSP/StatisticsFunctions/arm_rms_q31.o \
./Middlewares/DSP/StatisticsFunctions/arm_std_f32.o \
./Middlewares/DSP/StatisticsFunctions/arm_std_q15.o \
./Middlewares/DSP/StatisticsFunctions/arm_std_q31.o \
./Middlewares/DSP/StatisticsFunctions/arm_var_f32.o \
./Middlewares/DSP/StatisticsFunctions/arm_var_q15.o \
./Middlewares/DSP/StatisticsFunctions/arm_var_q31.o 

C_DEPS += \
./Middlewares/DSP/StatisticsFunctions/arm_max_f32.d \
./Middlewares/DSP/StatisticsFunctions/arm_max_q15.d \
./Middlewares/DSP/StatisticsFunctions/arm_max_q31.d \
./Middlewares/DSP/StatisticsFunctions/arm_max_q7.d \
./Middlewares/DSP/StatisticsFunctions/arm_mean_f32.d \
./Middlewares/DSP/StatisticsFunctions/arm_mean_q15.d \
./Middlewares/DSP/StatisticsFunctions/arm_mean_q31.d \
./Middlewares/DSP/StatisticsFunctions/arm_mean_q7.d \
./Middlewares/DSP/StatisticsFunctions/arm_min_f32.d \
./Middlewares/DSP/StatisticsFunctions/arm_min_q15.d \
./Middlewares/DSP/StatisticsFunctions/arm_min_q31.d \
./Middlewares/DSP/StatisticsFunctions/arm_min_q7.d \
./Middlewares/DSP/StatisticsFunctions/arm_power_f32.d \
./Middlewares/DSP/StatisticsFunctions/arm_power_q15.d \
./Middlewares/DSP/StatisticsFunctions/arm_power_q31.d \
./Middlewares/DSP/StatisticsFunctions/arm_power_q7.d \
./Middlewares/DSP/StatisticsFunctions/arm_rms_f32.d \
./Middlewares/DSP/StatisticsFunctions/arm_rms_q15.d \
./Middlewares/DSP/StatisticsFunctions/arm_rms_q31.d \
./Middlewares/DSP/StatisticsFunctions/arm_std_f32.d \
./Middlewares/DSP/StatisticsFunctions/arm_std_q15.d \
./Middlewares/DSP/StatisticsFunctions/arm_std_q31.d \
./Middlewares/DSP/StatisticsFunctions/arm_var_f32.d \
./Middlewares/DSP/StatisticsFunctions/arm_var_q15.d \
./Middlewares/DSP/StatisticsFunctions/arm_var_q31.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/DSP/StatisticsFunctions/%.o: ../Middlewares/DSP/StatisticsFunctions/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -DUSE_HAL_DRIVER -DSTM32F746xx -I"D:/workspace/ethernet_lights/Inc" -I"D:/workspace/ethernet_lights/Middlewares/Third_Party/LwIP/src/include" -I"D:/workspace/ethernet_lights/Middlewares/Third_Party/LwIP/system" -I"D:/workspace/ethernet_lights/Drivers/STM32F7xx_HAL_Driver/Inc" -I"D:/workspace/ethernet_lights/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"D:/workspace/ethernet_lights/Middlewares/Third_Party/LwIP/src/include/netif/ppp" -I"D:/workspace/ethernet_lights/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"D:/workspace/ethernet_lights/Middlewares/Third_Party/LwIP/src/include/lwip" -I"D:/workspace/ethernet_lights/Middlewares/Third_Party/LwIP/src/include/lwip/apps" -I"D:/workspace/ethernet_lights/Middlewares/Third_Party/LwIP/src/include/lwip/priv" -I"D:/workspace/ethernet_lights/Middlewares/Third_Party/LwIP/src/include/lwip/prot" -I"D:/workspace/ethernet_lights/Middlewares/Third_Party/LwIP/src/include/netif" -I"D:/workspace/ethernet_lights/Middlewares/Third_Party/LwIP/src/include/posix" -I"D:/workspace/ethernet_lights/Middlewares/Third_Party/LwIP/src/include/posix/sys" -I"D:/workspace/ethernet_lights/Middlewares/Third_Party/LwIP/system/arch" -I"D:/workspace/ethernet_lights/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


