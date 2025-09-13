#include <iostream>
#include <map>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::map<std::string, int> log;
	std::string title;
	int N, cnt = 0;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> title;
		log[title]++;
	}

	for (auto itr : log) {
		cnt = std::max(cnt, itr.second);
	}

	for (auto itr : log) {
		if (cnt == itr.second) {
			std::cout << itr.first;
			break;
		}
	}
}