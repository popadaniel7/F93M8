################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Middlewares/FreeRTOS/subdir.mk
-include Drivers/STM32F1xx_HAL_Driver/subdir.mk
-include Core/ThreadSafe/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include BSW/Sys/EcuM/subdir.mk
-include BSW/Nvm/subdir.mk
-include BSW/Io/Ain/subdir.mk
-include BSW/Diag/Dem/subdir.mk
-include BSW/Diag/Dcm/subdir.mk
-include BSW/Com/CanH/subdir.mk
-include APPL/LoadCtrl/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := PDM_APP
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
PDM_APP.elf \

MAP_FILES += \
PDM_APP.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
PDM_APP.list \

OBJCOPY_HEX += \
PDM_APP.hex \

OBJCOPY_BIN += \
PDM_APP.bin \

OBJCOPY_VERILOG += \
PDM_APP.verilog \

OBJCOPY_SREC += \
PDM_APP.srec \

OBJCOPY_SYMBOLSREC += \
PDM_APP.symbolsrec \


# All Target
all: main-build

# Main-build Target
main-build: PDM_APP.elf secondary-outputs

# Tool invocations
PDM_APP.elf PDM_APP.map: $(OBJS) $(USER_OBJS) C:\Users\Daniel\Desktop\FG9322\PDM\ -\ Power\ Distributor\ Module\PDM_APP\STM32F103C8TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "PDM_APP.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\Daniel\Desktop\FG9322\PDM - Power Distributor Module\PDM_APP\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="PDM_APP.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

PDM_APP.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "PDM_APP.list"
	@echo 'Finished building: $@'
	@echo ' '

PDM_APP.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "PDM_APP.hex"
	@echo 'Finished building: $@'
	@echo ' '

PDM_APP.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "PDM_APP.bin"
	@echo 'Finished building: $@'
	@echo ' '

PDM_APP.verilog: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O verilog $(EXECUTABLES) "PDM_APP.verilog"
	@echo 'Finished building: $@'
	@echo ' '

PDM_APP.srec: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O srec $(EXECUTABLES) "PDM_APP.srec"
	@echo 'Finished building: $@'
	@echo ' '

PDM_APP.symbolsrec: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O symbolsrec $(EXECUTABLES) "PDM_APP.symbolsrec"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) PDM_APP.bin PDM_APP.elf PDM_APP.hex PDM_APP.list PDM_APP.map PDM_APP.srec PDM_APP.symbolsrec PDM_APP.verilog default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN) $(OBJCOPY_VERILOG) $(OBJCOPY_SREC) $(OBJCOPY_SYMBOLSREC)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
