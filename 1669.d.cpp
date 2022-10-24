#include <iostream>
#include <vector>
#include <string>
int main() {
	int t = 0;
	std::cin >> t;
	for (int i = 0; i < t; i += 1) {
		int n = 0;
		std::string s;
		std::cin >> n;
		std::cin >> s;
		std::string a;
		a = 'K' + s + 'K';
		int bt = 0;
		int rt = 0;
		int fl2 = 1;
		int fl3 = 1;
		int otvet = 3;
		for (int i = 1; i < n-1; i += 1) {
			if (a[i] == 'B' && a[i + 1] != 'R' && a[i - 1] != 'R' && fl2 != 3 ) {
				fl2 = 1;
			}
			else if (a[i] == 'B' && (a[i + 1] == 'R' || a[i - 1] == 'R')) {
				fl2 = 3;
			}
			if (a[i] == 'W' && fl2 == 1) {
				std::cout << "no";
				otvet = 4;
			}

		}
		for (int i = 1; i < n-1; i += 1) {
			if (a[i] == 'R' && a[i + 1] != 'B' && a[i - 1] != 'B' && fl3 != 3) {
				fl3 = 1;
			}
			else if (a[i] == 'R' && (a[i + 1] == 'B' || a[i - 1] == 'B')) {
				fl3 = 3;
			}
			if ((a[i] == 'W' && fl3 == 1) && (otvet == 3)) {
				std::cout << "no";
				otvet = 4;
			}

		}
		if (otvet == 3) {
			std::cout << "yes";
		}
	}
	
}