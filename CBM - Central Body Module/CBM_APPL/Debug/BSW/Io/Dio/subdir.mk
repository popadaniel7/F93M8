################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/Io/Dio/Dio.c 

OBJS += \
./BSW/Io/Dio/Dio.o 

C_DEPS += \
./BSW/Io/Dio/Dio.d 


# Each subdirectory must supply rules for building sources it contributes
BSW/Io/Dio/%.o BSW/Io/Dio/%.su BSW/Io/Dio/%.cyclo: ../BSW/Io/Dio/%.c BSW/Io/Dio/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -DSTM32_THREAD_SAFE_STRATEGY=4 -c -I../Core/Inc -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Drivers/CMSIS/Include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Middlewares/Third_Party/FreeRTOS/Source/include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.27.1/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Core/ThreadSafe -I"C:/Users/Daniel/Desktop/M8F93/EDAS/EDAS_APPL/APPL/ActCtrl" -I"C:/Users/Daniel/Desktop/M8F93/EDAS/EDAS_APPL/APPL/ClimaSnH" -I"C:/Users/Daniel/Desktop/M8F93/EDAS/EDAS_APPL/APPL/CrsSnH" -I"C:/Users/Daniel/Desktop/M8F93/EDAS/EDAS_APPL/APPL/DriveCtrl" -I"C:/Users/Daniel/Desktop/M8F93/EDAS/EDAS_APPL/APPL/HmiSnH" -I"C:/Users/Daniel/Desktop/M8F93/EDAS/EDAS_APPL/APPL/OpM" -I"C:/Users/Daniel/Desktop/M8F93/EDAS/EDAS_APPL/BSW" -I"C:/Users/Daniel/Desktop/M8F93/EDAS/EDAS_APPL/BSW/Com/CanH" -I"C:/Users/Daniel/Desktop/M8F93/EDAS/EDAS_APPL/BSW/Com/I2cH" -I"C:/Users/Daniel/Desktop/M8F93/EDAS/EDAS_APPL/BSW/Com/SpiH" -I"C:/Users/Daniel/Desktop/M8F93/EDAS/EDAS_APPL/BSW/Com/UartH" -I"C:/Users/Daniel/Desktop/M8F93/EDAS/EDAS_APPL/BSW/Diag/Dcm" -I"C:/Users/Daniel/Desktop/M8F93/EDAS/EDAS_APPL/BSW/Diag/Dem" -I"C:/Users/Daniel/Desktop/M8F93/EDAS/EDAS_APPL/BSW/Io/Ain" -I"C:/Users/Daniel/Desktop/M8F93/EDAS/EDAS_APPL/BSW/Io/TimH" -I"C:/Users/Daniel/Desktop/M8F93/EDAS/EDAS_APPL/BSW/Io/Dio" -I"C:/Users/Daniel/Desktop/M8F93/EDAS/EDAS_APPL/BSW/Mem" -I"C:/Users/Daniel/Desktop/M8F93/EDAS/EDAS_APPL/BSW/Sys/EcuM" -I"C:/Users/Daniel/Desktop/M8F93/EDAS/EDAS_APPL/BSW/Sys/SysMgr" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-BSW-2f-Io-2f-Dio

clean-BSW-2f-Io-2f-Dio:
	-$(RM) ./BSW/Io/Dio/Dio.cyclo ./BSW/Io/Dio/Dio.d ./BSW/Io/Dio/Dio.o ./BSW/Io/Dio/Dio.su

.PHONY: clean-BSW-2f-Io-2f-Dio

