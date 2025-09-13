#include <iostream>
int arr[1000001] = { 0, };

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int M, N;
	std::cin >> M >> N;

	for (int i = 2; i < 1000001; i++) {
		arr[i] = i;
	}

	for (int i = 2; i < 1000001; i++) {
		if (arr[i] == 0) {
			continue;
		}

		for (int j = 2 * i; j < 1000001; j += i) {
			arr[j] = 0;
		}
	}

	for (int i = M; i <= N; i++) {
		if (arr[i] != 0) {
			std::cout << arr[i] << "\n";
		}
	}
}