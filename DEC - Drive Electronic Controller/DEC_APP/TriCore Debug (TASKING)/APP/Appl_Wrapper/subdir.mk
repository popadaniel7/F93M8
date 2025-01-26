################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../APP/Appl_Wrapper/Appl_Wrapper.c" 

COMPILED_SRCS += \
"APP/Appl_Wrapper/Appl_Wrapper.src" 

C_DEPS += \
"./APP/Appl_Wrapper/Appl_Wrapper.d" 

OBJS += \
"APP/Appl_Wrapper/Appl_Wrapper.o" 


# Each subdirectory must supply rules for building sources it contributes
"APP/Appl_Wrapper/Appl_Wrapper.src":"../APP/Appl_Wrapper/Appl_Wrapper.c" "APP/Appl_Wrapper/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"APP/Appl_Wrapper/Appl_Wrapper.o":"APP/Appl_Wrapper/Appl_Wrapper.src" "APP/Appl_Wrapper/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-APP-2f-Appl_Wrapper

clean-APP-2f-Appl_Wrapper:
	-$(RM) ./APP/Appl_Wrapper/Appl_Wrapper.d ./APP/Appl_Wrapper/Appl_Wrapper.o ./APP/Appl_Wrapper/Appl_Wrapper.src

.PHONY: clean-APP-2f-Appl_Wrapper

