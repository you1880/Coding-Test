#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);
	
	int N, M, res = 0;
	std::cin >> N;

	std::vector<int> vec(N);
	for (int i = 0; i < N; i++) {
		std::cin >> vec[i];
	}
	
	std::cin >> M;
	std::sort(vec.begin(), vec.end());

	int s = 0, e = vec[N - 1];

	while (s <= e) {
		int sum = 0;
		int m = (s + e) / 2;

		for (int i = 0; i < N; i++) {
			sum += std::min(m, vec[i]);
		}

		if (sum > M) {
			e = m - 1;
		}
		else {
			res = m;
			s = m + 1;
		}
	}

	std::cout << res;
}