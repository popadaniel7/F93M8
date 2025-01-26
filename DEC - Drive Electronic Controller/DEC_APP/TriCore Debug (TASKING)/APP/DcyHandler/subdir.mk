################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../APP/DcyHandler/DcyHandler.c" 

COMPILED_SRCS += \
"APP/DcyHandler/DcyHandler.src" 

C_DEPS += \
"./APP/DcyHandler/DcyHandler.d" 

OBJS += \
"APP/DcyHandler/DcyHandler.o" 


# Each subdirectory must supply rules for building sources it contributes
"APP/DcyHandler/DcyHandler.src":"../APP/DcyHandler/DcyHandler.c" "APP/DcyHandler/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"APP/DcyHandler/DcyHandler.o":"APP/DcyHandler/DcyHandler.src" "APP/DcyHandler/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-APP-2f-DcyHandler

clean-APP-2f-DcyHandler:
	-$(RM) ./APP/DcyHandler/DcyHandler.d ./APP/DcyHandler/DcyHandler.o ./APP/DcyHandler/DcyHandler.src

.PHONY: clean-APP-2f-DcyHandler

