################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SCR/main.c 

OBJS += \
./SCR/main.o 


# Each subdirectory must supply rules for building sources it contributes
SCR/%.o: ../SCR/%.c SCR/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: SDCC Compiler'
	sdcc --asm-scr -c --model-large --std-sdcc99 --nooverlay --no-peep-return --opt-code-speed  "$<" -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-SCR

clean-SCR:
	-$(RM) ./SCR/main.o

.PHONY: clean-SCR

