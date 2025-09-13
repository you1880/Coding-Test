#include <iostream>
#include <deque>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::deque<int> dq;
	std::string op;

	int N, x;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> op;

		if (op == "push_front") {
			std::cin >> x;
			dq.push_front(x);
		}
		else if (op == "push_back") {
			std::cin >> x;
			dq.push_back(x);
		}
		else if (op == "pop_front") {
			if (dq.empty())
				std::cout << "-1\n";
			else {
				std::cout << dq.front() << "\n";
				dq.pop_front();
			}
		}
		else if (op == "pop_back") {
			if (dq.empty())
				std::cout << "-1\n";
			else {
				std::cout << dq.back() << "\n";
				dq.pop_back();
			}
		}
		else if (op == "size") {
			std::cout << dq.size() << "\n";
		}
		else if (op == "empty") {
			std::cout << dq.empty() << "\n";
		}
		else if (op == "front") {
			if (dq.empty())
				std::cout << "-1\n";
			else {
				std::cout << dq.front() << "\n";
			}
		}
		else if (op == "back") {
			if (dq.empty())
				std::cout << "-1\n";
			else {
				std::cout << dq.back() << "\n";
			}
		}
	}
}