# SPIM S20 MIPS simulator.
# The default exception handler for spim.
#
# Copyright (c) 1990-2010, James R. Larus.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without modification,
# are permitted provided that the following conditions are met:
#
# Redistributions of source code must retain the above copyright notice,
# this list of conditions and the following disclaimer.
#
# Redistributions in binary form must reproduce the above copyright notice,
# this list of conditions and the following disclaimer in the documentation and/or
# other materials provided with the distribution.
#
# Neither the name of the James R. Larus nor the names of its contributors may be
# used to endorse or promote products derived from this software without specific
# prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
# GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#

# Define the exception handling code.  This must go first!

	.kdata
__m1_:	.asciiz "  Exception "
__m2_:	.asciiz " occurred and ignored\n"
__e0_:	.asciiz "  [Interrupt] "
__e1_:	.asciiz	"  [TLB]"
__e2_:	.asciiz	"  [TLB]"
__e3_:	.asciiz	"  [TLB]"
__e4_:	.asciiz	"  [Address error in inst/data fetch] "
__e5_:	.asciiz	"  [Address error in store] "
__e6_:	.asciiz	"  [Bad instruction address] "
__e7_:	.asciiz	"  [Bad data address] "
__e8_:	.asciiz	"  [Error in syscall] "
__e9_:	.asciiz	"  [Breakpoint] "
__e10_:	.asciiz	"  [Reserved instruction] "
__e11_:	.asciiz	""
__e12_:	.asciiz	"  [Arithmetic overflow] "
__e13_:	.asciiz	"  [Trap] "
__e14_:	.asciiz	""
__e15_:	.asciiz	"  [Floating point] "
__e16_:	.asciiz	""
__e17_:	.asciiz	""
__e18_:	.asciiz	"  [Coproc 2]"
__e19_:	.asciiz	""
__e20_:	.asciiz	""
__e21_:	.asciiz	""
__e22_:	.asciiz	"  [MDMX]"
__e23_:	.asciiz	"  [Watch]"
__e24_:	.asciiz	"  [Machine check]"
__e25_:	.asciiz	""
__e26_:	.asciiz	""
__e27_:	.asciiz	""
__e28_:	.asciiz	""
__e29_:	.asciiz	""
__e30_:	.asciiz	"  [Cache]"
__e31_:	.asciiz	""
__excp:	.word __e0_, __e1_, __e2_, __e3_, __e4_, __e5_, __e6_, __e7_, __e8_, __e9_
	.word __e10_, __e11_, __e12_, __e13_, __e14_, __e15_, __e16_, __e17_, __e18_,
	.word __e19_, __e20_, __e21_, __e22_, __e23_, __e24_, __e25_, __e26_, __e27_,
	.word __e28_, __e29_, __e30_, __e31_
	
# Space in memory for saved registers.
__v0:	.word 0
__a0:	.word 0
__at:	.word 0
__t0:   .word 0
__t1:   .word 0

# The exception handler must reside in memory at addres 0x80000180.  This
# value is hardwired into the MIPS processor.
	.ktext 0x80000180
	
