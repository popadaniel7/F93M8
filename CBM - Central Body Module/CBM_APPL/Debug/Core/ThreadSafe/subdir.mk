################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/ThreadSafe/newlib_lock_glue.c 

C_DEPS += \
./Core/ThreadSafe/newlib_lock_glue.d 

OBJS += \
./Core/ThreadSafe/newlib_lock_glue.o 


# Each subdirectory must supply rules for building sources it contributes
Core/ThreadSafe/%.o Core/ThreadSafe/%.su Core/ThreadSafe/%.cyclo: ../Core/ThreadSafe/%.c Core/ThreadSafe/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -DSTM32_THREAD_SAFE_STRATEGY=4 -c -I../Core/Inc -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/CBM - Central Body Module/CBM_APPL/BSW/Com/UartH" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/CBM - Central Body Module/CBM_APPL/BSW/Com/Xcp" -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Middlewares/Third_Party/FreeRTOS/Source/include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/CMSIS/Include -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/CBM - Central Body Module/CBM_APPL/APPL/ActCtrl" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/CBM - Central Body Module/CBM_APPL/BSW" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/CBM - Central Body Module/CBM_APPL/BSW/Diag/Dcm" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/CBM - Central Body Module/CBM_APPL/BSW/Diag/Dem" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/CBM - Central Body Module/CBM_APPL/BSW/Io/Ain" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/CBM - Central Body Module/CBM_APPL/BSW/Io/TimH" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/CBM - Central Body Module/CBM_APPL/BSW/Mem" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/CBM - Central Body Module/CBM_APPL/BSW/Sys/EcuM" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/CBM - Central Body Module/CBM_APPL/BSW/Com/CanSpi" -I"C:/Users/Daniel/Desktop/FG9326M8GTEI4/CBM - Central Body Module/CBM_APPL/APPL/InputCtrl" -I../Core/ThreadSafe -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-ThreadSafe

clean-Core-2f-ThreadSafe:
	-$(RM) ./Core/ThreadSafe/newlib_lock_glue.cyclo ./Core/ThreadSafe/newlib_lock_glue.d ./Core/ThreadSafe/newlib_lock_glue.o ./Core/ThreadSafe/newlib_lock_glue.su

.PHONY: clean-Core-2f-ThreadSafe

