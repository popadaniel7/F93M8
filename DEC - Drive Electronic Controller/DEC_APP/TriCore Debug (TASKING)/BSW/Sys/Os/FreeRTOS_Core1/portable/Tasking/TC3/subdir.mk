################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../BSW/Sys/Os/FreeRTOS_Core1/portable/Tasking/TC3/port.c" 

COMPILED_SRCS += \
"BSW/Sys/Os/FreeRTOS_Core1/portable/Tasking/TC3/port.src" 

C_DEPS += \
"./BSW/Sys/Os/FreeRTOS_Core1/portable/Tasking/TC3/port.d" 

OBJS += \
"BSW/Sys/Os/FreeRTOS_Core1/portable/Tasking/TC3/port.o" 


# Each subdirectory must supply rules for building sources it contributes
"BSW/Sys/Os/FreeRTOS_Core1/portable/Tasking/TC3/port.src":"../BSW/Sys/Os/FreeRTOS_Core1/portable/Tasking/TC3/port.c" "BSW/Sys/Os/FreeRTOS_Core1/portable/Tasking/TC3/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/Os/FreeRTOS_Core1/portable/Tasking/TC3/port.o":"BSW/Sys/Os/FreeRTOS_Core1/portable/Tasking/TC3/port.src" "BSW/Sys/Os/FreeRTOS_Core1/portable/Tasking/TC3/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-Sys-2f-Os-2f-FreeRTOS_Core1-2f-portable-2f-Tasking-2f-TC3

clean-BSW-2f-Sys-2f-Os-2f-FreeRTOS_Core1-2f-portable-2f-Tasking-2f-TC3:
	-$(RM) ./BSW/Sys/Os/FreeRTOS_Core1/portable/Tasking/TC3/port.d ./BSW/Sys/Os/FreeRTOS_Core1/portable/Tasking/TC3/port.o ./BSW/Sys/Os/FreeRTOS_Core1/portable/Tasking/TC3/port.src

.PHONY: clean-BSW-2f-Sys-2f-Os-2f-FreeRTOS_Core1-2f-portable-2f-Tasking-2f-TC3

