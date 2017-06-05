#include "vec3.h"

double square (double number)
{
	double sq = number * number;
	return sq;
}

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

double Vec3::magnitude ()
{
	double x2 = square(x);
	double y2 = square(y);
	double z2 = square(z);
	double sum = x2 + y2 + z2;
	double mag = sqrrt(sum);
	return mag;
}

Vec3 operator+(Vec3 left, Vec3 right)
{
	double newx = left.x + right.x;
	double newy = left.y + right.y;
	double newz = left.z + right.z;
	return Vec3 (newx, newy, newz);
}

Vec3 operator-(Vec3 left, Vec3 right)
{
	double newx = left.x - right.x;
	double newy = left.y - right.y;
	double newz = left.z - right.z;
	return Vec3 (newx, newy, newz);
}

Vec3 operator*(double k, Vec3 vector)
{
	double newx = k * vector.x;
	double newy = k * vector.y;
	double newz = k * vector.z;
	return Vec3 (newx, newy, newz);
}
