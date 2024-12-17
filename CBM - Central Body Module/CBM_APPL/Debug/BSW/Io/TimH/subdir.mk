################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/Io/TimH/TimH.c 

C_DEPS += \
./BSW/Io/TimH/TimH.d 

OBJS += \
./BSW/Io/TimH/TimH.o 


# Each subdirectory must supply rules for building sources it contributes
BSW/Io/TimH/%.o BSW/Io/TimH/%.su BSW/Io/TimH/%.cyclo: ../BSW/Io/TimH/%.c BSW/Io/TimH/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -DSTM32_THREAD_SAFE_STRATEGY=4 -c -I../Core/Inc -I"C:/Users/Daniel/Desktop/FG9322/CBM - Central Body Module/CBM_APPL/BSW/Com/UartH" -I"C:/Users/Daniel/Desktop/FG9322/CBM - Central Body Module/CBM_APPL/BSW/Com/Xcp" -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Middlewares/Third_Party/FreeRTOS/Source/include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/CMSIS/Include -I"C:/Users/Daniel/Desktop/FG9322/CBM - Central Body Module/CBM_APPL/APPL/ActCtrl" -I"C:/Users/Daniel/Desktop/FG9322/CBM - Central Body Module/CBM_APPL/BSW" -I"C:/Users/Daniel/Desktop/FG9322/CBM - Central Body Module/CBM_APPL/BSW/Diag/Dcm" -I"C:/Users/Daniel/Desktop/FG9322/CBM - Central Body Module/CBM_APPL/BSW/Diag/Dem" -I"C:/Users/Daniel/Desktop/FG9322/CBM - Central Body Module/CBM_APPL/BSW/Io/Ain" -I"C:/Users/Daniel/Desktop/FG9322/CBM - Central Body Module/CBM_APPL/BSW/Io/TimH" -I"C:/Users/Daniel/Desktop/FG9322/CBM - Central Body Module/CBM_APPL/BSW/Mem" -I"C:/Users/Daniel/Desktop/FG9322/CBM - Central Body Module/CBM_APPL/BSW/Sys/EcuM" -I"C:/Users/Daniel/Desktop/FG9322/CBM - Central Body Module/CBM_APPL/BSW/Com/CanSpi" -I"C:/Users/Daniel/Desktop/FG9322/CBM - Central Body Module/CBM_APPL/APPL/InputCtrl" -I../Core/ThreadSafe -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-BSW-2f-Io-2f-TimH

clean-BSW-2f-Io-2f-TimH:
	-$(RM) ./BSW/Io/TimH/TimH.cyclo ./BSW/Io/TimH/TimH.d ./BSW/Io/TimH/TimH.o ./BSW/Io/TimH/TimH.su

.PHONY: clean-BSW-2f-Io-2f-TimH

