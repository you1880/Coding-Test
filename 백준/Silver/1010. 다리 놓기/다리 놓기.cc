#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T, N, M;
	std::cin >> T;

	long long arr[31][31] = {};
	arr[1][0] = 1;
	arr[1][1] = 1;

	for (int i = 2; i <= 30; i++) {
		arr[i][0] = 1;
		for (int j = 1; j <= 30; j++) {
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}

	for (int i = 0; i < T; i++) {
		std::cin >> N >> M;
		std::cout << arr[M][N] << "\n";
	}
}