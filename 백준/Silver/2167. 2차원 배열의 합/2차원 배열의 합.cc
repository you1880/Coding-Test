#include <iostream>

int arr[301][301];
int dp[301][301];

int main() {
	std::cin.tie(0)->sync_with_stdio(false);
	
	int N, M;
	std::cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			std::cin >> arr[i][j];

			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
		}
	}

	int K, x1, y1, x2, y2;
	std::cin >> K;

	for (int i = 0; i < K; i++) {
		std::cin >> x1 >> y1 >> x2 >> y2;

		int res = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
		std::cout << res << "\n";
	}
}