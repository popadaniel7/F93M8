################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../BSW/Sys/Os/FreeRTOS/croutine.c" \
"../BSW/Sys/Os/FreeRTOS/event_groups.c" \
"../BSW/Sys/Os/FreeRTOS/list.c" \
"../BSW/Sys/Os/FreeRTOS/queue.c" \
"../BSW/Sys/Os/FreeRTOS/stream_buffer.c" \
"../BSW/Sys/Os/FreeRTOS/tasks.c" \
"../BSW/Sys/Os/FreeRTOS/timers.c" 

COMPILED_SRCS += \
"BSW/Sys/Os/FreeRTOS/croutine.src" \
"BSW/Sys/Os/FreeRTOS/event_groups.src" \
"BSW/Sys/Os/FreeRTOS/list.src" \
"BSW/Sys/Os/FreeRTOS/queue.src" \
"BSW/Sys/Os/FreeRTOS/stream_buffer.src" \
"BSW/Sys/Os/FreeRTOS/tasks.src" \
"BSW/Sys/Os/FreeRTOS/timers.src" 

C_DEPS += \
"./BSW/Sys/Os/FreeRTOS/croutine.d" \
"./BSW/Sys/Os/FreeRTOS/event_groups.d" \
"./BSW/Sys/Os/FreeRTOS/list.d" \
"./BSW/Sys/Os/FreeRTOS/queue.d" \
"./BSW/Sys/Os/FreeRTOS/stream_buffer.d" \
"./BSW/Sys/Os/FreeRTOS/tasks.d" \
"./BSW/Sys/Os/FreeRTOS/timers.d" 

OBJS += \
"BSW/Sys/Os/FreeRTOS/croutine.o" \
"BSW/Sys/Os/FreeRTOS/event_groups.o" \
"BSW/Sys/Os/FreeRTOS/list.o" \
"BSW/Sys/Os/FreeRTOS/queue.o" \
"BSW/Sys/Os/FreeRTOS/stream_buffer.o" \
"BSW/Sys/Os/FreeRTOS/tasks.o" \
"BSW/Sys/Os/FreeRTOS/timers.o" 


# Each subdirectory must supply rules for building sources it contributes
"BSW/Sys/Os/FreeRTOS/croutine.src":"../BSW/Sys/Os/FreeRTOS/croutine.c" "BSW/Sys/Os/FreeRTOS/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/Os/FreeRTOS/croutine.o":"BSW/Sys/Os/FreeRTOS/croutine.src" "BSW/Sys/Os/FreeRTOS/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Sys/Os/FreeRTOS/event_groups.src":"../BSW/Sys/Os/FreeRTOS/event_groups.c" "BSW/Sys/Os/FreeRTOS/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/Os/FreeRTOS/event_groups.o":"BSW/Sys/Os/FreeRTOS/event_groups.src" "BSW/Sys/Os/FreeRTOS/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Sys/Os/FreeRTOS/list.src":"../BSW/Sys/Os/FreeRTOS/list.c" "BSW/Sys/Os/FreeRTOS/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/Os/FreeRTOS/list.o":"BSW/Sys/Os/FreeRTOS/list.src" "BSW/Sys/Os/FreeRTOS/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Sys/Os/FreeRTOS/queue.src":"../BSW/Sys/Os/FreeRTOS/queue.c" "BSW/Sys/Os/FreeRTOS/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/Os/FreeRTOS/queue.o":"BSW/Sys/Os/FreeRTOS/queue.src" "BSW/Sys/Os/FreeRTOS/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Sys/Os/FreeRTOS/stream_buffer.src":"../BSW/Sys/Os/FreeRTOS/stream_buffer.c" "BSW/Sys/Os/FreeRTOS/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/Os/FreeRTOS/stream_buffer.o":"BSW/Sys/Os/FreeRTOS/stream_buffer.src" "BSW/Sys/Os/FreeRTOS/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Sys/Os/FreeRTOS/tasks.src":"../BSW/Sys/Os/FreeRTOS/tasks.c" "BSW/Sys/Os/FreeRTOS/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/Os/FreeRTOS/tasks.o":"BSW/Sys/Os/FreeRTOS/tasks.src" "BSW/Sys/Os/FreeRTOS/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Sys/Os/FreeRTOS/timers.src":"../BSW/Sys/Os/FreeRTOS/timers.c" "BSW/Sys/Os/FreeRTOS/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/Os/FreeRTOS/timers.o":"BSW/Sys/Os/FreeRTOS/timers.src" "BSW/Sys/Os/FreeRTOS/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-Sys-2f-Os-2f-FreeRTOS

clean-BSW-2f-Sys-2f-Os-2f-FreeRTOS:
	-$(RM) ./BSW/Sys/Os/FreeRTOS/croutine.d ./BSW/Sys/Os/FreeRTOS/croutine.o ./BSW/Sys/Os/FreeRTOS/croutine.src ./BSW/Sys/Os/FreeRTOS/event_groups.d ./BSW/Sys/Os/FreeRTOS/event_groups.o ./BSW/Sys/Os/FreeRTOS/event_groups.src ./BSW/Sys/Os/FreeRTOS/list.d ./BSW/Sys/Os/FreeRTOS/list.o ./BSW/Sys/Os/FreeRTOS/list.src ./BSW/Sys/Os/FreeRTOS/queue.d ./BSW/Sys/Os/FreeRTOS/queue.o ./BSW/Sys/Os/FreeRTOS/queue.src ./BSW/Sys/Os/FreeRTOS/stream_buffer.d ./BSW/Sys/Os/FreeRTOS/stream_buffer.o ./BSW/Sys/Os/FreeRTOS/stream_buffer.src ./BSW/Sys/Os/FreeRTOS/tasks.d ./BSW/Sys/Os/FreeRTOS/tasks.o ./BSW/Sys/Os/FreeRTOS/tasks.src ./BSW/Sys/Os/FreeRTOS/timers.d ./BSW/Sys/Os/FreeRTOS/timers.o ./BSW/Sys/Os/FreeRTOS/timers.src

.PHONY: clean-BSW-2f-Sys-2f-Os-2f-FreeRTOS

