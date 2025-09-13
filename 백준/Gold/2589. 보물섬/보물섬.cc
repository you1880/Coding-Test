#include <iostream>
#include <vector>
#include <queue>
#define MAX 51

std::vector<std::vector<char>> map(MAX, std::vector<char>(MAX));

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int N, M, res = 0;

int bfs(int r, int c, std::vector<std::vector<int>>& dist) {
	std::queue<std::pair<int, int>> q;

	int tmp = 0;
	dist[r][c] = 1;
	q.push({ r, c });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = x + dx[i];
			int nc = y + dy[i];

			if (nr < 0 || nc < 0 || nr >= N || nc >= M || map[nr][nc] == 'W' || dist[nr][nc]) {
				continue;
			}

			dist[nr][nc] = dist[x][y] + 1;
			q.push({ nr, nc });
			tmp = std::max(tmp, dist[nr][nc]);
		}
	}

	return tmp;
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		std::string line;
		std::cin >> line;

		for (int j = 0; j < M; j++) {
			map[i][j] = line[j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'L') {
				std::vector<std::vector<int>> dist(N, std::vector<int>(M, 0));
				res = std::max(res, bfs(i, j, dist));
			}
		}
	}

	std::cout << res - 1;
}