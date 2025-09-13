#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001
#define INF 1e9

int table[MAX];
std::vector<std::pair<int, int>> graph[MAX];

void dijkstra(int start) {
	std::priority_queue<std::pair<int, int>> pq;
	pq.push({ 0, start });
	table[start] = 0;

	while (!pq.empty()) {
		int curDist = -pq.top().first;
		int curNum = pq.top().second;
		pq.pop();

		if (curDist > table[curNum]) {
			continue;
		}

		for (auto edge : graph[curNum]) {
			int adjNum = edge.first;
			int cost = edge.second;
			int newCost = curDist + cost;

			if (table[adjNum] > newCost) {
				table[adjNum] = newCost;
				pq.push({ -newCost, adjNum });
			}
		}
	}
}

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		int n, d, c, a, b, s;
		std::cin >> n >> d >> c;
		int num = n, cost = 0;

		for (int j = 1; j <= n; j++) {
			table[j] = INF;
			graph[j].clear();
		}

		for (int j = 0; j < d; j++) {
			std::cin >> a >> b >> s;
			
			graph[b].push_back({ a, s });
		}

		dijkstra(c);

		for (int j = 1; j <= n; j++) {
			if (table[j] == INF) {
				num--;
				continue;
			}
			cost = table[j] > cost ? table[j] : cost;
		}

		std::cout << num << " " << cost << "\n";
	}
}