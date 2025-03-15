################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../APP/ColDet/ColDet.c" 

COMPILED_SRCS += \
"APP/ColDet/ColDet.src" 

C_DEPS += \
"./APP/ColDet/ColDet.d" 

OBJS += \
"APP/ColDet/ColDet.o" 


# Each subdirectory must supply rules for building sources it contributes
"APP/ColDet/ColDet.src":"../APP/ColDet/ColDet.c" "APP/ColDet/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"APP/ColDet/ColDet.o":"APP/ColDet/ColDet.src" "APP/ColDet/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-APP-2f-ColDet

clean-APP-2f-ColDet:
	-$(RM) ./APP/ColDet/ColDet.d ./APP/ColDet/ColDet.o ./APP/ColDet/ColDet.src

.PHONY: clean-APP-2f-ColDet

