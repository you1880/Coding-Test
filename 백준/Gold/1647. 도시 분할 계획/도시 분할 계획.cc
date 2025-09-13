#include <iostream>
#include <vector>
#include <algorithm>

int root[100001];
int rank[100001];

struct Edge {
	int from;
	int to;
	int weight;

	Edge(int a, int b, int c) {
		from = a;
		to = b;
		weight = c;
	}

	bool operator<(const Edge& e) const {
		return weight < e.weight;
	}
};

int op_find(int x) {
	if (root[x] == x) {
		return x;
	}
	else {
		return root[x] = op_find(root[x]);
	}
}

void op_union(int x, int y) {
	x = op_find(x);
	y = op_find(y);

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
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::vector<Edge> vec;
	int N, M, A, B, C, cost = 0, max = 0;
	std::cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		root[i] = i;
	}

	for (int i = 0; i < M; i++) {
		std::cin >> A >> B >> C;
		vec.push_back(Edge(A, B, C));
	}

	for (int i = 1; i <= N; i++) {
		root[i] = i;
	}

	std::sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		if (op_find(vec[i].from) != op_find(vec[i].to)) {
			op_union(vec[i].from, vec[i].to);
			cost += vec[i].weight;

			max = vec[i].weight > max ? vec[i].weight : max;
		}
	}

	std::cout << cost - max;
}