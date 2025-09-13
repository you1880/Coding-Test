#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::vector<std::pair<int, int>> vec;
	int N, L, a, b, ans = 0;

	std::cin >> N >> L;
	for (int i = 0; i < N; i++) {
		std::cin >> a >> b;

		vec.push_back({ a, b });
	}

	std::sort(vec.begin(), vec.end());

	a = 0;
	for (int i = 0; i < N; i++) {
		if (a < vec[i].first) {
			a = vec[i].first;
		}

		while (a < vec[i].second) {
			a += L;
			ans++;
		}
	}

	std::cout << ans;
}