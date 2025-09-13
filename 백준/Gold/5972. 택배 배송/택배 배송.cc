#include <iostream>
#include <vector>
#include <queue>
#define MAX 50001
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
			int newCost = cost + curDist;

			if (table[adjNum] > newCost) {
				table[adjNum] = newCost;
				pq.push({ -newCost, adjNum });
			}
		}
	}
}

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	int N, M, A_i, B_i, C_i;
	std::cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		table[i] = INF;
	}

	for (int i = 0; i < M; i++) {
		std::cin >> A_i >> B_i >> C_i;

		graph[A_i].push_back({ B_i, C_i });
		graph[B_i].push_back({ A_i, C_i });
	}

	dijkstra(1);

	std::cout << table[N];
}