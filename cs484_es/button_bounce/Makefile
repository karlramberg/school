buttondebounce.hex: buttondebounce.elf
		avr-objcopy -j .text -j .data -O ihex buttondebounce.elf buttondebounce.hex

buttondebounce.elf: delay.S setlowandtime.S showBytes.c
		avr-gcc -mmcu=atmega328p delay.S setlowandtime.S showBytes.c

install: buttondebounce.hex
		avrdude -p atmega328p -c usbtiny -U flash:w:buttondebounce.hex:i

clean:
	rm *.0 *.elf *.hex *.lst*
