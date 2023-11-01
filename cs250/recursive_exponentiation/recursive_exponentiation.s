# Karl Ramberg
# MIPS implementation of recursive exponentiation

		.data
base_prompt:	.asciiz "Please enter non-negative base: "
exponent_prompt:.asciiz "Please enter non-negative exponent: "
error:		.asciiz "Can't raise 0 to zero power.\n"
carat:		.asciiz "^"
equals_sign:	.asciiz "="


		.text
main:		
		# Prologue
		addi $sp, $sp, -4			# grow the stack by 1 word
		sw $ra, 0($sp)				# store the final return address

		# Prompt the user for a base
		la $a0, base_prompt			# load the prompt
		li $v0, 4				# load the print_string instruction
		syscall					# call the system

		# Read the base
		li $v0, 5				# load read_integer instruction
		syscall					# call the system
		move $s0, $v0				# base associated with $s0

		# Prompt the user for an exponent
		la $a0, exponent_prompt			# load the prompt
		li $v0, 4				# load the print_string instruction
		syscall					# call the system
		
		# Read the exponent
		li $v0, 5				# load the read_integer instruction
		syscall					# call the system
		move $s1, $v0				# exponent associated with $s1

		# Error if both base and exponent are 0
		add $t0, $s0, $s1			# $t0 = base + exponent
		bne $t0, $zero, if_done			# branch if($t0 != 0)
		
		# Print an error message
		la $a0, error				# load the error message
		li $v0, 4				# load the print_string instruction
		syscall					# call the system

		# Epilogue
		lw $ra, 0($sp)				# restore the final return address
		addi $sp, $sp, 4			# shrink the stack by 1 word
		jr $ra					# return
if_done:

		# Calculate the result
		move $a0, $s0				# base is the first arg
		move $a1, $s1				# exponent is the second arg
		jal power				# call power
		move $s2, $v0				# result is associated with $s2

		# Print base
		move $a0, $s0				# load base
		li $v0, 1				# load print_integer instruction
		syscall					# call the system

		# Print ^
		la $a0, carat				# load carat
		li $v0, 4				# load print_string instruction
		syscall					# call the system
		
		# Print exponent
		move $a0, $s1				# load exponent
		li $v0, 1				# load print_integer instruction
		syscall					# call the system

		# Print =
		la $a0, equals_sign			# load equals sign
		li $v0, 4				# load print_string instruction
		syscall					# call the system

		# Print result
		move $a0, $s2				# load result
		li $v0, 1				# load print_integer instruction
		syscall					# call the system

		# Epilogue
		lw $ra, 0($sp)				# restore the final return address
		addi $sp, $sp, 4			# shrink the stack by 1 word
		jr $ra					# return



is_even:	# Determine if a non-negative number is even by inspecting the LSB
		# n is in $a0
	
		andi $t0, $a0, 0x1			# mask the LSB of n
		bne $t0, $zero, if_done2		# branch if($t0 != 0)
		li $v0, 1				# load 1 for return value
		jr $ra					# return
if_done2:	li $v0, 0				# load 0 for return value
		jr $ra					# return



multiply:	# Multiply the parameters together by repeated addition
		# a is in $a0
		# b is in $a1

		# Prologue
		addi $sp, $sp, -12			# grow the stack by 3 words
		sw $s0, 8($sp)				# save $s0
		sw $s1, 4($sp)				# save $s1
		sw $s2, 0($sp)				# save $s2

		move $s1, $a0				# a associated with $s1
		move $s2, $a1				# b associated with $s2

		# Repeatedly add b to the result
		li $s0, 0				# result associated with $s0
while:		ble $s1, $zero, while_exit		# branch if(a <= 0)
		add $s0, $s0, $s2			# result += b
		addi $s1, $s1, -1			# a--
		j while					# go back to the top of while
while_exit:	move $v0, $s0				# load result for return value

		# Epilogue
		lw $s2, 0($sp)				# restore $s2
		lw $s1, 4($sp)				# restore $s1
		lw $s0, 8($sp)				# restore $s0
		addi $sp, $sp, 12			# shrink the stack by 3 words
		jr $ra					# return

power:		# Calculate the first parameter raised to the second parameter
		# b is in $a0
		# e is in $a1

		# Prologue
		addi $sp, $sp, -24			# grow the stack by 6 words
		sw $ra, 20($sp)				# save the return address
		sw $s0, 16($sp)				# save $s0
		sw $s1, 12($sp)				# save $s1
		sw $s2, 8($sp)				# save $s2
		sw $s3, 4($sp)				# save $s3
		sw $s4, 0($sp)				# save $s4
		

		# temp associated with $s1
		# result associated with $s2
		
		move $s3, $a0				# b associated with $s3
		move $s4, $a1				# e associated with $s4

		bne $s4, $zero, if_done3		# branch if(e != 0)
		li $v0, 1				# load 1 for return value
		
		# Epilogue
		lw $s4, 0($sp)				# restore $s4
		lw $s3, 4($sp)				# restore $s3
		lw $s2, 8($sp)				# restore $s2
		lw $s1, 12($sp)				# restore $s1
		lw $s0, 16($sp)				# restore $s0
		lw $ra, 20($sp)				# restore the return address
		addi $sp, $sp, 24			# shrink the stack by 6 words
		jr $ra					# return
if_done3:
		

		# Check if exponent is even or odd
		move $a0, $s4				# e is the first arg
		jal is_even				# call is_even
		move $s0, $v0				# even_exponent associated with $s0
		
		li $t0, 1				# $t0 = 1
		bne $s0, $t0, else			# branch if(even_exponent != 1)

		# Even case
		move $a0, $s3				# b is the first arg
		srl $a1, $s4, 1				# e / 2 is the second arg
		jal power				# call power
		move $s1, $v0				# temp = power(b, e / 2) 

		move $a0, $s1				# temp is the first arg
		move $a1, $s1				# temp is the second arg
		jal multiply				# call multiply
		move $s2, $v0				# result = multiply(temp, temp)
		
		j if_done4
else:
		# Odd case
		move $a0, $s3				# b is the first arg
		addi $t1, $s4, -1			# $t1 = e - 1
		srl $a1, $t1, 1				# (e - 1) / 2 is the second arg
		jal power				# call power
		move $s1, $v0				# temp = power(b, (e - 1) / 2)

		move $a0, $s3				# b is the first arg
		move $a1, $s1				# temp is the second arg
		jal multiply				# call multiply
		move $s2, $v0				# result = multiply(b, temp)

		move $a0, $s2				# result is the first arg
		move $a1, $s1				# temp is the second result
		jal multiply				# call multiply
		move $s2, $v0				# result = multiply(result, temp)
if_done4:

		move $v0, $s2				# load result for return value
		
		# Epilogue
		lw $s4, 0($sp)				# restore $s4
		lw $s3, 4($sp)				# restore $s3
		lw $s2, 8($sp)				# restore $s2
		lw $s1, 12($sp)				# restore $s1
		lw $s0, 16($sp)				# restore $s0
		lw $ra, 20($sp)				# restore $ra
		addi $sp, $sp, 24			# shrink the stack by 6 words
		jr $ra					# return
