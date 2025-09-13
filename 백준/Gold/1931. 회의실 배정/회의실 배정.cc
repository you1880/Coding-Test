#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::vector<std::pair<int, int>> vec;
	int N, a, b, cnt = 1;
	
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> a >> b;
		vec.push_back({ b, a });
	}
	
	std::sort(vec.begin(), vec.end());

	int end = vec[0].first;

	for (int i = 1; i < vec.size(); i++) {
		if (vec[i].second >= end) {
			cnt++;
			end = vec[i].first;
		}
	}
	std::cout << cnt;
}