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
CFLAGS = -mcpu=$(MCU) $(FPU) -mthumb -O2 -Wall -ffunction-sections -fdata-sections
LDFLAGS = -T linker.ld -nostartfiles -Wl,--gc-sections

# ==== Includes ====
SDK_ROOT = ../../STM32CubeF4
INCLUDES = -I$(SDK_ROOT)/Drivers/CMSIS/Include \
           -I$(SDK_ROOT)/Drivers/CMSIS/Device/ST/STM32F4xx/Include

CFLAGS += $(INCLUDES)


# ==== Files ====
SRC = src/main.c startup_stm32f410xx.s
# startup_stm32f410xx.s
OBJ = $(addprefix $(BUILD_DIR)/, $(notdir $(SRC:.c=.o)))
OBJ := $(OBJ:.s=.o)

# ==== Rules ====
$(BUILD_DIR)/%.o: src/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: %.s | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@
	$(OBJCOPY) -O binary $@ $(BUILD_DIR)/$(TARGET).bin

all: $(BUILD_DIR)/$(TARGET).elf

clean:
	rm -rf $(BUILD_DIR)

flash: all
	openocd -f board/st_nucleo_f4.cfg -c "program $(BUILD_DIR)/$(TARGET).elf verify reset exit"

