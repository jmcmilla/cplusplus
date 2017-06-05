#include <cmath>
#include <stdio.h>
#include "vectemppointers.h"
#include "getnumber.h"

int main ()
{
  printf("%s\n", "Let's have some fun with vectors.");
  printf("%s\n", "We'll make two integer vectors and two double vectors.");
  printf("%s\n", "Then we'll do some addition subtraction and mulitplication to get several others.");
  printf("%s\n", "Then we'll calculate the magnitude of all these vectors.");

  printf("%s\n", "How many components would you like your first integer vector to have?");
  int firstveclength = getint();
  int* components = nullptr;
  components = new int[firstveclength];
  for (int i = 0; i < firstveclength; i++)
    {
      printf("%s\n", "Please enter a component as an integer.");
      int comp = getint();
      components[i] = comp;
    }
  Vec<int> first(components, firstveclength);
  printf("%s %i\n", "Your first vector's magnitude is ", first.magnitude());

  printf("%s\n", "How many components would you like your second integer vector to have?");
  int secondveclength = getint();
  int* components2 = nullptr;
  components2 = new int[secondveclength];
  for (int i = 0; i < secondveclength; i++)
    {
      printf("%s\n", "Please enter a component as an integer.");
      int comp = getint();
      components2[i] = comp;
    }
  Vec<int> second(components2, secondveclength);
  printf("%s %i\n", "Your second vector's magnitude is ", second.magnitude());

  printf("%s\n", "How many components would you like your first double vector to have?");
  int firstdveclength = getint();
  double* components3 = nullptr;
  components3 = new double[firstdveclength];
  for (int i = 0; i < firstdveclength; i++)
    {
      printf("%s\n", "Please enter a component as an double.");
      double comp = getdouble();
      components3[i] = comp;
    }
  Vec<double> firstd(components3, firstdveclength);
  printf("%s %f\n", "Your third vector's magnitude is ", firstd.magnitude());

  printf("%s\n", "How many components would you like your second double vector to have?");
  int seconddveclength = getint();
  double* components4 = nullptr;
  components4 = new double[seconddveclength];
  for (int i = 0; i < seconddveclength; i++)
    {
      printf("%s\n", "Please enter a component as an double.");
      double comp = getdouble();
      components4[i] = comp;
    }
  Vec<double> secondd(components4, seconddveclength);
  printf("%s %f\n", "Your third vector's magnitude is ", secondd.magnitude());

  Vec<int> addvec = first + second;
  if (addvec.comp[0] == first.comp[0] && first.comp[0] != 0)
    {
      printf("%s\n", "We can't add your integer vectors because they aren't the same size.");
    }
  else
   {
    printf("%s\n", "This is what it looks like when we add your integer vectors together.");
    addvec.outputvector();
    printf("%s", "This vector's magnitude is ");
    addvec.outputsingle(addvec.magnitude());
    printf("\n");
    }

  Vec<int> subvec = first - second;
  if (subvec.comp[0] == first.comp[0] && first.comp[0] != 0)
    {
      printf("%s\n", "We can't subtract your integer vectors because they aren't the same size.");
    }
  else
    {
    printf("%s\n", "This is what it looks like when we subtract your first vector - your second.");
    subvec.outputvector();
    printf("%s", "This vector's magnitude is ");
    subvec.outputsingle(subvec.magnitude());
    printf("\n");
    }

  printf("%s\n", "Please choose a number to multiply your integer vectors by.");
  int k = getint();
  printf("%s\n", "Please choose which vector you'd like to multiply.");
  printf("%s\n", "If you'd like to multiply your first vector, enter 1.");
  printf("%s\n", "If you'd like to multiply your second vector, enter 2.");
  printf("%s\n", "If you'd like to multiply your fifth vector, enter 3.");
  printf("%s\n", "If you'd like to multiply your sixth vector, enter 4.");
  int choice = getint();
  switch(choice)
    {
    case 1:
      {
      printf("%s, %i\n", "You chose to multiply your first vector by", k);
      Vec<int> multvec = k * first;
      printf("%s\n", "Your new vector looks like this.");
      multvec.outputvector();
      printf("%s", "This vector's magnitude is ");
      multvec.outputsingle(multvec.magnitude());
      printf("\n");
      }
      break;
    case 2:
      {
      printf("%s, %i\n", "You chose to multiply your second vector by", k);
      Vec<int> multvec2 = k * second;
      printf("%s\n", "Your new vector looks like this.");
      multvec2.outputvector();
      printf("%s", "This vector's magnitude is ");
      multvec2.outputsingle(multvec2.magnitude());
      printf("\n");
      }
      break;
    case 3:
      {
      printf("%s, %i\n", "You chose to multiply your fifth vector by", k);
      Vec<int> multvec3 = k * addvec;
      printf("%s\n", "Your new vector looks like this.");
      multvec3.outputvector();
      printf("%s", "This vector's magnitude is ");
      multvec3.outputsingle(multvec3.magnitude());
      printf("\n");
      }
      break;
    case 4:
      {
      printf("%s, %i\n", "You chose to multiply your sixth vector by", k);
      Vec<int> multvec4 = k * subvec;
      printf("%s\n", "Your new vector looks like this.");
      multvec4.outputvector();
      printf("%s", "This vector's magnitude is ");
      multvec4.outputsingle(multvec4.magnitude());
      printf("\n");
      }
      break;
    }

  Vec<double> addvecd = firstd + secondd;
  if (addvecd.comp[0] == firstd.comp[0] && firstd.comp[0] != 0)
    {
      printf("%s\n", "We can't add your double vectors because they aren't the same size.");
    }
  else
    {
    printf("%s\n", "This is what it looks like when we add your double vectors together.");
    addvecd.outputvector();
    printf("%s", "This vector's magnitude is ");
    addvecd.outputsingle(addvecd.magnitude());
    printf("\n");
    }

  Vec<double> subvecd = firstd - secondd;
  if (subvecd.comp[0] == firstd.comp[0] && firstd.comp[0] != 0)
    {
      printf("%s\n", "We can't subtract your double vectors because they aren't the same size.");
    }
  else
    {
    printf("%s\n", "This is what it looks like when we subtract your third vector - your fourth.");
    subvecd.outputvector();
    printf("%s", "This vector's magnitude is ");
    subvecd.outputsingle(subvecd.magnitude());
    printf("\n");
    }

  printf("%s\n", "Please choose a number to multiply your double vectors by.");
  double kd = getdouble();
  printf("%s\n", "Please choose which vector you'd like to multiply.");
  printf("%s\n", "If you'd like to multiply your third vector, enter 1.");
  printf("%s\n", "If you'd like to multiply your fourth vector, enter 2.");
  printf("%s\n", "If you'd like to multiply your seventh vector, enter 3.");
  printf("%s\n", "If you'd like to multiply your eigth vector, enter 4.");
  int choiced = getint();
  switch(choiced)
    {
    case 1:
      {
      printf("%s, %f\n", "You chose to multiply your third vector by", kd);
      Vec<double> multvecd = kd * firstd;
      printf("%s\n", "Your new vector looks like this.");
      multvecd.outputvector();
      printf("%s", "This vector's magnitude is ");
      multvecd.outputsingle(multvecd.magnitude());
      printf("\n");
      }
      break;
    case 2:
      {
      printf("%s, %f\n", "You chose to multiply your fourth vector by", kd);
      Vec<double> multvecd2 = kd * secondd;
      printf("%s\n", "Your new vector looks like this.");
      multvecd2.outputvector();
      printf("%s", "This vector's magnitude is ");
      multvecd2.outputsingle(multvecd2.magnitude());
      printf("\n");
      }
      break;
    case 3:
      {
      printf("%s, %f\n", "You chose to multiply your seventh vector by", kd);
      Vec<double> multvecd3 = kd * addvecd;
      printf("%s\n", "Your new vector looks like this.");
      multvecd3.outputvector();
      printf("%s", "This vector's magnitude is ");
      multvecd3.outputsingle(multvecd3.magnitude());
      printf("\n");
      }
      break;
    case 4:
      {
      printf("%s, %f\n", "You chose to multiply your sixth vector by", kd);
      Vec<double> multvecd4 = kd * subvecd;
      printf("%s\n", "Your new vector looks like this.");
      multvecd4.outputvector();
      printf("%s", "This vector's magnitude is ");
      multvecd4.outputsingle(multvecd4.magnitude());
      printf("\n");
      }
      break;
    }

  delete components;
  delete components2;
  delete components3;
  delete components4;

  return 0;
}
