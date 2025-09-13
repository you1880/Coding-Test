#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	char c;
	int H, W;
	std::cin >> H >> W;

	std::vector<std::vector<std::pair<char, int>>> vec(H, std::vector<std::pair<char, int>>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			std::cin >> c;

			if (c == 'c') {
				vec[i][j] = { c, 0 };
			}
			else {
				vec[i][j] = { c, -1 };
			}
		}
	}

	for (int t = 1; t <= W; t++) {

		for (int i = 0; i < H; i++) {
			for (int j = W - 1; j >= 1; j--) {
				vec[i][j].first = vec[i][j - 1].first;

				if (vec[i][j].first == 'c' && vec[i][j].second == -1) {
					vec[i][j].second = t;
				}
			}
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			std::cout << vec[i][j].second << " ";
		}
		std::cout << "\n";
	}
}