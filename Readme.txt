
Directory structure:
project_root/
├── applications
│   ├── linker.ld
│   ├── Makefile
│   ├── src
│   │   ├── main.c
│   │   └── system_stm32f4xx.c
│   └── startup_stm32f410xx.s
├── FreeRTOS/
└── STM32CubeF4/

Dependencies:
$ sudo apt update
$ sudo apt install gcc-arm-none-eabi gdb-multiarch

Verify installation:
$ arm-none-eabi-gcc --version

Install OpenOCD:
$ sudo apt install openocd
$ openocd --version

Install ST-LINK udev Rules: (OPTIONAL)
(This avoids "permission denied" errors when accessing the board)
$ sudo apt install stlink-tools
$ sudo cp /usr/share/stlink/config/udev/rules.d/49-stlinkv2-1.rules /etc/udev/rules.d/
$ sudo udevadm control --reload-rules
$ sudo udevadm trigger

