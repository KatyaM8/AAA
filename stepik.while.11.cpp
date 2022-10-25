#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
int main() {
	int maxim = 0;
	int i = 1;
	int k = -1;
	std::vector<int> a;
	while (i != 0) {
		std::cin >> i;
		a.push_back(i);
		k += 1;
		if (i > maxim) {
			maxim = i;
		}
	}
	int kol = 0;
	std::sort(a.begin(), a.end());
	std::reverse(a.begin(), a.end());
	std::cout << a[1];
}