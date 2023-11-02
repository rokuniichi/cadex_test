#include "curves_lib/curve.h" 

double Curve::Validate(const double p) const 
{
	if (p <= 0.0) {
		throw std::invalid_argument("Error while constructing a curve (zero/negative parameter)");
	}

	return p;
}

std::ostream& operator<<(std::ostream& out, Curve& c)
{
	return c.Print(out);
}
