################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../BSW/Sys/McuSm/McuSm.c" 

COMPILED_SRCS += \
"BSW/Sys/McuSm/McuSm.src" 

C_DEPS += \
"./BSW/Sys/McuSm/McuSm.d" 

OBJS += \
"BSW/Sys/McuSm/McuSm.o" 


# Each subdirectory must supply rules for building sources it contributes
"BSW/Sys/McuSm/McuSm.src":"../BSW/Sys/McuSm/McuSm.c" "BSW/Sys/McuSm/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/McuSm/McuSm.o":"BSW/Sys/McuSm/McuSm.src" "BSW/Sys/McuSm/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-Sys-2f-McuSm

clean-BSW-2f-Sys-2f-McuSm:
	-$(RM) ./BSW/Sys/McuSm/McuSm.d ./BSW/Sys/McuSm/McuSm.o ./BSW/Sys/McuSm/McuSm.src

.PHONY: clean-BSW-2f-Sys-2f-McuSm

