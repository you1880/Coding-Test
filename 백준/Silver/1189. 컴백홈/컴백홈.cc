#include <iostream>
#include <vector>
#define MAX 5

std::vector<std::vector<char>> map(MAX, std::vector<char>(MAX));
std::vector<std::vector<bool>> visited(MAX, std::vector<bool>(MAX, false));
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int R, C, K, res = 0;

void dfs(int x, int y, int cnt) {
	if (cnt == K) {
		if (x == 0 && y == C - 1) {
			res++;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int a = x + dx[i];
		int b = y + dy[i];

		if (a < 0 || b < 0 || a >= R || b >= C || visited[a][b] || map[a][b] == 'T') {
			continue;
		}

		visited[a][b] = true;
		dfs(a, b, cnt + 1);
		visited[a][b] = false;
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> R >> C >> K;

	for (int i = 0; i < R; i++) {
		std::string line;
		std::cin >> line;
		
		for (int j = 0; j < C; j++) {
			map[i][j] = line[j];
		}
	}

	visited[R - 1][0] = true;
	dfs(R - 1, 0, 1);
	
	std::cout << res;
}