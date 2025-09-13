#include <iostream>
#include <vector>
#define MAX 51

std::vector<int> vec[MAX];
std::vector<bool> visited(MAX, false);
int N, root, rmv, cnt = 0;

void dfs(int start, int parent) {
	if (start == rmv) {
		return;
	}

	bool isLeaf = true;

	for (auto& next : vec[start]) {
		if (next == parent || next == rmv) {
			continue;
		}

		isLeaf = false;
		dfs(next, start);
	}

	if (isLeaf) {
		cnt++;
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int x;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> x;

		if (x == -1) {
			root = i;
		}
		else {
			vec[x].push_back(i);
		}
	}

	std::cin >> rmv;
	dfs(root, -1);

	std::cout <<cnt;
}