#include <iostream>
#include <vector>
#include <queue>
#define MAX 5001

const int INF = 1e9;
std::vector<std::pair<int, int>> graph[MAX];

int V, E, P;

int dijkstra(int start, int dest) {
	std::priority_queue<std::pair<int, int>> pq;
	std::vector<int> dist(MAX, INF);

	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int curDist = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (const auto& e : graph[cur]) {
			int adj = e.first;
			int newCost = e.second + curDist;

			if (dist[adj] > newCost) {
				dist[adj] = newCost;
				pq.push({ -newCost, adj });
			}
		}
	}

	return dist[dest];
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> V >> E >> P;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;

		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	int shortest = dijkstra(1, V);
	int dist = dijkstra(1, P) + dijkstra(P, V);

	if (shortest == dist) {
		std::cout << "SAVE HIM";
	}
	else {
		std::cout << "GOOD BYE";
	}
}