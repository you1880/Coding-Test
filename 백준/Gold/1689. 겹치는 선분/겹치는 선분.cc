#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::vector<std::pair<int, int>> vec;
	int N, a, b, res = 1, tmp = 0;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> a >> b;
		vec.push_back({ a, 1 });
		vec.push_back({ b, -1 });
	}

	std::sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		if (vec[i].second == 1) {
			tmp++;
		}
		else if (vec[i].second == -1) {
			res = tmp > res ? tmp : res;
			tmp--;
		}
	}

	std::cout << res;
}