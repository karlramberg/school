// Karl Ramberg, Paul Ramberg

#include<avr/io.h>
#include"delay.h"
#include"lcd.h"

#define SAMPLES_PER_SECOND 8
#define SAMPLE_DELAY_MS (1000 / SAMPLES_PER_SECOND)
#define DEGREE_SYMBOL 248

// R_2 resistance is 9800ohms 
// Calculated ADC value at 77F is 517
// Calculated slope of ADC/temp is -0.161627
// So, T = 77 + 0.161627 * (517-ADC)
#define BASE_TEMP_FAHRENHEIT 77
#define BASE_ADC_VALUE 517
#define ADC_OVER_TEMP_SLOPE 0.161627

void main(void)
{
	// Initialize LCD
	lcdInit(12, 13, 14, 15, 16, 17);

	// Set PC0 as input pin	
	DDRC |= (0<<PC0);

	// Enable ADC, prescale to run at 125kHz
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0); 

	// Set internal Vcc as reference, right justify result, set ADC5 (A5) as input
	ADMUX = (0<<REFS1) | (1<<REFS0) | (0<<ADLAR) | (0<<MUX3) | (1<<MUX2) | (0<<MUX1) | (1<<MUX0); 

	while(1)
	{
		uint32_t runningTotal = 0;

		// Set to fahrenheit if PC0 is high
		uint8_t isFahrenheit = PINC & (1<<PC0);
	
		// Sample temperature X times in 1 second
		for (int sampleCount = 0; sampleCount < SAMPLES_PER_SECOND; sampleCount++)
		{
			// Read voltage and convert
			ADCSRA |= (1<<ADSC); 
			while ((ADCSRA & (1<<ADIF)) == 0);
			ADCSRA |= (1<<ADIF);

			// Conver to 8-bit numbers to 16-bit number
			uint16_t adc = (ADCH<<8);
			adc |= ADCL;
		
			// Compute temperature in fahrenheit from premade formula based on R_2 measured resistance
			float temperature = BASE_TEMP_FAHRENHEIT + (ADC_OVER_TEMP_SLOPE * (BASE_ADC_VALUE - adc));
	
			if (!isFahrenheit) // convert to Celsius
			{ 
				temperature -= 32;
				temperature *= 5;
				temperature /= 9;
			}

			runningTotal += temperature;

			delay1ms(SAMPLE_DELAY_MS); 
		}
	
		uint8_t finalTemp = runningTotal / SAMPLES_PER_SECOND;
		
		// LCD
		lcdClear();
		lcdHome();
		// Write temp number
		lcdPuts(finalTemp + "");
		lcdPutc(DEGREE_SYMBOL);
		if (isFahrenheit)
		{
			lcdPutc('F');
		}
		else
		{
			lcdPutc('C');
		}
	}
}
