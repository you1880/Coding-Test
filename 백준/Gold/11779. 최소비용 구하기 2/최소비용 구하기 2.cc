#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
#define INF 1e9

std::vector<std::pair<int, int>> graph[MAX];
int table[MAX];
int d[MAX];
int N, M, start, end;

void dijkstra() {
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

		for (auto& e : graph[curNum]) {
			int next = e.first;
			int cost = e.second;
			int newCost = cost + curDist;

			if (d[next] > newCost) {
				d[next] = newCost;
				pq.push({ -newCost, next });

				table[next] = curNum;
			}
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::vector<int> nums;
	int s, e, w;
	std::cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		d[i] = INF;
	}

	for (int i = 0; i < M; i++) {
		std::cin >> s >> e >> w;

		graph[s].push_back({ e, w });
	}

	std::cin >> start >> end;

	dijkstra();

	std::cout << d[end] << "\n";
	
	int n = end;
	while (1) {
		if (n == 0) {
			break;
		}
		nums.push_back(n);
		n = table[n];
	}

	std::cout << nums.size() << "\n";
	for (auto itr = nums.rbegin(); itr != nums.rend(); itr++) {
		std::cout << *itr << " ";
	}
}