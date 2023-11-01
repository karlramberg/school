lcdtest.hex: lcdtest.elf
	avr-objcopy -j .text -j .data -O ihex lcdtest.elf lcdtest.hex

lcdtest.elf: delay.S lcd.c main.c
	avr-gcc -mmcu=atmega328p delay.S lcd.c main.c -o lcdtest.elf 

install: lcdtest.hex
	avrdude -p atmega328p -c usbtiny -U flash:w:lcdtest.hex:i

clean:
	rm *.o *.elf *.hex *.lst*
