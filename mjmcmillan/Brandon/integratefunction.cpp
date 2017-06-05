#include <math.h>
#include <iostream>
#include <stdio.h>

double integrate (double (*f)(double), double x0, double x1, int n)
{
	double range = x1 - x0;
	double deltax = range / n;
	double totalarea = 0;
	for (int i = 0; i < n; i ++)
		{
		double recarea = deltax * f((i * deltax) + x0);
		totalarea += recarea;
		}
	return totalarea;
}

int main ()
{
	double integral = 0;
	integral = integrate (sin, 0, M_PI, 1000000000);
	printf("%g\n", integral);
	return 0;
}
