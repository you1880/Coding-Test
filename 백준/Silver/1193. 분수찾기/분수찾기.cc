#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int X, d = 0;
	std::cin >> X;

	while (X > 0) {
		d++;
		X -= d;
	}

	if (d & 1)
		std::cout << 1 - X << "/" << d + X;
	else
		std::cout << d + X << "/" << 1 - X;
}