#include <iostream>
#include <vector>
#include <string>
int main() {
	int n = 0;
	std::cin >> n;
	std::vector<char> a(n+2);
	a[0] = '.';
	a[1] = '.';
	int fl = 0;
	int k = 0;
	for (int i = 0; i < n; ++i) {
		if ((a[i] != '.' && a[i + 1] != '.') && (a[i] != a[i+1]) && (a[i+1] != a[i-1])) {
			k += 1;
		}
		else {
			if (k == 2) {
				std::cout << "YES";
				fl = 1;
			}
			k = 0;

		}
		if (k == 2) {
			std::cout << "YES";
			fl = 1;
		}
	}
	if (0 == fl) {
		std::cout << "NO";
	}
}
