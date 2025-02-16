################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/Io/Ain/Ain.c \
../BSW/Io/Ain/Ain_Filtering.c 

C_DEPS += \
./BSW/Io/Ain/Ain.d \
./BSW/Io/Ain/Ain_Filtering.d 

OBJS += \
./BSW/Io/Ain/Ain.o \
./BSW/Io/Ain/Ain_Filtering.o 


# Each subdirectory must supply rules for building sources it contributes
BSW/Io/Ain/%.o: ../BSW/Io/Ain/%.c BSW/Io/Ain/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-elf-gcc -std=c99 "@C:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (GCC)/AURIX_GCC_Compiler-Include_paths__-I_.opt" -Og -g3 -gdwarf-3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc162 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-BSW-2f-Io-2f-Ain

clean-BSW-2f-Io-2f-Ain:
	-$(RM) ./BSW/Io/Ain/Ain.d ./BSW/Io/Ain/Ain.o ./BSW/Io/Ain/Ain_Filtering.d ./BSW/Io/Ain/Ain_Filtering.o

.PHONY: clean-BSW-2f-Io-2f-Ain

