#include <iostream>
#include <stack>

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	std::stack<int> stk;
	int N, x, c = 1;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> x;

		if (c == x) {
			c++;
			while (!stk.empty()) {
				if (stk.top() == c) {
					c++;
					stk.pop();
				}
				else {
					break;
				}
			}
		}
		else {
			stk.push(x);
		}
	}

	while (!stk.empty()) {
		if (stk.top() == c) {
			c++;
			stk.pop();
		}
		else {
			std::cout << "Sad";
			return 0;
		}
	}
	std::cout << "Nice";
}