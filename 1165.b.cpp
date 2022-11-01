#include <iostream>
#include <vector>
#include <algorithm>
int main() {
	int n = 0;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::sort(std::begin(a), std::end(a));
	int k = 1;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] >= k) {
			ans += 1;
			k += 1;
		}
	}
	std::cout << ans;
}