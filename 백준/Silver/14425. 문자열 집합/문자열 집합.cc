#include <iostream>
#include <set>

int main() {
	std::set<std::string> tmp;
	std::string str;
	int N, M, answer = 0;
	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		std::cin >> str;
		tmp.insert(str);
	}

	for (int i = 0; i < M; i++) {
		std::cin >> str;
		if (tmp.find(str) != tmp.end())
			answer++;
	}
	std::cout << answer;
}