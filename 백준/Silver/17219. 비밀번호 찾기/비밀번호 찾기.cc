#include <iostream>
#include <map>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::map<std::string, std::string> m;
	std::string s, p;
	int N, M;
	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		std::cin >> s >> p;

		m[s] = p;
	}

	for (int i = 0; i < M; i++) {
		std::cin >> s;
		std::cout << m[s] << "\n";
	}
}