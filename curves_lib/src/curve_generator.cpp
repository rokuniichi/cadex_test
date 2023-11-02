#include "curves_lib/curve_generator.h"
#include "curves_lib/vector3d.h"
#include "curves_lib/circle.h"
#include "curves_lib/ellipse.h"
#include "curves_lib/helix.h"

#include <iostream>

CurveGenerator::CurveGenerator()
{
	std::random_device random_device{};
	engine = std::mt19937(random_device());
}
 
int CurveGenerator::GenerateRandomInteger(const int min, const int max)
{
	std::uniform_int_distribution<> intDist = std::uniform_int_distribution<>(min, max);
	return intDist(engine);
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
			result.push_back(std::make_shared<Circle>(realDist(engine), Vector3D(realDist(engine), realDist(engine))));
			break;
		case ellipse:
			result.push_back(std::make_shared<Ellipse>(realDist(engine), realDist(engine), Vector3D(realDist(engine), realDist(engine))));
			break;
		case helix:
			result.push_back(std::make_shared<Helix>(realDist(engine), realDist(engine), Vector3D(realDist(engine), realDist(engine), realDist(engine))));
			break;
		default:
			result.push_back(std::make_shared<Circle>(realDist(engine)));
			break;
		}
	}

	return result;
}
