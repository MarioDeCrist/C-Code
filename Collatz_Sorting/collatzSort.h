// Mario DeCristofaro, EE222, collatz Sorting HW, October 18, 2019
#ifndef collatzSort_h
#define collatzSort_h
#include "dbg.h"

//create the constants
#define MAX_NUMBER 100
#define DBG
#define COLLATZ_FILE "collatz.txt"

// defined functions
void collatz_copy_array( int array[], int ( *array_copy )[ 2 ] );
void collatz_print_array( int ( *array_copy )[ 2 ] );
bool collatz_upload( int array[] );
void collatz_selection_sort( int( *array_copy )[ 2 ] );

#endif

