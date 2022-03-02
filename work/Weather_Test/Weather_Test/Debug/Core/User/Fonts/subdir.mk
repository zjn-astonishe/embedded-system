################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/User/Fonts/font12.c \
../Core/User/Fonts/font12CN.c \
../Core/User/Fonts/font16.c \
../Core/User/Fonts/font20.c \
../Core/User/Fonts/font24.c \
../Core/User/Fonts/font24CN.c \
../Core/User/Fonts/font8.c 

C_DEPS += \
./Core/User/Fonts/font12.d \
./Core/User/Fonts/font12CN.d \
./Core/User/Fonts/font16.d \
./Core/User/Fonts/font20.d \
./Core/User/Fonts/font24.d \
./Core/User/Fonts/font24CN.d \
./Core/User/Fonts/font8.d 

OBJS += \
./Core/User/Fonts/font12.o \
./Core/User/Fonts/font12CN.o \
./Core/User/Fonts/font16.o \
./Core/User/Fonts/font20.o \
./Core/User/Fonts/font24.o \
./Core/User/Fonts/font24CN.o \
./Core/User/Fonts/font8.o 


# Each subdirectory must supply rules for building sources it contributes
Core/User/Fonts/font12.o: ../Core/User/Fonts/font12.c Core/User/Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"D:/Documents/Embeded/Weather_Test/Core/User" -I"D:/Documents/Embeded/Weather_Test/Core/User/Config" -I"D:/Documents/Embeded/Weather_Test/Core/User/e-Paper" -I"D:/Documents/Embeded/Weather_Test/Core/User/Examples" -I"D:/Documents/Embeded/Weather_Test/Core/User/Fonts" -I"D:/Documents/Embeded/Weather_Test/Core/User/GUI" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/User/Fonts/font12.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/User/Fonts/font12CN.o: ../Core/User/Fonts/font12CN.c Core/User/Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"D:/Documents/Embeded/Weather_Test/Core/User" -I"D:/Documents/Embeded/Weather_Test/Core/User/Config" -I"D:/Documents/Embeded/Weather_Test/Core/User/e-Paper" -I"D:/Documents/Embeded/Weather_Test/Core/User/Examples" -I"D:/Documents/Embeded/Weather_Test/Core/User/Fonts" -I"D:/Documents/Embeded/Weather_Test/Core/User/GUI" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/User/Fonts/font12CN.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/User/Fonts/font16.o: ../Core/User/Fonts/font16.c Core/User/Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"D:/Documents/Embeded/Weather_Test/Core/User" -I"D:/Documents/Embeded/Weather_Test/Core/User/Config" -I"D:/Documents/Embeded/Weather_Test/Core/User/e-Paper" -I"D:/Documents/Embeded/Weather_Test/Core/User/Examples" -I"D:/Documents/Embeded/Weather_Test/Core/User/Fonts" -I"D:/Documents/Embeded/Weather_Test/Core/User/GUI" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/User/Fonts/font16.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/User/Fonts/font20.o: ../Core/User/Fonts/font20.c Core/User/Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"D:/Documents/Embeded/Weather_Test/Core/User" -I"D:/Documents/Embeded/Weather_Test/Core/User/Config" -I"D:/Documents/Embeded/Weather_Test/Core/User/e-Paper" -I"D:/Documents/Embeded/Weather_Test/Core/User/Examples" -I"D:/Documents/Embeded/Weather_Test/Core/User/Fonts" -I"D:/Documents/Embeded/Weather_Test/Core/User/GUI" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/User/Fonts/font20.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/User/Fonts/font24.o: ../Core/User/Fonts/font24.c Core/User/Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"D:/Documents/Embeded/Weather_Test/Core/User" -I"D:/Documents/Embeded/Weather_Test/Core/User/Config" -I"D:/Documents/Embeded/Weather_Test/Core/User/e-Paper" -I"D:/Documents/Embeded/Weather_Test/Core/User/Examples" -I"D:/Documents/Embeded/Weather_Test/Core/User/Fonts" -I"D:/Documents/Embeded/Weather_Test/Core/User/GUI" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/User/Fonts/font24.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/User/Fonts/font24CN.o: ../Core/User/Fonts/font24CN.c Core/User/Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"D:/Documents/Embeded/Weather_Test/Core/User" -I"D:/Documents/Embeded/Weather_Test/Core/User/Config" -I"D:/Documents/Embeded/Weather_Test/Core/User/e-Paper" -I"D:/Documents/Embeded/Weather_Test/Core/User/Examples" -I"D:/Documents/Embeded/Weather_Test/Core/User/Fonts" -I"D:/Documents/Embeded/Weather_Test/Core/User/GUI" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/User/Fonts/font24CN.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/User/Fonts/font8.o: ../Core/User/Fonts/font8.c Core/User/Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"D:/Documents/Embeded/Weather_Test/Core/User" -I"D:/Documents/Embeded/Weather_Test/Core/User/Config" -I"D:/Documents/Embeded/Weather_Test/Core/User/e-Paper" -I"D:/Documents/Embeded/Weather_Test/Core/User/Examples" -I"D:/Documents/Embeded/Weather_Test/Core/User/Fonts" -I"D:/Documents/Embeded/Weather_Test/Core/User/GUI" -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/User/Fonts/font8.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

