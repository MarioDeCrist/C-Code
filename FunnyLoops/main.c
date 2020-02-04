#include <stdio.h>
#include <stdlib.h>

// Mario DeCristofaro, EE222, Funny_Loops HW, September 25, 2019

int main() 
{
	int innerIndex, outerIndex;
	float solution;
	
	//Loops through outer index
	for( outerIndex = 0; outerIndex <= 100; outerIndex += 10 )
	{
		//loops through inner index
		for( innerIndex = 3; innerIndex >= 0; innerIndex-- )
		{
			solution = outerIndex + innerIndex;
			printf("%f deg fahrenheit is %f in celcius\n", solution, ( solution - 32 ) * 5/9);
		}
	}
	return EXIT_SUCCESS;
}
