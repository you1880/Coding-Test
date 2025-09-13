#include <iostream>
#include <vector>
#include <queue>
#define MAX 201

std::vector<std::vector<int>> grid(MAX, std::vector<int>(MAX));
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int hx[] = { 1, 1, 2, 2, -1, -1, -2, -2 };
int hy[] = { 2, -2, 1, -1, 2, -2, 1, -1 };
int W, H, K;

struct Data {
	int r;
	int c;
	int count;
};

int bfs(std::vector<std::vector<std::vector<int>>>& dist) {
	std::queue<Data> q;

	q.push({ 0, 0, K });
	dist[0][0][K] = 1;

	while (!q.empty()) {
		int x = q.front().r;
		int y = q.front().c;
		int count = q.front().count;
		q.pop();

		if (x == H - 1 && y == W - 1) {
			return dist[H - 1][W - 1][count] - 1;
		}

		if (count > 0) {
			for (int i = 0; i < 8; i++) {
				int a = x + hx[i];
				int b = y + hy[i];

				if (a < 0 || b < 0 || a >= H || b >= W || grid[a][b] == 1 || dist[a][b][count - 1]) {
					continue;
				}

				dist[a][b][count - 1] = dist[x][y][count] + 1;
				q.push({ a, b, count - 1 });
			}
		}
		for (int i = 0; i < 4; i++) {
			int a = x + dx[i];
			int b = y + dy[i];

			if (a < 0 || b < 0 || a >= H || b >= W || grid[a][b] == 1 || dist[a][b][count]) {
				continue;
			}

			dist[a][b][count] = dist[x][y][count] + 1;
			q.push({ a, b, count });
		}
	}

	return -1;
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> K >> W >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			std::cin >> grid[i][j];
		}
	}

	std::vector<std::vector<std::vector<int>>> dist(H, std::vector<std::vector<int>>(W, std::vector<int>(K + 1, 0)));

	std::cout << bfs(dist);
}