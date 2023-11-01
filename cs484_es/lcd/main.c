// Karl Ramberg, Paul Ramberg
#include"lcd.h"

void main(void)
{
	lcdInit();
	lcdPuts("Hello, world!");
	lcdHome();
	lcdCursorOn();
	lcdClear();
	delay1ms(1000);
	lcdPuts("H");
	delay1ms(1000);
	lcdPuts("E");
	delay1ms(1000);
	lcdPuts("L");
	delay1ms(1000);
	lcdPuts("L");
	delay1ms(1000);
	lcdPuts("O");
	delay1ms(1000);
	lcdPuts(",");
	delay1ms(1000);
	lcdPuts(" ");
	delay1ms(1000);
	lcdPuts("W");
	delay1ms(1000);
	lcdPuts("O");
	delay1ms(1000);
	lcdPuts("R");
	delay1ms(1000);
	lcdPuts("L");
	delay1ms(1000);
	lcdPuts("D");
	delay1ms(1000);
	lcdPuts("!");
	delay1ms(1000);
	lcdClear();
	lcdCursorOff();
	delay1ms(1000);
	lcdPuts("Goodbye, world.");
	while(1);
}
