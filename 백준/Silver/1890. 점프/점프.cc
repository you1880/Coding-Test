#include <iostream>
#include <vector>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int N;
	std::cin >> N;

	std::vector<std::vector<int>> vec(N, std::vector<int>(N, 0));
	std::vector<std::vector<long long>> dp(N, std::vector<long long>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> vec[i][j];
		}
	}

	dp[0][0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dp[i][j] == 0 || (i == N - 1 && j == N - 1)) {
				continue;
			}

			if (i + vec[i][j] < N) {
				dp[i + vec[i][j]][j] = dp[i + vec[i][j]][j] + dp[i][j];
			}

			if (j + vec[i][j] < N) {
				dp[i][j + vec[i][j]] = dp[i][j + vec[i][j]] + dp[i][j];
			}
		}
	}
	
	std::cout << dp[N - 1][N - 1];
}