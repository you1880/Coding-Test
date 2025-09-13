#include <iostream>
#include <vector>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int n, max = 0;
	std::cin >> n;
	std::vector<int> box(n), dp(n, 1);

	for (int i = 0; i < n; i++) {
		std::cin >> box[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (box[j] < box[i] && dp[j] + 1 > dp[i]) {
				dp[i] = 1 + dp[j];
			}
		}

		max = dp[i] > max ? dp[i] : max;
	}

	std::cout << max;
}