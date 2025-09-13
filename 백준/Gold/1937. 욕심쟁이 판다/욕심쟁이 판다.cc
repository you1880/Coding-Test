#include <iostream>
#include <vector>
#define MAX 501

std::vector<std::vector<int>> forest(MAX, std::vector<int>(MAX));
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int dp[MAX][MAX];
int n, res = 0;

int sol(int r, int c) {
	if (dp[r][c] != 0) {
		return dp[r][c];
	}

	dp[r][c] = 1;

	for (int i = 0; i < 4; i++) {
		int nr = r + dx[i];
		int nc = c + dy[i];

		if (nr < 0 || nc < 0 || nr >= n || nc >= n) {
			continue;
		}

		if (forest[nr][nc] > forest[r][c]) {
			dp[r][c] = std::max(dp[r][c], sol(nr, nc) + 1);
		}
	}

	return dp[r][c];
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> forest[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int t = sol(i, j);
			res = t > res ? t : res;
		}
	}

	std::cout << res;
}