#include <iostream>
#include <string>
int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	int count = 0;
	std::string str, srch;
	std::getline(std::cin, str);
	std::getline(std::cin, srch);

	while (1) {
		auto idx = str.find(srch);

		if (idx == std::string::npos) {
			std::cout << count;
			return 0;
		}

		count++;
		str = str.substr(idx + srch.length());
	}
}