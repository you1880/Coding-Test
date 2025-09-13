#include <iostream>
#include <vector>
#include <algorithm>

typedef struct {
	int from;
	int to;
	int cost;
}Node;

int root[1001];

int op_find(int x) {
	if (root[x] == x) {
		return x;
	}
	else {
		return op_find(root[x]);
	}
}

void op_union(int x, int y) {
	x = op_find(x);
	y = op_find(y);

	root[y] = x;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M, a, b, c;
	int ans = 0;
	std::cin >> N >> M;

	std::vector<Node> vec;

	for (int i = 1; i <= N; i++) {
		root[i] = i;
	}

	for (int i = 0; i < M; i++) {
		std::cin >> a >> b >> c;
		vec.push_back(Node{ a,b,c });
	}

	std::sort(vec.begin(), vec.end(), [](const Node a, const Node b) {return a.cost < b.cost ? true : false; });

	for (const auto& v : vec) {
		if (op_find(v.from) != op_find(v.to)) {
			op_union(v.from, v.to);
			ans += v.cost;
		}
	}

	std::cout << ans;
}
