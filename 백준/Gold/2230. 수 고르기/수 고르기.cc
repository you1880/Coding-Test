#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int N, M;
	std::cin >> N >> M;

	std::vector<int> vec(N);
	for (int i = 0; i < N; i++) {
		std::cin >> vec[i];
	}

	std::sort(vec.begin(), vec.end());
	int left = 0, right = 0, gap = 2100000000;

	while (left < N && right < N) {
		int g = vec[right] - vec[left];

		if (g < M) {
				right++;
		}
		else if (g >= M) {
			if (gap > g) {
				gap = g;
			}
			left++;
		}
	}
	std::cout << gap;
}