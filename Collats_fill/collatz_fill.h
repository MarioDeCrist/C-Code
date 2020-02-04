// Mario DeCristofaro, EE222, collatz_continued HW, October 15, 2019
#ifndef COLLATZ_FILL_H
#define COLLATZ_FILL_H
#define DBG
#include "dbg.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define COLLATZ_FILE "collatz.txt"
#define MAX_NUMBER 100

bool collatz_fill( int array[] );
int collats_max( int array[] );
float collatz_average( int array[] );
int collatz_greater_average( int array[] );

#endif
