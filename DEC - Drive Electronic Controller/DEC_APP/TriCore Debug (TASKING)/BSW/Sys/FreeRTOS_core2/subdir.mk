################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../BSW/Sys/FreeRTOS_core2/croutine_core2.c" \
"../BSW/Sys/FreeRTOS_core2/event_groups_core2.c" \
"../BSW/Sys/FreeRTOS_core2/heap_4_core2.c" \
"../BSW/Sys/FreeRTOS_core2/list_core2.c" \
"../BSW/Sys/FreeRTOS_core2/port_core2.c" \
"../BSW/Sys/FreeRTOS_core2/queue_core2.c" \
"../BSW/Sys/FreeRTOS_core2/stream_buffer_core2.c" \
"../BSW/Sys/FreeRTOS_core2/tasks_core2.c" \
"../BSW/Sys/FreeRTOS_core2/timers_core2.c" 

COMPILED_SRCS += \
"BSW/Sys/FreeRTOS_core2/croutine_core2.src" \
"BSW/Sys/FreeRTOS_core2/event_groups_core2.src" \
"BSW/Sys/FreeRTOS_core2/heap_4_core2.src" \
"BSW/Sys/FreeRTOS_core2/list_core2.src" \
"BSW/Sys/FreeRTOS_core2/port_core2.src" \
"BSW/Sys/FreeRTOS_core2/queue_core2.src" \
"BSW/Sys/FreeRTOS_core2/stream_buffer_core2.src" \
"BSW/Sys/FreeRTOS_core2/tasks_core2.src" \
"BSW/Sys/FreeRTOS_core2/timers_core2.src" 

C_DEPS += \
"./BSW/Sys/FreeRTOS_core2/croutine_core2.d" \
"./BSW/Sys/FreeRTOS_core2/event_groups_core2.d" \
"./BSW/Sys/FreeRTOS_core2/heap_4_core2.d" \
"./BSW/Sys/FreeRTOS_core2/list_core2.d" \
"./BSW/Sys/FreeRTOS_core2/port_core2.d" \
"./BSW/Sys/FreeRTOS_core2/queue_core2.d" \
"./BSW/Sys/FreeRTOS_core2/stream_buffer_core2.d" \
"./BSW/Sys/FreeRTOS_core2/tasks_core2.d" \
"./BSW/Sys/FreeRTOS_core2/timers_core2.d" 

OBJS += \
"BSW/Sys/FreeRTOS_core2/croutine_core2.o" \
"BSW/Sys/FreeRTOS_core2/event_groups_core2.o" \
"BSW/Sys/FreeRTOS_core2/heap_4_core2.o" \
"BSW/Sys/FreeRTOS_core2/list_core2.o" \
"BSW/Sys/FreeRTOS_core2/port_core2.o" \
"BSW/Sys/FreeRTOS_core2/queue_core2.o" \
"BSW/Sys/FreeRTOS_core2/stream_buffer_core2.o" \
"BSW/Sys/FreeRTOS_core2/tasks_core2.o" \
"BSW/Sys/FreeRTOS_core2/timers_core2.o" 


