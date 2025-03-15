################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../BSW/Sys/SmM/06_Safe_Computation/SafetyKit_Fce.c" \
"../BSW/Sys/SmM/06_Safe_Computation/SafetyKit_NvmPflash.c" 

COMPILED_SRCS += \
"BSW/Sys/SmM/06_Safe_Computation/SafetyKit_Fce.src" \
"BSW/Sys/SmM/06_Safe_Computation/SafetyKit_NvmPflash.src" 

C_DEPS += \
"./BSW/Sys/SmM/06_Safe_Computation/SafetyKit_Fce.d" \
"./BSW/Sys/SmM/06_Safe_Computation/SafetyKit_NvmPflash.d" 

OBJS += \
"BSW/Sys/SmM/06_Safe_Computation/SafetyKit_Fce.o" \
"BSW/Sys/SmM/06_Safe_Computation/SafetyKit_NvmPflash.o" 


# Each subdirectory must supply rules for building sources it contributes
"BSW/Sys/SmM/06_Safe_Computation/SafetyKit_Fce.src":"../BSW/Sys/SmM/06_Safe_Computation/SafetyKit_Fce.c" "BSW/Sys/SmM/06_Safe_Computation/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/SmM/06_Safe_Computation/SafetyKit_Fce.o":"BSW/Sys/SmM/06_Safe_Computation/SafetyKit_Fce.src" "BSW/Sys/SmM/06_Safe_Computation/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Sys/SmM/06_Safe_Computation/SafetyKit_NvmPflash.src":"../BSW/Sys/SmM/06_Safe_Computation/SafetyKit_NvmPflash.c" "BSW/Sys/SmM/06_Safe_Computation/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/SmM/06_Safe_Computation/SafetyKit_NvmPflash.o":"BSW/Sys/SmM/06_Safe_Computation/SafetyKit_NvmPflash.src" "BSW/Sys/SmM/06_Safe_Computation/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-Sys-2f-SmM-2f-06_Safe_Computation

clean-BSW-2f-Sys-2f-SmM-2f-06_Safe_Computation:
	-$(RM) ./BSW/Sys/SmM/06_Safe_Computation/SafetyKit_Fce.d ./BSW/Sys/SmM/06_Safe_Computation/SafetyKit_Fce.o ./BSW/Sys/SmM/06_Safe_Computation/SafetyKit_Fce.src ./BSW/Sys/SmM/06_Safe_Computation/SafetyKit_NvmPflash.d ./BSW/Sys/SmM/06_Safe_Computation/SafetyKit_NvmPflash.o ./BSW/Sys/SmM/06_Safe_Computation/SafetyKit_NvmPflash.src

.PHONY: clean-BSW-2f-Sys-2f-SmM-2f-06_Safe_Computation

