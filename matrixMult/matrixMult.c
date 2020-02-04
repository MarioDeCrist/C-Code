#include <stdio.h>
#include <stdlib.h>
#include "matrixMult.h"

// Mario DeCristofaro, EE222, Matrix Multiplication hw, November 19, 2019

float* matrix_multiplication( float* left, float* right, int rows, int shared, int columns )
{
	// create an index for row, column, and shared
	int rowIndex, colIndex, sharedIndex;
	float* result;
	// memory allocation
	result = malloc( rows * columns * sizeof( float ) );
	
	// iterates through the row
	for( rowIndex = 0; rowIndex < rows; rowIndex++ )
	{
		// iterates through the column
		for( colIndex = 0; colIndex < columns; colIndex++ )
		{
			// set to zero
			*( result + rowIndex * columns + colIndex ) = 0;
			
			// iterates through the shared index
			for( sharedIndex = 0; sharedIndex < shared; sharedIndex++ )
			{
				// the sum of the left and right matrix
				*( result + rowIndex * columns + colIndex ) += *( left+ rowIndex * shared + sharedIndex )* *( right + sharedIndex * columns + colIndex );
			}
		}
	}
	// returns the result
	return result;
}
