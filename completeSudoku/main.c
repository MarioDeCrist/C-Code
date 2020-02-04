// Mario DeCristofaro, EE222, final Sudoku, November 2, 2019
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "sudoku.h"

int main( int argc, char *argv[] )
{
	srand( ( unsigned int ) time( NULL ) );
	
	int num = 20;
	int row, col;
	// fill board with 0's to initialize
	int board[BOARD_SIZE][BOARD_SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0, 0,
	                                      0, 0, 0, 0, 0, 0, 0, 0, 0,
										  0, 0, 0, 0, 0, 0, 0, 0, 0,
										  0, 0, 0, 0, 0, 0, 0, 0, 0,
										  0, 0, 0, 0, 0, 0, 0, 0, 0,
										  0, 0, 0, 0, 0, 0, 0, 0, 0,
										  0, 0, 0, 0, 0, 0, 0, 0, 0,
										  0, 0, 0, 0, 0, 0, 0, 0, 0,
										  0, 0, 0, 0, 0, 0, 0, 0, 0 };
	// fills diagnol									  
	fill_diagonal( board );
	show_board(board );
	// fills whole board
	fill_board( board, 0, 0 );
	show_board( board );
	// removes 20 cells
	remove_cells( board, num );
	show_board( board );

}

