#include <iostream>
#include <vector>
#define MAX 1'000'001

int N;
std::vector<int> vec[MAX];
int dp[MAX][2];
bool visited[MAX];

void dfs(int node) {
	if (visited[node]) {
		return;
	}

	visited[node] = true;
	dp[node][0] = 1;

	for (const auto& next : vec[node]) {
		if (!visited[next]) {
			dfs(next);

			dp[node][0] += std::min(dp[next][0], dp[next][1]);
			dp[node][1] += dp[next][0];
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int u, v;
	std::cin >> N;

	for (int i = 0; i < N - 1; i++) {
		std::cin >> u >> v;

		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	dfs(1);
	
	std::cout << std::min(dp[1][0], dp[1][1]);
}