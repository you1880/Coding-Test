#include <iostream>
#include <vector>
#include <queue>

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

std::queue<std::pair<int, int>> melt_targets, check_targets;
int N, M, p = 0;


void init(std::vector<std::vector<int>>& cheese) {
	std::queue<std::pair<int, int>> q;
	std::vector<std::vector<bool>> visited(N + 2, std::vector<bool>(M + 2, false));

	q.push({ 1, 1 });
	visited[1][1] = true;
	cheese[1][1] = 2;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int a = x + dx[i];
			int b = y + dy[i];

			if (a <= 0 || b <= 0 || a > N || b > M || visited[a][b]) {
				continue;
			}

			visited[a][b] = true;

			if (cheese[a][b] == 1) {
				check_targets.push({ a, b });
			}
			else {
				q.push({ a, b });
				cheese[a][b] = 2;
			}
		}
	}
}

void melt(std::vector<std::vector<int>>& cheese) {
	while (!check_targets.empty()) {
		int t_r = check_targets.front().first;
		int t_c = check_targets.front().second;
		int cnt = 0;

		for (int i = 0; i < 4; i++) {
			if (cheese[t_r + dx[i]][t_c + dy[i]] == 2) {
				cnt++;
			}
		}

		if (cnt >= 2) {
			melt_targets.push({ t_r, t_c });
		}

		check_targets.pop();
	}

	while (!melt_targets.empty()) {
		int m_r = melt_targets.front().first;
		int m_c = melt_targets.front().second;
		
		cheese[m_r][m_c] = 2;
		p--;

		melt_targets.pop();
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int t = 0;
	std::cin >> N >> M;

	std::vector<std::vector<int>> cheese(N + 2, std::vector<int>(M + 2, 2));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			std::cin >> cheese[i][j];

			if (cheese[i][j] == 1) {
				p++;
			}
		}
	}

	while (true) {
		if (p == 0) {
			std::cout << t;

			return 0;
		}

		init(cheese);
		melt(cheese);

		t++;
	}
}