#include <iostream>
#include <vector>
#include <cmath>
int main() {
	int maxim = 0;
	int i = 1;
	int k = -1;
	std::vector<int> a;
	while (i != 0) {
		std::cin >> i;
		a.push_back(i);
		k += 1;
		if (i > maxim) {
			maxim = i;
		}
	}
	int kol = 0;
	for (int i = 0; i < k; i++) {
		if (a[i] == maxim) {
			kol += 1;
		}
	}
	std::cout << kol;
}