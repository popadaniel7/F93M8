################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/Infra/Ssw/TC37A/Tricore/Ifx_Ssw_Infra.c \
../Libraries/Infra/Ssw/TC37A/Tricore/Ifx_Ssw_Tc0.c \
../Libraries/Infra/Ssw/TC37A/Tricore/Ifx_Ssw_Tc1.c \
../Libraries/Infra/Ssw/TC37A/Tricore/Ifx_Ssw_Tc2.c 

C_DEPS += \
./Libraries/Infra/Ssw/TC37A/Tricore/Ifx_Ssw_Infra.d \
./Libraries/Infra/Ssw/TC37A/Tricore/Ifx_Ssw_Tc0.d \
./Libraries/Infra/Ssw/TC37A/Tricore/Ifx_Ssw_Tc1.d \
./Libraries/Infra/Ssw/TC37A/Tricore/Ifx_Ssw_Tc2.d 

OBJS += \
./Libraries/Infra/Ssw/TC37A/Tricore/Ifx_Ssw_Infra.o \
./Libraries/Infra/Ssw/TC37A/Tricore/Ifx_Ssw_Tc0.o \
./Libraries/Infra/Ssw/TC37A/Tricore/Ifx_Ssw_Tc1.o \
./Libraries/Infra/Ssw/TC37A/Tricore/Ifx_Ssw_Tc2.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Infra/Ssw/TC37A/Tricore/%.o: ../Libraries/Infra/Ssw/TC37A/Tricore/%.c Libraries/Infra/Ssw/TC37A/Tricore/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-elf-gcc -std=c99 "@C:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_FBL/TriCore Debug (GCC)/AURIX_GCC_Compiler-Include_paths__-I_.opt" -Og -g3 -gdwarf-3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc162 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Libraries-2f-Infra-2f-Ssw-2f-TC37A-2f-Tricore

clean-Libraries-2f-Infra-2f-Ssw-2f-TC37A-2f-Tricore:
	-$(RM) ./Libraries/Infra/Ssw/TC37A/Tricore/Ifx_Ssw_Infra.d ./Libraries/Infra/Ssw/TC37A/Tricore/Ifx_Ssw_Infra.o ./Libraries/Infra/Ssw/TC37A/Tricore/Ifx_Ssw_Tc0.d ./Libraries/Infra/Ssw/TC37A/Tricore/Ifx_Ssw_Tc0.o ./Libraries/Infra/Ssw/TC37A/Tricore/Ifx_Ssw_Tc1.d ./Libraries/Infra/Ssw/TC37A/Tricore/Ifx_Ssw_Tc1.o ./Libraries/Infra/Ssw/TC37A/Tricore/Ifx_Ssw_Tc2.d ./Libraries/Infra/Ssw/TC37A/Tricore/Ifx_Ssw_Tc2.o

.PHONY: clean-Libraries-2f-Infra-2f-Ssw-2f-TC37A-2f-Tricore

