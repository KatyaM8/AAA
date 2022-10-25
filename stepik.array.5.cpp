#include <iostream>
#include <vector>
int main() {
	int n = 0;
	std::cin >> n;
	std::vector <int> a(n);
	for (int i = 0; i <= n; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n - 1; i++) {
		if ((a[i] > 0 & a[i + 1] > 0) || (a[i] < 0 & a[i + 1] < 0)) {
			if (a[i] > a[i + 1]) {
				std::cout << a[i + 1] << " " << a[i];
			}
			else {
				std::cout << a[i] << " " << a[i + 1];
			}
			break;
		}
	}
	return 0;
}



