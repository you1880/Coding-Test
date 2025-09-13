#include <iostream>
#include <deque>
#define MAX 200001

int visited[MAX];
int N, K;

int bfs(int start) {
	std::deque<int> dq;
	dq.push_back(start);

	while (!dq.empty()) {
		int cur = dq.front();
		dq.pop_front();

		if (cur == K) {
			return visited[K];
		}

		if (cur * 2 <= 200000 && visited[cur * 2] > visited[cur]) {
			visited[cur * 2] = visited[cur];
			dq.push_front(cur * 2);
		}

		if (cur - 1 >= 0 && visited[cur - 1] > visited[cur] + 1) {
			visited[cur - 1] = visited[cur] + 1;
			dq.push_back(cur - 1);
		}

		if (cur + 1 <= 200000 && visited[cur + 1] > visited[cur] + 1) {
			visited[cur + 1] = visited[cur] + 1;
			dq.push_back(cur + 1);
		}
	}
}

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	std::cin >> N >> K;

	for (int i = 0; i < MAX; i++) {
		visited[i] = 1e9;
	}

	visited[N] = 0;

	std::cout << bfs(N);
}