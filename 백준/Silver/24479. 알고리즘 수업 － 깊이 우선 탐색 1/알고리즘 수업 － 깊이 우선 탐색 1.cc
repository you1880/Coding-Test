#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001

int visited[MAX] = { 0 };
int idx = 1;

void dfs(std::vector<std::vector<int>>& graph, int x) {
	visited[x] = idx++;

	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visited[y]) {
			dfs(graph, y);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int N, M, R, a, b;
	std::cin >> N >> M >> R;
	std::vector<std::vector<int>> vec(N + 1);

	for (int i = 0; i < M; i++) {
		std::cin >> a >> b;

		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	
	for (int i = 1; i < vec.size(); i++) {
		std::sort(vec[i].begin(), vec[i].end());
	}
	dfs(vec, R);

	for (int i = 1; i <= N; i++) {
		std::cout << visited[i] << "\n";
	}
}