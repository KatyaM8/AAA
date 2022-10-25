#include <iostream>
#include <vector>
#include <cmath>
int main() {
	int maxim = 0;
	int i = 1;
	while (i != 0) {
		std::cin >> i;
		if (i > maxim) {
			maxim = i;
		}
	}
	std::cout << maxim;
}