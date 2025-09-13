#include <iostream>
#include <stack>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::stack<int> stk;
	int N, h;
	long long sum = 0;
	std::cin >> N;
	
	for (int i = 0; i < N; i++) {
		std::cin >> h;

		if (stk.empty()) {
			stk.push(h);
			continue;
		}

		while (!stk.empty() && stk.top() <= h) {
			stk.pop();
		}
		
		sum += stk.size();
		stk.push(h);
	}

	std::cout << sum;
}