#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	char op;
	std::cin >> N;

	std::vector<std::vector<int>> map(101, std::vector<int>(101, -1));
	std::vector<int> tmp;
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };
	int dir = 1, x = 50, y = 50;
	map[x][y] = 1;

	for (int i = 0; i < N; i++) {
		std::cin >> op;

		if (op == 'R') {
			++dir;
			dir = dir > 3 ? 0 : dir;
		}
		else if (op == 'L') {
			--dir;
			dir = dir < 0 ? 3 : dir;
		}
		else if (op == 'F') {
			x = x + dx[dir];
			y = y + dy[dir];

			if (map[x][y] == -1) {
				map[x][y] = 1;
			}
		}
	}

	int mx = 1000, Mx = 0;
	for (int i = 0; i < map.size(); i++) {
		if (std::find(map[i].begin(), map[i].end(), 1) != map[i].end()) {
			mx = mx > i ? i : mx;
			Mx = i > Mx ? i : Mx;
		}
	}

	for (int i = mx; i <= Mx; i++) {
		for (int j = 0; j < map.size(); j++) {
			if (map[i][j] == 1) {
				tmp.push_back(j);
			}
		}
	}
	
	std::sort(tmp.begin(), tmp.end());

	for (int i = mx; i <= Mx; i++) {
		for (int j = tmp[0]; j <= tmp[tmp.size() - 1]; j++) {
			if (map[i][j] == 1) {
				std::cout << ".";
			}
			else {
				std::cout << "#";
			}
		}
		std::cout << "\n";
	}
}