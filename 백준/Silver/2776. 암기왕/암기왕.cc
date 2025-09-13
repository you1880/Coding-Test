#include <iostream>
#include <unordered_set>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T, N, M, n, m;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		std::unordered_set<int> s;
		std::cin >> N;

		for (int j = 0; j < N; j++) {
			std::cin >> n;
			s.insert(n);
		}

		std::cin >> M;
		for (int j = 0; j < M; j++) {
			std::cin >> m;

			if (s.find(m)!=s.end()) {
				std::cout << "1\n";
			}
			else {
				std::cout << "0\n";
			}
		}
	}
}