#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int N;
	std::cin >> N;

	std::vector<int> arr(N);
	
	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];
	}

	if (std::next_permutation(arr.begin(), arr.end())) {
		for (int i = 0; i < N; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << "\n";
	}
	else {
		std::cout << -1;
	}
}