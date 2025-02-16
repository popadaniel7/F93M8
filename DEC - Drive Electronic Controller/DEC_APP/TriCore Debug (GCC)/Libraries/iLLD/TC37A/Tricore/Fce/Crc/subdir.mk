################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/iLLD/TC37A/Tricore/Fce/Crc/IfxFce_Crc.c 

C_DEPS += \
./Libraries/iLLD/TC37A/Tricore/Fce/Crc/IfxFce_Crc.d 

OBJS += \
./Libraries/iLLD/TC37A/Tricore/Fce/Crc/IfxFce_Crc.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/iLLD/TC37A/Tricore/Fce/Crc/%.o: ../Libraries/iLLD/TC37A/Tricore/Fce/Crc/%.c Libraries/iLLD/TC37A/Tricore/Fce/Crc/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-elf-gcc -std=c99 "@C:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (GCC)/AURIX_GCC_Compiler-Include_paths__-I_.opt" -Og -g3 -gdwarf-3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc162 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Libraries-2f-iLLD-2f-TC37A-2f-Tricore-2f-Fce-2f-Crc

clean-Libraries-2f-iLLD-2f-TC37A-2f-Tricore-2f-Fce-2f-Crc:
	-$(RM) ./Libraries/iLLD/TC37A/Tricore/Fce/Crc/IfxFce_Crc.d ./Libraries/iLLD/TC37A/Tricore/Fce/Crc/IfxFce_Crc.o

.PHONY: clean-Libraries-2f-iLLD-2f-TC37A-2f-Tricore-2f-Fce-2f-Crc

