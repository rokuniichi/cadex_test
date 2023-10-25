#pragma once

#include <iostream>

struct Vector3D
{
public:
	const double x, y, z;
	Vector3D();
	Vector3D(double x, double y);
	Vector3D(double x, double y, double z);
	friend std::ostream& operator<<(std::ostream& os, const Vector3D& v);
};