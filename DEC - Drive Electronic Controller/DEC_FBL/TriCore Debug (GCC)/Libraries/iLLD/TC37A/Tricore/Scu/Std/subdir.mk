################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuCcu.c \
../Libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuEru.c \
../Libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuLbist.c \
../Libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuRcu.c \
../Libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuWdt.c 

C_DEPS += \
./Libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuCcu.d \
./Libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuEru.d \
./Libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuLbist.d \
./Libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuRcu.d \
./Libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuWdt.d 

OBJS += \
./Libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuCcu.o \
./Libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuEru.o \
./Libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuLbist.o \
./Libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuRcu.o \
./Libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuWdt.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/iLLD/TC37A/Tricore/Scu/Std/%.o: ../Libraries/iLLD/TC37A/Tricore/Scu/Std/%.c Libraries/iLLD/TC37A/Tricore/Scu/Std/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-elf-gcc -std=c99 "@C:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_FBL/TriCore Debug (GCC)/AURIX_GCC_Compiler-Include_paths__-I_.opt" -Og -g3 -gdwarf-3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc162 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Libraries-2f-iLLD-2f-TC37A-2f-Tricore-2f-Scu-2f-Std

clean-Libraries-2f-iLLD-2f-TC37A-2f-Tricore-2f-Scu-2f-Std:
	-$(RM) ./Libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuCcu.d ./Libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuCcu.o ./Libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuEru.d ./Libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuEru.o ./Libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuLbist.d ./Libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuLbist.o ./Libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuRcu.d ./Libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuRcu.o ./Libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuWdt.d ./Libraries/iLLD/TC37A/Tricore/Scu/Std/IfxScuWdt.o

.PHONY: clean-Libraries-2f-iLLD-2f-TC37A-2f-Tricore-2f-Scu-2f-Std

