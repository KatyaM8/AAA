#include <iostream>
#include <string>
#include <vector>

int main()
{
	int n = 0;
	std::cin >> n;
	std::string slovo;
	std::cin >> slovo;


	std::vector <int> dlyX(n, 0);
	int c = 1;
	for (int i = 0; i < n; i++)
	{
		if (slovo[i] == 'x' && slovo[i + 1] == 'x')
		{
			c += 1;

		}
		else {
			dlyX.push_back(c);
			c = 1;
		}

	}

	int ans = 0;
	for (int i = 0; i < dlyX.size(); i++)
	{
		if (dlyX[i] != 0 && dlyX[i] != 1)
		{
			ans += dlyX[i] - 2;
		}
	}


	std::cout << ans;

	return 0;
}
