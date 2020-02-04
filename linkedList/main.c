// Mario DeCristofaro EE222  LinkedList HomeWork  12/06/2019

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

#include "dbg.h"

#define FILENAME "people_data.txt"

int main( void )
{
    // variables
    person* people;
    
    // create a person list from data in a file
    probe( people = people_create_list( FILENAME ), "no people in the list" );
    
    // compute the average age of all persons
    printf( "Average age: %f\n", people_average_age( people ) );
    
    // print out all people with above average age
    people_print_age_above_average( people );
    
    return EXIT_SUCCESS;
    
error:
	return EXIT_FAILURE;
}
