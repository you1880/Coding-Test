#include <iostream>
#include <vector>
#include <queue>
#define MAX 301

int I;

int bfs(int x1, int y1, int x2, int y2) {
	std::queue<std::pair<std::pair<int, int>, int>> q;
	std::vector<std::vector<bool>> visited(I, std::vector<bool>(I, false));
	int dx[8] = { -2,-2,-1,1,-1,1,2,2 };
	int dy[8] = { 1,-1,2,2,-2,-2,1,-1 };
	int cnt = 0;

	q.push({ { x1,y1 },0 });
	visited[x1][y1] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int l = q.front().second;
		q.pop();

		if (x == x2 && y == y2) {
			return l;
		}

		for (int i = 0; i < 8; i++) {
			int _x = x + dx[i];
			int _y = y + dy[i];

			if (_x < 0 || _y < 0 || _x >= I || _y >= I || visited[_x][_y]) {
				continue;
			}
			q.push({ { _x, _y }, l + 1 });
			visited[_x][_y] = true;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int T, x1, y1, x2, y2;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		std::cin >> I;

		std::vector<std::vector<int>> chess(I, std::vector<int>(I, 0));
		std::cin >> x1 >> y1 >> x2 >> y2;

		std::cout << bfs(x1, y1, x2, y2) << "\n";
	}
}