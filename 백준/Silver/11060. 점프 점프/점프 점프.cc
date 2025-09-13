#include <iostream>
#include <vector>
#define INF 1e9

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int N;
	std::cin >> N;

	std::vector<int> vec(N), dp(N, INF);
	dp[0] = 0;

	for (int i = 0; i < N; i++) {
		std::cin >> vec[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= vec[i] && i + j < N; j++) {
			dp[i + j] = std::min(dp[i] + 1, dp[i + j]);
		}
	}

	if (dp[N - 1] == INF) {
		std::cout << -1;
	}
	else {
		std::cout << dp[N - 1];
	}
}