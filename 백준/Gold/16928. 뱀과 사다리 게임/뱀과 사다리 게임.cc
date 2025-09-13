#include <iostream>
#include <vector>
#include <queue>
#define MAX 101

std::vector<std::pair<int, int>> board(MAX);
std::vector<int> dist(MAX, 0);
int N, M;

void bfs() {
	std::queue<std::pair<int, int>> q;

	q.push({ 1, 0 });
	dist[1] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int depth = q.front().second;
		q.pop();

		if (x == 100) {
			std::cout << depth;
			return;
		}

		for (int i = 1; i <= 6; i++) {
			int a = x + i;

			if (a > 100 || dist[a]) {
				continue;
			}

			if (board[a].first == 1 || board[a].first == -1) {
				a = board[a].second;
			}

			q.push({ a, depth + 1 });
			dist[a] = 1;

		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int x, y;

	std::cin >> N >> M;
	for (int i = 0; i < N; i++) {
		std::cin >> x >> y;

		board[x].first = 1;
		board[x].second = y;
	}

	for (int i = 0; i < M; i++) {
		std::cin >> x >> y;

		board[x].first = -1;
		board[x].second = y;
	}

	bfs();
}