// Mario DeCristofaro, EE222, collatz_continued HW, October 15, 2019
#include <stdio.h>
#include <stdlib.h>
#include "collatz_fill.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main( void ) 
{
	int array[ MAX_NUMBER + 1 ];
	int max, g_average;
	float average;
	
	if( !collatz_fill( array ) )
	{
		printf( "Error Reading file" );
		return EXIT_FAILURE;
	}
	else
	{
		max = collatz_max( array );
		average = collatz_average( array );
		g_average = collatz_greater_average( array );
		
		printf("Collatz max: %i \n Collatz AVG: %f \n Numbers greater than AVG: %i \n", max, average, g_average );
		
		return EXIT_SUCCESS;
	}
}
