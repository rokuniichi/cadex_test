#pragma once

#include "curve.h"

struct Circle : public Curve 
{
public:
	const double radius;
	const Vector3D center;

	Circle(double radius);
	Circle(double radius, Vector3D center);

	Vector3D GetPoint(double t) const override;
	Vector3D GetFirstDerivative(double t) const override;
	std::ostream& Print(std::ostream& out) override;
};