#include <iostream>
#include <vector>
#define MAX 123'457

std::vector<int> tree[MAX];
int val[MAX];
int N;

long long dfs(int cur, int p) {
	long long sum = val[cur];

	for (const auto& next : tree[cur]) {
		if (p == next) {
			continue;
		}

		sum += dfs(next, cur);
	}

	return sum < 0ll ? 0ll : sum;
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	char t;
	int a, p;
	std::cin >> N;

	for (int i = 2; i <= N; i++) {
		std::cin >> t >> a >> p;

		if (t == 'S') {
			val[i] = a;
		}
		else if (t == 'W') {		
			val[i] = -a;
		}

		tree[p].push_back(i);
		tree[i].push_back(p);
	}

	std::cout << dfs(1, 0);
}