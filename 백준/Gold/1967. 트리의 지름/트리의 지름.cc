#include <iostream>
#include <vector>
#define MAX 10001

std::vector<std::pair<int, int>> vec[MAX];
int n, x, l = 0;

void dfs(int start, int weight, std::vector<bool>& visited) {
	visited[start] = true;

	if (l < weight) {
		l = weight;
		x = start;
	}

	for (auto& next : vec[start]) {
		if (!visited[next.first]) {
			dfs(next.first, weight + next.second, visited);
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int a, b, w;

	std::cin >> n;
	
	for (int i = 0; i < n - 1; i++) {
		std::cin >> a >> b >> w;

		vec[a].push_back({ b,w });
		vec[b].push_back({ a,w });
	}

	std::vector<bool> visited(n + 1, false);
	dfs(1, 0, visited);

	visited.assign(n + 1, false);
	dfs(x, 0, visited);

	std::cout << l;
}