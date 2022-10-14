#include <iostream>
#include <vector>
#include <cmath>
int main() {
	int index1 = 0;
	int index2 = 0;
	int kolnabr = 0;
	std::cin >> kolnabr;
	for (int i = 0; i < kolnabr; i++) {
		int n = 0;
		int fl1 = 0;
		int fl2 = 0;
		int kolv0 = 0;
		std::cin >> n;
		std::vector <int> a(n);
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			if (a[i] == 0) {
				kolv0 += 1;
			}
		}
		if (kolv0 == 0) {
			std::cout << 0;
		}
		else {
			if (n > 2) {
				for (int i = 0; i < n; i++) {
					if ((1 == a[i]) && (a[i + 1] == 0)) {
						index1 = i;
						fl1 = 1;
						continue;
					}
				}
			}
			if (n > 2) {
				for (int i = n - 1; i >= 0; i = i - 1) {
					if ((1 == a[i]) && (a[i - 1] == 0)) {
						index2 = i;
						fl2 = 1;
						continue;
					}
				}
			}

			if (1 == fl1 && 1 == fl2) {
				std::cout << abs(index2 - index1) << std::endl;
			}
			else {
				std::cout << 0 << std::endl;
			}
		}
	}
	return 0;
}