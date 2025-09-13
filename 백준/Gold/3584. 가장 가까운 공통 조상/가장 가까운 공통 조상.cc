#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10'001

int T, N, A, B;
std::vector<int> vec[MAX];
int depth[MAX];
int parent[MAX];
bool visited[MAX];

void dfs(int cur, int d) {
	if (visited[cur]) {
		return;
	}

	visited[cur] = true;
	depth[cur] = d;

	for (const auto& next : vec[cur]) {
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

	std::cin >> T;
	while (T--) {
		std::cin >> N;

		for (int i = 0; i < MAX; i++) {
			vec[i].clear();
			visited[i] = false;
			parent[i] = i;
			depth[i] = 0;
		}

		for (int i = 0; i < N - 1; i++) {
			std::cin >> A >> B;

			vec[A].push_back(B);
			parent[B] = A;
		}

		std::cin >> A >> B;

		for (int i = 1; i <= N; i++) {
			if (parent[i] == i) {
				dfs(i, 0);
			}
		}

		std::cout << lca(A, B) << "\n";
	}
}
