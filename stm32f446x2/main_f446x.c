#include <stdint.h>
// register address
#define RCC_BASE 		0x40023800
#define GPIOA_BASE 		0x40020000
#define RCC_AHB1ENR 		*(volatile uint32_t *) (RCC_BASE + 0x30)
#define GPIOA_MODER 		*(volatile uint32_t *) (GPIOA_BASE + 0x00)
#define GPIOA_PUPDR 		*(volatile uint32_t *) (GPIOA_BASE + 0x0C)
#define GPIOA_OTYPER 		*(volatile uint32_t *) (GPIOA_BASE + 0x04)
#define GPIOA_OSPEEDR 		*(volatile uint32_t *) (GPIOA_BASE + 0x08)

#define GPIOA_BSRR 		*(volatile uint32_t *) (GPIOA_BASE + 0x18)

// bit fields
#define RCC_GPIOAEN 	(1 << 0)
#define GPIOA05  	(1UL << 5)

int main(void)
{
    /* RCC periph clock enable		*/
    RCC_AHB1ENR   |= RCC_GPIOAEN;

    GPIOA_MODER   &= 0xFFFFF3FF;
    GPIOA_MODER   |= 0x00000400;
    GPIOA_PUPDR   &= 0xFFFFF3FF;
    GPIOA_OTYPER  &= 0xFFFFFFDF;
    GPIOA_OSPEEDR &= 0xFFFFF3FF;

    while(1)
    {
	/* Set the GPIOA.5        */
        GPIOA_BSRR &= GPIOA05;
        for (int i = 0; i < 500000; i++); // arbitrary delay

	/* Reset the GPIOA.5        */
        GPIOA_BSRR &= (GPIOA05 << 16);
        for (int i = 0; i < 500000; i++); // arbitrary delay
    }
}
