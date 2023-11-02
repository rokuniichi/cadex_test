#pragma once

#include "curve.h"

struct Circle : public Curve 
{
public:
	const double radius;
	const Vector3D center;

	Circle(const double radius);
	Circle(const double radius, const Vector3D center);

	Vector3D GetPoint(const double t) const override;
	Vector3D GetFirstDerivative(const double t) const override;
	std::ostream& Print(std::ostream& out) override;
};