#include <iostream>
#include <vector>
#include <cmath>
int main() {
	int n = 0;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int kol = 0;
	int index1 = 0;
	int index2 = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			index1 = i;
		}
	}
	for (int i = n; i > 0; i = i = -1) {
		if (a[i] == 1) {
			index2 = i;
		}
	}
	std::cout << abs(index2 - index1);

}