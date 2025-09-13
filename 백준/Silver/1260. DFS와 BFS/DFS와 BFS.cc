#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

void DFS(int start, std::vector<std::vector<int>>& graph, std::vector<bool>& visited) {	
	visited[start] = true;
	std::cout << start << " ";

	for (int i = 0; i < graph[start].size(); i++) {
		int y = graph[start][i];
		if (!visited[y]) {
			DFS(y, graph, visited);
		}
	}
}

void BFS(int start, std::vector<std::vector<int>>& graph) {
	std::vector<bool> visited(graph.size(), 0);
	std::queue<int> q;
	q.push(start);

	visited[start] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		std::cout << x << " ";

		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!visited[y]) {
				q.push(y);
				visited[y] = true;
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M, V, a, b;
	std::cin >> N >> M >> V;

	std::vector<std::vector<int>> graph(N + 1);
	std::vector<bool> visited(N + 1, 0);

	for (int i = 0; i < M; i++) {
		std::cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0; i < graph.size(); i++) {
		std::sort(graph[i].begin(), graph[i].end());
	}

	DFS(V, graph, visited);
	std::cout << "\n";
	BFS(V, graph);
}