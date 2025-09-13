#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 50001

std::vector<int> tree[MAX];
int parent[MAX];
int depth[MAX];
int visited[MAX];
int N, M;

void dfs(int cur, int d) {
	if (visited[cur]) {
		return;
	}

	visited[cur] = true;
	depth[cur] = d;

	for (auto& next : tree[cur]) {
		if (!visited[next]) {
			parent[next] = cur;
			dfs(next, d + 1);
		}
	}
}

int lca(int a, int b) {
	if (depth[a] < depth[b]) {
		std::swap(a, b);
	}

	while (depth[a] != depth[b]) {
		a = parent[a];
	}

	while (a != b) {
		a = parent[a];
		b = parent[b];
	}

	return a;
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int u, v;
	std::cin >> N;

	for (int i = 0; i < N - 1; i++) {
		std::cin >> u >> v;

		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	dfs(1, 0);

	std::cin >> M;
	for (int i = 0; i < M; i++) {
		std::cin >> u >> v;

		std::cout << lca(u, v) << "\n";
	}
}