// Mario DeCristofaro_EE222_Project1_mpgToLiters

#include <stdio.h>
#include <stdlib.h>

#include "mpgConversion.h"

int main( void ) 
{
	// declares variable
	float mpg = 0;
	
	//prompts user to input value in miles per gallon
	printf("Please enter a value in mpg: ");
	scanf( "%f", &mpg );
	printf("%f Miles per gallon is equal to %f Liters per 100 Kilometers \n",mpg, mpg_to_lp100k(mpg) );
	return EXIT_SUCCESS;
}
