#include <iostream>
#include <queue>

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	std::priority_queue<int> pq;
	int N, M, x;
	std::cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		std::cin >> x;
		pq.push(x);
	}

	for (int i = 0; i < M; i++) {
		std::cin >> x;

		if (pq.empty() || pq.top() < x) {
			std::cout << "0";
			return 0;
		}

		if (pq.top() > x) {
			int tmp = pq.top();
			pq.pop();
			pq.push(tmp - x);
		}
		else if (pq.top() == x) {
			pq.pop();
		}
	}
	std::cout << "1";
}