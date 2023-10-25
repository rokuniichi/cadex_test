#pragma once

#include "curve.h"

#include <random>
#include <vector>

struct CurveGenerator
{
public:
	CurveGenerator();

	int GenerateRandomInteger(int min, int max);
	std::vector<std::shared_ptr<Curve>> GenerateRandomCurves(int count, double min, double max);
private:
	const enum CurveType { circle, ellipse, helix };
	std::mt19937 engine;
};