// Mario DeCristofaro, EE222, F_to_C HW, September 19, 2019
#include <stdio.h>
#include <stdlib.h>

#include "f_to_c.h"

void f_to_c_while( void )
{
	// declare vars
	float f_Temp = 0;
	float c_Temp;
	
	// while loop to meet constraints
	while( f_Temp <= 66 )
	{
		printf("\nWhile Loop C to F\n");
		printf( "\nFahrenheit is : %f \n", f_Temp );
		c_Temp = ( f_Temp - C_FOFFSET ) * C_FCONSTANT;
		printf( "Celcius is : %f \n", c_Temp );
		f_Temp += 1.5;
	}
}
