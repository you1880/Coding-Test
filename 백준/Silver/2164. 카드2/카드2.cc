#include <iostream>
#include <queue>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	std::queue<int> q;
	int N;
	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	
	while (q.size() != 1) {
		q.pop();
		int tmp = q.front();
		q.pop();
		q.push(tmp);
	}

	std::cout << q.front();
}