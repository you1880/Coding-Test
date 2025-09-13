#include <iostream>
#include <vector>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int N, max = 0;
	std::cin >> N;

	std::vector<int> vec(N), dp(N, 1);

	for (int i = 0; i < N; i++) {
		std::cin >> vec[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (vec[j] > vec[i] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}

		max = dp[i] > max ? dp[i] : max;
	}

	std::cout << N - max;
}