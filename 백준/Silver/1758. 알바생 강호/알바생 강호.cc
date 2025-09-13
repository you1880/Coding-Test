#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	long long tip = 0;
	int N;
	std::cin >> N;

	std::vector<int> vec(N);
	for (int i = 0; i < N; i++) {
		std::cin >> vec[i];
	}

	std::sort(vec.begin(), vec.end(), std::greater<int>());

	for (int i = 0; i < N; i++) {
		int t = (vec[i] - i) > 0 ? (vec[i] - i) : 0;
		tip += t;
	}

	std::cout << tip;
}