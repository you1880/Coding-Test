#include <iostream>

int N, res = 0;
int nums[] = { 0,1,2 };
int arr[10];

void dfs(int cnt) {
	if (cnt == N) {
		int tmp = 0;

		for (int i = 0; i < N; i++) {
			tmp += arr[i];
		}
		
		if (tmp % 3 == 0) {
			res++;
		}

		return;
	}

	for (int i = 0; i < 3; i++) {
		if (cnt == 0 && nums[i] == 0)
			continue;

		arr[cnt] = nums[i];
		dfs(cnt + 1);
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	std::cin >> N;

	if (N == 1) {
		std::cout << 0;
	}
	else {
		dfs(0);
		std::cout << res;
	}
}