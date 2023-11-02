#pragma once

#include "curve.h"

struct Helix : public Curve 
{
public:
	const double radius, step;
	const Vector3D center;

	Helix(const double radius, const double step);
	Helix(const double radius, const double step, const Vector3D center);

	Vector3D GetPoint(const double t) const override;
	Vector3D GetFirstDerivative(const double t) const override;
	std::ostream& Print(std::ostream& out) override;	
};