hello.hex: hello.elf
	avr-objcopy -j .text -j .data -O ihex hello.elf hello.hex

hello.elf: hello.S
	avr-gcc -mmcu=atmega328p hello.S -o hello.elf

install: hello.hex
	avrdude -p atmega328p -c usbtiny -U flash:w:hello.hex:i

clean:
	del /s *.o *.elf *.hex *.lst* *~
