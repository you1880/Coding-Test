#include <iostream>
#include <vector>
#include <queue>

int BFS(int start, std::vector<std::vector<int>>& graph) {
	std::vector<bool> visited(graph.size(), 0);
	std::queue<int> q;
	int cnt = 0;
	q.push(start);

	visited[start] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!visited[y]) {
				q.push(y);
				visited[y] = true;
				cnt++;
			}
		}
	}

	return cnt;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	
	int N, M, a, b;
	std::cin >> N >> M;
	std::vector<std::vector<int>> net(N + 1);

	for (int i = 0; i < M; i++) {
		std::cin >> a >> b;
		net[a].push_back(b);
		net[b].push_back(a);
	}

	std::cout << BFS(1, net);
}