################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/EnergyMgmt/EnergyMgmt.c 

C_DEPS += \
./APP/EnergyMgmt/EnergyMgmt.d 

OBJS += \
./APP/EnergyMgmt/EnergyMgmt.o 


# Each subdirectory must supply rules for building sources it contributes
APP/EnergyMgmt/%.o: ../APP/EnergyMgmt/%.c APP/EnergyMgmt/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-elf-gcc -std=c99 "@C:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (GCC)/AURIX_GCC_Compiler-Include_paths__-I_.opt" -Og -g3 -gdwarf-3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc162 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-APP-2f-EnergyMgmt

clean-APP-2f-EnergyMgmt:
	-$(RM) ./APP/EnergyMgmt/EnergyMgmt.d ./APP/EnergyMgmt/EnergyMgmt.o

.PHONY: clean-APP-2f-EnergyMgmt

