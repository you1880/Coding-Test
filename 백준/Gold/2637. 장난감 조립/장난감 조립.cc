#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 101

std::vector<std::pair<int, int>> graph[MAX];
int parts[MAX][MAX];
int table[MAX];
int N, M, X, Y, K;

void topologySort() {
	std::queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (table[i] == 0) {
			q.push(i);
			parts[i][i] = 1;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (q.empty()) {
			return;
		}

		int cur = q.front();
		q.pop();

		for (const std::pair<int, int>& p : graph[cur]) {
			int next = p.first;
			if (--table[next] == 0) {
				q.push(next);
			}

			for (int k = 1; k <= N; k++) {
				parts[k][next] += p.second * parts[k][cur];	
			}
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int X, Y, K;
		std::cin >> X >> Y >> K;

		graph[Y].push_back({ X, K });
		table[X]++;
	}

	topologySort();

	for (int i = 1; i <= N; i++) {
		if (parts[i][N]) {
			std::cout << i << " " << parts[i][N] << "\n";
		}
	}
}