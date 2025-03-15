################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../APP/ComMaster/ComMaster.c" 

COMPILED_SRCS += \
"APP/ComMaster/ComMaster.src" 

C_DEPS += \
"./APP/ComMaster/ComMaster.d" 

OBJS += \
"APP/ComMaster/ComMaster.o" 


# Each subdirectory must supply rules for building sources it contributes
"APP/ComMaster/ComMaster.src":"../APP/ComMaster/ComMaster.c" "APP/ComMaster/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"APP/ComMaster/ComMaster.o":"APP/ComMaster/ComMaster.src" "APP/ComMaster/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-APP-2f-ComMaster

clean-APP-2f-ComMaster:
	-$(RM) ./APP/ComMaster/ComMaster.d ./APP/ComMaster/ComMaster.o ./APP/ComMaster/ComMaster.src

.PHONY: clean-APP-2f-ComMaster

