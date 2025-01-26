################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../APP/ConfigMgr/ConfigMgr.c" 

COMPILED_SRCS += \
"APP/ConfigMgr/ConfigMgr.src" 

C_DEPS += \
"./APP/ConfigMgr/ConfigMgr.d" 

OBJS += \
"APP/ConfigMgr/ConfigMgr.o" 


# Each subdirectory must supply rules for building sources it contributes
"APP/ConfigMgr/ConfigMgr.src":"../APP/ConfigMgr/ConfigMgr.c" "APP/ConfigMgr/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"APP/ConfigMgr/ConfigMgr.o":"APP/ConfigMgr/ConfigMgr.src" "APP/ConfigMgr/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-APP-2f-ConfigMgr

clean-APP-2f-ConfigMgr:
	-$(RM) ./APP/ConfigMgr/ConfigMgr.d ./APP/ConfigMgr/ConfigMgr.o ./APP/ConfigMgr/ConfigMgr.src

.PHONY: clean-APP-2f-ConfigMgr

