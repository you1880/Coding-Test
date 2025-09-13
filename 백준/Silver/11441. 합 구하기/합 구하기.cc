#include <iostream>

int arr[100001];

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int N;
	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		std::cin >> arr[i];

		arr[i] = arr[i] + arr[i - 1];
	}

	int M, x, y;
	std::cin >> M;

	for (int i = 0; i < M; i++) {
		std::cin >> x >> y;

		std::cout << arr[y] - arr[x - 1] << "\n";
	}
}