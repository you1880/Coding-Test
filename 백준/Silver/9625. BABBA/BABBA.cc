#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int K, A = 1, B = 0;
	std::cin >> K;

	for (int i = 0; i < K; i++) {
		int tb = B;
		B = B + A;
		A = tb;
	}

	std::cout << A << " " << B;
}