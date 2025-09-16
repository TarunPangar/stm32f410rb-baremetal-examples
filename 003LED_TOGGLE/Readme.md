# STM32F410RB - Toggle User LED (LD2)

This example shows how to toggle the **on-board User LED (LD2)** connected to **PA5** on the STM32F410RB Nucleo board using **bare-metal register programming**.

---

## Steps

1. **Enable RCC clock for GPIOA**
   - Register: `RCC_AHB1ENR` (RCC base `0x40023800`, offset `0x30`)
   - Action: Set bit `0` → enables clock for GPIOA

2. **Configure PA5 as Output**
   - Register: `GPIOA_MODER` (GPIOA base `0x40020000`, offset `0x00`)
   - Pin: PA5 → bits `[11:10]`
   - Value: `01` = General purpose output

3. **Set/Clear PA5 to Toggle LED**
   - Register: `GPIOA_ODR` (offset `0x14`)
   - Bit `5`: `1 = LED ON`, `0 = LED OFF`

