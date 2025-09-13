#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);
	
	int N, count = 1, tmp;;
	std::cin >> N;

	std::vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];
	}
	
	std::sort(arr.begin(), arr.end(), std::greater<int>());

	tmp = arr[0];
	for (int i = 1; i < N; i++) {
		count++;
		tmp = arr[i] * count > tmp ? arr[i] * count : tmp;
	}
	std::cout << tmp;
}