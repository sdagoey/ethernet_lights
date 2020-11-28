################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS/DSP/SupportFunctions/arm_copy_f32.c \
../Drivers/CMSIS/DSP/SupportFunctions/arm_copy_q15.c \
../Drivers/CMSIS/DSP/SupportFunctions/arm_copy_q31.c \
../Drivers/CMSIS/DSP/SupportFunctions/arm_copy_q7.c \
../Drivers/CMSIS/DSP/SupportFunctions/arm_fill_f32.c \
../Drivers/CMSIS/DSP/SupportFunctions/arm_fill_q15.c \
../Drivers/CMSIS/DSP/SupportFunctions/arm_fill_q31.c \
../Drivers/CMSIS/DSP/SupportFunctions/arm_fill_q7.c \
../Drivers/CMSIS/DSP/SupportFunctions/arm_float_to_q15.c \
../Drivers/CMSIS/DSP/SupportFunctions/arm_float_to_q31.c \
../Drivers/CMSIS/DSP/SupportFunctions/arm_float_to_q7.c \
../Drivers/CMSIS/DSP/SupportFunctions/arm_q15_to_float.c \
../Drivers/CMSIS/DSP/SupportFunctions/arm_q15_to_q31.c \
../Drivers/CMSIS/DSP/SupportFunctions/arm_q15_to_q7.c \
../Drivers/CMSIS/DSP/SupportFunctions/arm_q31_to_float.c \
../Drivers/CMSIS/DSP/SupportFunctions/arm_q31_to_q15.c \
../Drivers/CMSIS/DSP/SupportFunctions/arm_q31_to_q7.c \
../Drivers/CMSIS/DSP/SupportFunctions/arm_q7_to_float.c \
../Drivers/CMSIS/DSP/SupportFunctions/arm_q7_to_q15.c \
../Drivers/CMSIS/DSP/SupportFunctions/arm_q7_to_q31.c 

OBJS += \
./Drivers/CMSIS/DSP/SupportFunctions/arm_copy_f32.o \
./Drivers/CMSIS/DSP/SupportFunctions/arm_copy_q15.o \
./Drivers/CMSIS/DSP/SupportFunctions/arm_copy_q31.o \
./Drivers/CMSIS/DSP/SupportFunctions/arm_copy_q7.o \
./Drivers/CMSIS/DSP/SupportFunctions/arm_fill_f32.o \
./Drivers/CMSIS/DSP/SupportFunctions/arm_fill_q15.o \
./Drivers/CMSIS/DSP/SupportFunctions/arm_fill_q31.o \
./Drivers/CMSIS/DSP/SupportFunctions/arm_fill_q7.o \
./Drivers/CMSIS/DSP/SupportFunctions/arm_float_to_q15.o \
./Drivers/CMSIS/DSP/SupportFunctions/arm_float_to_q31.o \
./Drivers/CMSIS/DSP/SupportFunctions/arm_float_to_q7.o \
./Drivers/CMSIS/DSP/SupportFunctions/arm_q15_to_float.o \
./Drivers/CMSIS/DSP/SupportFunctions/arm_q15_to_q31.o \
./Drivers/CMSIS/DSP/SupportFunctions/arm_q15_to_q7.o \
./Drivers/CMSIS/DSP/SupportFunctions/arm_q31_to_float.o \
./Drivers/CMSIS/DSP/SupportFunctions/arm_q31_to_q15.o \
./Drivers/CMSIS/DSP/SupportFunctions/arm_q31_to_q7.o \
./Drivers/CMSIS/DSP/SupportFunctions/arm_q7_to_float.o \
./Drivers/CMSIS/DSP/SupportFunctions/arm_q7_to_q15.o \
./Drivers/CMSIS/DSP/SupportFunctions/arm_q7_to_q31.o 

C_DEPS += \
./Drivers/CMSIS/DSP/SupportFunctions/arm_copy_f32.d \
./Drivers/CMSIS/DSP/SupportFunctions/arm_copy_q15.d \
./Drivers/CMSIS/DSP/SupportFunctions/arm_copy_q31.d \
./Drivers/CMSIS/DSP/SupportFunctions/arm_copy_q7.d \
./Drivers/CMSIS/DSP/SupportFunctions/arm_fill_f32.d \
./Drivers/CMSIS/DSP/SupportFunctions/arm_fill_q15.d \
./Drivers/CMSIS/DSP/SupportFunctions/arm_fill_q31.d \
./Drivers/CMSIS/DSP/SupportFunctions/arm_fill_q7.d \
./Drivers/CMSIS/DSP/SupportFunctions/arm_float_to_q15.d \
./Drivers/CMSIS/DSP/SupportFunctions/arm_float_to_q31.d \
./Drivers/CMSIS/DSP/SupportFunctions/arm_float_to_q7.d \
./Drivers/CMSIS/DSP/SupportFunctions/arm_q15_to_float.d \
./Drivers/CMSIS/DSP/SupportFunctions/arm_q15_to_q31.d \
./Drivers/CMSIS/DSP/SupportFunctions/arm_q15_to_q7.d \
./Drivers/CMSIS/DSP/SupportFunctions/arm_q31_to_float.d \
./Drivers/CMSIS/DSP/SupportFunctions/arm_q31_to_q15.d \
./Drivers/CMSIS/DSP/SupportFunctions/arm_q31_to_q7.d \
./Drivers/CMSIS/DSP/SupportFunctions/arm_q7_to_float.d \
./Drivers/CMSIS/DSP/SupportFunctions/arm_q7_to_q15.d \
./Drivers/CMSIS/DSP/SupportFunctions/arm_q7_to_q31.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/DSP/SupportFunctions/%.o: ../Drivers/CMSIS/DSP/SupportFunctions/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -DUSE_HAL_DRIVER -DSTM32F746xx -I"D:/workspace/ethernet_lights/Inc" -I"D:/workspace/ethernet_lights/Middlewares/Third_Party/LwIP/src/include" -I"D:/workspace/ethernet_lights/Middlewares/Third_Party/LwIP/system" -I"D:/workspace/ethernet_lights/Drivers/STM32F7xx_HAL_Driver/Inc" -I"D:/workspace/ethernet_lights/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"D:/workspace/ethernet_lights/Middlewares/Third_Party/LwIP/src/include/netif/ppp" -I"D:/workspace/ethernet_lights/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"D:/workspace/ethernet_lights/Middlewares/Third_Party/LwIP/src/include/lwip" -I"D:/workspace/ethernet_lights/Middlewares/Third_Party/LwIP/src/include/lwip/apps" -I"D:/workspace/ethernet_lights/Middlewares/Third_Party/LwIP/src/include/lwip/priv" -I"D:/workspace/ethernet_lights/Middlewares/Third_Party/LwIP/src/include/lwip/prot" -I"D:/workspace/ethernet_lights/Middlewares/Third_Party/LwIP/src/include/netif" -I"D:/workspace/ethernet_lights/Middlewares/Third_Party/LwIP/src/include/posix" -I"D:/workspace/ethernet_lights/Middlewares/Third_Party/LwIP/src/include/posix/sys" -I"D:/workspace/ethernet_lights/Middlewares/Third_Party/LwIP/system/arch" -I"D:/workspace/ethernet_lights/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


