#include <iostream>
#include <stack>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::stack<int> stk;
	int n, idx = 0;
	std::cin >> n;
	
	std::vector<int> arr(n);
	std::vector<char> ans;
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		stk.push(i);
		ans.push_back('+');

		if (stk.top() == arr[idx] && !stk.empty()) {
			while (stk.top() == arr[idx]) {
				ans.push_back('-');
				idx++;
				stk.pop();

				if (idx == n || stk.empty()) {
					break;
				}
			}
		}
	}

	if (stk.empty()) {
		for (auto op : ans) {
			std::cout << op << "\n";
		}
	}
	else {
		std::cout << "NO";
	}
}