################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/Mem/Nvm/Nvm.c 

C_DEPS += \
./BSW/Mem/Nvm/Nvm.d 

OBJS += \
./BSW/Mem/Nvm/Nvm.o 


# Each subdirectory must supply rules for building sources it contributes
BSW/Mem/Nvm/%.o: ../BSW/Mem/Nvm/%.c BSW/Mem/Nvm/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-elf-gcc -std=c99 "@C:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (GCC)/AURIX_GCC_Compiler-Include_paths__-I_.opt" -Og -g3 -gdwarf-3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc162 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-BSW-2f-Mem-2f-Nvm

clean-BSW-2f-Mem-2f-Nvm:
	-$(RM) ./BSW/Mem/Nvm/Nvm.d ./BSW/Mem/Nvm/Nvm.o

.PHONY: clean-BSW-2f-Mem-2f-Nvm

