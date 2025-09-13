#include <iostream>
#include <unordered_set>
#include <sstream>

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	std::unordered_set<std::string> os;
	std::string line, tmp;
	int N, M;
	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		std::cin >> line;
		os.insert(line);
	}

	for (int i = 0; i < M; i++) {
		std::cin >> line;
		std::istringstream ss(line);

		while (std::getline(ss, tmp, ',')) {
			auto itr = os.find(tmp);

			if (itr != os.end()) {
				os.erase(itr);
			}
		}

		std::cout << os.size() << "\n";
	}
}