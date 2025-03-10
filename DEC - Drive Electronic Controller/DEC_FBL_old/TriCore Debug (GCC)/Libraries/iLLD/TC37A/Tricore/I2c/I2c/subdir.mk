################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/iLLD/TC37A/Tricore/I2c/I2c/IfxI2c_I2c.c 

C_DEPS += \
./Libraries/iLLD/TC37A/Tricore/I2c/I2c/IfxI2c_I2c.d 

OBJS += \
./Libraries/iLLD/TC37A/Tricore/I2c/I2c/IfxI2c_I2c.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/iLLD/TC37A/Tricore/I2c/I2c/%.o: ../Libraries/iLLD/TC37A/Tricore/I2c/I2c/%.c Libraries/iLLD/TC37A/Tricore/I2c/I2c/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-elf-gcc -std=c99 "@C:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_FBL/TriCore Debug (GCC)/AURIX_GCC_Compiler-Include_paths__-I_.opt" -Og -g3 -gdwarf-3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc162 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Libraries-2f-iLLD-2f-TC37A-2f-Tricore-2f-I2c-2f-I2c

clean-Libraries-2f-iLLD-2f-TC37A-2f-Tricore-2f-I2c-2f-I2c:
	-$(RM) ./Libraries/iLLD/TC37A/Tricore/I2c/I2c/IfxI2c_I2c.d ./Libraries/iLLD/TC37A/Tricore/I2c/I2c/IfxI2c_I2c.o

.PHONY: clean-Libraries-2f-iLLD-2f-TC37A-2f-Tricore-2f-I2c-2f-I2c

