// Mario DeCristofaro, EE222, final Sudoku, November 2, 2019
#ifndef sudoku_h
#define sudoku_h

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define BOARD_SIZE 9
#define SUBGRID_SIZE 3

bool is_in_row    ( int ( *board )[ BOARD_SIZE ], int test_number, int row );

bool is_in_col    ( int ( *board ) [BOARD_SIZE ], int test_number, int col );

bool is_in_subgrid( int ( *board )[ BOARD_SIZE ], int test_number, int row, int col );

bool has_conflict ( int ( *board )[ BOARD_SIZE ], int test_number, int row, int col );

void fill_diagonal( int ( *board )[ BOARD_SIZE ] );

bool fill_board( int ( *board )[ BOARD_SIZE ], int row, int col );

void remove_cells( int ( *board )[ BOARD_SIZE ], int number_cells );

void show_board( int( *board )[ BOARD_SIZE ] );

int random_number( int range_start, int range_end );

void write_board( int( *board )[ BOARD_SIZE ], FILE* stream );

#endif
