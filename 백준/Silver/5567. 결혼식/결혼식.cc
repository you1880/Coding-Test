#include <iostream>
#include <vector>
#include <queue>

int n, m;

int BFS(int start, std::vector<std::vector<int>>& graph) {
	std::vector<bool> visited(n + 1, 0);
	std::vector<int> rank(n + 1, 0);
	std::queue<int> q;
	int cnt = 0;
	q.push(start);

	visited[start] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];

			if (!visited[y]) {
				q.push(y);
				visited[y] = true;
				rank[y] = rank[x] + 1;
				
				if (rank[y] <= 2) {
					cnt++;
				}
			}
		}
	}

	return cnt;
}

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	int a, b;
	std::cin >> n >> m;
	std::vector<std::vector<int>> graph(n + 1);

	for (int i = 0; i < m; i++) {
		std::cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	std::cout << BFS(1, graph);
}