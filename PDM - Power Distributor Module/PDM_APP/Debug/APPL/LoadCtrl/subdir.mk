################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APPL/LoadCtrl/LoadCtrl.c 

C_DEPS += \
./APPL/LoadCtrl/LoadCtrl.d 

OBJS += \
./APPL/LoadCtrl/LoadCtrl.o 


# Each subdirectory must supply rules for building sources it contributes
APPL/LoadCtrl/%.o APPL/LoadCtrl/%.su APPL/LoadCtrl/%.cyclo: ../APPL/LoadCtrl/%.c APPL/LoadCtrl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -DSTM32_THREAD_SAFE_STRATEGY=4 -c -I../Core/Inc -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/PDM - Power Distributor Module/PDM_APP/BSW" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/PDM - Power Distributor Module/PDM_APP/APPL/LoadCtrl" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/PDM - Power Distributor Module/PDM_APP/BSW/Com/CanH" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/PDM - Power Distributor Module/PDM_APP/BSW/Io/Ain" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/PDM - Power Distributor Module/PDM_APP/BSW/Sys/EcuM" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/PDM - Power Distributor Module/PDM_APP/BSW/Diag/Dcm" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/PDM - Power Distributor Module/PDM_APP/BSW/Diag/Dem" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/PDM - Power Distributor Module/PDM_APP/BSW/Nvm" -I../Core/ThreadSafe -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Drivers/STM32F1xx_HAL_Driver/Inc -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Middlewares/Third_Party/FreeRTOS/Source/include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Drivers/CMSIS/Device/ST/STM32F1xx/Include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.6/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-APPL-2f-LoadCtrl

clean-APPL-2f-LoadCtrl:
	-$(RM) ./APPL/LoadCtrl/LoadCtrl.cyclo ./APPL/LoadCtrl/LoadCtrl.d ./APPL/LoadCtrl/LoadCtrl.o ./APPL/LoadCtrl/LoadCtrl.su

.PHONY: clean-APPL-2f-LoadCtrl

