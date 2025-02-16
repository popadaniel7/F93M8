################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/Io/Gtm/Gtm_Atom.c \
../BSW/Io/Gtm/Gtm_Pwm.c 

C_DEPS += \
./BSW/Io/Gtm/Gtm_Atom.d \
./BSW/Io/Gtm/Gtm_Pwm.d 

OBJS += \
./BSW/Io/Gtm/Gtm_Atom.o \
./BSW/Io/Gtm/Gtm_Pwm.o 


# Each subdirectory must supply rules for building sources it contributes
BSW/Io/Gtm/%.o: ../BSW/Io/Gtm/%.c BSW/Io/Gtm/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-elf-gcc -std=c99 "@C:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (GCC)/AURIX_GCC_Compiler-Include_paths__-I_.opt" -Og -g3 -gdwarf-3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc162 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-BSW-2f-Io-2f-Gtm

clean-BSW-2f-Io-2f-Gtm:
	-$(RM) ./BSW/Io/Gtm/Gtm_Atom.d ./BSW/Io/Gtm/Gtm_Atom.o ./BSW/Io/Gtm/Gtm_Pwm.d ./BSW/Io/Gtm/Gtm_Pwm.o

.PHONY: clean-BSW-2f-Io-2f-Gtm

