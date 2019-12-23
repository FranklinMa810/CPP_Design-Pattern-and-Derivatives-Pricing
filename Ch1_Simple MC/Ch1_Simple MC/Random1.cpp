#include "Random1.h"
#include <cstdlib>
#include <cmath>

double GetOneGaussianBySummation()
{
	double result = 0.0;
	for (int i = 0; i < 12; ++i) 
		result += rand() / static_cast<double>(RAND_MAX);
	result -= 6;
	return result;
}

double GetOneGaussianByBoxMuller()
{
	double result;
	double x, y;
	double sizeSquared;

	do
	{
		x = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
		y = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
		sizeSquared = x * x + y * y;
	} while (sizeSquared >= 1.0);
	result = x * sqrt(-2 * log(sizeSquared) / sizeSquared);

	return result;
}

