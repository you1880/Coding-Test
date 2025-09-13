#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001

std::vector<int> vec[MAX];
int table[MAX];
int cost[MAX];
int dp[MAX];

void func(int N, int W) {
	if (table[W] == 0) {
		return;
	}

	int res = 0;
	std::queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (table[i] == 0) {
			q.push(i);
		}
	}

	for (int i = 1; i <= N; i++) {
		int cur = q.front();
		q.pop();

		for (int j = 0; j < vec[cur].size(); j++) {
			int nx = vec[cur][j];
			if (--table[nx] == 0) {
				q.push(nx);
			}
			dp[nx] = std::max(dp[nx], dp[cur] + cost[nx]);
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		int N, K, X, Y, W;
		std::cin >> N >> K;

		for (int i = 1; i <= N; i++) {
			std::cin >> cost[i];
			dp[i] = cost[i];

			table[i] = 0;
			vec[i].clear();
		}

		for (int i = 1; i <= K; i++) {
			std::cin >> X >> Y;
			vec[X].push_back(Y);
			table[Y]++;
		}

		std::cin >> W;
		func(N, W);
		std::cout << dp[W] << "\n";
	}
}