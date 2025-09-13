#include <iostream>
#include <deque>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::deque<std::pair<int, int>> snake;
	std::vector<std::pair<int, char>> dirs;
	snake.push_front({ 1,1 });

	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };
	int dir = 0, time = 0;

	int N, K, L, x, y, idx = 0;
	std::cin >> N >> K;

	std::vector<std::vector<int>> map(N + 1, std::vector<int>(N + 1, 0));
	map[1][1] = 1;
	for (int i = 0; i < K; i++) {
		std::cin >> x >> y;
		map[x][y] = 2;
	}
	
	std::cin >> L;
	for (int i = 0; i < L; i++) {
		int t;
		char d;
		std::cin >> t >> d;
		dirs.push_back({ t,d });
	}

	while (1) {
		time++;
		int nx = snake.back().first + dx[dir];
		int ny = snake.back().second + dy[dir];

		if (nx < 1 || ny < 1 || nx > N || ny > N || map[nx][ny] == 1) {
			break;
		}

		if (map[nx][ny] == 2) {
			map[nx][ny] = 0;
		}
		else if (map[nx][ny] == 0) {
			map[snake.front().first][snake.front().second] = 0;
			snake.pop_front();
		}

		map[nx][ny] = 1;
		snake.push_back({ nx, ny });

		if (idx >= dirs.size()) {
			continue;
		}
		if (time == dirs[idx].first) {
			char direction = dirs[idx].second;
			if (direction == 'D') {
				dir++;
				dir = dir > 3 ? 0 : dir;
			}
			else if (direction == 'L') {
				dir--;
				dir = dir < 0 ? 3 : dir;
			}
			idx++;
		}
	}
	std::cout << time;
}