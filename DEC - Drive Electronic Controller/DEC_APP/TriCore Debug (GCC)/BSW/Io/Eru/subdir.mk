################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/Io/Eru/Eru.c 

C_DEPS += \
./BSW/Io/Eru/Eru.d 

OBJS += \
./BSW/Io/Eru/Eru.o 


# Each subdirectory must supply rules for building sources it contributes
BSW/Io/Eru/%.o: ../BSW/Io/Eru/%.c BSW/Io/Eru/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-elf-gcc -std=c99 "@C:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (GCC)/AURIX_GCC_Compiler-Include_paths__-I_.opt" -Og -g3 -gdwarf-3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc162 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-BSW-2f-Io-2f-Eru

clean-BSW-2f-Io-2f-Eru:
	-$(RM) ./BSW/Io/Eru/Eru.d ./BSW/Io/Eru/Eru.o

.PHONY: clean-BSW-2f-Io-2f-Eru

