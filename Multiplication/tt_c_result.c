// Mario DeCristofaro, EE222, Multiplication HW, October 1, 2019
#include "tt.h"
#include "dbg.h"

int result_tt(int x, int y )
{
	int product = 0;
	int number_element;
	FILE * times_table;
	
	// opens data file
	times_table = fopen( DATA_FILE, "rb" );
	 
	if( times_table == NULL )
	{
		printf( "Opening file %s failed\n", DATA_FILE );
		return 0;
	}
	
	//determines offset
	number_element = ( x - 1 ) * DIMENSION + y-1;
	
	// reads data at exact position
	fseek( times_table, number_element * sizeof( int ), SEEK_SET );
	// reads data
	fread( &product, sizeof( int ), 1, times_table );
	//closes data file
	fclose( times_table );
	//returns product of the numbers
	return product;
	
error:
	printf( "Oopsie" );
	exit;
}
