#    Name:    Mario DeCristofaro
#    Project: One_Assembly Simple
#    Date:    October 17, 2019

.data     #Strcutures for memory are placed after the .data assembler
intOne: .asciiz "Enter First int: "     # asks for the first int
intTwo: .asciiz "\nEnter Second int: "     # asks for the second int
intThree: .asciiz "\nEnter Third int: "    # asks for the third int
Result: .asciiz "\nYour Result is: "     #prints text to find the final result

.text     # the code is placed after the .text assembler
.globl main     # declares the main as a global function
main:

li $v0, 4     # loads immediate value(4) into $v0
la $a0,intOne     # loads the word in 'intOne' into $a0
syscall     # transfers control to the OS which then performs the service

li $v0,5     # loads immediate value(5) into $v0
syscall     # transfers control to the OS which then performs the service
move $t1,$v0     # Moves value from $v0 into $t1

li $v0,4     # loads immediate value(4) into $v0
la $a0,intTwo     # loads the word in 'intTwo' into $a0
syscall     # transfers control to the OS which then performs the service

li $v0,5     # loads immediate value(5) into $v0
syscall     # transfers control to the OS which then performs the service
move $t2,$v0     # Moves value from $t2 into $v0

li $v0,4      # loads immediate value(4) into $v0
la $a0,intThree     # loads the word in 'intThree' into $a0
syscall     # transfers control to the OS which then performs the service

li $v0,5     # loads immediate value(5) into $v0
syscall     # transfers control to the OS which then performs the service
move $t3,$v0     # Moves value from $t3 into $v0

sub $t4, $t1, $t2     # subtracts $t3 from $t4 puts that result into $t5
add $t5 ,$t4, $t3     #adds $t1 and $t2 and puts that result into $t4

li $v0,4     # loads immediate value(4) into $v0
la $a0,Result     # loads the word in 'finalResult' into $a0
syscall     # transfers control to the OS which then performs the service

li $v0,1     # loads immediate value(1) into $v0
move $a0,$t5     # Moves value from $t5 into $a0
syscall     # transfers control to the OS which then performs the service

li $v0,10     # loads immediate value(10) into $v0
syscall     # transfers control to the OS which then performs the service
