#include <iostream>
#include <queue>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::priority_queue<int> pq;
	int n, loc, x;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::cin >> loc;

		if (loc == 0) {
			if (pq.empty()) {
				std::cout << -1 << "\n";
			}
			else {
				std::cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			for (int j = 0; j < loc; j++) {
				std::cin >> x;
				pq.push(x);
			}
		}
	}
}