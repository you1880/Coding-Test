#include <iostream>
#include <vector>
#include <queue>

#define LIMIT 1000000

std::vector<std::vector<std::vector<char>>> building(30, std::vector<std::vector<char>>(30, std::vector<char>(30)));
int dx[] = { 1,-1,0,0,0,0 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };
int L, R, C;
int escape_time = LIMIT, sx, sy, sz;

struct pos {
	int l;
	int r;
	int c;

	pos(int l, int r, int c)
		: l(l), r(r), c(c) { }
};

void bfs(int l, int r, int c, std::vector<std::vector<std::vector<int>>>& visited) {
	std::queue<pos> q;

	q.push(pos(l, r, c));
	visited[l][r][c] = 1;

	while (!q.empty()) {
		int x = q.front().r;
		int y = q.front().c;
		int z = q.front().l;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int a = x + dx[i];
			int b = y + dy[i];
			int c = z + dz[i];

			if (a < 0 || b < 0 || c < 0 || a >= R || b >= C || c >= L || visited[c][a][b] != 0 || building[c][a][b] == '#') {
				continue;
			}

			if (building[c][a][b] == 'E') {
				escape_time = escape_time > visited[z][x][y] ? visited[z][x][y] : escape_time;
			}
			else if (building[c][a][b] == '.') {			
				visited[c][a][b] = visited[z][x][y] + 1;
				q.push(pos(c, a, b));
			}
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	while (1) {
		std::cin >> L >> R >> C;

		if (L == 0 && R == 0 && C == 0) {
			return 0;
		}

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					std::cin >> building[i][j][k];

					if (building[i][j][k] == 'S') {
						sz = i;
						sx = j;
						sy = k;
					}
				}
			}
		}

		std::vector<std::vector<std::vector<int>>> visited(L, std::vector<std::vector<int>>(R, std::vector<int>(C, 0)));
		escape_time = LIMIT;

		bfs(sz, sx, sy, visited);
		if (escape_time == LIMIT) {
			std::cout << "Trapped!\n";
		}
		else {
			std::cout << "Escaped in " << escape_time << " minute(s).\n";
		}
	}
}