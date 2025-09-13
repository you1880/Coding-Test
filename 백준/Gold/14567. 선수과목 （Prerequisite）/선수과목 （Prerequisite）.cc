#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001

int dp[MAX];
int table[MAX];
std::vector<int> graph[MAX];
int N, M;

void topology() {
	std::queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (table[i] == 0) {
			q.push(i);
		}
	}

	for (int i = 1; i <= N; i++) {
		int cur = q.front();
		q.pop();

		for (int j = 0; j < graph[cur].size(); j++) {
			int nx = graph[cur][j];

			if (--table[nx] == 0) {
				q.push(nx);
			}

			dp[nx] = std::max(dp[nx], dp[cur] + 1);
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int A, B;
	std::cin >> N >> M;

	for (int i = 0; i < M; i++) {
		std::cin >> A >> B;

		graph[A].push_back(B);
		table[B]++;
	}

	topology();

	for (int i = 1; i <= N; i++) {
		std::cout << dp[i] + 1 << " ";
	}
}