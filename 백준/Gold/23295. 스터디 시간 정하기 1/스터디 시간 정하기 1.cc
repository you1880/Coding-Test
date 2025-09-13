#include <iostream>
#define MAX 100001

int diff[MAX];

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int N, T, K, S, E;
	std::cin >> N >> T;

	for (int i = 0; i < N; i++) {
		std::cin >> K;

		for (int j = 0; j < K; j++) {
			std::cin >> S >> E;

			diff[++S]++;
			diff[E + 1]--;
		}
	}

	for (int i = 1; i < MAX; i++) {
		diff[i] += diff[i - 1];
	}

	std::pair<int, int> res = { 0, T };
	int sum = 0, max = 0;

	for (int i = 1; i <= T; i++) {
		sum += diff[i];
	}

	max = sum;

	for (int i = T + 1; i < MAX; i++) {
		sum += (diff[i] - diff[i - T]);

		if (sum > max) {
			res = { i - T, i };
			max = sum;
		}
	}

	std::cout << res.first << " " << res.second;
}