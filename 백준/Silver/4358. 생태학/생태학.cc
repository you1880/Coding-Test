#include <iostream>
#include <map>
#include <string>

int main() {
	std::map<std::string, int> m;
	int cnt = 0;
	std::string str;

	while (1) {
		std::getline(std::cin, str);

		if (std::cin.eof() == true) {
			break;
		}
		cnt++;
		m[str]++;
	}

	for (auto e : m) {
		std::cout << e.first << " ";
		std::cout << std::fixed;
		std::cout.precision(4);
		std::cout << e.second / static_cast<double>(cnt) * 100.0 << "\n";
	}
}