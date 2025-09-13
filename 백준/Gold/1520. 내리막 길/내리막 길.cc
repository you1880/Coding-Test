#include <iostream>
#define MAX 501

int map[MAX][MAX];
int dp[MAX][MAX];
int N, M;
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };

int dfs(int r, int c) {
	if (r == M - 1 && c == N - 1) {
		return 1;
	}

	if (dp[r][c] != -1) {
		return dp[r][c];
	}
	
	dp[r][c] = 0;

	for (int i = 0; i < 4; i++) {
		int _r = r + dr[i];
		int _c = c + dc[i];

		if (_r < 0 || _r >= M || _c < 0 || _c >= N || map[_r][_c] >= map[r][c]) {
			continue;
		}

		dp[r][c] = dp[r][c] + dfs(_r, _c);
	}

	return dp[r][c];
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> M >> N;

	for (int r = 0; r < M; r++) {
		for (int c = 0; c < N; c++) {
			std::cin >> map[r][c];
			dp[r][c] = -1;
		}
	}

	std::cout << dfs(0, 0);
}