// Karl Ramberg
// Code borrowed from Jon Beck
// A 'hello world' program

#include <avr/io.h>

void main()
{
	uint8_t mask = 0b00100000;
	uint8_t data = 0b00100000;
	volatile uint16_t i;
	
	DDRB = mask;
	
	while (1)
	{
		PORTB = data;
		data ^= mask;

		for (i = 65535U; i != 0; i--)
		{
			// do nothing
		}
	}	
}
