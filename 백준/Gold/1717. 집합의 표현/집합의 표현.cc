#include <iostream>

int root[1000001];
int rank[1000001];

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

	int n=8, m;
	int op, a, b;
	std::cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		root[i] = i;
	}

	for (int i = 0; i < m; i++) {
		std::cin >> op >> a >> b;

		if (op) {
			op_find(a) == op_find(b) ? std::cout << "YES\n" : std::cout << "NO\n";
		}
		else {
			op_union(a, b);
		}
	}
}