#define _USE_MATH_DEFINES
#include <math.h>
#include <omp.h>
#include <iostream>
#include <iomanip>
#include <vector>

#include <curves_lib/curve_generator.h>
#include <curves_lib/circle.h>

int main()
{
	const double t = M_PI / 4;
	CurveGenerator cg = CurveGenerator();
	const int count = cg.GenerateRandomInteger(5, 10);

	std::cout << std::setprecision(4) << std::fixed;

	std::cout << "Generating " << count << " curves..." << std::endl;
	std::cout << std::endl;

	std::vector<std::shared_ptr<Curve>> curves = cg.GenerateRandomCurves(count, 0.1, 1.0);
	std::vector<std::shared_ptr<Circle>> circles;

	for (const std::shared_ptr<Curve> &curve : curves) 
	{
		if (std::shared_ptr<Circle> circle = std::dynamic_pointer_cast<Circle>(curve))
		{
			circles.push_back(circle);
		}

		std::cout << *curve << std::endl;
		std::cout << "Coords at " << t << " " << curve->GetPoint(t) << std::endl;
		std::cout << "First derivative at " << t << " " << curve->GetFirstDerivative(t) << std::endl;
		std::cout << std::endl;
	}

	std::cout << "Unsorted circles radii: ";
	for (const std::shared_ptr<Circle> &circle : circles)
	{
		std::cout << circle->radius << " ";
	}
	std::cout << std::endl;
	std::sort(circles.begin(), circles.end(), [](const std::shared_ptr<Circle> &a, const std::shared_ptr<Circle> &b) 
		{
			return a->radius < b->radius;
		});
	std::cout << "Sorted circles radii: ";
	for (const std::shared_ptr<Circle> &circle : circles)
	{
		std::cout << circle->radius << " ";
	}
	std::cout << std::endl;

	double radiiSum = 0;
	#pragma omp parallel for reduction(+: radiiSum)
	for (std::shared_ptr<Circle> &circle : circles) {
		radiiSum += circle->radius;
	}
	std::cout << "Radii sum = " << radiiSum << std::endl;
	return 0;
}
