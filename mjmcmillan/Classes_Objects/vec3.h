#ifndef VEC3_H
#define VEC3_H

class Vec3
{
	public:

	double x;
	double y;
	double z;

	Vec3 (double xcomp, double ycomp, double zcomp)
	{
		x = xcomp;
		y = ycomp;
		z = zcomp;
	}

	double magnitude ();
};
Vec3 operator+(Vec3 left, Vec3 right);
Vec3 operator-(Vec3 left, Vec3 right);
Vec3 operator*(double k, Vec3 right);

#endif