#include <iostream>
#include <vector>
#include <cmath>
int main() {
	int n;
	std::cin >> n;
	int i = 0;
	int fl = 0;
	while (i < n) {
		if (pow(2, i) == n) {
			std::cout << "YES";
			fl = 1;
		}
		i++;
	}
	if (fl == 0) {
		std::cout << "NO";
	}

}