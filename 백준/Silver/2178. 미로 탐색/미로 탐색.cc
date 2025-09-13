#include <iostream>
#include <queue>
#include <vector>

void bfs(int n, int m, std::vector<std::vector<int>> maze, std::vector<std::vector<bool>>& visited, std::vector<std::vector<int>>& dis){
	std::queue<std::pair<int, int>> que;
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	
	int cnt = 1;
	que.push({ 0,0 });
	visited[0][0] = true;

	while (!que.empty()) {			
		int a = que.front().first;
		int b = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int _x = a + dx[i];
			int _y = b + dy[i];

			if (_x < 0 || _y < 0 || _x >= n || _y >= m) {
				continue;
			}

			if (visited[_x][_y]) {
				continue;
			}

			if (maze[_x][_y] == 0) {
				continue;
			}

			visited[_x][_y] = true;
			dis[_x][_y] = dis[a][b] + 1;
			que.push({ _x,_y });
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::string line;
	int N, M;
	std::cin >> N >> M;
	
	std::vector<std::vector<int>> maze;
	std::vector<std::vector<bool>> visited(N, std::vector<bool>(M, false));
	std::vector<std::vector<int>> dis(N, std::vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		std::vector<int> tmp;
		std::cin >> line;
		
		for (auto c : line) {
			tmp.push_back(c - '0');
		}
		maze.push_back(tmp);
	}

	bfs(N, M, maze, visited, dis);

	std::cout << dis[N - 1][M - 1] + 1;
}