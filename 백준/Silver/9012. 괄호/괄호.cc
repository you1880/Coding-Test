#include <iostream>
#include <vector>
#include <string>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::string str;
	int T, p = 0;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		std::cin >> str;
		std::vector<char> vec;
		p = 0;

		for (char c : str) {
			if (c == '(')
				vec.push_back('(');
			else if(c == ')' && vec.empty()) {
				p = 1;
				break;
			}
			else {
				vec.pop_back();
			}
		}

		if (!p && vec.empty()) {
			std::cout <<"YES\n";
		}
		else {
			std::cout <<"NO\n";
		}
	}
}
