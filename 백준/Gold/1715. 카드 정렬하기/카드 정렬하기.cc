#include <iostream>
#include <vector>
#include <queue>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	int N, x, cnt = 0;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> x;

		pq.push(x);
	}

	if (pq.size() == 1) {
		std::cout << "0";
		return 0;
	}

	while (!pq.empty()) {
		int x1 = pq.top();
		pq.pop();
		int x2 = pq.top();
		pq.pop();

		int sum = x1 + x2;
		cnt += sum;

		if (pq.empty()) {
			break;
		}
		pq.push(sum);
	}
	std::cout << cnt;
}