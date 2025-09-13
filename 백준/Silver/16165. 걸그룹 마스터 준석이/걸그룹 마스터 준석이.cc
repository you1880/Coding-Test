#include <iostream>
#include <map>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	std::map<std::string, std::string> m;
	int N, M, n;
	std::string team, name;
	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		std::cin >> team >> n;
		for (int j = 0; j < n; j++) {
			std::cin >> name;
			m.insert({ name, team });
		}
	}

	for (int i = 0; i < M; i++) {
		std::cin >> name >> n;
		if (n) {
			std::cout << m[name] << "\n";
		}
		else {
			for (auto& itr : m) {
				if (itr.second == name) {
					std::cout << itr.first << "\n";
				}
			}
		}
	}
}