;; Karl Ramberg
;; Paul Ramberg
;; walking.S creates a line of LEDs that turn on and off 
;; in sequence creating a walking animation

.equ PINC, 0x06
.equ DDRC, 0x07
.equ DDRD, 0x0A
.equ PORTD, 0x0B
.global main
main:
	cbi DDRC, 0					; set PC0 as input
	
	sbi DDRD, 0					; set PD0 as output
	sbi DDRD, 1					; set PD1 as output
	sbi DDRD, 2					; set PD2 as output
	sbi DDRD, 3					; set PD3 as output
	sbi DDRD, 4					; set PD4 as output
	sbi DDRD, 5					; set PD5 as output
	sbi DDRD, 6					; set PD6 as output
	sbi DDRD, 7					; set PD7 as output

	ldi r0, 0x00				; start with bit/pin 0	
loop:
	cbi PORTD, r0				; turn off pin at r0 value (0-7)

	in r1, PINC					; read in PINC to r1
	cbr r1, 0xFE				; mask out bits except 0 (PC0)
	brne reverse				; reverse direction if PINC was not zero (had a voltage)
	inc r0						; increment pin number
	jmp turnon 
reverse:
	dec r0						; decerement pin number
turnon:
	cbr r0, 0xF8				; clear bits 7-3 to keep range from 0-7
	sbi PORTD, r0				; turn on pin at r0 value (0-7)
	call delay					
	jmp loop

delay:
	ldi r31, 0xff				; put the value 65,535 in r31 and r30
	ldi r30, 0xff
	
delay1:
	nop							; no operation
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	sbiw r30, 1					; (r31/r30)--
	brne delay1					; delay again if result is not 0

	ret
