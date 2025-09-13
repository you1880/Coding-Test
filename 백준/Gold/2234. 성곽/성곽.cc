#include <iostream>
#include <vector>
#include <queue>
#define MAX 51

std::vector<std::vector<int>> spaces(MAX, std::vector<int>(MAX));
std::vector<std::vector<int>> nums(MAX, std::vector<int>(MAX));
std::vector<int> sizes(1);
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
int N, M, room_nums = 1, max_size = 0;

int bfs(int r, int c, std::vector<std::vector<bool>>& visited) {
	std::queue<std::pair<int, int>> q;
	int size = 1;

	q.push({ r, c });
	nums[r][c] = room_nums;
	visited[r][c] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			if (spaces[x][y] & (1 << i)) {
				continue;
			}

			int nr = x + dx[i];
			int nc = y + dy[i];

			if (nr < 0 || nr >= M || nc < 0 || nc >= N || visited[nr][nc]) {
				continue;
			}

			size++;
			visited[nr][nc] = true;
			nums[nr][nc] = room_nums;
			q.push({ nr, nc });
		}
	}

	return size;
}

void BreakWall(int r, int c) {
	for (int i = 0; i < 4; i++) {
		int nr = r + dx[i];
		int nc = c + dy[i];

		if (nr < 0 || nr >= M || nc < 0 || nc >= N) {
			continue;
		}

		if (!(spaces[r][c] & (1 << i))) {
			continue;
		}

		if (nums[r][c] == nums[nr][nc]) {
			continue;
		}

		int r1 = nums[r][c], r2 = nums[nr][nc];
		max_size = std::max(max_size, sizes[r1] + sizes[r2]);
		
		spaces[r][c] &= ~(1 << i);
		spaces[nr][nc] &= ~(1 << i);
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> N >> M;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> spaces[i][j];
		}
	}

	std::vector<std::vector<bool>> visited(M + 1, std::vector<bool>(N + 1, false));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				int size = bfs(i, j, visited);
				max_size = std::max(size, max_size);
				sizes.push_back(size);
				room_nums++;
			}
		}
	}
	
	std::cout << room_nums - 1 << "\n";
	std::cout << max_size << "\n";

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			BreakWall(i, j);
		}
	}

	std::cout << max_size;
}