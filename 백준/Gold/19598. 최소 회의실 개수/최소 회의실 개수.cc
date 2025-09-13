#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	std::vector<std::pair<int, int>> vec;
	int N, a, b;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> a >> b;
		vec.push_back({ a, b });
	}

	std::sort(vec.begin(), vec.end());
	pq.push(vec[0].second);

	for (int i = 1; i < N; i++) {
		pq.push(vec[i].second);

		if (pq.top() <= vec[i].first) {
			pq.pop();
		}
	}

	std::cout << pq.size();
}