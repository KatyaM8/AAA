#include <iostream>
#include <vector>
int main() {
	int n = 0;
	int k = 0;
	std::cin >> n >> k;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	// Ñîðòèðîâêà ìàññèâà ïóçûðüêîì
	int temp = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				// ìåíÿåì ýëåìåíòû ìåñòàìè
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = n - 1; i >= 0; i = i - 1) {
		if (k % a[i] == 0) {
			std::cout << k / a[i];
			break;
		}
	}
}
