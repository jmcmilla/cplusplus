#ifndef VEC3TEMPLATE_H
#define VEC3TEMPLATE_H

#include <cmath>
#include <stdio.h>
template <class vartype>
class Vec3
{
public:
  vartype x;
  vartype y;
  vartype z;

  Vec3<vartype> (vartype xValue, vartype yValue, vartype zValue)
    {
      x = xValue;
      y = yValue;
      z = zValue;
    }

  vartype magnitude ()
  {
    vartype x2 = x * x;
    vartype y2 = y * y;
    vartype z2 = z * z;
    vartype sum = x2 + y2 + z2;
    vartype mag = std::sqrt(sum);
    return mag;
  }

  void outputvector();

  void outputsingle(vartype value);
};

template< class vartype>
Vec3<vartype> operator*(vartype k, Vec3<vartype> rhs)
{
  vartype newx = k * rhs.x;
  vartype newy = k * rhs.y;
  vartype newz = k * rhs.z;
  return Vec3<vartype> (newx, newy, newz);
}

template<class vartype>
Vec3<vartype> operator+(Vec3<vartype> lhs, Vec3<vartype> rhs)
{
  vartype newx = lhs.x + rhs.x;
  vartype newy = lhs.y + rhs.y;
  vartype newz = lhs.z + rhs.z;
  return Vec3<vartype> (newx, newy, newz);
}

template<class vartype>
Vec3<vartype> operator-(Vec3<vartype> lhs, Vec3<vartype> rhs)
{
  vartype newx = lhs.x - rhs.x;
  vartype newy = lhs.y - rhs.y;
  vartype newz = lhs.z - rhs.z;
  return Vec3<vartype> (newx, newy, newz);
}

template<>
void Vec3<int>::outputvector()
{
  printf("(%i, %i, %i)\n", x, y, z);
}

template<>
void Vec3<double>::outputvector()
{
  printf("(%f, %f, %f)\n", x, y, z);
}

template<>
void Vec3<int>::outputsingle(int value)
{
  printf("%i\n", value);
}

template<>
void Vec3<double>::outputsingle(double value)
{
  printf("%f\n", value);
}

#endif
