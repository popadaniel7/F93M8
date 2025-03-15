################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../BSW/Mem/Fls/Fls.c" 

COMPILED_SRCS += \
"BSW/Mem/Fls/Fls.src" 

C_DEPS += \
"./BSW/Mem/Fls/Fls.d" 

OBJS += \
"BSW/Mem/Fls/Fls.o" 


# Each subdirectory must supply rules for building sources it contributes
"BSW/Mem/Fls/Fls.src":"../BSW/Mem/Fls/Fls.c" "BSW/Mem/Fls/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Mem/Fls/Fls.o":"BSW/Mem/Fls/Fls.src" "BSW/Mem/Fls/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-Mem-2f-Fls

clean-BSW-2f-Mem-2f-Fls:
	-$(RM) ./BSW/Mem/Fls/Fls.d ./BSW/Mem/Fls/Fls.o ./BSW/Mem/Fls/Fls.src

.PHONY: clean-BSW-2f-Mem-2f-Fls

