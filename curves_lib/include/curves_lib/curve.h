#pragma once

#include "vector3d.h"

#include <iostream>

struct Curve {
public:
	virtual Vector3D GetPoint(double t) const = 0;
	virtual Vector3D GetFirstDerivative(double t) const = 0;
	virtual std::ostream& Print(std::ostream& out) = 0;
	friend std::ostream& operator<<(std::ostream& out, Curve& c);

	virtual ~Curve() = default;
protected:
	virtual double Validate(double p) const;
};