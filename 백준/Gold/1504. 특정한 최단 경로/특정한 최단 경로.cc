#include <iostream>
#include <vector>
#include <queue>
#define INF 100000000
#define MAX 801

std::vector<std::pair<int, int>> graph[MAX];
int N, E;

int dijkstra(int start, int dest) {
	std::vector<int> d(MAX, INF);
	std::priority_queue<std::pair<int, int>> pq;

	pq.push({ 0, start });
	d[start] = 0;

	while (!pq.empty()) {
		int curDist = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (auto e : graph[cur]) {
			int adj = e.first;
			int newCost = curDist + e.second;

			if (d[adj] > newCost) {
				d[adj] = newCost;
				pq.push({ -newCost, adj });
			}
		}
	}

	return d[dest];
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;

		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	int u, v;
	std::cin >> u >> v;

	int uv = dijkstra(u, v);

	int s1 = dijkstra(1, u) + uv + dijkstra(v, N);
	int s2 = dijkstra(1, v) + uv + dijkstra(u, N);

	if (s1 >= INF && s2 >= INF) {
		std::cout << -1;
		return 0;
	}

	std::cout << std::min(s1, s2);
}