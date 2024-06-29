#include "stm32f303xe.h"
#include "gpio.h"

// Struct to store the different pins for a 7-segment digit
struct displayDigit
{
	struct gpioPin a_segment; // pin for segment A
	struct gpioPin b_segment; // pin for segment B
	struct gpioPin c_segment; // pin for segment C
	struct gpioPin d_segment; // pin for segment D
	struct gpioPin e_segment; // pin for segment E
	struct gpioPin f_segment; // pin for segment F
	struct gpioPin g_segment; // pin for segment F
};

// Stores different states for the 7-segment - ZERO to NINE display the digit, while CLEAR clears the display
enum displayState
{
	ZERO = 0,
	ONE = 1,
	TWO = 2,
	THREE = 3,
	FOUR = 4,
	FIVE = 5,
	SIX = 6,
	SEVEN = 7,
	EIGHT = 8,
	NINE = 9,
	CLEAR = 10
};

// Creates a gpioPin struct, given the port and pin
static struct gpioPin make_pin(char port, int pin)
{
	struct gpioPin out;
	out.port = port;
	out.pin = pin;
	return out;
}

static struct displayDigit make_digit(char a_port, int a_pin, char b_port, int b_pin, char c_port, int c_pin, char d_port, int d_pin, char e_port, int e_pin, char f_port, int f_pin, char g_port, int g_pin)
{
	static struct displayDigit out;
	
	// Sets the different pins of the digit
	out.a_segment = make_pin(a_port, a_pin);
	out.b_segment = make_pin(b_port, b_pin);
	out.c_segment = make_pin(c_port, c_pin);
	out.d_segment = make_pin(d_port, d_pin);
	out.e_segment = make_pin(e_port, e_pin);
	out.f_segment = make_pin(f_port, f_pin);
	out.g_segment = make_pin(g_port, g_pin);
	
	return out;
}

// Sets up GPIO pins connected to digit display
static void setup_digit(struct displayDigit digit)
{
	setup_gpio(digit.a_segment);
	setup_gpio(digit.b_segment);
	setup_gpio(digit.c_segment);
	setup_gpio(digit.d_segment);
	setup_gpio(digit.e_segment);
	setup_gpio(digit.f_segment);
	setup_gpio(digit.g_segment);
}

// Writes a digit to the display, or clears it
static void write_digit(struct displayDigit digit, int state)
{
	switch (state)
	{
		case 0:
			write_gpio(digit.a_segment, HIGH);
			write_gpio(digit.b_segment, HIGH);
		  write_gpio(digit.c_segment, HIGH);
			write_gpio(digit.d_segment, HIGH);
			write_gpio(digit.e_segment, HIGH);
			write_gpio(digit.f_segment, HIGH);
			write_gpio(digit.g_segment, LOW);
			break;
		
		case 1:
			write_gpio(digit.a_segment, LOW);
			write_gpio(digit.b_segment, HIGH);
		  write_gpio(digit.c_segment, HIGH);
			write_gpio(digit.d_segment, LOW);
			write_gpio(digit.e_segment, LOW);
			write_gpio(digit.f_segment, LOW);
			write_gpio(digit.g_segment, LOW);
			break;
		
		case 2:
			write_gpio(digit.a_segment, HIGH);
			write_gpio(digit.b_segment, HIGH);
		  write_gpio(digit.c_segment, LOW);
			write_gpio(digit.d_segment, HIGH);
			write_gpio(digit.e_segment, HIGH);
			write_gpio(digit.f_segment, LOW);
			write_gpio(digit.g_segment, HIGH);
			break;
		
		case 3:
			write_gpio(digit.a_segment, HIGH);
			write_gpio(digit.b_segment, HIGH);
		  write_gpio(digit.c_segment, HIGH);
			write_gpio(digit.d_segment, HIGH);
			write_gpio(digit.e_segment, LOW);
			write_gpio(digit.f_segment, LOW);
			write_gpio(digit.g_segment, HIGH);
			break;
		
		case 4:
			write_gpio(digit.a_segment, LOW);
			write_gpio(digit.b_segment, HIGH);
		  write_gpio(digit.c_segment, HIGH);
			write_gpio(digit.d_segment, LOW);
			write_gpio(digit.e_segment, LOW);
			write_gpio(digit.f_segment, HIGH);
			write_gpio(digit.g_segment, HIGH);
			break;
		
		case 5:
			write_gpio(digit.a_segment, HIGH);
			write_gpio(digit.b_segment, LOW);
		  write_gpio(digit.c_segment, HIGH);
			write_gpio(digit.d_segment, HIGH);
			write_gpio(digit.e_segment, LOW);
			write_gpio(digit.f_segment, HIGH);
			write_gpio(digit.g_segment, HIGH);
			break;
		
		case 6:
			write_gpio(digit.a_segment, HIGH);
			write_gpio(digit.b_segment, LOW);
		  write_gpio(digit.c_segment, HIGH);
			write_gpio(digit.d_segment, HIGH);
			write_gpio(digit.e_segment, HIGH);
			write_gpio(digit.f_segment, HIGH);
			write_gpio(digit.g_segment, HIGH);
			break;
		
		case 7:
			write_gpio(digit.a_segment, HIGH);
			write_gpio(digit.b_segment, HIGH);
		  write_gpio(digit.c_segment, HIGH);
			write_gpio(digit.d_segment, LOW);
			write_gpio(digit.e_segment, LOW);
			write_gpio(digit.f_segment, LOW);
			write_gpio(digit.g_segment, LOW);
			break;
		
		case 8:
			write_gpio(digit.a_segment, HIGH);
			write_gpio(digit.b_segment, HIGH);
		  write_gpio(digit.c_segment, HIGH);
			write_gpio(digit.d_segment, HIGH);
			write_gpio(digit.e_segment, HIGH);
			write_gpio(digit.f_segment, HIGH);
			write_gpio(digit.g_segment, HIGH);
			break;

		case 9:
			write_gpio(digit.a_segment, HIGH);
			write_gpio(digit.b_segment, HIGH);
		  write_gpio(digit.c_segment, HIGH);
			write_gpio(digit.d_segment, HIGH);
			write_gpio(digit.e_segment, LOW);
			write_gpio(digit.f_segment, HIGH);
			write_gpio(digit.g_segment, HIGH);
			break;
		
		case 10:
			write_gpio(digit.a_segment, LOW);
			write_gpio(digit.b_segment, LOW);
		  write_gpio(digit.c_segment, LOW);
			write_gpio(digit.d_segment, LOW);
			write_gpio(digit.e_segment, LOW);
			write_gpio(digit.f_segment, LOW);
			write_gpio(digit.g_segment, LOW);
			break;
	}
}
