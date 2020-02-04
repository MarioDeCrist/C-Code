// Mario DeCristofaro, EE222, Basic Pointers hw, November 12, 2019
#include <stdio.h>
#include <stdlib.h>


int main( int argc, char *argv[] ) 
{
	// hardcoded strings
	char *strOne = "Pointers rock, ";
	char *strTwo = "once you get the hang of it!";
	// creating integers we will be re ordering
	int num1 =  3;
	int num2 = 2;
	int num3 = 1;
	// pointers for the integers
	int *a = &num1;
	int *b = &num2;
	int *c = &num3;
	
	// prints the lenth of the first string
	printf( "The length of '%s' is: %i \n", strOne, string_length( strOne ) );
	// prints the concatination of both strings
	printf( "Concatination of '%s' and '%s' is: %s \n", strOne, strTwo, string_concat( strOne, strTwo ) );
	// method call
	string_concat( strOne, strTwo );
	//print values before the re order
	printf( "%s%d %d %d\n", "Values before reorder: ", num1, num2, num3 );
    //Call method
    reorder(a, b, c);
    //displays values after the re order
    printf( "%s%d %d %d\n", "Values after reorder: ", num1, num2, num3 );
	
	return 0;
}
