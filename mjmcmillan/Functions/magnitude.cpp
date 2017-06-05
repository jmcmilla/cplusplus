#include <iostream>
#include <stdio.h>
#include "vectorheader.h"

double magnitude (double x, double y, double z)
{
	double x2 = square(x);
	double y2 = square(y);
	double z2 = square(z);
	double sum = x2 + y2 + z2;
	double mag = sqrrt(sum);
	return mag;
}