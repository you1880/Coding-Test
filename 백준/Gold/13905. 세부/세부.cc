#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001

const int INF = 1e9;

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

struct Node {
	int from;
	int to;
	int cost;
};

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int N, M, s, e;
	std::cin >> N >> M >> s >> e;

	for (int i = 1; i <= N; i++) {
		root[i] = i;
		rank[i] = 0;
	}

	std::vector<Node> graph;
	
	for (int i = 0; i < M; i++) {
		int h1, h2, k;
		std::cin >> h1 >> h2 >> k;

		graph.push_back({ h1, h2, k });
	}

	std::sort(graph.begin(), graph.end(), [](const Node& n1, const Node& n2) { return n1.cost > n2.cost; });

	for (const auto& node : graph) {
		int x = Find(node.from), y = Find(node.to);

		if (x != y) {
			Union(x, y);
		}

		if (Find(s) == Find(e)) {
			std::cout << node.cost;
			return 0;
		}
	}
    
    std::cout << 0;
}