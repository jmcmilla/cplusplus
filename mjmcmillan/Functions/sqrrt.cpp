#include <iostream>
#include <stdio.h>
#include "vectorheader.h"

double sqrrt (double value)
{
	double squareroot = value / 2.0f;
	if (-.00001 < squareroot && squareroot < .00001)
		{
		return 0.0f;
		}
	for (int i = 0; i <10; ++i)
		{
		squareroot += value/squareroot;
		squareroot *= 0.5f;
		}
		return squareroot;
}