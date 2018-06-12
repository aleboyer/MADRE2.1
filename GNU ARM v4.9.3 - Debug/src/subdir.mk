################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/epilometer_sampling.c \
../src/epsilometer_AUX.c \
../src/epsilometer_CMU_init.c \
../src/epsilometer_DMA.c \
../src/epsilometer_GPIO_init.c \
../src/epsilometer_SDcard.c \
../src/epsilometer_TIMER_init.c \
../src/epsilometer_altimeter.c \
../src/epsilometer_analog.c \
../src/epsilometer_coms.c \
../src/epsilometer_main.c \
../src/epsilometer_menu.c 

OBJS += \
./src/epilometer_sampling.o \
./src/epsilometer_AUX.o \
./src/epsilometer_CMU_init.o \
./src/epsilometer_DMA.o \
./src/epsilometer_GPIO_init.o \
./src/epsilometer_SDcard.o \
./src/epsilometer_TIMER_init.o \
./src/epsilometer_altimeter.o \
./src/epsilometer_analog.o \
./src/epsilometer_coms.o \
./src/epsilometer_main.o \
./src/epsilometer_menu.o 

C_DEPS += \
./src/epilometer_sampling.d \
./src/epsilometer_AUX.d \
./src/epsilometer_CMU_init.d \
./src/epsilometer_DMA.d \
./src/epsilometer_GPIO_init.d \
./src/epsilometer_SDcard.d \
./src/epsilometer_TIMER_init.d \
./src/epsilometer_altimeter.d \
./src/epsilometer_analog.d \
./src/epsilometer_coms.d \
./src/epsilometer_main.d \
./src/epsilometer_menu.d 


# Each subdirectory must supply rules for building sources it contributes
src/epilometer_sampling.o: ../src/epilometer_sampling.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFM32WG842F256=1' -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/emlib" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/Calendar" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/inc" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src/option" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/drivers" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/bsp" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/Device/SiliconLabs/EFM32WG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/config" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/epilometer_sampling.d" -MT"src/epilometer_sampling.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/epsilometer_AUX.o: ../src/epsilometer_AUX.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFM32WG842F256=1' -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/emlib" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/Calendar" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/inc" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src/option" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/drivers" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/bsp" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/Device/SiliconLabs/EFM32WG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/config" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/epsilometer_AUX.d" -MT"src/epsilometer_AUX.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/epsilometer_CMU_init.o: ../src/epsilometer_CMU_init.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFM32WG842F256=1' -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/emlib" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/Calendar" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/inc" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src/option" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/drivers" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/bsp" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/Device/SiliconLabs/EFM32WG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/config" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/epsilometer_CMU_init.d" -MT"src/epsilometer_CMU_init.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/epsilometer_DMA.o: ../src/epsilometer_DMA.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFM32WG842F256=1' -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/emlib" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/Calendar" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/inc" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src/option" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/drivers" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/bsp" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/Device/SiliconLabs/EFM32WG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/config" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/epsilometer_DMA.d" -MT"src/epsilometer_DMA.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/epsilometer_GPIO_init.o: ../src/epsilometer_GPIO_init.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFM32WG842F256=1' -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/emlib" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/Calendar" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/inc" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src/option" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/drivers" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/bsp" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/Device/SiliconLabs/EFM32WG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/config" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/epsilometer_GPIO_init.d" -MT"src/epsilometer_GPIO_init.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/epsilometer_SDcard.o: ../src/epsilometer_SDcard.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFM32WG842F256=1' -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/emlib" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/Calendar" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/inc" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src/option" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/drivers" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/bsp" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/Device/SiliconLabs/EFM32WG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/config" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/epsilometer_SDcard.d" -MT"src/epsilometer_SDcard.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/epsilometer_TIMER_init.o: ../src/epsilometer_TIMER_init.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFM32WG842F256=1' -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/emlib" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/Calendar" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/inc" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src/option" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/drivers" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/bsp" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/Device/SiliconLabs/EFM32WG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/config" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/epsilometer_TIMER_init.d" -MT"src/epsilometer_TIMER_init.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/epsilometer_altimeter.o: ../src/epsilometer_altimeter.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFM32WG842F256=1' -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/emlib" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/Calendar" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/inc" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src/option" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/drivers" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/bsp" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/Device/SiliconLabs/EFM32WG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/config" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/epsilometer_altimeter.d" -MT"src/epsilometer_altimeter.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/epsilometer_analog.o: ../src/epsilometer_analog.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFM32WG842F256=1' -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/emlib" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/Calendar" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/inc" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src/option" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/drivers" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/bsp" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/Device/SiliconLabs/EFM32WG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/config" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/epsilometer_analog.d" -MT"src/epsilometer_analog.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/epsilometer_coms.o: ../src/epsilometer_coms.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFM32WG842F256=1' -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/emlib" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/Calendar" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/inc" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src/option" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/drivers" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/bsp" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/Device/SiliconLabs/EFM32WG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/config" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/epsilometer_coms.d" -MT"src/epsilometer_coms.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/epsilometer_main.o: ../src/epsilometer_main.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFM32WG842F256=1' -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/emlib" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/Calendar" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/inc" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src/option" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/drivers" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/bsp" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/Device/SiliconLabs/EFM32WG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/config" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/epsilometer_main.d" -MT"src/epsilometer_main.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/epsilometer_menu.o: ../src/epsilometer_menu.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFM32WG842F256=1' -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/emlib" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/Calendar" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/inc" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src/option" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/drivers" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/bsp" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/Device/SiliconLabs/EFM32WG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/config" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"src/epsilometer_menu.d" -MT"src/epsilometer_menu.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


