#include "stm32f303xe.h"

#define HIGH 1
#define LOW 0

struct gpioPin
{
	char port;
	int pin;
};

// Setup GPIO pin for output
static void setup_gpio(struct gpioPin io)
{
	switch (io.port)
	{
		case 'A':
			RCC -> AHBENR |= RCC_AHBENR_GPIOAEN;
			GPIOA -> MODER |= (1 << (2 * io.pin));
			break;
		
		case 'B':
			RCC -> AHBENR |= RCC_AHBENR_GPIOBEN;
			GPIOB -> MODER |= (1 << (2 * io.pin));
			break;
		
		case 'C':
			RCC -> AHBENR |= RCC_AHBENR_GPIOCEN;
			GPIOC -> MODER |= (1 << (2 * io.pin));
			break;
		
		case 'D':
			RCC -> AHBENR |= RCC_AHBENR_GPIODEN;
			GPIOD -> MODER |= (1 << (2 * io.pin));
			break;
		
		case 'E':
			RCC -> AHBENR |= RCC_AHBENR_GPIOEEN;
			GPIOE -> MODER |= (1 << (2 * io.pin));
			break;
		
		case 'F':
			RCC -> AHBENR |= RCC_AHBENR_GPIOFEN;
			GPIOF -> MODER |= (1 << (2 * io.pin));
			break;
		
		case 'G':
			RCC -> AHBENR |= RCC_AHBENR_GPIOGEN;
			GPIOG -> MODER |= (1 << (2 * io.pin));
			break;
		
		case 'H':
			RCC -> AHBENR |= RCC_AHBENR_GPIOHEN;
			GPIOH -> MODER |= (1 << (2 * io.pin));
			break;
	}
}

// Sets state of output pin (1 for HIGH, 0 for LOW)
static void write_gpio(struct gpioPin io, int state)
{
	switch (io.port)
	{
		case 'A':
			if (state == HIGH)
			{
				GPIOA -> BSRR |= (1 << (io.pin));
			}
			else
			{
				GPIOA -> BSRR |= (1 << (16 + (io.pin)));
			}
			break;
			
		case 'B':
			if (state == HIGH)
			{
				GPIOB -> BSRR |= (1 << (io.pin));
			}
			else
			{
				GPIOB -> BSRR |= (1 << (16 + (io.pin)));
			}
			break;	
		
		case 'C':
			if (state == HIGH)
			{
				GPIOC -> BSRR |= (1 << (io.pin));
			}
			else
			{
				GPIOC -> BSRR |= (1 << (16 + (io.pin)));
			}
			break;
			
		case 'D':
			if (state == HIGH)
			{
				GPIOD -> BSRR |= (1 << (io.pin));
			}
			else
			{
				GPIOD -> BSRR |= (1 << (16 + (io.pin)));
			}
			break;
				
		case 'E':
			if (state == HIGH)
			{
				GPIOE -> BSRR |= (1 << (io.pin));
			}
			else
			{
				GPIOE -> BSRR |= (1 << (16 + (io.pin)));
			}
			break;
			
		case 'F':
			if (state == HIGH)
			{
				GPIOF -> BSRR |= (1 << (io.pin));
			}
			else
			{
				GPIOF -> BSRR |= (1 << (16 + (io.pin)));
			}
			break;	
		
		case 'G':
			if (state == HIGH)
			{
				GPIOG -> BSRR |= (1 << (io.pin));
			}
			else
			{
				GPIOG -> BSRR |= (1 << (16 + (io.pin)));
			}
			break;	
		
		case 'H':
			if (state == HIGH)
			{
				GPIOH -> BSRR |= (1 << (io.pin));
			}
			else
			{
				GPIOH -> BSRR |= (1 << (16 + (io.pin)));
			}
			break;	
	}
}