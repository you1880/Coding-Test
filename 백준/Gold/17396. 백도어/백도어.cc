#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100001
#define INF 98765432100

std::vector<std::pair<int, long long>> graph[MAX];
std::vector<long long> d(MAX, INF);	

int N, M;
std::vector<int> visible(MAX);

void dijkstra(int start) {	
	std::priority_queue<std::pair<long long, int>> pq;

	pq.push({ 0, start });
	d[start] = 0;

	while (!pq.empty()) {
		long long curDist = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (curDist > d[cur]) {
			continue;
		}

		for (const auto& e : graph[cur]) {
			int adj = e.first;
			long long cost = e.second;
			long long newCost = cost + curDist;

			if (visible[adj] == 1 && adj != N - 1) {
				continue;
			}

			if (d[adj] > newCost) {
				d[adj] = newCost;
				pq.push({ -newCost, adj });
			}
		}
	}

}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		std::cin >> visible[i];
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;

		graph[a].push_back({ b, c });
		graph[b].push_back({ a,c });
	}

	dijkstra(0);

	if (d[N - 1] == INF) {
		std::cout << -1;
	}
	else {
		std::cout << d[N - 1];
	}
}