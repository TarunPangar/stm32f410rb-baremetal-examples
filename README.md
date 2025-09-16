# STM32F410RB Bare-Metal Examples

This repository contains simple **bare-metal, register-level projects** for the STM32F410RB Nucleo board.  
All code is written in **C** without using HAL or CMSIS drivers — the goal is to learn and understand how the MCU peripherals work at the lowest level.

---

## Projects
- **001hello_world_2** – minimal startup project (blinking as "Hello World" of embedded)  
- **002Clock_adc1_bit_enable** – enable RCC clock and configure ADC1  
- **003LED_TOGGLE** – toggle the on-board User LED (LD2, connected to PA5)  

---

## Requirements
- **Board**: Nucleo-F410RB (STM32F410RBT6 MCU)  
- **Toolchain**: STM32CubeIDE (or any ARM-GCC based toolchain with Make/CMake support)  
- **Debugger/Programmer**: ST-LINK (on-board debugger)  
- **Host OS**: Linux / Windows / macOS  

---

## Getting Started

1. **Clone the repository**
   ```bash
   git clone https://github.com/TarunPangar/stm32f410rb-baremetal-examples.git
   cd stm32f410rb-baremetal-examples/
   ```
2. **Open in STM32CubeIDE**
- Import as an existing workspace project.  
- Build and flash to the Nucleo board.  

3. **Alternative (ARM-GCC and st-flash/openocd)**
- Build with `arm-none-eabi-gcc`  
- Flash using `st-flash` or `openocd`  

4. **Connect the board via USB (ST-LINK)**

5. **Debug/Run**
- Use the integrated debugger to program and run examples.  
- For projects using UART, open a serial terminal at `115200 baud`.  

---

## Learning Goals
- Understand how to enable peripheral clocks via RCC registers.  
- Configure GPIO modes and drive pins directly using registers.  
- Toggle on-board LEDs and experiment with bit-level operations.  
- Learn how to set up ADC clocking at the register level.  

---

## Future Additions
- UART transmit/receive examples  
- External interrupt (EXTI) handling  
- Timer-based LED blinking  
- SPI/I2C peripheral bring-up  

---

## License
This repository is licensed under the MIT License.  
See [LICENSE](LICENSE) for details.

