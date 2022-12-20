#include <iostream>
#include <cmath>
int main() {
	float a = 0;
	float b = 1;
	double si = 0.05;
	double m = 0.0001;
	std::cout << "x | s(x)" << std::endl;
	double s = 0;
	int factor = 1;
	for (double x = a; x <= b; x += si) {
		double i = -1;
		s = 0;
		double k = 1;
		while (abs(k) > m && k != 0) {
			i += 1;
			factor *= i;
			k = std::pow(2 * x, i) / factor*(-i);
			s += k;
		}
		std::cout << x << " | " << s << std::endl;
	}
	return 0;
}
