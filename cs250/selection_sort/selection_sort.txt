	# Karl Ramberg
	# November 20, 2019
	# MIPS implementation of selection sort

	.data
prompt1:	.asciiz "Enter number of elements: "
prompt2:	.asciiz "Enter elements one per line:\n"
newline:	.asciiz "\n"

	.align 2
list:	.space	1024 # array of 256 integers

	.text
main:	la $s0, list 		# load address of list into $s0
	
	# Prompt for the number of elements
	la $a0, prompt1		# $a0 = &prompt1
	li $v0, 4		# $v0 = 4 (print string)
	syscall			# call the system

	# Read the number of elements from the console
	li $v0, 5		# $v0 = 5 (read integer)
	syscall			# call the system
	move $s1, $v0		# $s1 = $v0
	
	# Prompt for the elements
	la $a0, prompt2		# $a0 = &prompt2
	li $v0, 4		# $v0 = 4 (print string)
	syscall

	# Read each element from the console and store in list
	li $s2, 0		# i = 0
for1:	bge $s2, $s1, for1_exit # branch if(i >= n)
	
	# Calculate &list[i]
	sll $t0, $s2, 2		# $t0 = 4 * i
	addu $t0, $t0, $s0	# #t0 = &list[i]

	# Read an integer from the console
	li $v0, 5		# $v0 = 5 (read integer)
	syscall			# Call the system

	sw $v0, 0($t0)		# Write the integer to list[i]

	# Increment the loop counter and loop
	addi $s2, $s2, 1	# i++
	j for1	
for1_exit:
	
	# Iterate from 0 to n - 1 and selection sort
	li $s2, 0		# i = 0
	addi $t0, $s1, -1	# $t0 = n - 1
for2:	bge $s2, $t0, for2_exit	# branch if(i >= (n - 1))
	
	# Look for correct element for list[i]
	move $s4, $s2		# $s4 = min_pos = i
	addi $s3, $s2, 1	# $s4 = j = i + 1
for3:	bge $s3, $s1, for3_exit	# branch if(j >= n)
	
	# Load list[j]
	sll $t1, $s3, 2		# $t1 = 4 * j
	addu $t1, $t1, $s0	# $t1 = &list[j]
	lw $t1, 0($t1)		# $t1 = list[j]

	# Load list[min_pos]
	sll $t2, $s4, 2		# $t2 = 4 * min_pos
	addu $t2, $t2, $s0	# $t2 = &list[min_pos]
	lw $t2, 0($t2)		# $t2 = list[min_pos]

	bge $t1, $t2, if_done	# branch if(list[j] >= list[min_pos])
	move $s4, $s3		# min_pos = j
if_done:
	
	addi $s3, $s3, 1
	j for3
for3_exit:

	# Calculate &list[i]
	sll $t1, $s2, 2		# $t1 = 4 * i
	addu $t1, $t1, $s0	# $t1 = &list[i]

	# Load list[min_pos]
	sll $t2, $s4, 2		# $t3 = 4 * min_pos
	addu $t2, $t2, $s0	# $t3 = &list[min_pos]
	lw $t3, 0($t2)		# $t3 = list[min_pos]
				
	# Swap list[min_pos] and list[i]
	lw $t4, 0($t1)		# temp = list[i]
	sw $t3, 0($t1)		# list[i] = list[min_pos]
	sw $t4, 0($t2)		# list[min_pos] = temp	

	addi $s2, $s2, 1
	j for2
for2_exit:

				# Print the elements of list
	li $s2, 0		# $s2 = i = 0
for4:	bge $s2, $s1, for4_exit	# branch if(i >= n)
	
				# Load &list[i]
	sll $t0, $s2, 2		# $t0 = 4 * i
	addu $t0, $t0, $s0	# $t0 = &list[i]

				# Print list[i]
	lw $a0, 0($t0)		# $a0 = list[i]
	li $v0, 1		# $v0 = 1 (print integer)
	syscall			# call the system

				# Print a newline
	la $a0, newline		# $a0 = newline
	li $v0, 4		# $v0 = 4 (print string)
	syscall			# call the system

	addi $s2, $s2, 1	# i++
	j for4			# loop
for4_exit:

	jr $ra			# exit the program
