#include <iostream>
#include <deque>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::deque<int> dq;
	int N, cmd, x;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> cmd;

		switch (cmd) {
			case 1:
				std::cin >> x;
				dq.push_front(x);

				break;
			case 2:
				std::cin >> x;
				dq.push_back(x);

				break;
			case 3:
				if (dq.empty()) {
					std::cout << "-1\n";
				}
				else {
					std::cout << dq.front() << "\n";
					dq.pop_front();
				}

				break;
			case 4:
				if (dq.empty()) {
					std::cout << "-1\n";
				}
				else {
					std::cout << dq.back() << "\n";
					dq.pop_back();
				}

				break;
			case 5:
				std::cout << dq.size() << "\n";

				break;
			case 6:
				if (dq.empty()) {
					std::cout << "1\n";
				}
				else {
					std::cout << "0\n";
				}

				break;
			case 7:
				if (dq.empty()) {
					std::cout << "-1\n";
				}
				else {
					std::cout << dq.front() << "\n";
				}

				break;
			case 8:
				if (dq.empty()) {
					std::cout << "-1\n";
				}
				else {
					std::cout << dq.back() << "\n";
				}
		}
	}
}