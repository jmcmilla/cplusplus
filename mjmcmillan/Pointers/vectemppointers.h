#ifndef VECTEMPPOINTERS_H
#define VECTEMPPOINTERS_H

#include <cmath>
#include <stdio.h>
template <class vartype>
class Vec
{
public:

  vartype* comp;
  int size;

  Vec<vartype> (vartype components[], int arylength)
  {
    size = arylength;
    comp = new vartype[size];
    for (int i = 0; i < size; i++)
      {
        comp[i] = components[i];
      }

  }

  vartype magnitude ()
  {
    vartype sum = 0;
    for (int i = 0; i < size; i++)
      {
        vartype component = comp[i];
        sum += (component * component);
      }
    vartype mag = std::sqrt(sum);
    return mag;
  }

  void outputvector()
    {
      printf("(");
      for (int i = 0; i < size; i++)
        {
          outputsingle(comp[i]);
          if (i != size - 1) printf(",");
        }
      printf(")\n");
    }

  void outputsingle(vartype value);
};

template< class vartype>
Vec<vartype> operator*(vartype k, Vec<vartype> rhs)
{
  vartype* multcomp = nullptr;
  multcomp = new vartype[rhs.size];
  for (int i = 0; i < rhs.size; i++)
    {
      multcomp[i] = k * rhs.comp[i];
    }
  return Vec<vartype> (multcomp, rhs.size);
}

template<class vartype>
Vec<vartype> operator+(Vec<vartype> lhs, Vec<vartype> rhs)
{
  if (lhs.size != rhs.size) return lhs;
    vartype* addcomp = nullptr;
    addcomp = new vartype[lhs.size];
    for (int i = 0; i < lhs.size; i++)
      {
        addcomp[i] = lhs.comp[i] + rhs.comp[i];
      }
    return Vec<vartype> (addcomp, lhs.size);
}

template<class vartype>
Vec<vartype> operator-(Vec<vartype> lhs, Vec<vartype> rhs)
{
  if (lhs.size != rhs.size) return lhs;
  vartype* subcomp = nullptr;
  subcomp = new vartype[lhs.size];
  for (int i = 0; i < lhs.size; i++)
    {
      subcomp[i] = lhs.comp[i] - rhs.comp[i];
    }
  return Vec<vartype> (subcomp, lhs.size);
}

/*template<>
void Vec<int>::outputvector()
{
  printf("(");
  for (int i = 0; i < size; i++)
    {
      if (i == size -1) printf("%i", comp[i]);
      printf("%i,", comp[i]);
    }
  printf(")\n");
}

template<>
void Vec<double>::outputvector()
{
  printf("(");
  for (int i = 0; i < size; i++)
    {
      if (i == size - 1) printf("%f", comp[i]);
      printf("%f,", comp[i]);
    }
  printf(")\n");
}*/

template<>
void Vec<int>::outputsingle(int value)
{
  printf("%i", value);
}

template<>
void Vec<double>::outputsingle(double value)
{
  printf("%f", value);
}

#endif
