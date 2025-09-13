#include <iostream>
#include <set>
#include <string>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::string name;
	std::set<std::string> s, h;
	int N, M;
	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		std::cin >> name;
		h.insert(name);
	}

	for (int i = 0; i < M; i++) {
		std::cin >> name;
		if (h.find(name) != h.end()) {
			s.insert(name);
		}
	}
	
	std::cout << s.size() << "\n";
	for (auto& e : s) {
		std::cout << e << "\n";
	}
}