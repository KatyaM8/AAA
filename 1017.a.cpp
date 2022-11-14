#include <iostream>
#include <vector>
int main() {
	int n = 0;
	std::cin >> n;
	int d = 4;
	std::vector<int> a(n);
	std::vector<int> asumma(n);
	for (int i = 0; i < n; ++i) {
		int s = 0;
		for (int j = 0; j < d; ++j) {
			std::cin >> a[i];
			s += a[i];
		}
		asumma[i] = s;
	}
	int Tomas = 0;
	Tomas = asumma[0];
	int k = 1;
	for (int i = 1; i < n; ++i) {
		if (Tomas < asumma[i]) {
			k += 1;
		}
	}
	std::cout << k;
}