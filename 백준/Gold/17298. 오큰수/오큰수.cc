#include <iostream>
#include <vector>
#include <stack>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::stack<std::pair<int, int>> stk;
	int N;

	std::cin >> N;
	std::vector<int> vec(N), ans(N);
	for (int i = 0; i < N; i++) {
		std::cin >> vec[i];
	}

	for (int i = 0; i < N; i++) {
		while (!stk.empty() && stk.top().first < vec[i]) {
			ans[stk.top().second] = vec[i];
			stk.pop();
		}
		stk.push({ vec[i], i });
	}

	while (!stk.empty()) {
		ans[stk.top().second] = -1;
		stk.pop();
	}

	for (int i = 0; i < N; i++) {
		std::cout << ans[i] << " ";
	}
}