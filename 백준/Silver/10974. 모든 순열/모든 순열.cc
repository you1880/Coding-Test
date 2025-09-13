#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int N;
	std::cin >> N;

	std::vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		arr[i] = i + 1;
	}

	do {
		for (int i = 0; i < N; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << "\n";
	} while (std::next_permutation(arr.begin(), arr.end()));
}