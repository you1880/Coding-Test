#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int zero = 0, one = 0;
	std::string str, tmp;
	std::cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] != str[i + 1] && str[i] == '0') {
			zero++;
		}
		else if (str[i] != str[i + 1] && str[i] == '1') {
			one++;
		}
	}

	std::cout << std::min(zero, one);
}