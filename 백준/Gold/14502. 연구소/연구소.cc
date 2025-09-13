#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> map(8, std::vector<int>(8, 0));
std::vector<std::pair<int, int>> walls;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0, 0, 1, -1 };
int N, M;
int res = 0, safe = 0;

void bfs(int i, int j, int& areas, std::vector<std::vector<bool>>& visited, std::vector<std::vector<int>>& lab) {
	std::queue<std::pair<int, int>> q;

	q.push({ i, j });
	visited[i][j] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int a = x + dx[i];
			int b = y + dy[i];

			if (a < 0 || b < 0 || a >= N || b >= M || visited[a][b] || lab[a][b] != 0) {
				continue;
			}

			visited[a][b] = true;
			lab[a][b] = 2;
			areas--;
			q.push({ a, b });
		}
	}
}

void func(int cnt, std::vector<bool>& selected) {
	if (cnt == 3) {
		std::vector<std::vector<int>> lab = map;
		std::vector<std::vector<bool>> visited(8, std::vector<bool>(8, false));
		int areas = safe - 3;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (lab[i][j] == 2 && !visited[i][j]) {
					bfs(i, j, areas, visited, lab);
				}
			}
		}
		
		res = areas > res ? areas : res;

		return;
	}

	for (int i = 0; i < walls.size(); i++) {
		if (!selected[i]) {
			selected[i] = true;

			map[walls[i].first][walls[i].second] = 1;
			func(cnt + 1, selected);

			map[walls[i].first][walls[i].second] = 0;
			selected[i] = false;
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> map[i][j];

			if (map[i][j] == 0) {
				walls.push_back({ i, j });
				safe++;
			}
		}
	}

	std::vector<bool> selected(walls.size(), false);
	func(0, selected);

	std::cout << res;
}