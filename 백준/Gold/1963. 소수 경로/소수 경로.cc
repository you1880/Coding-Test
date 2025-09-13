#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define MAX 10000

std::vector<bool> prime(MAX + 1, true);

void init() {
	for (int i = 2; i * i <= MAX; i++) {
		if (prime[i]) {
			for (int j = i * i; j <= MAX; j += i) {
				prime[j] = false;
			}
		}
	}
}

void bfs(std::string start, std::string end) {
	std::queue<std::pair<std::string, int>> q;
	std::vector<bool> visited(MAX + 1, false);

	q.push({ start, 0 });
	visited[std::stoi(start)] = true;

	while (!q.empty()) {
		std::string cur = q.front().first;
		int count = q.front().second;
		q.pop();

		if (cur == end) {
			std::cout << count << "\n";
			return;
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 10; j++) {
				std::string tmp = cur;
				tmp[i] = j + '0';
				int next = std::stoi(tmp);

				if (next < 1000) {
					continue;
				}

				if (visited[next]) {
					continue;
				}

				if (!prime[next]) {
					continue;
				}

				visited[next] = true;
				q.push({ std::to_string(next), count + 1 });
			}
		}
	}

	std::cout << "Impossible\n";
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	init();

	int T;
	std::cin >> T;

	while (T--) {
		std::string p1, p2;
		std::cin >> p1 >> p2;

		bfs(p1, p2);
	}
}