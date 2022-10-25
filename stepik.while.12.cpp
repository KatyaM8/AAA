#include <iostream>
#include <vector>
int main() {
	int i = 1;
	std::vector<int> a;
	int k = 0;
	while (i != 0) {
		std::cin >> i;
		if (i != 0) {
			a.push_back(i);
			k += 1;
		}
	}
	a.push_back(0);
	k += 1;
	int kol = 1;
	int maxim = 0;
	for (int i = 0; i < k - 1; i++) {
		if (a[i] == a[i + 1]) {
			kol += 1;
			if (kol > maxim) {
				maxim = kol;
			}
		}
		else {
			if (kol > maxim) {
				maxim = kol;
			}
			kol = 1;
		}
		if (kol > maxim) {
			maxim = kol;
		}
	}
	std::cout << maxim;
}