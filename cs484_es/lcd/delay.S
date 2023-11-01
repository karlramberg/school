.macro nop2				; 2 cycle, 1 word NOP
	rjmp .
.endm

	.text
	.global delay1us	; void delay1us(uint16_t n)
						; delay in units of 16 cycles (1us at 16Mhz)
						; number of microseconds will be in register pair r24/r25
delay1us:				; Assume call required (4 cycles)
	nop					; (1 cycle)
	nop2				; (2 cycles)
	rjmp delay2			; (2 cycles)
delay1:
	nop2				; (2 cycles)
	nop2				; (2 cycles)
	nop2				; (2 cycles)
	nop2				; (2 cycles)
	nop2				; (2 cycles)
	nop2				; (2 cycles)
delay2:
	sbiw r24, 1			; subtract 1 from r24/r25 (2 cycles)
	brne delay1			; branch if not zero (1 / 2 cycles)

	ret					; return (4 cycles)

	.global delay1ms	; void delay1ms(uint16_t n)
						; delay n milliseconds = 1000*n microseconds
						; number of milliseconds will be in register r24/r25
delay1ms:				; assume call used (4 cycles)	
	movw r26, r24		; save millisecond count (1 cycle)
	rjmp delay4			; (2 cycles)
delay3:
	nop2				; (2 cycles)
	nop2				; (2 cycles)
	nop2				; (2 cycles)
	nop2				; (2 cycles)
	nop2				; (2 cycles)
delay4:
	ldi r24, 231		; r24/r25 contains 231+*256=999us (1 cycle)
	ldi r25, 3			; (1 cycle)	
	call delay1us		; delays 999us
	sbiw r26, 1			; subtract 1 from r26/r27 (2 cycles)
	brne delay3			; branch if not zero (1 / 2 cycles)

	ret					; return (4 cycles)
	
