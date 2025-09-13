#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int X, cnt = 0;
	std::cin >> X;

	while (X != 0) {
		if (X % 2 == 1) {
			cnt++;
		}
		X /= 2;
	}

	std::cout << cnt;
}