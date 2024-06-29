#include "stm32f303xe.h"

// Sets up TIM3 for upcounting mode
static void setup_TIM3(uint16_t prescalar, uint16_t reload)
{
	RCC -> APB1ENR |= RCC_APB1ENR_TIM3EN;
	TIM3 -> CR1 &= ~(TIM_CR1_CMS);
	TIM3 -> CR1 &= ~(TIM_CR1_DIR);
	TIM3 -> PSC = prescalar;
	TIM3 -> ARR = reload;
	TIM3 -> CR1 |= TIM_CR1_ARPE;
	
	// Enables TIM3 interrupt (update)
	TIM3 -> DIER |= TIM_DIER_UIE;
	NVIC_EnableIRQ(TIM3_IRQn);
	
	// Starts timer (enable counter)
	// TIM3 -> CR1 |= TIM_CR1_CEN;
}

// Starts TIM3
static void start_TIM3()
{
	TIM3 -> CR1 |= TIM_CR1_CEN;
}

// Stops TIM3
static void stop_TIM3()
{
	TIM3 -> CR1 &= ~(TIM_CR1_CEN);
}
