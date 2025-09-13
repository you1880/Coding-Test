#include <iostream>
#include <vector>
#include <deque>
#define MAX 52

std::vector<std::pair<int, int>> loc;
std::vector<std::vector<int>> map(MAX, std::vector<int>(MAX, -10));
int R, C, T;
int dust = 0;

void diffusion() {
	std::vector<std::vector<int>> tmp(MAX, std::vector<int>(MAX, 0));

	for (int r = 0; r <= R + 1; r++) {
		for (int c = 0; c <= C + 1; c++) {
			if (map[r][c] < 0) {
				tmp[r][c] = map[r][c];
			}

			if (map[r][c] > 0) {
				int amt = map[r][c] / 5;
				int count = 0;
				if (map[r - 1][c] >= 0) {
					tmp[r - 1][c] += amt;
					count++;
				}
				if (map[r][c + 1] >= 0) {
					tmp[r][c + 1] += amt;
					count++;
				}
				if (map[r + 1][c] >= 0) {
					tmp[r + 1][c] += amt;
					count++;
				}
				if (map[r][c - 1] >= 0) {
					tmp[r][c - 1] += amt;
					count++;
				}

				tmp[r][c] += map[r][c] - amt * count;
			}
		}
	}
	map = tmp;
}

void up_circul() {
	int u_start = loc[0].first;
	int d_start = loc[1].first;
	
	int bef = map[u_start][2];
	map[u_start][2] = 0;

	for (int c = 3; c <= C; c++) {
		int tmp = map[u_start][c];
		map[u_start][c] = bef;
		bef = tmp;
	}

	for (int r = u_start - 1; r >= 1; r--) {
		int tmp = map[r][C];
		map[r][C] = bef;
		bef = tmp;
	}

	for (int c = C - 1; c >= 1; c--) {
		int tmp = map[1][c];
		map[1][c] = bef;
		bef = tmp;
	}

	for (int r = 2; ; r++) {
		if (map[r][1] == -1) {
			dust -= bef;
			break;
		}
		else {
			int tmp = map[r][1];
			map[r][1] = bef;
			bef = tmp;
		}
	}
}

void down_circul() {
	int d_start = loc[1].first;

	int bef = map[d_start][2];
	map[d_start][2] = 0;

	for (int c = 3; c <= C; c++) {
		int tmp = map[d_start][c];
		map[d_start][c] = bef;
		bef = tmp;
	}

	for (int r = d_start + 1; r <= R; r++) {
		int tmp = map[r][C];
		map[r][C] = bef;
		bef = tmp;
	}

	for (int c = C - 1; c >= 1; c--) {
		int tmp = map[R][c];
		map[R][c] = bef;
		bef = tmp;
	}

	for (int r = R - 1; ; r--) {
		if (map[r][1] == -1) {
			dust -= bef;
			break;
		}
		else {
			int tmp = map[r][1];
			map[r][1] = bef;
			bef = tmp;
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> R >> C >> T;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			std::cin >> map[i][j];

			if (map[i][j] == -1) {
				loc.push_back({ i, j });
			}
			else {
				dust += map[i][j];
			}
		}
	}

	for (int t = 0; t < T; t++) {
		diffusion();
		up_circul();
		down_circul();
	}

	std::cout << dust;
}