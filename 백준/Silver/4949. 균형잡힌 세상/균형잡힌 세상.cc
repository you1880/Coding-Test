#include <iostream>
#include <string>
#include <stack>

void isBalanced(std::string str) {
	std::stack<char> stk;

	for (auto c : str) {
		if (c == '(' || c == '[') {
			stk.push(c);
		}
		else if (c == ')') {
			if (stk.empty() || stk.top() != '(') {
				std::cout << "no\n";
				break;
			}
			stk.pop();
		}
		else if (c == ']') {
			if (stk.empty() || stk.top() != '[') {
				std::cout << "no\n";
				break;
			}
			stk.pop();
		}
		else if (c == '.') {
			if (stk.empty()) {
				std::cout << "yes\n";
			}
			else {
				std::cout << "no\n";
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::string str;

	while (1) {
		std::getline(std::cin, str);
		if (str == ".")
			return 0;

		isBalanced(str);
	}
}