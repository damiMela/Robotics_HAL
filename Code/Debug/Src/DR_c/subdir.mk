################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/DR_c/DR_GPIO.c \
../Src/DR_c/DR_PLL.c \
../Src/DR_c/DR_Systick.c 

OBJS += \
./Src/DR_c/DR_GPIO.o \
./Src/DR_c/DR_PLL.o \
./Src/DR_c/DR_Systick.o 

C_DEPS += \
./Src/DR_c/DR_GPIO.d \
./Src/DR_c/DR_PLL.d \
./Src/DR_c/DR_Systick.d 


# Each subdirectory must supply rules for building sources it contributes
Src/DR_c/DR_GPIO.o: ../Src/DR_c/DR_GPIO.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/DR_c/DR_GPIO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/DR_c/DR_PLL.o: ../Src/DR_c/DR_PLL.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/DR_c/DR_PLL.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/DR_c/DR_Systick.o: ../Src/DR_c/DR_Systick.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DDEBUG -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/DR_c/DR_Systick.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

