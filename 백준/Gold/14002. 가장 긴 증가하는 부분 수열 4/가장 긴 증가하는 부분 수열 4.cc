#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	int N, x, idx, max = 0;
	std::cin >> N;

	std::vector<int> vec, nums;
	std::vector<std::pair<int, int>> p(N);

	for (int i = 0; i < N; i++) {
		std::cin >> x;
		vec.push_back(x);
		p[i] = { 1, i };
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i - 1; j++) {
			if (vec[j] < vec[i] && 1 + p[j].first > p[i].first) {
				p[i].first = 1 + p[j].first;
				p[i].second = j;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (p[i].first >= max) {
			max = p[i].first;
			idx = i;
		}
	}

	for (int i = max; i > 0; i--) {
		nums.push_back(vec[idx]);
		idx = p[idx].second;
	}

	std::cout << max << "\n";
	for (auto itr = nums.rbegin(); itr != nums.rend(); itr++) {
		std::cout << *itr << " ";
	}
}