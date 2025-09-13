#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	int N, sum = 0;
	std::cin >> N;

	std::vector<int> C(N);
	for (int i = 0; i < N; i++) {
		std::cin >> C[i];
	}

	std::sort(C.begin(), C.end(), std::greater<int>());

	for (int i = 0; i < N; i++) {
		if (i % 3 == 2) {
			continue;
		}
		sum += C[i];
	}

	std::cout << sum;
}