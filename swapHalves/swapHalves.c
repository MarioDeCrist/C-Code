// Mario DeCristofaro, EE222, String halves HW, November 21, 2019
#include <stdlib.h>
#include <stdio.h>

void swap_half( char* string )
{
	int index;
	// for loop for when the index doesnt equal the null terminator
	for( index = 0;  string[ index ] != '\0'; index++  );
	
	// method calls for the mirror displays
	mirror( string, 0, ( index / 2 ) - 1 );
	mirror( string, ( index / 2 ) , index - 1 );
	mirror( string, 0, index - 1 );
}


void mirror( char *string, int from, int to )
{
	char word;
	// while loop to go from the start(from) to the end (to)
	while( from < to )
	{
		
		// mirrors the string
		word = *( string + from );
		*( string + from ) = *( string + to );
		*( string + to ) = word;
		from++;
		to--;
	}
	
}
