// Mario DeCristofaro EE222  LinkedList HomeWork  12/06/2019

#ifndef person_h
#define person_h

#include <stdio.h>

// structure of a person's data, suitable to be used in a linked list
typedef struct _person
{
    char first_name[ 32 ];
    char last_name[ 32 ];
    int age;
    struct _person* next;
} person;

// function prototype declarations
person* people_create_list( char* data_file_name );
float people_average_age( person* people );
void people_print_age_above_average( person* people );

#endif /* person_h */
