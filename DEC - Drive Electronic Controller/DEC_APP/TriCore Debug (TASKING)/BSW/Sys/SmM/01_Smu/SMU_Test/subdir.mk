################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../BSW/Sys/SmM/01_Smu/SMU_Test/Keys.c" 

COMPILED_SRCS += \
"BSW/Sys/SmM/01_Smu/SMU_Test/Keys.src" 

C_DEPS += \
"./BSW/Sys/SmM/01_Smu/SMU_Test/Keys.d" 

OBJS += \
"BSW/Sys/SmM/01_Smu/SMU_Test/Keys.o" 


# Each subdirectory must supply rules for building sources it contributes
"BSW/Sys/SmM/01_Smu/SMU_Test/Keys.src":"../BSW/Sys/SmM/01_Smu/SMU_Test/Keys.c" "BSW/Sys/SmM/01_Smu/SMU_Test/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/SmM/01_Smu/SMU_Test/Keys.o":"BSW/Sys/SmM/01_Smu/SMU_Test/Keys.src" "BSW/Sys/SmM/01_Smu/SMU_Test/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-Sys-2f-SmM-2f-01_Smu-2f-SMU_Test

clean-BSW-2f-Sys-2f-SmM-2f-01_Smu-2f-SMU_Test:
	-$(RM) ./BSW/Sys/SmM/01_Smu/SMU_Test/Keys.d ./BSW/Sys/SmM/01_Smu/SMU_Test/Keys.o ./BSW/Sys/SmM/01_Smu/SMU_Test/Keys.src

.PHONY: clean-BSW-2f-Sys-2f-SmM-2f-01_Smu-2f-SMU_Test

