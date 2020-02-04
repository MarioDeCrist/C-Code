//Mario DeCristofaro, EE222, F_to_C HW, September 19, 2019
#include <stdio.h>
#include <stdlib.h>

#include "f_to_c.h"

void f_to_c_for( void )
{
	float c_Temp;
	float f_Temp;
	
	// for loop to meet constraints
	for( f_Temp = 0; f_Temp <= 66; f_Temp = f_Temp + 1.5 )
	{
		printf("\nFor Loop C to F \n");
		printf("\nFarenheit is : %f \n", f_Temp);
		c_Temp = ( f_Temp - C_FOFFSET ) * C_FCONSTANT;
		printf( "and the Celcius is %f \n", c_Temp);
	}
}
