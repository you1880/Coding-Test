#include <iostream>
#include <queue>
#include <vector>

int visited[200001] = { 0, };

void bfs(int start, int target, bool& flag) {
	std::queue<int> q;
	int x, dx;
	int d[3] = { 1,-1,2 };

	q.push(start);
	visited[start] = 1;

	while (!q.empty()) {
		if (flag) {
			break;
		}
		x = q.front();
		q.pop();

		if (x == target) {
			flag = true;
			std::cout << visited[x] - 1;
			return;
		}

		for (int i = 0; i < 3; i++) {
			if (i == 2) {
				dx = x * d[i];
			}
			else {
				dx = x + d[i];
			}
			
			if (dx < 0 || dx>200000 || visited[dx]) {
				continue;
			}
			q.push(dx);
			visited[dx] = visited[x] + 1;
		}
	}
	
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, K;
	bool flag = false;
	std::cin >> N >> K;

	if (N == K) {
		std::cout << 0;
	}
	else {
		bfs(N, K, flag);
	}
}