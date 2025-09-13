#include <iostream>
#include <string>

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	char ucpc[4] = { 'U','C','P','C' };
	int idx = 0;
	std::string str;
	std::getline(std::cin, str);

	for (auto c : str) {
		if (ucpc[idx] == c) {
			idx++;
			if (idx == 4) {
				std::cout << "I love UCPC";
				return 0;
			}
		}
	}
	std::cout << "I hate UCPC";
}