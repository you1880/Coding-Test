#include <iostream>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int P;
	std::cin >> P;

	for (int i = 0; i < P; i++) {
		int T, cnt = 0;
		int arr[21] = { 0, };

		std::cin >> T;

		for (int j = 0; j < 20; j++) {
			std::cin >> arr[j];
		}

		for (int j = 0; j < 20; j++) {
			for (int k = j + 1; k < 20; k++) {
				if (arr[j] > arr[k]) cnt++;
			}
		}

		std::cout << i + 1 << " " << cnt << "\n";
	}
}