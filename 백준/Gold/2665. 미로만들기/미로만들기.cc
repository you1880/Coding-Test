#include <iostream>
#include <vector>
#include <deque>
#define MAX 51

int n;
int dist[MAX][MAX];
std::vector<std::string> map;

void bfs() {
	std::deque<std::pair<int, int>> dq;
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	dist[0][0] = 0;
	dq.push_back({ 0,0 });

	while (!dq.empty()) {
		int a = dq.front().first;
		int b = dq.front().second;
		dq.pop_front();

		for (int i = 0; i < 4; i++) {
			int _x = a + dx[i];
			int _y = b + dy[i];

			if (_x < 0 || _y < 0 || _x >= n || _y >= n || dist[_x][_y] != 1e9) {
				continue;
			}

			if (map[_x][_y] == '0') {
				dist[_x][_y] = dist[a][b] + 1;
				dq.push_back({ _x, _y });
			}

			if (map[_x][_y] == '1') {
				dist[_x][_y] = dist[a][b];
				dq.push_front({ _x, _y });
			}
		}
	}
}

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	std::string line;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			dist[i][j] = 1e9;
		}
	}
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> line;
		map.push_back(line);
	}

	bfs();

	std::cout << dist[n - 1][n - 1];
}