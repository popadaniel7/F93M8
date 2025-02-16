################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/Sys/Bsw_Wrapper/Bsw_Wrapper.c 

C_DEPS += \
./BSW/Sys/Bsw_Wrapper/Bsw_Wrapper.d 

OBJS += \
./BSW/Sys/Bsw_Wrapper/Bsw_Wrapper.o 


# Each subdirectory must supply rules for building sources it contributes
BSW/Sys/Bsw_Wrapper/%.o: ../BSW/Sys/Bsw_Wrapper/%.c BSW/Sys/Bsw_Wrapper/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-elf-gcc -std=c99 "@C:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (GCC)/AURIX_GCC_Compiler-Include_paths__-I_.opt" -Og -g3 -gdwarf-3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc162 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-BSW-2f-Sys-2f-Bsw_Wrapper

clean-BSW-2f-Sys-2f-Bsw_Wrapper:
	-$(RM) ./BSW/Sys/Bsw_Wrapper/Bsw_Wrapper.d ./BSW/Sys/Bsw_Wrapper/Bsw_Wrapper.o

.PHONY: clean-BSW-2f-Sys-2f-Bsw_Wrapper

