#======================
# Compiler Settings
#======================
MCU = atmega32
F_CPU = 8000000UL
CC = avr-gcc
OBJCOPY = avr-objcopy
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall

#======================
# Project Structure
#======================
BUILD_DIR = build

#======================
# Source Files
#======================
SRC = \
MCAL/DIO/DIO_Program.c \
MCAL/ADC/ADC_Program.c \
MCAL/EXTI/EXTI_Program.c \
MCAL/Timer/T0_Program.c \
MCAL/Uart/Uart_Program.c \
HAL/LED/LED_Program.c \
HAL/LDR/LDR_Program.c \
HAL/LM35/LM35_Program.c \
HAL/Relay/Relay_Program.c \
HAL/LCD/LCD_Program.c \
HAL/DC/DC_Program.c \
HAL/Btn/Btn_Program.c \
HAL/HC05/HC05_Program.c \
APP/ZoneControl/ZoneControl_Program.c \
APP/ModeControl/ModeControl_Program.c \
main.c

#======================
# Object Files
#======================
OBJ = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC))

#======================
# Target Executable
#======================
TARGET = MultiZone.elf
HEX = MultiZone.hex

#======================
# Rules
#======================
all: $(BUILD_DIR) $(HEX)

# Create build directory if not exists
$(BUILD_DIR):
	if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)

# Compile each source file
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@) 2>nul || true
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files to ELF
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# Convert ELF to HEX
$(HEX): $(TARGET)
	$(OBJCOPY) -O ihex -R .eeprom $(TARGET) $(HEX)

# Clean build files
clean:
	del /Q /F $(BUILD_DIR)\* 2>nul
	del /Q /F $(TARGET) 2>nul
	del /Q /F $(HEX) 2>nul
