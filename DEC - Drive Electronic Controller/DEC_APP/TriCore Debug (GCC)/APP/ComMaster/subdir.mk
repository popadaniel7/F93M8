################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/ComMaster/ComMaster.c 

C_DEPS += \
./APP/ComMaster/ComMaster.d 

OBJS += \
./APP/ComMaster/ComMaster.o 


# Each subdirectory must supply rules for building sources it contributes
APP/ComMaster/%.o: ../APP/ComMaster/%.c APP/ComMaster/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-elf-gcc -std=c99 "@C:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (GCC)/AURIX_GCC_Compiler-Include_paths__-I_.opt" -Og -g3 -gdwarf-3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc162 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-APP-2f-ComMaster

clean-APP-2f-ComMaster:
	-$(RM) ./APP/ComMaster/ComMaster.d ./APP/ComMaster/ComMaster.o

.PHONY: clean-APP-2f-ComMaster

