################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_DieTemp.c" \
"../BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_InternalWatchdogs.c" \
"../BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_RegMon.c" \
"../BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_VoltMon.c" 

COMPILED_SRCS += \
"BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_DieTemp.src" \
"BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_InternalWatchdogs.src" \
"BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_RegMon.src" \
"BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_VoltMon.src" 

C_DEPS += \
"./BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_DieTemp.d" \
"./BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_InternalWatchdogs.d" \
"./BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_RegMon.d" \
"./BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_VoltMon.d" 

OBJS += \
"BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_DieTemp.o" \
"BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_InternalWatchdogs.o" \
"BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_RegMon.o" \
"BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_VoltMon.o" 


# Each subdirectory must supply rules for building sources it contributes
"BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_DieTemp.src":"../BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_DieTemp.c" "BSW/Sys/SmM/02_Safety_Mechanisms/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_DieTemp.o":"BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_DieTemp.src" "BSW/Sys/SmM/02_Safety_Mechanisms/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_InternalWatchdogs.src":"../BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_InternalWatchdogs.c" "BSW/Sys/SmM/02_Safety_Mechanisms/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_InternalWatchdogs.o":"BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_InternalWatchdogs.src" "BSW/Sys/SmM/02_Safety_Mechanisms/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_RegMon.src":"../BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_RegMon.c" "BSW/Sys/SmM/02_Safety_Mechanisms/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_RegMon.o":"BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_RegMon.src" "BSW/Sys/SmM/02_Safety_Mechanisms/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_VoltMon.src":"../BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_VoltMon.c" "BSW/Sys/SmM/02_Safety_Mechanisms/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_VoltMon.o":"BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_VoltMon.src" "BSW/Sys/SmM/02_Safety_Mechanisms/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-Sys-2f-SmM-2f-02_Safety_Mechanisms

clean-BSW-2f-Sys-2f-SmM-2f-02_Safety_Mechanisms:
	-$(RM) ./BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_DieTemp.d ./BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_DieTemp.o ./BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_DieTemp.src ./BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_InternalWatchdogs.d ./BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_InternalWatchdogs.o ./BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_InternalWatchdogs.src ./BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_RegMon.d ./BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_RegMon.o ./BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_RegMon.src ./BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_VoltMon.d ./BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_VoltMon.o ./BSW/Sys/SmM/02_Safety_Mechanisms/SafetyKit_VoltMon.src

.PHONY: clean-BSW-2f-Sys-2f-SmM-2f-02_Safety_Mechanisms

