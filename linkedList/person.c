// Mario DeCristofaro EE222  LinkedList HomeWork  12/06/2019

#include <stdlib.h>

#include "dbg.h"
#include "person.h"

/*
 * Populate a single list of person structures with person data from a file and
 * return a pointer to the first element of that list.
 * A NULL pointer is returned:
 * - If there is no data in the file
 * - If there is an error reading the file. In addition, an error message is printed out on std error
 */
person* people_create_list( char* data_file_name )
{
    // declare variables
    FILE* people_data;
    person* people, *person_last, *person_next;

    // set the beginning of the list to NULL and the last person to the beginning of the list
    people = NULL;
    person_last = people;
    
    // provide space for the next persons' structure
    person_next = ( person* )malloc( sizeof( person ) );
    
    // open the data file
    probe( people_data = fopen( data_file_name, "r" ), "error opening file" );
    
    // we read the first record separately as that removes the need to check,
    // if the first person has already been set, every time we read a record
    if ( fscanf( people_data, "%s %s %d", person_next->first_name, person_next->last_name, &person_next->age) )
    {
        // there is a first record, so set first/last person to next person
        // also set the pointer to the next person to NULL
        people = person_next;
        person_last = person_next;
        person_last->next = NULL;
    }
    else
    {
        // there is no data in the file, free the memory we created for the next person & return NULL
        free( person_next );
        
        return NULL;
    }
    
    // create space for the next person
    person_next = ( person* )malloc( sizeof( person ) );
        
    // keep reading records until there is nothing to read any more
    while ( fscanf( people_data, "%s %s %d", person_next->first_name, person_next->last_name, &person_next->age ) == 3 )
    {
        // we successfully read one record:
        // - update the 'next' pointer of the last person to be the next person
        person_last->next = person_next;
        // - set the pointer to last person to the next person (which is now the new last)
        person_last = person_next;
        // - update the next pointer of the new last person to point to NULL
        person_last->next = NULL;
        
        // provide space for the new next person
        person_next = ( person* )malloc( sizeof( person ) );
    }
    
    // cleanup
    free( person_next );
    fclose( people_data );

    return people;
    
error:
    // free any resources and return
    free( person_next );
    
    return NULL;
}


/*
 * Return the age average of all persons in the list
 */
float people_average_age( person* people )
{
    // declare and initialize variables
    int number_persons = 0;
    float age_total = 0;

    // run through the linked list until we hit NULL as the next person
    while ( people != NULL )
    {
        // update number of persons
        number_persons++;
        // add age to age total
        age_total += people->age;
        // update pointer to the person that we will look at next
        people = people->next;
        
    }

    // compute and return age average
    return ( age_total / number_persons );
}


/*
 * Print the names of all persons, whose age is above average
 */
void people_print_age_above_average( person* people )
{
    // declare and initialize variables
    float average_age = people_average_age( people );

    // run through the linked list until we hit NULL as the next person
    while ( people != NULL )
    {
        // compare age of this person with average age and possibly print name
        if( people->age > average_age )
        {
        	printf( "%s %s is above the average age \n", people->first_name, people->last_name );
		}
        
        // update pointer to the person that we will look at next
        people = people->next;
    }
}
