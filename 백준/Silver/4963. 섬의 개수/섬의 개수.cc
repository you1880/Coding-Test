#include <iostream>
#include <queue>
#include <vector>

void bfs(int x, int y, std::vector<std::vector<int>> island, std::vector<std::vector<bool>>& visited) {
	std::queue<std::pair<int, int>> q;
	int dx[8] = { 1,0,-1,0,1,1,-1,-1 };
	int dy[8] = { 0,1,0,-1,-1,1,-1,1 };

	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int _x = a + dx[i];
			int _y = b + dy[i];

			if (_x < 0 || _y < 0 || _x >= island.size() || _y >= island[0].size() || visited[_x][_y] || island[_x][_y] == 0) {
				continue;
			}

			q.push({ _x,_y });
			visited[_x][_y] = true;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int w, h, x;
	
	while (1) {
		int cnt = 0;
		std::cin >> w >> h;
		if (!w && !h) {
			return 0;
		}

		std::vector<std::vector<int>> island;
		std::vector<std::vector<bool>> visited(h, std::vector<bool>(w, false));
		for (int i = 0; i < h; i++) {
			std::vector<int> tmp;
			for (int j = 0; j < w; j++) {
				std::cin >> x;
				tmp.push_back(x);
			}
			island.push_back(tmp);
		}

		for (int i = 0; i < island.size(); i++) {
			for (int j = 0; j < island[i].size(); j++) {
				if (island[i][j] && !visited[i][j]) {
					bfs(i, j, island, visited);
					cnt++;
				}
			}
		}
		std::cout << cnt << "\n";
	}
}