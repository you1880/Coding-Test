#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::vector<int> vec;
	long long sum = 0;
	int K, N;
	std::cin >> K;
	
	for (int i = 0; i < K; i++) {
		std::cin >> N;
		if (N) {
			vec.push_back(N);
		}
		else {
			vec.pop_back();
		}
	}

	for (auto e : vec) {
		sum += e;
	}
	std::cout << sum;
}