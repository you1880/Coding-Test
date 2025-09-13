#include <iostream>
#include <vector>
#include <deque>
#define MAX 101

int map[MAX][MAX];
int dist[MAX][MAX];
int N, M;

void bfs() {
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	std::deque<std::pair<int, int>> dq;
	dq.push_back({ 0, 0 });
	dist[0][0] = 0;

	while (!dq.empty()) {
		int x = dq.front().first;
		int y = dq.front().second;
		dq.pop_front();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M || dist[nx][ny] != 1e9) {
				continue;
			}

			if (map[nx][ny] == 0) {
				dq.push_front({ nx, ny });
				dist[nx][ny] = dist[x][y];
			}

			if (map[nx][ny] == 1) {
				dq.push_back({ nx, ny });
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
}

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	std::cin >> M >> N;
	std::string line;

	for (int i = 0; i < N; i++) {
		std::cin >> line;

		for (int j = 0; j < M; j++) {
			map[i][j] = line[j] - '0';
			dist[i][j] = 1e9;
		}
	}

	bfs();

	std::cout << dist[N - 1][M - 1];
}