#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

struct Pos {
	int s;
	int e;

	Pos(int s, int e)
		: s(s), e(e) {}
};

bool compare(const std::pair<Pos, int>& p1, const std::pair<Pos, int>& p2) {
	return p1.first.s < p2.first.s;
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::vector<std::pair<Pos, int>> vec, res;
	int K, s, e, cost, min;
	std::cin >> K;

	for (int i = 0; i < K; i++) {
		std::cin >> s >> e >> cost;
		vec.push_back({ Pos(s, e), cost });
	}

	std::sort(vec.begin(), vec.end(), compare);

	s = vec[0].first.s, e = vec[0].first.e, min = vec[0].second;
	for (int i = 1; i < K; i++) {
		int costs = vec[i].second;

		if (vec[i].first.s > e) {
			res.push_back({ Pos(s, e), min });
			s = vec[i].first.s;
			e = vec[i].first.e;
			min = vec[i].second;
		}
		else {
			min = min > costs ? costs : min;
			if (vec[i].first.e > e) {
				e = vec[i].first.e;
			}
		}
	}

	res.push_back({ Pos(s, e), min });

	std::cout << res.size() << "\n";
	for (auto& e : res) {
		std::cout << e.first.s << " " << e.first.e << " " << e.second << "\n";
	}
}