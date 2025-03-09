################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/Diag/Dcm/Dcm.c 

C_DEPS += \
./BSW/Diag/Dcm/Dcm.d 

OBJS += \
./BSW/Diag/Dcm/Dcm.o 


# Each subdirectory must supply rules for building sources it contributes
BSW/Diag/Dcm/%.o BSW/Diag/Dcm/%.su BSW/Diag/Dcm/%.cyclo: ../BSW/Diag/Dcm/%.c BSW/Diag/Dcm/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DSTM32_THREAD_SAFE_STRATEGY=4 -c -I../Core/Inc -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/DMU - Digital Main Unit/DMU_APPL/BSW" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/DMU - Digital Main Unit/DMU_APPL/APPL/DigitalCluster" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/DMU - Digital Main Unit/DMU_APPL/BSW/Sys/FsmcH" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/DMU - Digital Main Unit/DMU_APPL/APPL/DataRecorder" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/DMU - Digital Main Unit/DMU_APPL/APPL/RevCam" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/DMU - Digital Main Unit/DMU_APPL/BSW/Com/CanH" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/DMU - Digital Main Unit/DMU_APPL/BSW/Diag/Dcm" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/DMU - Digital Main Unit/DMU_APPL/BSW/Diag/Dem" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/DMU - Digital Main Unit/DMU_APPL/BSW/Mem/Nvm" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/DMU - Digital Main Unit/DMU_APPL/BSW/Sys/DcmiH" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/DMU - Digital Main Unit/DMU_APPL/BSW/Sys/EcuM" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/DMU - Digital Main Unit/DMU_APPL/BSW/Com/I2cH" -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Middlewares/Third_Party/FreeRTOS/Source/include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/CMSIS/Include -I../Core/ThreadSafe -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-BSW-2f-Diag-2f-Dcm

clean-BSW-2f-Diag-2f-Dcm:
	-$(RM) ./BSW/Diag/Dcm/Dcm.cyclo ./BSW/Diag/Dcm/Dcm.d ./BSW/Diag/Dcm/Dcm.o ./BSW/Diag/Dcm/Dcm.su

.PHONY: clean-BSW-2f-Diag-2f-Dcm

