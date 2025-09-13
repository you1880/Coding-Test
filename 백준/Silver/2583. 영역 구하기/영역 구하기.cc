#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int bfs(int x, int y, std::vector<std::vector<int>> arr, std::vector<std::vector<bool>>& visited) {
	std::queue<std::pair<int, int>> q;
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	int cnt = 1;

	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int _x = a + dx[i];
			int _y = b + dy[i];

			if ((_x < 0 || _y < 0 || _x >= arr.size() || _y >= arr[0].size()) || visited[_x][_y] || arr[_x][_y] == 1) {
				continue;
			}

			q.push({ _x,_y });
			visited[_x][_y] = true;
			cnt++;
		}
	}

	return cnt;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int M, N, K;
	int x1, x2, y1, y2;
	std::cin >> M >> N >> K;

	std::vector<std::vector<int>> arr(M, std::vector<int>(N, 0));
	std::vector<std::vector<bool>> visited(M, std::vector<bool>(N, false));
	std::vector<int> areas;

	for (int i = 0; i < K; i++) {
		std::cin >> x1 >> y1 >> x2 >> y2;

		for (int a = x1; a < x2; a++) {
			for (int b = y1; b < y2; b++) {
				arr[b][a] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && arr[i][j] == 0) {
				int t = bfs(i, j, arr, visited);
				areas.push_back(t);
			}
		}
	}

	std::sort(areas.begin(), areas.end());

	std::cout << areas.size() << "\n";
	for (auto e : areas) {
		std::cout << e << " ";
	}
}