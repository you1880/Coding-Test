#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int H, W, h, cnt = 0;
	std::cin >> H >> W;

	std::vector<std::vector<int>> map(H, std::vector<int>(W, 0));
	for (int i = 0; i < W; i++) {
		std::cin >> h;

		for (int j = H - h; j < H; j++) {
			map[j][i] = 1;
		}
	}

	for (auto row : map) {
		int left = -1, right = -1, w = 0;
		for (int i = 0; i < row.size(); i++) {
			if (row[i] && w % 2 == 0) {
				left = i;
				w++;
			}
			else if (row[i] && w % 2 == 1) {
				right = i;
				w++;
			}

			if (left != -1 && right != -1) {
				cnt += (right - left - 1);
				left = right;
				right = -1;
				w++;
			}
		}
	}
	std::cout << cnt;
}