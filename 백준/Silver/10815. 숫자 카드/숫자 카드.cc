#include <iostream>
#include <set>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::set<int> set;
	int N, M, num;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> num;
		set.insert(num);
	}

	std::cin >> M;
	for (int i = 0; i < M; i++) {
		std::cin >> num;
		if (set.find(num) != set.end()) {
			std::cout << "1 ";
		}
		else {
			std::cout << "0 ";
		}
	}
}