#include <iostream>
#include <vector>
#define MAX 52

std::vector<std::vector<int>> map(MAX, std::vector<int>(MAX, 1));
std::vector<std::vector<int>> trash(MAX, std::vector<int>(MAX, 1));
int N, M, r, c, d;
int count = 0;

void operate() {
	while (1) {
		if (trash[r][c] == 1) {
			trash[r][c] = 0;
			count++;
		}

		if (trash[r - 1][c] == 0 && trash[r][c + 1] == 0 && trash[r + 1][c] == 0 && trash[r][c - 1] == 0) {
			if ((d == 0 && map[r + 1][c] == 1) || (d == 1 && map[r][c - 1] == 1) || (d == 2 && map[r - 1][c] == 1) || (d == 3 && map[r][c + 1] == 1)) {
				break;
			}

			if (d == 0 && map[r + 1][c] == 0) {
				r += 1;
			}
			else if (d == 1 && map[r][c - 1] == 0) {
				c -= 1;
			}
			else if (d == 2 && map[r - 1][c] == 0) {
				r -= 1;
			}
			else if (d == 3 && map[r][c + 1] == 0) {
				c += 1;
			}
		}
		else {
			d = (d - 1) < 0 ? 3 : d - 1;

			if (d == 0 && map[r - 1][c] == 0 && trash[r - 1][c] == 1) {
				r -= 1;
			}
			else if (d == 1 && map[r][c + 1] == 0 && trash[r][c + 1] == 1) {
				c += 1;
			}
			else if (d == 2 && map[r + 1][c] == 0 && trash[r + 1][c] == 1) {
				r += 1;
			}
			else if (d == 3 && map[r][c - 1] == 0 && trash[r][c - 1] == 1) {
				c -= 1;
			}
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);
	
	std::cin >> N >> M >> r >> c >> d;
	r += 1;
	c += 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			std::cin >> map[i][j];

			if (map[i][j] == 1) {
				trash[i][j] = 0;
			}
		}
	}

	operate();

	std::cout << count;
}