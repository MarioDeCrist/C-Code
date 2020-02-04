// Mario DeCristofaro, EE222, collatz Sorting HW, October 18, 2019
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "collatzSort.h"

bool collatz_upload(int array[])
{
   FILE* collatz_file;
   int number, collatz;
   // open file
   collatz_file = fopen(COLLATZ_FILE, "r");
   probe(collatz_file, "Opening file %s failed", COLLATZ_FILE);
   // read collatz numbers from file
   while(fscanf(collatz_file, "%d - %d", &number, &collatz) == 2)
   {
       array[number-1] = collatz;
   }
   // terminate array by setting last element to 0
   array[number] = 0;
   // close file
   fclose(collatz_file);
   return true;
error:
   return false;
}

// copies the values from collatz from 1 dimentional Arr to a 2D one
void collatz_copy_array( int array[], int ( *array_copy )[ 2 ] )
{
	int index = 1;
	// loops through to copy all the elements over at the indices
	while( array[ index ] != 0 )
	{
		array_copy[ index ][ 0 ] = index + 1;
		array_copy[ index ][ 1 ] = array[ index ];
		
		index++;
	}
	// corrects the start
	array_copy[ 0 ][ 0 ] = 1;
	array_copy[ 0 ][ 1 ] = 0;
	// terminator
	array_copy[ index ][ 0 ] = 0;
	array_copy[ index ][ 1 ] = 0;
}

// slection sort algorithm for 2D array
void collatz_selection_sort( int ( *array_copy )[ 2 ] )
{
	int outer = 0;
	int arrLength = 0;
	int min, currMin, temp;
	
	// hardsets arrLength to 0
	while( array_copy[ outer ][ 0 ] != 0 )
	{
		arrLength++;
		outer++;
	}
	// outer loop to go through each each element
	for( outer = 0; outer < ( arrLength - 1 ); outer++ )
	{
		currMin = outer;
		// loops through elements to compare Values and find the minimum
		for( min = outer + 1; min < arrLength; min++ )
		{
			// if that min is less than currMin then set it to currMin
			if(array_copy[ currMin ][ 1 ] > array_copy[ min ][ 1 ] )
			{
				currMin = min;
			}
			
		}
		// swaps values at index 0
		temp = array_copy[ outer ][ 0 ];
		array_copy[ outer ][ 0 ] = array_copy[ currMin ][ 0 ];
		array_copy[currMin ][ 0 ] = temp;
		
		// swaps values at index 1
		temp = array_copy[ outer ][ 1 ];
		array_copy[ outer ][ 1 ] = array_copy[ currMin ][ 1 ];
		array_copy[ currMin ][ 1 ] = temp;
	}
}

void collatz_print_array( int (*array_copy)[2] )
{
   int index = 0;
   
   while(array_copy[index][0] != 0)
   {
       // prints the array
	   printf( "%d - %d\n", array_copy[ index ][ 0 ], array_copy[ index ][ 1 ] );
       index++;
   }
}
