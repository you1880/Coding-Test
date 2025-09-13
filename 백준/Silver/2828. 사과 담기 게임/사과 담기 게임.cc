#include <iostream>

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	int N, M, j, res = 0, left, right, loc;
	std::cin >> N >> M;

	left = 1, right = left + (M - 1);

	std::cin >> j;

	for (int i = 0; i < j; i++) {
		std::cin >> loc;

		if (loc >= left && loc <= right) {
			continue;
		}

		if (loc > right) {
			res += loc - right;
			right = loc;
			left = right - (M - 1);
		}
		else if (loc < left) {
			res += left - loc;
			left = loc;
			right = left + (M - 1);
		}
	}
	std::cout << res;
}