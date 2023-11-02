#include "curves_lib/curve_generator.h"
#include "curves_lib/vector3d.h"
#include "curves_lib/circle.h"
#include "curves_lib/ellipse.h"
#include "curves_lib/helix.h"

#include <iostream>
 
int CurveGenerator::GenerateRandomInteger(const int min, const int max)
{
	std::uniform_int_distribution<> intDist = std::uniform_int_distribution<>(min, max);
	return intDist(seed);
}

std::vector<std::shared_ptr<Curve>> CurveGenerator::GenerateRandomCurves(const int count, const double min, const double max)
{
	std::uniform_real_distribution<> realDist = std::uniform_real_distribution<>(min, max);
	std::vector<std::shared_ptr<Curve>> result;
	result.reserve(count);

	for (int i = 0; i < count; i++)
	{
		switch (GenerateRandomInteger(circle, helix))
		{
		case circle:
			result.push_back(std::make_shared<Circle>(realDist(seed), Vector3D(realDist(seed), realDist(seed))));
			break;
		case ellipse:
			result.push_back(std::make_shared<Ellipse>(realDist(seed), realDist(seed), Vector3D(realDist(seed), realDist(seed))));
			break;
		case helix:
			result.push_back(std::make_shared<Helix>(realDist(seed), realDist(seed), Vector3D(realDist(seed), realDist(seed), realDist(seed))));
			break;
		default:
			result.push_back(std::make_shared<Circle>(realDist(seed)));
			break;
		}
	}

	return result;
}