# Each subdirectory must supply rules for building sources it contributes
"BSW/Sys/FreeRTOS_core2/croutine_core2.src":"../BSW/Sys/FreeRTOS_core2/croutine_core2.c" "BSW/Sys/FreeRTOS_core2/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/FreeRTOS_core2/croutine_core2.o":"BSW/Sys/FreeRTOS_core2/croutine_core2.src" "BSW/Sys/FreeRTOS_core2/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Sys/FreeRTOS_core2/event_groups_core2.src":"../BSW/Sys/FreeRTOS_core2/event_groups_core2.c" "BSW/Sys/FreeRTOS_core2/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/FreeRTOS_core2/event_groups_core2.o":"BSW/Sys/FreeRTOS_core2/event_groups_core2.src" "BSW/Sys/FreeRTOS_core2/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Sys/FreeRTOS_core2/heap_4_core2.src":"../BSW/Sys/FreeRTOS_core2/heap_4_core2.c" "BSW/Sys/FreeRTOS_core2/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/FreeRTOS_core2/heap_4_core2.o":"BSW/Sys/FreeRTOS_core2/heap_4_core2.src" "BSW/Sys/FreeRTOS_core2/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Sys/FreeRTOS_core2/list_core2.src":"../BSW/Sys/FreeRTOS_core2/list_core2.c" "BSW/Sys/FreeRTOS_core2/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/FreeRTOS_core2/list_core2.o":"BSW/Sys/FreeRTOS_core2/list_core2.src" "BSW/Sys/FreeRTOS_core2/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Sys/FreeRTOS_core2/port_core2.src":"../BSW/Sys/FreeRTOS_core2/port_core2.c" "BSW/Sys/FreeRTOS_core2/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/FreeRTOS_core2/port_core2.o":"BSW/Sys/FreeRTOS_core2/port_core2.src" "BSW/Sys/FreeRTOS_core2/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Sys/FreeRTOS_core2/queue_core2.src":"../BSW/Sys/FreeRTOS_core2/queue_core2.c" "BSW/Sys/FreeRTOS_core2/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/FreeRTOS_core2/queue_core2.o":"BSW/Sys/FreeRTOS_core2/queue_core2.src" "BSW/Sys/FreeRTOS_core2/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Sys/FreeRTOS_core2/stream_buffer_core2.src":"../BSW/Sys/FreeRTOS_core2/stream_buffer_core2.c" "BSW/Sys/FreeRTOS_core2/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/FreeRTOS_core2/stream_buffer_core2.o":"BSW/Sys/FreeRTOS_core2/stream_buffer_core2.src" "BSW/Sys/FreeRTOS_core2/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Sys/FreeRTOS_core2/tasks_core2.src":"../BSW/Sys/FreeRTOS_core2/tasks_core2.c" "BSW/Sys/FreeRTOS_core2/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/FreeRTOS_core2/tasks_core2.o":"BSW/Sys/FreeRTOS_core2/tasks_core2.src" "BSW/Sys/FreeRTOS_core2/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Sys/FreeRTOS_core2/timers_core2.src":"../BSW/Sys/FreeRTOS_core2/timers_core2.c" "BSW/Sys/FreeRTOS_core2/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Sys/FreeRTOS_core2/timers_core2.o":"BSW/Sys/FreeRTOS_core2/timers_core2.src" "BSW/Sys/FreeRTOS_core2/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-Sys-2f-FreeRTOS_core2

clean-BSW-2f-Sys-2f-FreeRTOS_core2:
	-$(RM) ./BSW/Sys/FreeRTOS_core2/croutine_core2.d ./BSW/Sys/FreeRTOS_core2/croutine_core2.o ./BSW/Sys/FreeRTOS_core2/croutine_core2.src ./BSW/Sys/FreeRTOS_core2/event_groups_core2.d ./BSW/Sys/FreeRTOS_core2/event_groups_core2.o ./BSW/Sys/FreeRTOS_core2/event_groups_core2.src ./BSW/Sys/FreeRTOS_core2/heap_4_core2.d ./BSW/Sys/FreeRTOS_core2/heap_4_core2.o ./BSW/Sys/FreeRTOS_core2/heap_4_core2.src ./BSW/Sys/FreeRTOS_core2/list_core2.d ./BSW/Sys/FreeRTOS_core2/list_core2.o ./BSW/Sys/FreeRTOS_core2/list_core2.src ./BSW/Sys/FreeRTOS_core2/port_core2.d ./BSW/Sys/FreeRTOS_core2/port_core2.o ./BSW/Sys/FreeRTOS_core2/port_core2.src ./BSW/Sys/FreeRTOS_core2/queue_core2.d ./BSW/Sys/FreeRTOS_core2/queue_core2.o ./BSW/Sys/FreeRTOS_core2/queue_core2.src ./BSW/Sys/FreeRTOS_core2/stream_buffer_core2.d ./BSW/Sys/FreeRTOS_core2/stream_buffer_core2.o ./BSW/Sys/FreeRTOS_core2/stream_buffer_core2.src ./BSW/Sys/FreeRTOS_core2/tasks_core2.d ./BSW/Sys/FreeRTOS_core2/tasks_core2.o ./BSW/Sys/FreeRTOS_core2/tasks_core2.src ./BSW/Sys/FreeRTOS_core2/timers_core2.d ./BSW/Sys/FreeRTOS_core2/timers_core2.o ./BSW/Sys/FreeRTOS_core2/timers_core2.src

.PHONY: clean-BSW-2f-Sys-2f-FreeRTOS_core2

