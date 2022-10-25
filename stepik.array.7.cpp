#include <iostream>
#include <vector>
int main() {
	int n = 0;
	std::cin >> n;
	std::vector <int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	long long mink = 0;
	mink = 1000000000000000000;
	for (int y = 0; y < n; y++) {
		if ((a[y]) % 2 != 0) {
			if (a[y] < mink) {
				mink = a[y];
			}
		}
	}
	if (mink != 1000000000000000000) {
		std::cout << mink;
	}
	else {
		std::cout << 0;
	}
}

