#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001

const int INF = 1e9;

std::vector<std::pair<int, int>> graph[MAX];
std::vector<int> homes;
int A, B;
int N, V, E, res = 0;

void dijkstra(int start) {
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

	res += (dist[A] == INF ? -1 : dist[A]);
	res += (dist[B] == INF ? -1 : dist[B]);
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> N >> V >> E;

	std::cin >> A >> B;

	for (int i = 0; i < N; i++) {
		int a;
		std::cin >> a;

		homes.push_back(a);
	}

	for (int i = 0; i < E; i++) {
		int a, b, l;
		std::cin >> a >> b >> l;

		graph[a].push_back({ b,l });
		graph[b].push_back({ a,l });
	}

	for (int i = 0; i < N; i++) {
		dijkstra(homes[i]);
	}

	std::cout << res;
}