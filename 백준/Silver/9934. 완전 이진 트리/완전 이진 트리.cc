#include <iostream>
#include <vector>

std::vector<int> vec(1025);
std::vector<int> tree(1025);
int size, K, idx = 1;

void inorder(int cur) {
	if (cur > size) {
		return;
	}
	inorder(cur * 2);
	tree[cur] = vec[idx++];
	inorder(cur * 2 + 1);
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> K;

	size = (1 << K) - 1;
	for (int i = 1; i <= size; i++) {
		std::cin >> vec[i];
	}

	inorder(1);

	for (int i = 0; i < K; i++) {
		int cnt = (1 << i);
		for (int j = cnt; j < (cnt * 2); j++) {
			std::cout << tree[j] << " ";
		}
		std::cout << "\n";
	}
}