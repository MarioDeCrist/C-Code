// Mario DeCristofaro, EE222, Multiplication HW, October 1, 2019
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tt.h"

/*
 The main is running each individual method, then in the do while loop its
 seeing if it's the first time your inputting values, then if so it uses scanf to place x and y together.
 Then if x and y are greater than the dimension, then the print statement uses the tt_c_result with
 x and y to calculate the math for the result.
*/
int main( void ) 
{
	int x, y;
	bool firstTime = true;
	
	//writes the data file
	write_tt();
	//reads the times table from data file
	read_tt();
	
	do
	{
		if( firstTime )
		{
			printf( "\n Enter two factors, eg 10 16: " );
			firstTime = false;
		}
		else
		{
			printf( "\nBoth Factors cannot be greater than %d, try again: ", DIMENSION );
		}
		scanf( "%d %d", &x, &y );
	}
	while( x > DIMENSION || y > DIMENSION );
	{
		printf(" %d %d = %d\n", x, y, result_tt( x, y ) );
		return EXIT_SUCCESS;
	}
}
