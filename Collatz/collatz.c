// Mario DeCristofaro, EE222, Fibonacci HW, September 26, 2019
#include "collatz.h"
#include "dbg.h"

int collatz( int number )
{
	int iterations = 0;
	
	while( number != 1 )
	{
		iterations++;
		
		if( number % 2 == 1 )
		{
			number = 3 * number + 1;
			debug( "odd number", number );
		}
		else
		{
			number = number / 2;
			debug( "even number", number );
		}
	}
	return iterations;
}
