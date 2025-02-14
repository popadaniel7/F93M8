################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Libraries/iLLD/TC37A/Tricore/_PinMap/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/_Impl/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Stm/Std/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Src/Std/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Smu/Std/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Scu/Std/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Port/Std/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Port/Io/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Pms/Std/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Mtu/Std/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Gtm/Std/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Gtm/Atom/Timer/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Gtm/Atom/Pwm/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Flash/Std/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Fce/Std/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Fce/Crc/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Evadc/Std/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Evadc/Adc/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Dts/Std/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Dts/Dts/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Dma/Std/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Dma/Dma/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Cpu/Trap/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Cpu/Std/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Cpu/Irq/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Can/Std/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Can/Can/subdir.mk
-include Libraries/Service/CpuGeneric/SysSe/Bsp/subdir.mk
-include Libraries/Service/CpuGeneric/StdIf/subdir.mk
-include Libraries/Infra/Ssw/TC37A/Tricore/subdir.mk
-include Libraries/Infra/Platform/Tricore/Compilers/subdir.mk
-include Libraries/subdir.mk
-include Configurations/Debug/subdir.mk
-include Configurations/subdir.mk
-include BSW/Sys/Wdg/subdir.mk
-include BSW/Sys/SysMgr/subdir.mk
-include BSW/Sys/Smu/subdir.mk
-include BSW/Sys/Os/FreeRTOS_Core2/portable_core2/Tasking/TC3/subdir.mk
-include BSW/Sys/Os/FreeRTOS_Core2/portable_core2/MemMang/subdir.mk
-include BSW/Sys/Os/FreeRTOS_Core2/subdir.mk
-include BSW/Sys/Os/FreeRTOS_Core1/portable_core1/Tasking/TC3/subdir.mk
-include BSW/Sys/Os/FreeRTOS_Core1/portable_core1/MemMang/subdir.mk
-include BSW/Sys/Os/FreeRTOS_Core1/subdir.mk
-include BSW/Sys/Os/FreeRTOS_Core0/portable_core0/Tasking/TC3/subdir.mk
-include BSW/Sys/Os/FreeRTOS_Core0/portable_core0/MemMang/subdir.mk
-include BSW/Sys/Os/FreeRTOS_Core0/subdir.mk
-include BSW/Sys/Os/subdir.mk
-include BSW/Sys/McuSm/subdir.mk
-include BSW/Sys/Crc/subdir.mk
-include BSW/Sys/Bsw_Wrapper/subdir.mk
-include BSW/Mem/Nvm/subdir.mk
-include BSW/Mem/Fls/subdir.mk
-include BSW/Io/Irq/subdir.mk
-include BSW/Io/Gtm/subdir.mk
-include BSW/Io/Eru/subdir.mk
-include BSW/Io/Dma/subdir.mk
-include BSW/Io/Ain/subdir.mk
-include BSW/Diag/Dem/subdir.mk
-include BSW/Diag/Dcm/subdir.mk
-include BSW/Com/Can/subdir.mk
-include APP/Iven/subdir.mk
-include APP/EnergyMgmt/subdir.mk
-include APP/EncCal/subdir.mk
-include APP/DiagMaster/subdir.mk
-include APP/DcyHandler/subdir.mk
-include APP/ComMaster/subdir.mk
-include APP/ColDet/subdir.mk
-include subdir.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := DEC_APP
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_SIZE += \
DEC_APP.siz \


# All Target
all: main-build

# Main-build Target
main-build: DEC_APP.elf secondary-outputs

dependents:
	-cd "C:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/SCR Debug (SDCC)" && $(MAKE) clean all

# Tool invocations
DEC_APP.elf: $(OBJS) "C:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/SCR Debug (SDCC)/SCR_AURIX_TC3x" makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: TASKING Linker'
	cctc --lsl-file="../Lcf_Tasking_Tricore_Tc.lsl" -Wl-Oc -Wl-OL -Wl-Ot -Wl-Ox -Wl-Oy -Wl--map-file="DEC_APP.map" -Wl-mc -Wl-mf -Wl-mi -Wl-mk -Wl-ml -Wl-mm -Wl-md -Wl-mr -Wl-mu --no-warnings= -Wl--error-limit=42 --fp-model=3 -lrt --lsl-core=vtc --exceptions --strict --anachronisms --force-c++ -Ctc37x -o"DEC_APP.elf" -Wl-o"DEC_APP.hex:IHEX" $(OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

DEC_APP.siz: DEC_APP.elf makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	elfsize  "DEC_APP.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) DEC_APP.siz DEC_APP.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents main-build
"C:/Users/Daniel/Desktop/FG9326M8GTEI4/DEC - Drive Electronic Controller/DEC_APP/SCR Debug (SDCC)/SCR_AURIX_TC3x":

-include ../makefile.targets
