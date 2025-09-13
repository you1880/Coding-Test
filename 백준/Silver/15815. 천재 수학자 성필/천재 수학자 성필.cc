#include <iostream>
#include <stack>

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	std::stack<int> stk;
	std::string str;
	std::cin >> str;
	int res = 0, a, b;

	for (auto c : str) {
		if (c >= '0' && c <= '9') {
			stk.push(c - '0');
		}
		else {
			a = stk.top();
			stk.pop();
			b = stk.top();
			stk.pop();

			if (c == '+') {
				stk.push(b + a);
			}
			else if (c == '-') {
				stk.push(b - a);
			}
			else if (c == '*') {
				stk.push(b * a);
			}
			else if (c == '/') {
				stk.push(b / a);
			}
		}
	}
	std::cout << stk.top();
}