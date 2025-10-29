#define STM32F410Rx

//#include "stm32f4xx.h"

#include <stdint.h>

#define AHB1_BASE_ADDR		0x40023800UL
#define GPIO_AHB1_OFFSET	0x30UL

#define GPIOA_BASE_ADDR		0x40020000UL
#define GPIOA_MODER_OFFSET	0x00UL
#define GPIOA_ODR_OFFSET	0x14UL

static void delay(volatile uint32_t count) {
    while(count--);
}

int main(void)
{
	volatile uint32_t *pRccAhb1rstr = (volatile uint32_t *) (AHB1_BASE_ADDR + GPIO_AHB1_OFFSET);
	volatile uint32_t *pGpioPa5Dir = (volatile uint32_t *) (GPIOA_BASE_ADDR + GPIOA_MODER_OFFSET);
	volatile uint32_t *pGpioPa5Val = (volatile uint32_t *) (GPIOA_BASE_ADDR + GPIOA_ODR_OFFSET);

	// Enable clock for GPIOA AHB1 Bus - 0th bit
	*pRccAhb1rstr |= (1 << 0);

	// Enable PA5 as output -> so MODER5[11:10] = 01
	*pGpioPa5Dir &= ~(0x3 << 10);	// clear bits 10 and 11
	*pGpioPa5Dir |= (0x1 << 10);		// Set bit 10

	// Toggle PA5 value as 1/0 for led ON/OFF
	while (1) {
		*pGpioPa5Val ^= (0x1 << 5);
		delay(1000000);
	}

    /* Loop forever */
	for(;;);
}
