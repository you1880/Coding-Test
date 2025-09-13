#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, x, y;
	int sq = 0;
	std::cin >> N;

	std::vector<std::vector<int>> vec(100, std::vector<int>(100, 0));

	for (int i = 0; i < N; i++) {
		std::cin >> x >> y;

		for (int dx = x; dx < x + 10; dx++)
			for (int dy = y; dy < y + 10; dy++)
				vec[dx][dy] = 1;
	}

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (vec[i][j] == 1)
				sq++;
	std::cout << sq; 
}