#include <iostream>
#include <vector>
#include <queue>
#define MAX 501

std::vector<int> graph[MAX];
int table[MAX];
int times[MAX];
int dp[MAX];
int N;

void topologySort() {
	std::queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (table[i] == 0) {
			q.push(i);
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
			dp[next] = std::max(dp[next], dp[cur] + times[next]);
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		std::cin >> times[i];
		dp[i] = times[i];

		while (true) {
			int x;
			std::cin >> x;

			if (x == -1) {
				break;
			}

			graph[x].push_back(i);
			table[i]++;
		}
	}

	topologySort();

	for (int i = 1; i <= N; i++) {
		std::cout << dp[i] << "\n";
	}
}