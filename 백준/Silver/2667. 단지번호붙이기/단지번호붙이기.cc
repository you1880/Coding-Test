#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

int BFS(int x, int y, std::vector<std::vector<bool>>& visited, std::vector<std::string>& house) {
	std::queue<std::pair<int, int>> q;
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	int cnt = 1;

	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int _x = a + dx[i];
			int _y = b + dy[i];
			if (_x < 0 || _y < 0 || _x >= visited.size() || _y >= visited.size()) {
				continue;
			}
			if (visited[_x][_y]) {
				continue;
			}
			if (house[_x][_y] == '0') {
				continue;
			}

			visited[_x][_y] = true;
			q.push({ _x,_y });
			cnt++;
		}
	}

	return cnt;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::vector<std::string> house;
	std::vector<int> vec;
	std::string str;
	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> str;
		house.push_back(str);
	}

	std::vector<std::vector<bool>> visited(N, std::vector<bool>(N, 0));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (house[i][j] == '1' && !visited[i][j]) {
				vec.push_back(BFS(i, j, visited, house));
			}
		}
	}

	std::sort(vec.begin(), vec.end());

	std::cout << vec.size() << "\n";
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << "\n";
	}
}