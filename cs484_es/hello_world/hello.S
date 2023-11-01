;; Karl Ramberg
;; hello.S is a program to alternate voltage for pin 12 (PB4) of an Atmega328p

.equ DDRB, 0x04						; IO register for pin direction
.equ PORTB, 0x05					; IO register for Port B pins

.text
.global main
main:
	sbi DDRB, 4						; set pin PB4 as an output pin
	
loop:
	sbi PORTB, 4					; pin PB4 on (set)
	call delay						; function call

	cbi PORTB, 4					; pin PB4 off (clear)
	call delay						; function call

	jmp loop

;; Loop 65535 times to create a delay
delay:
	ldi	r31, 0xff					; together registers r31 and r30 form a 16-bit
	ldi r30, 0xff					; value set to 255 * 256 + 255 * 1 = 65535

delay1:
	nop								; no operation
	nop
	nop
	nop
	nop
	nop
	nop

	sbiw r30, 1						; (r31/ro30)--
	brne delay1						; branch if result is not equal to zero

	ret
	

