#include <iostream>
#include <cmath>
#include <array>

std::array<double, 2> function(int &a, int &b, double &step, double &eps) {
	auto e = [&](double x) -> double {
		double y = 0;
		double t;
		double last = 0;
		for (int i = 0; i < 100; i++) {
			t = std::pow(-1, i) * (std::pow(x, 2 * i) / (std::tgamma(2 * i + 1)));
			if (std::abs(t - last) < eps) {
				break;
			}
			y += t;
			last = t;
		}
		return y;
	};

	auto e2 = [](double x) -> double {
		return std::cos(x);
	};

	double resA = 0;
	double resR = 0;
	double x;
	for (int i = 0; i <= (std::abs(a) + std::abs(b)) / step; i++) {
		x = a + i * step;
		double temp = e(x);
		double compareTemp = e2(x);
		printf("%8.5f | %8.5f | %8.5f\n", x, temp, compareTemp);
		resA += temp;
		resR += compareTemp;
	}
	return std::array<double, 2> {resA, resR};
}

int main() {
	int c = -1;
	int g = 1;
	double step = 0.1;
	double eps = 10e-3;
	printf("%8s | %8s | %8s\n", "x", "s(x)", "f(x)");
	std::array<double, 2> res = function(c, g, step, eps);
	printf("SumAnalytical: %.5f\tSumReal: %.5f", res[0], res[1]);
}
