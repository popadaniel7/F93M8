################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Xcp/Xcp.c 

C_DEPS += \
./Xcp/Xcp.d 

OBJS += \
./Xcp/Xcp.o 


# Each subdirectory must supply rules for building sources it contributes
Xcp/%.o Xcp/%.su Xcp/%.cyclo: ../Xcp/%.c Xcp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -DSTM32_THREAD_SAFE_STRATEGY=4 -c -I../Core/Inc -I../Core/ThreadSafe -I"C:/Users/Daniel/Desktop/FG9322/EDAS - Electronic Data Acquisition System/EDAS_APPL/APPL/ActCtrl" -I"C:/Users/Daniel/Desktop/FG9322/EDAS - Electronic Data Acquisition System/EDAS_APPL/BSW" -I"C:/Users/Daniel/Desktop/FG9322/EDAS - Electronic Data Acquisition System/EDAS_APPL/BSW/Diag/Dcm" -I"C:/Users/Daniel/Desktop/FG9322/EDAS - Electronic Data Acquisition System/EDAS_APPL/BSW/Diag/Dem" -I"C:/Users/Daniel/Desktop/FG9322/EDAS - Electronic Data Acquisition System/EDAS_APPL/BSW/Io/Ain" -I"C:/Users/Daniel/Desktop/FG9322/EDAS - Electronic Data Acquisition System/EDAS_APPL/BSW/Io/TimH" -I"C:/Users/Daniel/Desktop/FG9322/EDAS - Electronic Data Acquisition System/EDAS_APPL/BSW/Mem" -I"C:/Users/Daniel/Desktop/FG9322/EDAS - Electronic Data Acquisition System/EDAS_APPL/BSW/Sys/EcuM" -I"C:/Users/Daniel/Desktop/FG9322/EDAS - Electronic Data Acquisition System/EDAS_APPL/BSW/Com/CanSpi" -I"C:/Users/Daniel/Desktop/FG9322/EDAS - Electronic Data Acquisition System/EDAS_APPL/APPL/InputCtrl" -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Middlewares/Third_Party/FreeRTOS/Source/include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Drivers/CMSIS/Include -I"C:/Users/Daniel/Desktop/FG9322/EDAS - Electronic Data Acquisition System/EDAS_APPL/BSW/Com/UartH" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Xcp

clean-Xcp:
	-$(RM) ./Xcp/Xcp.cyclo ./Xcp/Xcp.d ./Xcp/Xcp.o ./Xcp/Xcp.su

.PHONY: clean-Xcp

