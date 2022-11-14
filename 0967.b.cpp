#include <iostream>
#include <vector>
#include <algorithm>
int main() {
	int n = 0;
	int A = 0;
	int B = 0;
	std::cin >> n >> A >> B;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::vector<int> anew(n - 1);
	for (int i = 0; i < n-1; ++i) {
		anew[i] = a[i + 1];
	}
	std::sort(anew.begin(), anew.end(), std::greater<int>());
	int kolvo_zakrytyh = 0;
	int S = 0;
	for (int i = 0; i < n; ++i) {
		S += a[i];
	}
	int i = 0;
	while ((a[0] * A / S) < B) {
		S = S - anew[i];
		i += 1;
		kolvo_zakrytyh += 1;
	}
	std::cout << kolvo_zakrytyh;
}