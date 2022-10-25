#include <iostream>
#include <vector>
int main() {
	int n = 0;
	std::cin >> n;
	std::vector <int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (0 == a[i] % 2) {
			std::cout << a[i] << " ";
		}
	}
}
