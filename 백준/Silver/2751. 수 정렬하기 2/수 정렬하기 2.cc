#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, n;
	std::cin >> N;
	
	std::vector<int> vec;

	for (int i = 0; i < N; i++) {
		std::cin >> n;
		vec.push_back(n);
	}
	std::sort(vec.begin(), vec.end());

	for (auto e : vec)
		std::cout << e << '\n';
}