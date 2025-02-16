################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/iLLD/TC37A/Tricore/Iom/Std/IfxIom.c 

C_DEPS += \
./Libraries/iLLD/TC37A/Tricore/Iom/Std/IfxIom.d 

OBJS += \
./Libraries/iLLD/TC37A/Tricore/Iom/Std/IfxIom.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/iLLD/TC37A/Tricore/Iom/Std/%.o: ../Libraries/iLLD/TC37A/Tricore/Iom/Std/%.c Libraries/iLLD/TC37A/Tricore/Iom/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-elf-gcc -std=c99 "@C:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (GCC)/AURIX_GCC_Compiler-Include_paths__-I_.opt" -Og -g3 -gdwarf-3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc162 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Libraries-2f-iLLD-2f-TC37A-2f-Tricore-2f-Iom-2f-Std

clean-Libraries-2f-iLLD-2f-TC37A-2f-Tricore-2f-Iom-2f-Std:
	-$(RM) ./Libraries/iLLD/TC37A/Tricore/Iom/Std/IfxIom.d ./Libraries/iLLD/TC37A/Tricore/Iom/Std/IfxIom.o

.PHONY: clean-Libraries-2f-iLLD-2f-TC37A-2f-Tricore-2f-Iom-2f-Std

