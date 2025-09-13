#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int N, min = INT_MAX, max = INT_MIN;
std::vector<int> nums, ops;
int arr[11];
bool selected[11];

void dfs(int cnt) {
	if (cnt == N - 1) {
		int tmp = nums[0];

		for (int i = 0; i < N - 1; i++) {
			if (arr[i] == 1) {
				tmp = tmp + nums[i + 1];
			}
			else if (arr[i] == 2) {
				tmp = tmp - nums[i + 1];
			}
			else if (arr[i] == 3) {
				tmp = tmp * nums[i + 1];
			}
			else if (arr[i] == 4) {
				tmp = tmp / nums[i + 1];
			}
		}
		
		min = min > tmp ? tmp : min;
		max = tmp > max ? tmp : max;

		return;
	}

	for (int i = 0; i < N - 1; i++) {
		if (!selected[i]) {
			selected[i] = true;
			arr[cnt] = ops[i];
			dfs(cnt + 1);
			selected[i] = false;
		}
	}
}

int main() {
	std::cin.tie(0)->sync_with_stdio(false);

	int x;
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> x;
		nums.push_back(x);
	}

	for (int i = 1; i <= 4; i++) {
		std::cin >> x;

		for (int j = 0; j < x; j++) {
			ops.push_back(i);
		}
	}

	dfs(0);

	std::cout << max << "\n" << min;
}