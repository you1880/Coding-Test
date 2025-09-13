#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::vector<std::pair<long long, long long>> vec;
	int N, M;
	long long a, b, res = 0;
	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		std::cin >> a >> b;

		if (a > b) {
			vec.push_back({ b, a });
		}
	}

	res = M;

	if (!vec.empty()) {
		std::sort(vec.begin(), vec.end());

		a = vec[0].first, b = vec[0].second;

		for (int i = 1; i < vec.size(); i++) {
			if (vec[i].first > b) {
				res += 2 * (b - a);
				a = vec[i].first;
				b = vec[i].second;
			}
			else {
				if (vec[i].second > b) {
					b = vec[i].second;
				}
			}
		}	

		res += 2 * (b - a);
	}

	std::cout << res;
}