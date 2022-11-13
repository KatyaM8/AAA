#include <iostream>
#include <vector>
#include <cmath>
int main() {
	//ñîçäàíèå ìàòðèöû
	//*ñîçäà¸ì âåêòîð âåêòîðîâ
	std::vector<std::vector<int>> m55{
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
	};
	//çàïîëíåíèå ìàòðèöû
	const auto nRow = std::size(m55); //êîë-âî ðÿäîâ(èõ 4) 
	const auto nCol = std::size(m55[0]); //ÊÎË - ÂÎ ÑÒÎËÁÖÎÂ(èõ 6)
	for (int iRow = 0; iRow < nRow; iRow++) {
		for (int iCol = 0; iCol < nCol; iCol++) {
			std::cin >> m55[iRow][iCol];
		}
	}
	//çàïîìèíàåì, â êàêîì ðÿäó è â êàêîé êîëîíêå åäèíè÷êà
	int row1 = 0;
	int col1 = 0;
	for (int iRow = 0; iRow < nRow; iRow++) {
		for (int iCol = 0; iCol < nCol; iCol++) {
			if (m55[iRow][iCol] == 1) {
				row1 = iRow + 1;
				col1 = iCol + 1;
			}
		}
	}
	std::cout << abs(3 - row1) + abs(3 - col1);
}
