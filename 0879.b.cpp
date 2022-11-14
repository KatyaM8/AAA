#include <iostream>
#include <queue>
int main() {
	std::queue<int> q;
	int n = 0;
	long long k = 0;
	std::cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int b = 0;
		std::cin >> b;
		q.push(b);
	}
	int a = 0;
	a = q.front();
	q.pop();
	long long c = 0;
	int b = 0;
	int fl = 0;
	while (c < k) {
		if (q.empty()) {
			std::cout << a;
			fl = 1;
			break;
		}
		b = q.front();
		if (a > b) {
			c += 1;
			q.pop();
		}
		else {
			//c = c;
			std::swap(a, b);
			q.pop();
			c = 0;
		}
	}
	if (0 == fl) {
		std::cout << a;
	}
}