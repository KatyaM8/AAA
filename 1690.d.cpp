#include <iostream>
#include <vector>
int main() {
	int t = 0;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		int n = 0;
		int k = 0;
		std::cin >> n >> k;
		std::vector<char>a(n);
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		int max_black_on_k = 0;
		//���������� ������ �� ������� � ���� ������������ ���-�� � �� ������� k
		for (int i = 0; i < n - k + 1; ++i) {
			int black_on_k = 0;
			for (int j = i; j < k + i; ++j) {
				if (a[j] == 'B') {
					black_on_k += 1;
				}
			}
			if (black_on_k > max_black_on_k) {
				max_black_on_k = black_on_k;
				black_on_k = 0;
			}
		}
		//���� �� k ������ ������������ ���-�� �, �� ������� ����������� ���-�� �����,
		//������� ����� ����������� � ������
		std::cout << k - max_black_on_k << std::endl;
	}

}