#pragma once

#include "curve.h"

#include <random>
#include <vector>

struct CurveGenerator
{
public:
	CurveGenerator();

	int GenerateRandomInteger(const int min, const int max);
	std::vector<std::shared_ptr<Curve>> GenerateRandomCurves(const int count, const double min, const double max);
private:
	const enum CurveType { circle, ellipse, helix };
	std::mt19937 engine;
};