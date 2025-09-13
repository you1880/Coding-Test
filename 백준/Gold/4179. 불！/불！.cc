#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001

std::vector<std::vector<char>> map(MAX, std::vector<char>(MAX));
std::vector<std::vector<std::pair<int, int>>> info(MAX, std::vector<std::pair<int, int>>(MAX, { -1, 0 }));
std::queue<std::pair<int, int>> f_locs, j_locs;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int R, C, ans = -1;

void f_move() {
	std::vector<std::vector<bool>> visited(MAX, std::vector<bool>(MAX));

	while (!f_locs.empty()) {
		int r = f_locs.front().first;
		int c = f_locs.front().second;
		visited[r][c] = true;
		f_locs.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dx[i];
			int nc = c + dy[i];

			if (nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc] || map[nr][nc] == '#' || info[nr][nc].first != -1) {
				continue;
			}

			visited[nr][nc] = true;
			info[nr][nc].first = info[r][c].first + 1;
			f_locs.push({ nr, nc });
		}
	}
}

void j_move() {
	std::vector<std::vector<bool>> visited(MAX, std::vector<bool>(MAX));

	while (!j_locs.empty()) {
		int r = j_locs.front().first;
		int c = j_locs.front().second;
		visited[r][c] = true;
		j_locs.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dx[i];
			int nc = c + dy[i];

			if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
				ans = info[r][c].second + 1;
				return;
			}

			if (visited[nr][nc] || map[nr][nc] == '#') {
				continue;
			}				

			if (info[r][c].second + 1 >= info[nr][nc].first && info[nr][nc].first != -1) {
				continue;
			}

			visited[nr][nc] = true;
			info[nr][nc].second = info[r][c].second + 1;
			j_locs.push({ nr, nc });
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> R >> C;

	for (int i = 0; i < R; i++) {
		std::string line;
		std::cin >> line;

		for (int j = 0; j < C; j++) {
			map[i][j] = line[j];

			if (map[i][j] == 'F') {
				f_locs.push({ i, j });
				info[i][j].first = 0;
			}
			else if (map[i][j] == 'J') {
				j_locs.push({ i, j });
			}
		}
	}

	f_move();
	j_move();

	if (ans == -1) {
		std::cout << "IMPOSSIBLE";
	}
	else {
		std::cout << ans;
	}
}