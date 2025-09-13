#include <iostream>
#include <vector>
#include <queue>
#define MAX 301

std::vector<std::vector<char>> room(MAX, std::vector<char>(MAX));
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int N, M;
int sx, sy, tx, ty;
bool check = false;

void bfs() {
	std::vector<std::vector<bool>> visited(N + 1, std::vector<bool>(M + 1, false));
	std::queue<std::pair<int, int>> q;

	q.push({ sx, sy });
	visited[sx][sy] = true;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dx[i];
			int nc = c + dy[i];

			if (nr == tx && nc == ty) {
				check = true;
				return;
			}

			if (nr <= 0 || nr > N || nc <= 0 || nc > M || visited[nr][nc]) {
				continue;
			}

			visited[nr][nc] = true;

			if (room[nr][nc] == '1') {
				room[nr][nc] = '0';
			}
			else if (room[nr][nc] == '0') {
				q.push({ nr, nc });
			}
		}
	}
}
int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> N >> M >> sx >> sy >> tx >> ty;
	for (int i = 1; i <= N; i++) {
		std::string line;
		std::cin >> line;

		for (int j = 1; j <= M; j++) {
			room[i][j] = line[j - 1];
		}
	}

	int cnt = 0;

	while (1) {
		cnt++;
		bfs();

		if (check) {
			std::cout << cnt;
			return 0;
		}
	}
}