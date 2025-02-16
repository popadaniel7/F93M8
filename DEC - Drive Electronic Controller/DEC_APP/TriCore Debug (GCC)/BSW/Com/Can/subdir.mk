################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/Com/Can/Can.c 

C_DEPS += \
./BSW/Com/Can/Can.d 

OBJS += \
./BSW/Com/Can/Can.o 


# Each subdirectory must supply rules for building sources it contributes
BSW/Com/Can/%.o: ../BSW/Com/Can/%.c BSW/Com/Can/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-elf-gcc -std=c99 "@C:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (GCC)/AURIX_GCC_Compiler-Include_paths__-I_.opt" -Og -g3 -gdwarf-3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc162 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-BSW-2f-Com-2f-Can

clean-BSW-2f-Com-2f-Can:
	-$(RM) ./BSW/Com/Can/Can.d ./BSW/Com/Can/Can.o

.PHONY: clean-BSW-2f-Com-2f-Can

