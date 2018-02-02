################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Calendar/clock_tc.c \
../Calendar/crystal_parameters.c \
../Calendar/main_calendar_tc.c 

OBJS += \
./Calendar/clock_tc.o \
./Calendar/crystal_parameters.o \
./Calendar/main_calendar_tc.o 

C_DEPS += \
./Calendar/clock_tc.d \
./Calendar/crystal_parameters.d \
./Calendar/main_calendar_tc.d 


# Each subdirectory must supply rules for building sources it contributes
Calendar/clock_tc.o: ../Calendar/clock_tc.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFM32WG842F256=1' -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/emlib" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/Calendar" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/inc" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src/option" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/drivers" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/bsp" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/Device/SiliconLabs/EFM32WG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/config" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"Calendar/clock_tc.d" -MT"Calendar/clock_tc.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Calendar/crystal_parameters.o: ../Calendar/crystal_parameters.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFM32WG842F256=1' -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/emlib" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/Calendar" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/inc" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src/option" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/drivers" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/bsp" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/Device/SiliconLabs/EFM32WG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/config" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"Calendar/crystal_parameters.d" -MT"Calendar/crystal_parameters.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Calendar/main_calendar_tc.o: ../Calendar/main_calendar_tc.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DDEBUG=1' '-DEFM32WG842F256=1' -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/emlib" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/Calendar" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/inc" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src" -I"/Users/aleboyer/SimplicityStudio/v4_workspace/MADRE2.1/FatFS/src/option" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/drivers" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//hardware/kit/common/bsp" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/Device/SiliconLabs/EFM32WG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/config" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v2.0//platform/emdrv/dmadrv/inc" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"Calendar/main_calendar_tc.d" -MT"Calendar/main_calendar_tc.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

