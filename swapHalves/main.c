// Mario DeCristofaro, EE222, String halves HW, November 21, 2019
#include <stdio.h>
#include <stdlib.h>
#include "swapHalves.h"


int main( int argc, char *argv[] ) 
{
	// create the two arrays
	char string[] = "whatever";
	char stringTwo[] = "EE222";
	// function call to swap the string of the first array
	swap_half( string );
	printf( " your result is: %s \n", string );
	// function call to swap the string of the second array
	swap_half( stringTwo );
	printf( " your result is: %s \n", stringTwo );
	
	return 0;
}
