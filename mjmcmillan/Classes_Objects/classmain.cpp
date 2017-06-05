#include <stdio.h>
#include "vec3.h"
#include "getnumber.h"

int main()
{
	printf("%s\n", "Let's have some fun with vectors.");
	printf("%s\n", " We are going to generate two vectors, find their magnitude,");
	printf("%s\n", "add them, subtract them, and perform scalar multiplication on them");
	printf("%s\n", "to create several new vectors and find their magnitudes as well."); 
	printf("%s\n", "Please enter the x value of the first vector.");
	double xValue1 = getdouble();
	printf("%s\n", "Please enter the y value of the first vector.");
	double yValue1 = getdouble();
	printf("%s\n", "Please enter the z value of the first vector.");
	double zValue1 = getdouble();
	Vec3 first (xValue1, yValue1, zValue1);
	printf("%s %f\n", "The magnitude of your first vector is ", first.magnitude());

	printf("%s\n", "Please enter the x value of the second vector.");
	double xValue2 = getdouble();
	printf("%s\n", "Please enter the y value of the second vector.");
	double yValue2 = getdouble();
	printf("%s\n", "Please enter the z value of the second vector.");
	double zValue2 = getdouble();
	Vec3 second (xValue2, yValue2, zValue2);
	printf("%s %f\n", "The magnitude of your second vector is ", second.magnitude());

	Vec3 newaddvec = first + second;
	printf("%s\n", "This is what it looks like if we add those vectors together.");
	printf("(%g,%g,%g)\n", newaddvec.x, newaddvec.y, newaddvec.z);
	printf("%s %f\n", "This vector's magnitude is ", newaddvec.magnitude());

	Vec3 newsubvec = first - second;
	printf("%s\n", "This is what it looks like if we subract the first vector - the second.");
	printf("(%g,%g,%g)\n", newsubvec.x, newsubvec.y, newsubvec.z);
	printf("%s %f\n", "This vector's magnitude is ", newsubvec.magnitude());

	printf("%s\n", "Please pick a number to multiply by");
	double ink = getdouble();
	printf("%s\n", "Please pick which vector you would like to multiply.");
	printf("%s\n", "If you would like to mulitply the first vector enter 1");
	printf("%s\n", "If you would like to mulitply the second vector enter 2");
	printf("%s\n", "If you would like to mulitply the added or third vector enter 3");
	printf("%s\n", "If you would like to mulitply the subtracted or fourth vector enter 4");
	int choice = getint();
	if (choice == 1)
		{
			Vec3 newmultvec = ink * first;
			printf("%s %f.\n", "You chose to mulitply the first vector by", ink);
			printf("%s\n", "Your new vector looks like this:");
			printf("(%g,%g,%g)\n", newmultvec.x, newmultvec.y, newmultvec.z);
			printf("%s %f\n", "This vector's magnitude is ", newmultvec.magnitude());
		}

	else if (choice == 2)
		{
			Vec3 newmultvec = ink * second;
			printf("%s %f.\n", "You chose to mulitply the second vector by", ink);
			printf("%s\n", "Your new vector looks like this:");
			printf("(%g,%g,%g)\n", newmultvec.x, newmultvec.y, newmultvec.z);
			printf("%s %f\n", "This vector's magnitude is ", newmultvec.magnitude());
		}

	else if (choice == 3)
		{
			Vec3 newmultvec = ink * newaddvec;
			printf("%s %f.\n", "You chose to mulitply the third vector by", ink);
			printf("%s\n", "Your new vector looks like this:");
			printf("(%g,%g,%g)\n", newmultvec.x, newmultvec.y, newmultvec.z);
			printf("%s %f\n", "This vector's magnitude is ", newmultvec.magnitude());
		}

	else if (choice == 4)
		{
			Vec3 newmultvec = ink * newsubvec;
			printf("%s %f.\n", "You chose to mulitply the fourth vector by", ink);
			printf("%s\n", "Your new vector looks like this:");
			printf("(%g,%g,%g)\n", newmultvec.x, newmultvec.y, newmultvec.z);
			printf("%s %f\n", "This vector's magnitude is ", newmultvec.magnitude());
		}

	else
		{
			printf("%s\n", "Sorry that's not an option.  Guess you don't want to play anymore.");
		}
	return 0;
}