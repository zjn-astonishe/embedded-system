################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/User/Config/DEV_Config.c 

C_DEPS += \
./Core/User/Config/DEV_Config.d 

OBJS += \
./Core/User/Config/DEV_Config.o 


# Each subdirectory must supply rules for building sources it contributes
Core/User/Config/DEV_Config.o: ../Core/User/Config/DEV_Config.c Core/User/Config/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"D:/Documents/Embeded/Weather_Test/Core/User" -I"D:/Documents/Embeded/Weather_Test/Core/User/Config" -I"D:/Documents/Embeded/Weather_Test/Core/User/e-Paper" -I"D:/Documents/Embeded/Weather_Test/Core/User/Examples" -I"D:/Documents/Embeded/Weather_Test/Core/User/Fonts" -I"D:/Documents/Embeded/Weather_Test/Core/User/GUI" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/User/Config/DEV_Config.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

