        .text
main:   
        li $s0, 10000000
for:    beq $s0, $zero, done
        addi $s0, $s0, -1
        j for
done:
        jr $ra