#include <iostream>
#include <queue>

int count = 0;
int vec[501][501];
int n, m;

int bfs(int r, int c) {
	int size = 1;
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	std::queue<std::pair<int, int>> q;
	q.push({ r, c });
	vec[r][c] = 0;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int _x = a + dx[i];
			int _y = b + dy[i];

			if (_x < 0 || _y < 0 || _x >= n || _y >= m || vec[_x][_y] == 0) {
				continue;
			}
			q.push({ _x, _y });
			vec[_x][_y] = 0;
			size++;
		}
	}

	return size;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int size = 0;
	std::cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> vec[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vec[i][j] == 1) {
				count++;
				size = std::max(size, bfs(i, j));
			}
		}
	}
	std::cout << count << "\n" << size;
}