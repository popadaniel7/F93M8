################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../BSW/Io/Ain/Ain.c" \
"../BSW/Io/Ain/Ain_Filtering.c" 

COMPILED_SRCS += \
"BSW/Io/Ain/Ain.src" \
"BSW/Io/Ain/Ain_Filtering.src" 

C_DEPS += \
"./BSW/Io/Ain/Ain.d" \
"./BSW/Io/Ain/Ain_Filtering.d" 

OBJS += \
"BSW/Io/Ain/Ain.o" \
"BSW/Io/Ain/Ain_Filtering.o" 


# Each subdirectory must supply rules for building sources it contributes
"BSW/Io/Ain/Ain.src":"../BSW/Io/Ain/Ain.c" "BSW/Io/Ain/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Io/Ain/Ain.o":"BSW/Io/Ain/Ain.src" "BSW/Io/Ain/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Io/Ain/Ain_Filtering.src":"../BSW/Io/Ain/Ain_Filtering.c" "BSW/Io/Ain/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Io/Ain/Ain_Filtering.o":"BSW/Io/Ain/Ain_Filtering.src" "BSW/Io/Ain/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-Io-2f-Ain

clean-BSW-2f-Io-2f-Ain:
	-$(RM) ./BSW/Io/Ain/Ain.d ./BSW/Io/Ain/Ain.o ./BSW/Io/Ain/Ain.src ./BSW/Io/Ain/Ain_Filtering.d ./BSW/Io/Ain/Ain_Filtering.o ./BSW/Io/Ain/Ain_Filtering.src

.PHONY: clean-BSW-2f-Io-2f-Ain

