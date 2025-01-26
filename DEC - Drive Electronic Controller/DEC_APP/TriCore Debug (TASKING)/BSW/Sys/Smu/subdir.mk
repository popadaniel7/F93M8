################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../BSW/Sys/Smu/Smu.c" 

COMPILED_SRCS += \
"BSW/Sys/Smu/Smu.src" 

C_DEPS += \
"./BSW/Sys/Smu/Smu.d" 

OBJS += \
"BSW/Sys/Smu/Smu.o" 


# Each subdirectory must supply rules for building sources it contributes
"BSW/Sys/Smu/Smu.src":"../BSW/Sys/Smu/Smu.c" "BSW/Sys/Smu/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/Smu/Smu.o":"BSW/Sys/Smu/Smu.src" "BSW/Sys/Smu/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-Sys-2f-Smu

clean-BSW-2f-Sys-2f-Smu:
	-$(RM) ./BSW/Sys/Smu/Smu.d ./BSW/Sys/Smu/Smu.o ./BSW/Sys/Smu/Smu.src

.PHONY: clean-BSW-2f-Sys-2f-Smu

