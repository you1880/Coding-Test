#include <iostream>
#include <vector>
#include <queue>
#define MAX 20001
#define INF 1e9

std::vector<std::pair<int, int>> graph[MAX];
int d[MAX];

void dijkstra(int start) {
	std::priority_queue<std::pair<int, int>> pq;

	pq.push({ 0, start });
	d[start] = 0;

	while (!pq.empty()) {
		int dist = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist > d[cur]) {
			continue;
		}

		for (auto& edge : graph[cur]) {
			int adj = edge.first;
			int weight = edge.second;
			int new_weight = dist + weight;

			if (d[adj] > new_weight) {
				d[adj] = new_weight;
				pq.push({ -new_weight, adj });
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int V, E, start;
	int u, v, w;

	std::cin >> V >> E >> start;

	for (int i = 1; i <= V; i++) {
		d[i] = INF;
	}

	for (int i = 0; i < E; i++) {
		std::cin >> u >> v >> w;

		graph[u].push_back({ v,w });
	}

	dijkstra(start);

	for (int i = 1; i <= V; i++) {
		if (d[i] == INF) {
			std::cout << "INF\n";
		}
		else {
			std::cout << d[i] << "\n";
		}
	}
}