#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int fig[7] = { 0, };
	int dx[5] = { 0, 0, 0, -1, 1 };
	int dy[5] = { 0, 1, -1, 0, 0 };

	int N, M, x, y, K, cmd;
	std::cin >> N >> M >> x >> y >> K;

	std::vector<std::vector<int>> map(N, std::vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		std::cin >> cmd;

		int _x = x + dx[cmd];
		int _y = y + dy[cmd];

		if (_x < 0 || _y < 0 || _x >= map.size() || _y >= map[0].size()) {
			continue;
		}

		int tmp[7];
		std::copy(std::begin(fig), std::end(fig), std::begin(tmp));

		if (cmd == 1) {
			tmp[5] = fig[1];
			tmp[6] = fig[5];
			tmp[1] = fig[3];
			tmp[3] = fig[6];
		}
		else if (cmd == 2) {
			tmp[1] = fig[5];
			tmp[3] = fig[1];
			tmp[6] = fig[3];
			tmp[5] = fig[6];
		}
		else if (cmd == 3) {
			tmp[1] = fig[4];
			tmp[4] = fig[6];
			tmp[6] = fig[2];
			tmp[2] = fig[1];
		}
		else if (cmd == 4) {
			tmp[1] = fig[2];
			tmp[4] = fig[1];
			tmp[6] = fig[4];
			tmp[2] = fig[6];
		}

		if (map[_x][_y] == 0) {
			map[_x][_y] = tmp[6];
		}
		else {
			tmp[6] = map[_x][_y];
			map[_x][_y] = 0;
		}

		std::cout << tmp[1] << " ";
		std::copy(std::begin(tmp), std::end(tmp), std::begin(fig));
		x = _x, y = _y;
	}
}