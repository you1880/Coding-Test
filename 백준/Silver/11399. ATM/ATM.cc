#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::vector<int> vec;
	int N, p, sum = 0;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> p;
		vec.push_back(p);
	}

	std::sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j <= i; j++) {
			sum += vec[j];
		}
	}
	
	std::cout << sum;
}