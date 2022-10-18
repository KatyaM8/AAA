#include <iostream>
#include <vector>
int main()
{
	int n, k;
	int ans = 0;
	std::cin >> n >> k;
	std::vector <int> a(n);
	for (int kY = 0; kY < n; kY++)
	{
		std::cin >> a[kY];

	}
	const int WIN = a[k - 1];
	for (int kY = 0; kY < n; kY++)
	{
		if (a[kY] >= WIN && a[kY] != 0)
		{
			ans += 1;
		}
	}
	std::cout << ans;
}
