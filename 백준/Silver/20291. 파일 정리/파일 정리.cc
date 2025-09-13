#include <iostream>
#include <map>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::map<std::string, int> m;
	std::string file;
	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> file;

		m[file.substr(file.find('.') + 1)]++;
	}

	for (auto e : m) {
		std::cout << e.first << " " << e.second << "\n";
	}
}