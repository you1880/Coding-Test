#include <iostream>
#include <vector>
#include <queue>
#define MAX 302

std::vector<std::vector<int>>map(MAX, std::vector<int>(MAX, -1));
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int N, M;

void bfs(int x, int y, std::vector<std::vector<bool>>& visited, std::vector<std::vector<int>>& tmp) {
	std::queue<std::pair<int, int>> q;
	visited[x][y] = true;
	q.push({ x,y });

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int _x = a + dx[i];
			int _y = b + dy[i];

			if (_x <= 0 || _y <= 0 || _x > N || _y > M || visited[_x][_y] || tmp[_x][_y] <= 0) {
				continue;
			}

			q.push({ _x,_y });
			visited[_x][_y] = true;
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int year = 0;

	std::cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			std::cin >> map[i][j];
		}
	}
	
	while (1) {
		int cnt = 0;
		year++;

		std::vector<std::vector<int>> tmp = map;
		
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (tmp[i][j] >= 1) {
					int water = 0;

					for (int k = 0; k < 4; k++) {
						if (map[i + dx[k]][j + dy[k]] == 0) {
							water++;
						}
					}

					tmp[i][j] = tmp[i][j] - water < 0 ? 0 : tmp[i][j] - water;
				}
			}
		}

		std::vector<std::vector<bool>> visited(MAX, std::vector<bool>(MAX, false));
		
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (!visited[i][j] && tmp[i][j] >= 1) {
					bfs(i, j, visited, tmp);
					cnt++;
				}

				if (cnt >= 2) {
					std::cout << year;
					return 0;
				}
			}
		}

		if (cnt == 0) {
			std::cout << "0";
			return 0;
		}

		map = tmp;
	}
}