#include <iostream>

int arr[301];
int dp[301];

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int N;
	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		std::cin >> arr[i];
	}

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = std::max(arr[1] + arr[3], arr[2] + arr[3]);

	for (int i = 4; i <= N; i++) {
		dp[i] = std::max(dp[i - 3] + arr[i - 1], dp[i - 2]) + arr[i];
	}
	
	std::cout << dp[N];
}