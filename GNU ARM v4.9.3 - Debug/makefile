################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include emlib/subdir.mk
-include FatFS/src/option/subdir.mk
-include FatFS/src/subdir.mk
-include FatFS/subdir.mk
-include Calendar/subdir.mk
-include CMSIS/EFM32WG/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: MADRE2.1.axf

# Tool invocations
MADRE2.1.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -T "MADRE2.1.ld" -Xlinker --gc-sections -Xlinker -Map="MADRE2.1.map" -mfpu=fpv4-sp-d16 -mfloat-abi=softfp --specs=nano.specs -o MADRE2.1.axf "./CMSIS/EFM32WG/startup_efm32wg.o" "./CMSIS/EFM32WG/system_efm32wg.o" "./Calendar/clock_tc.o" "./Calendar/crystal_parameters.o" "./Calendar/main_calendar_tc.o" "./FatFS/silabs_diskio.o" "./FatFS/src/ff.o" "./FatFS/src/option/syscall.o" "./FatFS/src/option/unicode.o" "./emlib/dmactrl.o" "./emlib/dmadrv.o" "./emlib/em_adc.o" "./emlib/em_cmu.o" "./emlib/em_core.o" "./emlib/em_dma.o" "./emlib/em_emu.o" "./emlib/em_gpio.o" "./emlib/em_int.o" "./emlib/em_leuart.o" "./emlib/em_msc.o" "./emlib/em_rtc.o" "./emlib/em_system.o" "./emlib/em_timer.o" "./emlib/em_usart.o" "./emlib/microsd.o" "./src/epilometer_sampling.o" "./src/epsilometer_AUX.o" "./src/epsilometer_CMU_init.o" "./src/epsilometer_DMA.o" "./src/epsilometer_GPIO_init.o" "./src/epsilometer_SDcard.o" "./src/epsilometer_TIMER_init.o" "./src/epsilometer_altimeter.o" "./src/epsilometer_analog.o" "./src/epsilometer_coms.o" "./src/epsilometer_main.o" "./src/epsilometer_menu.o" -lm -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: MADRE2.1.hex'
	arm-none-eabi-objcopy -O ihex "MADRE2.1.axf" "MADRE2.1.hex"
	@echo ' '

	@echo 'Building bin file: MADRE2.1.bin'
	arm-none-eabi-objcopy -O binary "MADRE2.1.axf" "MADRE2.1.bin"
	@echo ' '

	@echo 'Building s37 file: MADRE2.1.s37'
	arm-none-eabi-objcopy -O srec "MADRE2.1.axf" "MADRE2.1.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "MADRE2.1.axf"
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) MADRE2.1.axf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
