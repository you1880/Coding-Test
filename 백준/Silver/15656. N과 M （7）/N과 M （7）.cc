#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> vec;
int arr[9];
int M, N;

void dfs(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << "\n";

		return;
	}

	for (int i = 0; i < N; i++) {
		arr[cnt] = vec[i];
		dfs(cnt + 1);
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int x;

		std::cin >> x;
		vec.push_back(x);
	}

	std::sort(vec.begin(), vec.end());

	dfs(0);
}