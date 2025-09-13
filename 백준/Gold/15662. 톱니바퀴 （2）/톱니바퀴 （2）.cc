#include <iostream>
#include <vector>
#define MAX 1001

std::vector<std::string> gears(MAX);
int T, K;

void rot(int target, int dir, std::vector<bool> visited, std::vector<std::pair<int, int>>& rots) {
	if (target > 1 && !visited[target - 1] && gears[target - 1][2] != gears[target][6]) {
		visited[target - 1] = true;
		rots.push_back({ target - 1, dir * -1 });
		rot(target - 1, dir * -1, visited, rots);
	}

	if (target < T && !visited[target + 1] && gears[target + 1][6] != gears[target][2]) {
		visited[target + 1] = true;
		rots.push_back({ target + 1, dir * -1 });
		rot(target + 1, dir * -1, visited, rots);
	}
}

std::string change_gear(std::pair<int, int> r) {
	std::string tmp;

	if (r.second == 1) {
		tmp += gears[r.first][7];
		tmp += gears[r.first].substr(0, 7);	

	}
	else {
		tmp += gears[r.first].substr(1, 7);
		tmp += gears[r.first][0];
	}

	return tmp;
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int res = 0;

	std::cin >> T;

	for (int i = 1; i <= T; i++) {
		std::cin >> gears[i];
	}

	std::cin >> K;

	for (int i = 0; i < K; i++) {
		int target, dir;
		std::vector<bool> visited(T + 1);
		std::vector<std::pair<int, int>> rots;

		std::cin >> target >> dir;
		visited[target] = true;
		rots.push_back({ target, dir });

		rot(target, dir, visited, rots);

		if (!rots.empty()) {
			for (auto& e : rots) {
				gears[e.first] = change_gear(e);
			}
		}
	}

	for (int i = 1; i <= T; i++) {
		if (gears[i][0] == '1') {
			res++;
		}
	}

	std::cout << res;
}