# This is the exception handler code that the processor runs when
# an exception occurs.  Right now, it just prints the exception number
# and returns.
#
# Because we are running in the kernel, we can use $k0/$k1 without
# saving their old values.
	
	# Normally, we shouldn't touch $at.  This directive
	# tells the assembler not to complain if we do.
	.set noat

	# We have to save any registers we use, but we can't use
	# the stack.  Dump them into kernel memory.
	# We need $at because we want to use pseudo-instructions.
	# We need $v0 and $a0 to make syscalls.
	
	sw $at, __at		
	.set at
	
	sw $v0, __v0		
	sw $a0, __a0

	# If you use any registers other than $k0, and $k1, you need
	# save them to kernel memory.  Do that here.

	# Get the exception number from cause[6:2]
	mfc0 $k0, $13		# Cause register is reg. 13
	srl $a0, $k0, 2		# Shift exception number to bits $a0[4:0]
	andi $a0, $a0, 0x1f     # Clear bits $a0[31:5]

	# If the exception number is zero, this is an interrupt.
	# Jump to the interrupt handler.
	beq $a0, $zero, interrupt_handler

	# Print information about exception.
	#
	li $v0 4		# syscall 4 (print_str)
	la $a0 __m1_
	syscall

	# Get the exception number from $k0 again since the syscall
	# destroyed $a0.
	li $v0, 1	
	srl $a0, $k0, 2	
	andi $a0, $a0, 0x1f
	syscall

	li $v0, 4		# syscall 4 (print_str)
	andi $a0, $k0, 0x3c
	lw $a0, __excp($a0)
	nop
	syscall

	bne $k0 0x18 ok_pc	# Bad PC exception requires special checks
	nop

	mfc0 $a0, $14		# EPC
	andi $a0, $a0, 0x3	# Is EPC word-aligned?
	beq $a0, 0, ok_pc

	li $v0, 10		# PC is hopelessly fouled up.  Give up.
	syscall

ok_pc:
	li $v0, 4		# syscall 4 (print_str)
	la $a0, __m2_
	syscall

	srl $a0, $k0, 2		# Extract ExcCode Field yet again
	andi $a0, $a0, 0x1f

	# At this point, we've basically done all we can
	# to service a non-interrupt exception.  Clean up
	# and go to the instruction following the excepting one.
	bne $a0, 0, ret_from_non_interrupt_exception	# 0 means exception was an interrupt


	# Interrupt-specific code goes here!
	# 
	# Don't skip the instruction at EPC when returning from an interrupt.
	# If the exception was an interrupt, it was detected *before* the instruction
	# began to execute.
interrupt_handler:

    # Check for RCR ready bit
    li $k0, 0xFFFF0000
    lw $k1, 0($k0)
    andi $k1, $k1, 0x1
    beq $k1, $zero, return
    
    # Check for TCR ready bit
    li $k0, 0xFFFF0008
    lw $k1, 0($k0)
    andi $k1, $k1, 0x1
    beq $k1, $zero, return

    # Read character from RDR
    li $k0, 0xFFFF0004
    lw $k1, 0($k0)
    andi $k1, $k1, 0xFF

    # Check if in uppercase range (65-90)
    li $k0, 65
    blt $k1, $k0, print
    li $k0, 91
    blt $k1, $k0, flip_uppercase 

    # Check if in lowercase range (97-103)
    li $k0, 97
    blt $k1, $k0, print
    li $k0, 123
    blt $k1, $k0, flip_lowercase
flip_uppercase:
    addi $k1, $k1, 32
    j print
flip_lowercase:
    addi $k1, $k1, -32
print:
    # Store character in TDR
    li $k0, 0xFFFF000C
    sw $k1, 0($k0)

return:
	j ret_from_interrupt

ret_from_non_interrupt_exception:
# Return from (non-interrupt) exception. Skip excepting instruction
# at EPC to avoid infinite loop.
#
# Note that we *don't* patch up the EPC if we are here because of
# an interrupt.  That's because the interrupt happened at the
# beginning of the instruction.

	mfc0 $k0, $14		# Bump EPC register
	addiu $k0, $k0, 4	# Skip faulting instruction
	# On a real processor, need to handle delayed branch case
	# here.
	mtc0 $k0, $14


# Restore registers, reset co-processor, return from exception
ret_from_interrupt:	
	lw $v0, __v0		# Restore registers
	lw $a0, __a0

	.set noat
	lw $at, __at
	.set at

	mtc0 $0, $13		# Clear Cause register

	# When the exception/interrupt happened, the hardware
	# turned off interrupts in the status register.  Re-enable them.
	mfc0 $k0, $12		
	ori  $k0, 0x1	
	mtc0 $k0, $12

# Return from exception:
	eret