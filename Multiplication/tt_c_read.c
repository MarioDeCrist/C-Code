// Mario DeCristofaro, EE222, Multiplication HW, October 1, 2019
#include "tt.h"
#include "dbg.h"

void read_tt( void )
{
	int value;
	FILE * times_table;
	int count = 0;
	
	// opens data file
	times_table = fopen( DATA_FILE, "rb" );
	probe( times_table, "Error opening file %s ", DATA_FILE );
	fseek(times_table, 0, SEEK_SET);
	
	// reads data file then outputs the data
	while( fread( &value, sizeof( int ), 1, times_table ) == 1 )
	{
		printf( "%4d", value );
		
		if( !( ++count % DIMENSION ) )
		{
			printf( "\n" );
		}
	}
	// closes data file
	fclose( times_table );
	return;
	
error:
	printf("Oopsie!");
	exit;
}
