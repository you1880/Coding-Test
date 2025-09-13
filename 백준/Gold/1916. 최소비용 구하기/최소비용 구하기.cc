#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
#define INF 1e9

std::vector<std::pair<int, int>> vec[MAX];
int table[MAX];

void dijkstra(int start) {
	std::priority_queue<std::pair<int, int>> pq;
	pq.push({ 0,start });
	table[start] = 0;

	while (!pq.empty()) {
		int dist = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist > table[cur]) {
			continue;
		}

		for (auto e : vec[cur]) {
			int adj = e.first;
			int cost = e.second;
			int new_cost = cost + dist;

			if (table[adj] > new_cost) {
				table[adj] = new_cost;
				pq.push({ -new_cost, adj });
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M, a, b, c, start, dest;
	std::cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		table[i] = INF;
	}

	for (int i = 0; i < M; i++) {
		std::cin >> a >> b >> c;

		vec[a].push_back({ b,c });
	}

	std::cin >> start >> dest;
	dijkstra(start);

	std::cout << table[dest];
}