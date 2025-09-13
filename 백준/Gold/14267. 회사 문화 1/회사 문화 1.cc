#include <iostream>
#include <vector>
#define MAX 100001

std::vector<int> vec[MAX];
int dp[MAX];

void dfs(int cur) {
	for (const auto& next : vec[cur]) {
		dp[next] += dp[cur];
		dfs(next);
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);
	
	int n, m, x, w;
	std::cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		std::cin >> x;

		if (x != -1) {
			vec[x].push_back(i);
		}
	}

	for (int i = 0; i < m; i++) {
		std::cin >> x >> w;

		dp[x] += w;
	}

	dfs(1);
	
	for (int i = 1; i <= n; i++) {
		std::cout << dp[i] << " ";
	}
}