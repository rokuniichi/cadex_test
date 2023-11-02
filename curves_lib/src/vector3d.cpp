#include "curves_lib/vector3d.h"

Vector3D::Vector3D() : x{ 0 }, y{ 0 }, z{ 0 } {}
Vector3D::Vector3D(const double x, const double y) : x{ x }, y{ y }, z{ 0 } {}
Vector3D::Vector3D(const double x, const double y, const double z) : x{ x }, y{ y }, z{ z } {}

std::ostream& operator<<(std::ostream& os, const Vector3D& v)
{
		return os << "{" << v.x << ", " << v.y << ", " << v.z << "}";
};

