#define __SFR_OFFSET 0
#include<avr/io.h>

	.text
	.global setLowAndTime
setLowAndTime:
	clr r22				; r22:r25 32-bit int
	clr r23
	clr r24
	clr r25
	ldi r20, 1

	cbi PORTB, PB1
loop1:
	in r21, PINB			; 1
	andi r21, (1<<PB0)		; 1
	breq done1			; 1 (false) or 2 (true)
	add r22, r20			; 1
	adc r23, r1			; 1
	adc r24, r1			; 1
	adc r25, r1			; 1
	nop				; 1
	rjmp . 				; 2
	rjmp . 				; 2
	rjmp . 				; 2
	rjmp loop1			; 2
done1:
	sbi PORTB, PB1
	ret
