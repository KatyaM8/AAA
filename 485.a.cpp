#include <iostream>
int main() {
	int a = 0;
	int m = 0;
	std::cin >> a >> m;
	int fl = 0;
	while (a % m != 0) {
		a += a % m;
		if (0 == a % m) {
			std::cout << "Yes";
			fl = 1;
		}
		if (0 == fl && a >= 10*10*10*10*10*10*10) {
			std::cout << "No";
			fl = 1;
			break;
		}
	}
	if (fl == 0) {
		std::cout << "Yes";
	}
}