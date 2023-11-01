// Karl Ramberg, Paul Ramberg
#include<avr/io.h>
#include<avr/interrupt.h>
#include<avr/sleep.h>

// TODO
// Sound

// Buttons and LEDs
#define LEFT_LED PC1
#define RIGHT_LED PC2
#define LEFT_BUTTON PCINT11
#define RIGHT_BUTTON PCINT0
void flash_lights();

// Timer times
#define MAX_IDLE_TIME 4
#define FLASH_TIME 30
#define WINNER_TIME 100
#define ADC_SCALE 32
#define MIN_STEP_TIME 4

volatile uint8_t step_time;
void step();

// General step timer
volatile uint8_t clock_countdown;
void wait(uint8_t time);
ISR(TIMER0_OVF_vect) {
	clock_countdown--;
} 

// Sleep timer
volatile uint8_t sleep_countdown;
ISR(TIMER1_OVF_vect) {
	sleep_countdown--;
}

// Game state
volatile uint8_t game_over;
volatile uint8_t left_wins;
volatile uint8_t moving_right;

// Left button handler
ISR(PCINT1_vect) {
	// check if pin went low, ignore otherwise
	if (!(PINC & (1<<PC3))) { 
		// reset sleep timer
		TCNT1 = 0; 
		sleep_countdown = MAX_IDLE_TIME;

		// game over if pressed and LED not lit, else continue
		if (!(PINC & (1<<LEFT_LED))) {
			game_over = 1;
			left_wins = 0;
		} else { 
			game_over = 0;
			moving_right = 1;
		}
	}
}

// Right button handler 
ISR(PCINT0_vect) {
	// check if pin went low, ignore otherwise
	if (!(PINB & (1<<PB0))) { 
		// reset sleep timer
		TCNT1 = 0; 
		sleep_countdown = MAX_IDLE_TIME;

		// game over if pressed and LED not lit, else continue
		if (!(PINC & (1<<RIGHT_LED))) {
			game_over = 1;
			left_wins = 1;
		} else { 
			game_over = 0;
			moving_right = 0;
		}
	}
}

void main(void) {
	// set PORTD as outputp
	DDRD = 0xFF; 
	
	// set leftmost and rightmost LED as output, left button and potentiometer as input
	DDRC = (0<<PC0) | (0<<PC3) | (1<<LEFT_LED) | (1<<RIGHT_LED); 

	// set right button to input	
   	DDRB = (0<<PB0);

	// set up ADC at 124kHz, ADC0 (PC0) as input, right justified, internal Vcc as reference
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0); 
	ADMUX = (0<<REFS1) | (1<<REFS0) | (0<<ADLAR) | (0<<MUX3) | (0<<MUX2) | (0<<MUX1) | (0<<MUX0); 

	// set up interrupts
	cli(); 
	PCICR = (1<<PCIE1) | (1<<PCIE0); 	// enable PCINT0 and PCINT1
	PCMSK1 = (1<<LEFT_BUTTON); 			// left button
	PCMSK0 = (1<<RIGHT_BUTTON); 		// right button
	TIMSK0 = (1<<TOIE0);				// timer 0 overflow interrupts
	TIMSK1 = (1<<TOIE1);				// timer 1 overflow interrupts	

	// start sleep timer
	TCCR1B = (1<<CS12) | (0<<CS11) | (1<<CS10); // start timer 1 at 0.238Hz
	sleep_countdown = MAX_IDLE_TIME;			// reset sleep timer 
	TCNT1 = 0;									// reset timer 1 
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);		// set sleep mode to power down

	while (1) {
		// get game speed from potentiometer
		ADCSRA |= (1<<ADSC); 				// start conversion
		while((ADCSRA & (1<< ADIF)) == 0);  // wait to finish
		ADCSRA |= (1<<ADIF); 				// clear ADIF

		uint8_t lo = ADCL;					// get low bytes
		uint8_t hi = ADCH; 					// get high bytes
		uint16_t adc = (hi<<8) | lo;		// combine into a 16-bit int
		step_time = (adc / ADC_SCALE) + MIN_STEP_TIME; // scale to usable speeds

		// starting game state
		game_over = 0;
		moving_right = 1; 
		PORTD = 0x00; 
		PORTC = 0x00;

		sei();
		while (!game_over) {
			// switch directions if needed, else step
			if (PIND == 0x00) { 
				PORTC = 0x00;
				if (moving_right) {
					PORTD = 0x80;
				} else {
					PORTD = 0x01;
				}
			} else { 
				step();
			}
			wait(step_time);
		}

		// game is over, declare winner
		PORTC = left_wins ? (1<<LEFT_LED) : (1<<RIGHT_LED);
		PORTD = 0x00;
		wait(WINNER_TIME);
	
		// sleep if no buttons were pressed lately	
		if (sleep_countdown == 0) {
			flash_lights();	
			sleep_enable();
			sleep_cpu();	
			flash_lights();
			sleep_countdown = MAX_IDLE_TIME;
			cli();
		}
	}
}

void step() {
	if (moving_right) {
		PORTD = (PIND>>1); // step right
		if (PIND == 0x00) { // if overflowed
			PORTC = (1<<RIGHT_LED);
			game_over = 1;
			left_wins = 1;
		}
	} else {
		PORTD = (PIND<<1); // step left
		if (PIND == 0x00) { // if underflowed
			PORTC = (1<<LEFT_LED);
			game_over = 1;
			left_wins = 0;
		}
	}
}

void wait(uint8_t time) {
	clock_countdown = time;
	TCCR0B = (1<<CS02) | (1<<CS00); 			 // start timer at 61Hz
	while(clock_countdown > 0);  				 // wait for countdown
	TCCR0B |= (0<<CS02) | (0<<CS01) | (0<<CS00); // stop timer
	TCNT0 = 0; 									 // clear timer
}

void flash_lights() {
	PORTD = 0xFF;
	PORTC = 0x06;
	wait(FLASH_TIME);
	PORTD = 0x00;
	PORTC = 0x00;
	wait(FLASH_TIME);
	PORTD = 0xFF;
	PORTC = 0x06;
	wait(FLASH_TIME);
	PORTD = 0x00;
	PORTC = 0x00;
}

