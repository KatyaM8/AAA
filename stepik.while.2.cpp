#include <iostream>
#include <vector>
int main() {
	int n;
	std::cin >> n;
	int i = 2;
	while (i <= n) {
		if (n%i == 0) {
			std::cout << i;
			break;
		}
		i += 1;
	}
}