#include <iostream>
#include <vector>

void bfs(int x, int y, std::vector<std::vector<std::pair<int, int>>>& vec, std::vector<std::vector<bool>>& visited) {
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int _x = x + dx[i];
		int _y = y + dy[i];

		if (_x < 1 || _y < 1 || _x >= vec.size() || _y >= vec.size() || vec[_x][_y].first != 0) {
			continue;
		}

		vec[_x][_y].first = vec[x][y].first;
		vec[_x][_y].second = vec[x][y].second + 1;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, K, S, X, Y;
	std::cin >> N >> K;

	std::vector<std::vector<std::pair<int, int>>> vec(N + 1, std::vector<std::pair<int, int>>(N + 1, { 0, 0 }));
	std::vector<std::vector<bool>> visited(N + 1, std::vector<bool>(N + 1, false));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			std::cin >> vec[i][j].first;
		}
	}

	std::cin >> S >> X >> Y;

	for (int t = 0; t < S; t++) {
		for (int k = 1; k <= K; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (!visited[i][j] && vec[i][j].first == k && vec[i][j].second == t) {
						bfs(i, j, vec, visited);
					}
				}
			}
		}
		if (vec[X][Y].first != 0) {
			std::cout << vec[X][Y].first;
			return 0;
		}
	}
	std::cout << vec[X][Y].first;
}