#include <stdint.h>

#define RCC   0x40023800
#define GPIOA 0x40020000

#define GPIOA_MODER *((volatile uint32_t *) GPIOA + 0x0)
#define GPIOA_BSRR  *((volatile uint32_t *) GPIOA + 0x18)
#define RCC_AHB1ENR *((volatile uint32_t *) RCC + 0x30)


int main(){

    RCC_AHB1ENR |= (1 << 0);

    for(int i = 0; i < 10; i++){ // wait for a few cycles
        asm("nop");
    }

    GPIOA_MODER |= (1 << 10); // set PA5 to output
    GPIOA_MODER &= ~(1 << 11);

    GPIOA_BSRR = (1 << 5); // set pin high

    while(1){}
}
