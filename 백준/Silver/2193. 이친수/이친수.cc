#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	long long arr[91] = { 0, 1, 1 };
	int N;
	
	for (int i = 3; i <= 90; i++) {
		arr[i] = arr[i - 2] + arr[i - 1];
	}

	std::cin >> N;
	
	std::cout << arr[N] << "\n";
}