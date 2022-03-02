################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/User/GUI/GUI_Paint.c 

C_DEPS += \
./Core/User/GUI/GUI_Paint.d 

OBJS += \
./Core/User/GUI/GUI_Paint.o 


# Each subdirectory must supply rules for building sources it contributes
Core/User/GUI/GUI_Paint.o: ../Core/User/GUI/GUI_Paint.c Core/User/GUI/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"D:/Documents/Embeded/Weather_Test/Core/User" -I"D:/Documents/Embeded/Weather_Test/Core/User/Config" -I"D:/Documents/Embeded/Weather_Test/Core/User/e-Paper" -I"D:/Documents/Embeded/Weather_Test/Core/User/Examples" -I"D:/Documents/Embeded/Weather_Test/Core/User/Fonts" -I"D:/Documents/Embeded/Weather_Test/Core/User/GUI" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/User/GUI/GUI_Paint.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

