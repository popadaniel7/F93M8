################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/adc.c \
../Core/Src/can.c \
../Core/Src/dma.c \
../Core/Src/freertos.c \
../Core/Src/gpio.c \
../Core/Src/main.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_hal_timebase_tim.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c \
../Core/Src/tim.c 

C_DEPS += \
./Core/Src/adc.d \
./Core/Src/can.d \
./Core/Src/dma.d \
./Core/Src/freertos.d \
./Core/Src/gpio.d \
./Core/Src/main.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_hal_timebase_tim.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d \
./Core/Src/tim.d 

OBJS += \
./Core/Src/adc.o \
./Core/Src/can.o \
./Core/Src/dma.o \
./Core/Src/freertos.o \
./Core/Src/gpio.o \
./Core/Src/main.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_hal_timebase_tim.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o \
./Core/Src/tim.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -DSTM32_THREAD_SAFE_STRATEGY=4 -c -I../Core/Inc -I"C:/Users/Daniel/Desktop/FG9322/PDM - Power Distributor Module/PDM_APP/BSW" -I"C:/Users/Daniel/Desktop/FG9322/PDM - Power Distributor Module/PDM_APP/APPL/LoadCtrl" -I"C:/Users/Daniel/Desktop/FG9322/PDM - Power Distributor Module/PDM_APP/BSW/Com/CanH" -I"C:/Users/Daniel/Desktop/FG9322/PDM - Power Distributor Module/PDM_APP/BSW/Io/Ain" -I"C:/Users/Daniel/Desktop/FG9322/PDM - Power Distributor Module/PDM_APP/BSW/Sys/EcuM" -I"C:/Users/Daniel/Desktop/FG9322/PDM - Power Distributor Module/PDM_APP/BSW/Diag/Dcm" -I"C:/Users/Daniel/Desktop/FG9322/PDM - Power Distributor Module/PDM_APP/BSW/Diag/Dem" -I"C:/Users/Daniel/Desktop/FG9322/PDM - Power Distributor Module/PDM_APP/BSW/Nvm" -I../Core/ThreadSafe -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Drivers/STM32F1xx_HAL_Driver/Inc -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Middlewares/Third_Party/FreeRTOS/Source/include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Drivers/CMSIS/Device/ST/STM32F1xx/Include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/adc.cyclo ./Core/Src/adc.d ./Core/Src/adc.o ./Core/Src/adc.su ./Core/Src/can.cyclo ./Core/Src/can.d ./Core/Src/can.o ./Core/Src/can.su ./Core/Src/dma.cyclo ./Core/Src/dma.d ./Core/Src/dma.o ./Core/Src/dma.su ./Core/Src/freertos.cyclo ./Core/Src/freertos.d ./Core/Src/freertos.o ./Core/Src/freertos.su ./Core/Src/gpio.cyclo ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32f1xx_hal_msp.cyclo ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_hal_timebase_tim.cyclo ./Core/Src/stm32f1xx_hal_timebase_tim.d ./Core/Src/stm32f1xx_hal_timebase_tim.o ./Core/Src/stm32f1xx_hal_timebase_tim.su ./Core/Src/stm32f1xx_it.cyclo ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.cyclo ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su ./Core/Src/tim.cyclo ./Core/Src/tim.d ./Core/Src/tim.o ./Core/Src/tim.su

.PHONY: clean-Core-2f-Src

