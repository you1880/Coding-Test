#include <iostream>
#include <queue>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int N, x;
	std::cin >> N;
	
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	for (int i = 0; i < N; i++) {
		std::cin >> x;

		if (x == 0) {
			if (pq.empty()) {
				std::cout << "0\n";
			}
			else {
				std::cout << pq.top().second << "\n";
				pq.pop();
			}
		}
		else {
			pq.push({ std::abs(x), x });
		}
	}
}