#include <iostream>
#include <vector>
#include <queue>
#define MAX 20001

int K, V, E;
std::vector<int> vec[MAX];
std::vector<int> visited(MAX, 0);

bool bfs(int start) {
	std::queue<int> q;
	q.push(start);
	visited[start] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto& e : vec[cur]) {
			if (visited[e] == visited[cur]) {
				return false;
			}
			else if (visited[e] == 0) {
				visited[e] = visited[cur] * -1;
				q.push(e);
			}
		}
	}

	return true;
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> K;
	while (K--) {
		
		std::cin >> V >> E;
		for (int i = 0; i <= V; i++) {
			vec[i].clear();
			visited[i] = 0;
		}

		for (int i = 0; i < E; i++) {
			int a, b;
			std::cin >> a >> b;

			vec[a].push_back(b);
			vec[b].push_back(a);
		}

		bool flag = true;

		for (int i = 1; i <= V; i++) {
			if (visited[i] == 0) {
				if (!bfs(i)) {
					flag = false;
				}
			}
		}

		if (flag) {
			std::cout << "YES\n";
		}
		else {
			std::cout << "NO\n";
		}
	}
}