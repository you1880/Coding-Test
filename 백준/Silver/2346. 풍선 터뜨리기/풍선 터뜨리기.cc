#include <iostream>
#include <deque>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::deque<std::pair<int, int>> dq;
	int N, x, mv = 0;
	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		std::cin >> x;
		dq.push_back({ x, i });
	}

	while (!dq.empty()) {				
		if (mv < 0) {
			for (int i = 0; i < -mv; i++) {
				std::pair<int, int> p = dq.back();
				dq.pop_back();
				dq.push_front(p);
			}
		}
		else {
			for (int i = 1; i < mv; i++) {		
				std::pair<int, int> p = dq.front();
				dq.pop_front();
				dq.push_back(p);
			}
		}

		mv = dq.front().first;
		std::cout << dq.front().second << " ";
		dq.pop_front();
	}
}