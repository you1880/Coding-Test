#include <iostream>
#include <vector>
#define MAX 51

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

	std::vector<std::vector<int>> party;
	std::vector<int> kn;
	int N, M, p, x, count = 0;
	std::cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		root[i] = i;
		rank[i] = 1;
	}

	std::cin >> p;

	for (int i = 0; i < p; i++) {
		std::cin >> x;
		kn.push_back(x);
	}

	if (kn.size() > 1) {
		for (int i = 1; i < kn.size(); i++) {
			Union(kn[0], kn[i]);
		}
	}

	for (int i = 0; i < M; i++) {
		std::vector<int> tmp;
		int first;
		std::cin >> p >> first;

		tmp.push_back(first);
		if (p > 1) {
			for (int j = 1; j < p; j++) {
				std::cin >> x;
				tmp.push_back(x);
				Union(first, x);
			}
		}

		party.push_back(tmp);
	}

	if (kn.size() == 0) {
		count = M;
	}
	else {
		for (int i = 0; i < M; i++) {
			bool flag = false;
			for (int j = 0; j < party[i].size(); j++) {
				if (Find(kn[0]) == Find(party[i][j])) {
					flag = true;
					break;
				}
			}

			if (!flag) {
				count++;
			}
		}
	}
	std::cout << count;
}