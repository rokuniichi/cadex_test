#pragma once

#include "curve.h"

struct Ellipse : public Curve
{
public:
	const double radiusX, radiusY;
	const Vector3D center;

	Ellipse(double radiusX, double radiusY);
	Ellipse(double radiusX, double radiusY, Vector3D center);

	Vector3D GetPoint(double t) const override;
	Vector3D GetFirstDerivative(double t) const override;
	std::ostream& Print(std::ostream& out) override;
};