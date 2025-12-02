# ==== Project ====
TARGET = blink
BUILD_DIR = build

# ==== Toolchain ====
CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
OBJCOPY = arm-none-eabi-objcopy

# ==== MCU ====
MCU = cortex-m4
FPU = -mfpu=fpv4-sp-d16 -mfloat-abi=hard
CFLAGS = -mcpu=$(MCU) $(FPU) -mthumb -O0 -g3 -Wall -ffunction-sections -fdata-sections -DSTM32F410Rx
LDFLAGS = -T linker.ld -Wl,--gc-sections

# ==== Includes ====
SDK_ROOT = ../../STM32CubeF4
FREERTOS_ROOT = ../../FreeRTOS

INCLUDES = -I$(SDK_ROOT)/Drivers/CMSIS/Include \
           -I$(SDK_ROOT)/Drivers/CMSIS/Device/ST/STM32F4xx/Include \
		   -I$(FREERTOS_ROOT)/include \
		   -I$(FREERTOS_ROOT)/portable/GCC/ARM_CM4F \
		   -Isrc \
		   -I.

CFLAGS += $(INCLUDES)

.PHONY: all

# FreeRTOS Kernel sources
FREERTOS_SRC = \
    $(FREERTOS_ROOT)/tasks.c \
    $(FREERTOS_ROOT)/queue.c \
    $(FREERTOS_ROOT)/list.c \
    $(FREERTOS_ROOT)/timers.c \
    $(FREERTOS_ROOT)/event_groups.c \
    $(FREERTOS_ROOT)/stream_buffer.c \
    $(FREERTOS_ROOT)/croutine.c \
    $(FREERTOS_ROOT)/portable/GCC/ARM_CM4F/port.c \
	$(FREERTOS_ROOT)/portable/MemMang/heap_4.c

SRC = \
    src/main.c \
    src/blink.c \
	src/syscalls.c \
    startup_stm32f410xx.s \
    $(FREERTOS_SRC) \
	$(SDK_ROOT)/Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.c


OBJ = $(addprefix $(BUILD_DIR)/, $(notdir $(SRC:.c=.o)))
OBJ := $(OBJ:.s=.o)

# ==== Rules ====
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: src/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(FREERTOS_ROOT)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(FREERTOS_ROOT)/portable/GCC/ARM_CM4F/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(FREERTOS_ROOT)/portable/MemMang/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: %.s | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@
	$(OBJCOPY) -O binary $@ $(BUILD_DIR)/$(TARGET).bin

all: $(BUILD_DIR)/$(TARGET).elf

$(BUILD_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)

flash: all
	openocd -f board/st_nucleo_f4.cfg -c "program $(BUILD_DIR)/$(TARGET).elf verify reset exit"

debug:
	openocd -f board/st_nucleo_f4.cfg &
	sleep 1
	gdb-multiarch build/blink.elf -ex "target remote :3333" -ex "monitor reset halt"

