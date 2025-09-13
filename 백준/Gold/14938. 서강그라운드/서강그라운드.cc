#include <iostream>
#include <queue>
#include <vector>
#define MAX 101
#define INF 1e9

int n, m, r;
int d[MAX];
int item[MAX];
std::vector<std::pair<int, int>> graph[MAX];

int dijkstra(int start) {
	int cnt = 0;
	std::priority_queue<std::pair<int, int>> pq;
	
	for (int i = 1; i <= n; i++) {
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

		for (auto& edge : graph[cur]) {
			int adj = edge.first;
			int weight = edge.second;
			int new_weight = dist + weight;

			if (d[adj] > new_weight) {
				d[adj] = new_weight;
				pq.push({ -new_weight, adj });
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (m >= d[i]) {
			cnt += item[i];
		}
	}

	return cnt;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int a, b, c, ans = 0;
	std::cin >> n >> m >> r;

	for (int i = 1; i <= n; i++) {
		std::cin >> item[i];
	}

	for (int i = 0; i < r; i++) {
		std::cin >> a >> b >> c;

		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}

	for (int i = 1; i <= n; i++) {
		int c = dijkstra(i);
		ans = c > ans ? c : ans;
	}

	std::cout << ans;
}