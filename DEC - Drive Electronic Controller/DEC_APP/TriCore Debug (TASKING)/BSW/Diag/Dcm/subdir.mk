################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../BSW/Diag/Dcm/Dcm.c" 

COMPILED_SRCS += \
"BSW/Diag/Dcm/Dcm.src" 

C_DEPS += \
"./BSW/Diag/Dcm/Dcm.d" 

OBJS += \
"BSW/Diag/Dcm/Dcm.o" 


# Each subdirectory must supply rules for building sources it contributes
"BSW/Diag/Dcm/Dcm.src":"../BSW/Diag/Dcm/Dcm.c" "BSW/Diag/Dcm/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Diag/Dcm/Dcm.o":"BSW/Diag/Dcm/Dcm.src" "BSW/Diag/Dcm/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-Diag-2f-Dcm

clean-BSW-2f-Diag-2f-Dcm:
	-$(RM) ./BSW/Diag/Dcm/Dcm.d ./BSW/Diag/Dcm/Dcm.o ./BSW/Diag/Dcm/Dcm.src

.PHONY: clean-BSW-2f-Diag-2f-Dcm

