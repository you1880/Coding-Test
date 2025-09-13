#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define MAX 1001

int root[MAX];
int rank[MAX];

struct Node {
	int from;
	int to;
	double dis;

	Node(int f, int t, double d)
		: from(f), to(t), dis(d) {}
};

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

int main() {
	std::cin.tie(NULL)->sync_with_stdio(false);

	double min_dis = 0.0;
	int N, M, x, y;
	std::cin >> N >> M;

	std::vector<std::pair<int, int>> points;
	std::vector<Node> nodes;

	for (int i = 1; i <= N; i++) {
		std::cin >> x >> y;
		points.push_back({ x,y });
		root[i] = i;
		rank[i] = 0;
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			double dis = sqrt(pow((points[i].first - points[j].first), 2) + pow(points[i].second - points[j].second, 2));
			nodes.push_back(Node(i + 1, j + 1, dis));
		}
	}

	for (int i = 0; i < M; i++) {
		std::cin >> x >> y;
		Union(x, y);
	}

	std::sort(nodes.begin(), nodes.end(), [](Node& n1, Node& n2) {return n1.dis < n2.dis; });

	for (const auto& node : nodes) {
		if (Find(node.from) != Find(node.to)) {
			Union(node.from, node.to);
			min_dis += node.dis;
		}
	}

	std::cout << std::fixed;
	std::cout.precision(2);
	std::cout << min_dis;
}