#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 100001

int N, M, R;
std::vector<int> vec[MAX];
int visited[MAX];

void bfs(int start) {
	std::queue<int> q;
	int seq = 1;

	q.push(start);
	visited[start] = seq;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < vec[x].size(); i++) {
			int y = vec[x][i];

			if (!visited[y]) {
				q.push(y);
				visited[y] = ++seq;
			}
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int a, b;
	std::cin >> N >> M >> R;

	for (int i = 0; i < M; i++) {
		std::cin >> a >> b;

		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	
	for (int i = 1; i <= N; i++) {
		if (vec[i].size() > 1)
			std::sort(vec[i].begin(), vec[i].end());
	}

	bfs(R);
	
	for (int i = 1; i <= N; i++) {
		std::cout << visited[i] << "\n";
	}
}