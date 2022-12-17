#include <iostream>
#include <string>

int main() {
	int t;
	std::cin >> t;
	for (t; t > 0; t -= 1) {
		std::string str;
		int a, b, test1(0);
		std::cin >> a >> b >> str;
		for (int i = 0; i < a + b; i += 1) {
			if (str[i] == '?')
				test1 += 1;
		}
		int count_a = a;
		int count_b = b;
		for (int i = 0; i < (a + b); i += 1) {
			if (str[i] == '0')
				count_a -= 1;
			else if (str[i] == '1')
				count_b -= 1;
		}
		for (int i = 0; i < (a + b) / 2; i += 1) {
			if (str[i] == '?' && str[str.size() - i - 1] == '0') {
				str[i] = '0';
				count_a -= 1;
			}
			else if (str[str.size() - i - 1] == '?' && str[i] == '0') {
				str[str.size() - i - 1] = '0';
				count_a -= 1;
			}
			else if (str[i] == '?' && str[str.size() - i - 1] == '1') {
				str[i] = '1';
				count_b -= 1;
			}
			else if (str[str.size() - i - 1] == '?' && str[i] == '1') {
				str[str.size() - i - 1] = '1';
				count_b -= 1;
			}
		}
		for (int i = 0; count_a > 0 || count_b > 0; i += 1) {
			if ((a + b) % 2 == 0) {
				if (str[i] == '?' && count_a > 0) {
					str[i] = '0';
					str[str.size() - i - 1] = '0';
					count_a -= 2;
				}
				else if (str[i] == '?' && count_b > 0) {
					str[i] = '1';
					str[str.size() - i - 1] = '1';
					count_b -= 2;
				}
			}
			else {
				//                  std::cout << str << " " << count_a << " " << count_b << std::endl;
				if (str[(a + b) / 2] == '?') {
					if (a % 2 != 0) {
						str[(a + b) / 2] = '0';
						count_a -= 1;
					}
					else {
						str[(a + b) / 2] = '1';
						count_b -= 1;
					}
				}
				else if (str[i] == '?' && count_a > 0) {
					str[i] = '0';
					str[str.size() - i - 1] = '0';
					count_a -= 2;
				}
				else if (str[i] == '?' && count_b > 0) {
					str[i] = '1';
					str[str.size() - i - 1] = '1';
					count_b -= 2;
				}
			}
		}
		if (test1 == 0)
			std::cout << -1 << std::endl;
		else if (str.size() == 1)
			std::cout << str << std::endl;
		else if (count_a == 0 && count_b == 0)
			std::cout << str << std::endl;
		else
			std::cout << -1 << std::endl;
		//        std::cout << str << " " << count_a << " " << count_b << std::endl;
		str = "";
	}
}