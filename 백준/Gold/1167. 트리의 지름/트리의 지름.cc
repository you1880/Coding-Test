#include <iostream>
#include <vector>
#define MAX 100001

int V, cost = 0, x;
std::vector<std::pair<int, int>> vec[MAX];

void dfs(int start, int weight, std::vector<bool>& visited) {
	visited[start] = true;

	if (cost < weight) {
		cost = weight;
		x = start;
	}

	for (int i = 0; i < vec[start].size(); i++) {
		int nx = vec[start][i].first;
		if (!visited[nx]) {
			dfs(nx, weight + vec[start][i].second, visited);
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> V;
	for (int i = 0; i < V; i++) {
		int v, nx, w;
		std::cin >> v;

		while (1) {
			std::cin >> nx;

			if (nx == -1) {
				break;
			}

			std::cin >> w;
			vec[v].push_back({ nx, w });
		}
	}

	std::vector<bool> visited(V + 1, false);
	dfs(1, 0, visited);

	visited.assign(V + 1, false);
	dfs(x, 0, visited);
	std::cout << cost;
}