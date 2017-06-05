#include <stdio.h>
#include "getnumber.h"
#include "vec3template.h"

int main()
{
  printf("%s\n", "Let's have some fun with vectors.");
	printf("%s\n", " We are going to generate four vectors, find their magnitude,");
	printf("%s\n", "add them, subtract them, and perform scalar multiplication on them");
	printf("%s\n", "to create several new vectors and find their magnitudes as well.");

	printf("%s\n", "Please enter an integer x value for the first vector.");
	int xValue1 = getint();
	printf("%s\n", "An integer y value please.");
	int yValue1 = getint();
	printf("%s\n", "Z value please.");
	int zValue1 = getint();
	Vec3<int> first (xValue1, yValue1, zValue1);
	printf("%s", "The magnitude of your first vector is ");
  first.outputsingle(first.magnitude());

  printf("%s\n", "Please enter another integer x value for the second vector.");
	int xValue2 = getint();
	printf("%s\n", "An integer y value please.");
	int yValue2 = getint();
	printf("%s\n", "Z value please.");
	int zValue2 = getint();
	Vec3<int> second (xValue2, yValue2, zValue2);
	printf("%s", "The magnitude of your second vector is ");
  second.outputsingle(second.magnitude());

  printf("%s\n", "Please enter a double x value for the third vector.");
	double xValue1doub = getdouble();
	printf("%s\n", "A double y value please.");
	double yValue1doub = getdouble();
	printf("%s\n", "Z value please.");
	double zValue1doub = getdouble();
	Vec3<double> firstdoub (xValue1doub, yValue1doub, zValue1doub);
	printf("%s", "The magnitude of your third vector is ");
  firstdoub.outputsingle(firstdoub.magnitude());

  printf("%s\n", "Please enter another double x value for the fourth vector.");
	double xValue2doub = getdouble();
	printf("%s\n", "A double y value please.");
	double yValue2doub = getdouble();
	printf("%s\n", "Z value please.");
	double zValue2doub = getdouble();
	Vec3<double> seconddoub (xValue2doub, yValue2doub, zValue2doub);
	printf("%s", "The magnitude of your fourth vector is ");
  seconddoub.outputsingle(seconddoub.magnitude());

  Vec3<int> newaddvec = first + second;
  printf("%s\n", "This is what it looks like if we add your integer vectors together.");
	newaddvec.outputvector();
	printf("%s", "This vector's magnitude is ");
  newaddvec.outputsingle(newaddvec.magnitude());

  Vec3<int> newsubvec = first - second;
  printf("%s\n", "This is what it looks like if we subract the first vector - the second.");
	newsubvec.outputvector();
	printf("%s", "This vector's magnitude is ");
  newsubvec.outputsingle(newsubvec.magnitude());

  Vec3<double> newaddvecd = firstdoub + seconddoub;
  printf("%s\n", "This is what it looks like if we add your double vectors together.");
	newaddvecd.outputvector();
	printf("%s", "This vector's magnitude is ");
  newaddvecd.outputsingle(newaddvecd.magnitude());

  Vec3<double> newsubvecd = firstdoub - seconddoub;
  printf("%s\n", "This is what it looks like if we subract the third vector - the fourth.");
	newsubvecd.outputvector();
	printf("%s", "This vector's magnitude is ");
  newsubvecd.outputsingle(newsubvecd.magnitude());

  printf("%s\n", "Please pick a number to multiply your integer vectors by");
  int inki = getint();
  printf("%s\n", "Please pick which vector you would like to multiply.");
  printf("%s\n", "If you would like to mulitply the first vector enter 1");
  printf("%s\n", "If you would like to mulitply the second vector enter 2");
  printf("%s\n", "If you would like to mulitply the fifth vector or the integer added vector enter 3");
  printf("%s\n", "If you would like to mulitply the sixth vector or the integer subtracted vector enter 4");
  int choice1 = getint();
  if (choice1 == 1)
    {
      Vec3<int> newmultvec = inki * first;
      printf("%s %i.\n", "You chose to mulitply the first vector by", inki);
      printf("%s\n", "Your new vector looks like this:");
      newmultvec.outputvector();
      printf("%s", "This vector's magnitude is ");
      newmultvec.outputsingle(newmultvec.magnitude());
    }

  else if (choice1 == 2)
    {
      Vec3<int> newmultvec = inki * second;
      printf("%s %i.\n", "You chose to mulitply the second vector by", inki);
      printf("%s\n", "Your new vector looks like this:");
      newmultvec.outputvector();
      printf("%s", "This vector's magnitude is ");
      newmultvec.outputsingle(newmultvec.magnitude());
    }

  else if (choice1 == 3)
    {
      Vec3<int> newmultvec = inki * newaddvec;
      printf("%s %i.\n", "You chose to mulitply the fifth vector by", inki);
      printf("%s\n", "Your new vector looks like this:");
      newmultvec.outputvector();
      printf("%s", "This vector's magnitude is ");
      newmultvec.outputsingle(newmultvec.magnitude());
    }

  else if (choice1 == 4)
    {
      Vec3<int> newmultvec = inki * newsubvec;
      printf("%s %i.\n", "You chose to mulitply the sixth vector by", inki);
      printf("%s\n", "Your new vector looks like this:");
      newmultvec.outputvector();
      printf("%s", "This vector's magnitude is ");
      newmultvec.outputsingle(newmultvec.magnitude());
    }

  else
    {
      printf("%s\n", "Sorry that's not an option.  Guess you don't want to play anymore.");
    }

	printf("%s\n", "Please pick a number to multiply your double vectors by");
	double ink = getdouble();
	printf("%s\n", "Please pick which vector you would like to multiply.");
	printf("%s\n", "If you would like to mulitply the third vector enter 1");
	printf("%s\n", "If you would like to mulitply the fourth vector enter 2");
	printf("%s\n", "If you would like to mulitply the seventh vector or the double added vector enter 3");
	printf("%s\n", "If you would like to mulitply the eigth vector or the double subtracted vector enter 4");
	int choice = getint();
	if (choice == 1)
		{
			Vec3<double> newmultvecd = ink * firstdoub;
			printf("%s %f.\n", "You chose to mulitply the third vector by", ink);
			printf("%s\n", "Your new vector looks like this:");
			newmultvecd.outputvector();
			printf("%s", "This vector's magnitude is ");
      newmultvecd.outputsingle(newmultvecd.magnitude());
		}

	else if (choice == 2)
		{
			Vec3<double> newmultvecd = ink * seconddoub;
			printf("%s %f.\n", "You chose to mulitply the fourth vector by", ink);
			printf("%s\n", "Your new vector looks like this:");
			newmultvecd.outputvector();
			printf("%s", "This vector's magnitude is ");
      newmultvecd.outputsingle(newmultvecd.magnitude());
		}

	else if (choice == 3)
		{
			Vec3<double> newmultvecd = ink * newaddvecd;
			printf("%s %f.\n", "You chose to mulitply the seventh vector by", ink);
			printf("%s\n", "Your new vector looks like this:");
      newmultvecd.outputvector();
			printf("%s", "This vector's magnitude is ");
      newmultvecd.outputsingle(newmultvecd.magnitude());
		}

	else if (choice == 4)
		{
			Vec3<double> newmultvecd = ink * newsubvecd;
			printf("%s %f.\n", "You chose to mulitply the fourth vector by", ink);
			printf("%s\n", "Your new vector looks like this:");
      newmultvecd.outputvector();
			printf("%s", "This vector's magnitude is ");
      newmultvecd.outputsingle(newmultvecd.magnitude());
		}

	else
		{
			printf("%s\n", "Sorry that's not an option.  Guess you don't want to play anymore.");
		}
	return 0;
}
