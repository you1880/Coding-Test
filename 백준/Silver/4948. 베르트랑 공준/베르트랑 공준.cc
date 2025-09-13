#include <iostream>
int arr[246913] = { 0, };

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n;

	for (int i = 2; i < 246913; i++) {
		arr[i] = i;
	}

	for (int i = 2; i < 246913; i++) {
		if (arr[i] == 0) {
			continue;
		}

		for (int j = 2 * i; j < 246913; j += i) {
			arr[j] = 0;
		}
	}

	while (1) {
		int cnt = 0;
		std::cin >> n;
		if (n == 0) {
			break;
		}

		for (int i = n + 1; i <= 2 * n; i++) {
			if (arr[i] != 0) {
				cnt++;
			}
		}
		std::cout << cnt << "\n";
	}
}