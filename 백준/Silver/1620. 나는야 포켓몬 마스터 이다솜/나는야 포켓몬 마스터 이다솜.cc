#include <iostream>
#include <map>
#include <string>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M;
	std::string name, input;
	std::map<std::string, int> dicName;
	std::map<int, std::string> dicNum;
	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		std::cin >> name;
		dicName.insert({ name, i + 1 });
		dicNum.insert({ i + 1, name });
	}

	for (int i = 0; i < M; i++) {
		std::cin >> input;
		if (std::atoi(input.c_str()) != 0) {
			auto itr = dicNum.find(std::stoi(input));
			std::cout << itr->second << "\n";
		}
		else {
			auto itr = dicName.find(input);
			std::cout << itr->second << "\n";
		}
	}
}