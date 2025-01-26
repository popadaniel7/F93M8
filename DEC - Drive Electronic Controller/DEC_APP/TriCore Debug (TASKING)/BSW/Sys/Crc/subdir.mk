################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../BSW/Sys/Crc/Crc.c" 

COMPILED_SRCS += \
"BSW/Sys/Crc/Crc.src" 

C_DEPS += \
"./BSW/Sys/Crc/Crc.d" 

OBJS += \
"BSW/Sys/Crc/Crc.o" 


# Each subdirectory must supply rules for building sources it contributes
"BSW/Sys/Crc/Crc.src":"../BSW/Sys/Crc/Crc.c" "BSW/Sys/Crc/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/Crc/Crc.o":"BSW/Sys/Crc/Crc.src" "BSW/Sys/Crc/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-Sys-2f-Crc

clean-BSW-2f-Sys-2f-Crc:
	-$(RM) ./BSW/Sys/Crc/Crc.d ./BSW/Sys/Crc/Crc.o ./BSW/Sys/Crc/Crc.src

.PHONY: clean-BSW-2f-Sys-2f-Crc

