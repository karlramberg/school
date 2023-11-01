#include<avr/io.h>
#include<avr/interrupt.h>

// Button bounce detector. Hook a button to PB0 with a pull-up and
// press (and release) it to increment the light. If there is bounce it
// should become apparent.

volatile uint8_t old_pb0 = (1<<PB0); // button released
volatile uint8_t new_pb0;
volatile uint8_t leds = 0x01;

ISR(PCINT0_vect) {
		new_pb0 = PINB & (1<<PB0);
		if (new_pb0 != old_pb0) {
				old_pb0 = new_pb0;
				leds <<= 1;
				if (!leds) leds = 0x01;
				PORTD = leds;
		}
}

void main() {
		DDRD = 0xff;
		PORTD = leds;

		cli();
		PCICR = (1<<PCIE0);
		PCMSK0 = (1<<PCINT0);
		sei();

		while(1);
}
