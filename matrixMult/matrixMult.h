#include <stdio.h>
#include <stdlib.h>

// Mario DeCristofaro, EE222, Matrix Multiplication hw, November 19, 2019

#ifndef matrixMult_h
#define matrixMult_h
//delcare constants
#define SHARED 3
#define ROWS 2
#define COLS 4
// declare method
float* matrix_multiplication( float* left, float* right, int rows, int shared, int columns );

#endif
