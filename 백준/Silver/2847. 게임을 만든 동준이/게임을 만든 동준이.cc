#include <iostream>
#include <vector>

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	int N, cnt = 0;
	std::cin >> N;

	std::vector<int> vec(N);
	for (int i = 0; i < N; i++) {
		std::cin >> vec[i];
	}

	if (N == 1) {
		std::cout << vec[0];
		return 0;
	}
	for (int i = N - 2; i >= 0; i--) {
		if (vec[i] >= vec[i + 1]) {
			cnt += vec[i] - (vec[i + 1] - 1);
			vec[i] = vec[i + 1] - 1;
		}
	}

	std::cout << cnt;
}