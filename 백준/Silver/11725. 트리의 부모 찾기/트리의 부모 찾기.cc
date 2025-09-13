#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001

std::vector<int> graph[MAX];
int ans[MAX];
bool visited[MAX];

void bfs() {
	std::queue<int> q;
	visited[1] = true;
	q.push(1);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!visited[y]) {
				q.push(y);
				visited[y] = true;
				ans[y] = x;
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, a, b;
	std::cin >> N;

	for (int i = 0; i < N - 1; i++) {
		std::cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	bfs();

	for (int i = 2; i <= N; i++) {
		std::cout << ans[i] << "\n";
	}
}