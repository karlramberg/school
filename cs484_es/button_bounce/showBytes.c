#include<avr/io.h>
#include"delay.h"
#include"setlowandtime.h"

void showBytes(uint32_t n) {
		PINB |= (1<<PB5);
		PORTD = (n>>24);
		delay1ms(5000);

		PINB |= (1<<PB5);
		PORTD = (n>>16);
		delay1ms(5000);

		PINB |= (1<<PB5);
		PORTD = (n>>8);
		delay1ms(5000);

		PINB |= (1<<PB5);
		PORTD = (n>>0);
		delay1ms(5000);
}


void main() {
		DDRD = 0xff; // all out
		DDRB = 0xfe; // PB0 in, rest out
		showBytes(setLowAndTime());
}
