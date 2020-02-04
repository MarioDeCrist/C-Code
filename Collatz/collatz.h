// Mario DeCristofaro, EE222, Fibonacci HW, September 26, 2019
#ifndef collatz_h
#define collatz_h

#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
#define DATA_FILE "collatz.txt"
#define MAX_NUMBER 100

#define DBG
#include "dbg.h"

int collatz( int number );

#endif 
