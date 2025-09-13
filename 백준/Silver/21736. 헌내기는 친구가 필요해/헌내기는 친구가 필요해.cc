#include <iostream>
#include <vector>
#include <queue>

int N, M;

int bfs(int x, int y, std::vector<std::vector<char>>& graph) {
	std::vector<std::vector<bool>> visited(N, std::vector<bool>(M, false));
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	int cnt = 0;
	std::queue<std::pair<int, int>> q;

	q.push({ x,y });
	visited[x][y] = true;
	
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int _x = a + dx[i];
			int _y = b + dy[i];

			if (_x < 0 || _y < 0 || _x >= N || _y >= M || visited[_x][_y] || graph[_x][_y] == 'X') {
				continue;
			}

			q.push({ _x,_y });
			visited[_x][_y] = true;

			if (graph[_x][_y] == 'P') {
				cnt++;
			}
		}
	}

	return cnt;
}

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	std::cin >> N >> M;

	int x, y;
	std::string str;
	std::vector<std::vector<char>> map(N, std::vector<char>(M));

	for (int i = 0; i < N; i++) {
		std::cin >> str;

		for (int j = 0; j < M; j++) {
			map[i][j] = str[j];

			if (str[j] == 'I') {
				x = i, y = j;
			}
		}
	}

	int p = bfs(x, y, map);
	if (p) {
		std::cout << p;
	}
	else {
		std::cout << "TT";
	}
}