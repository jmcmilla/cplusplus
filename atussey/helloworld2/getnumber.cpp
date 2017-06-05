#include "getnumber.h"
#include <iostream>
#include <stdio.h>

double getdouble () 
{
	double value = 0;
	bool isnumber = false;
	while (!isnumber)
		{
		if(!(1 == scanf("%lf", &value)))
			{
			printf("%s\n", "That number was invalid.");
			//Get rid of stored input
			while('\n' != getchar());
			}
		else
			{
			isnumber = true;
			}
		}
		return value;
}

int getint () 
{
	int value = 0;
	bool isnumber = false;
	while (!isnumber)
		{
		if(!(1 == scanf("%i", &value)))
			{
			printf("%s\n", "That number was invalid.");
			//Get rid of stored input
			while('\n' != getchar());
			}
		else
			{
			isnumber = true;
			}
		}
		return value;
}