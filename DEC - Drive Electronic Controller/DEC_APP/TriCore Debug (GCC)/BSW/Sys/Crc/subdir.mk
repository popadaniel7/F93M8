################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/Sys/Crc/Crc.c 

C_DEPS += \
./BSW/Sys/Crc/Crc.d 

OBJS += \
./BSW/Sys/Crc/Crc.o 


# Each subdirectory must supply rules for building sources it contributes
BSW/Sys/Crc/%.o: ../BSW/Sys/Crc/%.c BSW/Sys/Crc/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-elf-gcc -std=c99 "@C:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (GCC)/AURIX_GCC_Compiler-Include_paths__-I_.opt" -Og -g3 -gdwarf-3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc162 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-BSW-2f-Sys-2f-Crc

clean-BSW-2f-Sys-2f-Crc:
	-$(RM) ./BSW/Sys/Crc/Crc.d ./BSW/Sys/Crc/Crc.o

.PHONY: clean-BSW-2f-Sys-2f-Crc

