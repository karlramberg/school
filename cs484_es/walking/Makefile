walking.hex: walking.elf
	avr-objcopy -j .text -j .data -O ihex walking.elf walking.hex

walking.elf: walking.S
	avr-gcc -mmcu=atmega328p walking.S -o walking.elf

install: walking.hex
	avrdude -p atmega328p -c usbtiny -U flash:w:walking.hex:i

clean:
	del /s *.o *.elf *.hex *.lst* *~
