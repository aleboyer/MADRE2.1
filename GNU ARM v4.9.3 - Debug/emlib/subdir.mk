################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0/hardware/kit/common/drivers/dmactrl.c \
/Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0/platform/emdrv/dmadrv/src/dmadrv.c \
/Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0/platform/emlib/src/em_adc.c \
/Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0/platform/emlib/src/em_cmu.c \
/Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0/platform/emlib/src/em_core.c \
/Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0/platform/emlib/src/em_dma.c \
/Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0/platform/emlib/src/em_emu.c \
/Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0/platform/emlib/src/em_gpio.c \
/Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0/platform/emlib/src/em_int.c \
/Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0/platform/emlib/src/em_leuart.c \
/Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0/platform/emlib/src/em_rtc.c \
/Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0/platform/emlib/src/em_system.c \
/Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0/platform/emlib/src/em_timer.c \
/Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0/platform/emlib/src/em_usart.c \
/Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0/hardware/kit/common/drivers/microsd.c 

OBJS += \
./emlib/dmactrl.o \
./emlib/dmadrv.o \
./emlib/em_adc.o \
./emlib/em_cmu.o \
./emlib/em_core.o \
./emlib/em_dma.o \
./emlib/em_emu.o \
./emlib/em_gpio.o \
./emlib/em_int.o \
./emlib/em_leuart.o \
./emlib/em_rtc.o \
./emlib/em_system.o \
./emlib/em_timer.o \
./emlib/em_usart.o \
./emlib/microsd.o 

C_DEPS += \
./emlib/dmactrl.d \
./emlib/dmadrv.d \
./emlib/em_adc.d \
./emlib/em_cmu.d \
./emlib/em_core.d \
./emlib/em_dma.d \
./emlib/em_emu.d \
./emlib/em_gpio.d \
./emlib/em_int.d \
./emlib/em_leuart.d \
./emlib/em_rtc.d \
./emlib/em_system.d \
./emlib/em_timer.d \
./emlib/em_usart.d \
./emlib/microsd.d 


# Each subdirectory must supply rules for building sources it contributes
emlib/dmactrl.o: /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0/hardware/kit/common/drivers/dmactrl.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFM32WG842F256=1' -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/emlib" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/Calendar" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/inc" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src/option" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/drivers" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/bsp" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/Device/SiliconLabs/EFM32WG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/config" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"emlib/dmactrl.d" -MT"emlib/dmactrl.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/dmadrv.o: /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0/platform/emdrv/dmadrv/src/dmadrv.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFM32WG842F256=1' -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/emlib" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/Calendar" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/inc" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src/option" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/drivers" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/bsp" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/Device/SiliconLabs/EFM32WG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/config" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"emlib/dmadrv.d" -MT"emlib/dmadrv.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_adc.o: /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0/platform/emlib/src/em_adc.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFM32WG842F256=1' -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/emlib" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/Calendar" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/inc" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src/option" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/drivers" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/bsp" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/Device/SiliconLabs/EFM32WG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/config" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"emlib/em_adc.d" -MT"emlib/em_adc.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_cmu.o: /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0/platform/emlib/src/em_cmu.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFM32WG842F256=1' -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/emlib" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/Calendar" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/inc" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src/option" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/drivers" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/bsp" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/Device/SiliconLabs/EFM32WG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/config" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"emlib/em_cmu.d" -MT"emlib/em_cmu.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_core.o: /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0/platform/emlib/src/em_core.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFM32WG842F256=1' -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/emlib" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/Calendar" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/inc" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src/option" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/drivers" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/bsp" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/Device/SiliconLabs/EFM32WG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/config" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"emlib/em_core.d" -MT"emlib/em_core.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_dma.o: /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0/platform/emlib/src/em_dma.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFM32WG842F256=1' -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/emlib" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/Calendar" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/inc" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src/option" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/drivers" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/bsp" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/Device/SiliconLabs/EFM32WG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/config" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"emlib/em_dma.d" -MT"emlib/em_dma.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_emu.o: /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0/platform/emlib/src/em_emu.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFM32WG842F256=1' -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/emlib" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/Calendar" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/inc" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src/option" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/drivers" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/bsp" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/Device/SiliconLabs/EFM32WG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/config" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"emlib/em_emu.d" -MT"emlib/em_emu.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_gpio.o: /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0/platform/emlib/src/em_gpio.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFM32WG842F256=1' -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/emlib" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/Calendar" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/inc" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src/option" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/drivers" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/bsp" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/Device/SiliconLabs/EFM32WG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/config" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"emlib/em_gpio.d" -MT"emlib/em_gpio.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_int.o: /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0/platform/emlib/src/em_int.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFM32WG842F256=1' -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/emlib" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/Calendar" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/inc" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src/option" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/drivers" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/bsp" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/Device/SiliconLabs/EFM32WG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/config" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"emlib/em_int.d" -MT"emlib/em_int.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_leuart.o: /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0/platform/emlib/src/em_leuart.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFM32WG842F256=1' -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/emlib" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/Calendar" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/inc" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src/option" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/drivers" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/bsp" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/Device/SiliconLabs/EFM32WG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/config" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"emlib/em_leuart.d" -MT"emlib/em_leuart.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_rtc.o: /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0/platform/emlib/src/em_rtc.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFM32WG842F256=1' -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/emlib" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/Calendar" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/inc" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src/option" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/drivers" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/bsp" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/Device/SiliconLabs/EFM32WG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/config" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"emlib/em_rtc.d" -MT"emlib/em_rtc.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_system.o: /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0/platform/emlib/src/em_system.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFM32WG842F256=1' -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/emlib" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/Calendar" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/inc" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src/option" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/drivers" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/bsp" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/Device/SiliconLabs/EFM32WG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/config" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"emlib/em_system.d" -MT"emlib/em_system.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_timer.o: /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0/platform/emlib/src/em_timer.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFM32WG842F256=1' -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/emlib" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/Calendar" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/inc" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src/option" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/drivers" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/bsp" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/Device/SiliconLabs/EFM32WG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/config" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"emlib/em_timer.d" -MT"emlib/em_timer.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/em_usart.o: /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0/platform/emlib/src/em_usart.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFM32WG842F256=1' -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/emlib" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/Calendar" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/inc" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src/option" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/drivers" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/bsp" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/Device/SiliconLabs/EFM32WG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/config" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"emlib/em_usart.d" -MT"emlib/em_usart.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

emlib/microsd.o: /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0/hardware/kit/common/drivers/microsd.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFM32WG842F256=1' -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/emlib" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/Calendar" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/inc" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src/option" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/drivers" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/bsp" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/Device/SiliconLabs/EFM32WG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/config" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"emlib/microsd.d" -MT"emlib/microsd.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


