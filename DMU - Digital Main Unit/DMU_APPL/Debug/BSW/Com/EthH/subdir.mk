################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/Com/EthH/EthH.c 

C_DEPS += \
./BSW/Com/EthH/EthH.d 

OBJS += \
./BSW/Com/EthH/EthH.o 


# Each subdirectory must supply rules for building sources it contributes
BSW/Com/EthH/%.o BSW/Com/EthH/%.su BSW/Com/EthH/%.cyclo: ../BSW/Com/EthH/%.c BSW/Com/EthH/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DSTM32_THREAD_SAFE_STRATEGY=4 -c -I../Core/Inc -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Drivers/CMSIS/Include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Middlewares/Third_Party/FreeRTOS/Source/include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Core/ThreadSafe -I"C:/Users/Daniel/Desktop/FG9322/IDE - Interior Digital Entertainment/IDE_APPL/BSW" -I"C:/Users/Daniel/Desktop/FG9322/IDE - Interior Digital Entertainment/IDE_APPL/APPL/DigitalCluster" -I"C:/Users/Daniel/Desktop/FG9322/IDE - Interior Digital Entertainment/IDE_APPL/BSW/Sys/FsmcH" -I"C:/Users/Daniel/Desktop/FG9322/IDE - Interior Digital Entertainment/IDE_APPL/APPL/DataRecorder" -I"C:/Users/Daniel/Desktop/FG9322/IDE - Interior Digital Entertainment/IDE_APPL/APPL/RevCam" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-BSW-2f-Com-2f-EthH

clean-BSW-2f-Com-2f-EthH:
	-$(RM) ./BSW/Com/EthH/EthH.cyclo ./BSW/Com/EthH/EthH.d ./BSW/Com/EthH/EthH.o ./BSW/Com/EthH/EthH.su

.PHONY: clean-BSW-2f-Com-2f-EthH

