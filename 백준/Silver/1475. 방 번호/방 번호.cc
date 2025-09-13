#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int max = 0;
	std::string N;
	std::cin >> N;
	int arr[9] = { 0, };

	for (auto c : N) {
		if (c == '9') {
			arr[6]++;
		}
		else {
			arr[c - '0']++;
		}
	}

	arr[6] = (arr[6] + 1) / 2;

	for (int i = 0; i < 9; i++) {
		max = arr[i] > max ? arr[i] : max;
	}
	std::cout << max;
}