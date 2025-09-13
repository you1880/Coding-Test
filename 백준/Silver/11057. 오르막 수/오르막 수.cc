#include <iostream>
#include <vector>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int N;
	std::cin >> N;

	std::vector<std::vector<int>> dp(N + 1, std::vector<int>(11, 1));
	dp[1][10] = 10;

	for (int i = 2; i <= N; i++) {
		long long sum = dp[i][0];

		for (int j = 1; j < 10; j++) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 10007;
			sum = (sum + dp[i][j]) % 10007;
		}
		dp[i][10] = sum;
	}
	std::cout << dp[N][10];
}