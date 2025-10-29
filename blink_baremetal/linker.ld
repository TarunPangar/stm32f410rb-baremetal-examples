/* STM32F410RB memory map */
MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 128K
    RAM (rwx)   : ORIGIN = 0x20000000, LENGTH = 32K
}

/* Define top of stack */
_stack_top = ORIGIN(RAM) + LENGTH(RAM);

SECTIONS
{
    /* Vector table */
    .isr_vector :
    {
        KEEP(*(.isr_vector))
    } > FLASH

    /* Code and read-only data */
    .text :
    {
        _stext = .;
        *(.text*)
        *(.rodata*)
        _etext = .;
    } > FLASH

    /* Initialized data section */
    .data : AT(_etext)
    {
        _sdata = .;
        *(.data*)
        _edata = .;
    } > RAM

    /* Uninitialized data (zero-initialized) */
    .bss :
    {
        _sbss = .;
        *(.bss*)
        *(COMMON)
        _ebss = .;
    } > RAM

    /* End of program */
    _end = .;
}

