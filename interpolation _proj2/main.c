// Mario DeCristofaro_EE222_Project2_interpolation
#include <stdio.h>
#include <stdlib.h>

#include "interpolation.h"



int main() 
{
	//declare variables
	float x1, y1, x2, y2, x = 0;
	
	// prompts user to input the values
	printf("Enter an x1, y1, x2, y2, x in order with a propper commas and spaces between values: ");
	scanf("%f, %f, %f, %f, %f", &x1, &y1, &x2, &y2, &x);
	printf("the interpolation of the points is: %f \n", interpolation(x1, y1, x2, y2, x));
	
	return EXIT_SUCCESS;
}
