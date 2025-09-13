#include <iostream>
#include <vector>
#include <queue>
#define MAX 251

int dx[] = { 1,1,0,-1,-1,-1,0,1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };
int M, N;

std::vector<std::vector<int>> vec(MAX, std::vector<int>(MAX, 0));
std::vector<std::vector<bool>> visited(MAX, std::vector<bool>(MAX, false));

void bfs(int r, int c) {
	std::queue<std::pair<int, int>> q;

	q.push({ r, c });
	visited[r][c] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int a = x + dx[i];
			int b = y + dy[i];

			if (a < 0 || b < 0 || a >= M || b >= N || visited[a][b] || vec[a][b] == 0) {
				continue;
			}

			q.push({ a, b });
			visited[a][b] = true;
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int res = 0;
	std::cin >> M >> N;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> vec[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && vec[i][j] == 1) {
				bfs(i, j);
				res++;
			}
		}
	}

	std::cout << res;
}