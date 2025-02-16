################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSW/Sys/Os/FreeRTOS/croutine.c \
../BSW/Sys/Os/FreeRTOS/event_groups.c \
../BSW/Sys/Os/FreeRTOS/list.c \
../BSW/Sys/Os/FreeRTOS/queue.c \
../BSW/Sys/Os/FreeRTOS/stream_buffer.c \
../BSW/Sys/Os/FreeRTOS/tasks.c \
../BSW/Sys/Os/FreeRTOS/timers.c 

C_DEPS += \
./BSW/Sys/Os/FreeRTOS/croutine.d \
./BSW/Sys/Os/FreeRTOS/event_groups.d \
./BSW/Sys/Os/FreeRTOS/list.d \
./BSW/Sys/Os/FreeRTOS/queue.d \
./BSW/Sys/Os/FreeRTOS/stream_buffer.d \
./BSW/Sys/Os/FreeRTOS/tasks.d \
./BSW/Sys/Os/FreeRTOS/timers.d 

OBJS += \
./BSW/Sys/Os/FreeRTOS/croutine.o \
./BSW/Sys/Os/FreeRTOS/event_groups.o \
./BSW/Sys/Os/FreeRTOS/list.o \
./BSW/Sys/Os/FreeRTOS/queue.o \
./BSW/Sys/Os/FreeRTOS/stream_buffer.o \
./BSW/Sys/Os/FreeRTOS/tasks.o \
./BSW/Sys/Os/FreeRTOS/timers.o 


# Each subdirectory must supply rules for building sources it contributes
BSW/Sys/Os/FreeRTOS/%.o: ../BSW/Sys/Os/FreeRTOS/%.c BSW/Sys/Os/FreeRTOS/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-elf-gcc -std=c99 "@C:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/TriCore Debug (GCC)/AURIX_GCC_Compiler-Include_paths__-I_.opt" -Og -g3 -gdwarf-3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc162 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-BSW-2f-Sys-2f-Os-2f-FreeRTOS

clean-BSW-2f-Sys-2f-Os-2f-FreeRTOS:
	-$(RM) ./BSW/Sys/Os/FreeRTOS/croutine.d ./BSW/Sys/Os/FreeRTOS/croutine.o ./BSW/Sys/Os/FreeRTOS/event_groups.d ./BSW/Sys/Os/FreeRTOS/event_groups.o ./BSW/Sys/Os/FreeRTOS/list.d ./BSW/Sys/Os/FreeRTOS/list.o ./BSW/Sys/Os/FreeRTOS/queue.d ./BSW/Sys/Os/FreeRTOS/queue.o ./BSW/Sys/Os/FreeRTOS/stream_buffer.d ./BSW/Sys/Os/FreeRTOS/stream_buffer.o ./BSW/Sys/Os/FreeRTOS/tasks.d ./BSW/Sys/Os/FreeRTOS/tasks.o ./BSW/Sys/Os/FreeRTOS/timers.d ./BSW/Sys/Os/FreeRTOS/timers.o

.PHONY: clean-BSW-2f-Sys-2f-Os-2f-FreeRTOS

