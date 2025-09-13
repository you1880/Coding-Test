#include <iostream>
#include <vector>

std::vector<std::vector<char>> vec(12, std::vector<char>(12, '.'));
std::vector<std::vector<char>> map(12, std::vector<char>(12, '.'));

int check(int x, int y) {
	int cnt = 0;
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };

	for (int i = 0; i < 4; i++) {
		int cx = x + dx[i];
		int cy = y + dy[i];

		if (vec[cx][cy] == '.') {
			cnt++;
		}
	}
	
	return cnt;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);


	int R, C, min_r = 100, min_c = 100, max_r = 0, max_c = 0;
	std::cin >> R >> C;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			std::cin >> vec[i][j];
		}
	}

	map = vec;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (vec[i][j] == 'X' && check(i, j) >= 3) {
				map[i][j] = '.';
			}
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] == 'X') {
				min_r = std::min(min_r, i);
				min_c = std::min(min_c, j);
				max_r = std::max(max_r, i);
				max_c = std::max(max_c, j);
			}
		}
	}

	for (int i = min_r; i <= max_r; i++) {
		for (int j = min_c; j <= max_c; j++) {
			std::cout << map[i][j];
		}
		std::cout << "\n";
	}
}