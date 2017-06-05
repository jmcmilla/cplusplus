#include <iostream>
#include <stdio.h>
#include "vectorheader.h"

int main()
{
	printf("%s\n", "Today we are going to find the magnitude of a vector.  Please enter the x value of the vector");
	double xValue = getdouble();
	printf("%s\n", "Please enter the y value of the vector.");
	double yValue = getdouble();
	printf("%s\n", "Please enter the z value of the vector.");
	double zValue = getdouble();
	printf("%s", "Your vector's magnitude is:");
	printf("%g\n", magnitude(xValue, yValue, zValue));
	return 0;
}