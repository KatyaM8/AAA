#include <iostream>
#include <vector>
int main() {
	int n = 0;
	std::cin >> n;
	std::vector <int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			k = k + 1;
		}
	}
	std::cout << k;
}

