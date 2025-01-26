################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../BSW/Sys/Bsw_Wrapper/Bsw_Wrapper.c" 

COMPILED_SRCS += \
"BSW/Sys/Bsw_Wrapper/Bsw_Wrapper.src" 

C_DEPS += \
"./BSW/Sys/Bsw_Wrapper/Bsw_Wrapper.d" 

OBJS += \
"BSW/Sys/Bsw_Wrapper/Bsw_Wrapper.o" 


# Each subdirectory must supply rules for building sources it contributes
"BSW/Sys/Bsw_Wrapper/Bsw_Wrapper.src":"../BSW/Sys/Bsw_Wrapper/Bsw_Wrapper.c" "BSW/Sys/Bsw_Wrapper/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/Bsw_Wrapper/Bsw_Wrapper.o":"BSW/Sys/Bsw_Wrapper/Bsw_Wrapper.src" "BSW/Sys/Bsw_Wrapper/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-Sys-2f-Bsw_Wrapper

clean-BSW-2f-Sys-2f-Bsw_Wrapper:
	-$(RM) ./BSW/Sys/Bsw_Wrapper/Bsw_Wrapper.d ./BSW/Sys/Bsw_Wrapper/Bsw_Wrapper.o ./BSW/Sys/Bsw_Wrapper/Bsw_Wrapper.src

.PHONY: clean-BSW-2f-Sys-2f-Bsw_Wrapper

