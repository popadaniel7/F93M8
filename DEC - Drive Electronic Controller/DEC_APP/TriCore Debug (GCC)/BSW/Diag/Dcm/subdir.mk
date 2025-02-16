################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/Diag/Dcm/Dcm.c 

C_DEPS += \
./BSW/Diag/Dcm/Dcm.d 

OBJS += \
./BSW/Diag/Dcm/Dcm.o 


# Each subdirectory must supply rules for building sources it contributes
BSW/Diag/Dcm/%.o: ../BSW/Diag/Dcm/%.c BSW/Diag/Dcm/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-elf-gcc -std=c99 "@C:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (GCC)/AURIX_GCC_Compiler-Include_paths__-I_.opt" -Og -g3 -gdwarf-3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc162 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-BSW-2f-Diag-2f-Dcm

clean-BSW-2f-Diag-2f-Dcm:
	-$(RM) ./BSW/Diag/Dcm/Dcm.d ./BSW/Diag/Dcm/Dcm.o

.PHONY: clean-BSW-2f-Diag-2f-Dcm

