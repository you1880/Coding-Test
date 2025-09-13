#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001

std::vector<int> graph[MAX];
int cost[MAX];
int table[MAX];
int dp[MAX];

int N, res = 0;

void topologySort() {
	std::queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (table[i] == 0) {
			q.push(i);
			dp[i] = cost[i];
		}
	}

	for (int i = 1; i <= N; i++) {
		if (q.empty()) {
			return;
		}
		int cur = q.front();
		q.pop();

		for (int j = 0; j < graph[cur].size(); j++) {
			int next = graph[cur][j];
			if (--table[next] == 0) {
				q.push(next);
			}

			dp[next] = std::max(dp[next], dp[cur] + cost[next]);
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		std::cin >> cost[i] >> table[i];

		for (int j = 0; j < table[i]; j++) {
			int t;
			std::cin >> t;

			graph[t].push_back(i);
		}
	}

	topologySort();

	for (int i = 1; i <= N; i++) {
		res = std::max(res, dp[i]);
	}
	std::cout << res;
}