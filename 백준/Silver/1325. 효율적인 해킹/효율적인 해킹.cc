#include <memory.h>
#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001

std::vector<int> graph[MAX];
int visited[MAX] = { 0, };

int bfs(int start) {
	memset(visited, 0, sizeof(visited));
	std::queue<int> q;
	q.push(start);
	int cnt = 1;
	visited[start] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!visited[y]) {
				q.push(y);
				visited[y] = 1;
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M, a, b, max = 0;
	std::cin >> N >> M;

	std::vector<int> vec(N + 1, 0);

	for (int i = 0; i < M; i++) {
		std::cin >> a >> b;

		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		int cnt = bfs(i);
		vec[i] = cnt;
		max = cnt > max ? cnt : max;
	}

	for (int i = 1; i <= N; i++) {
		if (max == vec[i]) {
			std::cout << i << " ";
		}
	}
}