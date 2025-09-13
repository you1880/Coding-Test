#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int T, N, a, b;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		std::cin >> N;
		std::vector<std::pair<int, int>> vec;
		int res = 1, x;

		for (int j = 0; j < N; j++) {
			std::cin >> a >> b;
			vec.push_back({ a,b });
		}

		std::sort(vec.begin(), vec.end());
		x = vec[0].second;

		for (int j = 1; j < vec.size(); j++) {
			if (vec[j].second < x) {
				res++;
				x = vec[j].second;
			}
		}

		std::cout << res << "\n";
	}
}