#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> vec(9);
int arr[9];
bool selected[9];
int N, max = 0;

void dfs(int cnt) {
	if (cnt == N) {
		int sum = 0;

		for (int i = 0; i < N - 1; i++) {
			sum += std::abs(arr[i] - arr[i + 1]);
		}

		max = sum > max ? sum : max;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!selected[i]) {
			selected[i] = true;
			arr[cnt] = vec[i];
			dfs(cnt + 1);
			selected[i] = false;
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> vec[i];
	}

	dfs(0);

	std::cout << max;
}