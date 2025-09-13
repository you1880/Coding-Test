#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
#define INF 1e9

int N, M, X;
std::vector<std::pair<int, int>> roads[MAX];

int dijkstra(int start, int dest) {
	std::priority_queue<std::pair<int, int>> pq;
	int d[MAX];

	for (int i = 0; i <= N; i++) {
		d[i] = INF;
	}

	pq.push({ 0, start });
	d[start] = 0;

	while (!pq.empty()) {
		int dist = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist > d[cur]) {
			continue;
		}

		for (auto& edge : roads[cur]) {
			int adj = edge.first;
			int time = edge.second;
			int new_time = dist + time;

			if (d[adj] > new_time) {
				d[adj] = new_time;
				pq.push({ -new_time, adj });
			}
		}
	}

	return d[dest];
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int a, b, c, max = 0;
	std::cin >> N >> M >> X;

	for (int i = 0; i < M; i++) {
		std::cin >> a >> b >> c;

		roads[a].push_back({ b,c });
	}

	for (int i = 1; i <= N; i++) {
		int d_i = dijkstra(i, X) + dijkstra(X, i);

		max = d_i > max ? d_i : max;
	}

	std::cout << max;
}