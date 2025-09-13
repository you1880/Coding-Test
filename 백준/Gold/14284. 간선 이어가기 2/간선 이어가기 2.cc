#include <iostream>
#include <vector>
#include <queue>
#define MAX 5001
#define INF 1e9

std::vector<std::pair<int, int>> graph[MAX];
int d[MAX];
int n, m, s, t;

void dijkstra() {
	std::priority_queue<std::pair<int, int>> pq;
	pq.push({ 0, s });
	d[s] = 0;

	while (!pq.empty()) {
		int curDist = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (curDist > d[cur]) {
			continue;
		}

		if (cur == t) {
			std::cout << curDist;
			return;
		}

		for (auto& e : graph[cur]) {
			int next = e.first;
			int cost = e.second;
			int newCost = cost + curDist;

			if (d[next] > newCost) {
				d[next] = newCost;
				pq.push({ -newCost, next });
			}
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int a, b, c;
	std::cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		d[i] = INF;
	}

	for (int i = 0; i < m; i++) {
		std::cin >> a >> b >> c;

		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	std::cin >> s >> t;

	dijkstra();
}