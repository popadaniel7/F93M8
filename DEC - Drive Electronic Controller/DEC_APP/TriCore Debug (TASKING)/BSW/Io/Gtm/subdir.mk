################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../BSW/Io/Gtm/Gtm_Atom.c" \
"../BSW/Io/Gtm/Gtm_Pwm.c" 

COMPILED_SRCS += \
"BSW/Io/Gtm/Gtm_Atom.src" \
"BSW/Io/Gtm/Gtm_Pwm.src" 

C_DEPS += \
"./BSW/Io/Gtm/Gtm_Atom.d" \
"./BSW/Io/Gtm/Gtm_Pwm.d" 

OBJS += \
"BSW/Io/Gtm/Gtm_Atom.o" \
"BSW/Io/Gtm/Gtm_Pwm.o" 


# Each subdirectory must supply rules for building sources it contributes
"BSW/Io/Gtm/Gtm_Atom.src":"../BSW/Io/Gtm/Gtm_Atom.c" "BSW/Io/Gtm/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Io/Gtm/Gtm_Atom.o":"BSW/Io/Gtm/Gtm_Atom.src" "BSW/Io/Gtm/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Io/Gtm/Gtm_Pwm.src":"../BSW/Io/Gtm/Gtm_Pwm.c" "BSW/Io/Gtm/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Io/Gtm/Gtm_Pwm.o":"BSW/Io/Gtm/Gtm_Pwm.src" "BSW/Io/Gtm/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-Io-2f-Gtm

clean-BSW-2f-Io-2f-Gtm:
	-$(RM) ./BSW/Io/Gtm/Gtm_Atom.d ./BSW/Io/Gtm/Gtm_Atom.o ./BSW/Io/Gtm/Gtm_Atom.src ./BSW/Io/Gtm/Gtm_Pwm.d ./BSW/Io/Gtm/Gtm_Pwm.o ./BSW/Io/Gtm/Gtm_Pwm.src

.PHONY: clean-BSW-2f-Io-2f-Gtm

