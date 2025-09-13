#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::vector<int> coins;
	int N, K, c, cnt = 0;
	std::cin >> N >> K;

	for (int i = 0; i < N; i++) {
		std::cin >> c;
		coins.push_back(c);
	}

	for (int i = coins.size() - 1; i >= 0; i--) {
		if (coins[i] > K) {
			continue;
		}

		if (K == 0) {
			break;
		}

		cnt += K / coins[i];
		K %= coins[i];
	}

	std::cout << cnt;
}