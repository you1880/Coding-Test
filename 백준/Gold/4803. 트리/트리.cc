#include <iostream>
#include <unordered_set>
#define MAX 501

int root[MAX];
bool check[MAX];

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
		check[x] = true;
	}
	else {
		if (check[x] || check[y]) {
			check[x] = check[y] = true;
		}
		root[y] = x;
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int n, m, a, b, c = 1;
	while (1) {
		std::cin >> n >> m;

		if (n == 0 && m == 0) {
			break;
		}

		std::unordered_set<int> s;

		for (int i = 0; i <= n; i++) {
			root[i] = i;
			check[i] = false;
		}

		for (int i = 0; i < m; i++) {
			std::cin >> a >> b;

			Union(a, b);
		}

		for (int i = 1; i <= n; i++) {
			int x = Find(i);
			if (!check[x]) {
				s.insert(x);
			}
		}

		int size = s.size();
		std::cout << "Case " << c << ": ";
		if (size == 0) {
			std::cout << "No trees.\n";
		}
		else if (size == 1) {
			std::cout << "There is one tree.\n";
		}
		else {
			std::cout << "A forest of " << size << " trees.\n";
		}
		c++;
	}
}