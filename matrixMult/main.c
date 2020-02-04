#include <stdio.h>
#include <stdlib.h>
#include "matrixMult.h"

// Mario DeCristofaro, EE222, Matrix Multiplication hw, November 19, 2019

void main( void )
{
	int rowIndex, colIndex;
	// initialzing the matrix
	float left[ ROWS ][ SHARED ] = { { 1, 2, 3 },
								     { 4, 5, 6 } };
								     
	float right[ SHARED ][ COLS ] = { { 7, 8, 9, 10 },
								{ 11, 12, 13, 14 },
							 	{ 15, 16, 17, 18 } };
	float ( *result )[ COLS ] = { 0 };
	
	// result uses the method from matricMult.c to return the multiplied matrix
	result = ( float (*)[ COLS ] ) matrix_multiplication( &left[ 0 ][ 0 ], &right[ 0 ][ 0 ],
	                                                                   ROWS, SHARED, COLS );
	
	// iterates through row and column to print the result
	for( rowIndex = 0; rowIndex < ROWS; rowIndex++ )
	{
		for( colIndex = 0; colIndex < COLS; colIndex++ )
		{
			printf( " %f ", result[ rowIndex ][ colIndex ] );
		}
		
		printf( "\n" );
	}
	
	return EXIT_SUCCESS;
}
