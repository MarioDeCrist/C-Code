// Mario DeCristofaro_EE222_Project2_interpolation
#include "interpolation.h"

float interpolation(float x1, float y1, float x2, float y2, float x)
{
	// formula for interpolation
	float y = ( ( (x - x1) * (y2 - y1) ) / (x2 - x1) ) + y1;
	
	return y;
}
