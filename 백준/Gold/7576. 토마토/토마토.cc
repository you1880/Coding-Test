#include <iostream>
#include <vector>
#include <queue>

std::queue<std::pair<int, int>> q;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(std::vector<std::vector<int>>& farm) {
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int _x = a + dx[i];
			int _y = b + dy[i];

			if ((_x < 0 || _y < 0 || _x >= farm.size() || _y >= farm[0].size()) || farm[_x][_y] != 0) {
				continue;
			}
			farm[_x][_y] = farm[a][b] + 1;
			q.push({ _x,_y });
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M, max = 0;
	std::cin >> N >> M;

	std::vector<std::vector<int>> farm(M, std::vector<int>(N, 0));

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> farm[i][j];

			if (farm[i][j] == 1) {
				q.push({ i,j });
			}
		}
	}

	bfs(farm);

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (farm[i][j] == 0) {
				std::cout << "-1";
				return 0;
			}

			max = farm[i][j] > max ? farm[i][j] : max;
		}
	}

	std::cout << max - 1;
}