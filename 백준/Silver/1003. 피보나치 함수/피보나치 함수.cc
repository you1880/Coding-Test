#include <iostream>

int main() {
	int T, N;
	int arr[41] = { 0,1,1 };
	for (int i = 3; i < 41; i++)
		arr[i] = arr[i - 1] + arr[i - 2];
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		std::cin >> N;
		if (N == 0)
			std::cout << "1 0" << std::endl;
		else if (N == 1)
			std::cout << "0 1" << std::endl;
		else
			std::cout << arr[N - 1] << " " << arr[N] << std::endl;
	}
}