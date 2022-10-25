#include <iostream>
#include <vector>
int main() {
	int n = 0;
	std::cin >> n;
	std::vector <int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::cout << a[n - 1] << " ";
	for (int i = 0; i < n - 1; i++) {
		std::cout << a[i] << " ";
	}
}


