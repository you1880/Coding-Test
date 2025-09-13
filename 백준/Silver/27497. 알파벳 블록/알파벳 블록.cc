#include <iostream>
#include <deque>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::deque<std::pair<char, int>> dq;
	int N, x;
	char c;
	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		std::cin >> x;
		if (x == 1) {
			std::cin >> c;

			dq.push_back({ c, i });
		}
		else if (x == 2) {
			std::cin >> c;

			dq.push_front({ c, i });
		}
		else {
			if (dq.empty()) {
				continue;
			}

			if (dq.front().second >= dq.back().second) {
				dq.pop_front();
			}
			else {
				dq.pop_back();
			}
		}
	}

	if (dq.empty()) {
		std::cout << 0;
	}
	else {
		while (!dq.empty()) {
			std::cout << dq.front().first;
			dq.pop_front();
		}
	}
}