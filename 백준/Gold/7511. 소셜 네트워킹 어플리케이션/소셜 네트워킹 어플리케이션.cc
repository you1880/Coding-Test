#include <iostream>
#include <vector>
#define MAX 1000001

int root[MAX];
int rank[MAX];

int Find(int x) {
	if (root[x] == x) {
		return x;
	}
	else {
		return root[x] = Find(root[x]);
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y) {
		return;
	}

	if (rank[x] < rank[y]) {
		root[x] = y;
	}
	else {
		root[y] = x;
		
		if (rank[x] == rank[y]) {
			rank[x]++;
		}
	}
}

void Print(int i, std::vector<std::pair<int, int>>& vec) {
	std::cout << "Scenario " << i << ":" << "\n";

	for (int i = 0; i < vec.size(); i++) {
		std::cout << (Find(vec[i].first) == Find(vec[i].second)) << "\n";
	}
	std::cout << "\n";
}

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	int T;
	std::cin >> T;

	for (int i = 1; i <= T; i++) {
		int n, k, a, b, m, u, v;

		std::cin >> n >> k;

		for (int j = 0; j < n; j++) {
			rank[j] = 0;
			root[j] = j;
		}

		for (int j = 0; j < k; j++) {
			std::cin >> a >> b;

			Union(a, b);
		}

		std::cin >> m;

		std::vector<std::pair<int, int>> vec;
		for (int j = 0; j < m; j++) {
			std::cin >> u >> v;
			vec.push_back({ u,v });
		}

		Print(i, vec);
	}
}