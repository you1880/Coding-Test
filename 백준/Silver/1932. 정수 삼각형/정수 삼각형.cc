#include <iostream>
#include <vector>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int n, x;
	std::cin >> n;

	std::vector<std::vector<int>> vec(n), tmp;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			std::cin >> x;
			vec[i].push_back(x);
		}
	}

	if (n == 1) {
		std::cout << vec[0][0];
	}
	else {
		for (int i = n - 2; i >= 0; i--) {
			for (int j = 0; j < i + 1; j++) {
				vec[i][j] = vec[i][j] + std::max(vec[i + 1][j], vec[i + 1][j + 1]);
			}
		}
		std::cout << vec[0][0];
	}
}