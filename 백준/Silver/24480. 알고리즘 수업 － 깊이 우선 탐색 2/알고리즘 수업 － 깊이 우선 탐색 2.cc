#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001

int N, M, R;
int visited[MAX] = { 0, };
int idx = 0;

void dfs(int start, std::vector<std::vector<int>>& graph) {
	visited[start] = ++idx;

	for (int i = 0; i < graph[start].size(); i++) {
		int y = graph[start][i];

		if (!visited[y]) {
			dfs(y, graph);
		}
	}
}

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	int a, b;
	std::cin >> N >> M >> R;

	std::vector<std::vector<int>> graph(N + 1);
	for (int i = 0; i < M; i++) {
		std::cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		std::sort(graph[i].begin(), graph[i].end(), std::greater<int>());
	}

	dfs(R, graph);

	for (int i = 1; i <= N; i++) {
		std::cout << visited[i] << "\n";
	}
}