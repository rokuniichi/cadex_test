#pragma once

#include "curve.h"

struct Helix : public Curve 
{
public:
	const double radius, step;
	const Vector3D center;

	Helix(double radius, double step);
	Helix(double radius, double step, Vector3D center);

	Vector3D GetPoint(double t) const override;
	Vector3D GetFirstDerivative(double t) const override;
	std::ostream& Print(std::ostream& out) override;	
};