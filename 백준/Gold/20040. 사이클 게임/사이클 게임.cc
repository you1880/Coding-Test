#include <iostream>
#define MAX 500000

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

int main() {
	std::cin.tie(0)->sync_with_stdio(false);
	
	int N, M, a, b, cycle = 0;
	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		root[i] = i;
		rank[i] = 0;
	}

	for (int i = 0; i < M; i++) {
		std::cin >> a >> b;

		if (Find(a) == Find(b)) {
			std::cout << i + 1;
			return 0;
		}
		Union(a, b);
	}
	std::cout << "0";
}