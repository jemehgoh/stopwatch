#include "stm32f303xe.h"
#include "display.h"
#include "timer.h"
#include "button.h"

static volatile int secs = 0;
static volatile int mins = 0;
static volatile int isRunning = 0; // Used to start and stop stopwatch
static volatile int isSplit = 0; // To indicate split
static volatile unsigned int counter = 0;
static volatile unsigned int prev_counter_0 = 0;
static volatile unsigned int prev_counter_1 = 0;
static struct displayDigit hunds;
static struct displayDigit tens;
static struct displayDigit ones;

// ISR for Timer 3
void TIM3_IRQHandler(void)
{
	counter++;
	if (isRunning && !(counter % 30))
	{
		secs++;
		if (secs == 60)
		{
			secs = 0;
			mins++;
			if (mins == 100)
			{
				mins = 0;
			}
		}
}
	
	TIM3 -> SR &= ~(TIM_SR_UIF);
}

// ISR for button 0
void EXTI2_TSC_IRQHandler(void)
{
	unsigned int curr_counter = counter;
	if (curr_counter - prev_counter_0 > 50)
	{
		isRunning = 1 - isRunning; // Starts or stops stopwatch
		EXTI -> PR |= EXTI_PR_PR2;
		prev_counter_0 = curr_counter;
	}
}

// ISR for button 1
void EXTI1_IRQHandler(void)
{
	unsigned int curr_counter = counter;
	if (curr_counter - prev_counter_1 > 50)
	{
		if (isRunning)
		{
			// Display split
			isSplit = 1 - isSplit;
		}
		else
		{
			// Reset stopwatch if timer is stopped
			mins = 0;
			secs = 0;
		}
		prev_counter_1 = curr_counter;
	}
	EXTI -> PR |= EXTI_PR_PR1;
}

int main()
{
	struct displayDigit thous = make_digit('C', 3, 'C', 0, 'C', 1, 'B' , 0, 'A', 4, 'A', 1, 'A', 0);
	hunds = make_digit('A', 8, 'A', 9, 'A', 10, 'C' , 7, 'B', 5, 'B', 6, 'B', 10);
	tens = make_digit('C', 4, 'B', 13, 'B', 14, 'B', 15, 'B', 1, 'B', 2, 'B', 11);
	ones = make_digit('A', 7, 'A', 6, 'A', 5, 'B', 12, 'A', 11, 'A', 12, 'C', 5);
	setup_digit(thous);
	setup_digit(hunds);
	setup_digit(tens);
	setup_digit(ones);
	setup_button_0();
	setup_button_1();
	setup_TIM3(8, 65355);
	start_TIM3();
	while (1)
	{
		if (!isSplit)
		{
			write_digit(thous, mins / 10);
			write_digit(hunds, mins % 10);
			write_digit(tens, secs / 10);
			write_digit(ones, secs % 10);
		}
	}
}
