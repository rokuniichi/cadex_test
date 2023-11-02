#pragma once

#include "curve.h"

struct Ellipse : public Curve
{
public:
	const double radiusX, radiusY;
	const Vector3D center;

	Ellipse(const double radiusX, const double radiusY);
	Ellipse(const double radiusX, const double radiusY, const Vector3D center);

	Vector3D GetPoint(const double t) const override;
	Vector3D GetFirstDerivative(const double t) const override;
	std::ostream& Print(std::ostream& out) override;
};