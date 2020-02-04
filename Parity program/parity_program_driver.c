//Driver program for use with Programming Project 3
//Do NOT change anything in this program!!!

#include <stdio.h>
#include "parity.h"

int main()
{
    int orig_num;    
    printf("Enter a 3 digit integer: \n");
    scanf("%d", &orig_num);
    
    parity_digit(orig_num);    
    
    return 0;
    
}