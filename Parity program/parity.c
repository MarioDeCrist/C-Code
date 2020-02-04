#include <stdio.h>
#include "parity.h"

int sumOfNums( int num )
  {
    int total = 0;
    int temp = num;

    while( temp > 0 )
    {
      total = total + ( temp % 10 );
      temp = temp / 10;
    }
    return total;
  }

int parity_digit( int num )
  {
    int digit = num % 9;
    int temp = 0;
    int total = num;
    int notZero = num * 10;
    int parity = 9 - digit;
    int finalParNum = ( num * 10 + parity );

    if( digit != 0 )
    {
      printf( "The parity digit is: %d\n", parity );
      printf( "The number with the parity digit added is: %d\n", finalParNum );

      return printf( "The sum of all the numbers is: %d\n", sumOfNums( num ) );
      return parity;
    }
    printf( "The parity digit is: %d\n", parity );
    printf( "The sum of all the numbers is: %d\n", sumOfNums( num ) );
    return printf( "The number with the parity digit added is: %d\n", notZero );
}
