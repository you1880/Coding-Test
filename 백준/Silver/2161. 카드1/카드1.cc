#include <iostream>
#include <deque>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::deque<int> dq;
	int N;
	std::cin >> N;

	for (int i = N; i >= 1; i--) {
		dq.push_back(i);
	}

	while (1) {
		std::cout << dq.back() << " ";
		dq.pop_back();

		if (!dq.empty()) {
			int top = dq.back();
			dq.pop_back();
			dq.push_front(top);
		}
		else {
			break;
		}
	}
}