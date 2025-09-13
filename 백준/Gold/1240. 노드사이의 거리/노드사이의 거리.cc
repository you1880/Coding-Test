#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 1001

std::vector<std::pair<int, int>> graph[MAX];
int visited[MAX];
int N, M, start, target;

int bfs(int start) {
	std::queue<std::pair<int, int>> q;

	visited[start] = 1;
	q.push({ start, 0 });
	
	while (!q.empty()) {
		int x = q.front().first;
		int c = q.front().second;
		q.pop();

		if (x == target) {
			return c;
		}

		for (int i = 0; i < graph[x].size(); i++) {
			if (!visited[graph[x][i].first]) {
				visited[graph[x][i].first] = 1;
				q.push({ graph[x][i].first, c + graph[x][i].second });
			}
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int f, t, c;
	std::cin >> N >> M;

	for (int i = 0; i < N - 1; i++) {
		std::cin >> f >> t >> c;

		graph[f].push_back({ t, c });
		graph[t].push_back({ f,c });
	}

	for (int i = 0; i < M; i++) {
		std::cin >> start >> target;
		std::cout << bfs(start) << "\n";

		memset(visited, 0, sizeof(visited));
	}
}