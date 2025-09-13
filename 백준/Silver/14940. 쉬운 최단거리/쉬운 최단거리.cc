#include <iostream>
#include <queue>
#include <vector>

void bfs(int r, int c, std::vector<std::vector<std::pair<int, bool>>>& vec, std::vector<std::vector<int>>& ans) {
	std::queue<std::pair<int, int>> q;
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };

	q.push({ r, c });
	vec[r][c].second = true;
	ans[r][c] = 0;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int _x = a + dx[i];
			int _y = b + dy[i];

			if (_x < 0 || _y < 0 || _x >= vec.size() || _y >= vec[0].size() || vec[_x][_y].second || vec[_x][_y].first == 0) {
				continue;
			}

			vec[_x][_y].second = true;
			q.push({ _x, _y });
			ans[_x][_y] = ans[a][b] + 1;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M, r = 0, c = 0;
	std::cin >> N >> M;

	std::vector<std::vector<std::pair<int, bool>>> vec(N, std::vector<std::pair<int, bool>>(M, { 0, false }));
	std::vector<std::vector<int>> ans(N, std::vector<int>(M, -1));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> vec[i][j].first;

			if (vec[i][j].first == 2) {
				r = i;
				c = j;
			}
			if (vec[i][j].first == 0) {
				ans[i][j] = 0;
			}
		}
	}

	bfs(r, c, vec, ans);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cout << ans[i][j] << " ";
		}
		std::cout << "\n";
	}
}