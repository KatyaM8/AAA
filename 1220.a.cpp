#include <iostream>
#include <string>
#include <vector>

int main() {
	int t = 0;
	std::cin >> t;
	std::string slovo;
	std::cin >> slovo;

	// z -0 e - 1 r-2 o-3 n-4
	std::vector <int> alf(5);
	for (int i = 0; i <= t; i++) {
		if (slovo[i] == 'z')
		{
			alf[0] += 1;
		}
		if (slovo[i] == 'e')
		{
			alf[1] += 1;
		}
		if (slovo[i] == 'r')
		{
			alf[2] += 1;
		}
		if (slovo[i] == 'o')
		{
			alf[3] += 1;
		}
		if (slovo[i] == 'n')
		{
			alf[4] += 1;
		}
	}
	std::cout << '\n';
	while (alf[3] > 0 && alf[4] > 0 && alf[1] > 0) {
		alf[3] -= 1;
		alf[4] -= 1;
		alf[1] -= 1;
		std::cout << '1' << ' ';
	}
	while (alf[0] > 0 && alf[1] > 0 && alf[2] > 0 && alf[3] > 0)
	{
		alf[0] -= 1;
		alf[1] -= 1;
		alf[2] -= 1;
		alf[3] -= 1;
		std::cout << '0' << ' ';
	}
}
