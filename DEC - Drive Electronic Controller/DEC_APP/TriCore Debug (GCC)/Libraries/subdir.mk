################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/aurix_pin_mappings.c 

C_DEPS += \
./Libraries/aurix_pin_mappings.d 

OBJS += \
./Libraries/aurix_pin_mappings.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/%.o: ../Libraries/%.c Libraries/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-elf-gcc -std=c99 "@C:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (GCC)/AURIX_GCC_Compiler-Include_paths__-I_.opt" -Og -g3 -gdwarf-3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc162 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Libraries

clean-Libraries:
	-$(RM) ./Libraries/aurix_pin_mappings.d ./Libraries/aurix_pin_mappings.o

.PHONY: clean-Libraries

