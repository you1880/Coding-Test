#include <iostream>
#include <vector>
#define MAX 51

int N, M, times = 1;
std::vector<std::vector<int>> map(MAX, std::vector<int>(MAX, 0));
std::vector<std::vector<int>> loc(MAX, std::vector<int>(MAX, 0));
std::vector<std::pair<int, int>> clouds;

int inc(int r, int c) {
	int count = 0;
	if (r - 1 >= 1 && c - 1 >= 1 && map[r - 1][c - 1] > 0) {
		count++;
	}
	if (r + 1 <= N && c - 1 >= 1 && map[r + 1][c - 1] > 0) {
		count++;
	}
	if (r - 1 >= 1 && c + 1 <= N && map[r - 1][c + 1] > 0) {
		count++;
	}
	if (r + 1 <= N && c + 1 <= N && map[r + 1][c + 1] > 0) {
		count++;
	}

	return count;
}

void move(int d, int s) {
	s = s % N;

	for (auto& c : clouds) {
		switch (d) {
			case 1:
				c.second = c.second - s < 1 ? N - s + c.second : c.second - s;
				break;
			case 2:
				c.first = c.first - s < 1 ? N - s + c.first : c.first - s;
				c.second = c.second - s < 1 ? N - s + c.second : c.second - s;
				break;
			case 3:
				c.first = c.first - s < 1 ? N - s + c.first : c.first - s;
				break;
			case 4:
				c.first = c.first - s < 1 ? N - s + c.first : c.first - s;
				c.second = c.second + s > N ? (c.second + s) % N : c.second + s;
				break;
			case 5:
				c.second = c.second + s > N ? (c.second + s) % N : c.second + s;
				break;
			case 6:
				c.first = c.first + s > N ? (c.first + s) % N : c.first + s;
				c.second = c.second + s > N ? (c.second + s) % N : c.second + s;
				break;
			case 7:
				c.first = c.first + s > N ? (c.first + s) % N : c.first + s;
				break;
			case 8:
				c.first = c.first + s > N ? (c.first + s) % N : c.first + s;
				c.second = c.second - s < 1 ? N - s + c.second : c.second - s;
				break;
		}

		loc[c.first][c.second] = times;
		map[c.first][c.second] += 1;
	}
	times++;
}

void make_cloud() {
	for (auto c : clouds) {
		map[c.first][c.second] += inc(c.first, c.second);
	}
	clouds.clear();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] >= 2 && loc[i][j] != times - 1) {
				map[i][j] -= 2;
				clouds.push_back({ i, j });
			}
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int d, s, rains = 0;
	std::cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			std::cin >> map[i][j];
		}
	}

	clouds = { {N,1}, {N,2}, {N - 1,1},{N - 1,2} };

	for (int i = 0; i < M; i++) {
		std::cin >> d >> s;

		move(d, s);
		make_cloud();
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			rains += map[i][j];
		}
	}

	std::cout << rains;
}