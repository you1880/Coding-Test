#include <iostream>
#include <set>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int N, M, num;
	std::cin >> N;

	std::set<long long> nums;
	for (int i = 0; i < N; i++) {
		std::cin >> num;
		nums.insert(num);
	}

	std::cin >> M;
	for (int i = 0; i < M; i++) {
		std::cin >> num;
		if (nums.find(num) != nums.end())
			std::cout << "1\n";
		else
			std::cout << "0\n";
	}
}