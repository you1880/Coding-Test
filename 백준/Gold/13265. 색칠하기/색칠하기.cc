#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001

std::vector<int> vec[MAX];
std::vector<int> visited(MAX, 0);
int T, N, M, x, y;

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

	std::cin >> T;

	while (T--) {
		std::cin >> N >> M;

		for (int i = 0; i <= N; i++) {
			vec[i].clear();
			visited[i] = 0;
		}

		for (int i = 0; i < M; i++) {
			std::cin >> x >> y;

			vec[x].push_back(y);
			vec[y].push_back(x);
		}

		bool flag = true;
		for (int i = 1; i <= N; i++) {
			if (visited[i] == 0) {
				if (!bfs(i)) {
					flag = false;
				}
			}
		}

		if (flag) {
			std::cout << "possible\n";
		}
		else {
			std::cout << "impossible\n";
		}
	}
}