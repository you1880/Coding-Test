#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T, N, M, x;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		std::cin >> N >> M;
		int cnt = 0;
		std::queue<std::pair<int, int>> q;
		std::vector<int> vec;

		for (int j = 0; j < N; j++) {
			std::cin >> x;
			q.push({ j, x });
			vec.push_back(x);
		}

		std::sort(vec.begin(), vec.end());

		while (1) {
			if (q.front().second >= vec[vec.size() - 1]) {
				cnt++;
				if (q.front().first == M) {
					std::cout << cnt << "\n";
					break;
				}
				else {
					q.pop();
					vec.pop_back();
				}
			}
			else {
				std::pair<int, int> p = q.front();
				q.pop();
				q.push(p);
			}
		}
	}
}