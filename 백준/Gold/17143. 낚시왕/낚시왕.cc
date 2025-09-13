#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#define MAX 101

struct Shark {
	int row;
	int col;
	int speed;
	int dir;
	int size;

	Shark(int r, int c, int s, int d, int z)
		: row(r), col(c), speed(s), dir(d), size(z) {}
};

std::vector<std::vector<int>> grid(MAX, std::vector<int>(MAX, 0));
std::map<std::pair<int, int>, std::vector<Shark>> sharks;
int dr[] = { 0, -1, 1, 0, 0 };
int dc[] = { 0, 0, 0, 1, -1 };
int R, C, M;
int king_loc = 0, res = 0;

int compare(Shark& s1, Shark& s2) {
	return s1.size > s2.size;
}

void move_king() {
	king_loc++;
}

void catch_shark() {
	for (int r = 1; r <= R; r++) {
		if (grid[r][king_loc]) {
			auto itr = sharks.find({ r, king_loc });
			res += itr->second[0].size;

			sharks.erase(itr);
			grid[r][king_loc] = 0;
		
			break;
		}
	}
}

void move_shark() {
	std::queue<Shark> q;
	for (const auto& e : sharks) {
		q.push(e.second[0]);
		grid[e.second[0].row][e.second[0].col] = 0;
	}

	sharks.clear();

	while (!q.empty()) {
		Shark shark = q.front();
		q.pop();

		int speed = shark.speed;
		int dir = shark.dir;
		int row = shark.row;
		int col = shark.col;
		int size = shark.size;

		if (dir == 1 || dir == 2) {
			if (speed >= (R - 1) * 2) {
				speed = speed % ((R - 1) * 2);
			}

			for (int i = 0; i < speed; i++) {
				row += dr[dir];

				if (row < 1) {
					dir = 2;
					row += 2;
				}
				
				if (row > R) {
					dir = 1;
					row -= 2;
				}
			}
		}
		else if (dir == 3 || dir == 4) {
			if (speed >= (C - 1) * 2) {
				speed = speed % ((C - 1) * 2);
			}

			for (int i = 0; i < speed; i++) {
				col += dc[dir];

				if (col < 1) {
					dir = 3;
					col += 2;
				}

				if (col > C) {
					dir = 4;
					col -= 2;
				}
			}
		}

		grid[row][col]++;

		if (grid[row][col]) {
			sharks[{row, col}].push_back(Shark(row, col, speed, dir, size));
		}
		else {
			sharks[{row, col}] = std::vector<Shark> { Shark(row, col, speed, dir, size) };
		}
	}
}

void eat_shark() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (grid[i][j] > 1) {
				auto itr = sharks.find({ i, j });

				std::sort(itr->second.begin(), itr->second.end(), compare);

				Shark s = itr->second[0];
				itr->second = std::vector<Shark>{ s };
				
				grid[i][j] = 1;
			}
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int r, c, s, d, z;
	std::cin >> R >> C >> M;

	for (int i = 0; i < M; i++) {
		std::cin >> r >> c >> s >> d >> z;

		sharks[{r, c}] = std::vector<Shark>{ Shark(r, c, s, d, z) };
		grid[r][c] = 1;
	}

	while (1) {
		move_king();

		if (king_loc == C + 1) {
			break;
		}

		catch_shark();
		move_shark();
		eat_shark();
	}

	std::cout << res;
}