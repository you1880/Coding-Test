#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);
	
	int N;
	std::cin >> N;

	std::vector<int> vec(N);

	for (int i = 0; i < N; i++) {
		std::cin >> vec[i];
	}

	std::sort(vec.begin(), vec.end(), std::greater<int>());

	for (int i = 0; i < N; i++) {
		vec[i] += i;
	}

	std::sort(vec.begin(), vec.end(), std::greater<int>());
	std::cout << vec[0] + 2;

}