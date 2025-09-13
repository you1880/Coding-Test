#include <iostream>
#include <vector>

std::vector<std::vector<int>> vec(11, std::vector<int>(11, 0));
std::vector<bool> selected(11, false);
int max = 0;

void func(int row, int sum) {
	if (row == 11) {
		max = sum > max ? sum : max;
		return;
	}

	for (int col = 0; col < 11; col++) {
		if (vec[row][col] == 0) {
			continue;
		}

		if (!selected[col]) {
			selected[col] = true;
			func(row + 1, sum + vec[row][col]);
			selected[col] = false;
		}
	}
}
int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int C;
	std::cin >> C;

	for (int tc = 0; tc < C; tc++) {
		for (int i = 0; i < 11; i++) {
			selected[i] = false;

			for (int j = 0; j < 11; j++) {
				std::cin >> vec[i][j];
			}
		}

		max = 0;
		func(0, 0);

		std::cout << max << "\n";
	}
}