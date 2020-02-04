// Mario DeCristofaro, EE222, Basic Pointers hw, November 12, 2019
#include <stdio.h>
#include <stdlib.h>
#include "pointers.h"

// returns the length of given string
int string_length( char* string_ptr )
{
	// create a variable length
	int length = 0;
	
	while( *string_ptr )
	{
		length++;
		*string_ptr++;
	}
	
	return length;
}
// concatinates two strings
char* string_concat( char* first_string, char* second_string )
{
	// creates both lenth by using the string_length method we created
	int strLength1 = string_length( first_string );
	int strLength2 = string_length( second_string );
	// calculates the new string length from both strings
	int final_length = ( strLength1 + strLength2 ) + 1;
	int index = 0;
	// create a temp to allocate space to;
	char *temp;
	temp = ( char* )malloc( final_length );
	// copies over the first string
	while( *first_string != '\0' )
	{
		temp[ index ] = *first_string;
		*first_string++;
		index++;
	}
	// copies over the second string
	while( *second_string != '\0' )
	{
		temp[ index ] = *second_string;
		second_string++;
		index++;
	}
	// end of string termination
	temp[ index ] = '\0';
	// return that temp value;
	return temp;
}

void reorder( int* a, int* b, int* c )
{
	int min, mid, max;
	// checks if a is bigger or equal to b
	if( *a >= *b )
	{
		// then if a is bigger than C that means the max is *a
		if( *a >= *c )
		{
			max = *a;
		}
		// if b is bigger than or equal to c then the mid is b and the min is c
		if( *b >= *c )
		{
			mid = *b;
			min = *c;
		}
		
		else
		{
			mid = *c;
			min = *b;
		}
	}
	// recursive call checks now for b being in *a's spot and a in *b' spot to get that first check we created
	else
	{
		reorder( b, a, c );
	}
	// reset and assign the values again
	*a = min;
	*b = mid;
	*c = max;
}
