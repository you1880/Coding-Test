#include <iostream>
#include <vector>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int K, N;
	std::cin >> K >> N;

	std::vector<long long> vec(K);

	long long low = 1, high = 1, mid = 0, res = 0;

	for (int i = 0; i < K; i++) {
		std::cin >> vec[i];

		high = std::max(high, vec[i]);
	}
	
	while (low <= high) {
		mid = (low + high) / 2;

		long long tmp = 0;
		for (auto& e : vec) {
			tmp += e / mid;
		}

		if (N > tmp) {
			high = mid - 1;
		}
		else {
			low = mid + 1;

			res = std::max(res, mid);
		}
	}

	std::cout << res;
}