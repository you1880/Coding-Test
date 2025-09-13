#include <iostream>
#include <vector>
#include <queue>
#define MAX 17

std::vector<std::vector<int>> grid(MAX, std::vector<int>(MAX, 0));
std::vector<std::pair<int, int>> pos;
int dx[] = { 0, -1, 0 };
int dy[] = { -1, 0, 1 };
int archerPos[3];
int N, M, D, enemyCount = 0, ans = 0;

int getDistance(int r1, int r2, int c1, int c2) {
	return std::abs(r1 - r2) + std::abs(c1 - c2);
}

int bfs(int& enemy, std::vector<std::vector<int>>& copyGrid) {
	std::vector<std::pair<int, int>> targetPos;
	int count = 0;

	for (int i = 0; i < 3; i++) {
		std::queue<std::pair<int, int>> q;
		std::vector<std::vector<bool>> visited(MAX, std::vector<bool>(MAX, false));
		int r = N, c = archerPos[i];

		q.push({ r, c });
		visited[r][c] = true;

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (copyGrid[x][y] == 1) {
				targetPos.push_back({ x, y });
				break;
			}

			for (int i = 0; i < 3; i++) {
				int nr = x + dx[i];
				int nc = y + dy[i];

				if (nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc]) {
					continue;
				}

				if (getDistance(r, nr, c, nc) > D) {
					continue;
				}

				q.push({ nr ,nc });
				visited[nr][nc] = true;
			}
		}
	}

	for (const auto& pos : targetPos) {
		if (copyGrid[pos.first][pos.second] == 1) {
			copyGrid[pos.first][pos.second] = 0;
			count++;
			enemy--;
		}
	}

	return count;
}

void game() {
	std::vector<std::vector<int>> copyGrid = grid;
	int count = 0, enemy = enemyCount;

	while (1) {
		if (enemy == 0) {
			ans = std::max(ans, count);
			break;
		}

		count += bfs(enemy, copyGrid);

		for (int i = 0; i < M; i++) {
			if (copyGrid[N - 1][i] == 1) {
				enemy--;
				copyGrid[N - 1][i] = 0;
			}
		}

		for (int i = N - 2; i >= 0; i--) {
			for (int j = 0; j < M; j++) {
				copyGrid[i + 1][j] = copyGrid[i][j];
				copyGrid[i][j] = 0;
			}
		}
	}
}

void selectPos(int cnt, int idx) {
	if (cnt == 3) {
		game();
		return;
	}

	for (int i = idx; i < M; i++) {
		archerPos[cnt] = i;
		selectPos(cnt + 1, i + 1);
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> N >> M >> D;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> grid[i][j];

			if (grid[i][j] == 1) {
				enemyCount++;
			}
		}
	}

	selectPos(0, 0);

	std::cout << ans;
}