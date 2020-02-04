// Mario DeCristofaro, EE222, Fibonacci HW, September 26, 2019
#include <stdio.h>
#include <stdlib.h>
#include "collatz.h"
#include "dbg.h"


int main( void ) 
{
	int index;
	FILE* collatzFile;
	
	collatzFile = fopen( DATA_FILE, "w" );
	probe( collatzFile, "Error opening file %s", DATA_FILE );
	
	
	for ( index = 1; index <= MAX_NUMBER; index++ )
	{
		fprintf( collatzFile, "%d - %d\n", index, collatz( index ) );
	}
	
	fclose( collatzFile );
	
	return EXIT_SUCCESS;
	
error:
	printf( "Thats an Error dog.." );
	exit;
	
}
