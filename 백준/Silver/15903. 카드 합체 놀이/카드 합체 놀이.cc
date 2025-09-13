#include <iostream>
#include <queue>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;

	long long n, m, x, a, b, sum = 0;
	std::cin >> n >> m;

	for (int i = 0; i < n; i++) {
		std::cin >> x;
		pq.push(x);
	}

	for (int i = 0; i < m; i++) {
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();

		pq.push(a + b);
		pq.push(a + b);
	}

	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}
	std::cout << sum;
}