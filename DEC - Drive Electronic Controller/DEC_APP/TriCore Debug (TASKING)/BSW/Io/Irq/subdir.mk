################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../BSW/Io/Irq/Irq.c" 

COMPILED_SRCS += \
"BSW/Io/Irq/Irq.src" 

C_DEPS += \
"./BSW/Io/Irq/Irq.d" 

OBJS += \
"BSW/Io/Irq/Irq.o" 


# Each subdirectory must supply rules for building sources it contributes
"BSW/Io/Irq/Irq.src":"../BSW/Io/Irq/Irq.c" "BSW/Io/Irq/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Io/Irq/Irq.o":"BSW/Io/Irq/Irq.src" "BSW/Io/Irq/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-Io-2f-Irq

clean-BSW-2f-Io-2f-Irq:
	-$(RM) ./BSW/Io/Irq/Irq.d ./BSW/Io/Irq/Irq.o ./BSW/Io/Irq/Irq.src

.PHONY: clean-BSW-2f-Io-2f-Irq

