// Mario DeCristofaro_EE222_Project1_mpgToLiters
#include "mpgConversion.h"

float mpg_to_lp100k( float mpg )
{
	//CONVERSION_CONST is used for converting to liters per 100 kilometers
	float kilosPLiter;
	
	kilosPLiter = CONVERSION_CONST / mpg;
	
	return kilosPLiter;
}
