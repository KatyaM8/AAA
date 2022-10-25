#include <iostream>
#include <vector>
#include <cmath>
int main() {
	int k = 0;
	int i = 1;
	int s = 0;
	while (i != 0) {
		std::cin >> i;
		s = s + i;
	}
	std::cout << s;
}