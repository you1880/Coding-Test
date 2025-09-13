#include <iostream>
#include <vector>
#include <queue>
#define MAX 251

int R, C, wolf = 0, sheep = 0;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int visited[MAX][MAX];
std::vector<std::string> map;

void bfs(int x, int y) {
	int w = 0, s = 0;
	std::queue<std::pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = 1;

	if (map[x][y] == 'o') {
		s++;
	}
	else if (map[x][y] == 'v') {
		w++;
	}

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int _x = a + dx[i];
			int _y = b + dy[i];

			if (_x < 0 || _y < 0 || _x >= R || _y >= C || visited[_x][_y] || map[_x][_y] == '#') {
				continue;
			}

			if (map[_x][_y] == 'o') {
				s++;
			}
			else if (map[_x][_y] == 'v') {
				w++;
			}

			visited[_x][_y] = 1;
			q.push({ _x, _y });
		}
	}

	if (w >= s) {
		wolf += w;
	}
	else {
		sheep += s;
	}
}

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	std::string line;
	std::cin >> R >> C;

	for (int i = 0; i < R; i++) {
		std::cin >> line;
		map.push_back(line);
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] != '#' && !visited[i][j]) {
				bfs(i, j);
			}
		}
	}
	
	std::cout << sheep << " " << wolf;
}