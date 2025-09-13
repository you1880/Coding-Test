#include <iostream>
#include <queue>
#include <vector>
#define MAX 300001
#define INF 1e9

std::vector<std::pair<int, int>> graph[MAX];
int d[MAX];

void dijkstra(int start) {
	std::priority_queue<std::pair<int, int>> pq;
	pq.push({ 0, start });
	d[start] = 0;

	while (!pq.empty()) {
		int curDist = -pq.top().first;
		int curNum = pq.top().second;
		pq.pop();

		if (curDist > d[curNum]) {
			continue;
		}

		for (auto& edge : graph[curNum]) {
			int adjNum = edge.first;
			int cost = edge.second;
			int newcost = curDist + cost;

			if (d[adjNum] > newcost) {
				d[adjNum] = newcost;
				pq.push({ -newcost, adjNum });
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::vector<int> res;
	int N, M, K, X, a, b;
	std::cin >> N >> M >> K >> X;

	for (int i = 1; i <= N; i++) {
		d[i] = INF;
	}
	
	for (int i = 0; i < M; i++) {
		std::cin >> a >> b;

		graph[a].push_back({ b, 1 });
	}

	dijkstra(X);

	for (int i = 1; i <= N; i++) {
		if (d[i] == K) {
			res.push_back(i);
		}
	}

	if (res.empty()) {
		std::cout << -1;
	}
	else {
		for (auto e : res) {
			std::cout << e << "\n";
		}
	}
}