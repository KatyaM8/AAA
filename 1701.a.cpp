#include <iostream>
#include <vector>
int main() {
	int t = 0;
	std::cin >> t;
	for (int i = 0; i < t; i += 1) {
		std::vector<std::vector<int>> m22{
			{0,0},
			{0,0}
		};
		const auto nRow = std::size(m22);
		const auto nCol = std::size(m22[0]);
		for (int iRow = 0; iRow < nRow; iRow += 1) {
			for (int iCol = 0; iCol < nCol; iCol += 1) {
				std::cin >> m22[iRow][iCol];
			}
		}
		int count1 = 0;
		for (int iRow = 0; iRow < nRow; iRow += 1) {
			for (int iCol = 0; iCol < nCol; iCol += 1) {
				if (m22[iRow][iCol] == 1) {
					count1 += 1;
				}
			}
		}
		if (0 == count1) {
			std::cout << 0 << std::endl;
		}
		else if (count1 >= 1 && count1 <= 3) {
			std::cout << 1 << std::endl;
		}
		else if (count1 == 4) {
			std::cout << 2<<std::endl;
		}
	}
}