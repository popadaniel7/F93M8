################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/DiagMaster/DiagMaster.c 

C_DEPS += \
./APP/DiagMaster/DiagMaster.d 

OBJS += \
./APP/DiagMaster/DiagMaster.o 


# Each subdirectory must supply rules for building sources it contributes
APP/DiagMaster/%.o: ../APP/DiagMaster/%.c APP/DiagMaster/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-elf-gcc -std=c99 "@C:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (GCC)/AURIX_GCC_Compiler-Include_paths__-I_.opt" -Og -g3 -gdwarf-3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc162 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-APP-2f-DiagMaster

clean-APP-2f-DiagMaster:
	-$(RM) ./APP/DiagMaster/DiagMaster.d ./APP/DiagMaster/DiagMaster.o

.PHONY: clean-APP-2f-DiagMaster

