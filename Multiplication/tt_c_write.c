// Mario DeCristofaro, EE222, Multiplication HW, October 1, 2019
#include "tt.h"
#include "dbg.h"

void write_tt( void )
{
	int rows, columns;
	int value;
	FILE * times_table;
	
	//creates and opens the data file
	times_table = fopen( DATA_FILE, "wb" );
	probe( times_table, "Error opening file %s", DATA_FILE );
	fseek( times_table, 0, SEEK_SET);
	
	// writes the times table into data file
	for( rows = 1; rows <= DIMENSION; rows++ )
	{
		for( columns = 1; columns <= DIMENSION; columns++ )
		{
			value = rows * columns;
			fwrite( &value, sizeof( int ), 1, times_table );
		}
	}
	//closes the data file
	fclose( times_table );
	return;
	
error:
	printf( "Oopsie!" );
	exit;
}
