// Mario DeCristofaro, EE222, collatz_continued HW, October 15, 2019
#include <stdio.h>
#include <stdlib.h>
#include "collatz_fill.h"
#include "dbg.h"

bool collatz_fill( int array[] )
{
	FILE * collatz_file;
	int collatz, number;
	// opens file
	collatz_file = fopen( COLLATZ_FILE, "r" );
	probe( collatz_file, "Error opening file %s", collatz_file );
	// read collatz numbers from file
	while( fscanf( collatz_file, "%d - %d", &number, &collatz) == 2 )
	{
		array[ number - 1 ] = collatz;
	}
	// terminates array by setting the last index to 0
	array[ number ] = 0;
	// closes file
	fclose( collatz_file );
	return true;
	
error:
	printf( "Oopsie!" );
	return false;
}

int collatz_max( int array[] )
{
	int index = 1;
	int maxNum = 0;
	
	// loops through array and searches for max
	while( array[ index ] != 0 )
	{
		// looks for new max
		if( array[ index ] > maxNum )
		{
			maxNum = array[ index ];
			// debugger that helped me
			//debug( "The max number is: %d", maxNum );
		}
		index++;
	}
	return maxNum;
}

float collatz_average( int array[] )
{
	int index = 1;
	float sum = 0.0;
	// loops through array in search for the average
	while( array[index] != 0 )
	{
		sum += array[index];
		index++;
	}
	return sum/(float)index;
}

int collatz_greater_average( int array[] )
{
	int index = 1;
	int count = 0;
	
	float average = collatz_average( array );
	// loops through array and counts how many numbers are greater than the average
	while( array[ index ] != 0 )
	{
		if(array[ index ] > average)
		{
			count++;
		}
		index++;
	}
	return count;
}
