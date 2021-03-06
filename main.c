#include <stdint.h>

#define RCC   			0x40023800
#define GPIOA_BASE 		0x40020000

#define GPIOA_MODER 	*(volatile uint32_t *) (GPIOA_BASE + 0x0)
#define GPIOA_OTYPER 	*(volatile uint32_t *) (GPIOA_BASE + 0x04)
#define GPIOA_ODR  		*(volatile uint32_t *) (GPIOA_BASE + 0x14)
#define GPIOA_BSRR  	*(volatile uint32_t *) (GPIOA_BASE + 0x18)

#define RCC_AHB1ENR 	*(volatile uint32_t *) (RCC + 0x30)

#define PORTA 		(0)		/* 0 = PORTA	*/
#define LED_PIN    	(5)		/* 5 = PIN5		*/

#define RCC_GPIOAEN 	(1 << PORTA)

int main(){

	//int i_alone;
	//static int i_value=3;
	//static int j_alone;
	//static int jvalue=5;
	
	//j_alone=6;
	
    RCC_AHB1ENR |= RCC_GPIOAEN;				/* Enable clock on PORTA	*/
	
	GPIOA_MODER  &= ~(0x3 << (LED_PIN*2));
	GPIOA_MODER  |=  (0x1 << (LED_PIN*2));
	GPIOA_OTYPER &= ~(1 << LED_PIN);
	
	GPIOA_ODR |= (1 << LED_PIN);			/* LED is ON				*/
	

    while(1){
		GPIOA_ODR ^= (1 << LED_PIN);		/* Toggle the led			*/
		
	for (int i = 0; i < 500000; i++) ;		/* Arbitrary delay			*/
	}
}
