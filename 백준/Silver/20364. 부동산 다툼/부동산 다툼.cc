#include <iostream>
#include <vector>
#define MAX (1 << 20) + 1

std::vector<int> vec(MAX);
int N, Q;

int func(int cur) {
	int flag = 0;
	int idx = cur;
	while (idx != 1) {
		if (vec[idx] == 1) {
			flag = idx;
		}
		idx /= 2;
	}
	vec[cur] = 1;
	return flag;
}
int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int x;

	std::cin >> N >> Q;
	for (int i = 0; i < Q; i++) {
		std::cin >> x;

		std::cout << func(x) << "\n";
	}
}