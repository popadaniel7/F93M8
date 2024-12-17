################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FATFS/App/fatfs.c 

C_DEPS += \
./FATFS/App/fatfs.d 

OBJS += \
./FATFS/App/fatfs.o 


# Each subdirectory must supply rules for building sources it contributes
FATFS/App/%.o FATFS/App/%.su FATFS/App/%.cyclo: ../FATFS/App/%.c FATFS/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DSTM32_THREAD_SAFE_STRATEGY=4 -c -I../Core/Inc -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Drivers/CMSIS/Include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Middlewares/Third_Party/FreeRTOS/Source/include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Core/ThreadSafe -I"C:/Users/Daniel/Desktop/FG9322/IDE - Interior Digital Entertainment/IDE_APPL/BSW" -I"C:/Users/Daniel/Desktop/FG9322/IDE - Interior Digital Entertainment/IDE_APPL/APPL/DigitalCluster" -I"C:/Users/Daniel/Desktop/FG9322/IDE - Interior Digital Entertainment/IDE_APPL/BSW/Sys/FsmcH" -I"C:/Users/Daniel/Desktop/FG9322/IDE - Interior Digital Entertainment/IDE_APPL/APPL/DataRecorder" -I"C:/Users/Daniel/Desktop/FG9322/IDE - Interior Digital Entertainment/IDE_APPL/APPL/RevCam" -I../FATFS/Target -I../FATFS/App -I../LWIP/App -I../LWIP/Target -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Middlewares/Third_Party/LwIP/src/include -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Middlewares/Third_Party/LwIP/system -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Middlewares/Third_Party/FatFs/src -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Drivers/BSP/Components/lan8742 -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Middlewares/Third_Party/LwIP/src/include/netif/ppp -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Middlewares/Third_Party/LwIP/src/include/lwip -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Middlewares/Third_Party/LwIP/src/include/lwip/apps -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Middlewares/Third_Party/LwIP/src/include/lwip/priv -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Middlewares/Third_Party/LwIP/src/include/lwip/prot -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Middlewares/Third_Party/LwIP/src/include/netif -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Middlewares/Third_Party/LwIP/src/include/compat/posix -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Middlewares/Third_Party/LwIP/src/include/compat/posix/arpa -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Middlewares/Third_Party/LwIP/src/include/compat/posix/net -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Middlewares/Third_Party/LwIP/src/include/compat/posix/sys -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Middlewares/Third_Party/LwIP/src/include/compat/stdc -IC:/Users/Daniel/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.0/Middlewares/Third_Party/LwIP/system/arch -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-FATFS-2f-App

clean-FATFS-2f-App:
	-$(RM) ./FATFS/App/fatfs.cyclo ./FATFS/App/fatfs.d ./FATFS/App/fatfs.o ./FATFS/App/fatfs.su

.PHONY: clean-FATFS-2f-App

