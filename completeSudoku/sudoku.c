// Mario DeCristofaro, EE222, final Sudoku, November 2, 2019
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sudoku.h"

//Declare function and check the row
bool is_in_row( int( *board )[ BOARD_SIZE ],int test_number,int row )
{
	//Declare Variables
	int colIndex;
	//Use for loop to check the board
	for( colIndex = 0; colIndex < BOARD_SIZE; colIndex++ )
	{
		if( test_number == board[ row ][ colIndex ] )
		{
			return true;
		}
	}
	return false;
}
//Declare function and check the column
bool is_in_col( int ( *board )[ BOARD_SIZE ], int test_number, int col )
{
	//Declare Variables
	int rowIndex;
	//Use For loop to check the board
	for( rowIndex = 0; rowIndex < BOARD_SIZE; rowIndex++ )
	{
		if( test_number == board[ rowIndex ][ col ] )
		{
			return true;
		}
	}
	return false;
}
//Declare function and check the subgrid
bool is_in_subgrid( int ( *board )[ BOARD_SIZE ], int test_number, int row, int col )
{
	//Declare Variables
	int rowIndex, colIndex;
	int startCol = ( col / SUBGRID_SIZE ) * SUBGRID_SIZE;
	int startRow = ( row / SUBGRID_SIZE ) * SUBGRID_SIZE;
	//Use for loop to run through the subgrid and check
	for( rowIndex = 0; rowIndex < SUBGRID_SIZE; rowIndex++ )
	{
		//checks through column up until SUBGRID_SIZE
		for( colIndex = 0; colIndex < SUBGRID_SIZE; colIndex++ )
		{
			if( test_number == board[ rowIndex + startRow][ colIndex + startCol ] )
			{
				return true;
			}
		}
	}
	return false;
}
//Declare function and check for conflicts
bool has_conflict( int ( *board )[ BOARD_SIZE ], int test_number, int row, int col )
{
	// checks if the number is in row, is in col, and or the subgrid
	return is_in_row( board, test_number, row ) || is_in_col( board, test_number, col ) || is_in_subgrid( board, test_number, row, col );
}

void fill_diagonal( int ( *board )[ BOARD_SIZE ] )
{
	// create variables
	int numSubGrid, rowIndex, colIndex, num;
	int rowStart, colStart;
	
	// iterates through up until SUBGRID_SIZE
	for( numSubGrid = 0; numSubGrid < SUBGRID_SIZE; numSubGrid++ )
	{
		// create the starts for the row and col
		rowStart = numSubGrid * SUBGRID_SIZE;
		colStart = numSubGrid * SUBGRID_SIZE;
		// iterate through row
		for( rowIndex = rowStart; rowIndex < rowStart + SUBGRID_SIZE; rowIndex++ )
		{
			// then iterate through column
			for( colIndex = colStart; colIndex < colStart + SUBGRID_SIZE; colIndex++ )
			{
				// while its in the sub grid
				do
				{
					num = random_number( 1, BOARD_SIZE );
				} while( is_in_subgrid( board, num, rowIndex, colIndex ) );
				
				board[ rowIndex ][ colIndex ] = num;
			}
		}
	}
	
}

bool fill_board( int ( *board )[ BOARD_SIZE ], int row, int col )
{
	//printf( "row %d, col %d\n", row, col );
	int num = 0;
	// if its at the end reset column then increment row
	if( col == BOARD_SIZE )
	{
		col = 0;
		row++;
	}
	
	// if row is at the end
	if( row == BOARD_SIZE )
	{
		return true;
	}
	// if it doesnt equal 0
	if( board[ row ][ col ] != 0 )
	{
		return fill_board( board, row, col + 1 );
	}
	// iterate the 9 times 
	for( num = 1; num <= BOARD_SIZE; num++ )
	{
		// checks if there isnt a conflict
		if( !has_conflict( board, num, row, col ) )
		{
			board[ row ][ col ] = num;
			// then recursivly calls itself at the next spot over
			if( fill_board( board, row, col + 1 ) )
			{
				return true;
			}
			board[ row ][ col ] = 0;
		}
	}
	return false;
}

void remove_cells( int ( *board )[ BOARD_SIZE ], int number_cells )
{
	int index;
	int randRow, randCol;
	// iterates through for the amount of cells you want to remove
	for( index = 0; index < number_cells; index++ )
	{
		while( board[ randRow ][ randCol ] == 0 )
		{
			randRow = random_number( 0, BOARD_SIZE - 1 );
			randCol = random_number( 0, BOARD_SIZE - 1 );
		}
		board[ randRow ][ randCol ] = 0;
	}
}


//writes the board to a given output stream
void write_board( int( *board )[ BOARD_SIZE ], FILE* stream)
{
	int rowIndex, colIndex;
	
	fprintf( stream, "\n\t#===|===|===#===|===|===#===|===|===#\n" );
	
	for( rowIndex = 0; rowIndex < BOARD_SIZE; rowIndex++ )
	{
		fprintf( stream, "\t# " );
		
		for( colIndex = 0; colIndex < BOARD_SIZE; colIndex++ )
		{
			if( board[ rowIndex ][ colIndex ] > 0 )
			{
				fprintf( stream,"%d", board[ rowIndex] [ colIndex ]);
			}
			else
			{
				fprintf( stream," ") ;
			}
			
			if( ( colIndex + 1 ) % SUBGRID_SIZE ==0 )
			{
				fprintf( stream," # ") ;
			}
			else
			{
				fprintf( stream," | " );
			}
		}
		
		if( ( rowIndex+1 ) % SUBGRID_SIZE ==0 )
		{
			fprintf( stream,"\n\t#===|===|===#===|===|===#===|===|===#\n" );
		}
		else
		{
			fprintf( stream,"\n\t#---|---|---#---|---|---#---|---|---#\n" );
		}
	}
	fprintf( stream,"\n" );
}

//show board on standart output, using write_board() with stdout stream
void show_board( int( *board )[ BOARD_SIZE ] )
{
	write_board( board, stdout );
}

//generates a random number in the given range
//mind that the random generator needs to be "seeded", before calling thiss function
int random_number( int range_start,int range_end )
{
	//return random number in range
	return rand() % ( range_end-range_start+1 ) + range_start;
}
