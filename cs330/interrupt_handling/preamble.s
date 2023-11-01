	    .text
	    .globl __start
start:	
	    # Enable interrupts in co-processor status register
	    mfc0 $t0, $12
	    ori $t0, $t0, 0x1
	    mtc0 $t0, $12

    	# Enable interrupts in receiver control register
        li $t0, 0xFFFF0000
        lw $t1, 0($t0)
        ori $t1, $t1, 0x2
        sw $t1, 0($t0)

        # Enable interrupts in transmitter control register
        li $t0, 0xFFFF0008
        lw $t1, 0($t0)
        ori $t1, $t1, 0x2
        sw $t1, 0($t0)
    
    	# Call main
    	jal main

    	# Exit
    	li $v0, 10
    	syscall