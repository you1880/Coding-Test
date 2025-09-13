#include <iostream>
#include <vector>
#define MAX 10'001

std::vector<int> tree[MAX];
int dp[MAX][2];
int val[MAX];
bool visited[MAX];
int N;

void dfs(int cur) {
	visited[cur] = true;

	dp[cur][0] = val[cur];
	dp[cur][1] = 0;

	for (const auto& next : tree[cur]) {
		if (visited[next]) {
			continue;
		}

		dfs(next);

		dp[cur][0] += dp[next][1];
		dp[cur][1] += std::max(dp[next][0], dp[next][1]);
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);
	
	int a, b;
	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		std::cin >> val[i];
	}

	for (int i = 0; i < N - 1; i++) {
		std::cin >> a >> b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1);
	std::cout << std::max(dp[1][0], dp[1][1]);
}