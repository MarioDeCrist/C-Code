# File: min_max_int.assembler
# Author: Mario DeCristofaro, April 12, 2019
# Description: finds the minimum and maximum value in an array
.data
inputArray:    .word    5, 7, 12, 3, 4, 9, 6, 11, 2, 10    # Data given
minimumVal:    .asciiz  "Minimum value: "                  # the text for ascii
maximumVal:    .asciiz  "Maximum value: "                  # the text for ascii
newLine:       .asciiz  "\n"                               # the text for ascii

.text
.globl main

main:

#sets up the array
lw    $t2, inputArray($t1)        # put the minimum Value in $s2, & sets inputArray[0]
lw    $t3, inputArray($t1)        # put the max Value in $s3, & sets inputArray[0]
addi  $s1, 9

loop:
  beq $s1, $s2 end
  addi $t1, 4
  lw   $t0, inputArray($t1)
  blt  $t0, $t2 min
  bgt  $t0, $t3 max

  addi $s2, 1
  j loop
min:
  move $t2, $t0
  addi $s2, 1
  j loop
max:
  move $t3, $t0
  addi $s2, 1
  j loop
end:
  li $v0, 4
  la $a0, minimumVal
  syscall

  li $v0, 1
  move $a0, $t2
  syscall

  li $v0, 4
  la $a0, newLine
  syscall

  li $v0, 4
  la $a0, maximumVal
  syscall

  li $v0, 1
  move $a0, $t3
  syscall

  li $v0, 10
  syscall
