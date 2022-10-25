#include <iostream>
#include <vector>
#include <cmath>
int main() {
	int n;
	std::cin >> n;
	int i = 0;
	while (pow(2, i) <= n) {
		std::cout << pow(2, i) << " ";
		i++;
	}
}