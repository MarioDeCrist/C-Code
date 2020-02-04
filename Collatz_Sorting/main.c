// Mario DeCristofaro, EE222, collatz Sorting HW, October 18, 2019
#include <stdio.h>
#include <stdlib.h>
#include "collatzSort.h"



int main() 
{
	int index = 0;
	
	int array[ MAX_NUMBER + 1 ];
	int copyArray[ MAX_NUMBER + 1 ][ 2 ];
	// array before the sort
	collatz_upload( array );
	collatz_copy_array( array, copyArray );
	printf( "Starting Array: \n" );
	collatz_print_array( copyArray );
	// array after the sort
	collatz_selection_sort( copyArray );
	printf( "Sorted Array: \n" );
	collatz_print_array( copyArray );
	
	return EXIT_SUCCESS;
}
