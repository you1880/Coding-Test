#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::pair<int, int>> vec[10001];
std::vector<int> dp(10001, 10000001);

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	int N, D, s, d, w;
	std::cin >> N >> D;

	for (int i = 0; i < N; i++) {
		std::cin >> s >> d >> w;

		if (d > D || (d - s) < w) {
			continue;
		}

		vec[d].push_back({ s,w });
	}

	dp[0] = 0;

	for (int i = 1; i <= D; i++) {
		if (vec[i].empty()) {
			dp[i] = dp[i - 1] + 1;
		}
		else {
			for (int j = 0; j < vec[i].size(); j++) {
				dp[i] = std::min(dp[i], std::min(dp[i - 1] + 1, dp[vec[i][j].first] + vec[i][j].second));
			}
		}
	}
	std::cout << dp[D];
}