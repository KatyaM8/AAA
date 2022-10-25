#include <iostream>
#include <vector>
int main() {
	int n = 0;
	std::cin >> n;
	std::vector <int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::vector <int> d;
	for (int j = 0; j < n; j++) {
		if (a[j] > 0) {
			d.push_back(a[j]);
		}
	}
	long long minim = 1000000000000000000000;
	for (int y = 0; y < d.size(); y++) {
		if (d[y] < minim) {
			minim = d[y];
		}
	}
	std::cout << minim;
}


