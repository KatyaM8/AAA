#include <iostream>
#include <vector>
int main() {
	int n = 0;
	std::cin>> n;
	std::vector<int> contine(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> contine[i];
	}
	int maxim = 0;
	for (int i = 0; i < n; ++i) {
		if (contine[i] > maxim) {
			maxim = contine[i];
		}
	}
	std::vector<int> indexi(maxim + 1, -1);
	for (int i = 0; i < n; ++i) {
		if (i > indexi[contine[i]]) {
			indexi[contine[i]] = i;
		}
	}
	int minim = 10 * 10 * 10 * 10 * 10 * 10;
	for (int i = 0; i < maxim + 1; ++i) {
		if (not(indexi[i] == -1) && (indexi[i] < minim)) {
			minim = indexi[i];
		}
	}
	std::cout << contine[minim];
}