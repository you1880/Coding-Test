#include <iostream>
#include <vector>

std::vector<std::vector<std::pair<int, int>>> vec(5, std::vector<std::pair<int, int>>(5, { 0, 0 }));
std::vector<std::pair<int, int>> xy(26);

int check() {
	int r = 0;
	if (vec[0][0].second && vec[1][1].second && vec[2][2].second && vec[3][3].second && vec[4][4].second) {
		r++;
	}
	if (vec[4][0].second && vec[3][1].second && vec[2][2].second && vec[1][3].second && vec[0][4].second) {
		r++;
	}

	for (int i = 0; i < 5; i++) {
		if (vec[i][0].second && vec[i][1].second && vec[i][2].second && vec[i][3].second && vec[i][4].second) {
			r++;
		}
		if (vec[0][i].second && vec[1][i].second && vec[2][i].second && vec[3][i].second && vec[4][i].second) {
			r++;
		}
	}

	return r;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, cnt = 0, res = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			std::cin >> vec[i][j].first;

			xy[vec[i][j].first].first = i;
			xy[vec[i][j].first].second = j;
		}
	}
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			std::cin >> n;

			int x = xy[n].first;
			int y = xy[n].second;
			vec[x][y].second = 1;
			cnt++;

			if (cnt >= 12) {
				int r = check();
				
				if (r >= 3 && res==0) {
					res = cnt;
				}
			}
		}
	}
	std::cout << res;
}