#include <iostream>
#include <vector>
#define MAX 12

std::vector<std::vector<int>> vec(MAX, std::vector<int>(MAX, -1));
std::vector<std::vector<bool>> selected(MAX, std::vector<bool>(MAX, false));
int N, min = 10000;

int check_pos(int r, int c) {
	if (selected[r][c] || selected[r - 1][c] || selected[r + 1][c] || selected[r][c - 1] || selected[r][c + 1]) {
		return 0;
	}

	return 1;
}

void func(int cnt, std::vector<std::pair<int, int>> petals) {
	if (cnt == 3) {
		int sum = 0;

		for (auto& p : petals) {
			int r = p.first, c = p.second;
			sum += (vec[r][c] + vec[r - 1][c] + vec[r + 1][c] + vec[r][c - 1] + vec[r][c + 1]);
		}

		min = min > sum ? sum : min;

		return;
	}

	for (int i = 2; i <= N - 1; i++) {
		for (int j = 2; j <= N - 1; j++) {
			if (check_pos(i, j)) {
				selected[i][j] = true, selected[i - 1][j] = true, selected[i + 1][j] = true, selected[i][j - 1] = true, selected[i][j + 1] = true;
				petals.push_back({ i, j });
				func(cnt + 1, petals);
				selected[i][j] = false, selected[i - 1][j] = false, selected[i + 1][j] = false, selected[i][j - 1] = false, selected[i][j + 1] = false;
				petals.pop_back();
			}
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);
	
	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			std::cin >> vec[i][j];
		}
	}

	for (int i = 2; i <= N - 1; i++) {
		for (int j = 2; j <= N - 1; j++) {
			std::vector<std::pair<int, int>> petals = { {i, j} };
			selected[i][j] = true, selected[i - 1][j] = true, selected[i + 1][j] = true, selected[i][j - 1] = true, selected[i][j + 1] = true;
			func(1, petals);
			selected[i][j] = false, selected[i - 1][j] = false, selected[i + 1][j] = false, selected[i][j - 1] = false, selected[i][j + 1] = false;
		}
	}

	std::cout << min;
}