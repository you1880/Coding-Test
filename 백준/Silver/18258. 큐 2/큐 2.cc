#include <iostream>
#include <queue>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::queue<int> q;
	int N, x;
	std::string op;

	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> op;

		if (op == "push") {
			std::cin >> x;
			q.push(x);
		}
		else if (op == "pop") {
			if (q.empty()) {
				std::cout << "-1\n";
			}
			else {
				std::cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (op == "size") {
			std::cout << q.size() << "\n";
		}
		else if (op == "empty") {
			std::cout << (q.empty() ? 1 : 0) << "\n";
		}
		else if (op == "front") {
			std::cout << (q.empty() ? -1 : q.front()) << "\n";
		}
		else if (op == "back") {
			std::cout << (q.empty() ? -1 : q.back()) << "\n";
		}
	}
}