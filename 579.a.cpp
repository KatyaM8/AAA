#include <iostream>
#include <algorithm>
#include <string>
int main() {
	int n = 0;
	std::cin >> n;
	int k = 536870912;
	int kolvo_1 = 0;
	while (k > 0) {
		if ((k & n) == k) {
			kolvo_1 = kolvo_1 + 1;
		}
		k = k >> 1;
	}
	std::cout << kolvo_1;;
}