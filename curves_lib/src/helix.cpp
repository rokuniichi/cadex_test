#include "curves_lib/helix.h"

#define _USE_MATH_DEFINES
#include <math.h>

Helix::Helix(double radius, double step) : radius{ Validate(radius) }, step{ step }, center { Vector3D() } {}
Helix::Helix(double radius, double step, Vector3D center) : radius{ Validate(radius) }, step{ step }, center { center } {}

Vector3D Helix::GetPoint(double t) const
{ 
	return Vector3D(center.x + radius * cos(t), center.y + radius * sin(t), center.z + step * t / (2 * M_PI));
}

Vector3D Helix::GetFirstDerivative(double t) const
{
	return Vector3D(-radius * sin(t), radius * cos(t), step / (2 * M_PI));
}

std::ostream& Helix::Print(std::ostream& out)
{
	out << "Helix of radius (" << radius << "), step (" << step << "), center at " << center;
	return out;
}
