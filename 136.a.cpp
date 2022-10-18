#include <iostream>
#include <vector>
int main() {
	int n = 0;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::vector<int>a2(n);
	int index = 0;
	for (int i = 0; i < n; i++) {
		index = a[i];
		a2[index - 1] = i + 1;
	}
	for (int i = 0; i < n; i++) {
		std::cout << a2[i] << " ";
	}
}