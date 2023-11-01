// Karl Ramberg, Paul Ramberg

#include<avr/io.h>
#include"delay.h"
#include"lcd.h"

uint8_t RS;
uint8_t ENABLE;
uint8_t DB4;
uint8_t DB5;
uint8_t DB6;
uint8_t DB7;

void setOutput(uint8_t pin) {
	char port = getPort(pin);

	if (port == 'B') {
		DDRB |= (1<<(pin%14));
	} else if (port == 'C') {
		if (pin == 1) {
			DDRC |= 0x20; // pin 6 
		} else {
			DDRC |= (1<<(pin%23));
		}
	} else { // port is D 
		if (pin >= 2 && pin <= 6) {
			DDRD |= (1<<(pin%2));
		} else {
			DDRD |= (1<<(pin%11)+5);
		}
	}
}

void setPin(uint8_t pin) {
	char port = getPort(pin);

	if (port == 'B') {
		PORTB |= (1<<(pin%14));
	} else if (port == 'C') {
		if (pin == 1) {
			PORTC |= 0x20; // pin 6
		} else {
			PORTC |= (1<<(pin%23));
		}
	} else { // port is D 
		if (pin >= 2 && pin <= 6) {
			PORTD |= (1<<(pin%2));
		} else {
			PORTD |= (1<<(pin%11)+5);
		}
	}
}

void clearPin(uint8_t pin) {
	char port = getPort(pin);

	if (port == 'B') {
		PORTB &= ~(1<<(pin%14));
	} else if (port == 'C') {
		if (pin == 1) {
			PORTC &= ~0x20;
		} else {
			PORTC &= ~(1<<(pin%23));
		}
	} else { // port is D 
		if (pin >= 2 && pin <= 6) {
			PORTD &= ~(1<<(pin%2));
		} else {
			PORTD &= ~(1<<(pin%11)+5);
		}
	}
}

char getPort(uint8_t pin) {
	if (pin >= 14 && pin <= 19) {	// pin is between 14-19, in PORTB
		return 'B';
	} else if (pin == 1 || (pin >= 23 && pin <= 28)) {	// pin is 1 or 23-28, in PORTC
		return 'C'; 
	} 
	return 'D';
}

void pulseENABLE(void) {
	delay1us(1);
	setPin(ENABLE);					// set ENABLE high
	delay1us(1);
	clearPin(ENABLE);				// set ENABLE low
	delay1us(100);
}

void write4bits(uint8_t bits) {
	if (bits & 1) {					// set DB4 pin of bit 1 on
		setPin(DB4);
	} else {
		clearPin(DB4);
	}

	if (bits & 2) {					// set DB5 pin if bit 2 on
		setPin(DB5);
	} else {
		clearPin(DB5);
	}

	if (bits & 4) {					// set DB6 pin if bit 3 on 
		setPin(DB6);
	} else {
		clearPin(DB6);
	}

	if (bits & 8) {					// set DB7 pin of bit 4 on
		setPin(DB7);
	} else {
		clearPin(DB7);
	}

	pulseENABLE();
}

void command(uint8_t cmd) {
	clearPin(RS);					// set RS low for commands
	write4bits(cmd>>4);
	write4bits(cmd);
}

void lcdInit(uint8_t rs, uint8_t enable, uint8_t db4, uint8_t db5, uint8_t db6, uint8_t db7) {
	RS = rs;
	ENABLE = enable;
	DB4 = db4;
	DB5 = db5;
	DB6 = db6;
	DB7 = db7;

	setOutput(RS);					// Set all pins as output
	setOutput(ENABLE);
	setOutput(DB4);
	setOutput(DB5);
	setOutput(DB6);
	setOutput(DB7);
									
	clearPin(RS);					// Set RS and ENABLE low
	clearPin(ENABLE);

	delay1ms(50);					// wait 50ms for power on
	write4bits(0x03);				// write 0x03 three times to initialize
	delay1ms(5);
	write4bits(0x03);
	delay1ms(1);
	write4bits(0x03);
	delay1ms(1);
	write4bits(0x02);				// Choose 4-bit interface
	command(0x28);					// Choose 2 lines w/ 5x8 font
	command(0x0c);					// Turn display on
	command(0x01);					// Clear display
	delay1ms(2);					// Wait 2ms for clear
	command(0x06);					// Left-to-right text
}

void lcdPutc(uint8_t c) {
	setPin(RS);						// Set RS high for data		
	write4bits(c>>4);				// Write the first 4 bits
	write4bits(c);					// Write the last 4 bits
}

void lcdPuts(unsigned char *s) {
	while (*s) lcdPutc(*s++);		// While char not null, write char to LCD and increment
}

void lcdClear(void) {
	command(0x01);			
}

void lcdHome(void) {
	command(0x02);			
}

void lcdCursorOn(void) {
	command(0x0f);					// Set display on with cursor on 
}

void lcdCursorOff(void) {
	command(0x0d);					// Set display on with cursor off
}
