#include "stm32f303xe.h"

// Connects a button to PC2
static void setup_button_0()
{
	// Sets up PC2 as input
	RCC -> AHBENR |= RCC_AHBENR_GPIOCEN;
	GPIOC -> MODER &= ~(GPIO_MODER_MODER2_Msk);
	
	// Configures interrupt line for button
	RCC -> APB2ENR |= RCC_APB2ENR_SYSCFGEN;
	SYSCFG -> EXTICR[0] &= ~(SYSCFG_EXTICR1_EXTI2_Msk);
	SYSCFG -> EXTICR[0] |= SYSCFG_EXTICR1_EXTI2_PC;
	
	// Sets up EXTI2 interrupt line
	EXTI -> IMR |= EXTI_IMR_MR2;
	EXTI -> FTSR |= EXTI_FTSR_FT2; // Set up to trigger on rising edge
	
	// Enable interrupt
	NVIC_EnableIRQ(EXTI2_TSC_IRQn);
}

// Connects a button to PF1
static void setup_button_1()
{
		// Sets up PF1 as input
	RCC -> AHBENR |= RCC_AHBENR_GPIOFEN;
	GPIOF -> MODER &= ~(GPIO_MODER_MODER1_Msk);
	
	// Configures interrupt line for button
	RCC -> APB2ENR |= RCC_APB2ENR_SYSCFGEN;
	SYSCFG -> EXTICR[0] &= ~(SYSCFG_EXTICR1_EXTI1_Msk);
	SYSCFG -> EXTICR[0] |= SYSCFG_EXTICR1_EXTI1_PF;
	
	// Sets up EXTI1 interrupt line
	EXTI -> IMR |= EXTI_IMR_MR1;
	EXTI -> FTSR |= EXTI_FTSR_FT1; // Set up to trigger on falling trigger
	
	// Enable interrupt
	NVIC_EnableIRQ(EXTI1_IRQn);
}
