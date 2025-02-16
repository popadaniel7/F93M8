################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/Io/Dma/Dma.c 

C_DEPS += \
./BSW/Io/Dma/Dma.d 

OBJS += \
./BSW/Io/Dma/Dma.o 


# Each subdirectory must supply rules for building sources it contributes
BSW/Io/Dma/%.o: ../BSW/Io/Dma/%.c BSW/Io/Dma/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-elf-gcc -std=c99 "@C:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (GCC)/AURIX_GCC_Compiler-Include_paths__-I_.opt" -Og -g3 -gdwarf-3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc162 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-BSW-2f-Io-2f-Dma

clean-BSW-2f-Io-2f-Dma:
	-$(RM) ./BSW/Io/Dma/Dma.d ./BSW/Io/Dma/Dma.o

.PHONY: clean-BSW-2f-Io-2f-Dma

