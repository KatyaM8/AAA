#include <iostream>
#include <vector>
int main() {
	int n = 0;
	std::cin >> n;
	std::vector <int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	if (n % 2 == 0) {
		int r = 0;
		for (int i = 0; i < n; i += 2) {
			r = a[i];
			a[i] = a[i + 1];
			a[i + 1] = r;
		}
	}
	else {
		int m = 0;
		for (int i = 0; i < n - 1; i += 2) {
			m = a[i];
			a[i] = a[i + 1];
			a[i + 1] = m;
		}
	}
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}
}


