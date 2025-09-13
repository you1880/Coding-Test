#include <iostream>
#include <vector>
#define MAX 51

int N, M;
std::vector<std::string> map;
int visited[MAX][MAX];
int d[2] = { 1, -1 };

void dfs(int x, int y) {
	if (visited[x][y]) {
		return;
	}

	visited[x][y] = 1;

	for (int i = 0; i < 2; i++) {
		if (map[x][y] == '-') {
			int _y = y + d[i];

			if (_y < 0 || _y >= M || map[x][_y] == '|') {
				return;
			}
			dfs(x, _y);
		}
		else if (map[x][y] == '|') {
			int _x = x + d[i];

			if (_x < 0 || _x >= N || map[_x][y] == '-') {
				return;
			}
			dfs(_x, y);
		}
	}
}
int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);
	
	int cnt = 0;
	std::string line;
	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		std::cin >> line;
		map.push_back(line);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}

	std::cout << cnt;
}