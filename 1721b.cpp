#include <iostream>

void lazer()
{
	int n, m, x, y, d;
	std::cin >> n >> m >> x >> y >> d;
	bool l = false, t = false, r = false, b = false;
	if (x <= d + 1) {
		l = true;
	}
	if (y <= d + 1) {
		t = true;
	}
	if (x + d >= n) {
		r = true;
	}
	if (y + d >= m) {
		b = true;
	}
	if ((b || l) && (t || r)) {
		std::cout << -1 << std::endl;
	}
	else {
		std::cout << n + m - 2 << std::endl;
	}
}

int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++) lazer();
	return 0;
}
