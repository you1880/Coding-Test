#include <iostream>
#include <queue>

int map[3][3];
int N;
std::string res = "Hing";

void dfs(int x, int y) {
	if (x >= N || y >= N || map[x][y] == 0) {
		return;
	}

	if (x == N - 1 && y == N - 1) {
		res = "HaruHaru";
		return;
	}
	
	dfs(x + map[x][y], y);
	dfs(x, y + map[x][y]);
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> map[i][j];
		}
	}

	dfs(0, 0);

	std::cout << res;
}