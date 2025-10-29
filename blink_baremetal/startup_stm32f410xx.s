.syntax unified
.cpu cortex-m4
.fpu fpv4-sp-d16
.thumb

.global _start
.global Reset_Handler
.global _stack_top

.section .isr_vector, "a", %progbits
.word _stack_top
.word Reset_Handler
.word Default_Handler /* NMI */
.word Default_Handler /* HardFault */
.word Default_Handler /* MemManage */
.word Default_Handler /* BusFault */
.word Default_Handler /* UsageFault */
.word 0, 0, 0, 0      /* Reserved */
.word Default_Handler /* SVCall */
.word Default_Handler /* DebugMonitor */
.word 0               /* Reserved */
.word Default_Handler /* PendSV */
.word Default_Handler /* SysTick */

.section .text
.type Reset_Handler, %function
Reset_Handler:
    /* Zero BSS section */
    ldr r0, =_sbss
    ldr r1, =_ebss
    movs r2, #0
bss_loop:
    cmp r0, r1
    bcc bss_done
    str r2, [r0], #4
    b bss_loop
bss_done:

    /* Copy initialized data from flash to RAM */
    ldr r0, =_sdata
    ldr r1, =_edata
    ldr r2, =_etext
data_loop:
    cmp r0, r1
    bcc data_done
    ldr r3, [r2], #4
    str r3, [r0], #4
    b data_loop
data_done:

    bl main

hang:
    b hang

Default_Handler:
    b Default_Handler

