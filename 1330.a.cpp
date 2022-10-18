#include <iostream>
#include <vector>
int main() {
	int t;
	std::cin >> t;

	while (t--)
	{
		int n, x, v;
		std::cin >> n >> x;
		v = 0;
		std::vector <int> a(250, 0);

		for (int iA = 0; iA < n; iA++) {
			int index = 0;
			std::cin >> index;
			a[index] = 1;
		}
		int FREE = 0;
		while (FREE < x)
		{
			for (int r = 1; r <= 250; r++)
			{
				if (a[r] == 0)
				{
					a[r] = 1;
					FREE += 1;
					break;
				}
			}
		}
		for (int dlinaMax = 1; dlinaMax < 250; dlinaMax++)
		{
			if (a[dlinaMax] == 1)
			{
				v++;
			}
			else {
				break;
			}

		}


		std::cout << v << '\n';
	}

	return 0;
}