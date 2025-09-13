#include <iostream>
#include <queue>
#include <vector>

void bfs(int x, int y, std::vector<std::vector<int>> farm, std::vector<std::vector<bool>>& visited) {
	std::queue<std::pair<int, int>> q;
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };

	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int _x = a + dx[i];
			int _y = b + dy[i];

			if ((_x < 0 || _y < 0 || _x >= farm.size() || _y >= farm[0].size()) || visited[_x][_y] || farm[_x][_y] == 0 ) {
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

	int T, M, N, K, X, Y;
	std::cin >> T;
	for (int i = 0; i < T; i++) {
		int cnt = 0;
		std::cin >> M >> N >> K;
		std::vector<std::vector<int>> farm(M, std::vector<int>(N, 0));
		std::vector<std::vector<bool>> visited(M, std::vector<bool>(N, false));

		for (int i = 0; i < K; i++) {
			std::cin >> X >> Y;
			farm[X][Y] = 1;
		}

		for (int a = 0; a < farm.size(); a++) {
			for (int b = 0; b < farm[a].size(); b++) {
				if (farm[a][b] && !visited[a][b]) {
					bfs(a, b, farm, visited);
					cnt++;
				}
			}
		}
		std::cout << cnt << "\n";
	}
}