################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/Diag/Dem/Dem.c 

C_DEPS += \
./BSW/Diag/Dem/Dem.d 

OBJS += \
./BSW/Diag/Dem/Dem.o 


# Each subdirectory must supply rules for building sources it contributes
BSW/Diag/Dem/%.o BSW/Diag/Dem/%.su BSW/Diag/Dem/%.cyclo: ../BSW/Diag/Dem/%.c BSW/Diag/Dem/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -DSTM32_THREAD_SAFE_STRATEGY=4 -c -I../Core/Inc -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/CBM - Central Body Module/CBM_APPL/BSW/Com/UartH" -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Middlewares/Third_Party/FreeRTOS/Source/include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/CMSIS/Include -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/CBM - Central Body Module/CBM_APPL/APPL/ActCtrl" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/CBM - Central Body Module/CBM_APPL/BSW" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/CBM - Central Body Module/CBM_APPL/BSW/Diag/Dcm" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/CBM - Central Body Module/CBM_APPL/BSW/Diag/Dem" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/CBM - Central Body Module/CBM_APPL/BSW/Io/Ain" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/CBM - Central Body Module/CBM_APPL/BSW/Io/TimH" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/CBM - Central Body Module/CBM_APPL/BSW/Mem" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/CBM - Central Body Module/CBM_APPL/BSW/Sys/EcuM" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/CBM - Central Body Module/CBM_APPL/BSW/Com/CanSpi" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/CBM - Central Body Module/CBM_APPL/APPL/InputCtrl" -I../Core/ThreadSafe -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-BSW-2f-Diag-2f-Dem

clean-BSW-2f-Diag-2f-Dem:
	-$(RM) ./BSW/Diag/Dem/Dem.cyclo ./BSW/Diag/Dem/Dem.d ./BSW/Diag/Dem/Dem.o ./BSW/Diag/Dem/Dem.su

.PHONY: clean-BSW-2f-Diag-2f-Dem

