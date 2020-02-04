#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBER 1000


// Mario DeCristofaro, EE222, NumberGuessing HW, Oct 15 2019

int main( int argc, char *argv[] ) 
{
	int min = 1;
	int max = MAX_NUMBER;
	int mid;
	int count = 0;
	char response;
	
	// runs until min and max are the same
	while( min!=max )
	{
		mid = ( min + max ) / 2;
		printf( "%2d. Is your number greater than %i? (y/n)", ++count, mid );
		response = getchar();
		getchar();
		
		// checks for keyboard input y and n and its its either itll remind you just y or no
		if( response == 'y' )
		{
			min = mid + 1;
		}
		else if( response == 'n' )
		{
			max = mid;
		}
		else
		{
			printf( "please enter (y/n): " );
			count--;
		}
	}
	// then just returns the found max number
	printf( "your number: %i", max );
	return EXIT_SUCCESS;
}
