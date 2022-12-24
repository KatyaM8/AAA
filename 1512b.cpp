#include <iostream>
#include <array>

std::array<std::array<std::string, 401>, 401> res{};
std::array<int, 401> indexes{};

int main() {
	int e;
	std::cin >> e;
	for (int i = 0; i < e; i++) {
		int a;
		std::cin >> a;
		int r1, r2;
		int c1, c2;
		bool flag1 = false;
		std::string s;
		for (int j = 0; j < a; j++) {
			std::cin >> s;
			for (int k = 0; k < a; k++) {
				if (s[k] == '*' && !flag1) {
					r1 = j;
					c1 = k;
					flag1 = true;
				}
				else if (s[k] == '*') {
					r2 = j;
					c2 = k;
				}
			}
		}
		int newR1, newR2;
		int newC1, newC2;
		if (r1 != r2 && c1 != c2) {
			newR1 = r1;
			newC1 = c2;

			newR2 = r2;
			newC2 = c1;
		}
		else {
			if (r1 == r2) {
				if (r1 == 0) {
					newR1 = newR2 = r1 + 1;
				}
				else {
					newR1 = newR2 = r1 - 1;
				}
				newC1 = c1;
				newC2 = c2;
			}
			else if (c1 == c2) {
				if (c1 == 0) {
					newC1 = newC2 = c1 + 1;
				}
				else {
					newC1 = newC2 = c1 - 1;
				}
				newR1 = r1;
				newR2 = r2;
			}
		}

		for (int j = 0; j < a; j++) {
			res[i][j] = "";
			for (int k = 0; k < a; k++) {
				res[i][j] += ".";
			}
		}
		res[i][r1][c1] = '*';
		res[i][r2][c2] = '*';
		res[i][newR1][newC1] = '*';
		res[i][newR2][newC2] = '*';
		indexes[i] = a;
	}

	for (int i = 0; i < e; i++) {
		for (int j = 0; j < indexes[i]; j++) {
			for (int k = 0; k < indexes[i]; k++) {
				std::cout << res[i][j][k];
			}
			std::cout << "\n";
		}
	}
}
