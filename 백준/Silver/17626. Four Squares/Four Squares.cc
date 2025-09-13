#include <iostream>
int dp[50001];

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int n;
	std::cin >> n;

	for (int i = 1; i <= 223; i++) {
		dp[i * i] = 1;
	}

	dp[2] = 2, dp[3] = 3;

	if (dp[n] == 1) {
		std::cout << "1";

		return 0;
	}

	for (int i = 5; i <= n; i++) {
		int tmp = 100000;

		for (int j = 1; j * j <= i; j++) {
			tmp = std::min(tmp, dp[i - j * j]);
		}
		dp[i] = tmp + 1;
	}

	std::cout << dp[n];
}