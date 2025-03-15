################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../BSW/Sys/SmM/00_Ssw/SafetyKit_SSW.c" \
"../BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_00_LBIST.c" \
"../BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_02_MCU_FW_CHECK.c" \
"../BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_03_MCU_STARTUP.c" \
"../BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_04_ALIVE_ALARM_TEST.c" \
"../BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_05_SMU_REG_MONITOR_TEST.c" \
"../BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_06_MBIST.c" 

COMPILED_SRCS += \
"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW.src" \
"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_00_LBIST.src" \
"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_02_MCU_FW_CHECK.src" \
"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_03_MCU_STARTUP.src" \
"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_04_ALIVE_ALARM_TEST.src" \
"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_05_SMU_REG_MONITOR_TEST.src" \
"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_06_MBIST.src" 

C_DEPS += \
"./BSW/Sys/SmM/00_Ssw/SafetyKit_SSW.d" \
"./BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_00_LBIST.d" \
"./BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_02_MCU_FW_CHECK.d" \
"./BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_03_MCU_STARTUP.d" \
"./BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_04_ALIVE_ALARM_TEST.d" \
"./BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_05_SMU_REG_MONITOR_TEST.d" \
"./BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_06_MBIST.d" 

OBJS += \
"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW.o" \
"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_00_LBIST.o" \
"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_02_MCU_FW_CHECK.o" \
"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_03_MCU_STARTUP.o" \
"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_04_ALIVE_ALARM_TEST.o" \
"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_05_SMU_REG_MONITOR_TEST.o" \
"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_06_MBIST.o" 


# Each subdirectory must supply rules for building sources it contributes
"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW.src":"../BSW/Sys/SmM/00_Ssw/SafetyKit_SSW.c" "BSW/Sys/SmM/00_Ssw/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW.o":"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW.src" "BSW/Sys/SmM/00_Ssw/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_00_LBIST.src":"../BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_00_LBIST.c" "BSW/Sys/SmM/00_Ssw/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_00_LBIST.o":"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_00_LBIST.src" "BSW/Sys/SmM/00_Ssw/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_02_MCU_FW_CHECK.src":"../BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_02_MCU_FW_CHECK.c" "BSW/Sys/SmM/00_Ssw/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_02_MCU_FW_CHECK.o":"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_02_MCU_FW_CHECK.src" "BSW/Sys/SmM/00_Ssw/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_03_MCU_STARTUP.src":"../BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_03_MCU_STARTUP.c" "BSW/Sys/SmM/00_Ssw/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_03_MCU_STARTUP.o":"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_03_MCU_STARTUP.src" "BSW/Sys/SmM/00_Ssw/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_04_ALIVE_ALARM_TEST.src":"../BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_04_ALIVE_ALARM_TEST.c" "BSW/Sys/SmM/00_Ssw/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_04_ALIVE_ALARM_TEST.o":"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_04_ALIVE_ALARM_TEST.src" "BSW/Sys/SmM/00_Ssw/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_05_SMU_REG_MONITOR_TEST.src":"../BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_05_SMU_REG_MONITOR_TEST.c" "BSW/Sys/SmM/00_Ssw/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_05_SMU_REG_MONITOR_TEST.o":"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_05_SMU_REG_MONITOR_TEST.src" "BSW/Sys/SmM/00_Ssw/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_06_MBIST.src":"../BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_06_MBIST.c" "BSW/Sys/SmM/00_Ssw/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_06_MBIST.o":"BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_06_MBIST.src" "BSW/Sys/SmM/00_Ssw/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-Sys-2f-SmM-2f-00_Ssw

clean-BSW-2f-Sys-2f-SmM-2f-00_Ssw:
	-$(RM) ./BSW/Sys/SmM/00_Ssw/SafetyKit_SSW.d ./BSW/Sys/SmM/00_Ssw/SafetyKit_SSW.o ./BSW/Sys/SmM/00_Ssw/SafetyKit_SSW.src ./BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_00_LBIST.d ./BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_00_LBIST.o ./BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_00_LBIST.src ./BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_02_MCU_FW_CHECK.d ./BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_02_MCU_FW_CHECK.o ./BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_02_MCU_FW_CHECK.src ./BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_03_MCU_STARTUP.d ./BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_03_MCU_STARTUP.o ./BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_03_MCU_STARTUP.src ./BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_04_ALIVE_ALARM_TEST.d ./BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_04_ALIVE_ALARM_TEST.o ./BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_04_ALIVE_ALARM_TEST.src ./BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_05_SMU_REG_MONITOR_TEST.d ./BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_05_SMU_REG_MONITOR_TEST.o ./BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_05_SMU_REG_MONITOR_TEST.src ./BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_06_MBIST.d ./BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_06_MBIST.o ./BSW/Sys/SmM/00_Ssw/SafetyKit_SSW_06_MBIST.src

.PHONY: clean-BSW-2f-Sys-2f-SmM-2f-00_Ssw

